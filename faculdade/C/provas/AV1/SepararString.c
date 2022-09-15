#include <stdio.h>
#include <string.h>

void separarLetrasNumeros(char str[], char let[], char num[]) {
    int i, l, n;
    int len = strlen(str);
    n=0;
    l=0;
    for(i=0; i<len; i++) {
        if(str[i] >= '0' && str[i] <='9') {
            num[n] = str[i];
            n++;
        } else if(str[i] != " ") {
            let[l] = str[i];
            l++;
        }
    }
    num[n] = '\0';
    let[l] = '\0';
}

int main() {
    char str[] = "abc654rhf78";
    int len = strlen(str);
    char let[len];
    char num[len];

    separarLetrasNumeros(str, let, num);

    printf("String: %s\n", str);
    printf("Letras: %s\n", let);
    printf("Numeros: %s\n", num);

    return 0;
}