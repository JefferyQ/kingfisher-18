
#ifndef KINGFISHER_ABI_H
#define KINGFISHER_ABI_H

#define MSAPI   __attribute__((ms_abi))
#define SYSVAPI __attribute__((sysv_abi))

#define EFIAPI  MSAPI

#endif