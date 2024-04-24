/* SPDX-License-Identifier: GPL-2.0+ WITH Linux-syscall-note */


#ifndef _LINUX_KEYCTL_H
#define _LINUX_KEYCTL_H

#include <linux/types.h>


#define KEY_SPEC_THREAD_KEYRING		-1	
#define KEY_SPEC_PROCESS_KEYRING	-2	
#define KEY_SPEC_SESSION_KEYRING	-3	
#define KEY_SPEC_USER_KEYRING		-4	
#define KEY_SPEC_USER_SESSION_KEYRING	-5	
#define KEY_SPEC_GROUP_KEYRING		-6	
#define KEY_SPEC_REQKEY_AUTH_KEY	-7	
#define KEY_SPEC_REQUESTOR_KEYRING	-8	


#define KEY_REQKEY_DEFL_NO_CHANGE		-1
#define KEY_REQKEY_DEFL_DEFAULT			0
#define KEY_REQKEY_DEFL_THREAD_KEYRING		1
#define KEY_REQKEY_DEFL_PROCESS_KEYRING		2
#define KEY_REQKEY_DEFL_SESSION_KEYRING		3
#define KEY_REQKEY_DEFL_USER_KEYRING		4
#define KEY_REQKEY_DEFL_USER_SESSION_KEYRING	5
#define KEY_REQKEY_DEFL_GROUP_KEYRING		6
#define KEY_REQKEY_DEFL_REQUESTOR_KEYRING	7


#define KEYCTL_GET_KEYRING_ID		0	
#define KEYCTL_JOIN_SESSION_KEYRING	1	
#define KEYCTL_UPDATE			2	
#define KEYCTL_REVOKE			3	
#define KEYCTL_CHOWN			4	
#define KEYCTL_SETPERM			5	
#define KEYCTL_DESCRIBE			6	
#define KEYCTL_CLEAR			7	
#define KEYCTL_LINK			8	
#define KEYCTL_UNLINK			9	
#define KEYCTL_SEARCH			10	
#define KEYCTL_READ			11	
#define KEYCTL_INSTANTIATE		12	
#define KEYCTL_NEGATE			13	
#define KEYCTL_SET_REQKEY_KEYRING	14	
#define KEYCTL_SET_TIMEOUT		15	
#define KEYCTL_ASSUME_AUTHORITY		16	
#define KEYCTL_GET_SECURITY		17	
#define KEYCTL_SESSION_TO_PARENT	18	
#define KEYCTL_REJECT			19	
#define KEYCTL_INSTANTIATE_IOV		20	
#define KEYCTL_INVALIDATE		21	
#define KEYCTL_GET_PERSISTENT		22	
#define KEYCTL_DH_COMPUTE		23	
#define KEYCTL_RESTRICT_KEYRING		29	


struct keyctl_dh_params {
	union {
#ifndef __cplusplus
		__s32 private;
#endif
		__s32 priv;
	};
	__s32 prime;
	__s32 base;
};

struct keyctl_kdf_params {
	char __user *hashname;
	char __user *otherinfo;
	__u32 otherinfolen;
	__u32 __spare[8];
};

#endif 