/*
 * Copyright (C) 2019 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

/* This file is generated by GenLP_setting.pl v1.5.7 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

const unsigned int AP_DCM_Golden_Setting_tcl_gs_dpidle_data[] = {
/*	Address		Mask		Golden Setting Value */
	0x0C53C8A0, 0x00000002, 0x00000002,/* MP0_DCM_CFG8 */
	0x0D01A070, 0x00000001, 0x00000001,/* ATB_CON */
	0x0D0A002C, 0x00000001, 0x00000001,/* DBGBUSCLK_EN */
	0x0D0A0030, 0x00000001, 0x00000001,/* DBGSYSCLK_EN */
	0x0D0A0070, 0x00000001, 0x00000001,/* ATB_CON */
	0x10000000, 0x00000F00, 0x00000000,/* CLK_MODE */
	0x10000010, 0x80808080, 0x00800000,/* CLK_CFG_0 */
	0x10000020, 0x80808080, 0x80808080,/* CLK_CFG_1 */
	0x10000030, 0x80808080, 0x80808080,/* CLK_CFG_2 */
	0x10000040, 0x80808080, 0x80808080,/* CLK_CFG_3 */
	0x10000050, 0x80808080, 0x80808080,/* CLK_CFG_4 */
	0x10000060, 0x80808080, 0x80808080,/* CLK_CFG_5 */
	0x10000070, 0x80808080, 0x80808080,/* CLK_CFG_6 */
	0x10000080, 0x80808080, 0x80808080,/* CLK_CFG_7 */
	0x10000090, 0x80808080, 0x00808000,/* CLK_CFG_8 */
	0x100000A0, 0x80808080, 0x80808080,/* CLK_CFG_9 */
	0x100000B0, 0x80808080, 0x80808080,/* CLK_CFG_10 */
	0x100000C0, 0x80808080, 0x80808080,/* CLK_CFG_11 */
	0x100000D0, 0x80808080, 0x80808080,/* CLK_CFG_12 */
	0x100000E0, 0x80008080, 0x80008080,/* CLK_CFG_13 */
	0x10000140, 0x00003030, 0x00003000,/* CLK_MISC_CFG_0 */
	0x10000320, 0x000007FF, 0x000007FF,/* CLK_AUDDIV_0 */
	0x10001070, 0x00000004, 0x00000000,/* INFRA_BUS_DCM_CTRL */
	0x10001074, 0x00000004, 0x00000000,/* PERI_BUS_DCM_CTRL */
	0x10001080, 0x9BEFFFFF, 0x9BEFFFF0,/* MODULE_SW_CG_0_SET */
	0x10001084, 0x9BEFFFFF, 0x00000000,/* MODULE_SW_CG_0_CLR */
	0x10001088, 0xFF9DFFD6, 0x7B1D8B56,/* MODULE_SW_CG_1_SET */
	0x1000108C, 0xFF9DFFD7, 0x00000000,/* MODULE_SW_CG_1_CLR */
	0x100010A4, 0xFFFFFEFF, 0xFFFFFEFF,/* MODULE_SW_CG_2_SET */
	0x100010A8, 0xFFFFFEFF, 0x00000000,/* MODULE_SW_CG_2_CLR */
	0x100010C0, 0xFFFFCFFF, 0xCFF0C9FF,/* MODULE_SW_CG_3_SET */
	0x100010C4, 0xFFFFCFFF, 0x00300000,/* MODULE_SW_CG_3_CLR */
	0x100010E0, 0xFFFF007F, 0xFEFF007F,/* MODULE_SW_CG_4_SET */
	0x100010E4, 0xFFFF007F, 0x01000000,/* MODULE_SW_CG_4_CLR */
	0x1000320C, 0x80000000, 0x00000000,/* PERIAXI_SI0_CTL */
	0x10006B00, 0x0100001E, 0x00000000,/* MD32PCM_CK_EN */
	0x10006B04, 0x0000001E, 0x00000000,/* MD32PCM_CKCTRL_FORCE_CK_ON */
	0x1000C000, 0x00000001, 0x00000001,/* AP_PLL_CON0 */
	0x1000C008, 0xE0000000, 0xE0000000,/* AP_PLL_CON2 */
	0x1000C00C, 0x0000001E, 0x00000000,/* AP_PLL_CON3 */
	0x1000C014, 0x00036BF8, 0x000020A0,/* AP_PLL_CON5 */
	0x1000C200, 0x00000FFF, 0x00000FE0,/* AP_PLLGP1_CON0 */
	0x1000C208, 0x00000001, 0x00000001,/* ARMPLL_LL_CON0 */
	0x1000C218, 0x00000001, 0x00000001,/* ARMPLL_BL0_CON0 */
	0x1000C228, 0x00000001, 0x00000001,/* ARMPLL_BL1_CON0 */
	0x1000C238, 0x00000001, 0x00000001,/* ARMPLL_BL2_CON0 */
	0x1000C248, 0x00000001, 0x00000001,/* ARMPLL_BL3_CON0 */
	0x1000C258, 0x00000001, 0x00000001,/* CCIPLL_CON0 */
	0x1000C268, 0x00000001, 0x00000000,/* MFGPLL_CON0 */
	0x1000C300, 0x060003FF, 0x060003FF,/* AP_PLLGP2_CON0 */
	0x1000C308, 0xFF000001, 0xFC000000,/* UNIVPLL_CON0 */
	0x1000C318, 0x00000001, 0x00000000,/* APLL1_CON0 */
	0x1000C32C, 0x00000001, 0x00000000,/* APLL2_CON0 */
	0x1000C340, 0x7F000001, 0x7C000001,/* MAINPLL_CON0 */
	0x1000C350, 0x00000001, 0x00000000,/* MSDCPLL_CON0 */
	0x1000C360, 0xFF000001, 0x00000000,/* MMPLL_CON0 */
	0x1000C370, 0xFF000001, 0x00000000,/* ADSPPLL_CON0 */
	0x1000C380, 0x00000001, 0x00000000,/* TVDPLL_CON0 */
	0x1000C390, 0x00000001, 0x00000001,/* MPLL_CON0 */
	0x1000C3A0, 0xFF000001, 0x00000000,/* APUPLL_CON0 */
	0x1000C3B4, 0xFF000001, 0x00000000,/* NPUPLL_CON0 */
	0x10012000, 0x00000001, 0x00000000,/* DVFSRC_BASIC_CONTROL */
	0x1020EB00, 0x00000007, 0x00000000,/* BUS_MON_CKEN */
	0x10219834, 0x00000003, 0x00000000,/* EMI_THRO_PRD0 */
	0x10219838, 0x00FF0000, 0x00000000,/* EMI_THRO_PRD1 */
	0x10219858, 0x00000800, 0x00000000,/* EMI_THRO_CTRL1 */
	0x1021C210, 0x0000000F, 0x00000000,/* BUS_MEM_MON_CKEN */
	0x102280F0, 0xFFFF0000, 0x00010000,/* GCE_CTL_INT0 */
	0x1022D468, 0x0000003F, 0x00000000,/* CG_EN */
	0x10443000, 0x001FEBFE, 0x00004000,/* SSPM_CK_EN */
	0x10443010, 0x00000001, 0x00000000,/* SSPM_UART_CTRL */
	//0x10720180, 0x00000001, 0x00000001,/* AUDIODSP_CK_CG */
	//0x10801000, 0x00000CFB, 0x00000000,/* ADSP_CK_EN */
	//0x10801010, 0x00000001, 0x00000000,/* ADSP_UART_CTRL */
	0x10943000, 0x00001000, 0x00000000,/* SSPM_CK_EN */
	//0x10943004, 0x00000100, 0x00000100,/* SSPM_MCLK_DIV */
	//0x10943010, 0x00000001, 0x00000000,/* SSPM_UART_CTRL */
	//0x11007E00, 0x0000000F, 0x0000000F,/* AP_CLOCK_CG_RO_CEN */
	0x1100B0E4, 0x00000001, 0x00000000,/* LVTSCLKEN_0 */
	0x1100B1E4, 0x00000001, 0x00000000,/* LVTSCLKEN_1 */
	0x1100B2E4, 0x00000001, 0x00000000,/* LVTSCLKEN_2 */
	0x1100B3E4, 0x00000001, 0x00000000,/* LVTSCLKEN_3 */
	0x1100BF00, 0x803F0000, 0x00000000,/* PTPCORESEL */
	0x11201C84, 0x00000004, 0x00000004,/* MISC_CTRL */
	0x11203E30, 0x00000001, 0x00000001,/* SSUSB_U3_CTRL_0P */
	0x11203E50, 0x00000001, 0x00000001,/* SSUSB_U2_CTRL_0P */
	0x11203E80, 0x00000001, 0x00000001,/* SSUSB_DMA_CTRL */
	//0x11210000, 0x1F1C0304, 0x1F1C0304,/* AUDIO_TOP_CON0 */
	//0x11210004, 0xF033F0F0, 0xF033F0F0,/* AUDIO_TOP_CON1 */
	//0x11210008, 0x0000001F, 0x0000001F,/* AUDIO_TOP_CON2 */
	0x112780E4, 0x00000001, 0x00000000,/* LVTSCLKEN_0 */
	0x112781E4, 0x00000001, 0x00000000,/* LVTSCLKEN_1 */
	0x112782E4, 0x00000001, 0x00000000,/* LVTSCLKEN_2 */
	0x11278F00, 0x803F0000, 0x00000000,/* PTPCORESEL */
	0x11CB1E00, 0x00000001, 0x00000001,/* AP_CLOCK_CG_RO_EST */
	0x11D03E00, 0x0000000F, 0x0000000F,/* AP_CLOCK_CG_RO_SOU */
	0x11D23E00, 0x00000007, 0x00000007,/* AP_CLOCK_CG_RO_WEST_SOU */
	0x11E01E00, 0x00000001, 0x00000001,/* AP_CLOCK_CG_RO_WST */
	0x11F02E00, 0x00000001, 0x00000001,/* AP_CLOCK_CG_RO_NOR */
	0x11F10000, 0x00007FFF, 0x00003080,/* MSDC_CTL_CKEN */
	//0x11F600B4, 0x00400000, 0x00000000,/* PATCH_BIT1 */
	//0x13FBF004, 0x00000001, 0x00000001,/* MFG_CG_SET */
	0x13FBF008, 0x00000001, 0x00000000,/* MFG_CG_CLR */
	0x14000100, 0xFFFFFFFF, 0xFFFFFFFF,/* MMSYS_CG_CON0 */
	0x14000110, 0xFFFFFFFF, 0xFFFFFFFF,/* MMSYS_CG_CON1 */
	0x140001A0, 0xFFFFFFFF, 0xFFFFFFFF,/* MMSYS_CG_CON2 */
	//0x15020000, 0x00001007, 0x00001007,/* IMG_CG_CON */
	//0x15820000, 0x000011C3, 0x000011C3,/* IMG_CG_CON */
	//0x1600F000, 0x00000001, 0x00000000,/* VDEC_CKEN_SET */
	//0x1600F004, 0x00000001, 0x00000001,/* VDEC_CKEN_CLR */
	//0x1600F008, 0x00000001, 0x00000000,/* LARB_CKEN_CON_SET */
	//0x1600F00C, 0x00000001, 0x00000001,/* LARB_CKEN_CON_CLR */
	//0x1600F200, 0x00000001, 0x00000000,/* LAT_CKEN_SET */
	//0x1600F204, 0x00000001, 0x00000001,/* LAT_CKEN_CLR */
	//0x1602F000, 0x00000001, 0x00000000,/* VDEC_CKEN_SET */
	//0x1602F004, 0x00000001, 0x00000001,/* VDEC_CKEN_CLR */
	//0x1602F008, 0x00000001, 0x00000000,/* LARB_CKEN_CON_SET */
	//0x1602F00C, 0x00000001, 0x00000001,/* LARB_CKEN_CON_CLR */
	//0x17000000, 0x10000111, 0x00000000,/* VENCSYS_CG_CON */
	//0x17000004, 0x10000111, 0x00000000,/* VENCSYS_CG_SET */
	//0x17000008, 0x10000111, 0x10000111,/* VENCSYS_CG_CLR */
	0x19020000, 0x0003FFFF, 0x0003FFFF,/* APU_CONN_CG_CON */
	0x19029000, 0x0000000F, 0x0000000F,/* APUSYS_VCORE_CG_CON */
	0x19030100, 0x00000007, 0x00000007,/* CORE_CG_CON */
	0x19030910, 0x02000000, 0x02000000,/* CORE_CTRL */
	0x19031100, 0x00000007, 0x00000007,/* CORE_CG_CON */
	0x19031910, 0x02000000, 0x02000000,/* CORE_CTRL */
	0x19034000, 0x00007FFF, 0x00007FFF,/* MDLA_CG_CON */
	//0x1A000000, 0x000FFFCF, 0x000FFFCF,/* CAMSYS_CG_CON */
	//0x1A04F000, 0x00000007, 0x00000007,/* CAMSYS_CG_CON */
	//0x1A06F000, 0x00000007, 0x00000007,/* CAMSYS_CG_CON */
	//0x1A08F000, 0x00000007, 0x00000007,/* CAMSYS_CG_CON */
	//0x1B000000, 0x0000017F, 0x0000017F,/* IMG_CG_CON */
	//0x1F000100, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON0 */
	//0x1F000110, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON1 */
	//0x1F000120, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON2 */
	//0x1F000130, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON3 */
	//0x1F000140, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON4 */
	0xA00C00E4, 0x00000001, 0x00000000,/* LVTSCLKEN_0 */
	0xA00C0F00, 0x803F0000, 0x00000000 /* PTPCORESEL */
};

const unsigned int *AP_DCM_Golden_Setting_tcl_gs_dpidle =
		AP_DCM_Golden_Setting_tcl_gs_dpidle_data;

unsigned int AP_DCM_Golden_Setting_tcl_gs_dpidle_len = 312;

const unsigned int AP_DCM_Golden_Setting_tcl_gs_suspend_data[] = {
/*	Address		Mask		Golden Setting Value */
	0x0C53C8A0, 0x00000002, 0x00000002,/* MP0_DCM_CFG8 */
	0x0D01A070, 0x00000001, 0x00000001,/* ATB_CON */
	0x0D0A002C, 0x00000001, 0x00000000,/* DBGBUSCLK_EN */
	0x0D0A0030, 0x00000001, 0x00000000,/* DBGSYSCLK_EN */
	0x0D0A0070, 0x00000001, 0x00000000,/* ATB_CON */
	0x10000000, 0x00000F00, 0x00000000,/* CLK_MODE */
	0x10000010, 0x80808080, 0x00800000,/* CLK_CFG_0 */
	0x10000020, 0x80808080, 0x80808080,/* CLK_CFG_1 */
	0x10000030, 0x80808080, 0x80808080,/* CLK_CFG_2 */
	0x10000040, 0x80808080, 0x80808080,/* CLK_CFG_3 */
	0x10000050, 0x80808080, 0x80808080,/* CLK_CFG_4 */
	0x10000060, 0x80808080, 0x80808080,/* CLK_CFG_5 */
	0x10000070, 0x80808080, 0x80808080,/* CLK_CFG_6 */
	0x10000080, 0x80808080, 0x80808080,/* CLK_CFG_7 */
	0x10000090, 0x80808080, 0x00808080,/* CLK_CFG_8 */
	0x100000A0, 0x80808080, 0x80808080,/* CLK_CFG_9 */
	0x100000B0, 0x80808080, 0x80808080,/* CLK_CFG_10 */
	0x100000C0, 0x80808080, 0x80808080,/* CLK_CFG_11 */
	0x100000D0, 0x80808080, 0x80808080,/* CLK_CFG_12 */
	0x100000E0, 0x80008080, 0x80008080,/* CLK_CFG_13 */
	0x10000140, 0x00003030, 0x00003000,/* CLK_MISC_CFG_0 */
	0x10000320, 0x000007FF, 0x000007FF,/* CLK_AUDDIV_0 */
	0x10001070, 0x00000004, 0x00000000,/* INFRA_BUS_DCM_CTRL */
	0x10001074, 0x00000004, 0x00000000,/* PERI_BUS_DCM_CTRL */
	0x10001080, 0x9BEFFFFF, 0x9BEFFFF0,/* MODULE_SW_CG_0_SET */
	0x10001084, 0x9BEFFFFF, 0x00000000,/* MODULE_SW_CG_0_CLR */
	0x10001088, 0xFF9DFFD6, 0x7B1D8B56,/* MODULE_SW_CG_1_SET */
	0x1000108C, 0xFF9DFFD7, 0x00000000,/* MODULE_SW_CG_1_CLR */
	0x100010A4, 0xFFFFFEFF, 0xFFFFFEFF,/* MODULE_SW_CG_2_SET */
	0x100010A8, 0xFFFFFEFF, 0x00000000,/* MODULE_SW_CG_2_CLR */
	0x100010C0, 0xFFFFCFFF, 0xCFF0C9FF,/* MODULE_SW_CG_3_SET */
	0x100010C4, 0xFFFFCFFF, 0x00300000,/* MODULE_SW_CG_3_CLR */
	0x100010E0, 0xFFFF007F, 0xFEFF007F,/* MODULE_SW_CG_4_SET */
	0x100010E4, 0xFFFF007F, 0x01000000,/* MODULE_SW_CG_4_CLR */
	0x1000320C, 0x80000000, 0x00000000,/* PERIAXI_SI0_CTL */
	0x10006B00, 0x0100001E, 0x00000000,/* MD32PCM_CK_EN */
	0x10006B04, 0x0000001E, 0x00000000,/* MD32PCM_CKCTRL_FORCE_CK_ON */
	0x1000C000, 0x00000001, 0x00000001,/* AP_PLL_CON0 */
	0x1000C008, 0xE0000000, 0xE0000000,/* AP_PLL_CON2 */
	0x1000C00C, 0x0000001E, 0x00000000,/* AP_PLL_CON3 */
	0x1000C014, 0x00036BF8, 0x000020A0,/* AP_PLL_CON5 */
	0x1000C200, 0x00000FFF, 0x00000FE0,/* AP_PLLGP1_CON0 */
	0x1000C208, 0x00000001, 0x00000001,/* ARMPLL_LL_CON0 */
	0x1000C218, 0x00000001, 0x00000001,/* ARMPLL_BL0_CON0 */
	0x1000C228, 0x00000001, 0x00000001,/* ARMPLL_BL1_CON0 */
	0x1000C238, 0x00000001, 0x00000001,/* ARMPLL_BL2_CON0 */
	0x1000C248, 0x00000001, 0x00000001,/* ARMPLL_BL3_CON0 */
	0x1000C258, 0x00000001, 0x00000001,/* CCIPLL_CON0 */
	0x1000C268, 0x00000001, 0x00000000,/* MFGPLL_CON0 */
	0x1000C300, 0x060003FF, 0x060003FF,/* AP_PLLGP2_CON0 */
	0x1000C308, 0xFF000001, 0xFC000000,/* UNIVPLL_CON0 */
	0x1000C318, 0x00000001, 0x00000000,/* APLL1_CON0 */
	0x1000C32C, 0x00000001, 0x00000000,/* APLL2_CON0 */
	0x1000C340, 0x7F000001, 0x7C000001,/* MAINPLL_CON0 */
	0x1000C350, 0x00000001, 0x00000000,/* MSDCPLL_CON0 */
	0x1000C360, 0xFF000001, 0x00000000,/* MMPLL_CON0 */
	0x1000C370, 0xFF000001, 0x00000000,/* ADSPPLL_CON0 */
	0x1000C380, 0x00000001, 0x00000000,/* TVDPLL_CON0 */
	0x1000C390, 0x00000001, 0x00000001,/* MPLL_CON0 */
	0x1000C3A0, 0xFF000001, 0x00000000,/* APUPLL_CON0 */
	0x1000C3B4, 0xFF000001, 0x00000000,/* NPUPLL_CON0 */
	0x10012000, 0x00000001, 0x00000000,/* DVFSRC_BASIC_CONTROL */
	0x1020EB00, 0x00000007, 0x00000000,/* BUS_MON_CKEN */
	0x10219834, 0x00000003, 0x00000000,/* EMI_THRO_PRD0 */
	0x10219838, 0x00FF0000, 0x00000000,/* EMI_THRO_PRD1 */
	0x10219858, 0x00000800, 0x00000000,/* EMI_THRO_CTRL1 */
	0x1021C210, 0x0000000F, 0x00000000,/* BUS_MEM_MON_CKEN */
	0x102280F0, 0xFFFF0000, 0x00010000,/* GCE_CTL_INT0 */
	0x1022D468, 0x0000003F, 0x00000000,/* CG_EN */
	0x10443000, 0x001FEBFE, 0x00004000,/* SSPM_CK_EN */
	0x10443010, 0x00000001, 0x00000000,/* SSPM_UART_CTRL */
	//0x10720180, 0x00000001, 0x00000001,/* AUDIODSP_CK_CG */
	//0x10801000, 0x00000CFB, 0x00000000,/* ADSP_CK_EN */
	//0x10801010, 0x00000001, 0x00000000,/* ADSP_UART_CTRL */
	0x10943000, 0x00001000, 0x00000000,/* SSPM_CK_EN */
	//0x10943004, 0x00000100, 0x00000100,/* SSPM_MCLK_DIV */
	//0x10943010, 0x00000001, 0x00000000,/* SSPM_UART_CTRL */
	//0x11007E00, 0x0000000F, 0x0000000F,/* AP_CLOCK_CG_RO_CEN */
	0x1100B0E4, 0x00000001, 0x00000000,/* LVTSCLKEN_0 */
	0x1100B1E4, 0x00000001, 0x00000000,/* LVTSCLKEN_1 */
	0x1100B2E4, 0x00000001, 0x00000000,/* LVTSCLKEN_2 */
	0x1100B3E4, 0x00000001, 0x00000000,/* LVTSCLKEN_3 */
	0x1100BF00, 0x803F0000, 0x00000000,/* PTPCORESEL */
	0x11201C84, 0x00000004, 0x00000004,/* MISC_CTRL */
	0x11203E30, 0x00000001, 0x00000001,/* SSUSB_U3_CTRL_0P */
	0x11203E50, 0x00000001, 0x00000001,/* SSUSB_U2_CTRL_0P */
	0x11203E80, 0x00000001, 0x00000001,/* SSUSB_DMA_CTRL */
	//0x11210000, 0x1F1C0304, 0x1F1C0304,/* AUDIO_TOP_CON0 */
	//0x11210004, 0xF033F0F0, 0xF033F0F0,/* AUDIO_TOP_CON1 */
	//0x11210008, 0x0000001F, 0x0000001F,/* AUDIO_TOP_CON2 */
	0x112780E4, 0x00000001, 0x00000000,/* LVTSCLKEN_0 */
	0x112781E4, 0x00000001, 0x00000000,/* LVTSCLKEN_1 */
	0x112782E4, 0x00000001, 0x00000000,/* LVTSCLKEN_2 */
	0x11278F00, 0x803F0000, 0x00000000,/* PTPCORESEL */
	0x11CB1E00, 0x00000001, 0x00000001,/* AP_CLOCK_CG_RO_EST */
	0x11D03E00, 0x0000000F, 0x0000000F,/* AP_CLOCK_CG_RO_SOU */
	0x11D23E00, 0x00000007, 0x00000007,/* AP_CLOCK_CG_RO_WEST_SOU */
	0x11E01E00, 0x00000001, 0x00000001,/* AP_CLOCK_CG_RO_WST */
	0x11F02E00, 0x00000001, 0x00000001,/* AP_CLOCK_CG_RO_NOR */
	0x11F10000, 0x00007FFF, 0x00003080,/* MSDC_CTL_CKEN */
	0x11F600B4, 0x00400000, 0x00000000,/* PATCH_BIT1 */
	//0x13FBF004, 0x00000001, 0x00000001,/* MFG_CG_SET */
	//0x13FBF008, 0x00000001, 0x00000000,/* MFG_CG_CLR */
	0x14000100, 0xFFFFFFFF, 0xFFFFFFFF,/* MMSYS_CG_CON0 */
	0x14000110, 0xFFFFFFFF, 0xFFFFFFFF,/* MMSYS_CG_CON1 */
	0x140001A0, 0xFFFFFFFF, 0xFFFFFFFF,/* MMSYS_CG_CON2 */
	//0x15020000, 0x00001007, 0x00001007,/* IMG_CG_CON */
	//0x15811058, 0x0003FFFF, 0x00000000,/* CTL_WPE_DCM_DIS */
	//0x1581105C, 0x0000001F, 0x00000000,/* CTL_DMA_DCM_DIS */
	//0x15820000, 0x000011C3, 0x000011C3,/* IMG_CG_CON */
	//0x1600F000, 0x00000001, 0x00000000,/* VDEC_CKEN_SET */
	//0x1600F004, 0x00000001, 0x00000001,/* VDEC_CKEN_CLR */
	//0x1600F008, 0x00000001, 0x00000000,/* LARB_CKEN_CON_SET */
	//0x1600F00C, 0x00000001, 0x00000001,/* LARB_CKEN_CON_CLR */
	//0x1600F200, 0x00000001, 0x00000000,/* LAT_CKEN_SET */
	//0x1600F204, 0x00000001, 0x00000001,/* LAT_CKEN_CLR */
	//0x1602F000, 0x00000001, 0x00000000,/* VDEC_CKEN_SET */
	//0x1602F004, 0x00000001, 0x00000001,/* VDEC_CKEN_CLR */
	//0x1602F008, 0x00000001, 0x00000000,/* LARB_CKEN_CON_SET */
	//0x1602F00C, 0x00000001, 0x00000001,/* LARB_CKEN_CON_CLR */
	//0x17000000, 0x10000111, 0x00000000,/* VENCSYS_CG_CON */
	//0x17000004, 0x10000111, 0x00000000,/* VENCSYS_CG_SET */
	//0x17000008, 0x10000111, 0x10000111,/* VENCSYS_CG_CLR */
	0x19020000, 0x0003FFFF, 0x0003FFFF,/* APU_CONN_CG_CON */
	0x19029000, 0x0000000F, 0x0000000F,/* APUSYS_VCORE_CG_CON */
	0x19030100, 0x00000007, 0x00000007,/* CORE_CG_CON */
	0x19030910, 0x02000000, 0x02000000,/* CORE_CTRL */
	0x19031100, 0x00000007, 0x00000007,/* CORE_CG_CON */
	0x19031910, 0x02000000, 0x02000000,/* CORE_CTRL */
	0x19034000, 0x00007FFF, 0x00007FFF,/* MDLA_CG_CON */
	//0x1A000000, 0x000FFFCF, 0x000FFFCF,/* CAMSYS_CG_CON */
	//0x1A04F000, 0x00000007, 0x00000007,/* CAMSYS_CG_CON */
	//0x1A06F000, 0x00000007, 0x00000007,/* CAMSYS_CG_CON */
	//0x1A08F000, 0x00000007, 0x00000007,/* CAMSYS_CG_CON */
	//0x1B000000, 0x0000017F, 0x0000017F,/* IMG_CG_CON */
	//0x1F000100, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON0 */
	//0x1F000110, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON1 */
	//0x1F000120, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON2 */
	//0x1F000130, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON3 */
	//0x1F000140, 0xFFFFFFFF, 0xFFFFFFFF,/* MDPSYS_CG_CON4 */
	0xA00C00E4, 0x00000001, 0x00000000,/* LVTSCLKEN_0 */
	0xA00C0F00, 0x803F0000, 0x00000000 /* PTPCORESEL */
};

const unsigned int *AP_DCM_Golden_Setting_tcl_gs_suspend =
		AP_DCM_Golden_Setting_tcl_gs_suspend_data;

unsigned int AP_DCM_Golden_Setting_tcl_gs_suspend_len = 309;

const unsigned int AP_DCM_Golden_Setting_tcl_gs_sodi_data[] = {
/*	Address		Mask		Golden Setting Value */
	0x0D01A070, 0x00000001, 0x00000001,/* ATB_CON */
	0x0D0A002C, 0x00000001, 0x00000001,/* DBGBUSCLK_EN */
	0x0D0A0030, 0x00000001, 0x00000001,/* DBGSYSCLK_EN */
	0x0D0A0070, 0x00000001, 0x00000001,/* ATB_CON */
	0x10012000, 0x00000001, 0x00000001,/* DVFSRC_BASIC_CONTROL */
	0x10219834, 0x00000003, 0x00000003,/* EMI_THRO_PRD0 */
	0x10219838, 0x00FF0000, 0x004D0000,/* EMI_THRO_PRD1 */
	0x10219858, 0x00000800, 0x00000800,/* EMI_THRO_CTRL1 */
	0x1022D468, 0x0000003F, 0x00000000,/* CG_EN */
	//0x10720180, 0x00000001, 0x00000001,/* AUDIODSP_CK_CG */
	0x11F600B4, 0x00400000, 0x00400000,/* PATCH_BIT1 */
	0x14000100, 0xFFFFFFFF, 0x00000000,/* MMSYS_CG_CON0 */
	0x14000110, 0xFFFFFFFF, 0x00000000,/* MMSYS_CG_CON1 */
	0x140001A0, 0xFFFFFFFF, 0x00000000,/* MMSYS_CG_CON2 */
	//0x15020000, 0x00001007, 0x00001007,/* IMG_CG_CON */
	0x15820000, 0x000011C3, 0x000011C3,/* IMG_CG_CON */
	0x1600F000, 0x00000001, 0x00000001,/* VDEC_CKEN_SET */
	0x1600F004, 0x00000001, 0x00000000,/* VDEC_CKEN_CLR */
	0x1600F008, 0x00000001, 0x00000001,/* LARB_CKEN_CON_SET */
	0x1600F00C, 0x00000001, 0x00000000,/* LARB_CKEN_CON_CLR */
	0x1600F200, 0x00000001, 0x00000001,/* LAT_CKEN_SET */
	0x1600F204, 0x00000001, 0x00000000,/* LAT_CKEN_CLR */
	0x1602F000, 0x00000001, 0x00000001,/* VDEC_CKEN_SET */
	0x1602F004, 0x00000001, 0x00000000,/* VDEC_CKEN_CLR */
	0x1602F008, 0x00000001, 0x00000001,/* LARB_CKEN_CON_SET */
	0x1602F00C, 0x00000001, 0x00000000,/* LARB_CKEN_CON_CLR */
	0x17000000, 0x10000111, 0x00000000,/* VENCSYS_CG_CON */
	0x17000004, 0x10000111, 0x00000000,/* VENCSYS_CG_SET */
	0x17000008, 0x10000111, 0x10000111,/* VENCSYS_CG_CLR */
	0x19020000, 0x0003FFFF, 0x0003FFFF,/* APU_CONN_CG_CON */
	0x19029000, 0x0000000F, 0x0000000F,/* APUSYS_VCORE_CG_CON */
	0x19030100, 0x00000007, 0x00000007,/* CORE_CG_CON */
	0x19031100, 0x00000007, 0x00000007,/* CORE_CG_CON */
	0x19034000, 0x00007FFF, 0x00007FFF,/* MDLA_CG_CON */
	0x1A000000, 0x000FFFCF, 0x000FFFCF,/* CAMSYS_CG_CON */
	0x1A04F000, 0x00000007, 0x00000007,/* CAMSYS_CG_CON */
	0x1A06F000, 0x00000007, 0x00000007,/* CAMSYS_CG_CON */
	0x1A08F000, 0x00000007, 0x00000007,/* CAMSYS_CG_CON */
	0x1B000000, 0x0000017F, 0x0000017F,/* IMG_CG_CON */
	0x1F000100, 0xFFFFFFFF, 0x00000000,/* MDPSYS_CG_CON0 */
	0x1F000110, 0xFFFFFFFF, 0x00000000,/* MDPSYS_CG_CON1 */
	0x1F000120, 0xFFFFFFFF, 0x00000000,/* MDPSYS_CG_CON2 */
	0x1F000130, 0xFFFFFFFF, 0x00000000,/* MDPSYS_CG_CON3 */
	0x1F000140, 0xFFFFFFFF, 0x00000000,/* MDPSYS_CG_CON4 */
};

const unsigned int *AP_DCM_Golden_Setting_tcl_gs_sodi =
		AP_DCM_Golden_Setting_tcl_gs_sodi_data;

unsigned int AP_DCM_Golden_Setting_tcl_gs_sodi_len = 126;
