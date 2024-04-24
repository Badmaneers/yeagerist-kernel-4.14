



#ifndef __ACTBL1_H__
#define __ACTBL1_H__




#define ACPI_SIG_BERT           "BERT"	
#define ACPI_SIG_CPEP           "CPEP"	
#define ACPI_SIG_ECDT           "ECDT"	
#define ACPI_SIG_EINJ           "EINJ"	
#define ACPI_SIG_ERST           "ERST"	
#define ACPI_SIG_HMAT           "HMAT"	
#define ACPI_SIG_HEST           "HEST"	
#define ACPI_SIG_MADT           "APIC"	
#define ACPI_SIG_MSCT           "MSCT"	
#define ACPI_SIG_PPTT           "PPTT"	
#define ACPI_SIG_SBST           "SBST"	
#define ACPI_SIG_SLIT           "SLIT"	
#define ACPI_SIG_SRAT           "SRAT"	
#define ACPI_SIG_NFIT           "NFIT"	


#pragma pack(1)







struct acpi_subtable_header {
	u8 type;
	u8 length;
};



struct acpi_whea_header {
	u8 action;
	u8 instruction;
	u8 flags;
	u8 reserved;
	struct acpi_generic_address register_region;
	u64 value;		
	u64 mask;		
};



struct acpi_table_bert {
	struct acpi_table_header header;	
	u32 region_length;	
	u64 address;		
};



struct acpi_bert_region {
	u32 block_status;	
	u32 raw_data_offset;	
	u32 raw_data_length;	
	u32 data_length;	
	u32 error_severity;	
};



#define ACPI_BERT_UNCORRECTABLE             (1)
#define ACPI_BERT_CORRECTABLE               (1<<1)
#define ACPI_BERT_MULTIPLE_UNCORRECTABLE    (1<<2)
#define ACPI_BERT_MULTIPLE_CORRECTABLE      (1<<3)
#define ACPI_BERT_ERROR_ENTRY_COUNT         (0xFF<<4)	



enum acpi_bert_error_severity {
	ACPI_BERT_ERROR_CORRECTABLE = 0,
	ACPI_BERT_ERROR_FATAL = 1,
	ACPI_BERT_ERROR_CORRECTED = 2,
	ACPI_BERT_ERROR_NONE = 3,
	ACPI_BERT_ERROR_RESERVED = 4	
};





struct acpi_table_cpep {
	struct acpi_table_header header;	
	u64 reserved;
};



struct acpi_cpep_polling {
	struct acpi_subtable_header header;
	u8 id;			
	u8 eid;			
	u32 interval;		
};



struct acpi_table_ecdt {
	struct acpi_table_header header;	
	struct acpi_generic_address control;	
	struct acpi_generic_address data;	
	u32 uid;		
	u8 gpe;			
	u8 id[1];		
};



struct acpi_table_einj {
	struct acpi_table_header header;	
	u32 header_length;
	u8 flags;
	u8 reserved[3];
	u32 entries;
};



struct acpi_einj_entry {
	struct acpi_whea_header whea_header;	
};



#define ACPI_EINJ_PRESERVE          (1)



enum acpi_einj_actions {
	ACPI_EINJ_BEGIN_OPERATION = 0,
	ACPI_EINJ_GET_TRIGGER_TABLE = 1,
	ACPI_EINJ_SET_ERROR_TYPE = 2,
	ACPI_EINJ_GET_ERROR_TYPE = 3,
	ACPI_EINJ_END_OPERATION = 4,
	ACPI_EINJ_EXECUTE_OPERATION = 5,
	ACPI_EINJ_CHECK_BUSY_STATUS = 6,
	ACPI_EINJ_GET_COMMAND_STATUS = 7,
	ACPI_EINJ_SET_ERROR_TYPE_WITH_ADDRESS = 8,
	ACPI_EINJ_GET_EXECUTE_TIMINGS = 9,
	ACPI_EINJ_ACTION_RESERVED = 10,	
	ACPI_EINJ_TRIGGER_ERROR = 0xFF	
};



enum acpi_einj_instructions {
	ACPI_EINJ_READ_REGISTER = 0,
	ACPI_EINJ_READ_REGISTER_VALUE = 1,
	ACPI_EINJ_WRITE_REGISTER = 2,
	ACPI_EINJ_WRITE_REGISTER_VALUE = 3,
	ACPI_EINJ_NOOP = 4,
	ACPI_EINJ_FLUSH_CACHELINE = 5,
	ACPI_EINJ_INSTRUCTION_RESERVED = 6	
};

struct acpi_einj_error_type_with_addr {
	u32 error_type;
	u32 vendor_struct_offset;
	u32 flags;
	u32 apic_id;
	u64 address;
	u64 range;
	u32 pcie_id;
};

struct acpi_einj_vendor {
	u32 length;
	u32 pcie_id;
	u16 vendor_id;
	u16 device_id;
	u8 revision_id;
	u8 reserved[3];
};



struct acpi_einj_trigger {
	u32 header_size;
	u32 revision;
	u32 table_size;
	u32 entry_count;
};



enum acpi_einj_command_status {
	ACPI_EINJ_SUCCESS = 0,
	ACPI_EINJ_FAILURE = 1,
	ACPI_EINJ_INVALID_ACCESS = 2,
	ACPI_EINJ_STATUS_RESERVED = 3	
};



#define ACPI_EINJ_PROCESSOR_CORRECTABLE     (1)
#define ACPI_EINJ_PROCESSOR_UNCORRECTABLE   (1<<1)
#define ACPI_EINJ_PROCESSOR_FATAL           (1<<2)
#define ACPI_EINJ_MEMORY_CORRECTABLE        (1<<3)
#define ACPI_EINJ_MEMORY_UNCORRECTABLE      (1<<4)
#define ACPI_EINJ_MEMORY_FATAL              (1<<5)
#define ACPI_EINJ_PCIX_CORRECTABLE          (1<<6)
#define ACPI_EINJ_PCIX_UNCORRECTABLE        (1<<7)
#define ACPI_EINJ_PCIX_FATAL                (1<<8)
#define ACPI_EINJ_PLATFORM_CORRECTABLE      (1<<9)
#define ACPI_EINJ_PLATFORM_UNCORRECTABLE    (1<<10)
#define ACPI_EINJ_PLATFORM_FATAL            (1<<11)
#define ACPI_EINJ_VENDOR_DEFINED            (1<<31)



struct acpi_table_erst {
	struct acpi_table_header header;	
	u32 header_length;
	u32 reserved;
	u32 entries;
};



struct acpi_erst_entry {
	struct acpi_whea_header whea_header;	
};



#define ACPI_ERST_PRESERVE          (1)



enum acpi_erst_actions {
	ACPI_ERST_BEGIN_WRITE = 0,
	ACPI_ERST_BEGIN_READ = 1,
	ACPI_ERST_BEGIN_CLEAR = 2,
	ACPI_ERST_END = 3,
	ACPI_ERST_SET_RECORD_OFFSET = 4,
	ACPI_ERST_EXECUTE_OPERATION = 5,
	ACPI_ERST_CHECK_BUSY_STATUS = 6,
	ACPI_ERST_GET_COMMAND_STATUS = 7,
	ACPI_ERST_GET_RECORD_ID = 8,
	ACPI_ERST_SET_RECORD_ID = 9,
	ACPI_ERST_GET_RECORD_COUNT = 10,
	ACPI_ERST_BEGIN_DUMMY_WRIITE = 11,
	ACPI_ERST_NOT_USED = 12,
	ACPI_ERST_GET_ERROR_RANGE = 13,
	ACPI_ERST_GET_ERROR_LENGTH = 14,
	ACPI_ERST_GET_ERROR_ATTRIBUTES = 15,
	ACPI_ERST_EXECUTE_TIMINGS = 16,
	ACPI_ERST_ACTION_RESERVED = 17	
};



enum acpi_erst_instructions {
	ACPI_ERST_READ_REGISTER = 0,
	ACPI_ERST_READ_REGISTER_VALUE = 1,
	ACPI_ERST_WRITE_REGISTER = 2,
	ACPI_ERST_WRITE_REGISTER_VALUE = 3,
	ACPI_ERST_NOOP = 4,
	ACPI_ERST_LOAD_VAR1 = 5,
	ACPI_ERST_LOAD_VAR2 = 6,
	ACPI_ERST_STORE_VAR1 = 7,
	ACPI_ERST_ADD = 8,
	ACPI_ERST_SUBTRACT = 9,
	ACPI_ERST_ADD_VALUE = 10,
	ACPI_ERST_SUBTRACT_VALUE = 11,
	ACPI_ERST_STALL = 12,
	ACPI_ERST_STALL_WHILE_TRUE = 13,
	ACPI_ERST_SKIP_NEXT_IF_TRUE = 14,
	ACPI_ERST_GOTO = 15,
	ACPI_ERST_SET_SRC_ADDRESS_BASE = 16,
	ACPI_ERST_SET_DST_ADDRESS_BASE = 17,
	ACPI_ERST_MOVE_DATA = 18,
	ACPI_ERST_INSTRUCTION_RESERVED = 19	
};



enum acpi_erst_command_status {
	ACPI_ERST_SUCESS = 0,
	ACPI_ERST_NO_SPACE = 1,
	ACPI_ERST_NOT_AVAILABLE = 2,
	ACPI_ERST_FAILURE = 3,
	ACPI_ERST_RECORD_EMPTY = 4,
	ACPI_ERST_NOT_FOUND = 5,
	ACPI_ERST_STATUS_RESERVED = 6	
};



struct acpi_erst_info {
	u16 signature;		
	u8 data[48];
};



struct acpi_table_hest {
	struct acpi_table_header header;	
	u32 error_source_count;
};



struct acpi_hest_header {
	u16 type;
	u16 source_id;
};



enum acpi_hest_types {
	ACPI_HEST_TYPE_IA32_CHECK = 0,
	ACPI_HEST_TYPE_IA32_CORRECTED_CHECK = 1,
	ACPI_HEST_TYPE_IA32_NMI = 2,
	ACPI_HEST_TYPE_NOT_USED3 = 3,
	ACPI_HEST_TYPE_NOT_USED4 = 4,
	ACPI_HEST_TYPE_NOT_USED5 = 5,
	ACPI_HEST_TYPE_AER_ROOT_PORT = 6,
	ACPI_HEST_TYPE_AER_ENDPOINT = 7,
	ACPI_HEST_TYPE_AER_BRIDGE = 8,
	ACPI_HEST_TYPE_GENERIC_ERROR = 9,
	ACPI_HEST_TYPE_GENERIC_ERROR_V2 = 10,
	ACPI_HEST_TYPE_IA32_DEFERRED_CHECK = 11,
	ACPI_HEST_TYPE_RESERVED = 12	
};




struct acpi_hest_ia_error_bank {
	u8 bank_number;
	u8 clear_status_on_init;
	u8 status_format;
	u8 reserved;
	u32 control_register;
	u64 control_data;
	u32 status_register;
	u32 address_register;
	u32 misc_register;
};



struct acpi_hest_aer_common {
	u16 reserved1;
	u8 flags;
	u8 enabled;
	u32 records_to_preallocate;
	u32 max_sections_per_record;
	u32 bus;		
	u16 device;
	u16 function;
	u16 device_control;
	u16 reserved2;
	u32 uncorrectable_mask;
	u32 uncorrectable_severity;
	u32 correctable_mask;
	u32 advanced_capabilities;
};



#define ACPI_HEST_FIRMWARE_FIRST        (1)
#define ACPI_HEST_GLOBAL                (1<<1)
#define ACPI_HEST_GHES_ASSIST           (1<<2)


#define ACPI_HEST_BUS(bus)              ((bus) & 0xFF)
#define ACPI_HEST_SEGMENT(bus)          (((bus) >> 8) & 0xFFFF)



struct acpi_hest_notify {
	u8 type;
	u8 length;
	u16 config_write_enable;
	u32 poll_interval;
	u32 vector;
	u32 polling_threshold_value;
	u32 polling_threshold_window;
	u32 error_threshold_value;
	u32 error_threshold_window;
};



enum acpi_hest_notify_types {
	ACPI_HEST_NOTIFY_POLLED = 0,
	ACPI_HEST_NOTIFY_EXTERNAL = 1,
	ACPI_HEST_NOTIFY_LOCAL = 2,
	ACPI_HEST_NOTIFY_SCI = 3,
	ACPI_HEST_NOTIFY_NMI = 4,
	ACPI_HEST_NOTIFY_CMCI = 5,	
	ACPI_HEST_NOTIFY_MCE = 6,	
	ACPI_HEST_NOTIFY_GPIO = 7,	
	ACPI_HEST_NOTIFY_SEA = 8,	
	ACPI_HEST_NOTIFY_SEI = 9,	
	ACPI_HEST_NOTIFY_GSIV = 10,	
	ACPI_HEST_NOTIFY_SOFTWARE_DELEGATED = 11,	
	ACPI_HEST_NOTIFY_RESERVED = 12	
};



#define ACPI_HEST_TYPE                  (1)
#define ACPI_HEST_POLL_INTERVAL         (1<<1)
#define ACPI_HEST_POLL_THRESHOLD_VALUE  (1<<2)
#define ACPI_HEST_POLL_THRESHOLD_WINDOW (1<<3)
#define ACPI_HEST_ERR_THRESHOLD_VALUE   (1<<4)
#define ACPI_HEST_ERR_THRESHOLD_WINDOW  (1<<5)





struct acpi_hest_ia_machine_check {
	struct acpi_hest_header header;
	u16 reserved1;
	u8 flags;		
	u8 enabled;
	u32 records_to_preallocate;
	u32 max_sections_per_record;
	u64 global_capability_data;
	u64 global_control_data;
	u8 num_hardware_banks;
	u8 reserved3[7];
};



struct acpi_hest_ia_corrected {
	struct acpi_hest_header header;
	u16 reserved1;
	u8 flags;		
	u8 enabled;
	u32 records_to_preallocate;
	u32 max_sections_per_record;
	struct acpi_hest_notify notify;
	u8 num_hardware_banks;
	u8 reserved2[3];
};



struct acpi_hest_ia_nmi {
	struct acpi_hest_header header;
	u32 reserved;
	u32 records_to_preallocate;
	u32 max_sections_per_record;
	u32 max_raw_data_length;
};





struct acpi_hest_aer_root {
	struct acpi_hest_header header;
	struct acpi_hest_aer_common aer;
	u32 root_error_command;
};



struct acpi_hest_aer {
	struct acpi_hest_header header;
	struct acpi_hest_aer_common aer;
};



struct acpi_hest_aer_bridge {
	struct acpi_hest_header header;
	struct acpi_hest_aer_common aer;
	u32 uncorrectable_mask2;
	u32 uncorrectable_severity2;
	u32 advanced_capabilities2;
};



struct acpi_hest_generic {
	struct acpi_hest_header header;
	u16 related_source_id;
	u8 reserved;
	u8 enabled;
	u32 records_to_preallocate;
	u32 max_sections_per_record;
	u32 max_raw_data_length;
	struct acpi_generic_address error_status_address;
	struct acpi_hest_notify notify;
	u32 error_block_length;
};



struct acpi_hest_generic_v2 {
	struct acpi_hest_header header;
	u16 related_source_id;
	u8 reserved;
	u8 enabled;
	u32 records_to_preallocate;
	u32 max_sections_per_record;
	u32 max_raw_data_length;
	struct acpi_generic_address error_status_address;
	struct acpi_hest_notify notify;
	u32 error_block_length;
	struct acpi_generic_address read_ack_register;
	u64 read_ack_preserve;
	u64 read_ack_write;
};



struct acpi_hest_generic_status {
	u32 block_status;
	u32 raw_data_offset;
	u32 raw_data_length;
	u32 data_length;
	u32 error_severity;
};



#define ACPI_HEST_UNCORRECTABLE             (1)
#define ACPI_HEST_CORRECTABLE               (1<<1)
#define ACPI_HEST_MULTIPLE_UNCORRECTABLE    (1<<2)
#define ACPI_HEST_MULTIPLE_CORRECTABLE      (1<<3)
#define ACPI_HEST_ERROR_ENTRY_COUNT         (0xFF<<4)	



struct acpi_hest_generic_data {
	u8 section_type[16];
	u32 error_severity;
	u16 revision;
	u8 validation_bits;
	u8 flags;
	u32 error_data_length;
	u8 fru_id[16];
	u8 fru_text[20];
};



struct acpi_hest_generic_data_v300 {
	u8 section_type[16];
	u32 error_severity;
	u16 revision;
	u8 validation_bits;
	u8 flags;
	u32 error_data_length;
	u8 fru_id[16];
	u8 fru_text[20];
	u64 time_stamp;
};



#define ACPI_HEST_GEN_ERROR_RECOVERABLE     0
#define ACPI_HEST_GEN_ERROR_FATAL           1
#define ACPI_HEST_GEN_ERROR_CORRECTED       2
#define ACPI_HEST_GEN_ERROR_NONE            3



#define ACPI_HEST_GEN_VALID_FRU_ID          (1)
#define ACPI_HEST_GEN_VALID_FRU_STRING      (1<<1)
#define ACPI_HEST_GEN_VALID_TIMESTAMP       (1<<2)



struct acpi_hest_ia_deferred_check {
	struct acpi_hest_header header;
	u16 reserved1;
	u8 flags;		
	u8 enabled;
	u32 records_to_preallocate;
	u32 max_sections_per_record;
	struct acpi_hest_notify notify;
	u8 num_hardware_banks;
	u8 reserved2[3];
};



struct acpi_table_hmat {
	struct acpi_table_header header;	
	u32 reserved;
};



enum acpi_hmat_type {
	ACPI_HMAT_TYPE_ADDRESS_RANGE = 0,	
	ACPI_HMAT_TYPE_LOCALITY = 1,	
	ACPI_HMAT_TYPE_CACHE = 2,	
	ACPI_HMAT_TYPE_RESERVED = 3	
};

struct acpi_hmat_structure {
	u16 type;
	u16 reserved;
	u32 length;
};





struct acpi_hmat_address_range {
	struct acpi_hmat_structure header;
	u16 flags;
	u16 reserved1;
	u32 processor_PD;	
	u32 memory_PD;		
	u32 reserved2;
	u64 physical_address_base;	
	u64 physical_address_length;	
};



#define ACPI_HMAT_PROCESSOR_PD_VALID    (1)	
#define ACPI_HMAT_MEMORY_PD_VALID       (1<<1)	
#define ACPI_HMAT_RESERVATION_HINT      (1<<2)	



struct acpi_hmat_locality {
	struct acpi_hmat_structure header;
	u8 flags;
	u8 data_type;
	u16 reserved1;
	u32 number_of_initiator_Pds;
	u32 number_of_target_Pds;
	u32 reserved2;
	u64 entry_base_unit;
};



#define ACPI_HMAT_MEMORY_HIERARCHY  (0x0F)



#define ACPI_HMAT_MEMORY            0
#define ACPI_HMAT_LAST_LEVEL_CACHE  1
#define ACPI_HMAT_1ST_LEVEL_CACHE   2
#define ACPI_HMAT_2ND_LEVEL_CACHE   3
#define ACPI_HMAT_3RD_LEVEL_CACHE   4



#define ACPI_HMAT_ACCESS_LATENCY    0
#define ACPI_HMAT_READ_LATENCY      1
#define ACPI_HMAT_WRITE_LATENCY     2
#define ACPI_HMAT_ACCESS_BANDWIDTH  3
#define ACPI_HMAT_READ_BANDWIDTH    4
#define ACPI_HMAT_WRITE_BANDWIDTH   5



struct acpi_hmat_cache {
	struct acpi_hmat_structure header;
	u32 memory_PD;
	u32 reserved1;
	u64 cache_size;
	u32 cache_attributes;
	u16 reserved2;
	u16 number_of_SMBIOShandles;
};



#define ACPI_HMAT_TOTAL_CACHE_LEVEL     (0x0000000F)
#define ACPI_HMAT_CACHE_LEVEL           (0x000000F0)
#define ACPI_HMAT_CACHE_ASSOCIATIVITY   (0x00000F00)
#define ACPI_HMAT_WRITE_POLICY          (0x0000F000)
#define ACPI_HMAT_CACHE_LINE_SIZE       (0xFFFF0000)



#define ACPI_HMAT_CA_NONE                     (0)
#define ACPI_HMAT_CA_DIRECT_MAPPED            (1)
#define ACPI_HMAT_CA_COMPLEX_CACHE_INDEXING   (2)



#define ACPI_HMAT_CP_NONE   (0)
#define ACPI_HMAT_CP_WB     (1)
#define ACPI_HMAT_CP_WT     (2)



struct acpi_table_madt {
	struct acpi_table_header header;	
	u32 address;		
	u32 flags;
};



#define ACPI_MADT_PCAT_COMPAT       (1)	



#define ACPI_MADT_DUAL_PIC          1
#define ACPI_MADT_MULTIPLE_APIC     0



enum acpi_madt_type {
	ACPI_MADT_TYPE_LOCAL_APIC = 0,
	ACPI_MADT_TYPE_IO_APIC = 1,
	ACPI_MADT_TYPE_INTERRUPT_OVERRIDE = 2,
	ACPI_MADT_TYPE_NMI_SOURCE = 3,
	ACPI_MADT_TYPE_LOCAL_APIC_NMI = 4,
	ACPI_MADT_TYPE_LOCAL_APIC_OVERRIDE = 5,
	ACPI_MADT_TYPE_IO_SAPIC = 6,
	ACPI_MADT_TYPE_LOCAL_SAPIC = 7,
	ACPI_MADT_TYPE_INTERRUPT_SOURCE = 8,
	ACPI_MADT_TYPE_LOCAL_X2APIC = 9,
	ACPI_MADT_TYPE_LOCAL_X2APIC_NMI = 10,
	ACPI_MADT_TYPE_GENERIC_INTERRUPT = 11,
	ACPI_MADT_TYPE_GENERIC_DISTRIBUTOR = 12,
	ACPI_MADT_TYPE_GENERIC_MSI_FRAME = 13,
	ACPI_MADT_TYPE_GENERIC_REDISTRIBUTOR = 14,
	ACPI_MADT_TYPE_GENERIC_TRANSLATOR = 15,
	ACPI_MADT_TYPE_RESERVED = 16	
};





struct acpi_madt_local_apic {
	struct acpi_subtable_header header;
	u8 processor_id;	
	u8 id;			
	u32 lapic_flags;
};



struct acpi_madt_io_apic {
	struct acpi_subtable_header header;
	u8 id;			
	u8 reserved;		
	u32 address;		
	u32 global_irq_base;	
};



struct acpi_madt_interrupt_override {
	struct acpi_subtable_header header;
	u8 bus;			
	u8 source_irq;		
	u32 global_irq;		
	u16 inti_flags;
};



struct acpi_madt_nmi_source {
	struct acpi_subtable_header header;
	u16 inti_flags;
	u32 global_irq;		
};



struct acpi_madt_local_apic_nmi {
	struct acpi_subtable_header header;
	u8 processor_id;	
	u16 inti_flags;
	u8 lint;		
};



struct acpi_madt_local_apic_override {
	struct acpi_subtable_header header;
	u16 reserved;		
	u64 address;		
};



struct acpi_madt_io_sapic {
	struct acpi_subtable_header header;
	u8 id;			
	u8 reserved;		
	u32 global_irq_base;	
	u64 address;		
};



struct acpi_madt_local_sapic {
	struct acpi_subtable_header header;
	u8 processor_id;	
	u8 id;			
	u8 eid;			
	u8 reserved[3];		
	u32 lapic_flags;
	u32 uid;		
	char uid_string[1];	
};



struct acpi_madt_interrupt_source {
	struct acpi_subtable_header header;
	u16 inti_flags;
	u8 type;		
	u8 id;			
	u8 eid;			
	u8 io_sapic_vector;	
	u32 global_irq;		
	u32 flags;		
};



#define ACPI_MADT_CPEI_OVERRIDE     (1)



struct acpi_madt_local_x2apic {
	struct acpi_subtable_header header;
	u16 reserved;		
	u32 local_apic_id;	
	u32 lapic_flags;
	u32 uid;		
};



struct acpi_madt_local_x2apic_nmi {
	struct acpi_subtable_header header;
	u16 inti_flags;
	u32 uid;		
	u8 lint;		
	u8 reserved[3];		
};



struct acpi_madt_generic_interrupt {
	struct acpi_subtable_header header;
	u16 reserved;		
	u32 cpu_interface_number;
	u32 uid;
	u32 flags;
	u32 parking_version;
	u32 performance_interrupt;
	u64 parked_address;
	u64 base_address;
	u64 gicv_base_address;
	u64 gich_base_address;
	u32 vgic_interrupt;
	u64 gicr_base_address;
	u64 arm_mpidr;
	u8 efficiency_class;
	u8 reserved2[3];
};




#define ACPI_MADT_PERFORMANCE_IRQ_MODE  (1<<1)	
#define ACPI_MADT_VGIC_IRQ_MODE         (1<<2)	



struct acpi_madt_generic_distributor {
	struct acpi_subtable_header header;
	u16 reserved;		
	u32 gic_id;
	u64 base_address;
	u32 global_irq_base;
	u8 version;
	u8 reserved2[3];	
};



enum acpi_madt_gic_version {
	ACPI_MADT_GIC_VERSION_NONE = 0,
	ACPI_MADT_GIC_VERSION_V1 = 1,
	ACPI_MADT_GIC_VERSION_V2 = 2,
	ACPI_MADT_GIC_VERSION_V3 = 3,
	ACPI_MADT_GIC_VERSION_V4 = 4,
	ACPI_MADT_GIC_VERSION_RESERVED = 5	
};



struct acpi_madt_generic_msi_frame {
	struct acpi_subtable_header header;
	u16 reserved;		
	u32 msi_frame_id;
	u64 base_address;
	u32 flags;
	u16 spi_count;
	u16 spi_base;
};



#define ACPI_MADT_OVERRIDE_SPI_VALUES   (1)



struct acpi_madt_generic_redistributor {
	struct acpi_subtable_header header;
	u16 reserved;		
	u64 base_address;
	u32 length;
};



struct acpi_madt_generic_translator {
	struct acpi_subtable_header header;
	u16 reserved;		
	u32 translation_id;
	u64 base_address;
	u32 reserved2;
};





#define ACPI_MADT_ENABLED           (1)	



#define ACPI_MADT_POLARITY_MASK     (3)	
#define ACPI_MADT_TRIGGER_MASK      (3<<2)	



#define ACPI_MADT_POLARITY_CONFORMS       0
#define ACPI_MADT_POLARITY_ACTIVE_HIGH    1
#define ACPI_MADT_POLARITY_RESERVED       2
#define ACPI_MADT_POLARITY_ACTIVE_LOW     3

#define ACPI_MADT_TRIGGER_CONFORMS        (0)
#define ACPI_MADT_TRIGGER_EDGE            (1<<2)
#define ACPI_MADT_TRIGGER_RESERVED        (2<<2)
#define ACPI_MADT_TRIGGER_LEVEL           (3<<2)



struct acpi_table_msct {
	struct acpi_table_header header;	
	u32 proximity_offset;	
	u32 max_proximity_domains;	
	u32 max_clock_domains;	
	u64 max_address;	
};



struct acpi_msct_proximity {
	u8 revision;
	u8 length;
	u32 range_start;	
	u32 range_end;		
	u32 processor_capacity;
	u64 memory_capacity;	
};



struct acpi_table_nfit {
	struct acpi_table_header header;	
	u32 reserved;		
};



struct acpi_nfit_header {
	u16 type;
	u16 length;
};



enum acpi_nfit_type {
	ACPI_NFIT_TYPE_SYSTEM_ADDRESS = 0,
	ACPI_NFIT_TYPE_MEMORY_MAP = 1,
	ACPI_NFIT_TYPE_INTERLEAVE = 2,
	ACPI_NFIT_TYPE_SMBIOS = 3,
	ACPI_NFIT_TYPE_CONTROL_REGION = 4,
	ACPI_NFIT_TYPE_DATA_REGION = 5,
	ACPI_NFIT_TYPE_FLUSH_ADDRESS = 6,
	ACPI_NFIT_TYPE_RESERVED = 7	
};





struct acpi_nfit_system_address {
	struct acpi_nfit_header header;
	u16 range_index;
	u16 flags;
	u32 reserved;		
	u32 proximity_domain;
	u8 range_guid[16];
	u64 address;
	u64 length;
	u64 memory_mapping;
};



#define ACPI_NFIT_ADD_ONLINE_ONLY       (1)	
#define ACPI_NFIT_PROXIMITY_VALID       (1<<1)	





struct acpi_nfit_memory_map {
	struct acpi_nfit_header header;
	u32 device_handle;
	u16 physical_id;
	u16 region_id;
	u16 range_index;
	u16 region_index;
	u64 region_size;
	u64 region_offset;
	u64 address;
	u16 interleave_index;
	u16 interleave_ways;
	u16 flags;
	u16 reserved;		
};



#define ACPI_NFIT_MEM_SAVE_FAILED       (1)	
#define ACPI_NFIT_MEM_RESTORE_FAILED    (1<<1)	
#define ACPI_NFIT_MEM_FLUSH_FAILED      (1<<2)	
#define ACPI_NFIT_MEM_NOT_ARMED         (1<<3)	
#define ACPI_NFIT_MEM_HEALTH_OBSERVED   (1<<4)	
#define ACPI_NFIT_MEM_HEALTH_ENABLED    (1<<5)	
#define ACPI_NFIT_MEM_MAP_FAILED        (1<<6)	



struct acpi_nfit_interleave {
	struct acpi_nfit_header header;
	u16 interleave_index;
	u16 reserved;		
	u32 line_count;
	u32 line_size;
	u32 line_offset[1];	
};



struct acpi_nfit_smbios {
	struct acpi_nfit_header header;
	u32 reserved;		
	u8 data[1];		
};



struct acpi_nfit_control_region {
	struct acpi_nfit_header header;
	u16 region_index;
	u16 vendor_id;
	u16 device_id;
	u16 revision_id;
	u16 subsystem_vendor_id;
	u16 subsystem_device_id;
	u16 subsystem_revision_id;
	u8 valid_fields;
	u8 manufacturing_location;
	u16 manufacturing_date;
	u8 reserved[2];		
	u32 serial_number;
	u16 code;
	u16 windows;
	u64 window_size;
	u64 command_offset;
	u64 command_size;
	u64 status_offset;
	u64 status_size;
	u16 flags;
	u8 reserved1[6];	
};



#define ACPI_NFIT_CONTROL_BUFFERED          (1)	



#define ACPI_NFIT_CONTROL_MFG_INFO_VALID    (1)	



struct acpi_nfit_data_region {
	struct acpi_nfit_header header;
	u16 region_index;
	u16 windows;
	u64 offset;
	u64 size;
	u64 capacity;
	u64 start_address;
};



struct acpi_nfit_flush_address {
	struct acpi_nfit_header header;
	u32 device_handle;
	u16 hint_count;
	u8 reserved[6];		
	u64 hint_address[1];	
};



struct acpi_table_pptt {
	struct acpi_table_header header;	
};



enum acpi_pptt_type {
	ACPI_PPTT_TYPE_PROCESSOR = 0,
	ACPI_PPTT_TYPE_CACHE = 1,
	ACPI_PPTT_TYPE_ID = 2,
	ACPI_PPTT_TYPE_RESERVED = 3
};



struct acpi_pptt_processor {
	struct acpi_subtable_header header;
	u16 reserved;
	u32 flags;
	u32 parent;
	u32 acpi_processor_id;
	u32 number_of_priv_resources;
};



#define ACPI_PPTT_PHYSICAL_PACKAGE          (1)	
#define ACPI_PPTT_ACPI_PROCESSOR_ID_VALID   (2)	



struct acpi_pptt_cache {
	struct acpi_subtable_header header;
	u16 reserved;
	u32 flags;
	u32 next_level_of_cache;
	u32 size;
	u32 number_of_sets;
	u8 associativity;
	u8 attributes;
	u16 line_size;
};



#define ACPI_PPTT_SIZE_PROPERTY_VALID       (1)	
#define ACPI_PPTT_NUMBER_OF_SETS_VALID      (1<<1)	
#define ACPI_PPTT_ASSOCIATIVITY_VALID       (1<<2)	
#define ACPI_PPTT_ALLOCATION_TYPE_VALID     (1<<3)	
#define ACPI_PPTT_CACHE_TYPE_VALID          (1<<4)	
#define ACPI_PPTT_WRITE_POLICY_VALID        (1<<5)	
#define ACPI_PPTT_LINE_SIZE_VALID           (1<<6)	



#define ACPI_PPTT_MASK_ALLOCATION_TYPE      (0x03)	
#define ACPI_PPTT_MASK_CACHE_TYPE           (0x0C)	
#define ACPI_PPTT_MASK_WRITE_POLICY         (0x10)	



struct acpi_pptt_id {
	struct acpi_subtable_header header;
	u16 reserved;
	u32 vendor_id;
	u64 level1_id;
	u64 level2_id;
	u16 major_rev;
	u16 minor_rev;
	u16 spin_rev;
};



struct acpi_table_sbst {
	struct acpi_table_header header;	
	u32 warning_level;
	u32 low_level;
	u32 critical_level;
};



struct acpi_table_slit {
	struct acpi_table_header header;	
	u64 locality_count;
	u8 entry[1];		
};



struct acpi_table_srat {
	struct acpi_table_header header;	
	u32 table_revision;	
	u64 reserved;		
};



enum acpi_srat_type {
	ACPI_SRAT_TYPE_CPU_AFFINITY = 0,
	ACPI_SRAT_TYPE_MEMORY_AFFINITY = 1,
	ACPI_SRAT_TYPE_X2APIC_CPU_AFFINITY = 2,
	ACPI_SRAT_TYPE_GICC_AFFINITY = 3,
	ACPI_SRAT_TYPE_GIC_ITS_AFFINITY = 4,	
	ACPI_SRAT_TYPE_RESERVED = 5	
};





struct acpi_srat_cpu_affinity {
	struct acpi_subtable_header header;
	u8 proximity_domain_lo;
	u8 apic_id;
	u32 flags;
	u8 local_sapic_eid;
	u8 proximity_domain_hi[3];
	u32 clock_domain;
};



#define ACPI_SRAT_CPU_USE_AFFINITY  (1)	



struct acpi_srat_mem_affinity {
	struct acpi_subtable_header header;
	u32 proximity_domain;
	u16 reserved;		
	u64 base_address;
	u64 length;
       u32 reserved1;
	u32 flags;
       u64 reserved2;	       
};



#define ACPI_SRAT_MEM_ENABLED       (1)	
#define ACPI_SRAT_MEM_HOT_PLUGGABLE (1<<1)	
#define ACPI_SRAT_MEM_NON_VOLATILE  (1<<2)	



struct acpi_srat_x2apic_cpu_affinity {
	struct acpi_subtable_header header;
	u16 reserved;		
	u32 proximity_domain;
	u32 apic_id;
	u32 flags;
	u32 clock_domain;
	u32 reserved2;
};



#define ACPI_SRAT_CPU_ENABLED       (1)	



struct acpi_srat_gicc_affinity {
	struct acpi_subtable_header header;
	u32 proximity_domain;
	u32 acpi_processor_uid;
	u32 flags;
	u32 clock_domain;
};



#define ACPI_SRAT_GICC_ENABLED     (1)	



struct acpi_srat_gic_its_affinity {
	struct acpi_subtable_header header;
	u32 proximity_domain;
	u16 reserved;
	u32 its_id;
};



#pragma pack()

#endif				
