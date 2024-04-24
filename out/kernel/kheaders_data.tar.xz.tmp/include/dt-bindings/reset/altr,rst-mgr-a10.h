

#ifndef _DT_BINDINGS_RESET_ALTR_RST_MGR_A10_H
#define _DT_BINDINGS_RESET_ALTR_RST_MGR_A10_H


#define CPU0_RESET		0
#define CPU1_RESET		1
#define WDS_RESET		2
#define SCUPER_RESET		3


#define EMAC0_RESET		32
#define EMAC1_RESET		33
#define EMAC2_RESET		34
#define USB0_RESET		35
#define USB1_RESET		36
#define NAND_RESET		37
#define QSPI_RESET		38
#define SDMMC_RESET		39
#define EMAC0_OCP_RESET		40
#define EMAC1_OCP_RESET		41
#define EMAC2_OCP_RESET		42
#define USB0_OCP_RESET		43
#define USB1_OCP_RESET		44
#define NAND_OCP_RESET		45
#define QSPI_OCP_RESET		46
#define SDMMC_OCP_RESET		47
#define DMA_RESET		48
#define SPIM0_RESET		49
#define SPIM1_RESET		50
#define SPIS0_RESET		51
#define SPIS1_RESET		52
#define DMA_OCP_RESET		53
#define EMAC_PTP_RESET		54

#define DMAIF0_RESET		56
#define DMAIF1_RESET		57
#define DMAIF2_RESET		58
#define DMAIF3_RESET		59
#define DMAIF4_RESET		60
#define DMAIF5_RESET		61
#define DMAIF6_RESET		62
#define DMAIF7_RESET		63


#define L4WD0_RESET		64
#define L4WD1_RESET		65
#define L4SYSTIMER0_RESET	66
#define L4SYSTIMER1_RESET	67
#define SPTIMER0_RESET		68
#define SPTIMER1_RESET		69

#define I2C0_RESET		72
#define I2C1_RESET		73
#define I2C2_RESET		74
#define I2C3_RESET		75
#define I2C4_RESET		76

#define UART0_RESET		80
#define UART1_RESET		81

#define GPIO0_RESET		88
#define GPIO1_RESET		89
#define GPIO2_RESET		90


#define HPS2FPGA_RESET		96
#define LWHPS2FPGA_RESET	97
#define FPGA2HPS_RESET		98
#define F2SSDRAM0_RESET		99
#define F2SSDRAM1_RESET		100
#define F2SSDRAM2_RESET		101
#define DDRSCH_RESET		102


#define ROM_RESET		128
#define OCRAM_RESET		129

#define FPGAMGR_RESET		131
#define S2F_RESET		132
#define SYSDBG_RESET		133
#define OCRAM_OCP_RESET		134


#define CLKMGRCOLD_RESET	160

#define S2FCOLD_RESET		163
#define TIMESTAMPCOLD_RESET	164
#define TAPCOLD_RESET		165
#define HMCCOLD_RESET		166
#define IOMGRCOLD_RESET		167


#define NRSTPINOE_RESET		192


#define DBG_RESET		224
#endif