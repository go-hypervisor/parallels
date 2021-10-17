///////////////////////////////////////////////////////////////////////////////
///
/// PrlPerfCounters.h
///
/// This file is the part of parallels public SDK library.
/// Published performance counters list
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_PERF_COUNTERS_H__
#define __PARALLELS_PERF_COUNTERS_H__

//Total count of read requests to IDE controller
#define PRL_IDE_READ_REQUESTS_PTRN			"devices.ide#.read_requests"

//Total count of read bytes through IDE controller
#define PRL_IDE_READ_TOTAL_PTRN				"devices.ide#.read_total"

//Total count of write requests to IDE controller
#define PRL_IDE_WRITE_REQUESTS_PTRN			"devices.ide#.write_requests"

//Total count of write bytes through IDE controller
#define PRL_IDE_WRITE_TOTAL_PTRN			"devices.ide#.write_total"

//Total count of read requests to SCSI controller
#define PRL_SCSI_READ_REQUESTS_PTRN			"devices.scsi#.read_requests"

//Total count of read bytes through SCSI controller
#define PRL_SCSI_READ_TOTAL_PTRN			"devices.scsi#.read_total"

//Total count of write requests to SCSI controller
#define PRL_SCSI_WRITE_REQUESTS_PTRN			"devices.scsi#.write_requests"

//Total count of write bytes through SCSI controller
#define PRL_SCSI_WRITE_TOTAL_PTRN			"devices.scsi#.write_total"

//Total count of read requests to SATA controller
#define PRL_SATA_READ_REQUESTS_PTRN			"devices.sata#.read_requests"

//Total count of read bytes through SATA controller
#define PRL_SATA_READ_TOTAL_PTRN			"devices.sata#.read_total"

//Total count of write requests to SATA controller
#define PRL_SATA_WRITE_REQUESTS_PTRN			"devices.sata#.write_requests"

//Total count of write bytes through SATA controller
#define PRL_SATA_WRITE_TOTAL_PTRN			"devices.sata#.write_total"



#define PRL_NET_PKTS_IN_PTRN				"net.nic#.pkts_in"
#define PRL_NET_PKTS_OUT_PTRN				"net.nic#.pkts_out"
#define PRL_NET_BYTES_IN_PTRN				"net.nic#.bytes_in"
#define PRL_NET_BYTES_OUT_PTRN				"net.nic#.bytes_out"


//Classful network traffic counting info. Result parameter provides
//as binary buffer contains structure PRL_STAT_NET_TRAFFIC. See
//PrlIOStructs.h for more info
#define PRL_NET_CLASSFUL_TRAFFIC_PTRN		"net.classful.traffic"

//Guest OS CPU usage in percents (modulated to 100%)
#define PRL_GUEST_CPU_USAGE_PTRN			"guest.cpu.usage"

//Guest OS RAM usage in megabytes
#define PRL_GUEST_RAM_USAGE_PTRN			"guest.ram.usage"
#define PRL_GUEST_RAM_CACHED_PTRN			"guest.ram.cached"
#define PRL_WS_RECLAIMABLE_PTRN				"ws.reclaimable"

#endif

