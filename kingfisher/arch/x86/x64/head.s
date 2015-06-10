
[BITS 32]

[GLOBAL start]
[GLOBAL multiboot]

; external references to executable sections
[EXTERN kingfisher_start32]
[EXTERN code]
[EXTERN bss]
[EXTERN end]

STACKSIZE equ 0x4000

; multiboot 1.0 header.
[section .mboot]
align 4

multiboot:

; multiboot specification items
MULTIBOOT_MAGIC             equ 0x1BADB002
MULTIBOOT_FLAG_MEM_INFO     equ 1<<1
MULTIBOOT_FLAG_PAGE_ALIGN   equ 1<<0
MULTIBOOT_FLAGS             equ MULTIBOOT_FLAG_PAGE_ALIGN | MULTIBOOT_FLAG_MEM_INFO
MULTIBOOT_CHECKSUM          equ - (MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)
 
; multiboot information

    dd MULTIBOOT_MAGIC                  ; magic
    dd MULTIBOOT_FLAGS                  ; required + optional flags
    dd MULTIBOOT_CHECKSUM               ; checksum

section .data
align 0x1000

    db 0x6B, 0x69, 0x6E, 0x67, 0x66, 0x69, 0x73, 0x68, 0x65, 0x72

section .bss
align 32
    resb STACKSIZE


section .init32

start:
    cld
    cli
    jmp kingfisher_start32
