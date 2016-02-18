
Rough Dev plan
==============

This file contains the outline plan for what we want to work on:

Booting & Image Support:
------------------------

 * No IA32 support.
 * BIOS to x64:
    * Multiboot kernel, ELF64.
    * Assume 32-bit boot start, make our own way to long mode.
    * Probably get rid of VMA. We will ignore the loader's tables.
 * EFI x86_64:
    * Need to work out the correct build procedure. NOT using gnu-efi - what is Xen doing?
    * Get rid of entry.s, it doesn't work.
    * Work out runtime issues like `L""` strings.
