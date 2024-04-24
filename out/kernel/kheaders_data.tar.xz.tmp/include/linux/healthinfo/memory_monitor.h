/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _MEMORY_MONITOR_H_
#define _MEMORY_MONITOR_H_
extern struct ion_wait_para ionwait_para;
extern void memory_alloc_monitor(gfp_t gfp_mask, unsigned int order, u64 wait_ms);

extern struct alloc_wait_para allocwait_para;
extern void ionwait_monitor(u64 wait_ms);


#endif 
