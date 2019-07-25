SUBDIRS = le1/blinky lu1/blinky lu1/radio

all:
	@set -e; for dir in $(SUBDIRS); do $(MAKE) -C $${dir} all; done

clean:
	@set -e; for dir in $(SUBDIRS); do $(MAKE) -C $${dir} clean; done
