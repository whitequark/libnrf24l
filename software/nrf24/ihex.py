import re


__all__ = ["read"]


def read(file_or_data):
    """
    Read Intel HEX data from ``file_or_data``, which may be a string or a file-like object.

    Raises :class:`ValueError` if the input data has invalid format.

    Returns a list of ``(address, data)`` chunks.
    """

    if isinstance(file_or_data, str):
        data = file_or_data
    else:
        data = file_or_data.read()

    resoff = 0
    resbuf = []
    res    = []

    RE_HDR = re.compile(r":([0-9a-f]{8})", re.I)
    RE_WS  = re.compile(r"\s*")

    pos = 0
    while pos < len(data):
        match = RE_HDR.match(data, pos)
        if match is None:
            raise ValueError("Invalid record header at offset {}".format(pos))
        *rechdr, = bytes.fromhex(match.group(1))
        reclen, recoffh, recoffl, rectype = rechdr

        recdatahex = data[match.end(0):match.end(0)+(reclen+1)*2]
        if len(recdatahex) < (reclen + 1) * 2:
            raise ValueError("Truncated record at offset {}".format(pos))
        try:
            *recdata, recsum = bytes.fromhex(recdatahex)
        except ValueError:
            raise ValueError("Invalid record data at offset {}".format(pos))
        if sum(rechdr + recdata + [recsum]) & 0xff != 0:
            raise ValueError("Invalid record checksum at offset {}".format(pos))

        if rectype == 0x01:
            if len(resbuf) > 0:
                res.append((resoff, resbuf))
            return res

        elif rectype == 0x00:
            recoff = (recoffh << 8) | recoffl
            if resoff + len(resbuf) == recoff:
                resbuf += recdata
            else:
                if len(resbuf) > 0:
                    res.append((resoff, resbuf))
                resoff  = recoff
                resbuf  = recdata

        else:
            raise ValueError("Unknown record type {:02x} at offset {}".format(rectype, pos))

        match = RE_WS.match(data, match.end(0) + len(recdatahex))
        pos = match.end(0)
