
[BITS 64]

[GLOBAL longmode]
[GLOBAL x64_entry]

longmode:
     ; ensure paging is disabled:

     ; set PAE enable bit in CR4
     mov eax, cr4
     or  eax, 1 << 5
     mov cr4, eax

     ; load CR3 with PML4:
     mov eax, ?
     mov cr3, eax

     ; switch to long mode
     ; set EFER.LME flag in MSR 0xC0000080 
     mov eax, 1 << 8
     mov ecx, 0xC0000080 ; 
     wrmsr

     ; enable paging, prepare for long mode
     mov eax, cr0
     or  eax, 1 << 31
     or  eax, 1
     mov cr0, eax

     ; now in long mode but in compatibility mode
     ; underneath that. 
     ; load up a 64-bit GDT:
     lgdt <64-bit GDT address>

     ; and off we go:
     jmp  GDT_CODE_SEG:x64_entry

x64_entry:
     
     cli
     ; need to set up our own interrupts.

