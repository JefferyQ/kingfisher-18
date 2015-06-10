/*

Copyright (c) 2004 - 2007, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  

*/

#ifndef EFI_SIMPLEIN_H
#define EFI_SIMPLEIN_H

typedef struct _EFI_SIMPLE_TEXT_IN_PROTOCOL EFI_SIMPLE_TEXT_IN_PROTOCOL;

typedef struct {
  UINT16  ScanCode;
  CHAR16  UnicodeChar;
} EFI_INPUT_KEY;

typedef
EFI_STATUS
(EFIAPI *EFI_INPUT_RESET) (
  IN EFI_SIMPLE_TEXT_IN_PROTOCOL          * This,
  IN BOOLEAN                              ExtendedVerification
  );

typedef
EFI_STATUS
(EFIAPI *EFI_INPUT_READ_KEY) (
  IN EFI_SIMPLE_TEXT_IN_PROTOCOL          * This,
  OUT EFI_INPUT_KEY                       * Key
  );

struct _EFI_SIMPLE_TEXT_IN_PROTOCOL {
  EFI_INPUT_RESET     Reset;
  EFI_INPUT_READ_KEY  ReadKeyStroke;
  EFI_EVENT           WaitForKey;
};

#endif