

#ifndef _LINUX_MFD_SYSCON_PMU_EXYNOS4_H_
#define _LINUX_MFD_SYSCON_PMU_EXYNOS4_H_




#define EXYNOS4_MIPI_PHY_CONTROL(n)	(0x710 + (n) * 4)
#define EXYNOS4_MIPI_PHY_ENABLE		(1 << 0)
#define EXYNOS4_MIPI_PHY_SRESETN	(1 << 1)
#define EXYNOS4_MIPI_PHY_MRESETN	(1 << 2)
#define EXYNOS4_MIPI_PHY_RESET_MASK	(3 << 1)

#endif 