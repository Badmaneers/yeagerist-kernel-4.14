/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __LOWMEM_DBG_H
#define __LOWMEM_DBG_H
#include <linux/kernel.h>
#include <linux/proc_fs.h>

void oplus_lowmem_dbg(bool critical);

#ifndef CONFIG_MTK_ION
inline int oplus_is_dma_buf_file(struct file *file);
#endif 
#ifdef CONFIG_KSWAPD_DEBUG_STATISTICS
int kswapd_debug_init(struct proc_dir_entry *parent);
#endif

#endif 
