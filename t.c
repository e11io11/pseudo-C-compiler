#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c[2] = "";
    if (c[0]) {
        printf("Ah %d\n", c[0]);
    } else {
        printf("Oh %d\n", c[0]);
    }

    return 0;
}
