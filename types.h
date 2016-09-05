#ifndef TYPES_H
#define TYPES_H

#define TIPRO_LED1 (1 << 0)
#define TIPRO_LED2 (1 << 1)
#define TIPRO_LED3 (1 << 2)
#define TIPRO_LED4 (1 << 3)

struct controller_info
{
    int verMaj;
    int verMin;
    int verBuild;
    int verCustom;
    int FWLevel;
};

typedef int (*HIDTouchscreenDisable)(void);
typedef int (*HIDSetLuminance)(int nLum);
typedef int (*HIDTouchscreenEnable)(void);
typedef int (*HIDSetLeds)(int nLEDs);
typedef int (*HIDDetectDevices)(void);
typedef int (*HIDEnumerateModules)(void);
typedef int (*HIDGetControllerInfo)(int *nVerMaj, int *nVerMin, int *nVerBuild,int *nVerCustom, int *nFWLevel);
typedef int (*HIDGetModuleVersion)(int nIndex, unsigned char *nVerMaj, unsigned char *nVerMin, unsigned char *nVerBuild);

#if 0
/****************************************************************************/
/*		SPEAKERBOX FUNCTIONS                                                */
/****************************************************************************/

TIPROHIDAPI_API int HIDSetSpeakerLevel(int nFsNum, int nLevel);
/* Sets the level of the speakers											*/
/* arguments (IN)	: selected speakerbox module number                     */
/*					: speaker level			 								*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDGetSpeakerLevel(int nFsNum, int *nLevel);
/* Returns the level of the speakers										*/
/* arguments (IN)	: selected speakerbox module number                     */
/*					: speaker level			 								*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDGetHandsetState(int nHandsetNum, int *nPTTKey, int *nHookState);
/* Returns the state of the keys											*/
/* arguments (IN)	: selected handset module number	                    */
/* arguments (OUT)	: PTT key state	(KEY_PRESSED / KEY_RELEASED)			*/
/*					: Hook state (KEY_PRESSED / KEY_RELEASED)				*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDGetHandsetStateEx (int nHandsetNum, int *nPTTKey, int *nHookState);
/* Returns the state of the keys											*/
/* arguments (IN)	: selected handset module number	                    */
/* arguments (OUT)	: PTT key state	(KEY_PRESSED / KEY_RELEASED)			*/
/*					: Hook state (KEY_PRESSED / KEY_RELEASED)				*/
/*					: if any of OUT arguments is NULL, handset state is		*/
/*					: sent to system, otherwise just RAW is returned		*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDGetSbxKeyState (int nFsNum, int nKey, int *nState);
/* Returns the state of the keys											*/
/* arguments (IN)	: selected speakerbox module number                     */
/*					: key index												*/
/* arguments (OUT)	: state of the key (KEY_PRESSED / KEY_RELEASED)			*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDSetSbxLEDState (int nFsNum, int nKey, int nState);
/* Sets the LED state of the illuminated keys								*/
/* arguments (IN)	: selected speakerbox module number                     */
/*					: illuminated key index									*/
/*					: state of the LED (LED_ON/LED_OFF)						*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDGetSbxLEDState (int nFsNum, int nKey, int *nState);
/* Returns the LED state of the illuminated keys							*/
/* arguments (IN)	: selected speakerbox module number                     */
/*					: illuminated key index									*/
/* arguments (OUT)	: state of the LED (LED_ON/LED_OFF)						*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDSetExternalDeviceLevel (int nFsNum, int nLevel);
/* Sets the level of the connected headset/handset device					*/
/* arguments (IN)	: selected speakerbox module number                     */
/*					: level of the signal	 								*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDGetExternalDeviceLevel (int nFsNum, int *nLevel);
/* Returns the current level of the connected headset/handset device		*/
/* arguments (IN)	: selected speakerbox module number                     */
/* arguments (OUT)	: level of the signal	 								*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDGetExternalHeadsetState (int nFsNum, int *nState);
/* Returns the state of the headset											*/
/* arguments (IN)	: selected speakerbox module number	                    */
/* arguments (OUT)	: headset state											*/
/*								(HEADSET_CONNECTED / HEADSET_DISCONNECTED)	*/
/*																			*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDMuteMicrophone (int nFsNum, int nMute);
/* Mutes/un-mutes the microphone signal										*/
/* arguments (IN)	: selected speakerbox module number                     */
/*					: mute/un-mute microphone 								*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDSpeakerboxGoOnline (int nFsNum);
/* Puts speakerbox to On-line mode											*/
/* arguments (IN)	: selected speakerbox module number                     */
/* return value		: command status : 0 == OK, else error code			    */
/*																			*/

TIPROHIDAPI_API int HIDIsSpeakerboxOnline (int nFsNum, int *nOnline);
/* Returns On-line / Off-line mode											*/
/* arguments (IN)	: selected speakerbox module number                     */
/* arguments (OUT)	: 0 - Offline ; 1 - Online			                    */
/* return value		: command status : 0 == OK, else error code			    */
/*																			*/

TIPROHIDAPI_API int HIDSetAlertLine (int nFsNum, int nMode);
/* Sets the function (mode) of the alert line								*/
/* arguments (IN)	: selected speakerbox module number                     */
/*					: mode (ALERT, VOICE, NOT USED)							*/
/* return value		: command status : 0 == OK, else error code			    */
/*																			*/
/*																			*/
/*																			*/
/* ON-Line ONLY!															*/

TIPROHIDAPI_API int HIDGetAlertLine (int nFsNum, int *nMode);
/* returns the function (mode) of the alert line							*/
/* arguments (IN)	: selected speakerbox module number                     */
/* arguments (OUT)	: mode (ALERT, VOICE, NOT USED)							*/
/* return value		: command status : 0 == OK, else error code			    */
/*																			*/
/*																			*/
/*																			*/
/* ON-Line ONLY!															*/

TIPROHIDAPI_API int HIDSetActiveDevice (int nFsNum, int nDevice);
/* Sets the device where both speaker and microphone signals				*/
/* will be switched to														*/
/* arguments (IN)	: selected speakerbox module number                     */
/*					: device to be made active								*/
/* return value		: command status : 0 == OK, else error code			    */
/*																			*/
/*																			*/
/*																			*/
/* ON-Line ONLY!															*/

TIPROHIDAPI_API int HIDGetMicrophoneLevel (int nFsNum, int *nLevel);
/* Returns the level of the microphone signal								*/
/* arguments (IN) : selected speakerbox module number						*/
/* arguments (OUT): microphone level										*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDSetMicrophoneLevel (int nFsNum, int nLevel);
/* Sets the level of the microphone signal									*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone level										*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDSetMicrophoneLevelEx (int nFsNum, int nLevel, int nDevice);
/* Sets the level of the microphone signal									*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone level										*/
/*				  : device to set (handsfree, handset/headset)				*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDGetMicrophoneOptimalDistance (int nFsNum, int *nDistance);
/* Returns the optimal distnace of the handsfree microphone					*/
/* arguments (IN) : selected speakerbox module number						*/
/* arguments (OUT): microphone optimal distance								*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDSetMicrophoneOptimalDistance (int nFsNum, int nDistance);
/* Sets the optimal distance for the handsfree microphone					*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone optimal distance								*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDSetMicrophoneThreshold (int nFsNum, int nThreshold);
/* Sets the microphone threshold											*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone threshold									*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDGetMicrophoneThreshold (int nFsNum, int *nThreshold);
/* Returns the microphone threshold											*/
/* arguments (IN) : selected speakerbox module number						*/
/* arguments (OUT): microphone threshold									*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDSetMicrophoneCompression (int nFsNum, int nCompression);
/* Sets the microphone compression											*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone compression									*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDGetMicrophoneCompression (int nFsNum, int *nCompression);
/* Returns the microphone compression										*/
/* arguments (IN) : selected speakerbox module number						*/
/* arguments (OUT): microphone compression									*/
/* return value   : command status : 0 == OK, else error code				*/

/** Specific device versions **/
TIPROHIDAPI_API int HIDSetMicrophoneThresholdEx (int nFsNum, int nThreshold, int nDevice);
/* Sets the specific device's microphone threshold							*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone threshold									*/
/*				  : device to set (handsfree, handset/headset)				*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDSetMicrophoneCompressionEx (int nFsNum, int nCompression, int nDevice);
/* Sets the specific device's microphone compression					*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone compression									*/
/*				  : device to set (handsfree, handset/headset)				*/
/* return value   : command status : 0 == OK, else error code				*/

/* Supported if firmware with blink functionality							*/
TIPROHIDAPI_API int HIDSetSbxLEDBlinkSpeed (int nFsNum, int nTBlinkA, int nTBlinkB);
/* Sets the LED blink timings												*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : ON time in ms (1..5000)									*/
/*				  : OFF time in ms (1..5000)								*/
/* return value   : command status : 0 == OK, else error code				*/


/****************************************************************************/
/*		CHAMELEON FUNCTIONS													*/
/****************************************************************************/

TIPROHIDAPI_API int HIDChmGoOnline (int nChmNum);
/* Puts Chameleon into On-Line operating mode.                              */
/* arguments (IN)  : selected Chameleon module number						*/
/* arguments (OUT) : none													*/
/* return value    : command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDChmDisplayIcon (int nChmNum, struct CHM_ICON_DATA IconData);
/* Displays the icon from the library on the specified key.                 */
/* arguments (IN)  : selected Chameleon module number                       */
/*				   : address of the key (0x00-0x0F)                         */
/*				   : video type of the icon (NORMAL or INVERSE)             */
/*				   : index of the icon in the icon library                  */
/* arguments (OUT) : none													*/
/* return value    : command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDChmDisplayBitmap (int nChmNum, int nKeyAddr, int nVideoType, struct CHM_BITMAP_DATA BitmapData);
/* Displays the bitmap on the specified key.                 */
/* arguments (IN)  : selected Chameleon module number                       */
/*				   : address of the key (0x00-0x0F)                         */
/*				   : video type of the icon (NORMAL or INVERSE)             */
/*				   : bitmap data							                */
/* arguments (OUT) : none													*/
/* return value    : command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDChmChangeBacklighting (int nChmNum, struct CHM_BACKLIGHTING_DATA BacklightingData);
/* Sets the backlighting parameters for the addressed LCD key.              */
/* arguments (IN)  : selected Chameleon module number                       */
/*				   : address of the key (0x00-0x0F)                         */
/*				   : first color for the key backlight			            */
/*				   : alternate color for the key backlight                  */
/*				   : alternating frequency (switching from color1 to color2)*/
/* arguments (OUT) : none													*/
/* return value    : command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDChmGoToPage (int nChmNum, int nPageNumber);
/* Loads the selected page settings from the configuration memory.			*/
/* arguments (IN)  : selected Chameleon module number                       */
/*				   : page number					                        */
/* arguments (OUT) : none													*/
/* return value    : command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDChmGetPageNumber (int nChmNum, int *nPageNumber);
/* Returns current page number.												*/
/* arguments (IN)  : selected Chameleon module number                       */
/* arguments (OUT) : current page number									*/
/* return value    : command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDChmGetNumberOfPages (int nChmNum, int *nPages);
/* Returns number of preprogrammed pages.									*/
/* arguments (IN)  : selected Chameleon module number                       */
/* arguments (OUT) : number of preprogrammed pages							*/
/* return value    : command status : 0 == OK, else error code			    */



/****************************************************************************/
/*		BF104 FUNCTIONS														*/
/****************************************************************************/
/*																			*/
/* Old functions for BeFree and Speakerbox are updated to support new		*/
/* functionality. Some functions are calling old functions with correct		*/
/* paramters.																*/
/*																			*/
/****************************************************************************/

TIPROHIDAPI_API int HIDBF10SetLuminance (int nIndex);
/* Sets luminance for both stripe and LCD backlight			                */
/* arguments (IN)  : lumninance index (0-darkest; 10-brightest)             */
/* arguments (OUT) : none													*/
/* return value    : command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10TouchscreenDisable(void);
/* Disables touchscreen														*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10TouchscreenEnable(void);
/* Enables touchscreen														*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10SetSpeakerLevel(int nLevel);
/* Sets the level of the speakers											*/
/* arguments (IN)	: speaker level			 								*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10GetSpeakerLevel(int *nLevel);
/* Returns the level of the speakers										*/
/* arguments (OUT)	: speaker level			 								*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10GetPTTKeyState (int *nState);
/* Returns the state of the PTT key											*/
/* arguments (OUT)	: state of the key (KEY_PRESSED / KEY_RELEASED)			*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10SetPTTKeyLEDState (int nState);
/* Sets the LED state of illuminated PTT key								*/
/* arguments (IN)	: state of the LED (LED_ON/LED_OFF/LED_BLINK)			*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10SetPTTKeyLEDStateEx (int nState, int nTBlinkOn, int nTBlinkOff);
/* Sets the operation of the illuminated PTT key with more paramters		*/
/* arguments (IN)	: state of the LED (LED_ON/LED_OFF/LED_BLINK)			*/
/*					: On period for blink mode (ms)							*/
/*					: Off period for blink mode (ms)						*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10GetPTTKeyLEDState (int *nState);
/* Returns the LED state of the illuminated PTT Key							*/
/* arguments (OUT)	: state of the LED (LED_ON/LED_OFF/LED_BLINK)			*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10MuteMicrophone (int nMute);
/* Mutes/un-mutes the microphone signal										*/
/* arguments (IN)	: mute/un-mute microphone 								*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10SetAutoLuminance (int nAutoMode);
/* Sets luminance for both stripe and LCD backlight to be controlled by		*/
/* ambient light sensor.													*/
/* arguments (IN)	: Auto luminance mode									*/
/* return value		: command status : 0 == OK, else error code			    */

TIPROHIDAPI_API int HIDBF10GetAutoLuminance (int *nAutoMode);
/* Returns the mode of the auto controlled luminance						*/
/* arguments (OUT)	: Auto luminance mode									*/
/* return value		: command status : 0 == OK, else error code			    */

// functions that are also missing in the speakerbox part
TIPROHIDAPI_API int HIDBF10SetMicrophoneLevel (int nLevel);
/* Sets the level of the microphone signal									*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphne level									        */
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDBF10SetMicrophoneOptimalDistance (int nDistance);
/* Sets the optimal distance of the handsfree microphone signal				*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone optimal distance								*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDBF10SetMicrophoneThreshold (int nThreshold);
/* Sets threshold for the microphone signal									*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone threshold									*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDBF10SetMicrophoneCompression (int nCompression);
/* Sets compression for the microphone signal								*/
/* arguments (IN) : selected speakerbox module number						*/
/*				  : microphone compression									*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDBF10SetAnalogAudio(int nSettings);
/* Sets the Analog audio options											*/
/* arguments (IN) : select which analog channel is added to the output		*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDBF10GetAnalogAudio(int *nSettings);
/* Returns Analog audio options												*/
/* arguments (OUT): returns which analog channel is added to the output		*/
/* return value   : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDBF10GetMicrophoneLevel (int *nLevel);
/* Returns the level of the microphone signal								*/
/* arguments (OUT) : microphone level										*/
/* return value  : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDBF10GetMicrophoneOptimalDistance (int *nRange);
/* Returns the optimal distance of the handsfree microphone signal			*/
/* arguments (OUT) : microphone optimal distance							*/
/* return value  : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDBF10GetMicrophoneThreshold (int *nThreshold);
/* Returns threshold for the microphone signal								*/
/* arguments (IN) : selected speakerbox module number						*/
/* arguments (OUT) : microphone threshold									*/
/* return value  : command status : 0 == OK, else error code				*/

TIPROHIDAPI_API int HIDBF10GetMicrophoneCompression (int *nCompression);
/* Returns compression for the microphone signal							*/
/* arguments (IN) : selected speakerbox module number						*/
/* arguments (OUT) : microphone compression									*/
/* return value  : command status : 0 == OK, else error code				*/

/****************************************************************************/
/*		HIDAPI telephony functions (HID telephony hardware required)        */
/****************************************************************************/

TIPROHIDAPI_API int HIDDetectTelephonyDevices();
TIPROHIDAPI_API int HIDGetNumOfDetectedTelephonyDevices();
TIPROHIDAPI_API int HIDGetTelephonyDeviceProductString(USHORT hidIx, PVOID pString, ULONG lBufferLen);
TIPROHIDAPI_API int HIDGetTelephonyDevice_VID_PID(USHORT hidIx, USHORT *nVID, USHORT *nPID);
TIPROHIDAPI_API int HIDGetTelephonyDeviceManufacturerString(USHORT hidIx, PVOID pString, ULONG lBufferLen);

// currently not supported in hardware, not to be used
TIPROHIDAPI_API int HIDGetTelephonyDeviceSNString(USHORT hidIx, PVOID pString, ULONG lBufferLen);


#if 1	// new combined function for registring callbacks
// callback functions for returning pressed/released keys and status of the thread:
//
// fnCallback(USHORT nID, USHORT nUsagePage, USHORT nLinkUsage, USHORT nUsage, bool bPressed);
//
// Parameters:
//		nID;					// ID of the telephony device (supporting more then one telephony devices on the same PC)
//		nUsagePage;				// top collection usage page (for now always 0x0b = Telephony)
//		nLinkUsage;				// usage of the specific link collection (0x01 = Phone, 0x06 = Key Pad, 0x07 = Progrmable Button)
//		nUsage;					// usage at the specific collection
//		bPressed;				// key pressed = TRUE or released = FALSE
//
// fnKeyStatusCallback(USHORT nID, int nStatus, int nErrCode, int nRFUParam);
//
// Parameters:
//		nID;					// ID of the telephony device (supporting more then one telephony devices on the same PC)
//		nStatus;				// Status of the thread ( to be defined later... for instance 0x00 = Stopped, 0x01 = Running ... )
//		nErrCode;				// ErrCode for reported status ( to be defined later )
//		nRFUParam;				// Reserved for future use ( to be defined later )
//
// fnKeyStatusCallback can be NULL if not needed
//
// If Visual Studio 2010 or later is used callback can be defined inside of the class using std:bind
#if _MSC_VER > 1500
    #define _VARIADIC_MAX 10
    #include <functional>
    typedef std::function<int(USHORT,USHORT,USHORT,USHORT,bool)> tfnCallbackEx;
    typedef std::function<int(USHORT,int,int,int)> tfnThreadStatusEx;
    TIPROHIDAPI_API int HIDRegisterTelephonyCallbacksEx(USHORT hidIx, tfnCallbackEx fnKeyCallback, tfnThreadStatusEx fnKeyStatusCallback);
#endif
//
// example how to register callback function that is part of a class:
//
//	using namespace std::placeholders;
//  HIDRegisterTelephonyKeysCallbackEx(0,std::bind(&CExampleDlg::OnTelKeyPress,this,_1,_2,_3,_4,_5),NULL);
//
// else normal callback function defintion
typedef int (__stdcall *tfnCallback)(USHORT, USHORT, USHORT, USHORT, bool);
typedef int (__stdcall *tfnThreadStatus)(USHORT, int, int, int);
TIPROHIDAPI_API int HIDRegisterTelephonyCallbacks(USHORT hidIx, tfnCallback fnKeyCallback, tfnThreadStatus fnKeyStatusCallback);

#else
// callback function for returning pressed/released keys: fnCallback(USHORT nID, USHORT nUsagePage, USHORT nLinkUsage, USHORT nUsage, bool bPressed);
//
// Parameters:
//		nID;					// ID of the telephony device (supporting more then one telephony devices on the same PC)
//		nUsagePage;				// top collection usage page (for now always 0x0b = Telephony)
//		nLinkUsage;				// usage of the specific link collection (0x01 = Phone, 0x06 = Key Pad, 0x07 = Progrmable Button)
//		nUsage;					// usage at the specific collection
//		bPressed;				// key pressed = TRUE or released = FALSE
//
// If Visual Studio 2010 or later is used callback can be defined inside of the class using std:bind
#if _MSC_VER > 1500
    #define _VARIADIC_MAX 10
    #include <functional>
    typedef std::function<int(USHORT,USHORT,USHORT,USHORT,bool)> tfnCallbackEx;
    TIPROHIDAPI_API int HIDRegisterTelephonyKeysCallbackEx(USHORT hidIx, tfnCallbackEx fnKeyCallback);
#endif
//
// example how to register callback function that is part of a class:
//
//	using namespace std::placeholders;
//  HIDRegisterTelephonyKeysCallbackEx(0,std::bind(&CExampleDlg::OnTelKeyPress,this,_1,_2,_3,_4,_5));
//
// else normal callback function defintion
typedef int (__stdcall *tfnCallback)(USHORT, USHORT, USHORT, USHORT, bool);
TIPROHIDAPI_API int HIDRegisterTelephonyKeysCallback(USHORT hidIx, tfnCallback fnKeyCallback);


// prepared for future development
// callback function for returning status of the thread: fnThreadStatus(USHORT nID, int nStatus, int nErrCode, int nRFUParam);
//
// Parameters:
//		nID;					// ID of the telephony device (supporting more then one telephony devices on the same PC)
//		nStatus;				// Status of the thread ( to be defined later... for instance 0x00 = Stopped, 0x01 = Running ... )
//		nErrCode;				// ErrCode for reported status ( to be defined later )
//		nRFUParam;				// Reserved for future use ( to be defined later )
// If Visual Studio 2010 or later is used callback can be defined inside of the class using std:bind
#if _MSC_VER > 1500
    typedef std::function<int(USHORT,int,int,int)> tfnThreadStatusEx;
    TIPROHIDAPI_API int HIDRegisterTelephonyKeysStatusCallbackEx(USHORT hidIx, tfnThreadStatusEx fnKeyStatusCallback);
#endif
typedef int (__stdcall *tfnThreadStatus)(USHORT, int, int, int);
TIPROHIDAPI_API int HIDRegisterTelephonyKeysStatusCallback(USHORT hidIx, tfnThreadStatus fnKeyStatusCallback);
#endif

TIPROHIDAPI_API int HIDStopTelephonyKeyDevice(USHORT hidIx);
TIPROHIDAPI_API int HIDGetTelephonyDevicePath(USHORT hidIx, PVOID pString, ULONG lBufferLen);



/* END */

TIPROHIDAPI_API int HIDGetControllerInfo(int *nVerMaj, int *nVerMin, int *nVerBuild,int *nVerCustom, int *nFWLevel);
TIPROHIDAPI_API int HIDGetModuleVersion(int nIndex, unsigned char *nVerMaj, unsigned char *nVerMin, unsigned char *nVerBuild);
#endif


#endif // TYPES_H

