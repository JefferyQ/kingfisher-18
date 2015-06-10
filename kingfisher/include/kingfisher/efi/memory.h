/*

Copyright (c) 2004 - 2007, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  

*/

#ifndef EFI_MEMORY_H
#define EFI_MEMORY_H

typedef UINTN                     EFI_TPL;
typedef UINT64                    EFI_LBA;
typedef UINT16                    STRING_REF;
typedef UINT64                    EFI_PHYSICAL_ADDRESS;
typedef UINT64                    EFI_VIRTUAL_ADDRESS;

typedef enum {
  EfiReservedMemoryType,
  EfiLoaderCode,
  EfiLoaderData,
  EfiBootServicesCode,
  EfiBootServicesData,
  EfiRuntimeServicesCode,
  EfiRuntimeServicesData,
  EfiConventionalMemory,
  EfiUnusableMemory,
  EfiACPIReclaimMemory,
  EfiACPIMemoryNVS,
  EfiMemoryMappedIO,
  EfiMemoryMappedIOPortSpace,
  EfiPalCode,
  EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef struct {
  UINT32                Type;
  EFI_PHYSICAL_ADDRESS  PhysicalStart;
  EFI_VIRTUAL_ADDRESS   VirtualStart;
  UINT64                NumberOfPages;
  UINT64                Attribute;
} EFI_MEMORY_DESCRIPTOR;

///
/// Enumeration of EFI memory allocation types.
///
typedef enum {
  AllocateAnyPages,
  AllocateMaxAddress,
  AllocateAddress,
  MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef
EFI_STATUS
(EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP)(
  IN  UINTN                        MemoryMapSize,
  IN  UINTN                        DescriptorSize,
  IN  UINT32                       DescriptorVersion,
  IN  EFI_MEMORY_DESCRIPTOR        *VirtualMap
  );

#endif