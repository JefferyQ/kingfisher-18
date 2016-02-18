

OUTPUT_FORMAT(pei-x86-64)
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

BASE = 0x10;

KERNEL_VMA_MBOOT        = 0x0000000000100000;
KERNEL_LMA_MBOOT_OFFSET = 0x00000000000FFC00;
KERNEL_VMA_LOW          = 0x0000000000100010;
KERNEL_VMA_HIGH         = 0xffffffff00000000;
KERNEL_LMA_OFFSET_HIGH  = 0xFFFFFFFEFFEFFF00;

PHDRS
{
    mboot PT_LOAD;
    init.text PT_LOAD;
    init.data PT_LOAD;
    text PT_LOAD;
    data PT_LOAD;
    bss PT_LOAD;
}

SECTIONS
{
  . = KERNEL_VMA_LOW;

  .init.text : AT( ADDR(.init.text) )
  {
    init.text = .; _init.text = .; __init.text = .;
  } : text

  .init.data : AT( ADDR(.init.data) )
  {
    init.data = .; _init.data = .; __init.data = .;
  } : data

  . = KERNEL_VMA_HIGH;

  .text : AT(ADDR(.text) - KERNEL_LMA_OFFSET_HIGH)
  {
    code = .; _code = .; __code = .;
    *(EXCLUDE_FILE(build/arch/x86/boot.o) .text)
    *(.rodata*)
  } : text

  .data ALIGN (0x1000) : AT(ADDR(.data) - KERNEL_LMA_OFFSET_HIGH)
  {
     data = .; _data = .; __data = .;
     bss = .; _bss = .; __bss = .;
     *(.data)
     *(.rodata)
     *(.bss)
  } : data

  . = ALIGN(4);
  .reloc : {
    *(.reloc)
  } : text


  /DISCARD/ : {
       *(.comment)
       *(.comment.*)
  }

  end = .; _end = .; __end = .;
}
