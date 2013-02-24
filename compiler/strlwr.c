#include <stdio.h>
#include <ctype.h>

char *strlwr(char *c)
{
   char *p;
   if (!c) return NULL;
   for (p = c; *p; p++)
     if (isascii(*p) && isupper(*p))
        *p = tolower(*p);
  return c;
}
