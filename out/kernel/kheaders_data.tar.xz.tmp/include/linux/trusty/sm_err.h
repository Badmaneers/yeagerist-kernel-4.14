
#ifndef __LINUX_TRUSTY_SM_ERR_H
#define __LINUX_TRUSTY_SM_ERR_H



#define SM_ERR_UNDEFINED_SMC		0xFFFFFFFF
#define SM_ERR_INVALID_PARAMETERS	-2

#define SM_ERR_INTERRUPTED		-3

#define SM_ERR_UNEXPECTED_RESTART	-4

#define SM_ERR_BUSY			-5

#define SM_ERR_INTERLEAVED_SMC		-6

#define SM_ERR_INTERNAL_FAILURE		-7
#define SM_ERR_NOT_SUPPORTED		-8

#define SM_ERR_NOT_ALLOWED		-9
#define SM_ERR_END_OF_INPUT		-10

#define SM_ERR_PANIC			-11

#define SM_ERR_FIQ_INTERRUPTED		-12

#define SM_ERR_CPU_IDLE			-13

#define SM_ERR_NOP_INTERRUPTED		-14

#define SM_ERR_NOP_DONE			-15

#endif