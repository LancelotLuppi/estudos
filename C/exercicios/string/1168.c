#include <stdio.h>

int main() {
    int n, i, leds, k, tamanho;
    char numero[105];

    scanf("%d", &n);

    for(i=0 ; i<n ; i++) {
        scanf("%s", &numero);
        tamanho = strlen(numero);
        leds = 0;
        for(k=0; k<tamanho; k++) {
            if(numero[k] == '1') {
                leds += 2;
            } else if(numero[k] == '2') {
                leds += 5;
            } else if(numero[k] == '3') {
                leds += 5;
            } else if(numero[k] == '4') {
                leds += 4;
            } else if(numero[k] == '5') {
                leds += 5;
            } else if (numero[k] == '6') {
                leds += 6;
            } else if (numero[k] == '7') {
                leds += 3;
            } else if (numero[k] == '8') {
                leds += 7;
            } else if (numero[k] == '9') {
                leds += 6;
            } else if (numero[k] == '0') {
                leds += 6;
            };
        }
        printf("%d leds\n", leds);
    }
}