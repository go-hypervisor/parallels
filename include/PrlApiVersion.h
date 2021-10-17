///////////////////////////////////////////////////////////////////////////////
///
/// @file PrlApiVersion.h
///
/// It was generated automatically according to current build config.
///
/// Copyright (c) 2005-2021 Parallels Software International, Inc.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////


#ifndef __PRLAPIVERSION_H__
#define __PRLAPIVERSION_H__

/* Converts major and minor versions of the API to the format
   understood by SDK library. */
#define TO_PARALLELS_API_VER(majorV, minorV) \
     ((PRL_UINT32)(((PRL_UINT32)majorV) << 16 | ((PRL_UINT16)minorV)))

/* Converts API version from the library native format to
   major and minor values. */
#define FROM_PARALLELS_API_VER(version, majorV, minorV) \
     majorV = ((PRL_UINT32)version) >> 16; \
     minorV = ((PRL_UINT32)version) & 0x0000FFFF


#define PARALLELS_API_VER_1 TO_PARALLELS_API_VER(0,1)
#define PARALLELS_API_VER_2 TO_PARALLELS_API_VER(2,0)
#define PARALLELS_API_VER_3 TO_PARALLELS_API_VER(3,0)
#define PARALLELS_API_VER_4 TO_PARALLELS_API_VER(4,0)
#define PARALLELS_API_VER_5 TO_PARALLELS_API_VER(5,0)
#define PARALLELS_API_VER_6 TO_PARALLELS_API_VER(6,0)
#define PARALLELS_API_VER_6_1 TO_PARALLELS_API_VER(6,1)
#define PARALLELS_API_VER_7 TO_PARALLELS_API_VER(7,0)
#define PARALLELS_API_VER_7_1 TO_PARALLELS_API_VER(7,1)
#define PARALLELS_API_VER_8 TO_PARALLELS_API_VER(8,0)
#define PARALLELS_API_VER_9 TO_PARALLELS_API_VER(9,0)

/* Current Parallels API version. */
#define PARALLELS_API_VER PARALLELS_API_VER_9

/* Current major version of SDK library */
#define PARALLELS_SDK_LIB_MAJ "9"

#endif // __PRLAPIVERSION_H__

