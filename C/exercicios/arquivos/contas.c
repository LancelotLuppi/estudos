#include<stdio.h>

typedef struct {
	float saldo;
	char nome[50];
	struct data {int dia, mes, ano} dt_abertura;
} CONTA;

int main() {
	FILE *arqin, *arqout;
	
	arqin = fopen("contas.dat", "rb");
	arqout = fopen("contas_2017.dat", "wb");
	
	CONTA conta;
	
	while(fread(&conta, sizeof(CONTA), 1, arqin) > 0) {
		if(conta.dt_abertura.ano == 2017) {
			fwrite(&conta, sizeof(CONTA), 1, arqout);
		}
	}
	
	fclose(arqout);
	fclose(arqin);
	
	return 0;
}
