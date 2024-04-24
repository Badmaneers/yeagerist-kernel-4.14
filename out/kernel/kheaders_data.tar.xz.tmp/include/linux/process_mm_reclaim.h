/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __PROCESS_MM_RECLAIM_H__
#define __PROCESS_MM_RECLAIM_H__

#include <linux/types.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/proc_fs.h>
#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5,4,0)
#include <linux/pagewalk.h>
#endif
#define PR_PASS		0
#define PR_SEM_OUT	1
#define PR_TASK_FG	2
#define PR_TIME_OUT	3
#define PR_ADDR_OVER	4
#define PR_FULL		5
#define PR_TASK_RUN	6
#define PR_TASK_DIE	7

#define RECLAIM_TIMEOUT_JIFFIES (HZ/3)
#define RECLAIM_PAGE_NUM 1024ul

#ifndef CONFIG_OPLUS_SYSTEM_KERNEL_QCOM

struct reclaim_param {
	struct vm_area_struct *vma;
	
	int nr_scanned;
	
	int nr_to_reclaim;
	
	int nr_reclaimed;
	
	bool inactive_lru;
	
	struct task_struct *reclaimed_task;
};
#endif

extern int is_reclaim_should_cancel(struct mm_walk *walk);
extern int is_reclaim_addr_over(struct mm_walk *walk, unsigned long addr);
extern int __weak  create_process_reclaim_enable_proc(struct proc_dir_entry *parent);
#endif 
