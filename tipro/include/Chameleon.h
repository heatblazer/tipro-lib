/****************************************************************************/
/*		CHAMELEON DEFINES                                                   */
/****************************************************************************/

#define CHM_VIDEO_REVERSE			0x00
#define CHM_VIDEO_NORMAL			0x01

#define CHM_BLINK_OFF				0x00
#define CHM_BLINK_SLOW				0x01
#define CHM_BLINK_NORM				0x02
#define CHM_BLINK_FAST				0x03

#define CHM_COLOR_NONE				0x00
#define CHM_COLOR_BLUE				0x03
#define CHM_COLOR_GREEN				0x0C
#define CHM_COLOR_RED				0x30

/****************************************************************************/
/*		CHAMELEON DATA TYPE                                                 */
/****************************************************************************/

// bitmap data structure
struct CHM_BITMAP_DATA
{
	unsigned char nData[64];
};

struct CHM_KEY_ICON
{
	int nKey;
	int nVideoType;
	int nIconIndex;
};

struct CHM_KEY_BACKLIGHTING
{
	int nKey;
	int nColor1;
	int nColor2;
	int nFreq;
};

struct CHM_ICON_DATA
{
	int nLength;
	CHM_KEY_ICON keyData[16];
};

struct CHM_BACKLIGHTING_DATA
{
	int nLength;
	CHM_KEY_BACKLIGHTING keyData[16];
};
