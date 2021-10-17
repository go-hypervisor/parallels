///////////////////////////////////////////////////////////////////////////////
///
/// @file PrlEventsValues.h
///
/// DO NOT EDIT THIS FILE !!!
/// it generated automatically from PrlEventsValues.txt
/// Please, do not modify header directly - instead use description text file.
/// call Sources/Gen.py or Sources/SDK/GenSdk.py to generate
///
/// @author maximk
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_API_EVENTS_VALUES_H__
#define __PARALLELS_API_EVENTS_VALUES_H__

/**
 * Different event types are identified by these event codes.
 * Client can query event handle with the PrlEvent_GetType call to get this code.
 * @see PrlEvent_GetType
 */
typedef enum _PRL_EVENT_TYPE
{

/* +++ BASE VALUE SET TO 100000 +++ */

 PET_VM_INF_UNINITIALIZED_EVENT_CODE = 100000,

 PET_DSP_EVT_VM_STATE_CHANGED = 100001,
 PET_DSP_EVT_VM_CONFIG_CHANGED = 100002,
 PET_DSP_EVT_VM_DEV_STATE_CHANGED = 100003,
 PET_DSP_EVT_VM_CREATED = 100004,
 PET_DSP_EVT_VM_ADDED = 100005,
 PET_DSP_EVT_VM_DELETED = 100006,
 PET_DSP_EVT_VM_STARTED = 100007,
 PET_DSP_EVT_VM_STOPPED = 100008,
 PET_DSP_EVT_VM_ABORTED = 100009,
 PET_DSP_EVT_VM_RESETED = 100010,
 PET_DSP_EVT_VM_SUSPENDING = 100011,
 PET_DSP_EVT_VM_SUSPENDED = 100012,
 PET_DSP_EVT_VM_RESUMING = 100013,
 PET_DSP_EVT_VM_RESUMED = 100014,
 PET_DSP_EVT_VM_START_IO_FLOW = 100015,
 PET_DSP_EVT_VM_SNAPSHOTED = 100016,
PET_DSP_EVT_VM_STATESAVED = PET_DSP_EVT_VM_SNAPSHOTED,
 PET_DSP_EVT_VM_RESTORED = 100017,
PET_DSP_EVT_VM_STATERESTORED = PET_DSP_EVT_VM_RESTORED,
 PET_DSP_EVT_VM_NET_RECONNECTED = 100018,
 PET_DSP_EVT_VM_PAUSED = 100019,
 PET_DSP_EVT_VM_CONTINUED = 100020,
 PET_DSP_EVT_VM_CONFIG_APPLIED = 100021,
 PET_DSP_EVT_VM_STATISTICS_UPDATED = 100022,
 PET_DSP_EVT_VM_PROBLEM_REPORT_CREATED = 100023,
 PET_DSP_EVT_VM_ABOUT_TO_RESET = 100024,
 PET_DSP_EVT_VM_SECURITY_CHANGED = 100025,
 PET_DSP_EVT_VM_UNREGISTERED = 100026,
 PET_DSP_EVT_VM_REMOTE_DEV_READY_TO_START = 100027,
 PET_VM_EVT_VM_CONFIG_CHANGED = 100028,
 PET_VM_EVT_REQUEST_FILE_OPEN = 100029,
 PET_DSP_EVT_VM_MIGRATE_STARTED_OBSOLETE = 100030,
 PET_DSP_EVT_VM_MIGRATE_CANCELLED_OBSOLETE = 100031,
 PET_DSP_EVT_VM_MIGRATE_FINISHED_OBSOLETE = 100032,
 PET_DSP_EVT_VM_MIGRATE_PROGRESS_CHANGED_OBSOLETE = 100033,
 PET_DSP_EVT_VM_SNAPSHOTING = 100034,
 PET_DSP_EVT_VM_RESTORING = 100035,
 PET_DSP_EVT_VM_SNAPSHOTS_TREE_CHANGED = 100036,
 PET_DSP_EVT_VM_DELETING_STATE = 100037,
 PET_DSP_EVT_VM_STATE_DELETED = 100038,
 PET_DSP_EVT_VM_ABOUT_TO_START_DEINIT = 100039,
 PET_DSP_EVT_VM_ABOUT_TO_START_INIT = 100040,
 PET_DSP_EVT_VM_MEMORY_SWAPPING_STARTED = 100041,
 PET_DSP_EVT_VM_MEMORY_SWAPPING_FINISHED = 100042,
 PET_VM_EVT_UNMOUNT = 100043,
 PET_VM_EVT_MOUNT = 100044,
 PET_DSP_EVT_REBOOT_HOST = 100045,
 PET_DSP_EVT_REBOOT_HOST_MANUAL_TO_INIT_VTD_DEVICES = 100046,
 PET_DSP_EVT_BACKUP_STARTED_OBSOLETE = 100047,
 PET_DSP_EVT_BACKUP_CANCELLED_OBSOLETE = 100048,
 PET_DSP_EVT_CREATE_BACKUP_FINISHED_OBSOLETE = 100049,
 PET_DSP_EVT_BACKUP_PROGRESS_CHANGED_OBSOLETE = 100050,
 PET_DSP_EVT_JOB_PROGRESS_CHANGED = 100051,
 PET_DSP_EVT_RESTORE_PROGRESS_CHANGED_OBSOLETE = 100052,
 PET_DSP_EVT_DISK_RESIZE_STARTED = 100053,
 PET_DSP_EVT_DISK_RESIZE_FINISHED = 100054,
 PET_DSP_EVT_DISK_RESIZE_PROGRESS_CHANGED = 100055,
 PET_DSP_EVT_VM_ADDITION_STATE_CHANGED = 100056,
 PET_DSP_EVT_RESTORE_BACKUP_FINISHED_OBSOLETE = 100057,
 PET_DSP_EVT_REMOVE_BACKUP_FINISHED_OBSOLETE = 100058,
 PET_DSP_EVT_VM_MIGRATE_CANCELLED_DISP_OBSOLETE = 100059,
 PET_DSP_EVT_VM_MIGRATE_FINISHED_DISP_OBSOLETE = 100060,
 PET_DSP_EVT_TIME_MACHINE_BACKUP_IS_OVER = 100061,
 PET_DSP_EVT_CONVERSION_DISKS_PROGRESS_CHANGED = 100062,
 PET_DSP_EVT_CONVERSION_DISKS_PROGRESS_FINISHED = 100063,
 PET_DSP_EVT_CONVERT_THIRD_PARTY_PROGRESS_CHANGED = 100064,
 PET_DSP_EVT_CONNECTED_TO_PROXY = 100065,
 PET_DSP_EVT_DISCONNECTED_FROM_PROXY = 100066,
 PET_DSP_EVT_CONNECTING_TO_PROXY = 100067,
 PET_DSP_EVT_RECONFIG_VM_PROGRESS_CHANGED = 100068,
 PET_DSP_EVT_VM_MIGRATE_WAIT_REMOUNT_OBSOLETE = 100069,
 PET_DSP_EVT_VM_CONFIG_APPLY_FINISHED = 100070,
 PET_DSP_EVT_VM_IO_CLIENT_STATISTICTS = 100071,
 PET_DSP_EVT_VM_SET_HOST_TIME = 100072,
 PET_DSP_EVT_VM_LOW_HOST_MEMORY = 100073,
 PET_DSP_EVT_VM_MAC_OS_VER = 100074,
 PET_DSP_EVT_VM_PAUSED_BY_HOST_SLEEP = 100075,
 PET_DSP_EVT_VM_CONTINUED_BY_HOST_WAKEUP = 100076,
 PET_DSP_EVT_VM_FROZEN = 100077,
 PET_DSP_EVT_VM_UNFROZEN = 100078,
 PET_DSP_EVT_CONNECTION_CLIENT_INFO_WAS_SET = 100079,
 PET_DSP_EVT_CONNECTION_WAS_CLOSED = 100080,
 PET_DSP_EVT_HOST_CLEANUP = 100081,
 PET_DSP_EVT_HTTP_PROXY_AUTH_REQUIRED = 100082,
 PET_DSP_EVT_VM_DEBUGGER_EVENT = 100083,
 PET_DSP_EVT_VM_OS_CHANGED = 100084,
 PET_VM_EVT_REQUEST_DEVICE_OPEN = 100085,
 PET_VM_EVT_DISK_CHECK_STARTED = 100086,
 PET_VM_EVT_DISK_CHECK_FINISHED = 100087,
 PET_VM_EVT_DISK_CHECK_PROGRESS = 100088,

/* +++ ALIGNED VALUE TO 100100 +++ */
 PET_DSP_EVT_OP_ACCEPTED = 100100,
 PET_DSP_EVT_OP_REJECTED = 100101,
 PET_DSP_EVT_OP_RESULT = 100102,

/* +++ ALIGNED VALUE TO 100200 +++ */
 PET_DSP_EVT_DIR_STATE_CHANGED = 100200,
 PET_DSP_EVT_HOST_STATISTICS_UPDATED = 100201,
 PET_DSP_EVT_HW_CONFIG_CHANGED = 100202,
 PET_VM_EVT_HUGE_PAGES_LIMIT_CHANGED = 100203,

/* +++ ALIGNED VALUE TO 100300 +++ */
 PET_DSP_EVT_CLIENT_CONNECTED = 100300,
 PET_DSP_EVT_CLIENT_DISCONNECTED = 100301,
 PET_DSP_EVT_CLIENT_REJECTED = 100302,

/* +++ ALIGNED VALUE TO 100400 +++ */
 PET_DSP_EVT_FOUND_LOST_VM_CONFIG = 100400,
 PET_DSP_EVT_HAS_EVENT = 100401,
 PET_DSP_EVT_RECONNECT = 100402,
 PET_DSP_EVT_DISP_CONNECTION_CLOSED = 100403,
 PET_DSP_EVT_DISP_SHUTDOWN = 100404,

/* +++ ALIGNED VALUE TO 100500 +++ */
 PET_DSP_EVT_USER_PROFILE_CHANGED = 100500,
 PET_DSP_EVT_COMMON_PREFS_CHANGED = 100501,
 PET_DSP_EVT_VM_MESSAGE = 100502,
 PET_DSP_EVT_VM_QUESTION = 100503,
 PET_JOB_DELETE_VM_PROGRESS_CHANGED = 100504,
 PET_VM_INF_START_FILE_COPYING = 100505,
 PET_VM_INF_END_FILE_COPYING = 100506,
 PET_DSP_EVT_ERROR_MESSAGE = 100507,
 PET_DSP_EVT_WARNING_MESSAGE = 100508,
 PET_JOB_HDD_CREATE_PROGRESS_CHANGED = 100509,
 PET_JOB_FILE_COPY_PROGRESS_CHANGED = 100510,
 PET_JOB_SUSPEND_PROGRESS_CHANGED = 100511,
 PET_JOB_RESUME_PROGRESS_CHANGED = 100512,
 PET_DSP_EVT_ANSWER_TO_VM_WAS_DONE = 100513,
 PET_DSP_EVT_LICENSE_CHANGED = 100514,
 PET_JOB_CREATE_SNAPSHOT_PROGRESS_CHANGED = 100515,
 PET_JOB_SWITCH_TO_SNAPSHOT_PROGRESS_CHANGED = 100516,
 PET_JOB_DELETE_SNAPSHOT_PROGRESS_CHANGED = 100517,
 PET_JOB_COMMIT_UNFINISHED_DISK_OP_PROGRESS_CHANGED = 100518,
 PET_DSP_EVT_COMMIT_UNFINISHED_DISK_OP_STARTED = 100519,
 PET_DSP_EVT_COMMIT_UNFINISHED_DISK_OP_FINISHED = 100520,
 PET_DSP_EVT_VM_ENCRYPT_PROGRESS_CHANGED = 100521,
 PET_DSP_EVT_VM_DECRYPT_PROGRESS_CHANGED = 100522,
 PET_JOB_STAGE_PROGRESS_CHANGED = 100523,
 PET_VM_INF_START_BUNCH_COPYING = 100524,
 PET_VM_INF_END_BUNCH_COPYING = 100525,
 PET_DSP_EVT_LICENSE_WAS_DEACTIVATED = 100526,
 PET_DSP_EVT_VM_REQUEST = 100527,
 PET_DSP_EVT_SERVER_INFO_CHANGED = 100528,
 PET_DSP_EVT_FEATURE_MATRIX_CHANGED = 100529,
 PET_DSP_EVT_PWD_PROTECTION_STATE_CHANGED = 100530,
 PET_DSP_EVT_GET_VM_SNAPSHOTS_SIZE_CHANGED = 100531,
 PET_DSP_EVT_VM_ACQUIRE_STATES_PROGRESS_CHANGED = 100532,
 PET_DSP_EVT_VM_ESTIMATE_STATES_SIZE_PROGRESS_CHANGED = 100533,

/* +++ ALIGNED VALUE TO 100600 +++ */
 PET_DSP_EVT_SMC_USER_FORCE_DISCONNECTED = 100600,
 PET_DSP_EVT_SMC_CANCEL_USER_COMMAND = 100601,
 PET_DSP_EVT_SMC_DISPATCHER_SHUTDOWN = 100602,

/* +++ ALIGNED VALUE TO 100700 +++ */
 PET_IO_SCREEN_SIZE = 100700,
 PET_IO_SLIDING_MOUSE_FLAG = 100702,
 PET_IO_DEVICE_IS_IN_USE = 100703,
 PET_IO_KEYBOARD_LEDS = 100704,
 PET_IO_STATE = 100705,
 PET_IO_SCREEN_CAPTURED = 100706,
 PET_IO_BEFORE_SCREEN_SIZE = 100707,
 PET_IO_REMOTE_COMMAND = 100708,
 PET_IO_MOUSE_CURSOR_CHANGED = 100709,
 PET_IO_MOUSE_CURSOR_HID = 100710,
 PET_IO_MOUSE_CURSOR_SET = 100711,
 PET_IO_DYNRES_TOOL_STATUS = 100712,
 PET_IO_TOOLS_UTILITY_COMMAND = 100713,
 PET_IO_TOOLS_VM_SHUTDOWN = 100714,
 PET_IO_TOOLS_CLIPBOARD_DATA = 100715,
 PET_IO_SCREEN_SURFACE_DETACHED = 100716,
 PET_IO_TOOLS_SIA_DATA = 100717,
 PET_IO_TOOLS_VMCTG_COMMAND = 100718,
 PET_IO_TOOLS_DRAGDROP_DATA = 100719,
 PET_IO_TOOLS_GENERAL_COMMAND = 100720,
 PET_IO_TOOLS_DESKTOP_UTILITY_STATE = 100721,
 PET_IO_DISPLAY_SCREEN_SIZE = 100722,
 PET_IO_DISPLAY_BEFORE_SCREEN_SIZE = 100723,
 PET_IO_DISPLAY_SCREEN_CAPTURED = 100724,
 PET_IO_SWITCH_VESA_MODE = 100725,
 PET_IO_TOOLS_LANGUAGE_HOTKEY_CHANGED = 100726,
 PET_IO_AVAILABLE_DISPLAYS = 100727,
 PET_IO_SCREEN_SURFACE_ATTACHED = 100728,
 PET_IO_UIEMU_ELEMENT_AT_POS = 100729,
 PET_IO_AUDIO_OUTPUT_DATA = 100730,
 PET_IO_AUDIO_OUTPUT_ENCODING_SET = 100731,
 PET_IO_AUDIO_OUTPUT_STREAM_STARTED = 100732,
 PET_IO_AUDIO_OUTPUT_STOP = 100734,
 PET_IO_CVSRC_OPEN = 100735,
 PET_IO_CVSRC_CLOSE = 100736,
 PET_IO_MOUSE_CURSOR_MOVED = 100738,
 PET_IO_UIEMU_CARET_INFO = 100739,
 PET_IO_DISPLAY_GAMMA_CHANGED = 100740,
 PET_IO_DYNRES_OPERATION_STATUS = 100741,
 PET_IO_SCREEN_SURFACE_ATTACHED_EX = 100742,
 PET_IO_SCREEN_SURFACE_CHANGED = 100743,
 PET_IO_NEW_IP_APPEARED = 100744,

/* +++ ALIGNED VALUE TO 100800 +++ */
 PET_DSP_EVT_VM_TOOLS_STATE_CHANGED = 100800,
 PET_DSP_EVT_VM_COMPACT_PROCESSING = 100801,
 PET_DSP_EVT_VM_COMPACT_FINISHED = 100802,
 PET_DSP_EVT_VM_COMPRESSOR_FINISHED = 100803,
 PET_DSP_EVT_VM_COMPRESSOR_CONTINUED = 100804,
 PET_DSP_EVT_VM_SOFTWARE_INSTALLED = 100805,
 PET_DSP_EVT_VM_PIS_NOTIFICATION_ASK_TO_INSTALL = 100806,
 PET_DSP_EVT_VM_VIRTUAL_DEVICES_STATE_CHANGED = 100807,

/* +++ ALIGNED VALUE TO 100900 +++ */
 PET_DSP_EVT_PERFSTATS = 100900,
 PET_DSP_EVT_VM_PERFSTATS = 100901,

/* +++ ALIGNED VALUE TO 101000 +++ */
 PET_DSP_EVT_VM_UPGRADE_INIT = 101000,
 PET_DSP_EVT_VM_UPGRADE_INIT_TIMEOUT = 101001,
 PET_DSP_EVT_VM_UPGRADE_STAGE_1 = 101002,
 PET_DSP_EVT_VM_UPGRADE_STAGE_2 = 101003,
 PET_DSP_EVT_VM_UPGRADE_STAGE_3 = 101004,
 PET_DSP_EVT_VM_UPGRADE_COMPLETED = 101005,
 PET_DSP_EVT_VM_UPGRADE_UNKNOWN_ERROR = 101006,
 PET_DSP_EVT_VM_UPGRADE_INIT_VMW = 101007,
 PET_DSP_EVT_VM_UPGRADE_INIT_PHY = 101008,

/* +++ ALIGNED VALUE TO 101100 +++ */
 PET_IO_READY_TO_ACCEPT_STDIN_PKGS = 101100,

/* +++ ALIGNED VALUE TO 101200 +++ */
 PET_VM_READY_TO_BOOT = 101200,
 PET_VM_READY_TO_PRINT = 101201,
 PET_VM_DEFAULT_SOUND_RECONNECTED = 101202,
 PET_VM_EVT_UNMOUNT_USB_MEDIA = 101203,
 PET_VM_EVT_UNMOUNT_DVD_MEDIA = 101204,
 PET_VM_EVT_GET_PRINT_SETTINGS = 101205,
 PET_VM_EVT_LOAD_USB_DRV = 101206,
 PET_VM_EVT_UPDATE_VMNET_STATE = 101207,
 PET_VM_EVT_PRIVACY_STATE = 101208,

/* +++ ALIGNED VALUE TO 101300 +++ */
 PET_DSP_EVT_APPLIANCE_DOWNLOAD_PROGRESS_CHANGED = 101300,
 PET_DSP_EVT_APPLIANCE_DOWNLOAD_FINISHED = 101301,
 PET_DSP_EVT_APPLIANCE_ARCHIVE_UNPACK_STARTED = 101302,
 PET_DSP_EVT_APPLIANCE_ARCHIVE_UNPACK_FINISHED = 101303,
 PET_DSP_EVT_APPLIANCE_REGISTER_VM_STARTED = 101304,
 PET_DSP_EVT_APPLIANCE_REGISTER_VM_FINISHED = 101305,
 PET_DSP_EVT_APPLIANCE_RECONNECTING = 101306,

/* +++ ALIGNED VALUE TO 101400 +++ */
 PET_DSP_EVT_CEP_WRITE_STRING = 101400,
 PET_DSP_COHERENCE_FAKE_STUB_NOTIFICATION_OBSOLETE = 101401,

/* +++ ALIGNED VALUE TO 101500 +++ */
 PET_DSP_EVT_VM_WAS_ENCRYPTED = 101500,
 PET_DSP_EVT_VM_WAS_DECRYPTED = 101501,
 PET_DSP_EVT_ENCRYPTED_VM_PASSWORD_CHANGED = 101502,
 PET_DSP_EVT_ENCRYPTED_VM_NEED_AUTH_AGAIN = 101503,
 PET_DSP_EVT_VM_WAS_PROTECTED = 101504,
 PET_DSP_EVT_VM_WAS_UNPROTECTED = 101505,

/* +++ ALIGNED VALUE TO 101600 +++ */
 PET_VM_EVT_TIS_BACKUP_WRITE = 101600,
 PET_VM_EVT_CEP_ENGINE_WRITE = 101601,

/* +++ ALIGNED VALUE TO 101700 +++ */
 PET_IO_EVT_DISCONNECT_WITH_REASON = 101700,

/* +++ ALIGNED VALUE TO 101800 +++ */
 PET_VIDEO_RECEIVER_FORMAT = 101800,
 PET_VIDEO_RECEIVER_FRAME = 101801,
 PET_VIDEO_RECEIVER_CLOSED = 101802,
 PET_VIDEO_CAPTURE_GEOMETRY = 101803,
 PET_VIDEO_RECEIVER_CONNECTION_STATE = 101804,

/* +++ ALIGNED VALUE TO 101900 +++ */
 PET_PTM_EVT_PROPERTY_CHANGED = 101900,
 PET_PTM_EVT_OBJECT_DELETED = 101901,
 PET_PTM_EVT_OBJECT_CREATED = 101902,
 PET_PTM_EVT_SUBSCRIBED = 101903,
 PET_PTM_EVT_RPC_COMPLETED = 101904,

/* +++ ALIGNED VALUE TO 102000 +++ */
 PET_DSP_EVT_SHARED_ITEM_CHANGED = 102000,
 PET_DSP_EVT_SHARED_ITEM_REMOVED = 102001,

/* +++ ALIGNED VALUE TO 102100 +++ */
 PET_DSP_EVT_BACKUP_PROGRESS_INFO = 102100,
 PET_DSP_EVT_BACKUP_STARTED = 102101,
 PET_DSP_EVT_BACKUP_FINISHED = 102102,
 PET_DSP_EVT_BACKUP_ABORTED = 102103,

} PRL_EVENT_TYPE;
typedef PRL_EVENT_TYPE* PRL_EVENT_TYPE_PTR;

/**
 * Private event types.
 * Is NOT a part of public API.
 */
typedef enum _PRL_PRIVATE_EVENT_TYPE
{
/* +++ BASE VALUE SET TO 200000 +++ */

 PET_IO_DISPLAY_PALETTE_CHANGED = 200000,
 PET_IO_TOOLS_TIS_QUERY = 200001,
 PET_IO_SCREEN_UPDATED = 200002,
 PET_IO_AUTH_RESPONSE = 200003,
 PET_IO_ATTACH_RESPONSE = 200004,
 PET_IO_ENCODING_RESPONSE = 200005,
 PET_IO_MEMORY_INFO = 200006,
 PET_IO_SCREEN_CAPTURED_BUFFER = 200007,
 PET_IO_TOOLS_TIS_SUBSCRIBE = 200008,
 PET_IO_TOOLS_TIS_UNSUBSCRIBE = 200009,

/* +++ ALIGNED VALUE TO 200100 +++ */
 PET_IO_CLI_AUTHENTICATE_SESSION = 200100,
 PET_IO_CLI_ATTACH_TO_VM = 200101,
 PET_IO_CLI_ENCODING_REQUEST = 200102,
 PET_IO_CLI_SCREEN_WATCH_UPDATES = 200103,
 PET_IO_CLI_SCREEN_CAPTURE_BUFFER = 200104,
 PET_IO_CLI_SCREEN_SIZE = 200105,
 PET_IO_CLI_KEYBOARD_SCANCODE = 200106,
 PET_IO_CLI_MOUSE_SETPOS = 200107,
 PET_IO_CLI_MOUSE_MOVE = 200108,
 PET_IO_CLI_MOUSE_NEED_CURSOR = 200109,
 PET_IO_CLI_GRACEFUL_SHUTDOWN = 200110,
 PET_IO_CLI_SCREEN_SET_SURFACE = 200111,
 PET_IO_CLI_REMOTE_COMMAND = 200112,
 PET_IO_CLI_TOOLS_UTILITY_COMMAND = 200113,
 PET_IO_CLI_TOOLS_TIS_QUERY = 200114,
 PET_IO_CLI_TOOLS_CLIPBOARD_DATA = 200115,
 PET_IO_CLI_TOOLS_SIA_DATA = 200116,
 PET_IO_CLI_TOOLS_VMCTG_COMMAND = 200117,
 PET_IO_CLI_TOOLS_GENERAL_COMMAND = 200118,
 PET_IO_CLI_TOOLS_EMPTY_RECYCLE_BIN = 200119,
 PET_IO_CLI_TOOLS_SET_TASKBAR_VISIBILITY = 200120,
 PET_IO_CLI_TOOLS_TOGGLE_DESKTOP = 200121,
 DEPRECATED_PET_IO_CLI_TOOLS_MOVE_TASKBAR = 200122,
 PET_IO_CLI_TOOLS_SHOW_RECYCLE_BIN = 200123,
 PET_IO_CLI_TOOLS_NOTIFY_COHERENCE_STATE = 200124,
 PET_IO_CLI_TOOLS_ADJUST_WORKING_AREA = 200125,
 PET_IO_CLI_KEYBOARD_KEY = 200126,
 PET_IO_CLI_TOOLS_UIEMU = 200127,
 DEPRECATED_PET_IO_CLI_AUDIO_OUTPUT_STREAM_START = 200128,
 DEPRECATED_PET_IO_CLI_AUDIO_OUTPUT_STREAM_STOP = 200129,
 DEPRECATED_PET_IO_CLI_AUDIO_OUTPUT_SET_ENCODING = 200130,
 PET_IO_CLI_CVSRC_CONNECT = 200131,
 PET_IO_CLI_CVSRC_DISCONNECT = 200132,
 PET_IO_CLI_AUTHENTICATE_EXEC_SESSION = 200133,
 PET_IO_CLI_SWITCH_SLIDING_MOUSE = 200134,
 PET_IO_CLI_DPI_SCREEN_SIZE = 200139,
 PET_IO_CLI_TOOLS_SET_INDENTS = 200140,
 PET_IO_CLI_AUDIO_RECORDING_STREAM_START = 200141,
 PET_IO_CLI_AUDIO_RECORDING_STREAM_STOP = 200142,
 PET_IO_CLI_AUDIO_PLAYOUT_STREAM_START = 200143,
 PET_IO_CLI_AUDIO_PLAYOUT_STREAM_STOP = 200144,
 PET_IO_CLI_TOOLS_OPEN_FILE_BROWSER = 200145,
 PET_IO_CLI_GET_AUDIO_SWITCH_SETTINGS = 200146,
 PET_IO_CLI_GET_AUDIO_SWITCH_SETTINGS_RESPONSE = 200147,
 PET_IO_CLI_SET_AUDIO_SWITCH_SETTINGS = 200148,
 PET_IO_CLI_TOOLS_SET_POWER_SCHEME_SLEEP_ABILITY = 200149,
 PET_IO_CLI_SCREEN_ENABLE_UPDATES = 200150,
 PET_IO_CLI_SCREEN_CONTEXT_REQUEST = 200151,
 PET_IO_CLI_KEYBOARD_OPTIMIZATION_MODE = 200152,

/* +++ ALIGNED VALUE TO 200200 +++ */
 PET_IO_STDIN_PORTION = 200200,
 PET_IO_STDOUT_PORTION = 200201,
 PET_IO_STDERR_PORTION = 200202,
 PET_IO_READY_TO_ACCEPT_STDOUT_STDERR_PKGS = 200203,
 PET_IO_FIN_TO_TRANSMIT_STDOUT_STDERR = 200204,
 PET_IO_CLIENT_PROCESSED_ALL_DESCS_DATA = 200205,
 PET_IO_TTY_SETTINGS_REQUIRED = 200206,
 PET_IO_TTY_SETTINGS_PROVIDED = 200207,
 PET_IO_STDIN_WAS_CLOSED = 200208,

/* +++ ALIGNED VALUE TO 200300 +++ */
 PET_IT_RECONFIG_BOOTCAMP_START = 200300,
 PET_IT_VALIDATE_BOOTCAMP_START = 200301,
 PET_IT_CONVERT_TO_OLD_START = 200302,
 PET_IT_CONVERT_TO_CURRENT_START = 200303,
 PET_IT_RECONFIG_START = 200304,
 PET_IT_MERGE_SNAPSHOTS_START = 200305,
 PET_IT_MAKE_PLAIN_START = 200306,
 PET_IT_MAKE_EXPANDING_START = 200307,
 PET_IT_MAKE_SPLIT_START = 200308,
 PET_IT_MAKE_NON_SPLIT_START = 200309,
 PET_IT_GET_RESIZE_INFORMATION_START = 200310,
 PET_IT_INCREASE_LAST_VOLUME_START = 200311,
 PET_IT_RESIZING_START = 200312,
 PET_IT_DECREASING_START = 200313,
 PET_IT_COMPACTING_START = 200314,
 PET_IT_FIX_CONSISTENCY_START = 200315,
 PET_IT_CONVERT_TO_EXTEND_START = 200316,

/* +++ ALIGNED VALUE TO 200400 +++ */
 PET_DESKCTL_SESSION_AUTH = 200400,
 PET_DESKCTL_SESSION_AUTH_FIN = 200401,
 PET_DESKCTL_ATTACH = 200402,
 PET_DESKCTL_ATTACH_FIN = 200403,
 PET_DESKCTL_LOCAL_AUTH = 200404,
 PET_DESKCTL_LOCAL_AUTH_QUEST = 200405,
 PET_DESKCTL_LOCAL_AUTH_ANSWER = 200406,
 PET_DESKCTL_LOCAL_AUTH_FIN = 200407,
 PET_DESKCTL_ACCEPT_CLIENTS = 200408,
 PET_DESKCTL_REJECT_CLIENTS = 200409,
 PET_DESKCTL_CONFIG = 200410,
 PET_DESKCTL_CONFIG_QUERY = 200411,
 PET_DESKCTL_SEND_SAS = 200412,
 PET_DESKCTL_STATUS_CHANGE = 200413,
 PET_DESKCTL_ATTACH_WEB_CLIENT = 200414,
 PET_DESKCTL_SHARES_SHARE = 200415,
 PET_DESKCTL_SHARES_UNSHARE = 200416,
 PET_DESKCTL_SHARES_ENUMERATE = 200417,
 PET_DESKCTL_GET_CEP_REPORT = 200418,
 PET_DESKCTL_GET_CEP_REPORT_RESPONSE = 200419,
 PET_DESKCTL_DISCONNECT_CLIENTS = 200420,

/* +++ ALIGNED VALUE TO 200500 +++ */
 PET_IO_DISCONNECT_WITH_REASON = 200500,

/* +++ ALIGNED VALUE TO 200510 +++ */
 PET_IO_DISPLAY_RESOLUTION_SET = 200510,

/* +++ ALIGNED VALUE TO 200600 +++ */
 PET_VIDEO_STREAM_START = 200600,
 PET_VIDEO_STREAM_CLOSE = 200601,
 PET_VIDEO_STREAM_FORMAT = 200602,
 PET_VIDEO_STREAM_DATA = 200603,
 PET_VIDEO_STREAM_CLOSED = 200604,
 PET_VIDEO_STREAM_ACK_FRAME = 200605,
 PET_VIDEO_STREAM_OPEN = 200606,
 PET_VIDEO_DATA_CHANNEL_CTL = 200607,
 PET_VIDEO_STREAM_STOP = 200608,

/* +++ ALIGNED VALUE TO 200700 +++ */
 PET_IO_PTM_PROTOCOL = 200700,

/* +++ ALIGNED VALUE TO 200800 +++ */
 PET_IO_IOSERVICE_CHANNELS_PROTOCOL = 200800,

} PRL_PRIVATE_EVENT_TYPE;
typedef PRL_PRIVATE_EVENT_TYPE* PRL_PRIVATE_EVENT_TYPE_PTR;


#endif // __PARALLELS_API_EVENTS_VALUES_H__
