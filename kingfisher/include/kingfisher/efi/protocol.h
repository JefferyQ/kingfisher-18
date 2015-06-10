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

#ifndef EFI_PROTOCOL_H
#define EFI_PROTOCOL_H

typedef struct {
  EFI_HANDLE  AgentHandle;
  EFI_HANDLE  ControllerHandle;
  UINT32      Attributes;
  UINT32      OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef enum {
  AllHandles,
  ByRegisterNotify,
  ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_PROTOCOL)(
  IN  EFI_GUID  *Protocol,
  IN  VOID      *Registration, OPTIONAL
  OUT VOID      **Interface
  );

typedef
EFI_STATUS
(EFIAPI *EFI_PROTOCOLS_PER_HANDLE)(
  IN  EFI_HANDLE      Handle,
  OUT EFI_GUID        ***ProtocolBuffer,
  OUT UINTN           *ProtocolBufferCount
  );

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE)(
  IN     EFI_LOCATE_SEARCH_TYPE   SearchType,
  IN     EFI_GUID                 *Protocol,    OPTIONAL
  IN     VOID                     *SearchKey,   OPTIONAL
  IN OUT UINTN                    *BufferSize,
  OUT    EFI_HANDLE               *Buffer
  );

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL)(
  IN  EFI_HANDLE                Handle,
  IN  EFI_GUID                  *Protocol,
  OUT VOID                      **Interface, OPTIONAL
  IN  EFI_HANDLE                AgentHandle,
  IN  EFI_HANDLE                ControllerHandle,
  IN  UINT32                    Attributes
  );

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_PROTOCOL)(
  IN EFI_HANDLE               Handle,
  IN EFI_GUID                 *Protocol,
  IN EFI_HANDLE               AgentHandle,
  IN EFI_HANDLE               ControllerHandle
  );

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION)(
  IN  EFI_HANDLE                          Handle,
  IN  EFI_GUID                            *Protocol,
  OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer,
  OUT UINTN                               *EntryCount
  );

typedef
EFI_STATUS
(EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY)(
  IN  EFI_GUID                 *Protocol,
  IN  EFI_EVENT                Event,
  OUT VOID                     **Registration
  );

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE)(
  IN EFI_GUID                 *Guid,
  IN VOID                     *Table
  );

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE_BUFFER)(
  IN     EFI_LOCATE_SEARCH_TYPE       SearchType,
  IN     EFI_GUID                     *Protocol,      OPTIONAL
  IN     VOID                         *SearchKey,     OPTIONAL
  IN OUT UINTN                        *NoHandles,
  OUT    EFI_HANDLE                   **Buffer
  );

#endif