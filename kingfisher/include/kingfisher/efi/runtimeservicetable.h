/*

Copyright (c) 2004 - 2007, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  

*/

#ifndef EFI_RUNTIME_SERVICES_TABLE_H
#define EFI_RUNTIME_SERVICES_TABLE_H

typedef struct _EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

#include "runtimeservices.h"

#define EFI_RUNTIME_SERVICES_SIGNATURE  0x56524553544e5552ULL

struct _EFI_RUNTIME_SERVICES {
  EFI_TABLE_HEADER              Hdr;

  //
  // Time services
  //
  EFI_GET_TIME                  GetTime;
  EFI_SET_TIME                  SetTime;
  EFI_GET_WAKEUP_TIME           GetWakeupTime;
  EFI_SET_WAKEUP_TIME           SetWakeupTime;

  //
  // Virtual memory services
  //
  EFI_SET_VIRTUAL_ADDRESS_MAP   SetVirtualAddressMap;
  EFI_CONVERT_POINTER           ConvertPointer;

  //
  // Variable services
  //
  EFI_GET_VARIABLE              GetVariable;
  EFI_GET_NEXT_VARIABLE_NAME    GetNextVariableName;
  EFI_SET_VARIABLE              SetVariable;

  //
  // Misc
  //
  EFI_GET_NEXT_HIGH_MONO_COUNT  GetNextHighMonotonicCount;
  EFI_RESET_SYSTEM              ResetSystem;

#if (EFI_SPECIFICATION_VERSION >= 0x00020000)
  //
  // New Boot Service added by UEFI 2.0
  //
  EFI_UPDATE_CAPSULE             UpdateCapsule;
  EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
  EFI_QUERY_VARIABLE_INFO        QueryVariableInfo;
#elif (TIANO_RELEASE_VERSION != 0)
  //
  // Tiano extension to EFI 1.10 runtime table
  // It was moved to a protocol to not conflict with UEFI 2.0
  // If Tiano is disabled, this item is not enabled for EFI1.10
  //
  EFI_REPORT_STATUS_CODE        ReportStatusCode;
#endif

};


#endif