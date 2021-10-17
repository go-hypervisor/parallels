///////////////////////////////////////////////////////////////////////////////
///
/// @file PrlApiMgrMacro.h
///
/// This file used in PrlApiMacro.h and sould not use directly
/// It defines depricated methods list
///
/// NOTE: This file is just a list of names.
/// No static/dymamic type info declated here at all.
///
/// @author myakhin
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////
#ifndef PRL_SDK_WRAP_FOR_EACH_MANAGER

#ifdef PRL_NO_MANAGER

#define PRL_SDK_WRAP_FOR_EACH_MANAGER()

#else

#define PRL_SDK_WRAP_FOR_EACH_MANAGER() \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_CreateDesktopControl ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetAllHostUsers ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlApi_SwitchConsoleLogging ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_SetCertificateRevocationDateTime ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_SetGlobalDateTime ) \


#endif // PRL_NO_MANAGER

#endif // PRL_SDK_WRAP_FOR_EACH_MANAGER
