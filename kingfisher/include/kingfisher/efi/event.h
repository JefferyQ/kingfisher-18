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

#ifndef EFI_EVENT_H
#define EFI_EVENT_H

typedef enum {
  TimerCancel,
  TimerPeriodic,
  TimerRelative
} EFI_TIMER_DELAY;

typedef
VOID
(EFIAPI *EFI_EVENT_NOTIFY)(
  IN  EFI_EVENT                Event,
  IN  VOID                     *Context
  );

typedef
EFI_STATUS
(EFIAPI *EFI_SET_TIMER)(
  IN  EFI_EVENT                Event,
  IN  EFI_TIMER_DELAY          Type,
  IN  UINT64                   TriggerTime
  );

typedef
EFI_STATUS
(EFIAPI *EFI_SIGNAL_EVENT)(
  IN  EFI_EVENT                Event
  );

typedef
EFI_STATUS
(EFIAPI *EFI_WAIT_FOR_EVENT)(
  IN  UINTN                    NumberOfEvents,
  IN  EFI_EVENT                *Event,
  OUT UINTN                    *Index
  );

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_EVENT)(
  IN EFI_EVENT                Event
  );

typedef
EFI_STATUS
(EFIAPI *EFI_CHECK_EVENT)(
  IN EFI_EVENT                Event
  );

#endif
