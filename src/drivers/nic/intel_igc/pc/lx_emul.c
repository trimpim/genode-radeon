/*
 * \brief  Linux emulation environment specific to this driver
 * \author Josef Soentgen
 * \author Pirmin Duss
 * \date   2022-02-09
 */

/*
 * Copyright (C) 2022 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#include <lx_emul.h>

#include <linux/fs.h>

void lx_backtrace(void)
{
}


struct inode * new_inode_pseudo(struct super_block * sb)
{
printk("%s()  ::  %d\n",__func__,__LINE__);
	const struct super_operations *ops = sb->s_op;
	struct inode *inode;

printk("%s()  ::  %d\n",__func__,__LINE__);
	if (ops->alloc_inode)
		inode = ops->alloc_inode(sb);

printk("%s()  ::  %d\n",__func__,__LINE__);
	if (!inode)
		return (struct inode*)ERR_PTR(-ENOMEM);

printk("%s()  ::  %d\n",__func__,__LINE__);
	if (!inode->free_inode)
		inode->free_inode = ops->free_inode;

	return inode;
}
