
OUTPUT_FORMAT(elf64-x86-64)
OUTPUT_ARCH(i386:x86-64)
ENTRY(start)

BASE = 0x10;

KERNEL_MBOOT            = 0x400;
KERNEL_VMA_MBOOT        = 0x0000000000100000;
KERNEL_LMA_MBOOT_OFFSET = 0x00000000000FFC00;
KERNEL_VMA_LOW          = 0x0000000000100010;
KERNEL_VMA_HIGH         = 0xffffffff00000000;
KERNEL_LMA_OFFSET_HIGH  = 0xFFFFFFFEFFEFFF00;

PHDRS
{
    mboot PT_LOAD;
    init PT_LOAD;
    text PT_LOAD;
    data PT_LOAD;
    bss PT_LOAD;
}

SECTIONS
{
  . = KERNEL_MBOOT;

  .mboot : AT( ADDR(.mboot) + KERNEL_LMA_MBOOT_OFFSET) 
  {
     *(.mboot)
  } : mboot

  . = KERNEL_VMA_LOW;

  .init32 : AT( ADDR(.init32) )
  {
      build/arch/x86/boot.o (.init)
  } : init

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
     *(.data)
     *(.rodata) 
  } : data

  .bss : AT(ADDR(.bss) - KERNEL_LMA_OFFSET_HIGH)
  {
    bss = .; _bss = .; __bss = .;
    *(.bss)
  } : bss

  end = .; _end = .; __end = .;
} 
