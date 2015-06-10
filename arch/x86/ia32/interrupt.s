
[BITS 32]

%macro ISR_HANDLER_NOERROR 1

[GLOBAL isr%1]
isr%1:
    cli
    push byte 0
    push byte %1
    jmp  isr_handler_entry

%endmacro

%macro ISR_HANDLER_ERROR 1

[GLOBAL isr%1]
isr%1:
    cli
    push byte %1
    jmp  isr_handler_entry

%endmacro

isr_handler_entry:
    ; save processor state on the stack
    pusha


    mov  ax, ds
    push eax

    ; switch selectors to the kernel
    mov  ax, 0x10
    mov  ds, ax
    mov  es, ax
    mov  fs, ax
    mov  gs, ax

    ; call the handler:
    call  HANDLER!

    pop eax
    mov ds, ax
    mov es, ex
    mov fs, ax
    mov gs, ax

    popa
    add esp, 8
    sti
    iret


ISR_HANDLER_NOERROR  0
ISR_HANDLER_NOERROR  1
ISR_HANDLER_NOERROR  2
ISR_HANDLER_NOERROR  3
ISR_HANDLER_NOERROR  4
ISR_HANDLER_NOERROR  5
ISR_HANDLER_NOERROR  6
ISR_HANDLER_NOERROR  7
ISR_HANDLER_ERROR    8
ISR_HANDLER_NOERROR  9
ISR_HANDLER_ERROR   10
ISR_HANDLER_ERROR   11
ISR_HANDLER_ERROR   12
ISR_HANDLER_ERROR   13
ISR_HANDLER_ERROR   14
ISR_HANDLER_NOERROR 15
ISR_HANDLER_NOERROR 16
ISR_HANDLER_NOERROR 17
ISR_HANDLER_NOERROR 18
ISR_HANDLER_NOERROR 19

