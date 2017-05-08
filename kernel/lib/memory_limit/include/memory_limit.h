
// Copyright 2016 The Fuchsia Authors
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT
#pragma once
#include <iovec.h>
#include <types.h>

typedef struct mem_limit_cfg {
    uintptr_t kernel_base;
    uintptr_t kernel_end;
    uintptr_t ramdisk_base;
    size_t ramdisk_size;
    size_t memory_limit;
} mem_limit_cfg_t;

status_t mem_limit_apply(mem_limit_cfg_t* cfg,
                            uintptr_t range_base,
                            size_t range_size,
                            iovec_t* iovs[2],
                            size_t iov_cnt);

status_t mem_limit_get(uint64_t* limit);
status_t mem_limit_init(mem_limit_cfg_t* cfg);
