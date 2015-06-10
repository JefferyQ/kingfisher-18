
/*
 

 */

#ifndef KF_DESCRIPTORS_H
#define KD_GDT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _gpt_register_t
{
    uint16_t   limit;
    void*      address;
} gpt_register_t __attribute__((packed));

typedef struct _idt_register_t
{
    uint16_t   limit;
    void*      address;
} idt_register;

typedef struct _gdt_entry_t
{
    uint16_t   limit_lower;
    uint16_t   base_lower;
    uint8_t    base_middle;
    uint8_t    access;
    uint8_t    granularity;
    uint8_t    base_higher;
} gdt_entry_t __attribute__((packed));


typedef struct _idt_entry_32_t
{
    uint16_t   base_lower;
    uint16_t   segment_selector;
    uint8_t    reserved0;
    uint8_t    flags;
    uint8_t    base_high;
} idt_entry_32_t __attribute__((packed));

typedef struct _idt_entry_64_t
{
    uint64_t   base_lower;
    uint64_t   segment_selector;
    uint8_t    reserved0;
    uint8_t    flags;
    uint16_t   base_middle;
    uint32_t   base_high;
} idt_entry_64_t __attribute__((packed));

#ifdef __cplusplus
};
#endif

#endif
