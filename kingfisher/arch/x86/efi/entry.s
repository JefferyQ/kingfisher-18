
[BITS 64]

[extern uefi_start]
[global _start]

[SECTION .init.text]

_start:
    call uefi_start
