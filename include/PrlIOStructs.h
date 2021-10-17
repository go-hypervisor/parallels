///////////////////////////////////////////////////////////////////////////////
///
/// PrlIOStructs.h
///
/// This file is the part of parallels public sdk library
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_IO_STRUCTS_H__
#define __PARALLELS_IO_STRUCTS_H__

#include "PrlTypes.h"
#include "PrlEnums.h"

#ifdef _WIN_
#pragma pack(push, save_pack, 1)
#endif

#define PRL_IO_MAX_DISPLAYS 16
#define PRL_IO_MAX_ENCODINGS 32
#define PRL_IO_MAX_AUDIO_ENCODINGS 8
#define PRL_PROXY_MAX_HOSTS 16

#define PRL_IO_GAMMARAMP_DEFAULT 1
#define PRL_IO_GAMMARAMP_RGB256x3x16 2
#define PRL_IO_GAMMARAMP_DXGI1 3

typedef PRL_UINT32 PRL_IO_PALETTE[256];

typedef struct _PRL_IO_SCREEN_SIZE
{
	PRL_UINT32 width;
	PRL_UINT32 height;
	PRL_UINT32 depth;
	PRL_INT32 lineBytes;

} __attribute__((packed)) PRL_IO_SCREEN_SIZE ;
typedef PRL_IO_SCREEN_SIZE* PRL_IO_SCREEN_SIZE_PTR;

typedef struct _PRL_IO_DISPLAY_SCREEN_SIZE
{
	PRL_UINT32 width;
	PRL_UINT32 height;
	PRL_UINT32 depth;
	PRL_INT32 lineBytes;
	PRL_UINT32 display;
	PRL_INT32 displayX;
	PRL_INT32 displayY;

} __attribute__((packed)) PRL_IO_DISPLAY_SCREEN_SIZE ;
typedef PRL_IO_DISPLAY_SCREEN_SIZE* PRL_IO_DISPLAY_SCREEN_SIZE_PTR;

typedef struct _PRL_IO_DPI_DISPLAY_SCREEN_SIZE
{
	PRL_IO_DISPLAY_SCREEN_SIZE display;
	PRL_INT32	dpi;
	///	@brief See PRL_DISPLAY_CONFIG_MODE enum for possible 'flags' values
	PRL_UINT32	flags;
} __attribute__((packed)) PRL_IO_DPI_DISPLAY_SCREEN_SIZE ;
typedef PRL_IO_DPI_DISPLAY_SCREEN_SIZE* PRL_IO_DPI_DISPLAY_SCREEN_SIZE_PTR;

typedef struct _PRL_IO_DISPLAY_PALETTE
{
	PRL_IO_PALETTE palette;
	PRL_UINT32 display;

} __attribute__((packed)) PRL_IO_DISPLAY_PALETTE ;
typedef PRL_IO_DISPLAY_PALETTE* PRL_IO_DISPLAY_PALETTE_PTR;

typedef struct _PRL_IO_DISPLAY_GAMMA
{
	PRL_UINT32 display;
	PRL_UINT32 type;
	PRL_UINT32 gammaSize;
	PRL_UINT32 reserved;

} __attribute__((packed)) PRL_IO_DISPLAY_GAMMA ;
typedef PRL_IO_DISPLAY_GAMMA* PRL_IO_DISPLAY_GAMMA_PTR;

typedef struct D3DDDI_DXGI_RGB {
	float Red;
	float Green;
	float Blue;
}  __attribute__((packed)) D3DDDI_DXGI_RGB;
typedef struct _D3DDDI_GAMMA_RAMP_DXGI_1 {
	D3DDDI_DXGI_RGB Scale;
	D3DDDI_DXGI_RGB Offset;
	D3DDDI_DXGI_RGB GammaCurve[1025];
}  __attribute__((packed)) D3DDDI_GAMMA_RAMP_DXGI_1;


typedef struct _PRL_IO_SCREEN_REGION
{
	PRL_UINT32 x;
	PRL_UINT32 y;
	PRL_UINT32 width;
	PRL_UINT32 height;

} __attribute__((packed)) PRL_IO_SCREEN_REGION ;
typedef PRL_IO_SCREEN_REGION* PRL_IO_SCREEN_REGION_PTR;

typedef struct _PRL_IO_DISPLAY_SCREEN_REGION
{
	PRL_UINT32 x;
	PRL_UINT32 y;
	PRL_UINT32 width;
	PRL_UINT32 height;
	PRL_UINT32 display;

} __attribute__((packed)) PRL_IO_DISPLAY_SCREEN_REGION ;
typedef PRL_IO_DISPLAY_SCREEN_REGION* PRL_IO_DISPLAY_SCREEN_REGION_PTR;

typedef struct _PRL_IO_SCREEN_BUFFER_REGION
{
	PRL_UINT32 x;
	PRL_UINT32 y;
	PRL_UINT32 width;
	PRL_UINT32 height;
	PRL_UINT32 scaleWidth;
	PRL_UINT32 scaleHeight;
	PRL_UINT32 display;

} __attribute__((packed)) PRL_IO_SCREEN_BUFFER_REGION ;
typedef PRL_IO_SCREEN_BUFFER_REGION* PRL_IO_SCREEN_BUFFER_REGION_PTR;

typedef struct _PRL_IO_DISPLAY_RESOLUTION_CONFIRMATION
{
	PRL_BOOL success;
	/// @brief Not used now
	PRL_UINT32	flags;
} __attribute__((packed)) PRL_IO_DISPLAY_RESOLUTION_CONFIRMATION ;

typedef struct _PRL_IO_DISPLAY_RESOLUTION_CONFIRMATION_EX
{
	PRL_BOOL success;
	/// @brief Not used now
	PRL_UINT32 flags;
	PRL_UINT64 timestamp;
	PRL_UINT8 reserved[64];
} __attribute__((packed)) PRL_IO_DISPLAY_RESOLUTION_CONFIRMATION_EX ;

typedef struct _PRL_IO_KEYBOARD_SCANCODE
{
	PRL_UINT16 key;
	PRL_UINT16 event;

} __attribute__((packed)) PRL_IO_KEYBOARD_SCANCODE ;
typedef PRL_IO_KEYBOARD_SCANCODE* PRL_IO_KEYBOARD_SCANCODE_PTR;

typedef struct _PRL_IO_KEYBOARD_LEDS
{
	PRL_UINT32 ledsState;

} __attribute__((packed)) PRL_IO_KEYBOARD_LEDS ;
typedef PRL_IO_KEYBOARD_LEDS* PRL_IO_KEYBOARD_LEDS_PTR;

typedef struct _PRL_IO_KEYBOARD_OPTIMIZATION
{
	PRL_UINT32 mode;

} __attribute__((packed)) PRL_IO_KEYBOARD_OPTIMIZATION ;
typedef PRL_IO_KEYBOARD_OPTIMIZATION* PRL_IO_KEYBOARD_OPTIMIZATION_PTR;

typedef struct _PRL_IO_MOUSE_EVENT
{
	PRL_INT32 x;
	PRL_INT32 y;
	PRL_INT32 z;
	PRL_UINT32 buttons;

} __attribute__((packed)) PRL_IO_MOUSE_EVENT ;
typedef PRL_IO_MOUSE_EVENT* PRL_IO_MOUSE_EVENT_PTR;

typedef struct _PRL_IO_MOUSE_EVENT_EX
{
	PRL_INT32 x;
	PRL_INT32 y;
	PRL_INT32 z;
	PRL_UINT32 buttons;

	PRL_INT32 w;
} __attribute__((packed)) PRL_IO_MOUSE_EVENT_EX ;
typedef PRL_IO_MOUSE_EVENT_EX* PRL_IO_MOUSE_EVENT_EX_PTR;

typedef struct _PRL_IO_MOUSE_EVENT_EX2
{
	PRL_INT32 x;
	PRL_INT32 y;
	PRL_INT32 z;
	PRL_UINT32 buttons;

	PRL_INT32 w;

	PRL_INT32 z120;
	PRL_INT32 w120;
} __attribute__((packed)) PRL_IO_MOUSE_EVENT_EX2 ;
typedef PRL_IO_MOUSE_EVENT_EX2* PRL_IO_MOUSE_EVENT_EX2_PTR;

typedef struct _PRL_IO_MOUSE_EVENT_EX3
{
	PRL_INT32 x;
	PRL_INT32 y;
	PRL_INT32 z;
	PRL_UINT32 buttons;

	PRL_INT32 w;

	PRL_INT32 z120;
	PRL_INT32 w120;

	PRL_UINT32 pressure;
} __attribute__((packed)) PRL_IO_MOUSE_EVENT_EX3 ;
typedef PRL_IO_MOUSE_EVENT_EX3* PRL_IO_MOUSE_EVENT_EX3_PTR;

typedef struct _PRL_IO_MOUSE_EVENT_EX4
{
	PRL_INT32 x;
	PRL_INT32 y;
	PRL_INT32 z;
	PRL_UINT32 buttons;

	PRL_INT32 w;

	PRL_INT32 z120;
	PRL_INT32 w120;

	PRL_UINT32 pressure;
	PRL_INT32 x_tilt;
	PRL_INT32 y_tilt;
	PRL_UINT32 twist;
} __attribute__((packed)) PRL_IO_MOUSE_EVENT_EX4 ;
typedef PRL_IO_MOUSE_EVENT_EX4* PRL_IO_MOUSE_EVENT_EX4_PTR;

typedef struct _PRL_IO_GRACEFUL_SHUTDOWN
{
	PRL_UINT32 kind;

} __attribute__((packed)) PRL_IO_GRACEFUL_SHUTDOWN ;
typedef PRL_IO_GRACEFUL_SHUTDOWN* PRL_IO_GRACEFUL_SHUTDOWN_PTR;

typedef struct _PRL_IO_DESKTOP_UTILITIES_STATE
{
	PRL_UINT32	bDesktopShown;
	PRL_UINT32	bTaskbarShown;
} __attribute__((packed)) PRL_IO_DESKTOP_UTILITIES_STATE ;
typedef PRL_IO_DESKTOP_UTILITIES_STATE* PRL_IO_DESKTOP_UTILITIES_STATE_PTR;

typedef struct _PRL_IO_LANGUAGE_HOTKEYS
{
	PRL_UINT32	LanguageHotkey;
	PRL_UINT32	LayoutHotkey;
} __attribute__((packed)) PRL_IO_LANGUAGE_HOTKEYS ;
typedef PRL_IO_LANGUAGE_HOTKEYS* PRL_IO_LANGUAGE_HOTKEYS_PTR;

typedef struct _PRL_IO_SCREEN_SURFACE
{
	PRL_UINT32 windowId;
	PRL_UINT32 surfaceId;
	PRL_INT32  scrollX;
	PRL_INT32  scrollY;
	PRL_UINT32 width;
	PRL_UINT32 height;
	PRL_UINT32 display;

} __attribute__((packed)) PRL_IO_SCREEN_SURFACE ;
typedef PRL_IO_SCREEN_SURFACE* PRL_IO_SCREEN_SURFACE_PTR;

// linux/EGL DRM/DMA surface protocol
typedef struct _PRL_IO_SCREEN_SURFACE_EX
{
	PRL_UINT32 windowId;
	PRL_INT32 surfaceId;
	PRL_INT32  scrollX;
	PRL_INT32  scrollY;
	PRL_UINT32 width;
	PRL_UINT32 height;
	PRL_UINT32 display;

	PRL_UINT32 fourCC;
	PRL_UINT32 offset;
	PRL_UINT32 stride;
	PRL_UINT32 modifierHi;
	PRL_UINT32 modifierLo;

} __attribute__((packed)) PRL_IO_SCREEN_SURFACE_EX ;
typedef PRL_IO_SCREEN_SURFACE_EX* PRL_IO_SCREEN_SURFACE_EX_PTR;

typedef struct _PRL_IO_SCREEN_ENABLE_UPDATES
{
	PRL_UINT32 display;
	PRL_BOOL enable;
} __attribute__((packed)) PRL_IO_SCREEN_ENABLE_UPDATES ;
typedef PRL_IO_SCREEN_ENABLE_UPDATES* PRL_IO_SCREEN_ENABLE_UPDATES_PTR;

typedef struct _PRL_IO_SCREEN_CONTEXT_REQUEST
{
	PRL_UINT32 display;
	PRL_DOUBLE ctxScale;
	PRL_UINT32 ctxWidth;
	PRL_UINT32 ctxHeight;
	PRL_UINT32 colorspaceDisplayID;
} __attribute__((packed)) PRL_IO_SCREEN_CONTEXT_REQUEST ;
typedef PRL_IO_SCREEN_CONTEXT_REQUEST* PRL_IO_SCREEN_CONTEXT_REQUEST_PTR;

typedef struct _PRL_IO_MOUSE_CURSOR
{
	PRL_UINT32 x;
	PRL_UINT32 y;
	PRL_UINT32 hotSpotX;
	PRL_UINT32 hotSpotY;
	PRL_UINT32 width;
	PRL_UINT32 height;

	// Cursor bitmap follows

} __attribute__((packed)) PRL_IO_MOUSE_CURSOR ;
typedef PRL_IO_MOUSE_CURSOR* PRL_IO_MOUSE_CURSOR_PTR;

typedef struct _PRL_IO_SLIDING_MOUSE
{
	PRL_UINT32 state;

} __attribute__((packed)) PRL_IO_SLIDING_MOUSE ;
typedef PRL_IO_SLIDING_MOUSE* PRL_IO_SLIDING_MOUSE_PTR;

typedef struct _PRL_IO_AVAILABLE_DISPLAYS
{
	PRL_UINT32 availableDisplays;
} __attribute__((packed)) PRL_IO_AVAILABLE_DISPLAYS ;
typedef PRL_IO_AVAILABLE_DISPLAYS* PRL_IO_AVAILABLE_DISPLAYS_PTR;

typedef struct _PRL_IO_DEVICE_USED
{
	PRL_UINT32 devType;
	PRL_UINT32 devIndex;
	PRL_UINT32 devAction;

} __attribute__((packed)) PRL_IO_DEVICE_USED ;
typedef PRL_IO_DEVICE_USED* PRL_IO_DEVICE_USED_PTR;

typedef struct _PRL_IO_GENERIC_BUFFER
{
	PRL_UINT32   size;
	PRL_VOID_PTR data;

} __attribute__((packed)) PRL_IO_GENERIC_BUFFER ;
typedef PRL_IO_GENERIC_BUFFER* PRL_IO_GENERIC_BUFFER_PTR;


///	@brief Structure that is used in TIS to represent versions
/**
* TIS - Tools Information Service
*
* @sa PRL_TIS_INT_VERSION, PRL_TIS_RECORD_INFO
*/
typedef struct _PRL_TIS_VERSION
{
	///	@brief Version major number
	PRL_UINT32 maj;
	///	@brief Version minor number
	PRL_UINT32 min;
	///	@brief Build number
	PRL_UINT32 bld;
	///	@brief Revision number
	PRL_UINT32 rev;

} __attribute__((packed)) PRL_TIS_VERSION ;
typedef PRL_TIS_VERSION* PRL_TIS_VERSION_PTR;

///	@brief Structure that is used in TIS to represent internal versions
/*
* TIS - Tools Information Service
*
* @sa PRL_TIS_VERSION, PRL_TIS_RECORD_INFO
*/
typedef struct _PRL_TIS_INT_VERSION
{
	///	@brief Internal version major number
	PRL_UINT32 maj;
	///	@brief Internal version minor number
	PRL_UINT32 min;

} __attribute__((packed)) PRL_TIS_INT_VERSION ;
typedef PRL_TIS_INT_VERSION* PRL_TIS_INT_VERSION_PTR;

///	@brief Fixed size information about TIS record
/*
* TIS - Tools Information Service
*
* @sa PRL_TIS_VERSION, PRL_TIS_INT_VERSION
*/
typedef struct _PRL_TIS_RECORD_INFO
{
	///	@brief Version associated with record
	PRL_TIS_VERSION version;
	///	@brief Internal version associated with record
	PRL_TIS_INT_VERSION intVersion;

} __attribute__((packed)) PRL_TIS_RECORD_INFO ;
typedef PRL_TIS_RECORD_INFO* PRL_TIS_RECORD_INFO_PTR;


///    @brief Structure that represents Parallels Tools Utility command
/** This structure is used to handle PET_IO_TOOLS_UTILITY_COMMAND.
 */
typedef struct _PRL_IO_TOOLS_UTILITY_COMMAND
{
	///     @brief Command identifier
	PRL_UINT32 command;
	///     @brief Set of 32 bit-flags that can be used to control
	///     command behaviour
	PRL_UINT32 flags;
	///     @brief Size of data that comes with command and "pointed" by
	///     data member
	PRL_UINT32 dataSize;

	// Data follows
}
__attribute__((packed)) PRL_IO_TOOLS_UTILITY_COMMAND ;
typedef PRL_IO_TOOLS_UTILITY_COMMAND* PRL_IO_TOOLS_UTILITY_COMMAND_PTR;


///	@brief Structure that represents Parallels Tools Shared Internet Applications data
/** This structure is used to handle message of PET_IO_TOOLS_SIA_DATA type.
*/
typedef struct _PRL_IO_TOOLS_SIA_DATA
{
	///	SIA protocol version
	PRL_UINT32	ver;
	///	SIA command
	PRL_UINT32	command;
	///	SIA command flags
	PRL_UINT32	flags;
	///	SIA data size
	PRL_UINT32	size;

	// data buffer follows
}
__attribute__((packed)) PRL_IO_TOOLS_SIA_DATA ;
typedef PRL_IO_TOOLS_SIA_DATA* PRL_IO_TOOLS_SIA_DATA_PTR;


typedef struct _PRL_IO_DYNRES_TOOLS_STATUS
{
	PRL_UINT32 status;
}
__attribute__((packed)) PRL_IO_DYNRES_TOOLS_STATUS ;
typedef PRL_IO_DYNRES_TOOLS_STATUS* PRL_IO_DYNRES_TOOLS_STATUS_PTR;


typedef struct _PRL_PROXY_CLIENT_INFO
{
	PRL_UINT32 structSize;              /**< Should be filled by the caller with actual structure size*/
	PRL_CHAR clientOptions[64];         /**< Reserved */
	PRL_UINT8 customerSupportUUID[16];  /**< Reserved */
	PRL_CHAR managerURL[256];           /**< Reserved */
}
__attribute__((packed)) PRL_PROXY_CLIENT_INFO ;
typedef PRL_PROXY_CLIENT_INFO* PRL_PROXY_CLIENT_INFO_PTR;


typedef struct _PRL_PROXY_REGISTRATION_INFO
{
	PRL_CHAR hostAddresses[PRL_PROXY_MAX_HOSTS][64]; /**< Host addresses which host listens to */
	PRL_INT32 hostAddressesSz;                       /**< Size of host addresses */
	PRL_CHAR hostName[64];                           /**< Short host name */
	PRL_UINT8 appUUID[16];                           /**< Application uuid */
	PRL_CHAR appVersion[32];                         /**< Application version */
	PRL_CHAR hostOptions[33];                        /**< Using for host icon hash transport */
	PRL_CHAR hostOsName[63];                         /**< Reserved */
	PRL_CHAR isoTimestamp[32];                       /**< Reserved */
}
__attribute__((packed)) PRL_PROXY_REGISTRATION_INFO ;
typedef PRL_PROXY_REGISTRATION_INFO* PRL_PROXY_REGISTRATION_INFO_PTR;

typedef struct _PRL_PROXY_HOST_INFO
{
	PRL_UINT8 hostUUID[16];                            /**< Proxy host uuid */
	PRL_CHAR brokerAddresses[PRL_PROXY_MAX_HOSTS][64]; /**< Broker addresses to which connection should be established */
	PRL_INT32 brokerAddressesSz;                       /**< Broker addresses size */
	PRL_PROXY_REGISTRATION_INFO info;                  /**< Host registration info */
}
__attribute__((packed)) PRL_PROXY_HOST_INFO ;
typedef PRL_PROXY_HOST_INFO* PRL_PROXY_HOST_INFO_PTR;

typedef struct _PRL_PROXY_GEO_INFO
{
	PRL_CHAR countryName[64];
	PRL_CHAR countryCode[3];
	PRL_CHAR region[3];
	PRL_CHAR city[64];
	PRL_CHAR postalCode[10];
}
__attribute__((packed)) PRL_PROXY_GEO_INFO ;
typedef PRL_PROXY_GEO_INFO* PRL_PROXY_GEO_INFO_PTR;

typedef struct _PRL_PROXY_HOST_INFO_EXT
{
	PRL_PROXY_HOST_INFO hostInfo;
	PRL_BOOL isOnline;                               /** Sign which specifies whether appropriate host online */
	PRL_PROXY_GEO_INFO_PTR geoInfo;
	struct _PRL_PROXY_HOST_INFO_EXT *next;
}
__attribute__((packed)) PRL_PROXY_HOST_INFO_EXT ;
typedef PRL_PROXY_HOST_INFO_EXT* PRL_PROXY_HOST_INFO_EXT_PTR;

typedef struct _PRL_PROXY_USER_DATA
{
	PRL_STR dataKey;            /**< Data identifier */
	PRL_INT32 dataVersion;      /**< Data version */
	PRL_VOID_PTR data;          /**< Pointer to the data buffer */
	PRL_UINT32 dataSize;        /**< Data size */
	struct _PRL_PROXY_USER_DATA *next; /**< Pointer to the next element */
}
__attribute__((packed)) PRL_PROXY_USER_DATA ;
typedef PRL_PROXY_USER_DATA* PRL_PROXY_USER_DATA_PTR;

typedef struct _PRL_PROXY_DATA_KEY
{
	PRL_STR dataKey;            /**< Data identifier */
	PRL_INT32 dataVersion;      /**< Data version */
	struct _PRL_PROXY_DATA_KEY *next; /**< Pointer to the next element */
}
__attribute__((packed)) PRL_PROXY_DATA_KEY ;
typedef PRL_PROXY_DATA_KEY* PRL_PROXY_DATA_KEY_PTR;

typedef struct _PRL_IO_MEMORY_INFO
{
	PRL_UINT64 ramOffset;
	PRL_UINT64 ramSize;
	PRL_UINT64 vramOffset;
	PRL_UINT64 vramSize;
	PRL_UINT32 filenameSize;

	// filename follows

} __attribute__((packed)) PRL_IO_MEMORY_INFO ;
typedef PRL_IO_MEMORY_INFO* PRL_IO_MEMORY_INFO_PTR;

typedef struct _PRL_IO_AUTH_REQUEST
{
	PRL_UINT8 sessionUuid[16];

} __attribute__((packed)) PRL_IO_AUTH_REQUEST ;
typedef PRL_IO_AUTH_REQUEST* PRL_IO_AUTH_REQUEST_PTR;

typedef struct _PRL_IO_AUTH_EXEC_REQUEST
{
	PRL_UINT8 sessionUuid[16];

} __attribute__((packed)) PRL_IO_AUTH_EXEC_REQUEST ;
typedef PRL_IO_AUTH_EXEC_REQUEST* PRL_IO_AUTH_EXEC_REQUEST_PTR;

typedef struct _PRL_IO_AUTH_RESPONSE
{
	PRL_UINT32 authResult;

} __attribute__((packed)) PRL_IO_AUTH_RESPONSE ;
typedef PRL_IO_AUTH_RESPONSE* PRL_IO_AUTH_RESPONSE_PTR;

typedef struct _PRL_IO_ATTACH_REQUEST
{
	PRL_UINT32 isClientLocal;
	PRL_UINT32 encodingType;
	PRL_UINT8  vmUuid[16];
	PRL_UINT32 attachFlags; /** Since 6.4 IO protocol version */

} __attribute__((packed)) PRL_IO_ATTACH_REQUEST ;
typedef PRL_IO_ATTACH_REQUEST* PRL_IO_ATTACH_REQUEST_PTR;

typedef struct _PRL_IO_ATTACH_RESPONSE
{
	PRL_UINT32 attachResult;
	PRL_UINT32 encodingResult;

} __attribute__((packed)) PRL_IO_ATTACH_RESPONSE ;
typedef PRL_IO_ATTACH_RESPONSE* PRL_IO_ATTACH_RESPONSE_PTR;

/**
 * Since 6.3 IO protocol version.
 */
typedef struct _PRL_IO_DISPLAY_ENCODING
{
	PRL_UINT32 encodingType;
	PRL_UINT32 encodingQuality;
	PRL_CHAR encodingName[32];

} __attribute__((packed)) PRL_IO_DISPLAY_ENCODING ;
typedef PRL_IO_DISPLAY_ENCODING* PRL_IO_DISPLAY_ENCODING_PTR;

/**
 * Since 6.3 IO protocol version.
 */
typedef struct _PRL_IO_DISPLAY_ENCODING_LIST
{
	PRL_UINT32 encodingListSz;
	PRL_UINT32 defaultEncodingIdx;
	PRL_IO_DISPLAY_ENCODING encodingList[PRL_IO_MAX_ENCODINGS];

} __attribute__((packed)) PRL_IO_DISPLAY_ENCODING_LIST ;
typedef PRL_IO_DISPLAY_ENCODING_LIST* PRL_IO_DISPLAY_ENCODING_LIST_PTR;

/**
 * This struct was implemented earlier 6.3 IO protocol version
 * but actually it was never used, so we can safely change it
 * and use for 6.3 version.
 */
typedef struct _PRL_IO_ENCODING_REQUEST
{
	PRL_UINT32 encodingType;

} __attribute__((packed)) PRL_IO_ENCODING_REQUEST ;
typedef PRL_IO_ENCODING_REQUEST* PRL_IO_ENCODING_REQUEST_PTR;

/**
 * This struct was implemented earlier 6.3 IO protocol version
 * but actually it was never used, so we can safely change it
 * and use for 6.3 version.
 */
typedef struct _PRL_IO_ENCODING_RESPONSE
{
	PRL_UINT32 encodingResult;
	PRL_UINT32 requestedEncodingType;

} __attribute__((packed)) PRL_IO_ENCODING_RESPONSE ;
typedef PRL_IO_ENCODING_RESPONSE* PRL_IO_ENCODING_RESPONSE_PTR;

typedef struct _PRL_IO_SCREEN_UPDATE
{
	PRL_UINT32 offset;
	PRL_UINT32 x;
	PRL_UINT32 y;
	PRL_UINT32 width;
	PRL_UINT32 height;
	PRL_UINT32 display;

	// for remote clients or screenshots buffers bitmap follows

} __attribute__((packed)) PRL_IO_SCREEN_UPDATE ;
typedef PRL_IO_SCREEN_UPDATE* PRL_IO_SCREEN_UPDATE_PTR;

/**
 * Audio support since 6.6 IO protocol version.
 */
typedef struct _PRL_IO_AUDIO_ENCODING
{
	PRL_UINT32 encodingType;
	PRL_UINT32 encodingQuality;
	PRL_UINT32 inout_bitRate;       /*< if 0 in request - correct value should
									  be choosen by Vm side */
	PRL_UINT32 inout_channelsNum;   /*< if 0 in request - correct value should
                                      be choosen by Vm side */
	PRL_UINT32 inout_sampleRate;    /*< if 0 in request - correct value should
                                      be choosen by Vm side */
	PRL_UINT32 inout_bitsPerChannel;/*< if 0 in request - correct value should
                                      be choosen by Vm side */

	PRL_UINT32 unused1;
	PRL_UINT32 unused2;
	PRL_UINT32 out_magicCookieSize;
	PRL_CHAR   out_magicCookie[4];

} __attribute__((packed)) PRL_IO_AUDIO_ENCODING ;
typedef PRL_IO_AUDIO_ENCODING* PRL_IO_AUDIO_ENCODING_PTR;

/**
 * Audio support since 6.6 IO protocol version.
 * NOTE: this struct is visible only on client side
 *       and nobody sends/reads it from network.
 */
typedef struct _PRL_IO_AUDIO_DATA
{
	PRL_UINT64 framesCounter;
	PRL_UINT16 framesNum;
	PRL_UINT16* frameSize;
	PRL_VOID* frameData;

} __attribute__((packed)) PRL_IO_AUDIO_DATA ;
typedef PRL_IO_AUDIO_DATA* PRL_IO_AUDIO_DATA_PTR;

/**
 * Audio support since 6.6 IO protocol version.
 */
typedef struct _PRL_IO_AUDIO_ENCODING_RESPONSE
{
	PRL_UINT32 encodingResult;
	PRL_IO_AUDIO_ENCODING encoding;
	// audio encoding is a dynamic structure
	// (because of magic cookies), so nothing
	// should be placed after it

} __attribute__((packed)) PRL_IO_AUDIO_ENCODING_RESPONSE ;
typedef PRL_IO_AUDIO_ENCODING_RESPONSE* PRL_IO_AUDIO_ENCODING_RESPONSE_PTR;

/**
 * Audio support since 6.6 IO protocol version.
 */
typedef struct _PRL_IO_AUDIO_ENCODING_LIST
{
	PRL_UINT32 encodingListSz;
	PRL_UINT32 defaultEncodingIdx;
	PRL_IO_AUDIO_ENCODING encodingList[PRL_IO_MAX_AUDIO_ENCODINGS];

} __attribute__((packed)) PRL_IO_AUDIO_ENCODING_LIST ;
typedef PRL_IO_AUDIO_ENCODING_LIST* PRL_IO_AUDIO_ENCODING_LIST_PTR;

typedef struct _PRL_IO_SET_TASKBAR_VISIBILITY
{
	PRL_UINT32	visibility;
} __attribute__((packed)) PRL_IO_SET_TASKBAR_VISIBILITY ;
typedef PRL_IO_SET_TASKBAR_VISIBILITY* PRL_IO_SET_TASKBAR_VISIBILITY_PTR;

typedef struct _PRL_IO_SET_POWER_SCHEME_SLEEP_ABILITY
{
	PRL_UINT32	ability;
} __attribute__((packed)) PRL_IO_SET_POWER_SCHEME_SLEEP_ABILITY ;
typedef PRL_IO_SET_POWER_SCHEME_SLEEP_ABILITY* PRL_IO_SET_POWER_SCHEME_SLEEP_ABILITY_PTR;

typedef struct _PRL_IO_TOOLS_MOVE_TASKBAR
{
	PRL_BOOL	bCoherenceOn;
	PRL_BOOL	bRelocateTaskBar;
	PRL_UINT32	uDockEdge;
	PRL_UINT32	uEdgeMask;
} __attribute__((packed)) PRL_IO_TOOLS_MOVE_TASKBAR ;
typedef PRL_IO_TOOLS_MOVE_TASKBAR* PRL_IO_TOOLS_MOVE_TASKBAR_PTR;

typedef struct _PRL_IO_GUEST_NOTIFY_COHERENCE_STATE
{
	// Inverted flag for compatibility with old versions (waiting for PrlVm_ToolsChangeScreenSaverState)
	PRL_UINT32	bCoherenceDisabled;
} __attribute__((packed)) PRL_IO_GUEST_NOTIFY_COHERENCE_STATE ;
typedef PRL_IO_GUEST_NOTIFY_COHERENCE_STATE* PRL_IO_GUEST_NOTIFY_COHERENCE_STATE_PTR;

typedef struct _PRL_IO_TOOLS_ADJUST_WORKING_AREA
{
	PRL_UINT32	bIsOn;
	PRL_UINT32	uDockEdge;

	PRL_INT32	iDockLeft;
	PRL_INT32	iDockTop;
	PRL_INT32	iDockRight;
	PRL_INT32	iDockBottom;
} __attribute__((packed)) PRL_IO_TOOLS_ADJUST_WORKING_AREA ;
typedef PRL_IO_TOOLS_ADJUST_WORKING_AREA* PRL_IO_TOOLS_ADJUST_WORKING_AREA_PTR;

typedef struct _PRL_IO_TOOLS_DISPLAY_INDENT
{
	PRL_INT32 displayX;
	PRL_INT32 displayY;
	PRL_UINT32 leftIndentSize;
	PRL_UINT32 topIndentSize;
	PRL_UINT32 rightIndentSize;
	PRL_UINT32 bottomIndentSize;
} PRL_IO_TOOLS_DISPLAY_INDENT;
typedef PRL_IO_TOOLS_DISPLAY_INDENT* PRL_IO_TOOLS_DISPLAY_INDENT_PTR;

typedef struct _PRL_IO_SHUTDOWN_RESULT
{
	PRL_UINT32	uRefused;
	PRL_UINT32	uResult;
} __attribute__((packed)) PRL_IO_SHUTDOWN_RESULT ;
typedef PRL_IO_SHUTDOWN_RESULT* PRL_IO_SHUTDOWN_RESULT_PTR;

#define PRL_TC_CLASS_MAX   16

typedef struct _PRL_STAT_NET_TRAFFIC {
	PRL_UINT64 incoming[PRL_TC_CLASS_MAX];
	PRL_UINT64 outgoing[PRL_TC_CLASS_MAX];
	PRL_UINT32 incoming_pkt[PRL_TC_CLASS_MAX];
	PRL_UINT32 outgoing_pkt[PRL_TC_CLASS_MAX];
} __attribute__((packed)) PRL_STAT_NET_TRAFFIC ;
typedef PRL_STAT_NET_TRAFFIC* PRL_STAT_NET_TRAFFIC_PTR;

typedef struct _PRL_UIEMU_VKEY
{
	/// @brief One of PRL_KEY values.
	PRL_UINT16 key;
	/// @brief One of PRL_KEY_EVENT values.
	PRL_UINT16 ev;
	/// @brief Must be 0.
	PRL_UINT32 reserved;
} __attribute__((packed)) PRL_UIEMU_VKEY ;
typedef PRL_UIEMU_VKEY* PRL_UIEMU_VKEY_PTR;
typedef const PRL_UIEMU_VKEY* PRL_CONST_UIEMU_VKEY_PTR;

typedef struct _PRL_UIEMU_ELEMENT_AT_POS
{
	///	@brief Query id as is
	PRL_INT32 queryId;
	///	@brief Query flags as is
	PRL_UINT32 queryFlags;
	///	@brief Position x (from query)
	PRL_INT32 posX;
	///	@brief Position y (from query)
	PRL_INT32 posY;
	// @brief Element bounding rect
	PRL_INT32 propRectLeft;
	// @brief Element bounding rect
	PRL_INT32 propRectTop;
	// @brief Element bounding rect
	PRL_INT32 propRectRight;
	// @brief Element bounding rect
	PRL_INT32 propRectBottom;
	// @brief Element control type (PRL_UIEMU_ELEMENT_CONTROL_TYPE)
	PRL_UINT32 propControlType;
	// @brief Element is a control (PRL_TERNARY_XXX)
	PRL_UINT8 propIsControl;
	// @brief Element is keyboard focusable (PRL_TERNARY_XXX)
	PRL_UINT8 propIsKbdFocusable;
	// @brief Element is enabled (PRL_TERNARY_XXX)
	PRL_UINT8 propIsEnabled;
	// @brief Element has readonly "value" (PRL_TERNARY_XXX)
	PRL_UINT8 propValueIsReadOnly;
	// @brief Element has readonly "range value" (PRL_TERNARY_XXX)
	PRL_UINT8 propRngValueIsReadOnly;
	// @brief Element is text edit and need show keyboard (PRL_TERNARY_XXX)
	PRL_UINT8 propIsTextEdit;
	// @brief User can input text in some other element (PRL_TERNARY_XXX)
	PRL_UINT8 propCanInputTextGlobal;
} __attribute__((packed)) PRL_UIEMU_ELEMENT_AT_POS ;
typedef PRL_UIEMU_ELEMENT_AT_POS* PRL_UIEMU_ELEMENT_AT_POS_PTR;
typedef const PRL_UIEMU_ELEMENT_AT_POS* PRL_CONST_UIEMU_ELEMENT_AT_POS_PTR;

typedef struct _PRL_UIEMU_CARET_INFO
{
	// @brief Query id as is
	PRL_INT32 queryId;
	// @brief Query flags as is
	PRL_UINT32 queryFlags;
	// @brief Caret rect is available
	PRL_UINT32 caretRectIsAvailable;
	// @brief Caret is out of control's visible area
	PRL_UINT32 caretIsOutOfView;
	// @brief Caret bounding rect
	PRL_INT32 caretRectLeft;
	// @brief Caret bounding rect
	PRL_INT32 caretRectTop;
	// @brief Caret bounding rect
	PRL_INT32 caretRectRight;
	// @brief Caret bounding rect
	PRL_INT32 caretRectBottom;
	PRL_UINT32 reserved1;
	PRL_UINT32 reserved2;
} __attribute__((packed)) PRL_UIEMU_CARET_INFO ;
typedef PRL_UIEMU_CARET_INFO* PRL_UIEMU_CARET_INFO_PTR;
typedef const PRL_UIEMU_CARET_INFO* PRL_CONST_CARET_INFO_PTR;

typedef struct _PRL_UIEMU_INPUT_INFO
{
	// @brief User can input text (PRL_TERNARY_XXX)
	PRL_UINT32 keyboardInputAvailable;
	// @brief Increases when focus changes
	PRL_UINT32 focusVersion;
	// @brief Focused element bounding rect
	PRL_INT32 focusElemRectLeft;
	// @brief Focused element bounding rect
	PRL_INT32 focusElemRectTop;
	// @brief Focused element bounding rect
	PRL_INT32 focusElemRectRight;
	// @brief Focused element bounding rect
	PRL_INT32 focusElemRectBottom;
	// @brief Must be 0.
	PRL_UINT8 reserved[4+4*4];
} __attribute__((packed)) PRL_UIEMU_INPUT_INFO ;
typedef PRL_UIEMU_INPUT_INFO* PRL_UIEMU_INPUT_INFO_PTR;
typedef const PRL_UIEMU_INPUT_INFO* PRL_CONST_UIEMU_INPUT_INFO_PTR;

typedef struct _PRL_UIEMU_AUTOKEYBOARD
{
	// @brief Show (PRL_TERNARY_TRUE) or hide (PRL_TERNARY_FALSE) keyboard
	PRL_UINT8 showKeyboardState;
	// @brief Must be 0.
	PRL_UINT8 reserved[3+4*4];
} __attribute__((packed)) PRL_UIEMU_AUTOKEYBOARD ;
typedef PRL_UIEMU_AUTOKEYBOARD* PRL_UIEMU_AUTOKEYBOARD_PTR;
typedef const PRL_UIEMU_AUTOKEYBOARD* PRL_CONST_UIEMU_AUTOKEYBOARD_PTR;

typedef struct _PRL_UIEMU_CURSOR_DESC
{
	PRL_DOUBLE width;
	PRL_DOUBLE height;
	PRL_DOUBLE hotx;
	PRL_DOUBLE hoty;
	// @brief Preserved across sessions
	PRL_UINT8 imageHash[8];
	PRL_UINT8 reserved[6*4];
} __attribute__((packed)) PRL_UIEMU_CURSOR_DESC ;
typedef PRL_UIEMU_CURSOR_DESC* PRL_UIEMU_CURSOR_DESC_PTR;
typedef const PRL_UIEMU_CURSOR_DESC* PRL_CONST_UIEMU_CURSOR_DESC_PTR;

typedef struct _PRL_UIEMU_CURSOR_POS
{
	PRL_DOUBLE x;
	PRL_DOUBLE y;
	PRL_UINT8 reserved[4*4];
} __attribute__((packed)) PRL_UIEMU_CURSOR_POS ;
typedef PRL_UIEMU_CURSOR_POS* PRL_UIEMU_CURSOR_POS_PTR;
typedef const PRL_UIEMU_CURSOR_POS* PRL_CONST_UIEMU_CURSOR_POS_PTR;

typedef struct _PRL_UIEMU_CURSOR_FORMAT
{
	PRL_UINT32 width;
	PRL_UINT32 height;
	// If first bit is set then in cursor image:
	// Pixel[ ALPHA RGB ] Displayed as
	//        0x00  0x00  transparent pixel
	//        0x7f  0xff  inverted background pixel
	//        0xff  0x00  black pixel
	//        0xff  0xff  white pixel
	PRL_UINT32 alphaXor;
	// Number of frames in animated cursor (0 if not animated).
	// Height of each frame is (height / frames).
	PRL_UINT32 frames;
	// Duration of each frame in animated cursor.
	PRL_UINT32 framet;
	PRL_UINT8 reserved[3*4];
} __attribute__((packed)) PRL_UIEMU_CURSOR_FORMAT ;
typedef PRL_UIEMU_CURSOR_FORMAT* PRL_UIEMU_CURSOR_FORMAT_PTR;
typedef const PRL_UIEMU_CURSOR_FORMAT* PRL_CONST_UIEMU_CURSOR_FORMAT_PTR;

typedef struct _PRL_UIEMU_GESTURE_EVENT
{
	PRL_UIEMU_GESTURE_TYPE type;
	PRL_UIEMU_GESTURE_STATE state;
	// Reserved fields must be set to 0
	PRL_UINT32 reserved1;
	PRL_UINT32 reserved2;
	// The data format depends on the 'type' field
	PRL_UINT8 gestureData[48];
} __attribute__((packed)) PRL_UIEMU_GESTURE_EVENT ;
typedef PRL_UIEMU_GESTURE_EVENT* PRL_UIEMU_GESTURE_EVENT_PTR;
typedef const PRL_UIEMU_GESTURE_EVENT* PRL_CONST_UIEMU_GESTURE_EVENT_PTR;

typedef struct _PRL_UIEMU_GESTURE_DATA_PINCH
{
	PRL_INT32 x;
	PRL_INT32 y;
	PRL_DOUBLE scale;
	PRL_DOUBLE velocity;
} __attribute__((packed)) PRL_UIEMU_GESTURE_DATA_PINCH ;
typedef PRL_UIEMU_GESTURE_DATA_PINCH* PRL_UIEMU_GESTURE_DATA_PINCH_PTR;
typedef const PRL_UIEMU_GESTURE_DATA_PINCH* PRL_CONST_UIEMU_GESTURE_DATA_PINCH_PTR;

typedef struct _PRL_UIEMU_GESTURE_DATA_SMARTZOOM
{
	PRL_INT32 x;
	PRL_INT32 y;
} __attribute__((packed)) PRL_UIEMU_GESTURE_DATA_SMARTZOOM ;
typedef PRL_UIEMU_GESTURE_DATA_SMARTZOOM* PRL_UIEMU_GESTURE_DATA_SMARTZOOM_PTR;
typedef const PRL_UIEMU_GESTURE_DATA_SMARTZOOM* PRL_CONST_UIEMU_GESTURE_DATA_SMARTZOOM_PTR;

typedef struct _PRL_CVSRC_OPEN_MODE
{
	PRL_UINT32 sessionId;
	PRL_UINT32 frameFormat;
	PRL_UINT32 frameWidth;
	PRL_UINT32 frameHeight;
	PRL_UINT32 frameBytesPerRow;
} __attribute__((packed)) PRL_CVSRC_OPEN_MODE ;
typedef PRL_CVSRC_OPEN_MODE* PRL_CVSRC_OPEN_MODE_PTR;
typedef const PRL_CVSRC_OPEN_MODE* PRL_CONST_CVSRC_OPEN_MODE;

typedef struct _PRL_IO_CHANNEL_STAT
{
	// @brief Round trip time in milliseconds
	PRL_UINT32	delay;
	// @brief Approximate upload speed in bytes
	PRL_UINT32	upload;
	// @brief Approximate download speed in bytes
	PRL_UINT32	download;
	// Reserved fields for further purposes
	PRL_UINT32 reserved1;
	PRL_UINT32 reserved2;
	PRL_UINT32 reserved3;
} __attribute__((packed)) PRL_IO_CHANNEL_STAT ;
typedef PRL_IO_CHANNEL_STAT* PRL_IO_CHANNEL_STAT_PTR;

typedef struct _PRL_HOST_OS_INFO
{
	// @brief Host OS type (one of PVS_GUEST_TYPE_...)
	PRL_UINT32 hostOSType;
} __attribute__((packed)) PRL_HOST_OS_INFO ;
typedef PRL_HOST_OS_INFO* PRL_HOST_OS_INFO_PTR;

typedef struct _PRL_VMCTG_TOOL_DATA_RECEIVED
{
	PRL_SIZE uSize;			// size of received data in bytes
	PRL_VOID_PTR pData;		// pointer to the data itself
	PRL_BOOL bKeepBuffer;	// if recipient sets this field to true, the
							// buffer will not be freed after the callback returns.
							// To free the buffer, the recipient must call PrlTool_FreeBuffer()
} __attribute__((packed)) PRL_VMCTG_TOOL_DATA_RECEIVED ;
typedef PRL_VMCTG_TOOL_DATA_RECEIVED* PRL_VMCTG_TOOL_DATA_RECEIVED_PTR;

/**
 * User's callback function should have this prototype
 */
typedef PRL_METHOD_PTR( PRL_VMCTG_TOOL_HANDLER_PTR ) (
		PRL_VOID_PTR pUserData,			// User defined context
		PRL_UINT32 uParam,				// Event id (see prltool_events enum below)
		PRL_VOID_PTR pData				// Meaning of this param depends on value of uParam
		);

/**
 * Describes the tool to be registered
 * @see PrlVm_RegisterTool()
 */
typedef struct _PRL_VMCTG_TOOL_DESC
{
	PRL_SIZE uSize;						// Size of the structure, must be the sizeof(PRL_VMCTG_TOOL_DESC)
	PRL_UINT32 nToolId;					// Unique tool ID, see Tools/VmClientTG/Interfaces/ToolIds.h
	PRL_VMCTG_TOOL_HANDLER_PTR pCallBack;		// Callback function, which will receive all events
	PRL_VOID_PTR pUserData;				// User defined context, it will be passed to the callback unmodified
} __attribute__((packed)) PRL_VMCTG_TOOL_DESC ;
typedef PRL_VMCTG_TOOL_DESC* PRL_VMCTG_TOOL_DESC_PTR;


typedef struct PRL_VIDEO_RECEIVER_FRAME_DESC {
	PRL_UINT64 no;
	PRL_INT64 pts;
} PRL_VIDEO_RECEIVER_FRAME_DESC;
typedef PRL_VIDEO_RECEIVER_FRAME_DESC* PRL_VIDEO_RECEIVER_FRAME_DESC_PTR;

typedef struct PRL_VIDEO_RECEIVER_FRAME {
	PRL_UINT64 no;
	PRL_INT64 pts;
	PRL_DISPLAY_BUFFER_FORMAT format;
	PRL_UINT32 width;
	PRL_UINT32 height;
	PRL_UINT32 scale;
	PRL_UINT32 stride;
	PRL_UINT8_PTR data;
	PRL_VOID_PTR priv;
} PRL_VIDEO_RECEIVER_FRAME;
typedef PRL_VIDEO_RECEIVER_FRAME* PRL_VIDEO_RECEIVER_FRAME_PTR;

#ifdef _WIN_
#pragma pack(pop, save_pack)
#endif

#endif//__PARALLELS_IO_STRUCTS_H__
