#include <stdio.h>

int converter_str(char *str) {
    int i;
    int conjunto = 0;
    for(i=0; str[i] != '\0'; i++) {
        conjunto |= (1<<(str[i] - 'A'));
    }
    return conjunto;
}

int comparar_conjuntos(int conjunto) {
    if()
}

int main() {

    int qnt_inputs, valor_binario, i = 0;

    scanf("%d", &qnt_inputs);
    int lista_iniciais[qnt_inputs];
    char input[1000000];

    while(qnt_inputs > 0) {
        scanf("%s", input);
        valor_binario = converter_str(input);
        lista_iniciais[i] = valor_binario;
        qnt_inputs--;
        i++;
    }



    scanf("%d", &qnt_inputs);

    char texto[] = "ABEL";
    
    printf("%d", result);

    return 0;
}