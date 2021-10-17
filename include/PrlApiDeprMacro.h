///////////////////////////////////////////////////////////////////////////////
///
/// @file PrlApiDeprMacro.h
///
/// This file used in PrlApiMacro.h and sould not use directly
/// It defines depricated methods list
///
/// NOTE: This file is just a list of names.
/// No static/dymamic type info declated here at all.
///
/// @author Vadim Hohlov
///
/// Copyright (c) Parallels International GmbH. All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////
#ifndef PRL_SDK_WRAP_FOR_EACH_DEPRECATED

#ifdef PRL_NO_DEPRECATED

#define PRL_SDK_WRAP_FOR_EACH_DEPRECATED()

#else

#define PRL_SDK_WRAP_FOR_EACH_DEPRECATED() \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlApi_IsGuestOs ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlApi_SetMainServerVersion ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlApi_GetMainServerVersion ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlApi_GetProductName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_FromString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_ToString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_PortForwardingFromString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_PortForwardingToString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlLic_FromString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlLic_ToString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlLic_Create ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlLoginResponse_ToString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlResult_GetError ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlResult_GetParamToken ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_FromString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_SendToolsGeneralCommand ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDev_FromString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDev_ToString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDev_UpdateInfo ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlUsrCfg_FromString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlUsrCfg_ToString )\
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlUsrCfg_AddProxy ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlResult_FromString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_SetCpuVtxEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_StartConvertHdd ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_CreateAnswerEvent ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_SmcGetRuntimeInfo ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_TisGetEmitter ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlTisEmitter_GetUid ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlTisEmitter_RegCallback ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlTisEmitter_UnregCallback ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_RegisterTool ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlTool_SendData ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlTool_SendDataAsync ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlTool_AllocBuffer ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlTool_FreeBuffer ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlUsr_GetClientConfig ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlTool_Unregister ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToolsEmptyRecycleBin ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToolsOpenFileBrowser ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToolsWindowsShellToggleDesktop ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToolsMoveTaskBar ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToolsShowRecycleBin ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToolsNotifyCoherenceState ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToolsChangeScreenSaverState ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_UpdateToolsSection ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_PrepareForHibernate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_AfterHostResume ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_Remove ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_IsEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_IsHidden ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetHidden ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_IsDhcpEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetDhcpEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_GetNetworkType ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetNetworkType ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_GetName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_GetUuid ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_GetSysName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetSysName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_GetIndex ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetIndex ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_GetDhcpScopeStartIp ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetDhcpScopeStartIp ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_GetDhcpScopeEndIp ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetDhcpScopeEndIp ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_GetDhcpScopeMask ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispNet_SetDhcpScopeMask ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_AddNetAdapter ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_DeleteNetAdapter ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_UpdateNetAdapter ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_CreateDispNet ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetDispNetCount ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetDispNet ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlTools_SendUtilityCommand ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDevSIA_SendSIAData ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlApi_SetLogPath ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetDevsList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToolsAdjustWorkingArea ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_StoreValueByKey ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_StoreValueByKey ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_SendClientStatistics ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_UpdateUsbDevicesAssociationsList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_RunCompressor ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_CancelCompressor ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDevDisplay_SyncSetScreenSurface ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_InternalCommand ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_RestartNetworkShaping ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_UpdateNetworkShapingList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetNetworkShapingList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkClass_Create ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkClass_GetClassId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkClass_SetClassId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkClass_GetNetworkList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkClass_SetNetworkList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_UpdateNetworkClassesList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetNetworkClassesList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingEntry_Create ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingEntry_GetClassId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingEntry_SetClassId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingEntry_GetTotalRate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingEntry_SetTotalRate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingEntry_SetDevice ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingEntry_GetDevice) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingEntry_SetRate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingEntry_GetRate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_UpdateNetworkShapingConfig ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetNetworkShapingConfig ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingConfig_IsEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingConfig_SetEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingConfig_GetNetworkShapingList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingConfig_SetNetworkShapingList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingBandwidthEntry_Create ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingBandwidthEntry_SetDevice ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingBandwidthEntry_GetDevice ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingBandwidthEntry_SetBandwidth ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingBandwidthEntry_GetBandwidth) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingConfig_GetNetworkDeviceBandwidthList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkShapingConfig_SetNetworkDeviceBandwidthList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkRate_Create ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkRate_GetClassId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlNetworkRate_GetRate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetNetworkRateList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetNetworkRateList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsRateBound ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetRateBound ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetDefaultGateway) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetDefaultGatewayIPv6) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetDefaultGateway) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetDefaultGatewayIPv6) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevHd_GetBlockSize ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevHd_SetBlockSize ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_Is3DAccelerationEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_Set3DAccelerationEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_IsClusterMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetClusterMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_StartClusterService ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_StopClusterService ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetProxyManagerURL ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetProxyManagerURL ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetHostId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetHostId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_ToolsSetIndents ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsEditRestricted ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetEditRestriction ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_SendProblemReport ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetWebPortalDomain ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetWebPortalDomain ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_IsHeadlessModeEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetHeadlessModeEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetLicenseRequestFlags) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetLicenseRequestFlags) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDevAudio_StartOutputStream ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDevAudio_StopOutputStream ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDevAudio_SetOutputEncoding ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDevAudio_GetOutputEncoding ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetAudioOutputEncodingList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsDisableSpeaker ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetDisableSpeakerSign ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlJob_Resend ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetHostMemQuotaMin ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetHostMemQuotaMin ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsLockInFullScreenMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetLockInFullScreenMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsOfflineManagementEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetOfflineManagementEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlOffmgmtService_Create ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlOffmgmtService_GetName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlOffmgmtService_SetName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlOffmgmtService_GetPort ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlOffmgmtService_SetPort ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlOffmgmtService_IsUsedByDefault ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlOffmgmtService_SetUsedByDefault ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetOfflineServices ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetOfflineServices ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_UpdateOfflineService ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_DeleteOfflineService ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetOfflineServicesList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrvCfg_GetCpuFeaturesEx ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrvCfg_GetCpuFeaturesMaskingCapabilities ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetCpuFeaturesMaskEx ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetCpuFeaturesMaskEx ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCpuFeatures_Create ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCpuFeatures_GetValue ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCpuFeatures_SetValue ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetIoPriority ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetIoPriority ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetIoLimit ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetIoLimit ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetIopsLimit ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetIopsLimit ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetCpuLimit ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetCpuLimit ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetCpuLimitEx ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetCpuLimitEx ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetCpuMask ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetCpuMask ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetCpuUnits ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetCpuUnits ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevNet_IsFirewallEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevNet_SetFirewallEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevNet_GetFirewallDefaultPolicy ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevNet_SetFirewallDefaultPolicy ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevNet_GetFirewallRuleList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevNet_SetFirewallRuleList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_Create ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_GetLocalPort ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_SetLocalPort ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_GetRemotePort ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_SetRemotePort ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_GetProtocol ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_SetProtocol ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_GetLocalNetAddress ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_SetLocalNetAddress ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_GetRemoteNetAddress ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlFirewallRule_SetRemoteNetAddress ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetResource ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetResource ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCtTemplate_GetName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCtTemplate_GetType ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCtTemplate_GetDescription ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCtTemplate_GetVersion ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCtTemplate_GetOsType ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCtTemplate_GetOsVersion ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCtTemplate_GetOsTemplate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCtTemplate_GetCpuMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlCtTemplate_IsCached ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetCtTemplateList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_RemoveCtTemplate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_CopyCtTemplate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetAppTemplateList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetAppTemplateList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetOsTemplate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetOsTemplate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetCapabilitiesMask ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetCapabilitiesMask ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetFeaturesMask ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetFeaturesMask ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetNetfilterMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetNetfilterMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevHd_SetAutoCompressEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevHd_IsAutoCompressEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevHd_SetMountPoint ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevHd_GetMountPoint ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_AddIPPrivateNetwork ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_RemoveIPPrivateNetwork ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_UpdateIPPrivateNetwork ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetIPPrivateNetworksList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlIPPrivNet_Create ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlIPPrivNet_GetName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlIPPrivNet_SetNetAddresses ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlIPPrivNet_GetNetAddresses ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlIPPrivNet_SetName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlIPPrivNet_IsGlobal ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlIPPrivNet_SetGlobal ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevHd_SetStorageURL ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevHd_GetStorageURL ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_CreateVmBackup ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_RestoreVmBackup ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetBackupTree ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_RemoveVmBackup ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlBackupResult_GetBackupUuid ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetDefaultBackupServer ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetDefaultBackupServer ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetBackupUserLogin ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetBackupUserLogin ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetBackupUserPassword ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_IsBackupUserPasswordEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetBackupUserPasswordEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetDefaultBackupDirectory ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetDefaultBackupDirectory ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetBackupTimeout ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetBackupTimeout ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_Migrate ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_MigrateEx ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_MigrateWithRename ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_MigrateWithRenameEx ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_MigrateCancel ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetEnvId) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetVmType ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetVmType ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetDefaultCtDir ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_Mount ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_Umount ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevNet_GetVirtualNetworkId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmDevNet_SetVirtualNetworkId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetDefaultVmConfig) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_ApplyConfigSample ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsEfiEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetEfiEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDevDisplay_SendCaptureScreenRequest ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDevSecondaryDisplay_SendCaptureScreenRequest ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_ActivateInstalledLicenseOnline ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_ActivateInstalledLicenseOffline ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlLic_GetUserName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlLic_GetCompanyName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetDefaultEncryptionPluginId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetDefaultEncryptionPluginId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetPluginsList ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_RefreshPlugins ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlPluginInfo_GetVendor ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlPluginInfo_GetCopyright ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlPluginInfo_GetShortDescription ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlPluginInfo_GetLongDescription ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlPluginInfo_GetVersion ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlPluginInfo_GetId ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDisk_GetDefaultBlockSize ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDisk_GetSplitPartSize ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDisk_CommitUnfinishedOp ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDisk_ChangeKey ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDisk_Encrypt ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetVNCMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetVNCMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetVNCPassword ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetVNCPassword ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetVNCHostName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetVNCHostName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetVNCPortNumber ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetVNCPortNumber ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetDefaultVNCHostName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetDefaultVNCHostName ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetVNCBasePort ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetVNCBasePort ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_ArePluginsEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_EnablePlugins ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_GetOverallMemLimit ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlDispCfg_SetOverallMemLimit ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlReport_Send ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlApi_SendProblemReport ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_GetProblemReport ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVm_GetProblemReport ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlApi_CreateProblemReport ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsAddInstalledAppsToLaunchpad ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetAddInstalledAppsToLaunchpad ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsRelocateTaskBar ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetRelocateTaskBar ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetCoherenceButtonVisibility ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetCoherenceButtonVisibility ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsSwitchOffAeroEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetSwitchOffAeroEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_IsHideMinimizedWindowsEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetHideMinimizedWindowsEnabled ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrvConfig_FromString ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrv_Register3rdPartyVm ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_GetCpuMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlVmCfg_SetCpuMode ) \
PRL_SDK_WRAP_FOR_EACH_ITERATOR( PrlSrvCfg_GetCpuMode )
#endif // PRL_NO_DEPRECATED

#endif // PRL_SDK_WRAP_FOR_EACH_DEPRECATED
