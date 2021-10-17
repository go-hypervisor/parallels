///////////////////////////////////////////////////////////////////////////////
///
/// @file PrlDisk.h
///
/// Parallels Virtual Disk
///
/// Copyright (c) 2008-2017 Parallels International GmbH. All rights reserved.
/// Copyright (c) 2021 Parallels International GmbH. All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ___PARALLELS_DISK_SDK_DEFINITIONS___
#define ___PARALLELS_DISK_SDK_DEFINITIONS___

#ifdef __cplusplus
extern "C" {
#endif

// Include main header file
#include "PrlTypes.h"
#include "PrlErrors.h"

/*
 * On windows platform we're taking advantage of the #pack directive
 * to ensure internal structures alignment by 1 - on unixes we achive
 * the same results by using the __attribute__((packed)) directive
 * -> restoring alignment
 */
#ifdef _WIN_
    #pragma pack(push, save_api_pack, 1)
#endif

/* States progress definition. */
#define PRL_DISK_PROGRESS_MIN			0
#define PRL_DISK_PROGRESS_MAX			1000
#define PRL_DISK_PROGRESS_COMPLETED		1005

// States progress definition
#define PRL_STATE_PROGRESS_MIN			0
#define PRL_STATE_PROGRESS_MAX			PRL_DISK_PROGRESS_MAX
#define PRL_STATE_PROGRESS_COMPLETED	PRL_DISK_PROGRESS_COMPLETED

/* Parallels images types */

typedef PRL_UINT32 PRL_IMAGE_TYPE;
typedef PRL_IMAGE_TYPE* PRL_IMAGE_TYPE_PTR;

// Invalid type
#define PRL_IMAGE_INVALID			0
// Plain disk
#define PRL_IMAGE_PLAIN				1
// Compressed disk (version 1)
#define PRL_IMAGE_COMPRESSED		2
// Real disk (full)
#define PRL_IMAGE_PHYSICAL			4
// Partition from disk
#define PRL_IMAGE_PARTITION			5
// Bootcamp
#define PRL_IMAGE_BOOTCAMP			6
// Bootcamp set by UID
#define PRL_IMAGE_BOOTCAMP_UID			7
// FAKE Bootcamp, for test purposes
#define PRL_IMAGE_BOOTCAMP_FAKE			8
// Bootcamp partition identified by disk id etc.
#define PRL_IMAGE_BOOTCAMP_ID_STRING	9
// DMG file
#define PRL_IMAGE_DMG					10
// Limited Microsoft VHD support
#define PRL_IMAGE_VHD_PLAIN			80
#define PRL_IMAGE_VHD_DYNAMIC		81
#define PRL_IMAGE_VHD_PLAIN_PART	82
#define PRL_IMAGE_VHD_DYNAMIC_PART	83
#define PRL_IMAGE_VHD_DIFF			84
// VMware VMDK support
#define PRL_IMAGE_VMDK_MONOLITHIC_FLAT       90
#define PRL_IMAGE_VMDK_MONOLITHIC_SPARSE     91
#define PRL_IMAGE_VMDK_EXTENT_2GB_FLAT       92
#define PRL_IMAGE_VMDK_EXTENT_2GB_SPARSE     93
// Software should guess what kind of disk it is
#define PRL_IMAGE_TRY_GUESS			100
// Last (invalid)
#define PRL_IMAGE_LAST_INVALID		0x80000000

/* Storage/image/disk open parameters */

typedef PRL_UINT32					PRL_DISK_OPEN_FLAGS;
typedef PRL_DISK_OPEN_FLAGS*		PRL_DISK_OPEN_FLAGS_PTR;
typedef const PRL_DISK_OPEN_FLAGS*	PRL_CONST_DISK_OPEN_FLAGS_PTR;

/* Nothing. */
#define PRL_DISK_NOTHING			0x00000000
// Read
#define PRL_DISK_READ				0x00000001
// Write
#define PRL_DISK_WRITE				0x00000002
// ReadLock
#define PRL_DISK_READ_LOCK			0x00000004
/* Fake open, just for parameters get (processed by real disks
   that need administrative privileges to work with).          */
#define PRL_DISK_FAKE_OPEN			0x00000008
// Should be used in conjunction with PRL_DISK_FAKE_OPEN for perform internal
// validation procedure.
#define PRL_DISK_VALIDATE			0x00000010

/*
 * This parameter is used when user need to change XML data but not
 * access to the drive itself. It can prevent situations when VirtualDisk
 * library should unmount drive from host system to store small amount
 * of data to the XML descriptor.
 */
#define PRL_DISK_XML_CHANGE			0x00000020
/* Type of the file access to use (15 file accessors is enough). */
#define PRL_DISK_FOPS_MASK			0x000003C0
/* Default access mode that compiled in Parallels itself. */
#define PRL_DISK_FOPS_DEFAULT		0x00000000
// DEPRECATED! Normal access mode (default os)
#define PRL_DISK_FOPS_NORMAL		0x00000040
/* DEPRECATED! Access mode with file caching turned off. */
#define PRL_DISK_FOPS_NONCACHED		0x00000080
/* DEPRECATED! Access mode with requests merging. */
#define PRL_DISK_FOPS_MERGING		0x000000C0
/* DEPRECATED! Access mode to files on PCS storage */
#define PRL_DISK_FOPS_PCS			0x000001C0
// Force open of disk for reading without error checking
#define PRL_DISK_NO_ERROR_CHECKING	0x00000400
// So not create image when creating disk, just put reference to file in XML
#define PRL_DISK_NO_IMAGE_CREATION	0x00001000
// Use raw disk for BootCamp partition (/dev/rdisk instead of /dev/disk)
#define PRL_DISK_USE_RAW_DISK		0x00002000
// Do not use handle pool for disk image handles
#define PRL_DISK_NOT_LIMIT_HANDLES	0x00004000
// Do not check host free space
#define PRL_DISK_NO_SPACE_CHECKS	0x00008000
// Allow inplace data modification to reduce memory copying and allocation
#define PRL_DISK_ALLOW_DATA_MODIFY	0x00010000
// Incoming requests to read/write async must be gathered and aligned
#define PRL_DISK_ALIGN_REQUESTS		0x00020000
// Ignore storages read only flag (useful at disk creation)
#define PRL_DISK_IGNORE_PROTECTION	0x00040000
// Explicitly enable re-open disk with non-current snapshot (useful for backup,
// reclame all snapshots etc.)
#define PRL_DISK_ENABLE_SNAPSHOT_REOPEN	0x00080000

/* Default (writelock always on at write on). */
#define PRL_DISK_DEFAULT_FLAG		(PRL_DISK_READ | PRL_DISK_WRITE | PRL_DISK_FOPS_DEFAULT)
/* Special for backup operation */
#define PRL_DISK_BACKUP_FLAG		(PRL_DISK_ENABLE_SNAPSHOT_REOPEN \
									| PRL_DISK_READ \
									| PRL_DISK_NO_ERROR_CHECKING)

#define PRL_DISK_VALIDATION_FLAG	(PRL_DISK_FAKE_OPEN | PRL_DISK_VALIDATE)

/* Last (invalid). */
#define PRL_DISK_INVALID


////////////////////////////////////////////////////////////////////////
/**
 * Saved states callback types
 *
 * @author antonz@
 */
////////////////////////////////////////////////////////////////////////
typedef PRL_INT32 PRL_STATES_CALLBACK_TYPE;
typedef PRL_STATES_CALLBACK_TYPE* PRL_STATES_CALLBACK_TYPE_PTR;

// Ordinary callback that disk process going.
#define PRL_STATE_DISK_CALLBACK						0x1000
// Core callback completed
#define PRL_STATE_CORE_FIRST_COMPLETE_CALLBACK		0x1001
// Operation fully completed
#define PRL_STATE_CORE_FULL_COMPLETE_CALLBACK		0x1002
// Disk operation started
#define PRL_STATE_CORE_START_DISK_PROCESS_CALLBACK	0x1003
/*
 * At remove all states this callback indicates that one more stage complete
 * in states removal
 **/
#define PRL_STATE_DISK_CALLBACK_STAGE_CPL			0x1004
// Invalid callback
#define PRL_STATE_CALLBACK_INVALID					0x1005

/*
 * Disk partition types
 */
// Extended partitions
#define PRL_MSDOS_EXTENDED_PARTITION				0x05
#define PRL_WIN_EXTENDED_PARTITION					0x0F
#define PRL_LINUX_EXTENDED_PARTITION				0x85
// EFI system partition
#define PRL_EFI_PARTITION_GPT						0xEE
#define PRL_EFI_PARTITION							0xEF
// Mac OS
#define PRL_MACOS_PARTITION							0xAF
#define PRL_MACOS_BOOT_PARTITION					0xAB
/* Free BSD partition. */
#define PRL_BSD_PARTITION							0xA5
// Linux partitions
#define PRL_LINUX_PARTITION_SWAP					0x82
#define PRL_LINUX_PARTITION_DATA					0x83
// Windows partitions
#define PRL_WINDOWS_PARTITION_NTFS					0x07
#define PRL_WINDOWS_PARTITION_FAT					0x06
#define PRL_WINDOWS_PARTITION_FAT32					0x0B
#define PRL_WINDOWS_PARTITION_FAT32_LBA				0x0C
// Invalid partition
#define PRL_INVALID_PARTITION						0xFF
#define PRL_EMPTY_PARTITION							0x00
/* Special handle for data partition from GPT (can be linux,
   windows, any type).                                       */
#define PRL_DATA_PARTITION							0xd8

/*
 * Disk image cache modes (from host OS point of view)
 */

/* Disk cache default. */
#define PRL_DISK_CACHE_DEFAULT						0

/* Cached access to disk image. Fast write() and read() in case
   of all data can be fit in OS cache. But in the other hand
   host cache will be partially duplicated in guest OS cache, so
   in this mode memory usage may be ineffective.                 */
#define PRL_DISK_CACHE_ENABLED						1

/* Uncached access to disk image. Slow read/write always, but
   host OS cache is not used, so it's good for host
   applications.                                              */
#define PRL_DISK_CACHE_DISABLED						2

/* Cached write/uncached read. Like DISK_CACHE_ENABLED, but read
   data does not duplicated in host OS RAM, so you have more RAM
   for host applications. On Mac you may also see performance
   gain when you read data that were just written before and
   held in OS cache - data will be read from cache even with
   F_NOCACHE read(). This may help guest OS with stuff like
   pagefile.sys for example.                                     */
#define PRL_DISK_CACHE_UNCACHED_READ				3

/* Cached write and uncached read is used, while filesystem
   cache does not grow large enough. The writes transparently
   switch to the uncached mode. This mode requires a hypervisor
   driver connection in order to access the filesystem cache
   configuration.
 */
#define PRL_DISK_CACHE_LIMITED_CACHED_WRITE			5

////////////////////////////////////////////////////////////////////////
/* Parallels storage parameters */
////////////////////////////////////////////////////////////////////////

typedef struct __PRL_IMAGE_PARAMETERS
{
	// Type of storage (base)
	PRL_IMAGE_TYPE Type;
	// Start of storage
	PRL_UINT64 uStart;
	// End of storage
	PRL_UINT64 uSize;
	// Disk name
	PRL_CHAR_PTR pFileName;
} __attribute__((packed)) PRL_IMAGE_PARAMETERS ;
typedef PRL_IMAGE_PARAMETERS* PRL_IMAGE_PARAMETERS_PTR;

////////////////////////////////////////////////////////////////////////
/* Parallels disk parameters. Differs from internal due to lists
   classes                                                       */
////////////////////////////////////////////////////////////////////////

typedef struct __PRL_DISK_PARAMETERS
{
	// Number of heads of HDD
	PRL_UINT32 m_Heads;
	// Number of cylinders of HDD
	PRL_UINT32 m_Cylinders;
	// Number of sectors per track
	PRL_UINT32 m_Sectors;
	// Size of HDD in sectors (A size of the sector is 512 byte)
	PRL_UINT64 m_SizeInSectors;
	// Size of block for some kind of disks (in sectors, aligned to track,
	// track = sectors * sector_size)
	PRL_UINT32 m_BlockSize;
	// Count of the storages
	PRL_UINT32 m_Parts;
	// Pointer to array of file parts parameters
	PRL_IMAGE_PARAMETERS_PTR m_Storages;
	/*
	 * Following parameters are available only at SDK v3.
	 */
	// Disk UID
	PRL_GUID Uid;
	// Disk name pointer
	PRL_CHAR_PTR Name;
	/*
	 * Following parameters are available only at SDK v6.
	 */
	// Logical sector size reported to guest
	PRL_UINT32 m_LogicSectorSize;

	// Physical sector size reported to guest (this parameter is ignored in disk creation procedure)
	PRL_UINT32 m_PhysSectorSize;
} __attribute__((packed)) PRL_DISK_PARAMETERS ;
typedef PRL_DISK_PARAMETERS*		PRL_DISK_PARAMETERS_PTR;
typedef const PRL_DISK_PARAMETERS*	PRL_CONST_DISK_PARAMETERS_PTR;

////////////////////////////////////////////////////////////////////////
/**
 * Parallels snapshot tree element
 *
 */
////////////////////////////////////////////////////////////////////////
typedef struct __PRL_SNAPSHOT_ELEMENT
{
	// Snapshot UID
	PRL_GUID m_GUID;
	// Link to the next snapshot element on this level
	struct __PRL_SNAPSHOT_ELEMENT* m_pNext;
	// Link to the next snapshot level
	struct __PRL_SNAPSHOT_ELEMENT* m_pChild;
} __attribute__((packed)) PRL_SNAPSHOT_ELEMENT ;
typedef PRL_SNAPSHOT_ELEMENT*		PRL_SNAPSHOT_ELEMENT_PTR;
typedef const PRL_SNAPSHOT_ELEMENT* PRL_CONST_SNAPSHOT_ELEMENT_PTR;

// Define type of user's callback function
typedef PRL_BOOL (PRL_CALL *PRL_DISK_CALLBACK)(PRL_INT32 iComplete, PRL_INT32 iTotal, PRL_VOID_PTR pParam);
typedef PRL_DISK_CALLBACK* PRL_DISK_CALLBACK_PTR;
// Later put it somwhere else
typedef PRL_BOOL (PRL_CALL *PRL_STATES_CALLBACK)(PRL_STATES_CALLBACK_TYPE iCallbackType, PRL_INT32 iProgress, PRL_VOID_PTR pParameter);

////////////////////////////////////////////////////////////////////////
/**
 * CHS format of disk
 *
 */
////////////////////////////////////////////////////////////////////////
typedef struct _PRL_CHS
{
	PRL_UINT32 Sectors;
	PRL_UINT32 Heads;
	PRL_UINT32 Cylinders;
} PRL_CHS;
typedef PRL_CHS* PRL_CHS_PTR;
typedef const PRL_CHS* PRL_CONST_CHS_PTR;

/*
 * On windows platform we're taking advantage of the #pack directive
 * to ensure internal structures alignment by 1 - on unixes we achive
 * the same results by using the __attribute__((packed)) directive
 * -> restoring alignment
 */
#ifdef _WIN_
    #pragma pack(pop, save_api_pack)
#endif

/*
	This function can be used to create a new virtual disk locally without being connected to the Parallels Service.
	The function creates a new virtual disk and obtains a handle of type PHT_VIRTUAL_DISK identifying the new disk.
	The handle can then be used to perform other operations on the disk if necessary
	(see other functions from this group).

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the create parameters object.
					To create a new disk the parameters should be set (see PrlDiskOpParams_SetDiskParams)
					(see PrlDiskParams_SetName, PrlDiskOpParams_SetDiskOpenFlags)
	phDisk :		[out] A handle of type PHT_VIRTUAL_DISK identifying the new virtual disk. You must
					always free the handle using the PrlDisk_Free function when the handle is no longer needed.
					Failure to do so will result in memory leak.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDisk_ConfigurePhysical
	PrlDiskOpParams_SetDiskParams
	PrlDisk_OpenDiskEx
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDisk_CreateDiskEx, (
		PRL_HANDLE hParams,
		PRL_HANDLE_PTR phDisk
		) );

/*
	This function can be used to configure a new virtual disk, which is based on an external physical device,
	locally without being connected to the Parallels Service.

	Parameters
	pDiskName :		[in] Virtual disk name in UTF\-8 format, which will be created.
	pDevPath :		[in] Path to the physical device in UTF\-8 format '/dev/diskX'.
	nReserved :		[in] This is a reserved parameter.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_CANT_CONFIGURE_PHYSICAL_HDD - Unable to configure the hard disk settings.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDisk_CreateDiskEx
	PrlDiskOpParams_SetDiskParams
	PrlDisk_OpenDiskEx
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
	PrlDisk_ConfigurePhysical, (
		PRL_CONST_STR pDiskName,
		PRL_CONST_STR pDevPath,
		PRL_UINT32 nReserved
		) );

/*
	This function can be used to configure a new virtual disk, which is based on an external dmg image,

	Parameters
	pDiskName :		[in] Virtual disk name in UTF\-8 format, which will be created.
	pDmgPath :		[in] Path to the dmg image in UTF\-8 format.
	nReserved :		[in] This is a reserved parameter.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDisk_CreateDiskEx
	PrlDiskOpParams_SetDiskParams
	PrlDisk_OpenDiskEx
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
	PrlDisk_ConfigureDmg, (
		PRL_CONST_STR pDiskName,
		PRL_CONST_STR pDmgPath,
		PRL_UINT32 nReserved
		) );

/*
	This function can be used to open an existing virtual disk locally without being connected to the Parallels Service.
	The function opens a virtual disk and obtains a handle of type PHT_VIRTUAL_DISK identifying the disk.
	The handle can then be used to perform other operations on the disk if necessary
	(see other functions from this group).

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the open parameters object.
					To open a disk following parameters should be set : Name and OpenFlags
					(see PrlDiskParams_SetName, PrlDiskOpParams_SetDiskOpenFlags)
	phDisk :		[out] A handle of type PHT_VIRTUAL_DISK identifying the new virtual disk. You must
					always free the handle using the PrlDisk_Free function when the handle is no longer needed.
					Failure to do so will result in memory leak.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDiskParams_SetName
	PrlDiskOpParams_SetDiskOpenFlags
	PrlDisk_CreateDiskEx
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDisk_OpenDiskEx, (
		PRL_HANDLE hParams,
		PRL_HANDLE_PTR phDisk
		) );


/* This function can be used to create a new virtual disk
   locally without being connected to the Parallels Service. The
   function creates a new virtual disk and obtains a handle of
   type PHT_VIRTUAL_DISK identifying the new disk. The handle
   can then be used to perform other operations on the disk if
   necessary (see other functions from this group). If you would
   like to create a new virtual disk on a remote host, use the
   PrlDisk_CreateDisk function.
   Parameters
   pHandle :      [out] A handle of type PHT_VIRTUAL_DISK
                  identifying the new virtual disk. You must
                  always free the handle using the PrlDisk_Free
                  function when the handle is no longer needed.
                  Failure to do so will result in memory leak.
   pDiskName :    Disk name in UTF\-8 format.
   pParams :      Disk configuration parameters.
   pCallback :    A pointer to a callback function or NULL
                  pointer. This parameter allows to call the
                  function asynchronously. If this parameter
                  contains a pointer to a user\-implemented
                  callback function, the PrlDisk_CreateDisk
                  function will return immediately and the
                  operation will continue in the background
                  thread. The background thread will be calling
                  the callback function passing the operation
                  progress information to it. See
                  PRL_DISK_CALLBACK for more information. Using a
                  callback might be helpful when the disk
                  creation is expected to take a long time. For
                  \example, you may want to use a callback when
                  you are creating a large disk and allocating
                  all space for it right away.<p />If this
                  parameter contains a NULL pointer, the function
                  will be called synchronously.
   pAdditional :  A pointer to a buffer containing user\-defined
                  data to pass to the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_CreateDisk

   PrlDisk_Free                                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_CreateDisk_Local, (
	// Handle to receive data
	PRL_HANDLE_PTR pHandle,
	// File name
	PRL_CONST_STR pDiskName,
	// Parameters for image
	PRL_CONST_DISK_PARAMETERS_PTR pParams,
	// Callback for long procedures of image creation
	const PRL_DISK_CALLBACK pCallback,
	// Additional parameter (any type) for image class
	PRL_CONST_VOID_PTR pAdditional) );

/* Obtains a handle of type PHT_VIRTUAL_DISK identifying an
   existing virtual disk on a local machine. Use this function
   when you want to view or modify the configuration of an
   existing virtual disk. Once you obtain the disk handle, use
   its functions to perform the desired disk manipulations. This
   function can be used locally without a Parallels Service
   connection.
   Parameters
   pHandle :           [out] A handle of type PHT_VIRTUAL_DISK
                       identifying the virtual disk. You must
                       always free the handle using the
                       PrlDisk_Free function when the handle is
                       no longer needed. Failure to do so will
                       \result in memory leak.
   pDiskName :         The disk name for which to obtain the
                       handle, in UTF\-8 format. Disk name is the
                       same as the bundle name (Mac) or the
                       directory name (Windows, Linux) containing
                       the virtual disk files.
   OpenFlags :         Disk open parameters. See <link PRL_DISK Macros>
                       for available options.
   pAdditionalFlags :  Additional flags (not currently used).
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_OpenDisk

   PrlDisk_Free                                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_OpenDisk_Local, (
	// Handle to receive data
	PRL_HANDLE_PTR pHandle,
	// File name
	PRL_CONST_STR pDiskName,
	// Open flags
	const PRL_DISK_OPEN_FLAGS OpenFlags,
	// Additional flags to image
	PRL_CONST_VOID_PTR pAdditionalFlags) );

/* Converts virtual disks that were created with an older
   \version of Parallels Service to the current version. This
   function can only be used to convert virtual disks residing
   on the same machine where the client application is running.
   You do not have to establish a connection with the Parallels
   Service prior to calling this function. To convert disks on
   remote machines, use the PrlDisk_ConvertToCurrent function.
   Parameters
   pDiskName :  \File name in UTF\-8 format.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_ConvertToCurrent                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_ConvertToCurrent_Local, (
		// File name
		PRL_CONST_STR pDiskName) );

/* Sets necessary access permissions on a directory containing a
   virtual disk to make the disk accessible to other users. The
   function sets the read-write-execute (or 666) permission on
   all files contained in the directory. This makes the virtual
   disk files contained in the directory (and consequently the
   virtual disk itself) accessible to other users. This function
   can be used locally, without establishing a Parallels Service
   connection.
   Parameters
   pDirectoryName :  Directory name in UTF\-8 format.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_SetSharedDirectory                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_SetSharedDirectory_Local, (
		// Directory
		PRL_CONST_STR pDirectoryName) );


/* Creates a new virtual disk. The function creates a new
   virtual disk and obtains a handle of type PHT_VIRTUAL_DISK
   identifying the new disk. The handle can then be used to
   perform other operations on the disk if necessary (see the
   complete list of PHT_VIRTUAL_DISK functions). To use this
   function, you must be connected to the Parallels Service. If
   you are creating a new virtual disk locally, you can use the
   PrlDisk_CreateDisk_Local function which doesn't require the
   Parallels Service connection.
   Parameters
   pHandle :      [out] A handle of type PHT_VIRTUAL_DISK
                  identifying the new virtual disk. You must
                  always free the handle using the PrlDisk_Free
                  function when the handle is no longer needed.
                  Failure to do so will result in memory leak.
   pDiskName :    Virtual disk name in UTF\-8 format.
   pParams :      Virtual disk configuration parameters.
   pCallback :    A pointer to a callback function or NULL
                  pointer. This parameter allows to call the
                  function asynchronously. If this parameter
                  contains a pointer to a user\-implemented
                  callback function, the PrlDisk_CreateDisk
                  function will return immediately and the
                  operation will continue in the background
                  thread. The background thread will be calling
                  the callback function passing the operation
                  progress information to it. See
                  PRL_DISK_CALLBACK for more information. Using a
                  callback might be helpful when the disk
                  creation is expected to take a long time. For
                  \example, you may want to use a callback when
                  you are creating a large disk and allocating
                  all space for it right away.<p />If this
                  parameter contains a NULL pointer, the function
                  will be called synchronously.
   pAdditional :  A pointer to a buffer containing user\-defined
                  data to pass to the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_CreateDisk_Local

   PrlDisk_Free                                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_CreateDisk, (
	// Handle to receive data
	PRL_HANDLE_PTR pHandle,
	// File name
	PRL_CONST_STR pDiskName,
	// Parameters for image
	PRL_CONST_DISK_PARAMETERS_PTR pParams,
	// Callback for long procedures of image creation
	const PRL_DISK_CALLBACK pCallback,
	// Additional parameter (any type) for image class
	PRL_CONST_VOID_PTR pAdditional) );

/* Obtains a handle of type PHT_VIRTUAL_DISK identifying an
   existing virtual disk. Use this function when you want to
   view or modify the configuration of an existing virtual disk.
   Once you obtain the disk handle, use its functions to perform
   the desired disk manipulations.
   Parameters
   pHandle :           [out] A handle of type PHT_VIRTUAL_DISK
                       identifying the virtual disk. You must
                       always free the handle using the
                       PrlDisk_Free function when the handle is
                       no longer needed. Failure to do so will
                       \result in memory leak.
   pDiskName :         The disk name for which to obtain the
                       handle, in UTF\-8 format. Disk name is the
                       same as the bundle name (Mac) or the
                       directory name (Windows, Linux) containing
                       the virtual disk files.
   OpenFlags :         Disk open parameters. See <link PRL_DISK Macros>
                       for available options.
   pAdditionalFlags :  Additional flags (not currently used).
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_OpenDisk_Local

   PrlDisk_Free                                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_OpenDisk, (
	// Handle to receive data
	PRL_HANDLE_PTR pHandle,
	// File name
	PRL_CONST_STR pDiskName,
	// Open flags
	const PRL_DISK_OPEN_FLAGS OpenFlags,
	// Additional flags to image
	PRL_CONST_VOID_PTR pAdditionalFlags) );

/* Converts virtual disks that were created with an older
   \version of Parallels Service to the current version. This
   function can be used to convert disks residing on local and
   remote machines. A connection to the Parallels Service is
   required to do both. As a convenience, the PrlDisk_ConvertToCurrent_Local
   function is provided to convert virtual disks on local
   machines.
   Parameters
   pDiskName :  Virtual disk file name in UTF\-8 format.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_ConvertToCurrent_Local                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_ConvertToCurrent, (
		// File name
		PRL_CONST_STR pDiskName) );

/* Sets necessary access permissions on a directory containing a
   virtual disk to make the disk accessible to other users. The
   function sets the read-write-execute (or 666) permission on
   all files contained in the directory. This makes the virtual
   disk files contained in the directory (and consequently the
   virtual disk itself) accessible to other users.
   Parameters
   pDirectoryName :  Directory name in UTF\-8 format.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_SetSharedDirectory_Local                              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_SetSharedDirectory, (
		// Directory
		PRL_CONST_STR pDirectoryName) );

/* Waits for the background thread to finish executing before
   returning control to the client. Use this function with any
   of the PHT_VIRTUAL_DISK disk functions that can be executed
   asynchronously. When a function is called asynchronously, it
   \returns immediately. The actual task that was initiated by
   the call is performed in the background thread. By calling
   the PrlDisk_WaitForCompletion function, you will suspend the
   main thread execution until the background thread is finished
   processing the task.
   Parameters
   Handle :  A handle of type PHT_VIRTUAL_DISK identifying the
             virtual disk.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_WaitForCompletion, (
		// Disk handle
		const PRL_HANDLE Handle) );

/* Stores user-defined parameter values on a virtual disk. A
   user can store arbitrary data on the disk in the
   parameter/value form. Both the parameter name and the value
   are user-defined and don't have any specific requirements.
   The parameters and their values can be retrieved by the user
   using the PrlDisk_GetUserParameter function. Other users
   cannot access this data.
   Parameters
   Handle :           A handle of type PHT_VIRTUAL_DISK
                      identifying the virtual disk.
   pParameterName :   Parameter name in UTF\-8 format.
   pParameterValue :  Parameter value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_GetUserParameter                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_SetUserParameter, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to parameter name in UTF8
		PRL_CONST_STR pParameterName,
		// Parameter value
		PRL_CONST_STR pParameterValue) );

/* Retrieves user-defined parameter values stored on a virtual
   disk. A user can store arbitrary data on the disk in the
   parameter/value form. Both the parameter name and the value
   are user-defined and don't have any specific requirements.
   The parameters and values are stored using the PrlDisk_SetUserParameter
   function. Other users cannot access this data.
   Parameters
   Handle :           A handle of type PHT_VIRTUAL_DISK
                      identifying the virtual disk.
   pParameterName :   Parameter name in UTF\-8 format.
   pParameterValue :  [out] A pointer to a buffer that receives
                      the specified parameter value.
   BufferSize :       [in] The size of the output buffer (in
                      bytes). Set the buffer pointer to null and
                      this parameter's value to zero to receive
                      the required size. [out] The required
                      \output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_SetUserParameter                                                */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_GetUserParameter, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to parameter name in UTF8
		PRL_CONST_STR pParameterName,
		// Parameter value
		PRL_CHAR_PTR pParameterValue,
		// Parameter value buffer size
		PRL_UINT32_PTR BufferSize) );

/* Takes a snapshot of the specified virtual disk.
   Parameters
   Handle :          A handle of type PHT_VIRTUAL_DISK
                     identifying the virtual disk.
   pDirectoryName :  Directory name. The parameter is not
                     currently used.
   pUid :            A universally unique ID (UUID) to assign to
                     the new snapshot. You must generate the UUID
                     yourself.
   pCallback :       A pointer to a callback function or NULL
                     pointer. If the parameter contains a valid
                     pointer to the callback, the function will
                     be called asynchronously. If it contains a
                     NULL pointer, the function will be called
                     synchronously.
   pParameter :      A pointer to a buffer containing
                     user\-defined data to pass to the callback
                     function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_SwitchToState

   PrlDisk_DeleteState                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_CreateState, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to parameter name in UTF8
		PRL_CONST_STR pDirectoryName,
		// UID of the state
		PRL_CONST_GUID_PTR pUid,
		// Callback
		const PRL_STATES_CALLBACK pCallback,
		// Parameter to callback
		PRL_VOID_PTR pParameter) );

/* Reverts a virtual disk to the specified snapshot.
   Parameters
   Handle :          A handle of type PHT_VIRTUAL_DISK
                     identifying the virtual disk.
   pDirectoryName :  Directory name. This parameter is not
                     currently used.
   pUid :            The universally unique ID (UUID) assigned to
                     the disk. Use the PrlDisk_GetSnapshotsTree
                     function to obtain the snapshot tree with
                     UUIDs of individual snapshots.
   pCallback :       A pointer to a callback function or NULL
                     pointer. If the parameter contains a valid
                     pointer to the callback, the function will
                     be called asynchronously. If it contains a
                     NULL pointer, the function will be called
                     synchronously.
   pParameter :      A pointer to a buffer containing
                     user\-defined data to pass to the callback
                     function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_CreateState

   PrlDisk_DeleteState

   PrlDisk_GetSnapshotsTree                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_SwitchToState, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to parameter name in UTF8
		PRL_CONST_STR pDirectoryName,
		// UID of the state
		PRL_CONST_GUID_PTR pUid,
		// Callback
		const PRL_STATES_CALLBACK pCallback,
		// Parameter to callback
		PRL_VOID_PTR pParameter) );

/* Deletes the specified virtual disk snapshot.
   Parameters
   Handle :          A handle of type PHT_VIRTUAL_DISK
                     identifying the virtual disk.
   pDirectoryName :  Directory name. The parameter is not
                     currently used.
   pUid :            Universally unique ID (UUID) of the snapshot
                     to delete.
   bMerge :          A flag indicating whether the data contained
                     in the snapshot being deleted should be
                     merged with the descending snapshots.
                     PRL_TRUE merges the snapshot data, PRL_FALSE
                     simply deletes the snapshot. If you don't
                     merge the data, all descending snapshots
                     will be lost.
   pCallback :       A pointer to a callback function or NULL
                     pointer. If the parameter contains a valid
                     pointer to the callback, the function will
                     be called asynchronously. If it contains a
                     NULL pointer, the function will be called
                     synchronously.
   pParameter :      A pointer to a buffer containing
                     user\-defined data to pass to the callback
                     function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_CreateState

   PrlDisk_SwitchToState                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_DeleteState, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to parameter name in UTF8
		PRL_CONST_STR pDirectoryName,
		// UID of the state
		PRL_CONST_GUID_PTR pUid,
		// Need to merge or delete without it?
		const PRL_BOOL bMerge,
		// Callback
		const PRL_STATES_CALLBACK pCallback,
		// Parameter to callback
		PRL_VOID_PTR pParameter) );


/* Frees the PHT_VIRTUAL_DISK handle. This function must be
   called to free the PHT_VIRTUAL_DISK handle when it is no
   loner needed. Failure to do so will result in a memory leak.
   Parameters
   Handle :  A handle of type PHT_VIRTUAL_DISK identifying the
             virtual disk.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - operation completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_Free, (
		// Disk handle
		const PRL_HANDLE Handle) );

/* Writes data to the specified virtual disk.
   Parameters
   Handle :         A handle of type PHT_VIRTUAL_DISK identifying
                    the virtual disk.
   pBlock :         A pointer to the sector/page\-aligned data to
                    write (depends on the host operating system).
   uiSize :         Size of the data to write.
   uiBlockOffset :  Offset of the block on the disk, in sectors.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_Read                                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_Write, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Block to write
		PRL_CONST_VOID_PTR pBlock,
		// Size of block
		const PRL_UINT32 uiSize,
		// Offset of block (in sectors)
		const PRL_UINT64 uiBlockOffset) );

/* Reads data from the specified virtual disk.
   Parameters
   Handle :         A handle of type PHT_VIRTUAL_DISK identifying
                    the virtual disk.
   pBlock :         A pointer to sector/page\-aligned data to
                    read (depends on the host operating system).
   uiSize :         The size of the data to read.
   uiBlockOffset :  Offset of the block on the disk, in sectors.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_Write                                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_Read, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Block to write
		PRL_VOID_PTR pBlock,
		// Size of block
		const PRL_UINT32 uiSize,
		// Offset of block (in sectors)
		const PRL_UINT64 uiBlockOffset) );

/* Writes data from a virtual disk cache to the real storage.
   Parameters
   Handle :  A handle of type PHT_VIRTUAL_DISK identifying the
             virtual disk.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_FlushCache, (
		// Disk handle
		const PRL_HANDLE Handle) );

/* This method is deprecated now.

   Compacts a virtual disk. A virtual disk may become fragmented
   similar to a physical disk. As a result, the size that the
   disk files occupy on the physical hard drive may be larger
   than the size of the actual data they contain. The
   PrlDisk_Compact function defragments the specified virtual
   disk and decreases the size that the virtual disk files
   occupy on the physical hard disk. The designated size of the
   virtual disk itself remains unchanged.

   Please note that not all disks can be compacted. To determine
   if a disk can or cannot be compacted use the PrlDisk_IsCompactable
   function.
   Parameters
   Handle :         A handle of type PHT_VIRTUAL_DISK identifying
                    the virtual disk.
   pDiskCallback :  A pointer to a callback function or NULL
                    pointer. If the parameter contains a valid
                    pointer to the callback, the function will be
                    called asynchronously. If it contains a NULL
                    pointer, the function will be called
                    synchronously.
   pParameter :     A pointer to a buffer containing user\-defined
                    data to pass to the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_IsCompactable                                              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_Compact, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Callback
		const PRL_DISK_CALLBACK pDiskCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

/* Compacts a virtual disk with free blocks map.
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the virtual disk.
   pBitmap :     A pointer to a bit array of used blocks.
   uBlockSize :  Sectors per bit, i.e. block size.
   pCallback :   A pointer to a callback function or NULL
                 pointer. If the parameter contains a pointer to
                 a callback, the function will be called
                 asynchronously. If it contains NULL pointer, the
                 function will be called synchronously.
   pParameter :  A pointer to a buffer containing user\-defined
                 data to pass to the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlDisk_CompactByBitmap, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to the bitmap
		const PRL_UINT8_PTR pBitmap,
		// block size
		const PRL_UINT32 uBlockSize,
		// Callback
		const PRL_DISK_CALLBACK pCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

/* Estimate compacts for a virtual disk with free blocks map.
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the virtual disk.
   pBitmap :     A pointer to a bit array of used blocks.
   uBlockSize :  Sectors per bit, i.e. block size.
   uBlockCount : Estimated blocks count that will be reclaimed.
   pCallback :   A pointer to a callback function or NULL
                 pointer. If the parameter contains a pointer to
                 a callback, the function will be called
                 asynchronously. If it contains NULL pointer, the
                 function will be called synchronously.
   pParameter :  A pointer to a buffer containing user\-defined
                 data to pass to the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				PrlDisk_EstimateCompactByBitmap, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to the bitmap
		const PRL_UINT8_PTR pBitmap,
		// block size
		const PRL_UINT32 uBlockSize,
		// blocks count
		const PRL_UINT32_PTR puBlockCount,
		// Callback
		const PRL_DISK_CALLBACK pDiskCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

/* Checks and fixes consistency of a virtual disk.
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the virtual disk.
   pCallback :   A pointer to a callback function or NULL
                 pointer. If the parameter contains a pointer to
                 a callback, the function will be called
                 asynchronously. If it contains NULL pointer, the
                 function will be called synchronously.
   pParameter :  A pointer to a buffer containing user\-defined
                 data to pass to the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				PrlDisk_FixConsistency, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Callback
		const PRL_DISK_CALLBACK pCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

/*
	Allows to increase or decrease the size of an existing virtual disk.

	Increase :

	Disk size can be increased by adding a new storage segment(s)
	to its configuration or by increasing the size of an existing
	storage (only the size of the last storage segment in the
	storage list can be modified). A virtual disk can be
	comprised of one or more storage segments, which are logical
	portions of the entire disk. Each storage is contained in a
	separate file on the physical hard drive. All storages are
	logically connected in a particular order.

	To increase the overall disk capacity, a new storage(s) can be
	added at the end. In order to do that, specify new storage(s)
	list to add using PrlDiskParams_SetStorageList function. The type
	of storage can be either PRL_IMAGE_PLAIN or PRL_IMAGE_COMPRESSED
	depending on your preferences.

	Decrease :

	Depending on the new disk size, the size of the last storage
	segment in the virtual disk storage list will be adjusted or
	one (or more) storages will be deleted from the end of the
	list.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK identifying the virtual disk object.
	hDiskOpParams :	[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the resize parameters object.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDiskParams_SetSize
	PrlDiskStorageParams_SetSize
	PrlDiskStorageParams_SetImageType
	PrlDiskParams_SetStorageList
	PrlDiskOpParams_SetDiskParams

 */
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDisk_Resize, (
		PRL_HANDLE hDisk,
		PRL_HANDLE hDiskOpParams
		) );

/* Allows to increase the size of an existing virtual disk. Disk
   size can be increased by adding a new storage segment to its
   configuration or by increasing the size of an existing
   storage (only the size of the last storage segment in the
   storage list can be modified). A virtual disk can be
   comprised of one or more storage segments, which are logical
   portions of the entire disk. Each storage is contained in a
   separate file on the physical hard drive. All storages are
   logically connected in a particular order.

   To increase the overall disk capacity, a new storage can be
   added at the end. In order to do that, the members of the
   PRL_DISK_PARAMETERS structure that you pass in the pParam
   parameter must contain the following values:
     * <c>m_Parts</c> The number of storages to add (if adding
       one storage, pass 1).
     * <c>m_Storages</c> A pointer to an array of
       PRL_IMAGE_PARAMETERS structures. If adding a single storage,
       pass a pointer to a single structure. The uSize member of the
       structure must contain the new storage size. The <c>Type</c>
       member can be either PRL_IMAGE_PLAIN or PRL_IMAGE_COMPRESSED
       depending on your preferences.
   Parameters
   Handle :         A handle of type PHT_VIRTUAL_DISK identifying
                    the virtual disk.
   pParams :        Virtual disk parameters (see Remarks below).
   pDiskCallback :  A pointer to a callback function or NULL
                    pointer. If the parameter contains a valid
                    pointer to the callback, the function will be
                    called asynchronously. If it contains a NULL
                    pointer, the function will be called
                    synchronously.
   pParameter :     A pointer to a buffer containing user\-defined
                    data to pass to the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_DecreaseCapacity                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlDisk_IncreaseCapacity, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Increase paramenters
		PRL_CONST_DISK_PARAMETERS_PTR pParams,
		// Callback
		const PRL_DISK_CALLBACK pDiskCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

/* Allows to decrease the size of an existing virtual disk.
   Depending on the new disk size, the size of the last storage
   segment in the virtual disk storage list will be adjusted or
   one (or more) storages will be deleted from the end of the
   list.
   Parameters
   Handle :         A handle of type PHT_VIRTUAL_DISK identifying
                    the virtual disk.
   uiSize :         New overall disk size in sectors.
   pDiskCallback :  A pointer to a callback function or NULL
                    pointer. If the parameter contains a valid
                    pointer to the callback, the function will be
                    called asynchronously. If it contains a NULL
                    pointer, the function will be called
                    synchronously.
   pParameter :     A pointer to a buffer containing user\-defined
                    data to pass to the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_IncreaseCapacity                                        */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlDisk_DecreaseCapacity, (
		// Disk handle
		const PRL_HANDLE Handle,
		// New size
		const PRL_UINT64 uiSize,
		// Callback
		const PRL_DISK_CALLBACK pDiskCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

/* Combines all available disk snapshots into a single entity.
   On operation completion, the data from all existing disk
   snapshots will be merged and the snapshot tree will seize to
   exist.
   Parameters
   Handle :         A handle of type PHT_VIRTUAL_DISK identifying
                    the virtual disk.
   pDiskCallback :  A pointer to a callback function or NULL
                    pointer. If the parameter contains a valid
                    pointer to the callback, the function will be
                    called asynchronously. If it contains a NULL
                    pointer, the function will be called
                    synchronously.
   pParameter :     A pointer to a buffer containing user\-defined
                    data to pass to the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_GetSnapshotsTree

   PrlDisk_CreateState

   PrlDisk_SwitchToState

   PrlDisk_DeleteState                                             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_Coagulate, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Callback
		const PRL_STATES_CALLBACK pDiskCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

/* Determines if the specified virtual disk can be compacted.
   See the PrlDisk_Compact function for more information on disk
   compacting.
   Parameters
   Handle :   A handle of type PHT_VIRTUAL_DISK identifying the
              virtual disk.
   Result\ :  [out] A pointer to a variable that receives the
              \result. PRL_TRUE indicates that the disk image can
              be compacted. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_Compact                                                */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_IsCompactable, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Result receiver
		PRL_BOOL_PTR Result) );

/* Obtains the information about the specified virtual disk.
   Parameters
   Handle :           A handle of type PHT_VIRTUAL_DISK
                      identifying the virtual disk.
   pDiskParameters :  [out] A pointer to a buffer that receives
                      the disk information.
   BufferSize :       [in] The size of the output buffer (in
                      bytes). Set the buffer pointer to null and
                      this parameter's value to zero to receive
                      the required size. [out] The required
                      \output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_GetDiskInfo, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to memory, that receive parameters
		PRL_DISK_PARAMETERS_PTR pDiskParameters,
		// Parameter value buffer size
		PRL_UINT32_PTR BufferSize) );

/*
	Gets virtual disk states tree. States tree is returned as root node element,
	child elemets can be retrieved using PrlDiskStateParams_GetChildStateList function.

	Parameters
	hDisk :			[in] A handle of type PHT_VIRTUAL_DISK identifying the virtual disk
	phRootNode :	[out] A pointer to a variable that receives the new handle of type PHT_VIRTUAL_DISK_STATE_PARAMS.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDiskStateParams_GetChildStateList
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDisk_GetStatesTree, (
		PRL_HANDLE hDisk,
		PRL_HANDLE_PTR phRootNode
		) );

/*
	Gets virtual disk state UUID.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STATE_PARAMS identifying the virtual disk state.
	pGUID :			[out] A pointer to a variable that receives UUID.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDisk_GetStatesTree
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStateParams_GetUid, (
		PRL_HANDLE hParams,
		PRL_GUID_PTR pGUID
		) );

/*
	Gets virtual disk states child element list for specified element.
	Each element in the list has handle of type PHT_VIRTUAL_DISK_STATE_PARAMS.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STATE_PARAMS identifying the virtual disk state.
	phList :		[out] A pointer to a variable that receives the new handle of type PHT_HANDLES_LIST.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDisk_GetStatesTree
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStateParams_GetChildStateList, (
		PRL_HANDLE hParams,
		PRL_HANDLE_PTR phList
		) );

/* Determines the number of snapshots of the specified virtual
   disk. A virtual disk snapshot is created when a snapshot of a
   virtual machine is created or manually using the
   PrlDisk_CreateState function. Snapshots of a given virtual
   disk are organized into a tree. You can use the
   PrlDisk_GetSnapshotsTree function to obtain the entire tree
   and then, knowing the total snapshot count, traverse the
   tree. Each snapshot is identified using a universally unique
   ID (UUID). When you know the UUID of a snapshot of interest,
   you can revert to it or delete it if needed.
   Parameters
   Handle :          A handle of type PHT_VIRTUAL_DISK
                     identifying the virtual disk.
   SnapshotsCount :  [out] A pointer to a variable that receives
                     the snapshot count.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_GetSnapshotsTree

   PrlDisk_CreateState

   PrlDisk_SwitchToState

   PrlDisk_DeleteState                                           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_GetSnapshotsCount, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Variable to receive snapshots count
		PRL_UINT32_PTR SnapshotsCount) );

/* Obtains the entire snapshot tree for the specified virtual
   disk. A virtual disk snapshot is created when a snapshot of a
   virtual machine is created or manually using the
   PrlDisk_CreateState function. Each snapshot is identified
   using a universally unique ID (UUID). Snapshots of a given
   virtual disk are organized into a tree. You can use the
   PrlDisk_GetSnapshotsTree function to obtain the entire tree
   and then traverse it to obtain the UUID of a snapshot of
   interest. When you know the snapshot UUID, you can revert to
   it or delete it if needed.
   Parameters
   Handle :         A handle of type PHT_VIRTUAL_DISK identifying
                    the virtual disk.
   pSnapshotTree :  [out] A pointer to a buffer that receives the
                    \result.
   BufferSize :     [in] The size of the output buffer (in
                    bytes). Set the buffer pointer to null and
                    this parameter's value to zero to receive the
                    required size. [out] The required output
                    buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_GetSnapshotsCount

   PrlDisk_CreateState

   PrlDisk_SwitchToState

   PrlDisk_DeleteState                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				PrlDisk_GetSnapshotsTree, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to memory, that receive parameters
		PRL_SNAPSHOT_ELEMENT_PTR pSnapshotTree,
		// Parameter value buffer size
		PRL_UINT32_PTR BufferSize) );

/* Set the caching policy for a virtual disk.
   Parameters
   Handle :  A handle of type PHT_VIRTUAL_DISK identifying the
             virtual disk.
   Policy :  Caching policy to set. Possible values\:<p />PRL_DISK_CACHE_ENABLED
             \- caching enabled.<p />PRL_DISK_CACHE_DISABLED \-
             caching disabled.<p />PRL_DISK_CACHE_UNCACHED_READ \-
             cache write operations only. This option is
             available on Mac hosts only.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.                            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlDisk_SetCachingPolicy, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Caching policy value
		const PRL_UINT32 Policy) );

/* This function used to check is the disk bootable or not
   Parameters
   pDiskName :         The disk name for which to obtain the
                       handle, in UTF\-8 format. Disk name is the
                       same as the bundle name (Mac) or the
                       directory name (Windows, Linux) containing
                       the virtual disk files.
   pBootable :         Pointer to the value receiving disk status
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlDisk_IsBootable_Local, (
		// File name
		PRL_CONST_STR pDiskName,
		PRL_BOOL_PTR pBootable) );

/* This function used to create a linked clone disk
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the source virtual disk.
   GUID :        Pointer to the source disk snapshot GUID. If the
                 null GUID specified, the new snapshot will be created and
                 the cloned disk will be linked to created GUID.
   pDiskName :   The new disk name in UTF\-8 format.
                 Disk name is the same as the bundle name (Mac) or the
                 directory name (Windows, Linux) containing
                 the virtual disk files.
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlDisk_LinkedClone_Local, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Source uid
		PRL_CONST_GUID_PTR pGUID,
		// New disk name
		PRL_CONST_STR pDiskName) );

/* This function used to check is the disk encrypted or not
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the source virtual disk.
   Out :			 Boolean value, that receive status of disk encryption
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDisk_IsEncrypted, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Value receiving status
		PRL_BOOL_PTR Out) );

/* This function used to set the key to the encrypted disk
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the source virtual disk.
   Key :			 Pointer to the raw key data
   Length :		 Key length
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDisk_SetKey, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to the key
		PRL_UINT8_PTR Key,
		// Key length
		PRL_UINT32 Length) );

/* This function used to change the key of the encrypted disk
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the source virtual disk.
   Key :			 Pointer to the raw key data
   Length :		 Key length
   NewKey :		 Pointer to the raw new key data
   NewLength :		 New key length
   Salt :			 Pointer to the raw salt data or NULL pointer
   SaltLength :		 Salt length
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				PrlDisk_ChangeKeyEx, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to the key
		PRL_UINT8_PTR Key,
		// Key length
		PRL_UINT32 Length,
		// Pointer to the new key
		PRL_UINT8_PTR NewKey,
		// New key length
		PRL_UINT32 NewLength,
		// Pointer to the salt for key
		PRL_UINT8_PTR Salt,
		// Salt length
		PRL_UINT32 SaltLength) );

/* This function used to encrypt whole disk
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the source virtual disk.
   Engine :		 Encryption engine used to encrypt VM
   Key :			 Pointer to the raw key data
   Length :		 Key length
   Salt :			 Pointer to the raw salt data or NULL pointer
   SaltLength :		 Salt length
   pDiskCallback :  A pointer to a callback function or NULL
                    pointer. If the parameter contains a valid
                    pointer to the callback, the function will be
                    called asynchronously. If it contains a NULL
                    pointer, the function will be called
                    synchronously.
   pParameter :     A pointer to a buffer containing user\-defined
                    data to pass to the callback function.
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				PrlDisk_EncryptEx, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Engine
		PRL_GUID_PTR Engine,
		// Pointer to the key
		PRL_UINT8_PTR Key,
		// Key length
		PRL_UINT32 Length,
		// Pointer to the salt for key
		PRL_UINT8_PTR Salt,
		// Salt length
		PRL_UINT32 SaltLength,
		// Callback
		const PRL_DISK_CALLBACK pDiskCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

/* This function used to decrypt whole disk
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the source virtual disk.
   Key :			 Pointer to the raw key data
   Length :		 Key length
   pDiskCallback :  A pointer to a callback function or NULL
                    pointer. If the parameter contains a valid
                    pointer to the callback, the function will be
                    called asynchronously. If it contains a NULL
                    pointer, the function will be called
                    synchronously.
   pParameter :     A pointer to a buffer containing user\-defined
                    data to pass to the callback function.
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDisk_Decrypt, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to the key
		PRL_UINT8_PTR Key,
		// Key length
		PRL_UINT32 Length,
		// Callback
		const PRL_DISK_CALLBACK pDiskCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

/* This function used to convert disk size in blocks to the
   Cylinders-Heads-Sectors (CHS) format, used at disk creation
   Parameters
   Size   :      Disk size in sectors
   CHS    :      Pointer to PRL_CHS structure to fill to
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDisk_ConvertToCHS, (
		// Size in sectors
		PRL_UINT64 Size,
		// Size in CHS
		PRL_CHS_PTR Chs
		) );

/* This function used to calculate default block size of disk
   Parameters
   Size   :      Pointer to default block size of disk
   logicSectorSize   : Logic sector size of disk in bytes
   Returns:
   Default block size in sectors.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				PrlDisk_CalcDefaultBlockSize, (
		PRL_UINT32_PTR Size,
		// Logic sector size in bytes
		PRL_UINT64 logicSectorSize
				) );

/* This function used to get default logical sector size of disk
 Returns:
 Default logical sector size in bytes.                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlDisk_GetDefaultLogicSectorSize, (
		PRL_UINT32_PTR Size) );

/* This function used to get default physical sector size of disk
 Returns:
 Default physical sector size in bytes.                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlDisk_GetDefaultPhysicalSectorSize, (
		PRL_UINT32_PTR Size) );

/*	Get Theoretical upper limit (in sectors) after which we have to
	force splitted disks												*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
		PrlDisk_GetMaxNonSplitPartSize, (
		PRL_UINT64 logicSectorSize,
		PRL_UINT64_PTR Size
		) );

/*	Calculate the size of part of "splitted" disk in sectors.
	Part size is X Mb - 100 Mb for "may be smth. happens". Depends of
	the block size. The result is aligned to block size.				*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlDisk_CalcSplitPartSize, (
					 PRL_UINT64 sizeMib,
					 PRL_UINT64 logicSectorSize,
					 PRL_UINT64_PTR Size
					 ) );

/*
 * Definitions of length of incoming strings to PrlDisk_GetIdentify
 * function. The length includes c-string end '\0' symbol
 */
#define PRL_HDD_MODEL_LEN		41
#define PRL_HDD_SERIAL_LEN		21
#define PRL_HDD_FIRMWARE_LEN	9

/* This function used to get HDD identify information as it shown in guest OS
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the source virtual disk.
   Model    :    Pointer to array of 41 ASCII elements, that will
                 receive HDD model string
   Serial   :    Pointer to array of 21 ASCII elements, that will
                 receive HDD serial number
   Firmware :    Pointer to array of 9 ASCII elements, that will
                 receive HDD firmware revision
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDisk_GetIdentify, (
		// Disk handle
		const PRL_HANDLE Handle,
		PRL_CHAR_PTR Model,
		PRL_CHAR_PTR Serial,
		PRL_CHAR_PTR Firmware) );

/* Convert all Expanding images to Extend_Expanding
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
   pCallback :   A pointer to a callback function or NULL
                 pointer. If the parameter contains a pointer to
                 a callback, the function will be called
                 asynchronously. If it contains NULL pointer, the
                 function will be called synchronously.
   pParameter :  A pointer to a buffer containing user\-defined
                 data to pass to the callback function.
                the virtual disk.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				PrlDisk_ConvertToExtendFormat, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Callback
		const PRL_DISK_CALLBACK pCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );


/* Open a virtual disk at the specified snapshot. Current snaphot will not
   be changed.
   Parameters
   Handle :          A handle of type PHT_VIRTUAL_DISK
                     identifying the virtual disk.
   pUid :            The universally unique ID (UUID) assigned to
                     the disk. Use the PrlDisk_GetSnapshotsTree
                     function to obtain the snapshot tree with
                     UUIDs of individual snapshots.
   pCallback :       A pointer to a callback function or NULL
                     pointer. If the parameter contains a valid
                     pointer to the callback, the function will
                     be called asynchronously. If it contains a
                     NULL pointer, the function will be called
                     synchronously.
   pParameter :      A pointer to a buffer containing
                     user\-defined data to pass to the callback
                     function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid argument values.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDisk_CreateState

   PrlDisk_DeleteState

   PrlDisk_GetSnapshotsTree
   PrlDisk_SwitchToState                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				PrlDisk_ReopenWithSnapshot, (
		// Disk handle
		const PRL_HANDLE Handle,
		// UID of the state
		PRL_CONST_GUID_PTR pUid,
		// Callback
		const PRL_DISK_CALLBACK pCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );

///////////////////////////////////////////////////////////////////////////////
/// @section Disk parameters section
///////////////////////////////////////////////////////////////////////////////

/*
	Gets virtual disk parameters.

	Parameters
	hDisk :			[in] A handle of type PHT_VIRTUAL_DISK identifying the virtual disk
	phParams :		[out] A pointer to a variable that receives the new handle of type PHT_VIRTUAL_DISK_PARAMS

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDisk_GetParams, (
		PRL_HANDLE hDisk,
		PRL_HANDLE_PTR phParams
		) );

/*
	Creates virtual disk parameters object handle.
	Virtual disk parameters can be customize to perfrom disk operations, like create
	virtual disk.

	Parameters
	phParams :		[out] A pointer to a variable that receives the new handle of type PHT_VIRTUAL_DISK_PARAMS

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_Create, (
		PRL_HANDLE_PTR phParams
		) );

/*
	Gets virtual disk name.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pBuf :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pnBufLength :	[in] The size of the output buffer (in bytes). Set the buffer pointer to null
						 and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_GetName, (
		PRL_HANDLE hParams,
		PRL_STR pBuf,
		PRL_UINT32_PTR pnBufLength
		) );

/*
	Sets virtual disk name.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pString :		[in] The value to set. The value must be a a UTF\-8 encoded, null\-terminated string.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_SetName, (
		PRL_HANDLE hParams,
		PRL_CONST_STR pString
		) );

/*
	Gets virtual disk UUID.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pGUID :			[out] A pointer to a variable that receives UUID.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_GetUid, (
		PRL_HANDLE hParams,
		PRL_GUID_PTR pGUID
		) );

/*
	Sets virtual disk UUID.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pGUID :			[in] A pointer to a UUID.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_SetUid, (
		PRL_HANDLE hParams,
		PRL_CONST_GUID_PTR pGUID
		) );

/*
	Gets virtual disk size in sectors.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pnSize :		[out] A pointer to a variable that receives size.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_GetSize, (
		PRL_HANDLE hParams,
		PRL_UINT64_PTR pnSize
		) );

/*
	Sets virtual disk size in sectors.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	nSize :			[in] size in sectors.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_SetSize, (
		PRL_HANDLE hParams,
		PRL_UINT64 nSize
		) );

/*
	Gets virtual disk logical sector size in bytes.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pnSize :		[out] A pointer to a variable that receives size.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_GetLogicalSectorSize, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pnSize
		) );

/*
	Sets virtual disk logical sector size in bytes.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	nSize :			[in] size in sectors.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_SetLogicalSectorSize, (
		PRL_HANDLE hParams,
		PRL_UINT32 nSize
		) );

/*
	Gets virtual disk physical sector size in bytes.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pnSize :		[out] A pointer to a variable that receives size.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_GetPhysicalSectorSize, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pnSize
		) );

/*
	Sets virtual disk physical sector size in bytes.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	nSize :			[in] size in sectors.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_SetPhysicalSectorSize, (
		PRL_HANDLE hParams,
		PRL_UINT32 nSize
		) );

/*
	Gets virtual disk block size in sectors.
	(aligned to track, track = CHSsectors * sector_size)

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pnSize :		[out] A pointer to a variable that receives size.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDiskParams_GetCHS
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_GetBlockSize, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pnSize
		) );

/*
	Sets virtual disk block size in sectors.
	(aligned to track, track = CHSsectors * sector_size)

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	nSize :			[in] size in sectors.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_SetBlockSize, (
		PRL_HANDLE hParams,
		PRL_UINT32 nSize
		) );

/*
	Gets virtual disk Cylinders-Heads-Sectors (CHS) configuration.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pCHS :			[out] A pointer to a variable that receives CHS configuration.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_GetCHS, (
		PRL_HANDLE hParams,
		PRL_CHS_PTR pCHS
		) );

/*
	Sets virtual disk Cylinders-Heads-Sectors (CHS) configuration.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pCHS :			[in] A pointer to a variable that specifies CHS configuration.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_SetCHS, (
		PRL_HANDLE hParams,
		PRL_CONST_CHS_PTR pCHS
		) );

/*
	Gets virtual disk storages list.
	Each element in the list has handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STATE_PARAMS identifying the virtual disk state.
	phList :		[out] A pointer to a variable that receives the new handle of type PHT_HANDLES_LIST.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDiskParams_SetStorageList
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_GetStorageList, (
		PRL_HANDLE hParams,
		PRL_HANDLE_PTR phList
		) );

/*
	Sets virtual disk storages list.
	Each element in the list must be a handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STATE_PARAMS identifying the virtual disk state.
	hList :			[in] A handle of type PHT_HANDLES_LIST that specifies list of disk storages.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDiskParams_GetStorageList
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskParams_SetStorageList, (
		PRL_HANDLE hParams,
		PRL_HANDLE hList
		) );

/*
	Creates virtual disk storage parameters object handle.
	Virtual disk storage parameters can be customize to perfrom disk operations,
	like create virtual disk.

	Parameters
	phParams :		[out] A pointer to a variable that receives the new handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_Create, (
		PRL_HANDLE_PTR phParams
		) );

/*
	Gets virtual disk storage image type.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	pType :			[out] A pointer to a variable that receives the type.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_GetImageType, (
		PRL_HANDLE hParams,
		PRL_IMAGE_TYPE_PTR pType
		) );

/*
	Sets virtual disk storage image type.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	nType :			[in] The type of virtual disk storage image.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_SetImageType, (
		PRL_HANDLE hParams,
		PRL_IMAGE_TYPE nType
		) );

/*
	Gets virtual disk storage image name.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	pBuf :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pnBufLength :	[in] The size of the output buffer (in bytes). Set the buffer pointer to null
						 and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_GetImageName, (
		PRL_HANDLE hParams,
		PRL_STR pBuf,
		PRL_UINT32_PTR pnBufLength
		) );

/*
	Sets virtual disk storage image name.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	pString :		[in] The value to set. The value must be a a UTF\-8 encoded, null\-terminated string.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_SetImageName, (
		PRL_HANDLE hParams,
		PRL_CONST_STR pString
		) );

/*
	Gets virtual disk storage start sector.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	pnSize :		[out] A pointer to a variable that receives start sector.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_GetStart, (
		PRL_HANDLE hParams,
		PRL_UINT64_PTR pnStart
		) );

/*
	Sets virtual disk storage start sector.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	nStart :		[in] Start sector.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_SetStart, (
		PRL_HANDLE hParams,
		PRL_UINT64 nStart
		) );

/*
	Gets virtual disk storage size in sectors.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	pnSize :		[out] A pointer to a variable that receives size.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_GetSize, (
		PRL_HANDLE hParams,
		PRL_UINT64_PTR pnSize
		) );

/*
	Sets virtual disk storage size in sectors.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	nSize :			[in] Size in sectors.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_SetSize, (
		PRL_HANDLE hParams,
		PRL_UINT64 nSize
		) );

/*
	Determines if the specified virtual disk storage image is Read only.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	pbReadOnly :	[out] A pointer to a variable that receives the result.
					PRL_TRUE indicates that the disk storage image is Read only. PRL_FALSE indicates otherwise.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_GetReadOnly, (
		PRL_HANDLE hParams,
		PRL_BOOL_PTR pbReadOnly
		) );

/*
	Specifies that the specified virtual disk storage image must be Read only.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_STORAGE_PARAMS identifying the virtual disk storage object.
	pbReadOnly :	[in] PRL_TRUE indicates that the disk storage image must be Read only.
					PRL_FALSE indicates otherwise.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskStorageParams_SetReadOnly, (
		PRL_HANDLE hParams,
		PRL_BOOL bReadOnly
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section Disk operations parameters section
///////////////////////////////////////////////////////////////////////////////

/*
	Creates virtual disk operations parameters object handle.
	Virtual disk operations parameters can be used to perfrom disk operations, like create/open/...

	Parameters
	phParams :		[out] A pointer to a variable that receives the new handle of type PHT_VIRTUAL_DISK_OP_PARAMS

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskOpParams_Create, (
		PRL_HANDLE_PTR phParams
		) );

/*
	Gets virtual disk file path.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the parameters object.
	pBuf :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pnBufLength :	[in] The size of the output buffer (in bytes). Set the buffer pointer to null
						 and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskOpParams_GetDiskFilePath, (
		PRL_HANDLE hParams,
		PRL_STR pBuf,
		PRL_UINT32_PTR pnBufLength
		) );

/*
	Sets virtual disk file path.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the parameters object.
	pString :		[in] The value to set. The value must be a a UTF\-8 encoded, null\-terminated string.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskOpParams_SetDiskFilePath, (
		PRL_HANDLE hParams,
		PRL_CONST_STR pString
		) );

/*
	Gets virtual disk params assosiated with disk operations parameters handle.
	Returned handle is new handle that is not connected with PHT_VIRTUAL_DISK_OP_PARAMS handle.
	You can set required parameters in PHT_VIRTUAL_DISK_PARAMS handle and apply these params to
	PHT_VIRTUAL_DISK_OP_PARAMS using PrlDiskOpParams_SetDiskParams() function.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the parameters object.
	phDiskParams :	[out] A pointer to a variable that receives the new handle of type PHT_VIRTUAL_DISK_PARAMS

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDiskOpParams_SetDiskParams
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskOpParams_GetDiskParams, (
		PRL_HANDLE hParams,
		PRL_HANDLE_PTR phDiskParams
		) );

/*
	Sets virtual disk params assosiated with disk operations parameters handle.
	PHT_VIRTUAL_DISK_PARAMS handle parameters are copied to PHT_VIRTUAL_DISK_OP_PARAMS handle.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the parameters object.
	hDiskParams :	[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.

	See Also
	PrlDiskOpParams_GetDiskParams
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskOpParams_SetDiskParams, (
		PRL_HANDLE hParams,
		PRL_HANDLE hDiskParams
		) );

/*
	Gets virtual disk flags used in disk open operation.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the parameters object.
	pnOpenFlags :	[out] A pointer to a variable that receives Open flags.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskOpParams_GetDiskOpenFlags, (
		PRL_HANDLE hParams,
		PRL_DISK_OPEN_FLAGS_PTR pnOpenFlags
		) );

/*
	Sets virtual disk flags used in disk open operation.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the parameters object.
	nOpenFlags :	[in] The value to set.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskOpParams_SetDiskOpenFlags, (
		PRL_HANDLE hParams,
		PRL_DISK_OPEN_FLAGS nOpenFlags
		) );

/*
	Gets virtual disk callback function and callback parameter assosiated with disk operations parameters handle.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the parameters object.
	ppCallback :	[out] A pointer to a variable that receives a pointer to the callback function.
	ppParam :		[out] A pointer to a variable that receives a pointer to the callback function parameter.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskOpParams_GetDiskCallback, (
		PRL_HANDLE hParams,
		PRL_DISK_CALLBACK_PTR ppCallback,
		PRL_VOID_PTR_PTR ppParam
		) );

/*
	Sets virtual disk callback function and callback parameter assosiated with disk operations parameters handle.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_OP_PARAMS identifying the parameters object.
	pCallback :		[in] A pointer to a pointer to the callback function.
	pParam :		[in] A pointer to a pointer to the callback function parameter.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDiskOpParams_SetDiskCallback, (
		PRL_HANDLE hParams,
		PRL_DISK_CALLBACK pCallback,
		PRL_VOID_PTR pParam
		) );

/*
	Get the UID of the temporary disk snapshot

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK identifying the virtual disk.
	pGUID :			[out] A pointer to a variable that receives UUID.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
	PrlDisk_GetTemporarySnapshotUID, (
		PRL_HANDLE hDisk,
		PRL_GUID_PTR pGUID
		) );

/*
	Gets salt of a key of virtual disk.

	Parameters
	hParams :		[in] A handle of type PHT_VIRTUAL_DISK_PARAMS identifying the virtual disk parameters object.
	pBuf :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pnBufLength :	[in] The size of the output buffer (in bytes). Set the buffer pointer to null
						 and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9,
	PrlDiskParams_GetSalt, (
		PRL_HANDLE hParams,
		PRL_STR pBuf,
		PRL_UINT32_PTR pnBufLength
		) );

#ifdef __cplusplus
}
#endif

#endif
