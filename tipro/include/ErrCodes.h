// ErrCodes.h :
//				Definition of error codes
//////////////////////////////////////////////////////////////////////

// general errors
#define API_ERR_None						0x00
#define API_ERR_WrongParameter				0x01
#define API_ERR_InvalidHandleValue			0x02
#define API_ERR_DeviceNotOpened				0x03
#define API_ERR_GetFeature					0x04
#define API_ERR_SetFeature					0x05
#define API_ERR_Unknown						0x06

// Tipro specific
#define API_ERR_CmdNotSupportedAtFWLevel	0x07
#define API_ERR_FWLevelNotAvailable			0x08
#define API_ERR_FWLevelChangeFailed			0x09

// FW Level > 1 
#define API_ERR_WTCDelayExpired				0x0A
#define API_ERR_WrongSignatureBytes			0x0B
#define API_ERR_FWLevel_1_NotAvailable		0x0C
#define API_ERR_FWLevel_2_NotAvailable		0x0D
#define API_ERR_FWLevel_3_NotAvailable		0x0E

// enumeration errors
#define API_ERR_EnumerateModulesFailed		0x10
#define API_ERR_ModulesNotEnumerated		0x11
#define API_ERR_NonexistantModule			0x12

// command errors
#define API_ERR_CommunicationError			0x20
#define API_ERR_ResponseError				0x21
#define API_ERR_UnexpectedResponse			0x22

// Task#98
// command/parameter not supported in connected hardware/firmware
#define API_ERR_UnsupportedParameter		0x23
#define API_ERR_UnsupportedCommand			0x24

// string descriptor errors
#define API_ERR_NoStringDescriptor			0x30
#define API_ERR_VID_PID_NotReported			0x31

// module specifc errors
#define API_ERR_SBXMode						0x40

// low level errors
#define API_ERR_GeneralLowLevelError		0xE0

// API specifc errors
#define API_ERR_NoDevicesDetected			0xF1
#define API_ERR_DeviceUnplugged				0xF2
#define API_ERR_DeviceNotConnected			0xF3