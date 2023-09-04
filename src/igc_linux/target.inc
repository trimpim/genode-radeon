#
# Linux kernel configuration
#

# kernel fundamentals
LX_ENABLE += TTY SERIAL_EARLYCON SERIAL_OF_PLATFORM PRINTK HAS_IOMEM SMP

# support disabling ticking during idle
LX_ENABLE  += NO_HZ_IDLE

# initrd support
LX_ENABLE += BINFMT_ELF BINFMT_SCRIPT BLK_DEV_INITRD

# UART device
LX_ENABLE += SERIAL_8250 SERIAL_8250_CONSOLE

# PCI support
LX_ENABLE += PCI PCI_MSI

# IOMMU support (used by Intel fb to apply scanout scratch page workaround)
LX_ENABLE += IOMMU_SUPPORT INTEL_IOMMU

# ACPI support
LX_ENABLE += ACPI

# EFI support
LX_ENABLE += EFI EFI_STUB

# general network and WLAN support
LX_ENABLE += NET NETDEVICES PACKET

# Ethernet NIC support
LX_ENABLE += IGC

# firmware loader
LX_ENABLE += FW_LOADER

# mandatory fs support
LX_ENABLE += PROC_FS SYSFS

# disable cpu frequency scaling
LX_DISABLE += SCHED_MC CPU_FREQ

# disable optimization not possible in PIC code under Genode
LX_DISABLE += CC_HAS_ASM_GOTO

# slim down kernel by removing superfluous drivers
LX_DISABLE += HID HID_GENERIC USB_HID VGA_CONSOLE DUMMY_CONSOLE NLS VGA_ARB DEBUG_LIST

# vim: ft=make
