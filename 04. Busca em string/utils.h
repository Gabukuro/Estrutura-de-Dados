#include "rabinKarp.h"
#include "forcaBruta.h"

#define SIZE 256

void clear(void) {
	system("@cls||clear");
}

void menu() {
	
	int option;
	
	do {
		printf("\n\t*** MENU ***\n");
		printf("\n\t=> Escolha um algoritmo de busca:\n\n");
		printf("\t[1] - Rabin Karp\n");
		printf("\t[2] - Forca Bruta\n");
		printf("\t[0] - Sair\n");
		printf("\n\n\t=> Sua escolha: ");
		scanf("%d", &option);
		
		clear();
		switch(option) {
			case 1:
				printf("\n\t- Metodo Rabin Karp -\n\n");
				pesquisa(rabinKarp);
			break;
			case 2:
				printf("\n\t- Metodo Forca Bruta -\n\n");
				pesquisa(forcaBruta);
			break;
			default:
				printf("\n\t- Escolha invalida\n\n");
				system("pause");
				clear();
			break;
		}
	} while (option != 0);
}


void pesquisa(void (*func)(char *, char *, int, int)) {
	
	FILE *file;
	char texto[SIZE];
	char arquivo[SIZE];
	char frase[SIZE];
	int linha = 0, match = 0;
	
	printf("\n\t=> Informe o nome do arquivo: ");
	scanf(" %[^\n]s", arquivo);

	file = fopen(arquivo, "r");
	
	if(file == NULL) {
		
		printf("\n\tArquivo nao encontrado, tente novamente!\n");
		system("pause");
		clear();
		menu();
		
	}
	
	printf("\n\t=> Informe a frase desejado: ");
	scanf(" %[^\n]s", frase);
		
	while(fgets(texto, SIZE,file) != NULL) {
		func(frase, texto, linha, match);
		linha++;
	}
	if (match == 0)	printf("\n\n\tTexto nao encontrado!\n");
	fclose(file);
	printf("\n\n");
	system("pause");
	clear();
}

