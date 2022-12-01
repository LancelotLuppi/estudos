#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("num.bin", "r+b");
    int trocou;

    do {
        trocou = 0;
        int V[2];
        
        fread(&V[0], sizeof(int), 1, file);

        while(fread(&V[1], sizeof(int), 1, file)) {
            
            if(V[1]<V[0]) {
                printf("Trocou %d com %d\n", V[0], V[1]);
                int aux = V[0];
                V[0] = V[1];
                V[1] = aux;
                getch();
                fseek(file, -2L*sizeof(int), SEEK_CUR);
                fwrite(V, sizeof(int), 2, file);
                trocou = 1;
            }
        }

    } while();
}