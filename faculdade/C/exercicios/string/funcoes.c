/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char teste[] = "abc";
    char teste2[] = "123abc";
    char * ret;
    char copia[10];
    
    ret = strstr(teste2, teste);
    int len = strlen(teste);
    int cmp = strcmp(teste, ret);
    char * concat = strcat(teste, teste2);
    strcpy(copia, teste);
    int retChar = strchr(teste, "f");
    
    printf("Substring ocorrida: %s\n", ret);
    printf("Tamanho string Teste: %d\n", len);
    printf("Comparacao: %d\n", cmp);
    printf("Concatenacao: %s\n", concat);
    printf("Copia: %s\n", copia);
    printf("Primeiro char igual: %d\n", retChar);

    return 0;
}
