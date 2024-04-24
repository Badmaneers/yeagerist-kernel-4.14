/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __HUNG_TASK_ENHANCE_H
#define __HUNG_TASK_ENHANCE_H
#include <linux/sched/clock.h>
#include <linux/signal.h>
#include <linux/sched.h>
#include <soc/oplus/system/oplus_project.h>


#if IS_ENABLED(CONFIG_OPLUS_FEATURE_DEATH_HEALER)

extern char sysctl_hung_task_kill[];

extern int sysctl_hung_task_maxiowait_count;
static int five = 5;
#endif

#if IS_ENABLED(CONFIG_OPLUS_FEATURE_HUNG_TASK_ENHANCE)
void io_check_hung_detection(struct task_struct *t, unsigned long timeout,
			     unsigned int *iowait_count, bool *show_lock, bool *call_panic);
void io_block_panic(unsigned int *iowait_count,
		    unsigned int sys_mamxiowait_count);
#else
void io_check_hung_detection(struct task_struct *t, unsigned long timeout,
			     unsigned int *iowait_count, bool *show_lock, bool *call_panic) {}
static void io_block_panic(unsigned int *iowait_count,
			   unsigned int sys_mamxiowait_count) {}
#endif

#endif
