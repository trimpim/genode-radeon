/*
 * \brief  Dummy definitions of Linux Kernel functions - handled manually
 * \author Alexander Boettcher
 * \author Josef Soentgen
 * \author Pirmin Duss
 * \date   2022-01-10
 */

/*
 * Copyright (C) 2022 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#include <lx_emul/debug.h>
#include <linux/math64.h>
//#include <linux/jump_label.h>

#include <lx_emul.h>
#include <asm-generic/errno.h>

#if DEBUG_TRACE
#define TRACE lx_printf("\033[32m%s\033[0m called from %p, not implemented\n", __PRETTY_FUNCTION__, __builtin_return_address(0))
#else
#define TRACE
#endif

#include <linux/filter.h>
#include <linux/jump_label.h> /* for DEFINE_STATIC_KEY_FALSE */

DEFINE_STATIC_KEY_FALSE(bpf_stats_enabled_key);
DEFINE_STATIC_KEY_FALSE(init_on_alloc);

asmlinkage __wsum csum_partial(const void * buff,int len,__wsum sum)
{
	lx_emul_trace_and_stop(__func__);
}


void pci_disable_msi (struct pci_dev *pdev) { TRACE; }
void pci_disable_msix(struct pci_dev *pdev) { TRACE; }

int pci_enable_msix_range(struct pci_dev *dev, struct msix_entry *entries,
                          int minvec, int maxvec)
{
	lx_emul_trace(__func__);
	return -ENOSYS;
}

int pci_enable_msi(struct pci_dev *dev)
{
	lx_emul_trace(__func__);
	return -ENOSYS;
}


#include <asm/smp.h>

struct smp_ops smp_ops = { };
EXPORT_SYMBOL_GPL(smp_ops);


#include <linux/proc_ns.h>

int proc_alloc_inum(unsigned int * inum)
{
	*inum = 1;
	return 0;
}


#include <net/net_namespace.h>

__init int net_sysctl_init(void)
{
	printk("%s\n",__func__);
	return 0;
}


#include <linux/slab.h>

struct kmem_cache * kmem_cache_create_usercopy(const char * name,unsigned int size,unsigned int align,slab_flags_t flags,unsigned int useroffset,unsigned int usersize,void (* ctor)(void *))
{
	return kmem_cache_create(name, size, align, flags, ctor);
}


#include <linux/fs.h>

int register_filesystem(struct file_system_type * s)
{
	printk("%s  -> name='%s'\n",__func__,s->name);
//	lx_emul_backtrace();
	return 0;
}


#include <linux/fs.h>

struct vfsmount * kern_mount(struct file_system_type * type)
{
	printk("%s  -> name='%s'\n",__func__,type->name);
//	lx_emul_backtrace();
	return NULL;
}


#include <linux/kernel.h>

void bust_spinlocks(int yes)
{
	printk("%s\n",__func__);
}


#include <linux/printk.h>

void printk_safe_flush_on_panic(void)
{
	printk("%s\n",__func__);
}
