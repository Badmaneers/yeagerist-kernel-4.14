
#ifndef __ASM_SYSTEM_MISC_H
#define __ASM_SYSTEM_MISC_H

#ifndef __ASSEMBLY__

#include <linux/compiler.h>
#include <linux/linkage.h>
#include <linux/irqflags.h>
#include <linux/signal.h>
#include <linux/ratelimit.h>
#include <linux/reboot.h>

struct pt_regs;

void die(const char *msg, struct pt_regs *regs, int err);

struct siginfo;
void arm64_notify_die(const char *str, struct pt_regs *regs,
		      struct siginfo *info, int err);

void hook_debug_fault_code(int nr, int (*fn)(unsigned long, unsigned int,
					     struct pt_regs *),
			   int sig, int code, const char *name);

#ifdef CONFIG_MEDIATEK_SOLUTION
void hook_fault_code(int nr, int (*fn)(unsigned long, unsigned int,
			struct pt_regs *),
		int sig, int code, const char *name);
#endif

struct mm_struct;
extern void show_pte(unsigned long addr);
extern void __show_regs(struct pt_regs *);

extern void (*arm_pm_restart)(enum reboot_mode reboot_mode, const char *cmd);

#define show_unhandled_signals_ratelimited()				\
({									\
	static DEFINE_RATELIMIT_STATE(_rs,				\
				      DEFAULT_RATELIMIT_INTERVAL,	\
				      DEFAULT_RATELIMIT_BURST);		\
	bool __show_ratelimited = false;				\
	if (show_unhandled_signals && __ratelimit(&_rs))		\
		__show_ratelimited = true;				\
	__show_ratelimited;						\
})

int handle_guest_sea(phys_addr_t addr, unsigned int esr);

#endif	

#endif	
