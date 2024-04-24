/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __QCOM_PMICWD_H__
#define __QCOM_PMICWD_H__

#include <linux/regmap.h>
#include <linux/input/qpnp-power-on.h>

static inline int qpnp_pon_masked_write(struct qpnp_pon *pon, u16 addr, u8 mask,
					u8 val)
{
	int rc;

	rc = regmap_update_bits(pon->regmap, addr, mask, val);

	if (rc)
		dev_err(pon->dev, "Register write failed, addr=0x%04X, rc=%d\n",
			addr, rc);

	return rc;
}

#endif 
