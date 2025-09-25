#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <mem.h>

int fill_onegin_array (char oneg [], FILE* TEXTIN);
int fill_pointer_array (struct poi_len *structpointlen, char onegin_array[], const int LEN_ONEGIN);
void alphabet_buble (struct poi_len* *point_struct_array, const int NSTR);
void rhyme_buble (struct poi_len* *point_struct_array, const int NSTR);
int my_strcmp (const char* str1, const char* str2);
int func_len_oneg (FILE* TEXTIN);

struct poi_len
{
    char* point;
    int len;
};

int main ()
{
    FILE* TEXTIN = fopen ("textonegin.txt", "rb");
    if (TEXTIN == NULL)
    {
        perror ("AHAHAHA IT'S ERROR");
        return -1;
    }

    const int LEN_ONEGIN = func_len_oneg (TEXTIN);

    char *onegin_array = (char *) malloc (LEN_ONEGIN * sizeof (char));
    int NSTR = fill_onegin_array (onegin_array, TEXTIN);
    
    struct poi_len *structpointlen = (struct poi_len *) malloc (NSTR * sizeof (struct poi_len));
    fill_pointer_array (structpointlen, onegin_array, LEN_ONEGIN);

    struct poi_len* point_struct_array [NSTR] = {};
    for (int i = 0; i < NSTR; i++)
    {
        point_struct_array [i] = &(structpointlen [i]);
    }

    alphabet_buble (point_struct_array, NSTR);
    FILE* TEXTOUT = fopen ("FORTNITE_BOSS1.txt", "w");
    if (TEXTOUT == NULL)
    {
        perror ("AHAHAHA IT'S ERROR");
        return -1;
    }

    for (int i = 0; i < NSTR; i++)
    {
        fprintf (TEXTOUT, "%.*s", point_struct_array[i]->len, point_struct_array[i]->point);
    }
    fclose (TEXTOUT);

    return 0;
}

int func_len_oneg (FILE* TEXTIN)
{
    if (TEXTIN == NULL)
    {
        perror ("AHAHAHA IT'S ERROR");
        return -1;
    }

    fseek (TEXTIN, 0, SEEK_END);

    int len = ftell (TEXTIN);

    fseek (TEXTIN, 0, SEEK_SET);
    return len;
}

int fill_onegin_array (char oneg [], FILE* TEXTIN)
{
    assert (oneg);

    int c = 0;
    int n = 1;
    int i = 0;
    while ((c = fgetc(TEXTIN)) != EOF)
    {
        oneg[i] = c;
        if (c == '\n')
        {
            n++;
        }
        i++;
    }
    fclose(TEXTIN);
    oneg[i] = '\n';
    return n;
}

int fill_pointer_array (struct poi_len *structpointlen, char onegin_array[], const int LEN_ONEGIN)
{
    int idx = 0;
    int i = 0;
    int old_i = 0;
    for (; i < LEN_ONEGIN; i++)
    {
        //printf ("3");
        if (((onegin_array[i]) == '\n'))
        {
            //printf ("%d\n", idx);
            structpointlen[idx].point = &onegin_array[old_i];
            structpointlen[idx].len = (i + 1 - old_i);
            old_i = i + 1;
            idx++;
        }
    }
    structpointlen[idx].point = &onegin_array[old_i];
    structpointlen[idx].len = (i + 1 - old_i);
    return idx;
}

void alphabet_buble (struct poi_len* *point_struct_array, const int NSTR)
{
    assert (point_struct_array);
    struct poi_len* swap_poi_len = {0};

    for (int i = 0; i < (NSTR); i++)
    {
        //printf ("i: %d\n", i);
        for (int j = 0; j < (NSTR - i - 1); j++)
        {
            if (my_strcmp (point_struct_array[j]->point, (point_struct_array [j+1]->point)) > 0)
            {
                
                swap_poi_len = point_struct_array [j]; 
                point_struct_array [j] = point_struct_array [j+1];
                point_struct_array [j+1] = swap_poi_len;
                //printf ("%d\n", j);
            }
            //printf ("j: %d\n", j);
        }
    }
    return;
}

void rhyme_buble (struct poi_len* *point_struct_array, const int NSTR)
{
    assert (point_struct_array);
    struct poi_len* swap_poi_len = {};

    for (int i = 0; i < (NSTR); i++)
    {
        printf ("i: %d\n", i);
        for (int j = 0; j < (NSTR - i - 1); j++)
        {
            if (my_strcmp (point_struct_array[j]->point, (point_struct_array [j+1]->point)) > 0)
            {
                
                swap_poi_len = point_struct_array [j]; 
                point_struct_array [j] = point_struct_array [j+1];
                point_struct_array [j+1] = swap_poi_len;
                //printf ("%d\n", j);
            }
            //printf ("j: %d\n", j);
        }
    }
    return;
}

int my_strcmp (const char* str1, const char* str2, char )
{
    int i1 = 0;
    int i2 = 0;


    while ((str1[i1] != '\n') && (str2[i2] != '\n'))
    {
        if (str1[i1] == '\0' || str2[i2] == '\0')
        {
            return str1[i1] - str2[i2];
        }

        while ((isalpha(str1[i1]) == 0) && (str1[i1] != '\n'))
        {
            i1++;
        }

        while ((isalpha(str2[i2]) == 0) && (str2[i2] != '\n'))
        {
            i2++;
        }

        if ((toupper (str1[i1]) != toupper(str2[i2])) || (str1[i1] == '\n') || (str2[i2] == '\n'))
        {
            return str1[i1] - str2[i2];
        }

        while ((str1[i1] != '\0') && (str2[i2] != '\0') && (toupper(str1[i1]) == toupper(str2[i2])))
        {
            ++i1;
            ++i2;
        }
    }

    return str1[i1] - str2[i2];
}