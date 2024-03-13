#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[10];
    
    strcpy(str2, str1);
    
    printf("Copied String: %s\n", str2);
    
    return 0;
}

