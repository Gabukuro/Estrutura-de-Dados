void forcaBruta(char frase[], char texto[], int linha) {
	
	int j, k;
	int fraseLength = strlen(frase);
	int textoLength = strlen(texto);
	
	for(j = 0; j <= textoLength - fraseLength; j++) {
		while(k < fraseLength && texto[j + k] == frase[k]) {
			k++;
		}
		
		if(k == fraseLength) {
			printf("\n\tTexto encontrado na linha %d coluna %d", linha, j);
			printf("\n\t%d - %s\n\n", linha, texto);
			match ++;
		}
		k=0;
	}
}
