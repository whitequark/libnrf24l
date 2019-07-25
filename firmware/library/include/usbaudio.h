#ifndef USBAUDIO_H
#define USBAUDIO_H

enum {
  /// Audio Interface Class
  USB_IFACE_CLASS_AUDIO = 0x01,

  /// Audio Control Interface Subclass
  USB_IFACE_SUBCLASS_AUDIO_CONTROL = 0x01,
  /// Audio Streaming Interface Subclass
  USB_IFACE_SUBCLASS_AUDIO_STREAMING = 0x02,

  /// No Basic Audio Device Code provided. See full configuration descriptor for device details.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_UNDEFINED = 0x00,
  /// Mono Headphone using HT1 topology (no auxiliary inputs).
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_M_HP_HT1 = 0x01,
  /// Mono Headphone using HT2 topology (no auxiliary inputs).
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_M_HP_HT2 = 0x02,
  /// Mono Headphone using HT3 topology (no auxiliary inputs).
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_M_HP_HT3 = 0x03,
  /// Stereo Headphone using HT1 topology (no auxiliary inputs).
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HP_HT1 = 0x04,
  /// Stereo Headphone using HT2 topology with mono auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HP_HT2_MAUX1 = 0x05,
  /// Stereo Headphone using HT2 topology with stereo auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HP_HT2_SAUX1 = 0x06,
  /// Stereo Headphone using HT3 topology with mono first auxiliary signal path
  /// and mono second auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HP_HT3_MAUX1_MAUX2 = 0x07,
  /// Stereo Headphone using HT3 topology with stereo first auxiliary signal path
  /// and mono second auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HP_HT3_SAUX1_MAUX2 = 0x08,
  /// Stereo Headphone using HT3 topology with mono first auxiliary signal path
  /// and stereo second auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HP_HT3_MAUX1_SAUX2 = 0x09,
  /// Stereo Headphone using HT3 topology with stereo first auxiliary signal path
  /// and stereo second auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HP_HT3_SAUX1_SAUX2 = 0x0A,
  /// Mono Microphone.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_M_MIC = 0x0B,
  /// Stereo microphone.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_MIC = 0x0C,
  /// Mono Headset using HS1 topology.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_M_HS_HS1 = 0x0D,
  /// Mono Headset using HS2 topology.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_M_HS_HS2 = 0x0E,
  /// Mono Headset using HS3 topology.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_M_HS_HS3 = 0x0F,
  /// Stereo Headset using HS1 topology.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HS_HS1 = 0x10,
  /// Stereo Headset using HS2 topology with mono auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HS_HS2_MAUX1 = 0x11,
  /// Stereo Headset using HS2 topology with stereo auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HS_HS2_SAUX1 = 0x12,
  /// Stereo Headset using HS3 topology with mono first auxiliary signal path
  /// and mono second auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HS_HS3_MAUX1_MAUX2 = 0x13,
  /// Stereo Headset using HS3 topology with stereo first auxiliary signal path
  /// and mono second auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HS_HS3_SAUX1_MAUX2 = 0x14,
  /// Stereo Headset using HS3 topology with mono first auxiliary signal path
  /// and stereo second auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HS_HS3_MAUX1_SAUX2 = 0x15,
  /// Stereo Headset using HS3 topology with stereo first auxiliary signal path
  /// and stereo second auxiliary signal path.
  USB_IFACE_PROTOCOL_AUDIO_BASIC_CODE_S_HS_HS3_SAUX1_SAUX2 = 0x16,
};

enum usb_audio_desc_control_subtype {
  /// Header Descriptor
  USB_DESC_AUDIO_CONTROL_SUBTYPE_HEADER = 0x01,
  /// Input Terminal Descriptor
  USB_DESC_AUDIO_CONTROL_SUBTYPE_INPUT_TERMINAL = 0x02,
  /// Output Terminal Descriptor
  USB_DESC_AUDIO_CONTROL_SUBTYPE_OUTPUT_TERMINAL = 0x03,
  /// Feature Unit Descriptor
  USB_DESC_AUDIO_CONTROL_SUBTYPE_FEATURE_UNIT = 0x06,
};

struct usb_audio_desc_control_header_1 {
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubType;
  uint16_t bcdADC;
  uint16_t wTotalLength;
  uint8_t bInCollection;
  // uint8_t baInterfaceNr[];
};

struct usb_audio_desc_control_input_terminal {
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubType;
  uint8_t bTerminalID;
  uint16_t wTerminalType;
  uint8_t bAssocTerminal;
  uint8_t bNrChannels;
  uint16_t wChannelConfig;
  uint8_t iChannelNames;
  uint8_t iTerminal;
};

struct usb_audio_desc_control_output_terminal {
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubType;
  uint8_t bTerminalID;
  uint16_t wTerminalType;
  uint8_t bAssocTerminal;
  uint8_t bSourceID;
  uint8_t iTerminal;
};

struct usb_audio_desc_control_feature_unit_1 {
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubType;
  uint8_t bUnitID;
  uint8_t bSourceID;
  uint8_t bControlSize;
  // uint16_t bmaControls[];
};
struct usb_audio_desc_control_feature_unit_2 {
  uint8_t iFeature;
};

enum usb_audio_desc_streaming_subtype {
  /// General Interface Descriptor
  USB_DESC_AUDIO_STREAMING_SUBTYPE_GENERAL = 0x01,
  /// Format Type Descriptor
  USB_DESC_AUDIO_STREAMING_SUBTYPE_FORMAT_TYPE = 0x02,
};

struct usb_audio_desc_streaming_general {
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubType;
  uint8_t bTerminalLink;
  uint8_t bDelay;
  uint16_t wFormatTag;
};

struct usb_audio_desc_streaming_format_type {
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubType;
  uint8_t bFormatType;
  uint8_t bNrChannels;
  uint8_t bSubFrameSize;
  uint8_t bBitResolution;
  uint8_t bSamFreqType;
  uint8_t tSamFreq[3];
};

enum usb_audio_desc_data_subtype {
  /// General Endpoint Descriptor
  USB_DESC_AUDIO_DATA_SUBTYPE_GENERAL = 0x01,
};

struct usb_audio_desc_data_general {
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubType;
  uint8_t bmAttributes;
  uint8_t bLockDelayUnits;
  uint16_t wLockDelay;
};

/// Class-Specific Request Codes
enum usb_audio_request {
  USB_AUDIO_REQ_SET_CUR = 0x01,
  USB_AUDIO_REQ_GET_CUR = 0x81,
  USB_AUDIO_REQ_SET_MIN = 0x02,
  USB_AUDIO_REQ_GET_MIN = 0x82,
  USB_AUDIO_REQ_SET_MAX = 0x03,
  USB_AUDIO_REQ_GET_MAX = 0x83,
  USB_AUDIO_REQ_SET_RES = 0x04,
  USB_AUDIO_REQ_GET_RES = 0x84,
};

#endif
