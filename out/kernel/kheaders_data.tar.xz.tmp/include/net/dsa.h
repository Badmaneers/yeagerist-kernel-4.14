

#ifndef __LINUX_NET_DSA_H
#define __LINUX_NET_DSA_H

#include <linux/if.h>
#include <linux/if_ether.h>
#include <linux/list.h>
#include <linux/notifier.h>
#include <linux/timer.h>
#include <linux/workqueue.h>
#include <linux/of.h>
#include <linux/ethtool.h>
#include <net/devlink.h>
#include <net/switchdev.h>

struct tc_action;
struct phy_device;
struct fixed_phy_status;

enum dsa_tag_protocol {
	DSA_TAG_PROTO_NONE = 0,
	DSA_TAG_PROTO_BRCM,
	DSA_TAG_PROTO_DSA,
	DSA_TAG_PROTO_EDSA,
	DSA_TAG_PROTO_KSZ,
	DSA_TAG_PROTO_LAN9303,
	DSA_TAG_PROTO_MTK,
	DSA_TAG_PROTO_QCA,
	DSA_TAG_PROTO_TRAILER,
	DSA_TAG_LAST,		
};

#define DSA_MAX_SWITCHES	4
#define DSA_MAX_PORTS		12

#define DSA_RTABLE_NONE		-1

struct dsa_chip_data {
	
	struct device	*host_dev;
	int		sw_addr;

	
	struct device	*netdev[DSA_MAX_PORTS];

	
	int		eeprom_len;

	
	struct device_node *of_node;

	
	char		*port_names[DSA_MAX_PORTS];
	struct device_node *port_dn[DSA_MAX_PORTS];

	
	s8		rtable[DSA_MAX_SWITCHES];
};

struct dsa_platform_data {
	
	struct device	*netdev;
	struct net_device *of_netdev;

	
	int		nr_chips;
	struct dsa_chip_data	*chip;
};

struct packet_type;

struct dsa_device_ops {
	struct sk_buff *(*xmit)(struct sk_buff *skb, struct net_device *dev);
	struct sk_buff *(*rcv)(struct sk_buff *skb, struct net_device *dev,
			       struct packet_type *pt);
	int (*flow_dissect)(const struct sk_buff *skb, __be16 *proto,
			    int *offset);
};

struct dsa_switch_tree {
	struct list_head	list;

	
	struct raw_notifier_head	nh;

	
	u32 tree;

	
	struct kref refcount;

	
	bool applied;

	
	struct dsa_platform_data	*pd;

	
	struct sk_buff *	(*rcv)(struct sk_buff *skb,
				       struct net_device *dev,
				       struct packet_type *pt);

	
	struct dsa_port		*cpu_dp;

	
	struct dsa_switch	*ds[DSA_MAX_SWITCHES];

	
	const struct dsa_device_ops *tag_ops;
};


enum dsa_port_mall_action_type {
	DSA_PORT_MALL_MIRROR,
};


struct dsa_mall_mirror_tc_entry {
	u8 to_local_port;
	bool ingress;
};


struct dsa_mall_tc_entry {
	struct list_head list;
	unsigned long cookie;
	enum dsa_port_mall_action_type type;
	union {
		struct dsa_mall_mirror_tc_entry mirror;
	};
};


struct dsa_port {
	struct dsa_switch	*ds;
	unsigned int		index;
	const char		*name;
	struct dsa_port		*cpu_dp;
	struct net_device	*netdev;
	struct device_node	*dn;
	unsigned int		ageing_time;
	u8			stp_state;
	struct net_device	*bridge_dev;
	struct devlink_port	devlink_port;
	
	struct ethtool_ops	ethtool_ops;
	const struct ethtool_ops *orig_ethtool_ops;
};

struct dsa_switch {
	struct device *dev;

	
	struct dsa_switch_tree	*dst;
	int			index;

	
	struct notifier_block	nb;

	
	void *priv;

	
	struct dsa_chip_data	*cd;

	
	const struct dsa_switch_ops	*ops;

	
	s8		rtable[DSA_MAX_SWITCHES];

	
	u32			dsa_port_mask;
	u32			cpu_port_mask;
	u32			enabled_port_mask;
	u32			phys_mii_mask;
	struct mii_bus		*slave_mii_bus;

	
	unsigned int ageing_time_min;
	unsigned int ageing_time_max;

	
	struct devlink		*devlink;

	
	unsigned int		num_tx_queues;

	
	size_t num_ports;
	struct dsa_port ports[];
};

static inline bool dsa_is_cpu_port(struct dsa_switch *ds, int p)
{
	return !!(ds->cpu_port_mask & (1 << p));
}

static inline bool dsa_is_dsa_port(struct dsa_switch *ds, int p)
{
	return !!((ds->dsa_port_mask) & (1 << p));
}

static inline bool dsa_is_normal_port(struct dsa_switch *ds, int p)
{
	return !dsa_is_cpu_port(ds, p) && !dsa_is_dsa_port(ds, p);
}

static inline u8 dsa_upstream_port(struct dsa_switch *ds)
{
	struct dsa_switch_tree *dst = ds->dst;

	
	if (dst->cpu_dp->ds == ds)
		return dst->cpu_dp->index;
	else
		return ds->rtable[dst->cpu_dp->ds->index];
}

typedef int dsa_fdb_dump_cb_t(const unsigned char *addr, u16 vid,
			      bool is_static, void *data);
struct dsa_switch_ops {
	
	const char	*(*probe)(struct device *dsa_dev,
				  struct device *host_dev, int sw_addr,
				  void **priv);

	enum dsa_tag_protocol (*get_tag_protocol)(struct dsa_switch *ds);

	int	(*setup)(struct dsa_switch *ds);
	int	(*set_addr)(struct dsa_switch *ds, u8 *addr);
	u32	(*get_phy_flags)(struct dsa_switch *ds, int port);

	
	int	(*phy_read)(struct dsa_switch *ds, int port, int regnum);
	int	(*phy_write)(struct dsa_switch *ds, int port,
			     int regnum, u16 val);

	
	void	(*adjust_link)(struct dsa_switch *ds, int port,
				struct phy_device *phydev);
	void	(*fixed_link_update)(struct dsa_switch *ds, int port,
				struct fixed_phy_status *st);

	
	void	(*get_strings)(struct dsa_switch *ds, int port, uint8_t *data);
	void	(*get_ethtool_stats)(struct dsa_switch *ds,
				     int port, uint64_t *data);
	int	(*get_sset_count)(struct dsa_switch *ds);

	
	void	(*get_wol)(struct dsa_switch *ds, int port,
			   struct ethtool_wolinfo *w);
	int	(*set_wol)(struct dsa_switch *ds, int port,
			   struct ethtool_wolinfo *w);

	
	int	(*suspend)(struct dsa_switch *ds);
	int	(*resume)(struct dsa_switch *ds);

	
	int	(*port_enable)(struct dsa_switch *ds, int port,
			       struct phy_device *phy);
	void	(*port_disable)(struct dsa_switch *ds, int port,
				struct phy_device *phy);

	
	int	(*set_mac_eee)(struct dsa_switch *ds, int port,
			       struct ethtool_eee *e);
	int	(*get_mac_eee)(struct dsa_switch *ds, int port,
			       struct ethtool_eee *e);

	
	int	(*get_eeprom_len)(struct dsa_switch *ds);
	int	(*get_eeprom)(struct dsa_switch *ds,
			      struct ethtool_eeprom *eeprom, u8 *data);
	int	(*set_eeprom)(struct dsa_switch *ds,
			      struct ethtool_eeprom *eeprom, u8 *data);

	
	int	(*get_regs_len)(struct dsa_switch *ds, int port);
	void	(*get_regs)(struct dsa_switch *ds, int port,
			    struct ethtool_regs *regs, void *p);

	
	int	(*set_ageing_time)(struct dsa_switch *ds, unsigned int msecs);
	int	(*port_bridge_join)(struct dsa_switch *ds, int port,
				    struct net_device *bridge);
	void	(*port_bridge_leave)(struct dsa_switch *ds, int port,
				     struct net_device *bridge);
	void	(*port_stp_state_set)(struct dsa_switch *ds, int port,
				      u8 state);
	void	(*port_fast_age)(struct dsa_switch *ds, int port);

	
	int	(*port_vlan_filtering)(struct dsa_switch *ds, int port,
				       bool vlan_filtering);
	int	(*port_vlan_prepare)(struct dsa_switch *ds, int port,
				     const struct switchdev_obj_port_vlan *vlan,
				     struct switchdev_trans *trans);
	void	(*port_vlan_add)(struct dsa_switch *ds, int port,
				 const struct switchdev_obj_port_vlan *vlan,
				 struct switchdev_trans *trans);
	int	(*port_vlan_del)(struct dsa_switch *ds, int port,
				 const struct switchdev_obj_port_vlan *vlan);
	
	int	(*port_fdb_add)(struct dsa_switch *ds, int port,
				const unsigned char *addr, u16 vid);
	int	(*port_fdb_del)(struct dsa_switch *ds, int port,
				const unsigned char *addr, u16 vid);
	int	(*port_fdb_dump)(struct dsa_switch *ds, int port,
				 dsa_fdb_dump_cb_t *cb, void *data);

	
	int	(*port_mdb_prepare)(struct dsa_switch *ds, int port,
				    const struct switchdev_obj_port_mdb *mdb,
				    struct switchdev_trans *trans);
	void	(*port_mdb_add)(struct dsa_switch *ds, int port,
				const struct switchdev_obj_port_mdb *mdb,
				struct switchdev_trans *trans);
	int	(*port_mdb_del)(struct dsa_switch *ds, int port,
				const struct switchdev_obj_port_mdb *mdb);
	
	int	(*get_rxnfc)(struct dsa_switch *ds, int port,
			     struct ethtool_rxnfc *nfc, u32 *rule_locs);
	int	(*set_rxnfc)(struct dsa_switch *ds, int port,
			     struct ethtool_rxnfc *nfc);

	
	int	(*port_mirror_add)(struct dsa_switch *ds, int port,
				   struct dsa_mall_mirror_tc_entry *mirror,
				   bool ingress);
	void	(*port_mirror_del)(struct dsa_switch *ds, int port,
				   struct dsa_mall_mirror_tc_entry *mirror);

	
	int	(*crosschip_bridge_join)(struct dsa_switch *ds, int sw_index,
					 int port, struct net_device *br);
	void	(*crosschip_bridge_leave)(struct dsa_switch *ds, int sw_index,
					  int port, struct net_device *br);
};

struct dsa_switch_driver {
	struct list_head	list;
	const struct dsa_switch_ops *ops;
};


void register_switch_driver(struct dsa_switch_driver *type);
void unregister_switch_driver(struct dsa_switch_driver *type);
struct mii_bus *dsa_host_dev_to_mii_bus(struct device *dev);

struct net_device *dsa_dev_to_net_device(struct device *dev);


static inline bool netdev_uses_dsa(struct net_device *dev)
{
#if IS_ENABLED(CONFIG_NET_DSA)
	return dev->dsa_ptr && dev->dsa_ptr->rcv;
#endif
	return false;
}

struct dsa_switch *dsa_switch_alloc(struct device *dev, size_t n);
void dsa_unregister_switch(struct dsa_switch *ds);
int dsa_register_switch(struct dsa_switch *ds);
#ifdef CONFIG_PM_SLEEP
int dsa_switch_suspend(struct dsa_switch *ds);
int dsa_switch_resume(struct dsa_switch *ds);
#else
static inline int dsa_switch_suspend(struct dsa_switch *ds)
{
	return 0;
}
static inline int dsa_switch_resume(struct dsa_switch *ds)
{
	return 0;
}
#endif 

#endif
