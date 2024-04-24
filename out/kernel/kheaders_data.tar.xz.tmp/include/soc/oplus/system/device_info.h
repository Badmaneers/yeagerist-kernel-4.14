/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _DEVICE_INFO_H
#define _DEVICE_INFO_H

#ifdef CONFIG_OPLUS_FEATURE_DUMP_DEVICE_INFO
void save_dump_reason_to_device_info(char *buf);
#else
inline void save_dump_reason_to_device_info(char *reason) {}
#endif

#endif 
