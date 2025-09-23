#include <stdio.h>
#include <stdlib.h>

int main ()
{
    //FILE* text = fopen("textonegin.txt", "r");

    char *ptr = (char*)malloc(sizeof("abc"));
    *ptr = (char)"abc";
    printf("%d %p", *ptr, (int*)ptr);



}