/*

Copyright (c) 2004 - 2007, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  

*/

#ifndef EFI_BOOT_SERVICES_TABLE_H
#define EFI_BOOT_SERVICES_TABLE_H

typedef struct _EFI_BOOT_SERVICES EFI_BOOT_SERVICES;

#include "bootservices.h"

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42ULL

struct _EFI_BOOT_SERVICES {
  EFI_TABLE_HEADER                            Hdr;

  //
  // Task priority functions
  //
  EFI_RAISE_TPL                               RaiseTPL;
  EFI_RESTORE_TPL                             RestoreTPL;

  //
  // Memory functions
  //
  EFI_ALLOCATE_PAGES                          AllocatePages;
  EFI_FREE_PAGES                              FreePages;
  EFI_GET_MEMORY_MAP                          GetMemoryMap;
  EFI_ALLOCATE_POOL                           AllocatePool;
  EFI_FREE_POOL                               FreePool;

  //
  // Event & timer functions
  //
  EFI_CREATE_EVENT                            CreateEvent;
  EFI_SET_TIMER                               SetTimer;
  EFI_WAIT_FOR_EVENT                          WaitForEvent;
  EFI_SIGNAL_EVENT                            SignalEvent;
  EFI_CLOSE_EVENT                             CloseEvent;
  EFI_CHECK_EVENT                             CheckEvent;

  //
  // Protocol handler functions
  //
  EFI_INSTALL_PROTOCOL_INTERFACE              InstallProtocolInterface;
  EFI_REINSTALL_PROTOCOL_INTERFACE            ReinstallProtocolInterface;
  EFI_UNINSTALL_PROTOCOL_INTERFACE            UninstallProtocolInterface;
  EFI_HANDLE_PROTOCOL                         HandleProtocol;
  VOID                                        *Reserved;
  EFI_REGISTER_PROTOCOL_NOTIFY                RegisterProtocolNotify;
  EFI_LOCATE_HANDLE                           LocateHandle;
  EFI_LOCATE_DEVICE_PATH                      LocateDevicePath;
  EFI_INSTALL_CONFIGURATION_TABLE             InstallConfigurationTable;

  //
  // Image functions
  //
  EFI_IMAGE_LOAD                              LoadImage;
  EFI_IMAGE_START                             StartImage;
  EFI_EXIT                                    Exit;
  EFI_IMAGE_UNLOAD                            UnloadImage;
  EFI_EXIT_BOOT_SERVICES                      ExitBootServices;

  //
  // Misc functions
  //
  EFI_GET_NEXT_MONOTONIC_COUNT                GetNextMonotonicCount;
  EFI_STALL                                   Stall;
  EFI_SET_WATCHDOG_TIMER                      SetWatchdogTimer;

  //
  // ////////////////////////////////////////////////////
  // EFI 1.1 Services
    //////////////////////////////////////////////////////
  //
  // DriverSupport Services
  //
  EFI_CONNECT_CONTROLLER                      ConnectController;
  EFI_DISCONNECT_CONTROLLER                   DisconnectController;

  //
  // Added Open and Close protocol for the new driver model
  //
  EFI_OPEN_PROTOCOL                           OpenProtocol;
  EFI_CLOSE_PROTOCOL                          CloseProtocol;
  EFI_OPEN_PROTOCOL_INFORMATION               OpenProtocolInformation;

  //
  // Added new services to EFI 1.1 as Lib to reduce code size.
  //
  EFI_PROTOCOLS_PER_HANDLE                    ProtocolsPerHandle;
  EFI_LOCATE_HANDLE_BUFFER                    LocateHandleBuffer;
  EFI_LOCATE_PROTOCOL                         LocateProtocol;

  EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES    InstallMultipleProtocolInterfaces;
  EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES  UninstallMultipleProtocolInterfaces;

  //
  // CRC32 services
  //
  EFI_CALCULATE_CRC32                         CalculateCrc32;

  //
  // Memory Utility Services
  //
  EFI_COPY_MEM                                CopyMem;
  EFI_SET_MEM                                 SetMem;
#if (EFI_SPECIFICATION_VERSION >= 0x00020000)
  //
  // UEFI 2.0 Extension to the table
  //
  EFI_CREATE_EVENT_EX                         CreateEventEx;
#endif

};

#endif