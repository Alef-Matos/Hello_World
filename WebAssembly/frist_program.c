#include <unistd.h>

void    fu_printstr(char *str)
{
    while(*str)
        write(1, str++, 1);
}

int main (void)
{
    fu_printstr("Ola Mundo Online heheh\n");
}