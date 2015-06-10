
ENTRY(start)
OUTPUT_FORMAT(elf32-i386)
KERNEL_MBOOT = 0x400;
KERNEL_VMA_LOW    = 0x00100000;
KERNEL_VMA_LOW_1  = 0x00100010;
KERNEL_VMA_HIGH   = 0xC0000000;
KERNEL_LMA_OFFSET = 0xBFEFFF00;

SECTIONS
{
  /*. = KERNEL_MBOOT;*/

  . = KERNEL_VMA_LOW; 

  .mboot : AT( ADDR(.mboot) )
  {
     *(.mboot)
  }

  . = KERNEL_VMA_LOW_1;

  .init : AT( ADDR(.init) )
  {
    *(.init) 
  }

  . = KERNEL_VMA_HIGH;

  .text : AT((ADDR(.text) - KERNEL_LMA_OFFSET))
  {
    code = .; _code = .; __code = .;
    *(.text)
    *(.rodata*)
  }

  .data ALIGN (0x1000) : AT((ADDR(.data) - KERNEL_LMA_OFFSET))
  {
     data = .; _data = .; __data = .;
     *(.data)
     *(.rodata)
  }

  .bss : AT((ADDR(.bss) - KERNEL_LMA_OFFSET))
  {
    bss = .; _bss = .; __bss = .;
    *(.bss)
    *(COMMON)
    ebss = .;
  }

  end = .; _end = .; __end = .;
} 
