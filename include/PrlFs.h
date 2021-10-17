///////////////////////////////////////////////////////////////////////////////
///
/// PrlFs.h
///
/// This file is the part of parallels public sdk library
///
/// Remote file system specific definitions
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_API_FS_H__
#define __PARALLELS_API_FS_H__


#define FS_PERM_EXECUTE					0x1
#define FS_PERM_READ					0x2
#define FS_PERM_WRITE					0x4

#define IS_FS_EXECUTE_PERMITTED(x)		( (x) & FS_PERM_EXECUTE ?1:0 )
#define IS_FS_READ_PERMITTED(x)			( (x) & FS_PERM_READ ?1:0 )
#define IS_FS_WRITE_PERMITTED(x)		( (x) & FS_PERM_WRITE ?1:0 )

#define SET_FS_EXECUTE_ENABLED(x)		(x) | FS_PERM_EXECUTE;
#define SET_FS_READ_ENABLED(x)			(x) | FS_PERM_READ;
#define SET_FS_WRITE_ENABLED(x)			(x) | FS_PERM_WRITE;

#define SET_FS_EXECUTE_DISABLED(x)		(x) & ~FS_PERM_EXECUTE;
#define SET_FS_READ_DISABLED(x)			(x) & ~FS_PERM_READ;
#define SET_FS_WRITE_DISABLED(x)		(x) & ~FS_PERM_WRITE;

#endif//__PARALLELS_API_FS_H__
