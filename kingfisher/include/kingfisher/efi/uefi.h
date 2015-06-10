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

#ifndef KINGFISHER_UEFI_H
#define KINGFISHER_UEFI_H



#include "int.h"                 /* INT TYPES */

typedef struct {
  UINT32  Data1;
  UINT16  Data2;
  UINT16  Data3;
  UINT8   Data4[8];
} EFI_GUID;

typedef void* EFI_HANDLE;
typedef void* EFI_EVENT;
typedef UINTN EFI_STATUS;
typedef void  VOID;
#define CONST const
#define STATIC static

#define IN 
#define OUT 
#define OPTIONAL 

#include "abi.h"                 /* ABI includes */
#include "memory.h"              /* memory structs */
#include "event.h"               /* event api */
#include "time.h"                /* time definitions */
#include "net.h"                 /* network definitions */
#include "protocol.h"            /* protocols, handles */
#include "device.h"              /* devices */
#include "statuscodes.h"
#include "systemtable.h"         /* the system table. */

#endif
