X86_init.c 
struct x86_init_ops x86_init __initdata = {

	.resources = {
		.probe_roms		= probe_roms,
		.reserve_resources	= reserve_standard_io_resources,
		.memory_setup		= default_machine_specific_memory_setup,
	},

	.mpparse = {
		.mpc_record		= x86_init_uint_noop,
		.setup_ioapic_ids	= x86_init_noop,
		.mpc_apic_id		= default_mpc_apic_id,
		.smp_read_mpc_oem	= default_smp_read_mpc_oem,
		.mpc_oem_bus_info	= default_mpc_oem_bus_info,
		.find_smp_config	= default_find_smp_config,
		.get_smp_config		= default_get_smp_config,
	},

	.irqs = {
		.pre_vector_init	= init_ISA_irqs,
		.intr_init		= native_init_IRQ,
		.trap_init		= x86_init_noop,
	},

	.oem = {
		.arch_setup		= x86_init_noop,
		.banner			= default_banner,
	},

	.mapping = {
		.pagetable_reserve		= native_pagetable_reserve,
	},

	.paging = {
		.pagetable_setup_start	= native_pagetable_setup_start,
		.pagetable_setup_done	= native_pagetable_setup_done,
	},

	.timers = {
		.setup_percpu_clockev	= setup_boot_APIC_clock,
		.tsc_pre_init		= x86_init_noop,
		.timer_init		= hpet_time_init,
		.wallclock_init		= x86_init_noop,
	},

	.iommu = {
		.iommu_init		= iommu_init_noop,
	},

	.pci = {
		.init			= x86_default_pci_init,
		.init_irq		= x86_default_pci_init_irq,
		.fixup_irqs		= x86_default_pci_fixup_irqs,
	},
};
arch/x86/boot/main.c:main()
        |
        |_________detect_memory()
        |                |
        |                |detect_memory_e820:boot_params.e820_map进行e820BIOS中断调用将物理memory信息保存在e820_map中
        |
        |--->arch/x86/boot/pm.c:go_to_protected_mode()--->arch/x86/boot/pmjump.S:protected_mode_jump()
         --->arch/i386/boot/compressed/head_32.S:startup_32()--->arch/x86/kernel/head_32.S:startup_32()
         --->arch/x86/kernel/head32.c:i386_start_kernel()
         --->init/main.c:start_kernel()
                   |
                   |_________setup_arch(&command_line)
		   |		|
		   |		|_________setup_memory_map()_________x86_init.resources.memory_setup()_________default_machine_specific_memory_setup (boot_params.e820_map---->e820)
		   |		|                                                                                          |
		   |		|                                                                                          |____________append_e820_map
		   |	        |                                                                                          |
		   |		|                                                                                          |____________e820_add_region
		   |		|
		   |		|
		   |		|_________e820_end_of_ram_pfn()_________e820_end_pfn 使用e820计算出可用物理内存的页数
		   |		| 
		   |		|_________init_memory_mapping(）建立内核映射页表
		   |		|                 |
		   |		|                 |_________save_mr
		   |		|                 |
		   |		|                 |_________kernel_physical_mapping_init
		   |		| 
		   |		|_________init_memory_mapping()_________
		   |		| 
		   |		|_________initmem_init()
		   |		|
		   |		|_________paging_init()
                   |
                   |_________mm_init()



