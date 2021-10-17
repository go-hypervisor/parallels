///////////////////////////////////////////////////////////////////////////////
///
/// PrlApi.h
///
/// This file is the part of parallels public SDK library.
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_API_MANAGEMENT_H__
#define __PARALLELS_API_MANAGEMENT_H__

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

#ifndef PRL_NO_DEPRECATED
#include "PrlApiDeprecated.h"
#endif // !defined(PRL_NO_DEPRECATED)

#ifndef PRL_NO_MANAGER
#include "PrlApiManager.h"
#endif

#include "PrlApiCore.h"
#include "PrlApiDisp.h"
#include "PrlApiVm.h"
#include "PrlApiNet.h"
#include "PrlApiStat.h"
#include "PrlApiRemoteDev.h"
#include "PrlApiBackup.h"

#ifdef _WIN_
    #pragma pack(pop, save_api_pack)
#endif

#ifdef __cplusplus
}
#endif

#endif // __PARALLELS_API_MANAGEMENT_H__
