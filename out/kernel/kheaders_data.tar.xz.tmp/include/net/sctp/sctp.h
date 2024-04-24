

#ifndef __net_sctp_h__
#define __net_sctp_h__



#include <linux/types.h>
#include <linux/slab.h>
#include <linux/in.h>
#include <linux/tty.h>
#include <linux/proc_fs.h>
#include <linux/spinlock.h>
#include <linux/jiffies.h>
#include <linux/idr.h>

#if IS_ENABLED(CONFIG_IPV6)
#include <net/ipv6.h>
#include <net/ip6_route.h>
#endif

#include <linux/uaccess.h>
#include <asm/page.h>
#include <net/sock.h>
#include <net/snmp.h>
#include <net/sctp/structs.h>
#include <net/sctp/constants.h>

#ifdef CONFIG_IP_SCTP_MODULE
#define SCTP_PROTOSW_FLAG 0
#else 
#define SCTP_PROTOSW_FLAG INET_PROTOSW_PERMANENT
#endif


#define SCTP_PAD4(s) (((s)+3)&~3)

#define SCTP_TRUNC4(s) ((s)&~3)




int sctp_copy_local_addr_list(struct net *net, struct sctp_bind_addr *addr,
			      enum sctp_scope, gfp_t gfp, int flags);
struct sctp_pf *sctp_get_pf_specific(sa_family_t family);
int sctp_register_pf(struct sctp_pf *, sa_family_t);
void sctp_addr_wq_mgmt(struct net *, struct sctp_sockaddr_entry *, int);


int sctp_inet_connect(struct socket *sock, struct sockaddr *uaddr,
		      int addr_len, int flags);
int sctp_backlog_rcv(struct sock *sk, struct sk_buff *skb);
int sctp_inet_listen(struct socket *sock, int backlog);
void sctp_write_space(struct sock *sk);
void sctp_data_ready(struct sock *sk);
unsigned int sctp_poll(struct file *file, struct socket *sock,
		poll_table *wait);
void sctp_sock_rfree(struct sk_buff *skb);
void sctp_copy_sock(struct sock *newsk, struct sock *sk,
		    struct sctp_association *asoc);
extern struct percpu_counter sctp_sockets_allocated;
int sctp_asconf_mgmt(struct sctp_sock *, struct sctp_sockaddr_entry *);
struct sk_buff *sctp_skb_recv_datagram(struct sock *, int, int, int *);

int sctp_transport_walk_start(struct rhashtable_iter *iter);
void sctp_transport_walk_stop(struct rhashtable_iter *iter);
struct sctp_transport *sctp_transport_get_next(struct net *net,
			struct rhashtable_iter *iter);
struct sctp_transport *sctp_transport_get_idx(struct net *net,
			struct rhashtable_iter *iter, int pos);
int sctp_transport_lookup_process(int (*cb)(struct sctp_transport *, void *),
				  struct net *net,
				  const union sctp_addr *laddr,
				  const union sctp_addr *paddr, void *p);
int sctp_for_each_transport(int (*cb)(struct sctp_transport *, void *),
			    int (*cb_done)(struct sctp_transport *, void *),
			    struct net *net, int *pos, void *p);
int sctp_for_each_endpoint(int (*cb)(struct sctp_endpoint *, void *), void *p);
int sctp_get_sctp_info(struct sock *sk, struct sctp_association *asoc,
		       struct sctp_info *info);


int sctp_primitive_ASSOCIATE(struct net *, struct sctp_association *, void *arg);
int sctp_primitive_SHUTDOWN(struct net *, struct sctp_association *, void *arg);
int sctp_primitive_ABORT(struct net *, struct sctp_association *, void *arg);
int sctp_primitive_SEND(struct net *, struct sctp_association *, void *arg);
int sctp_primitive_REQUESTHEARTBEAT(struct net *, struct sctp_association *, void *arg);
int sctp_primitive_ASCONF(struct net *, struct sctp_association *, void *arg);
int sctp_primitive_RECONF(struct net *net, struct sctp_association *asoc,
			  void *arg);


int sctp_rcv(struct sk_buff *skb);
void sctp_v4_err(struct sk_buff *skb, u32 info);
void sctp_hash_endpoint(struct sctp_endpoint *);
void sctp_unhash_endpoint(struct sctp_endpoint *);
struct sock *sctp_err_lookup(struct net *net, int family, struct sk_buff *,
			     struct sctphdr *, struct sctp_association **,
			     struct sctp_transport **);
void sctp_err_finish(struct sock *, struct sctp_transport *);
void sctp_icmp_frag_needed(struct sock *, struct sctp_association *,
			   struct sctp_transport *t, __u32 pmtu);
void sctp_icmp_redirect(struct sock *, struct sctp_transport *,
			struct sk_buff *);
void sctp_icmp_proto_unreachable(struct sock *sk,
				 struct sctp_association *asoc,
				 struct sctp_transport *t);
void sctp_backlog_migrate(struct sctp_association *assoc,
			  struct sock *oldsk, struct sock *newsk);
int sctp_transport_hashtable_init(void);
void sctp_transport_hashtable_destroy(void);
int sctp_hash_transport(struct sctp_transport *t);
void sctp_unhash_transport(struct sctp_transport *t);
struct sctp_transport *sctp_addrs_lookup_transport(
				struct net *net,
				const union sctp_addr *laddr,
				const union sctp_addr *paddr);
struct sctp_transport *sctp_epaddr_lookup_transport(
				const struct sctp_endpoint *ep,
				const union sctp_addr *paddr);


int sctp_snmp_proc_init(struct net *net);
void sctp_snmp_proc_exit(struct net *net);
int sctp_eps_proc_init(struct net *net);
void sctp_eps_proc_exit(struct net *net);
int sctp_assocs_proc_init(struct net *net);
void sctp_assocs_proc_exit(struct net *net);
int sctp_remaddr_proc_init(struct net *net);
void sctp_remaddr_proc_exit(struct net *net);


int sctp_offload_init(void);


int sctp_send_reset_streams(struct sctp_association *asoc,
			    struct sctp_reset_streams *params);
int sctp_send_reset_assoc(struct sctp_association *asoc);
int sctp_send_add_streams(struct sctp_association *asoc,
			  struct sctp_add_streams *params);



 
extern struct kmem_cache *sctp_chunk_cachep __read_mostly;
extern struct kmem_cache *sctp_bucket_cachep __read_mostly;
extern long sysctl_sctp_mem[3];
extern int sysctl_sctp_rmem[3];
extern int sysctl_sctp_wmem[3];




#define SCTP_INC_STATS(net, field)	SNMP_INC_STATS((net)->sctp.sctp_statistics, field)
#define __SCTP_INC_STATS(net, field)	__SNMP_INC_STATS((net)->sctp.sctp_statistics, field)
#define SCTP_DEC_STATS(net, field)	SNMP_DEC_STATS((net)->sctp.sctp_statistics, field)


enum {
	SCTP_MIB_NUM = 0,
	SCTP_MIB_CURRESTAB,			
	SCTP_MIB_ACTIVEESTABS,			
	SCTP_MIB_PASSIVEESTABS,			
	SCTP_MIB_ABORTEDS,			
	SCTP_MIB_SHUTDOWNS,			
	SCTP_MIB_OUTOFBLUES,			
	SCTP_MIB_CHECKSUMERRORS,		
	SCTP_MIB_OUTCTRLCHUNKS,			
	SCTP_MIB_OUTORDERCHUNKS,		
	SCTP_MIB_OUTUNORDERCHUNKS,		
	SCTP_MIB_INCTRLCHUNKS,			
	SCTP_MIB_INORDERCHUNKS,			
	SCTP_MIB_INUNORDERCHUNKS,		
	SCTP_MIB_FRAGUSRMSGS,			
	SCTP_MIB_REASMUSRMSGS,			
	SCTP_MIB_OUTSCTPPACKS,			
	SCTP_MIB_INSCTPPACKS,			
	SCTP_MIB_T1_INIT_EXPIREDS,
	SCTP_MIB_T1_COOKIE_EXPIREDS,
	SCTP_MIB_T2_SHUTDOWN_EXPIREDS,
	SCTP_MIB_T3_RTX_EXPIREDS,
	SCTP_MIB_T4_RTO_EXPIREDS,
	SCTP_MIB_T5_SHUTDOWN_GUARD_EXPIREDS,
	SCTP_MIB_DELAY_SACK_EXPIREDS,
	SCTP_MIB_AUTOCLOSE_EXPIREDS,
	SCTP_MIB_T1_RETRANSMITS,
	SCTP_MIB_T3_RETRANSMITS,
	SCTP_MIB_PMTUD_RETRANSMITS,
	SCTP_MIB_FAST_RETRANSMITS,
	SCTP_MIB_IN_PKT_SOFTIRQ,
	SCTP_MIB_IN_PKT_BACKLOG,
	SCTP_MIB_IN_PKT_DISCARDS,
	SCTP_MIB_IN_DATA_CHUNK_DISCARDS,
	__SCTP_MIB_MAX
};

#define SCTP_MIB_MAX    __SCTP_MIB_MAX
struct sctp_mib {
        unsigned long   mibs[SCTP_MIB_MAX];
};


static inline void sctp_max_rto(struct sctp_association *asoc,
				struct sctp_transport *trans)
{
	if (asoc->stats.max_obs_rto < (__u64)trans->rto) {
		asoc->stats.max_obs_rto = trans->rto;
		memset(&asoc->stats.obs_rto_ipaddr, 0,
			sizeof(struct sockaddr_storage));
		memcpy(&asoc->stats.obs_rto_ipaddr, &trans->ipaddr,
			trans->af_specific->sockaddr_len);
	}
}


#ifdef CONFIG_SCTP_DBG_OBJCNT

extern atomic_t sctp_dbg_objcnt_sock;
extern atomic_t sctp_dbg_objcnt_ep;
extern atomic_t sctp_dbg_objcnt_assoc;
extern atomic_t sctp_dbg_objcnt_transport;
extern atomic_t sctp_dbg_objcnt_chunk;
extern atomic_t sctp_dbg_objcnt_bind_addr;
extern atomic_t sctp_dbg_objcnt_bind_bucket;
extern atomic_t sctp_dbg_objcnt_addr;
extern atomic_t sctp_dbg_objcnt_datamsg;
extern atomic_t sctp_dbg_objcnt_keys;


#define SCTP_DBG_OBJCNT_INC(name) \
atomic_inc(&sctp_dbg_objcnt_## name)
#define SCTP_DBG_OBJCNT_DEC(name) \
atomic_dec(&sctp_dbg_objcnt_## name)
#define SCTP_DBG_OBJCNT(name) \
atomic_t sctp_dbg_objcnt_## name = ATOMIC_INIT(0)


#define SCTP_DBG_OBJCNT_ENTRY(name) \
{.label= #name, .counter= &sctp_dbg_objcnt_## name}

void sctp_dbg_objcnt_init(struct net *);
void sctp_dbg_objcnt_exit(struct net *);

#else

#define SCTP_DBG_OBJCNT_INC(name)
#define SCTP_DBG_OBJCNT_DEC(name)

static inline void sctp_dbg_objcnt_init(struct net *net) { return; }
static inline void sctp_dbg_objcnt_exit(struct net *net) { return; }

#endif 

#if defined CONFIG_SYSCTL
void sctp_sysctl_register(void);
void sctp_sysctl_unregister(void);
int sctp_sysctl_net_register(struct net *net);
void sctp_sysctl_net_unregister(struct net *net);
#else
static inline void sctp_sysctl_register(void) { return; }
static inline void sctp_sysctl_unregister(void) { return; }
static inline int sctp_sysctl_net_register(struct net *net) { return 0; }
static inline void sctp_sysctl_net_unregister(struct net *net) { return; }
#endif


#define SCTP_SAT_LEN(x) (sizeof(struct sctp_paramhdr) + (x) * sizeof(__u16))

#if IS_ENABLED(CONFIG_IPV6)

void sctp_v6_pf_init(void);
void sctp_v6_pf_exit(void);
int sctp_v6_protosw_init(void);
void sctp_v6_protosw_exit(void);
int sctp_v6_add_protocol(void);
void sctp_v6_del_protocol(void);

#else 

static inline void sctp_v6_pf_init(void) { return; }
static inline void sctp_v6_pf_exit(void) { return; }
static inline int sctp_v6_protosw_init(void) { return 0; }
static inline void sctp_v6_protosw_exit(void) { return; }
static inline int sctp_v6_add_protocol(void) { return 0; }
static inline void sctp_v6_del_protocol(void) { return; }

#endif 



static inline sctp_assoc_t sctp_assoc2id(const struct sctp_association *asoc)
{
	return asoc ? asoc->assoc_id : 0;
}

static inline enum sctp_sstat_state
sctp_assoc_to_state(const struct sctp_association *asoc)
{
	
	return asoc->state + 1;
}


struct sctp_association *sctp_id2assoc(struct sock *sk, sctp_assoc_t id);

int sctp_do_peeloff(struct sock *sk, sctp_assoc_t id, struct socket **sockp);


#define sctp_skb_for_each(pos, head, tmp) \
	skb_queue_walk_safe(head, pos, tmp)



static inline struct list_head *sctp_list_dequeue(struct list_head *list)
{
	struct list_head *result = NULL;

	if (!list_empty(list)) {
		result = list->next;
		list_del_init(result);
	}
	return result;
}


static inline void sctp_skb_set_owner_r(struct sk_buff *skb, struct sock *sk)
{
	struct sctp_ulpevent *event = sctp_skb2event(skb);

	skb_orphan(skb);
	skb->sk = sk;
	skb->destructor = sctp_sock_rfree;
	atomic_add(event->rmem_len, &sk->sk_rmem_alloc);
	
	sk->sk_forward_alloc -= event->rmem_len;
}


static inline int sctp_list_single_entry(struct list_head *head)
{
	return (head->next != head) && (head->next == head->prev);
}


static inline int sctp_frag_point(const struct sctp_association *asoc, int pmtu)
{
	struct sctp_sock *sp = sctp_sk(asoc->base.sk);
	int frag = pmtu;

	frag -= sp->pf->af->net_header_len;
	frag -= sizeof(struct sctphdr) + sizeof(struct sctp_data_chunk);

	if (asoc->user_frag)
		frag = min_t(int, frag, asoc->user_frag);

	frag = SCTP_TRUNC4(min_t(int, frag, SCTP_MAX_CHUNK_LEN -
					    sizeof(struct sctp_data_chunk)));

	return frag;
}

static inline void sctp_assoc_pending_pmtu(struct sctp_association *asoc)
{
	sctp_assoc_sync_pmtu(asoc);
	asoc->pmtu_pending = 0;
}

static inline bool sctp_chunk_pending(const struct sctp_chunk *chunk)
{
	return !list_empty(&chunk->list);
}


#define sctp_walk_params(pos, chunk, member)\
_sctp_walk_params((pos), (chunk), ntohs((chunk)->chunk_hdr.length), member)

#define _sctp_walk_params(pos, chunk, end, member)\
for (pos.v = chunk->member;\
     (pos.v + offsetof(struct sctp_paramhdr, length) + sizeof(pos.p->length) <=\
      (void *)chunk + end) &&\
     pos.v <= (void *)chunk + end - ntohs(pos.p->length) &&\
     ntohs(pos.p->length) >= sizeof(struct sctp_paramhdr);\
     pos.v += SCTP_PAD4(ntohs(pos.p->length)))

#define sctp_walk_errors(err, chunk_hdr)\
_sctp_walk_errors((err), (chunk_hdr), ntohs((chunk_hdr)->length))

#define _sctp_walk_errors(err, chunk_hdr, end)\
for (err = (struct sctp_errhdr *)((void *)chunk_hdr + \
	    sizeof(struct sctp_chunkhdr));\
     ((void *)err + offsetof(struct sctp_errhdr, length) + sizeof(err->length) <=\
      (void *)chunk_hdr + end) &&\
     (void *)err <= (void *)chunk_hdr + end - ntohs(err->length) &&\
     ntohs(err->length) >= sizeof(struct sctp_errhdr); \
     err = (struct sctp_errhdr *)((void *)err + SCTP_PAD4(ntohs(err->length))))

#define sctp_walk_fwdtsn(pos, chunk)\
_sctp_walk_fwdtsn((pos), (chunk), ntohs((chunk)->chunk_hdr->length) - sizeof(struct sctp_fwdtsn_chunk))

#define _sctp_walk_fwdtsn(pos, chunk, end)\
for (pos = chunk->subh.fwdtsn_hdr->skip;\
     (void *)pos <= (void *)chunk->subh.fwdtsn_hdr->skip + end - sizeof(struct sctp_fwdtsn_skip);\
     pos++)



extern struct proto sctp_prot;
extern struct proto sctpv6_prot;
void sctp_put_port(struct sock *sk);

extern struct idr sctp_assocs_id;
extern spinlock_t sctp_assocs_id_lock;




static inline int ipver2af(__u8 ipver)
{
	switch (ipver) {
	case 4:
	        return  AF_INET;
	case 6:
		return AF_INET6;
	default:
		return 0;
	}
}


static inline int param_type2af(__be16 type)
{
	switch (type) {
	case SCTP_PARAM_IPV4_ADDRESS:
	        return  AF_INET;
	case SCTP_PARAM_IPV6_ADDRESS:
		return AF_INET6;
	default:
		return 0;
	}
}



static inline int sctp_phashfn(struct net *net, __u16 lport)
{
	return (net_hash_mix(net) + lport) & (sctp_port_hashsize - 1);
}


static inline int sctp_ep_hashfn(struct net *net, __u16 lport)
{
	return (net_hash_mix(net) + lport) & (sctp_ep_hashsize - 1);
}

#define sctp_for_each_hentry(epb, head) \
	hlist_for_each_entry(epb, head, node)


#define sctp_style(sk, style) __sctp_style((sk), (SCTP_SOCKET_##style))
static inline int __sctp_style(const struct sock *sk,
			       enum sctp_socket_type style)
{
	return sctp_sk(sk)->type == style;
}


#define sctp_state(asoc, state) __sctp_state((asoc), (SCTP_STATE_##state))
static inline int __sctp_state(const struct sctp_association *asoc,
			       enum sctp_state state)
{
	return asoc->state == state;
}


#define sctp_sstate(sk, state) __sctp_sstate((sk), (SCTP_SS_##state))
static inline int __sctp_sstate(const struct sock *sk,
				enum sctp_sock_state state)
{
	return sk->sk_state == state;
}


static inline void sctp_v6_map_v4(union sctp_addr *addr)
{
	addr->v4.sin_family = AF_INET;
	addr->v4.sin_port = addr->v6.sin6_port;
	addr->v4.sin_addr.s_addr = addr->v6.sin6_addr.s6_addr32[3];
}


static inline void sctp_v4_map_v6(union sctp_addr *addr)
{
	__be16 port;

	port = addr->v4.sin_port;
	addr->v6.sin6_addr.s6_addr32[3] = addr->v4.sin_addr.s_addr;
	addr->v6.sin6_port = port;
	addr->v6.sin6_family = AF_INET6;
	addr->v6.sin6_flowinfo = 0;
	addr->v6.sin6_scope_id = 0;
	addr->v6.sin6_addr.s6_addr32[0] = 0;
	addr->v6.sin6_addr.s6_addr32[1] = 0;
	addr->v6.sin6_addr.s6_addr32[2] = htonl(0x0000ffff);
}


static inline struct dst_entry *sctp_transport_dst_check(struct sctp_transport *t)
{
	if (t->dst && !dst_check(t->dst, t->dst_cookie))
		sctp_transport_dst_release(t);

	return t->dst;
}

static inline bool sctp_transport_pmtu_check(struct sctp_transport *t)
{
	__u32 pmtu = max_t(size_t, SCTP_TRUNC4(dst_mtu(t->dst)),
			   SCTP_DEFAULT_MINSEGMENT);

	if (t->pathmtu == pmtu)
		return true;

	t->pathmtu = pmtu;

	return false;
}

#endif 