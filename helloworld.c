#include<unistd.h>

void fun_putstr(char *str)
{
    while(*str)
      write(1, str++, 1);
}
int main (void)
{
   fun_putstr("Hello World");
}
