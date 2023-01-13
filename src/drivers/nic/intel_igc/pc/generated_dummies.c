/*
 * \brief  Dummy definitions of Linux Kernel functions
 * \author Automatically generated file - do no edit
 * \date   2022-10-25
 */

#include <lx_emul.h>


#include <linux/proc_fs.h>

void * PDE_DATA(const struct inode * inode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/ratelimit_types.h>

int ___ratelimit(struct ratelimit_state * rs,const char * func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

noinline u64 __bpf_call_base(u64 r1,u64 r2,u64 r3,u64 r4,u64 r5)
{
	lx_emul_trace_and_stop(__func__);
}


void __bpf_prog_free(struct bpf_prog * fp)
{
	lx_emul_trace_and_stop(__func__);
}


u64 bpf_user_rnd_u32(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)
{
	lx_emul_trace_and_stop(__func__);
}


u64 bpf_get_raw_cpu_id(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)
{
	lx_emul_trace_and_stop(__func__);
}


u64 bpf_event_output(struct bpf_map *map, u64 flags, void *meta, u64 meta_size,
                     void *ctx, u64 ctx_size, bpf_ctx_copy_t ctx_copy)
{
	lx_emul_trace_and_stop(__func__);
}


void bpf_jit_compile(struct bpf_prog *fp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/clk-provider.h>

const char * __clk_get_name(const struct clk * clk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/once.h>

void __do_once_done(bool * done,struct static_key_true * once_key,unsigned long * flags,struct module * mod)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/once.h>

bool __do_once_start(bool * done,unsigned long * flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/file.h>

unsigned long __fdget(unsigned int fd)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/file.h>

int __get_unused_fd_flags(unsigned flags,unsigned long nofile)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

int __nla_parse(struct nlattr ** tb,int maxtype,const struct nlattr * head,int len,const struct nla_policy * policy,unsigned int validate,struct netlink_ext_ack * extack)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

int __nla_validate(const struct nlattr * head,int len,int maxtype,const struct nla_policy * policy,unsigned int validate,struct netlink_ext_ack * extack)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/gfp.h>

void __page_frag_cache_drain(struct page * page,unsigned int count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/cred.h>

void __put_cred(struct cred * cred)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mm.h>

void __put_page(struct page * page)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/task.h>

void __put_task_struct(struct task_struct * tsk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

struct rhash_lock_head __rcu ** __rht_bucket_nested(const struct bucket_table * tbl,unsigned int hash)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/scm.h>

void __scm_destroy(struct scm_cookie * scm)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/scm.h>

int __scm_send(struct socket * sock,struct msghdr * msg,struct scm_cookie * p)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/skbuff.h>

bool __skb_flow_dissect(const struct net * net,const struct sk_buff * skb,struct flow_dissector * flow_dissector,void * target_container,const void * data,__be16 proto,int nhoff,int hlen,unsigned int flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/skbuff.h>

void __skb_get_hash(struct sk_buff * skb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/skbuff.h>

u32 __skb_get_poff(const struct sk_buff * skb,const void * data,const struct flow_keys_basic * keys,int hlen)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sock_diag.h>

u64 __sock_gen_cookie(struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/srcu.h>

void __srcu_read_unlock(struct srcu_struct * ssp,int idx)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

pid_t __task_pid_nr_ns(struct task_struct * task,enum pid_type type,struct pid_namespace * ns)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/vmalloc.h>

void * __vmalloc_node(unsigned long size,unsigned long align,gfp_t gfp_mask,int node,const void * caller)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uio.h>

size_t _copy_from_iter(void * addr,size_t bytes,struct iov_iter * i)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uaccess.h>

unsigned long _copy_from_user(void * to,const void __user * from,unsigned long n)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uio.h>

size_t _copy_to_iter(const void * addr,size_t bytes,struct iov_iter * i)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uaccess.h>

unsigned long _copy_to_user(void __user * to,const void * from,unsigned long n)
{
	lx_emul_trace_and_stop(__func__);
}


extern void ack_bad_irq(unsigned int irq);
void ack_bad_irq(unsigned int irq)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/file.h>

struct file * alloc_file_pseudo(struct inode * inode,struct vfsmount * mnt,const char * name,int flags,const struct file_operations * fops)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/bpf.h>

const struct bpf_func_proto bpf_get_current_comm_proto;


#include <linux/bpf.h>

const struct bpf_func_proto bpf_get_current_pid_tgid_proto;


#include <linux/bpf.h>

const struct bpf_func_proto bpf_get_current_uid_gid_proto;


#include <linux/bpf.h>

const struct bpf_func_proto bpf_get_local_storage_proto;


#include <linux/bpf.h>

const struct bpf_func_proto bpf_get_smp_processor_id_proto;


#include <linux/filter.h>

void * bpf_internal_load_pointer_neg_helper(const struct sk_buff * skb,int k,unsigned int size)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

struct bpf_prog * bpf_prog_alloc(unsigned int size,gfp_t gfp_extra_flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

void bpf_prog_free(struct bpf_prog * fp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

struct bpf_prog * bpf_prog_realloc(struct bpf_prog * fp_old,unsigned int size,gfp_t gfp_extra_flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/filter.h>

struct bpf_prog * bpf_prog_select_runtime(struct bpf_prog * fp,int * err)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/bpf.h>

void bpf_user_rnd_init_once(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kernel.h>

void bust_spinlocks(int yes)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/console.h>

void console_flush_on_panic(enum con_flush_mode mode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/printk.h>

int console_printk[] = {};


#include <linux/console.h>

void console_unblank(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kernel.h>

int get_option(char ** str,int * pint)
{
	lx_emul_trace_and_stop(__func__);
}


char * get_options(const char * str,int nints,int * ints)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pm_qos.h>

void cpu_latency_qos_add_request(struct pm_qos_request * req,s32 value)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/netdevice.h>

int dev_ifconf(struct net * net,struct ifconf * ifc,int size)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/netdevice.h>

int dev_ioctl(struct net * net,unsigned int cmd,struct ifreq * ifr,bool * need_copyout)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/netdevice.h>

int __init dev_proc_init(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/dynamic_queue_limits.h>

void dql_completed(struct dql * dql,unsigned int count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/dynamic_queue_limits.h>

void dql_init(struct dql * dql,unsigned int hold_time)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/dynamic_queue_limits.h>

void dql_reset(struct dql * dql)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/dst.h>

void dst_release(struct dst_entry * dst)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/printk.h>

asmlinkage __visible void dump_stack(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/dcache.h>

char * dynamic_dname(struct dentry * dentry,char * buffer,int buflen,const char * fmt,...)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/reboot.h>

void emergency_restart(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/ethtool.h>

int ethtool_check_ops(const struct ethtool_ops * ops)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/ethtool.h>

int ethtool_get_phc_vclocks(struct net_device * dev,int ** vclock_index)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

pid_t f_getown(struct file * filp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int f_setown(struct file * filp,unsigned long arg,int force)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int fasync_helper(int fd,struct file * filp,int on,struct fasync_struct ** fapp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/file.h>

void fd_install(unsigned int fd,struct file * file)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/capability.h>

bool file_ns_capable(const struct file * file,struct user_namespace * ns,int cap)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

struct task_struct * find_task_by_vpid(pid_t vnr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/flow_dissector.h>

struct flow_dissector flow_keys_basic_dissector;


#include <linux/file.h>

void fput(struct file * file)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/user.h>

void free_uid(struct user_struct * up)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/stringhash.h>

unsigned int full_name_hash(const void * salt,const char * name,unsigned int len)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/property.h>

void fwnode_remove_software_node(struct fwnode_handle * fwnode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

ssize_t generic_file_splice_read(struct file * in,loff_t * ppos,struct pipe_inode_info * pipe,size_t len,unsigned int flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

ssize_t generic_splice_sendpage(struct pipe_inode_info * pipe,struct file * out,loff_t * ppos,size_t len,unsigned int flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/genetlink.h>

atomic_t genl_sk_destructing_cnt;


#include <linux/genetlink.h>

wait_queue_head_t genl_sk_destructing_waitq;


#include <linux/fs.h>

unsigned int get_next_ino(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/file.h>

int get_unused_fd_flags(unsigned flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/gfp.h>

unsigned long get_zeroed_page(gfp_t gfp_mask)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/gfp.h>

bool gfp_pfmemalloc_allowed(gfp_t gfp_mask)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uio.h>

ssize_t import_iovec(int type,const struct iovec __user * uvec,unsigned nr_segs,unsigned fast_segs,struct iovec ** iovp,struct iov_iter * i)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uio.h>

int import_single_range(int rw,void __user * buf,size_t len,struct iovec * iov,struct iov_iter * i)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pseudo_fs.h>

struct pseudo_fs_context * init_pseudo(struct fs_context * fc,unsigned long magic)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/init.h>

bool initcall_debug;


#include <linux/fs.h>

void inode_init_once(struct inode * inode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

void io_schedule_finish(int token)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

int io_schedule_prepare(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

long __sched io_schedule_timeout(long timeout)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uio.h>

void iov_iter_kvec(struct iov_iter * i,unsigned int direction,const struct kvec * kvec,unsigned long nr_segs,size_t count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/uio.h>

void iov_iter_revert(struct iov_iter * i,size_t unroll)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

void iput(struct inode * inode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/irq_work.h>

void irq_work_tick(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/property.h>

bool is_software_node(const struct fwnode_handle * fwnode)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kobject.h>

struct kobject *kernel_kobj;


#include <linux/fs.h>

void kill_anon_super(struct super_block * sb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

void kill_fasync(struct fasync_struct ** fp,int sig,int band)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/slab.h>

int kmem_cache_alloc_bulk(struct kmem_cache * s,gfp_t flags,size_t size,void ** p)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/slab.h>

void kmem_cache_destroy(struct kmem_cache * s)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/slab.h>

void kmem_cache_free_bulk(struct kmem_cache * s,size_t size,void ** p)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/kmsg_dump.h>

void kmsg_dump(enum kmsg_dump_reason reason)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rcutree.h>

void kvfree_call_rcu(struct rcu_head * head,rcu_callback_t func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/netdevice.h>

struct pernet_operations __net_initdata loopback_net_ops;


#include <net/dst_metadata.h>

struct metadata_dst __percpu * metadata_dst_alloc_percpu(u8 optslen,enum metadata_type type,gfp_t flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/dst_metadata.h>

void metadata_dst_free_percpu(struct metadata_dst __percpu * md_dst)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/preempt.h>

void migrate_disable(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/preempt.h>

void migrate_enable(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/neighbour.h>

const struct nla_policy nda_policy[] = {};


#include <net/netlink.h>

int netlink_policy_dump_attr_size_estimate(const struct nla_policy * pt)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

int netlink_policy_dump_write_attr(struct sk_buff * skb,const struct nla_policy * pt,int nestattr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

struct inode * new_inode_pseudo(struct super_block * sb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

struct nlattr * nla_find(const struct nlattr * head,int len,int attrtype)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

int nla_memcpy(void * dest,const struct nlattr * src,int count)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

int nla_put(struct sk_buff * skb,int attrtype,int attrlen,const void * data)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

int nla_put_64bit(struct sk_buff * skb,int attrtype,int attrlen,const void * data,int padattr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

struct nlattr * nla_reserve(struct sk_buff * skb,int attrtype,int attrlen)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

struct nlattr * nla_reserve_64bit(struct sk_buff * skb,int attrtype,int attrlen,int padattr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

char * nla_strdup(const struct nlattr * nla,gfp_t flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/netlink.h>

ssize_t nla_strscpy(char * dst,const struct nlattr * nla,size_t dstsize)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/irq.h>

struct irq_chip no_irq_chip;


#include <linux/fs.h>

loff_t no_llseek(struct file * file,loff_t offset,int whence)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/irq.h>

void note_interrupt(struct irq_desc * desc,irqreturn_t action_ret)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/proc_fs.h>

int open_related_ns(struct ns_common * ns,struct ns_common * (* get_ns)(struct ns_common * ns))
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/highuid.h>

int overflowuid;


#include <linux/gfp.h>

void * page_frag_alloc_align(struct page_frag_cache * nc,unsigned int fragsz,gfp_t gfp_mask,unsigned int align_mask)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/gfp.h>

void page_frag_free(void * addr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/reboot.h>

enum reboot_mode panic_reboot_mode;


#include <linux/pci.h>

bool pci_device_is_present(struct pci_dev * pdev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

void pci_disable_device(struct pci_dev * dev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

int pci_enable_device_mem(struct pci_dev * dev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

int pci_enable_wake(struct pci_dev * pci_dev,pci_power_t state,bool enable)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

void pci_release_selected_regions(struct pci_dev * pdev,int bars)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

int pci_request_selected_regions(struct pci_dev * pdev,int bars,const char * res_name)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

void pci_restore_state(struct pci_dev * dev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

int pci_save_state(struct pci_dev * dev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

int pci_select_bars(struct pci_dev * dev,unsigned long flags)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

int pci_set_power_state(struct pci_dev * dev,pci_power_t state)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

int pci_wake_from_d3(struct pci_dev * dev,bool enable)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pci.h>

void pcie_print_link_status(struct pci_dev * dev)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pid.h>

pid_t pid_vnr(struct pid * pid)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/poll.h>

int poll_select_set_timeout(struct timespec64 * to,time64_t sec,long nsec)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/prandom.h>

u32 prandom_u32(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/printk.h>

int printk_deferred(const char * fmt,...)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/printk.h>

void printk_safe_flush_on_panic(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/proc_ns.h>

void proc_free_inum(unsigned int inum)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/socket.h>

int put_cmsg(struct msghdr * msg,int level,int type,int len,void * data)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/pid.h>

void put_pid(struct pid * pid)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/file.h>

void put_unused_fd(unsigned int fd)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/reboot.h>

enum reboot_mode reboot_mode;


#include <linux/syscore_ops.h>

void register_syscore_ops(struct syscore_ops * ops)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/proc_fs.h>

void remove_proc_entry(const char * name,struct proc_dir_entry * parent)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/sock_reuseport.h>

int reuseport_attach_prog(struct sock * sk,struct bpf_prog * prog)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/sock_reuseport.h>

int reuseport_detach_prog(struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/sock_reuseport.h>

void reuseport_detach_sock(struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

void rhashtable_destroy(struct rhashtable * ht)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

void * rhashtable_insert_slow(struct rhashtable * ht,const void * key,struct rhash_head * obj)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

void rhashtable_walk_enter(struct rhashtable * ht,struct rhashtable_iter * iter)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

void rhashtable_walk_exit(struct rhashtable_iter * iter)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

void * rhashtable_walk_next(struct rhashtable_iter * iter)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

int rhashtable_walk_start_check(struct rhashtable_iter * iter)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

void rhashtable_walk_stop(struct rhashtable_iter * iter)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

struct rhash_lock_head __rcu ** rht_bucket_nested(const struct bucket_table * tbl,unsigned int hash)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/rhashtable.h>

struct rhash_lock_head __rcu ** rht_bucket_nested_insert(struct rhashtable * ht,struct bucket_table * tbl,unsigned int hash)
{
	lx_emul_trace_and_stop(__func__);
}


#include <net/scm.h>

void scm_detach_fds(struct msghdr * msg,struct scm_cookie * scm)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

struct list_head * seq_list_next(void * v,struct list_head * head,loff_t * ppos)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

struct list_head * seq_list_start_head(struct list_head * head,loff_t pos)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

void seq_printf(struct seq_file * m,const char * f,...)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/seq_file.h>

void seq_puts(struct seq_file * m,const char * s)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/mm.h>

void show_mem(unsigned int filter,nodemask_t * nodemask)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/debug.h>

void show_state_filter(unsigned int state_filter)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int simple_setattr(struct user_namespace * mnt_userns,struct dentry * dentry,struct iattr * iattr)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int simple_statfs(struct dentry * dentry,struct kstatfs * buf)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/skbuff.h>

u32 skb_get_poff(const struct sk_buff * skb)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/smp.h>

int smp_call_function_single(int cpu,smp_call_func_t func,void * info,int wait)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/smp.h>

int smp_call_function_single_async(int cpu,struct __call_single_data * csd)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sock_diag.h>

void sock_diag_broadcast_destroy(struct sock * sk)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/jump_label.h>

bool static_key_initialized;


#include <linux/fs.h>

int stream_open(struct inode * inode,struct file * filp)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/string_helpers.h>

int string_escape_mem(const char * src,size_t isz,char * dst,size_t osz,unsigned int flags,const char * only)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/printk.h>

int suppress_printk;


#include <linux/rcupdate.h>

void synchronize_rcu(void)
{
	lx_emul_trace_and_stop(__func__);
}


void synchronize_rcu_expedited()
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sysfs.h>

int sysfs_rename_dir_ns(struct kobject * kobj,const char * new_name,const void * new_ns)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sysfs.h>

int sysfs_rename_link_ns(struct kobject * kobj,struct kobject * targ,const char * old,const char * new,const void * new_ns)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/task_work.h>

int task_work_add(struct task_struct * task,struct callback_head * work,enum task_work_notify_mode notify)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/task_work.h>

struct callback_head * task_work_cancel(struct task_struct * task,task_work_func_t func)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/vt_kern.h>

void unblank_screen(void)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/fs.h>

int unregister_filesystem(struct file_system_type * fs)
{
	lx_emul_trace_and_stop(__func__);
}


extern void unregister_handler_proc(unsigned int irq,struct irqaction * action);
void unregister_handler_proc(unsigned int irq,struct irqaction * action)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched/wake_q.h>

void wake_q_add_safe(struct wake_q_head * head,struct task_struct * task)
{
	lx_emul_trace_and_stop(__func__);
}


#include <linux/sched.h>

void __sched yield(void)
{
	lx_emul_trace_and_stop(__func__);
}

