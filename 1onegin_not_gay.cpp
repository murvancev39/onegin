#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

// TODO сделай отдельный проект и разнеси по файлам функции логично

//void param_Onegin (int *maxLen, FILE *text);
int onegin_array (char str_array[][47], const char* string);
void buble_str_array (char str_array[][47], int S_number);
int my_strcmp (const char* str1, const char* str2);
void output (char str_array[][47], const int NSTR);
//ssize_t my_getline (char **lineptr, int *n, FILE *stream);

int main ()
{
    const int NSTR = 5332;
    char str_array[5332][47]={0};
    onegin_array (str_array, "textonegin.txt");
    
    buble_str_array (str_array, NSTR);

    output (str_array, NSTR);
    return 0;
    
}

/*
void param_Onegin (int *maxLen, FILE *text)
{
    int nLen = 0;
    int symbol = 0;
    while ((symbol = fgetc (text)) != EOF)
    {
        if (symbol == '\n')
        {
            if (nLen > *maxLen)
            {
                *maxLen = nLen + 1;
            }
            nLen = 0;
        }
        else
        {
            nLen++;
        }
    }
    return;
}
*/

// TODO fstat or fseek for filesize
// TODO not magic number, count lines max len line
int onegin_array (char str_array[][47], const char* string) // TODO without magic size number
{
    // TODO asserts
    assert(str_array);
    FILE* text = fopen (string, "r");
    if (text == NULL)
    {
        perror("AHAHAHA IT'S ERROR");
        return -1;
    }

    int str_num = 0;

    const int n = 47;
    char str[n] = {0};
    
    while (fgets(str, n, text) != NULL)
    {
        strcpy(str_array[str_num], str);
        str_num++;
    }
    fclose(text);

    return 1;
}

void buble_str_array (char str_array[][47], int S_number)
{
    assert(str_array);

    char swap_str [47] = {0};
    for (int i = 0 ; i < S_number ; i++)
    {
        for (int ii = 0 ; ii < (S_number - i - 1) ; ii++)
        {
            if (my_strcmp(str_array[ii], str_array[ii+1]) > 0)
            {
                strcpy (swap_str, str_array [ii]);
                // printf("swap_str: %s\nstr_array[i] %s\n", swap_str, str_array[i]);
                
                strcpy (str_array [ii], str_array [ii+1]);
                strcpy ( str_array [ii+1], swap_str);
                // printf("%s", swap_str);
            }
            
            //printf("%d\n", i);
            /*
            int ii = 0;
            while ((str_array [i][ii] <= str_array [i+1][ii])) //&& (str_array[i][ii] != '\n') && (str_array [i+1][ii] != '\n'
            {
                ii++;
            }
            
            if (str_array [i][ii] > str_array [i+1][ii]) 
            {
                strcpy (swap_str, ((const char*) str_array [i]));
                printf("%s", swap_str);
                strcpy (str_array [i], (const char*) str_array [i+1]);
                strcpy ( str_array [i+1], (const char*) swap_str);
            }
            i++;
            */
            
        }
    }
    //printf("%d\n", S_number);

    return;
}

void output (char str_array[][47], const int NSTR) // TODO FILE* parameter
{
    int str_num = 0;

    while (str_num < NSTR)
    {
        printf ("%s", str_array[str_num]);
        str_num++;
    }
    return;
}

int my_strcmp (const char* str1, const char* str2)
{
    int i1 = 0;
    int i2 = 0;
    
    while ((str1[i1] != '\0') && (str2[i2] != '\0') && (str1[i1] == str2[i2]))
    {
        ++i1;
        ++i2;
    }
    return str1[i1] - str2[i2];
    

    while ((str1[i1] != '\0') && (str1[i1] != '\0'))
    {
        while ((isalpha(str1[i1]) != 0) && (str1[i1] != '\0'))
        {
            i1++;
        }

        while ((isalpha(str2[i2]) != 0) && (str2[i2] != '\0'))
        {
            i2++;
        }

        if ((toupper (str1[i1]) != toupper(str2[i2])) || (str1[i1] == '\0') || (str2[i2] == '\0'))
        {
            return str1[i1] - str2[i2];
        }
    }

    return str1[i1] - str2[i2];
}

/*

ssize_t my_getline (char **lineptr, int *n, FILE *stream)
{
    if (fgets ( *lineptr, *n , stream) == NULL)
    {
        if (feof (stream) != 0)
        {
            return 1;
        }
        
        if (ferror (stream) != 0)
        {
            perror ("AHAHAHA IT'S ERROR");
            return -1;
        }
    }
    //printf ("pointer lineptr %p\n", lineptr);
    //printf ("string lineptr %s\n", lineptr);
    //printf ("pointer *lineptr %p\n", *lineptr);
    //printf ("string *lineptr %s\n", *lineptr);
    //printf ("strlen *lineptr %lld\n", strlen(*lineptr));
    return ;//strlen (*lineptr)
}
    */