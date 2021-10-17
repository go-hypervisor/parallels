///////////////////////////////////////////////////////////////////////////////
///
/// PrlApiBackup.h
///
/// This file is the part of parallels public SDK library.
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_API_BACKUP_H__
#define __PARALLELS_API_BACKUP_H__

#ifdef __cplusplus
extern "C" {
#endif

// On windows platform we're taking advantage of the #pack directive
// to ensure internal structures alignment by 1 - on unixes we achive
// the same results by using the __attribute__((packed)) directive
// -> changing alignment
#ifdef _WIN_
    #pragma pack(push, save_api_pack, 1)
#endif

#include "PrlIOStructs.h"

///////////////////////////////////////////////////////////////////////////////
/// @section Generic API methods for the client
///
/// This section consists of methods that are used for general
/// manipulation of the parallels api library and are not specific
/// to objects in the object hierarchy.
///////////////////////////////////////////////////////////////////////////////

#include "PrlApiVersion.h"


///////////////////////////////////////////////////////////////////////////////
/// @section Backup object creation handling routines.
///////////////////////////////////////////////////////////////////////////////

/* Retrieves all backupable virtual machines from server.
   Parameters
   hServer         : A handle of type PHT_SERVER identifying
                     the Parallels Service.

   nFlags          : Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   Job result contains list of PHT_BACKUP handles.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_6,
				PrlSrv_GetBackupVmList, (
					 PRL_HANDLE hServer,
					 PRL_UINT32 nFlags
					 ) );

/* Retrieves backupable virtual machine registered by specific path.
   Parameters
   hServer         : A handle of type PHT_SERVER identifying
                     the Parallels Service.
   strPath         : Path to the virtual machine.
   nFlags          : Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   Job result contains PHT_BACKUP handle.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_6,
				PrlSrv_GetBackupVmByPath, (
					 PRL_HANDLE hServer,
					 PRL_CONST_STR strPath,
					 PRL_UINT32 nFlags
					 ) );

///////////////////////////////////////////////////////////////////////////////
/// @section Backup attributes.
///////////////////////////////////////////////////////////////////////////////

/* Returns backup session uuid. Returns an empty string if
   session has not been started yet.
   Parameters
   hBackupInfo  : A handle of type PHT_BACKUP_INFO.

   strUuid      : [out] A pointer to a buffer that receives
                  the result (a UTF\-8 encoded,
                  null\-terminated string).
   pnBufLength  : [in] The size of the output buffer (in
                  bytes). Set the buffer pointer to null
                  and this parameter's value to zero to
                  receive the required size. [out] The
                  required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackup_GetSessionUuid, (
					 PRL_HANDLE hBackup,
					 PRL_STR strUuid,
					 PRL_UINT32_PTR pnBufLength
					 ) );



///////////////////////////////////////////////////////////////////////////////
/// @section Backup info operations.
///////////////////////////////////////////////////////////////////////////////

/* Returns backup info handle.
   Parameters
   hBackup  : A handle of type PHT_BACKUP.

   phInfo   : [out] A pointer to a variable that receives
              the handle of type PHT_BACKUP_INFO.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackup_GetInfo, (
					 PRL_HANDLE hBackup,
					 PRL_HANDLE_PTR phBackupInfo
					 ) );

/* Returns the backupable virtual machine state information.
   Parameters
   handle :     A handle of type PHT_BACKUP_INFO.
   pnVmState : [out] A pointer to a variable that receives the
                virtual machine state information.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine state information is
   not available.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupInfo_GetState, (
					 PRL_HANDLE hBackupInfo,
					 VIRTUAL_MACHINE_STATE_PTR pnVmState
					 ) );

/* Checks that the backupable virtual machine is bootcamp VM.
   Parameters
   handle :      A handle of type PHT_BACKUP_INFO.
   pbBootcamp :  [out] A pointer to a variable that receives the
                 bootcamp information.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupInfo_IsBootcamp, (
					 PRL_HANDLE hBackupInfo,
					 PRL_BOOL_PTR pbBootcamp
					 ) );

/* Returns path to the virtual machine directory.
   Parameters
   hBackupInfo  : A handle of type PHT_BACKUP_INFO.

   strPath      : [out] A pointer to a buffer that receives
                  the result (a UTF\-8 encoded,
                  null\-terminated string).
   pnBufLength  : [in] The size of the output buffer (in
                  bytes). Set the buffer pointer to null
                  and this parameter's value to zero to
                  receive the required size. [out] The
                  required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupInfo_GetVmPath, (
					 PRL_HANDLE hBackupInfo,
					 PRL_STR strPath,
					 PRL_UINT32_PTR pnBufLength
					 ) );

///////////////////////////////////////////////////////////////////////////////
/// @section Backup parameter operations.
///////////////////////////////////////////////////////////////////////////////

/* Returns backup parameters handle.
   Parameters
   hBackup  :         A handle of type PHT_BACKUP.

   phBackupParams   : [out] A pointer to a variable that receives
                      the handle of type PHT_BACKUP_PARAMS.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackup_GetParams, (
					 PRL_HANDLE hBackup,
					 PRL_HANDLE_PTR phBackupParams
					 ) );

/* Set up backup parameters.
   Parameters
   hBackup  :        A handle of type PHT_BACKUP.

   pBackupParams   : [out] A pointer to a variable that receives
                     the handle of type PHT_BACKUP_PARAMS.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackup_SetParams, (
					 PRL_HANDLE hBackup,
					 PRL_HANDLE hBackupParams
					 ) );

/* Sets the location uuid for backup operation.
   Parameters
   hBackup         : A handle of type PHT_BACKUP_PARAMS.

   strLocationUuid : Uuid of the backup location.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_BACKUP_IN_PROGRESS - parameter can not be changed
   because the backup operation already started.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_SetLocationUuid, (
					 PRL_HANDLE hBackupParams,
					 PRL_CONST_STR strLocationUuid
					 ) );

/* Returns the location uuid for backup operation.
   Parameters
   hBackup    : A handle of type PHT_BACKUP_PARAMS.

   strLocationUuid : [out] A pointer to a buffer that receives
              the result (a UTF\-8 encoded,
              null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_GetLocationUuid, (
					 PRL_HANDLE hBackupParams,
					 PRL_STR strLocationUuid,
					 PRL_UINT32_PTR pnBufLength
					 ) );

/* Sets the backup level.
   Parameters
   hBackup : A handle of type PHT_BACKUP_PARAMS.

   nLevel  : Backup level.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_BACKUP_IN_PROGRESS - parameter can not be changed
   because the backup operation already started.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_SetLevel, (
					 PRL_HANDLE hBackupParams,
					 PRL_BACKUP_LEVEL nLevel
					 ) );

/* Returns the backup level.
   Parameters
   hBackup : A handle of type PHT_BACKUP_PARAMS.

   pnLevel : A pointer to a variable that receives the
            \result. See PRL_BACKUP_FILE_TYPE enum.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_GetLevel, (
					 PRL_HANDLE hBackupParams,
					 PRL_BACKUP_LEVEL_PTR pnLevel
					 ) );

/* Sets the change monitoring for backup.
   Parameters
   hBackup : A handle of type PHT_BACKUP_PARAMS.

   bOn     : Backup change monitoring value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_BACKUP_IN_PROGRESS - parameter can not be changed
   because the backup operation already started.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_SetChangeMonitoring, (
					 PRL_HANDLE hBackupParams,
					 PRL_BOOL bOn
					 ) );

/* Returns the change monitoring for current backup operation.
   Parameters
   hBackup : A handle of type PHT_BACKUP_PARAMS.

   pnOn    : A pointer to a variable that receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_GetChangeMonitoring, (
				 	 PRL_HANDLE hBackupParams,
					 PRL_BOOL_PTR pbOn
					 ) );

/* Sets the backup location timeout. It defines the maximum allowed
   time between two backups for same location when change monitoring
   is enabled.
   Parameters
   hBackup  : A handle of type PHT_BACKUP_PARAMS.

   nTimeout : Backup location timeout value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_BACKUP_IN_PROGRESS - parameter can not be changed
   because the backup operation already started.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_SetLocationTimeout, (
					 PRL_HANDLE hBackupParams,
					 PRL_UINT64 nTimeout
					 ) );

/* Returns the backup location timeout.
   Parameters
   hBackup   : A handle of type PHT_BACKUP_PARAMS.

   pnTimeout : A pointer to a variable that receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_GetLocationTimeout, (
				 	 PRL_HANDLE hBackupParams,
					 PRL_UINT64_PTR pnTimeout
					 ) );

/* Sets the backup options.
   Parameters
   hBackup  : A handle of type PHT_BACKUP_PARAMS.

   nOptions : Bitmask of valid backup options.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_BACKUP_IN_PROGRESS - parameter can not be changed
   because the backup operation already started.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_SetOptions, (
					 PRL_HANDLE hBackupParams,
					 PRL_UINT32 nOptions
					 ) );

/* Get the backup options.
   Parameters
   hBackup   : A handle of type PHT_BACKUP_PARAMS.

   pnOptions : A pointer to a variable that receives the options bitmask.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupParam_GetOptions, (
				 	 PRL_HANDLE hBackupParams,
					 PRL_UINT32_PTR pnOptions
					 ) );


///////////////////////////////////////////////////////////////////////////////
/// @section Backup mech operations.
///////////////////////////////////////////////////////////////////////////////

/* Begins backup transaction.
   Parameters
   hBackup         : A handle of type PHT_BACKUP.

   nFlags          : Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackup_Begin, (
					 PRL_HANDLE hBackup,
					 PRL_UINT32 nFlags
					 ) );

/* Commits backup transaction.
   Parameters
   hBackup : A handle of type PHT_BACKUP.

   nFlags  : Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackup_Commit, (
					 PRL_HANDLE hBackup,
					 PRL_UINT32 nFlags
					 ) );

/* Rollbacks backup transaction.
   Parameters
   hBackup : A handle of type PHT_BACKUP.

   nFlags  : Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackup_Rollback, (
					 PRL_HANDLE hBackup,
					 PRL_UINT32 nFlags
					 ) );

/* Returns backup file info handles list.
   Parameters
   hBackup  : A handle of type PHT_BACKUP.

   phList   : [out] A pointer to a variable that receives
              the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackup_GetFilesList, (
					 PRL_HANDLE hBackup,
					 PRL_HANDLE_PTR phList
					 ) );

/* Send backup progress information to the server.
   Parameters
   hBackup          : A handle of type PHT_BACKUP.

   nCurrentProgress : Current progress value
   nMaxProgress     : Maximum progress value
   nError           : Last backup error code.
   nFlags  			: Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackup_SendProgress, (
					 PRL_HANDLE hBackup,
					 PRL_UINT32 nCurrentProgress,
					 PRL_UINT32 nMaxProgress,
					 PRL_RESULT nError,
					 PRL_UINT32 nFlags
					 ) );


///////////////////////////////////////////////////////////////////////////////
/// @section Backup file info operations.
///////////////////////////////////////////////////////////////////////////////

/* Returns backup file difference info handles list.
   Parameters
   hFile    : A handle of type PHT_BACKUP_FILE.

   phList   : [out] A pointer to a variable that receives
              the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_OUT_OF_MEMORY - out of memory to create
   backup object.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupFile_GetDifferencesList, (
					 PRL_HANDLE hFile,
					 PRL_HANDLE_PTR phList
					 ) );

/* Returns file path to backup it.
   Parameters
   hFile    : A handle of type PHT_BACKUP_FILE.

   sPath    : [out] A pointer to a buffer that receives
              the result (a UTF\-8 encoded,
              null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupFile_GetPath, (
					 PRL_HANDLE hFile,
					 PRL_STR sPath,
					 PRL_UINT32_PTR pnBufLength
					 ) );

/* Returns  path that should be used to restore backed up file.
   Note that restore file path value can differ from original file path.
   Parameters
   hFile    : A handle of type PHT_BACKUP_FILE.

   sPath    : [out] A pointer to a buffer that receives
              the result (a UTF\-8 encoded,
              null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupFile_GetRestorePath, (
					 PRL_HANDLE hFile,
					 PRL_STR sPath,
					 PRL_UINT32_PTR pnBufLength
					 ) );

/* Returns backup file kind.
   hFile    : A handle of type PHT_BACKUP_FILE.

   pnKind : A pointer to a variable that receives the
            \result. See PRL_BACKUP_FILE_KIND enum.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupFile_GetKind, (
					 PRL_HANDLE hFile,
					 PRL_BACKUP_FILE_KIND_PTR pnKind
					 ) );

/* Returns backup file type.
   hFile    : A handle of type PHT_BACKUP_FILE.

   pnKind : A pointer to a variable that receives the
            \result. See PRL_BACKUP_FILE_TYPE enum.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupFile_GetType, (
					 PRL_HANDLE hFile,
					 PRL_BACKUP_FILE_TYPE_PTR pnType
					 ) );

/* Returns backup file level.
   hFile   : A handle of type PHT_BACKUP_FILE.

   pnLevel : A pointer to a variable that receives the
             \result. See PRL_BACKUP_LEVEL enum.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupFile_GetLevel, (
					 PRL_HANDLE hFile,
					 PRL_BACKUP_LEVEL_PTR pnLevel
					 ) );

/* Returns backup file size.
   hFile   : A handle of type PHT_BACKUP_FILE.

   pnSize  : A pointer to a variable that receives the
             \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupFile_GetSize, (
					 PRL_HANDLE hFile,
					 PRL_UINT64_PTR pnSize
					 ) );

///////////////////////////////////////////////////////////////////////////////
/// @section Backup file's difference info operations.
///////////////////////////////////////////////////////////////////////////////

/* Returns file difference offset.
   Parameters
   hDiff    : A handle of type PHT_BACKUP_FILE_DIFF.
   pnOffset : [out] A pointer to a variable that receives
              the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupFileDiff_GetOffset, (
					 PRL_HANDLE hDiff,
					 PRL_UINT64_PTR pnOffset
					 ) );

/* Returns file difference size.
   Parameters
   hDiff  : A handle of type PHT_BACKUP_FILE_DIFF.
   pnSize : [out] A pointer to a variable that receives
            the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer
   was passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlBackupFileDiff_GetSize, (
					 PRL_HANDLE hDiff,
					 PRL_UINT64_PTR pnSize
					 ) );


#ifdef _WIN_
    #pragma pack(pop, save_api_pack)
#endif

#ifdef __cplusplus
}
#endif

#endif	// __PARALLELS_API_BACKUP_H__
