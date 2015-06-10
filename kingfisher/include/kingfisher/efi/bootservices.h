/*

Copyright (c) 2004 - 2007, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  

*/

#ifndef EFI_BOOT_SERVICES_H
#define EFI_BOOT_SERVICES_H


typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_ALLOCATE_PAGES) (
  IN EFI_ALLOCATE_TYPE            Type,
  IN EFI_MEMORY_TYPE              MemoryType,
  IN UINTN                        NoPages,
  OUT EFI_PHYSICAL_ADDRESS        * Memory
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_FREE_PAGES) (
  IN EFI_PHYSICAL_ADDRESS         Memory,
  IN UINTN                        NoPages
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_GET_MEMORY_MAP) (
  IN OUT UINTN                    *MemoryMapSize,
  IN OUT EFI_MEMORY_DESCRIPTOR    * MemoryMap,
  OUT UINTN                       *MapKey,
  OUT UINTN                       *DescriptorSize,
  OUT UINT32                      *DescriptorVersion
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_ALLOCATE_POOL) (
  IN EFI_MEMORY_TYPE              PoolType,
  IN UINTN                        Size,
  OUT VOID                        **Buffer
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_FREE_POOL) (
  IN VOID                         *Buffer
  );



typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_CREATE_EVENT) (
  IN UINT32                       Type,
  IN EFI_TPL                      NotifyTpl,
  IN EFI_EVENT_NOTIFY             NotifyFunction,
  IN VOID                         *NotifyContext,
  OUT EFI_EVENT                   * Event
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_CREATE_EVENT_EX) (
  IN UINT32                 Type,
  IN EFI_TPL                NotifyTpl      OPTIONAL,
  IN EFI_EVENT_NOTIFY       NotifyFunction OPTIONAL,
  IN CONST VOID             *NotifyContext OPTIONAL,
  IN CONST EFI_GUID         *EventGroup    OPTIONAL,
  OUT EFI_EVENT             *Event
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_SET_TIMER) (
  IN EFI_EVENT                Event,
  IN EFI_TIMER_DELAY          Type,
  IN UINT64                   TriggerTime
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_SIGNAL_EVENT) (
  IN EFI_EVENT                Event
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_WAIT_FOR_EVENT) (
  IN UINTN                    NumberOfEvents,
  IN EFI_EVENT                * Event,
  OUT UINTN                   *Index
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_CLOSE_EVENT) (
  IN EFI_EVENT                Event
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_CHECK_EVENT) (
  IN EFI_EVENT                Event
  );



//
// Task priority level
//
#define EFI_TPL_APPLICATION 4
#define EFI_TPL_CALLBACK    8
#define EFI_TPL_NOTIFY      16
#define EFI_TPL_HIGH_LEVEL  31

typedef
EFI_BOOTSERVICE
EFI_TPL
(EFIAPI *EFI_RAISE_TPL) (
  IN EFI_TPL      NewTpl
  );

typedef
EFI_BOOTSERVICE
VOID
(EFIAPI *EFI_RESTORE_TPL) (
  IN EFI_TPL      OldTpl
  );


typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_IMAGE_LOAD) (
  IN BOOLEAN                      BootPolicy,
  IN EFI_HANDLE                   ParentImageHandle,
  IN EFI_DEVICE_PATH_PROTOCOL     * FilePath,
  IN VOID                         *SourceBuffer OPTIONAL,
  IN UINTN                        SourceSize,
  OUT EFI_HANDLE                  * ImageHandle
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_IMAGE_START) (
  IN EFI_HANDLE                   ImageHandle,
  OUT UINTN                       *ExitDataSize,
  OUT CHAR16                      **ExitData OPTIONAL
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_EXIT) (
  IN EFI_HANDLE                   ImageHandle,
  IN EFI_STATUS                   ExitStatus,
  IN UINTN                        ExitDataSize,
  IN CHAR16                       *ExitData OPTIONAL
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_IMAGE_UNLOAD) (
  IN EFI_HANDLE                   ImageHandle
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_EXIT_BOOT_SERVICES) (
  IN EFI_HANDLE                   ImageHandle,
  IN UINTN                        MapKey
  );

//
// Misc
//
typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_STALL) (
  IN UINTN                    Microseconds
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_SET_WATCHDOG_TIMER) (
  IN UINTN                    Timeout,
  IN UINT64                   WatchdogCode,
  IN UINTN                    DataSize,
  IN CHAR16                   *WatchdogData OPTIONAL
  );


typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT) (
  OUT UINT64                  *Count
  );

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT) (
  OUT UINT32                  *HighCount
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_CALCULATE_CRC32) (
  IN  VOID                              *Data,
  IN  UINTN                             DataSize,
  OUT UINT32                            *Crc32
  );

typedef
EFI_BOOTSERVICE
VOID
(EFIAPI *EFI_COPY_MEM) (
  IN VOID     *Destination,
  IN VOID     *Source,
  IN UINTN    Length
  );

typedef
EFI_BOOTSERVICE
VOID
(EFIAPI *EFI_SET_MEM) (
  IN VOID     *Buffer,
  IN UINTN    Size,
  IN UINT8    Value
  );

//
// Protocol handler functions
//
typedef enum {
  EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE) (
  IN OUT EFI_HANDLE           * Handle,
  IN EFI_GUID                 * Protocol,
  IN EFI_INTERFACE_TYPE       InterfaceType,
  IN VOID                     *Interface
  );


typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE) (
  IN EFI_HANDLE               Handle,
  IN EFI_GUID                 * Protocol,
  IN VOID                     *OldInterface,
  IN VOID                     *NewInterface
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE) (
  IN EFI_HANDLE               Handle,
  IN EFI_GUID                 * Protocol,
  IN VOID                     *Interface
  );

typedef
EFI_BOOTSERVICE
EFI_STATUS
(EFIAPI *EFI_HANDLE_PROTOCOL) (
  IN EFI_HANDLE               Handle,
  IN EFI_GUID                 * Protocol,
  OUT VOID                    **Interface
  );




typedef
EFI_BOOTSERVICE11
EFI_STATUS
(EFIAPI *EFI_CONNECT_CONTROLLER) (
  IN  EFI_HANDLE                    ControllerHandle,
  IN  EFI_HANDLE                    * DriverImageHandle OPTIONAL,
  IN  EFI_DEVICE_PATH_PROTOCOL      * RemainingDevicePath OPTIONAL,
  IN  BOOLEAN                       Recursive
  );

typedef
EFI_BOOTSERVICE11
EFI_STATUS
(EFIAPI *EFI_DISCONNECT_CONTROLLER) (
  IN EFI_HANDLE                              ControllerHandle,
  IN EFI_HANDLE                              DriverImageHandle, OPTIONAL
  IN EFI_HANDLE                              ChildHandle        OPTIONAL
  );

typedef
EFI_BOOTSERVICE11
EFI_STATUS
(EFIAPI *EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
  IN OUT EFI_HANDLE           * Handle,
  ...
  );

typedef
EFI_BOOTSERVICE11
EFI_STATUS
(EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
  IN EFI_HANDLE           Handle,
  ...
  );

#endif