#include <stdio.h>
#include <string.h>

int main() {
    char str1[100];
    char str2[100];
    scanf(" %s %s", str1, str2);

    int n;
    scanf(" %d", &n);

    strcat(str1, str2);
    str2[strlen(str2) > n ? strlen(str2) : n] = 0;
    strncpy(str2, str1, n);

    printf("%s\n%s", str1, str2);

    return 0;
}