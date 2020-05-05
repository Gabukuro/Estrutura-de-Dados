#define primo 101
#define R 256

void rabinKarp(char frase[], char texto[], int linha, int match)
{
	int i, j, h = 1;
	int tamanhoFrase = strlen(frase);
	int tamanhoTexto = strlen(texto);
	int hashTexto = 0;
	int hashFrase = 0;


	// o valor de h sera a potencia de (256 ^ tamanho da frase procurada - 1) % primo
	for (i = 0; i < tamanhoFrase - 1; i++)
		h = (h * R) % primo;

	// hash da frase procurada e do texto com a ser comparado
	for (i = 0; i < tamanhoFrase; i++)
	{
		hashTexto = (R * hashTexto + texto[i]) % primo;
		hashFrase = (R * hashFrase + frase[i]) % primo;
	}

	// comparar frase com o texto um a um
	for (i = 0; i < tamanhoTexto - tamanhoFrase; i++)
	{

		if (hashTexto == hashFrase)
		{
			// se os valores hash baterem devemos compara as letras para validar o hash
			for (j = 0; j < tamanhoFrase; j++)
			{
				if (frase[j] != texto[i + j])
				{
					break;
				}
			}

			if (j == tamanhoFrase)
			{
				printf("\n\tTexto encontrado na linha %d coluna %d", linha, i);
				printf("\n\t%d - %s\n\n", linha, texto);
				match++;
			}
		}

		if (i < tamanhoTexto - tamanhoFrase)
		{
			hashTexto = (R * (hashTexto - texto[i] * h) + texto[i + tamanhoFrase]) % primo;

			if (hashTexto < 0)
			{
				hashTexto = (hashTexto + primo);
			}
		}
	}
}

