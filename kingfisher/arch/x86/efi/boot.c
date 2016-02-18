
#include <kingfisher/kingfisher.h>
#include <kingfisher/efi/uefi.h>

void EFIAPI SECTION_INIT_TEXT NORETURN uefi_start(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE * SystemTable)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"KINGFISHER EFI KERNEL BOOTSTRAP");
    while (1)
    {
        SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Kernel Booted.");
    }
}
