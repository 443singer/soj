#include <stdio.h>
#include <string.h>

void reverse_str(char* buf, int n)
{
    if (n < 2)
        return;

    char temp = buf[0];
    buf[0] = buf[n-1];
    buf[n-1] = temp;
    reverse_str(buf+1,n-2); //МоїХ
}

int main()
{
    char str[100];
    while (scanf("%s", str) != EOF)
    {
        reverse_str(str, strlen(str));
        printf("%s\n", str);
    }
    return 0;
}
