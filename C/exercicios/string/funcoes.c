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
    
    printf("Substring ocorrida: %s\n", ret);
    printf("Tamanho string Teste: %d\n", len);
    printf("Comparacao: %d\n", cmp);
    printf("Concatenacao: %s\n", concat);
    printf("Copia: %s\n", copia);

    return 0;
}
