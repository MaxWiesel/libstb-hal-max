#ifndef __CS_FRONTPANEL_H__
#define __CS_FRONTPANEL_H__

#define VFDDISPLAYCHARS      0xc0425a00
#define VFDWRITECGRAM        0x40425a01
#define VFDBRIGHTNESS        0xc0425a03
#define VFDPWRLED            0xc0425a04
#define VFDDRIVERINIT        0xc0425a08
#define VFDICONDISPLAYONOFF  0xc0425a0a
#define VFDDISPLAYWRITEONOFF 0xc0425a05

#define VFDCLEARICONS        0xc0425af6
#define VFDSETRF             0xc0425af7
#define VFDSETFAN            0xc0425af8
#define VFDGETWAKEUPMODE     0xc0425af9
#define VFDGETTIME           0xc0425afa
#define VFDSETTIME           0xc0425afb
#define VFDSTANDBY           0xc0425afc
#define VFDREBOOT            0xc0425afd
#define VFDSETLED            0xc0425afe
#define VFDSETMODE           0xc0425aff

#define VFDGETWAKEUPTIME     0xc0425b00
#define VFDGETVERSION        0xc0425b01
#define VFDSETDISPLAYTIME    0xc0425b02
#define VFDSETTIMEMODE       0xc0425b03
#define VFDDISPLAYCLR        0xc0425b00

typedef enum
{
	FP_ICON_USB = 0x10,
	FP_ICON_HD,
	FP_ICON_HDD,
	FP_ICON_LOCK,
	FP_ICON_BT,
	FP_ICON_MP3,
	FP_ICON_MUSIC,
	FP_ICON_DD,
	FP_ICON_MAIL,
	FP_ICON_MUTE,
	FP_ICON_PLAY,
	FP_ICON_PAUSE,
	FP_ICON_FF,
	FP_ICON_FR,
	FP_ICON_REC,
	FP_ICON_CLOCK,
	FP_ICON_CAM1 = FP_ICON_REC,
	FP_ICON_TV = FP_ICON_MUSIC,
	FP_ICON_RADIO = FP_ICON_MUSIC,
	FP_ICON_RECORD = FP_ICON_REC,
	FP_ICON_DOWNLOAD,
	FP_ICON_TIMESHIFT,
	FP_ICON_MAX
} fp_icon;

typedef enum
{
	FP_FLAG_NONE              = 0x00,
	FP_FLAG_SCROLL_ON         = 0x01, /* switch scrolling on */
	FP_FLAG_SCROLL_LTR        = 0x02, /* scroll from left to rightinstead of default right to left direction (i.e. for arabic text) */
	FP_FLAG_SCROLL_SIO        = 0x04, /* start/stop scrolling with empty screen (scroll in/out) */
	FP_FLAG_SCROLL_DELAY      = 0x08, /* delayed scroll start */
	FP_FLAG_ALIGN_LEFT        = 0x10, /* align the text in display from the left (default) */
	FP_FLAG_ALIGN_RIGHT       = 0x20, /* align the text in display from the right (arabic) */
	FP_FLAG_UPDATE_SCROLL_POS = 0x40, /* update the current position for scrolling */
} fp_flag;

typedef struct
{
	unsigned char brightness;
	unsigned char flags;
	unsigned char current_hour;
	unsigned char current_minute;
	unsigned char timer_minutes_hi;
	unsigned char timer_minutes_lo;
} fp_standby_data_t;

typedef enum
{
	FP_LED_1_ON  = 0x81,
	FP_LED_2_ON  = 0x82,
	FP_LED_3_ON  = 0x83,
	FP_LED_1_OFF = 0x01,
	FP_LED_2_OFF = 0x02,
	FP_LED_3_OFF = 0x03
} fp_led_ctrl_t;

typedef struct
{
	unsigned char source;
	unsigned char time_minutes_hi;
	unsigned char time_minutes_lo;
} fp_wakeup_data_t;

typedef enum
{
	FP_WAKEUP_SOURCE_TIMER  = 0x01,
	FP_WAKEUP_SOURCE_BUTTON = 0x02,
	FP_WAKEUP_SOURCE_REMOTE = 0x04,
	FP_WAKEUP_SOURCE_PWLOST = 0x7F,
	FP_WAKEUP_SOURCE_POWER  = 0xFF
} fp_wakeup_source;

typedef struct
{
	unsigned short addr;
	unsigned short cmd;
} fp_standby_cmd_data_t;

typedef enum
{
	FP_DISPLAY_TEXT_NONE = 0,
	FP_DISPLAY_TEXT_LIMITED,
	FP_DISPLAY_TEXT_ALL
} fp_display_text_type_t;

typedef enum
{
	FP_DISPLAY_TYPE_NONE = 0,
	FP_DISPLAY_TYPE_VFD,
	FP_DISPLAY_TYPE_OLED,
	FP_DISPLAY_TYPE_LED_SEGMENT
} fp_display_type_t;

typedef struct
{
	fp_display_type_t display_type;
	unsigned short xres, yres;
	unsigned int segment_count;
	fp_display_text_type_t text_support;
	bool number_support;
} fp_display_caps_t;

#endif // __CS_FRONTPANEL_H__
