
; TODO: macro-ize this file.

[BITS 32]

section .text

[GLOBAL cpu_test_long_mode]
[GLOBAL cpu_test_vtx]

; return in eax 0 if not long mode,
; and something else otherwise.
cpu_test_long_mode:
    ; ask for cpu features:
    mov eax, DWORD 1
    cpuid

    ; test for bit 29 (long mode) in edx
    mov eax, DWORD 0x20000000
    xor eax, edx
    ret

cpu_test_vtx:
    ; ask for cpu features:
    mov eax, DWORD 1
    cpuid

    ; test for bit 29 (long mode) in edx
    mov eax, DWORD 0x20000000
    xor eax, edx
    ret
    
