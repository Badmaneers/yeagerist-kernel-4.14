

#ifndef SI476X_H
#define SI476X_H

#include <linux/types.h>
#include <linux/videodev2.h>

#include <linux/mfd/si476x-reports.h>

enum si476x_ctrl_id {
	V4L2_CID_SI476X_RSSI_THRESHOLD	= (V4L2_CID_USER_SI476X_BASE + 1),
	V4L2_CID_SI476X_SNR_THRESHOLD	= (V4L2_CID_USER_SI476X_BASE + 2),
	V4L2_CID_SI476X_MAX_TUNE_ERROR	= (V4L2_CID_USER_SI476X_BASE + 3),
	V4L2_CID_SI476X_HARMONICS_COUNT	= (V4L2_CID_USER_SI476X_BASE + 4),
	V4L2_CID_SI476X_DIVERSITY_MODE	= (V4L2_CID_USER_SI476X_BASE + 5),
	V4L2_CID_SI476X_INTERCHIP_LINK	= (V4L2_CID_USER_SI476X_BASE + 6),
};

#endif 