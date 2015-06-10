/*

Copyright (c) 2004 - 2007, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  

*/

#ifndef EFI_RUNTIME_SERVICES_H
#define EFI_RUNTIME_SERVICES_H

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_CONVERT_POINTER) (
  IN UINTN                        DebugDisposition,
  IN OUT VOID                     **Address
  );

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_GET_VARIABLE) (
  IN CHAR16                       *VariableName,
  IN EFI_GUID                     * VendorGuid,
  OUT UINT32                      *Attributes OPTIONAL,
  IN OUT UINTN                    *DataSize,
  OUT VOID                        *Data
  );

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_VARIABLE_NAME) (
  IN OUT UINTN                    *VariableNameSize,
  IN OUT CHAR16                   *VariableName,
  IN OUT EFI_GUID                 * VendorGuid
  );

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_SET_VARIABLE) (
  IN CHAR16                       *VariableName,
  IN EFI_GUID                     * VendorGuid,
  IN UINT32                       Attributes,
  IN UINTN                        DataSize,
  IN VOID                         *Data
  );

//
// EFI Time
//
typedef struct {
  UINT32  Resolution;
  UINT32  Accuracy;
  BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_GET_TIME) (
  OUT EFI_TIME                    * Time,
  OUT EFI_TIME_CAPABILITIES       * Capabilities OPTIONAL
  );

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_SET_TIME) (
  IN EFI_TIME                     * Time
  );

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_GET_WAKEUP_TIME) (
  OUT BOOLEAN                     *Enabled,
  OUT BOOLEAN                     *Pending,
  OUT EFI_TIME                    * Time
  );

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_SET_WAKEUP_TIME) (
  IN BOOLEAN                      Enable,
  IN EFI_TIME                     * Time OPTIONAL
  );

typedef enum {
  EfiResetCold,
  EfiResetWarm,
  EfiResetShutdown
} EFI_RESET_TYPE;

typedef
EFI_RUNTIMESERVICE
VOID
(EFIAPI *EFI_RESET_SYSTEM) (
  IN EFI_RESET_TYPE           ResetType,
  IN EFI_STATUS               ResetStatus,
  IN UINTN                    DataSize,
  IN CHAR16                   *ResetData OPTIONAL
  );

typedef
EFI_RUNTIMESERVICE
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT) (
  OUT UINT32                  *HighCount
  );


#endif