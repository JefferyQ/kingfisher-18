/*

Copyright (c) 2004 - 2007, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  

*/

#ifndef EFI_SIMPLEOUT_H
#define EFI_SIMPLEOUT_H

typedef struct _EFI_SIMPLE_TEXT_OUT_PROTOCOL EFI_SIMPLE_TEXT_OUT_PROTOCOL;

typedef struct {
  INT32   MaxMode;

  //
  // current settings
  //
  INT32   Mode;
  INT32   Attribute;
  INT32   CursorColumn;
  INT32   CursorRow;
  BOOLEAN CursorVisible;
} EFI_SIMPLE_TEXT_OUTPUT_MODE;

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_OUTPUT_STRING) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN CHAR16                                 *String
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_ENABLE_CURSOR) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN BOOLEAN                                Enable
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_RESET) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN BOOLEAN                                ExtendedVerification
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_RESET) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN BOOLEAN                                ExtendedVerification
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_TEST_STRING) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN CHAR16                                 *String
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_QUERY_MODE) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN UINTN                                  ModeNumber,
  OUT UINTN                                 *Columns,
  OUT UINTN                                 *Rows
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_MODE) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN UINTN                                  ModeNumber
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_ATTRIBUTE) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN UINTN                                  Attribute
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_CLEAR_SCREEN) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL   * This
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_CURSOR_POSITION) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN UINTN                                  Column,
  IN UINTN                                  Row
  );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_CURSOR_POSITION) (
  IN EFI_SIMPLE_TEXT_OUT_PROTOCOL           * This,
  IN UINTN                                  Column,
  IN UINTN                                  Row
  );

struct _EFI_SIMPLE_TEXT_OUT_PROTOCOL {
  EFI_TEXT_RESET                Reset;

  EFI_TEXT_OUTPUT_STRING        OutputString;
  EFI_TEXT_TEST_STRING          TestString;

  EFI_TEXT_QUERY_MODE           QueryMode;
  EFI_TEXT_SET_MODE             SetMode;
  EFI_TEXT_SET_ATTRIBUTE        SetAttribute;

  EFI_TEXT_CLEAR_SCREEN         ClearScreen;
  EFI_TEXT_SET_CURSOR_POSITION  SetCursorPosition;
  EFI_TEXT_ENABLE_CURSOR        EnableCursor;

  //
  // Current mode
  //
  EFI_SIMPLE_TEXT_OUTPUT_MODE   *Mode;
};

#endif
