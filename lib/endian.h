#ifndef _ANUBISNET_ENDIAN_
#define _ANUBISNET_ENDIAN_

#include "pch.h"

typedef int _bool;
#define _true 0x01
#define _false 0x00

extern _bool IsBigEndian ();
extern short rotate2b ( short var);
extern unsigned int rotate4b ( unsigned int var );

#endif
