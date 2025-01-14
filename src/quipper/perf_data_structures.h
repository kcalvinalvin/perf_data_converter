// Copyright 2016 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMIUMOS_WIDE_PROFILING_PERF_DATA_STRUCTURES_H_
#define CHROMIUMOS_WIDE_PROFILING_PERF_DATA_STRUCTURES_H_

#include <vector>

#include "kernel/perf_event.h"

// Data structures that are used by multiple modules.

namespace quipper {

// This is becoming more like a partial struct perf_evsel
struct PerfFileAttr {
  struct perf_event_attr attr;
  std::string name;
  std::vector<uint64_t> ids;
};

struct PerfUint32Metadata {
  uint32_t type;
  std::vector<uint32_t> data;
};

struct PerfUint64Metadata {
  uint32_t type;
  std::vector<uint64_t> data;
};

struct PerfCPU {
  uint32_t core_id;
  uint32_t socket_id;
};

struct PerfCPUTopologyMetadata {
  std::vector<std::string> core_siblings;
  std::vector<std::string> thread_siblings;
  std::vector<PerfCPU> available_cpus;
};

struct PerfNodeTopologyMetadata {
  uint32_t id;
  uint64_t total_memory;
  uint64_t free_memory;
  std::string cpu_list;
};

struct PerfPMUMappingsMetadata {
  uint32_t type;
  std::string name;
};

struct PerfGroupDescMetadata {
  std::string name;
  uint32_t leader_idx;
  uint32_t num_members;
};

}  // namespace quipper

#endif  // CHROMIUMOS_WIDE_PROFILING_PERF_DATA_STRUCTURES_H_
