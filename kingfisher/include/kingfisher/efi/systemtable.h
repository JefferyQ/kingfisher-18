/*

Significant portions of this header are:
Copyright (c) 2004 - 2007, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  

*/

#ifndef EFI_SYSTEM_TABLE_H
#define EFI_SYSTEM_TABLE_H

typedef struct {
  UINT64  Signature;
  UINT32  Revision;
  UINT32  HeaderSize;
  UINT32  CRC32;
  UINT32  Reserved;
} EFI_TABLE_HEADER;

typedef struct _EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;

#define EFI_BOOTSERVICE
#define EFI_BOOTSERVICE11
#define EFI_RUNTIMESERVICE

#include "simplein.h"
#include "simpleout.h"
#include "bootservicetable.h"
#include "runtimeservicetable.h"

typedef struct {
  EFI_GUID                          VendorGuid;
  VOID                              *VendorTable;
} EFI_CONFIGURATION_TABLE;

struct _EFI_SYSTEM_TABLE {
  EFI_TABLE_HEADER              Hdr;

  CHAR16                        *FirmwareVendor;
  UINT32                        FirmwareRevision;

  EFI_HANDLE                    ConsoleInHandle;
  EFI_SIMPLE_TEXT_IN_PROTOCOL   *ConIn;

  EFI_HANDLE                    ConsoleOutHandle;
  EFI_SIMPLE_TEXT_OUT_PROTOCOL  *ConOut;

  EFI_HANDLE                    StandardErrorHandle;
  EFI_SIMPLE_TEXT_OUT_PROTOCOL  *StdErr;

  EFI_RUNTIME_SERVICES          *RuntimeServices;
  EFI_BOOT_SERVICES             *BootServices;

  UINTN                         NumberOfTableEntries;
  EFI_CONFIGURATION_TABLE       *ConfigurationTable;

};

#endif