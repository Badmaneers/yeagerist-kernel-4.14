// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2021 MediaTek Inc.
 */

#ifndef _KBASE_GATOR_HWCNT_NAMES_TNAX_H_
#define _KBASE_GATOR_HWCNT_NAMES_TNAX_H_

static const char * const hardware_counters_mali_tNAx[] = {
	/* Performance counters for the Job Manager */
	"",
	"",
	"",
	"",
	"TNAx_MESSAGES_SENT",
	"TNAx_MESSAGES_RECEIVED",
	"TNAx_GPU_ACTIVE",
	"TNAx_IRQ_ACTIVE",
	"TNAx_JS0_JOBS",
	"TNAx_JS0_TASKS",
	"TNAx_JS0_ACTIVE",
	"",
	"TNAx_JS0_WAIT_READ",
	"TNAx_JS0_WAIT_ISSUE",
	"TNAx_JS0_WAIT_DEPEND",
	"TNAx_JS0_WAIT_FINISH",
	"TNAx_JS1_JOBS",
	"TNAx_JS1_TASKS",
	"TNAx_JS1_ACTIVE",
	"",
	"TNAx_JS1_WAIT_READ",
	"TNAx_JS1_WAIT_ISSUE",
	"TNAx_JS1_WAIT_DEPEND",
	"TNAx_JS1_WAIT_FINISH",
	"TNAx_JS2_JOBS",
	"TNAx_JS2_TASKS",
	"TNAx_JS2_ACTIVE",
	"",
	"TNAx_JS2_WAIT_READ",
	"TNAx_JS2_WAIT_ISSUE",
	"TNAx_JS2_WAIT_DEPEND",
	"TNAx_JS2_WAIT_FINISH",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",

	/* Performance counters for the Tiler */
	"",
	"",
	"",
	"",
	"TNAx_TILER_ACTIVE",
	"TNAx_JOBS_PROCESSED",
	"TNAx_TRIANGLES",
	"TNAx_LINES",
	"TNAx_POINTS",
	"TNAx_FRONT_FACING",
	"TNAx_BACK_FACING",
	"TNAx_PRIM_VISIBLE",
	"TNAx_PRIM_CULLED",
	"TNAx_PRIM_CLIPPED",
	"TNAx_PRIM_SAT_CULLED",
	"TNAx_BIN_ALLOC_INIT",
	"TNAx_BIN_ALLOC_OVERFLOW",
	"TNAx_BUS_READ",
	"",
	"TNAx_BUS_WRITE",
	"TNAx_LOADING_DESC",
	"TNAx_IDVS_POS_SHAD_REQ",
	"TNAx_IDVS_POS_SHAD_WAIT",
	"TNAx_IDVS_POS_SHAD_STALL",
	"TNAx_IDVS_POS_FIFO_FULL",
	"TNAx_PREFETCH_STALL",
	"TNAx_VCACHE_HIT",
	"TNAx_VCACHE_MISS",
	"TNAx_VCACHE_LINE_WAIT",
	"TNAx_VFETCH_POS_READ_WAIT",
	"TNAx_VFETCH_VERTEX_WAIT",
	"TNAx_VFETCH_STALL",
	"TNAx_PRIMASSY_STALL",
	"TNAx_BBOX_GEN_STALL",
	"TNAx_IDVS_VBU_HIT",
	"TNAx_IDVS_VBU_MISS",
	"TNAx_IDVS_VBU_LINE_DEALLOCATE",
	"TNAx_IDVS_VAR_SHAD_REQ",
	"TNAx_IDVS_VAR_SHAD_STALL",
	"TNAx_BINNER_STALL",
	"TNAx_ITER_STALL",
	"TNAx_COMPRESS_MISS",
	"TNAx_COMPRESS_STALL",
	"TNAx_PCACHE_HIT",
	"TNAx_PCACHE_MISS",
	"TNAx_PCACHE_MISS_STALL",
	"TNAx_PCACHE_EVICT_STALL",
	"TNAx_PMGR_PTR_WR_STALL",
	"TNAx_PMGR_PTR_RD_STALL",
	"TNAx_PMGR_CMD_WR_STALL",
	"TNAx_WRBUF_ACTIVE",
	"TNAx_WRBUF_HIT",
	"TNAx_WRBUF_MISS",
	"TNAx_WRBUF_NO_FREE_LINE_STALL",
	"TNAx_WRBUF_NO_AXI_ID_STALL",
	"TNAx_WRBUF_AXI_STALL",
	"",
	"",
	"",
	"TNAx_UTLB_TRANS",
	"TNAx_UTLB_TRANS_HIT",
	"TNAx_UTLB_TRANS_STALL",
	"TNAx_UTLB_TRANS_MISS_DELAY",
	"TNAx_UTLB_MMU_REQ",

	/* Performance counters for the Shader Core */
	"",
	"",
	"",
	"",
	"TNAx_FRAG_ACTIVE",
	"TNAx_FRAG_PRIMITIVES_OUT",
	"TNAx_FRAG_PRIM_RAST",
	"TNAx_FRAG_FPK_ACTIVE",
	"TNAx_FRAG_STARVING",
	"TNAx_FRAG_WARPS",
	"TNAx_FRAG_PARTIAL_QUADS_RAST",
	"TNAx_FRAG_QUADS_RAST",
	"TNAx_FRAG_QUADS_EZS_TEST",
	"TNAx_FRAG_QUADS_EZS_UPDATE",
	"TNAx_FRAG_QUADS_EZS_KILL",
	"TNAx_FRAG_LZS_TEST",
	"TNAx_FRAG_LZS_KILL",
	"TNAx_WARP_REG_SIZE_64",
	"TNAx_FRAG_PTILES",
	"TNAx_FRAG_TRANS_ELIM",
	"TNAx_QUAD_FPK_KILLER",
	"TNAx_FULL_QUAD_WARPS",
	"TNAx_COMPUTE_ACTIVE",
	"TNAx_COMPUTE_TASKS",
	"TNAx_COMPUTE_WARPS",
	"TNAx_COMPUTE_STARVING",
	"TNAx_EXEC_CORE_ACTIVE",
	"TNAx_EXEC_INSTR_FMA",
	"TNAx_EXEC_INSTR_CVT",
	"TNAx_EXEC_INSTR_SFU",
	"TNAx_EXEC_INSTR_MSG",
	"TNAx_EXEC_INSTR_DIVERGED",
	"TNAx_EXEC_ICACHE_MISS",
	"TNAx_EXEC_STARVE_ARITH",
	"TNAx_CALL_BLEND_SHADER",
	"TNAx_TEX_MSGI_NUM_FLITS",
	"TNAx_TEX_DFCH_CLK_STALLED",
	"TNAx_TEX_TFCH_CLK_STALLED",
	"TNAx_TEX_TFCH_STARVED_PENDING_DATA_FETCH",
	"TNAx_TEX_FILT_NUM_OPERATIONS",
	"TNAx_TEX_FILT_NUM_FXR_OPERATIONS",
	"TNAx_TEX_FILT_NUM_FST_OPERATIONS",
	"TNAx_TEX_MSGO_NUM_MSG",
	"TNAx_TEX_MSGO_NUM_FLITS",
	"TNAx_LS_MEM_READ_FULL",
	"TNAx_LS_MEM_READ_SHORT",
	"TNAx_LS_MEM_WRITE_FULL",
	"TNAx_LS_MEM_WRITE_SHORT",
	"TNAx_LS_MEM_ATOMIC",
	"TNAx_VARY_INSTR",
	"TNAx_VARY_SLOT_32",
	"TNAx_VARY_SLOT_16",
	"TNAx_ATTR_INSTR",
	"TNAx_ARITH_INSTR_FP_MUL",
	"TNAx_BEATS_RD_FTC",
	"TNAx_BEATS_RD_FTC_EXT",
	"TNAx_BEATS_RD_LSC",
	"TNAx_BEATS_RD_LSC_EXT",
	"TNAx_BEATS_RD_TEX",
	"TNAx_BEATS_RD_TEX_EXT",
	"TNAx_BEATS_RD_OTHER",
	"TNAx_BEATS_WR_LSC_OTHER",
	"TNAx_BEATS_WR_TIB",
	"TNAx_BEATS_WR_LSC_WB",

	/* Performance counters for the Memory System */
	"",
	"",
	"",
	"",
	"TNAx_MMU_REQUESTS",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"TNAx_L2_RD_MSG_IN",
	"TNAx_L2_RD_MSG_IN_STALL",
	"TNAx_L2_WR_MSG_IN",
	"TNAx_L2_WR_MSG_IN_STALL",
	"TNAx_L2_SNP_MSG_IN",
	"TNAx_L2_SNP_MSG_IN_STALL",
	"TNAx_L2_RD_MSG_OUT",
	"TNAx_L2_RD_MSG_OUT_STALL",
	"TNAx_L2_WR_MSG_OUT",
	"TNAx_L2_ANY_LOOKUP",
	"TNAx_L2_READ_LOOKUP",
	"TNAx_L2_WRITE_LOOKUP",
	"TNAx_L2_EXT_SNOOP_LOOKUP",
	"TNAx_L2_EXT_READ",
	"TNAx_L2_EXT_READ_NOSNP",
	"TNAx_L2_EXT_READ_UNIQUE",
	"TNAx_L2_EXT_READ_BEATS",
	"TNAx_L2_EXT_AR_STALL",
	"TNAx_L2_EXT_AR_CNT_Q1",
	"TNAx_L2_EXT_AR_CNT_Q2",
	"TNAx_L2_EXT_AR_CNT_Q3",
	"TNAx_L2_EXT_RRESP_0_127",
	"TNAx_L2_EXT_RRESP_128_191",
	"TNAx_L2_EXT_RRESP_192_255",
	"TNAx_L2_EXT_RRESP_256_319",
	"TNAx_L2_EXT_RRESP_320_383",
	"TNAx_L2_EXT_WRITE",
	"TNAx_L2_EXT_WRITE_NOSNP_FULL",
	"TNAx_L2_EXT_WRITE_NOSNP_PTL",
	"TNAx_L2_EXT_WRITE_SNP_FULL",
	"TNAx_L2_EXT_WRITE_SNP_PTL",
	"TNAx_L2_EXT_WRITE_BEATS",
	"TNAx_L2_EXT_W_STALL",
	"TNAx_L2_EXT_AW_CNT_Q1",
	"TNAx_L2_EXT_AW_CNT_Q2",
	"TNAx_L2_EXT_AW_CNT_Q3",
	"TNAx_L2_EXT_SNOOP",
	"TNAx_L2_EXT_SNOOP_STALL",
	"TNAx_L2_EXT_SNOOP_RESP_CLEAN",
	"TNAx_L2_EXT_SNOOP_RESP_DATA",
	"TNAx_L2_EXT_SNOOP_INTERNAL",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
};

#endif /* _KBASE_GATOR_HWCNT_NAMES_TNAX_H_ */
