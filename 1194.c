#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct noArv{

	char letra;
	struct noArv *dir;
	struct noArv *esq;

} noArv;

noArv* novoNo(char letra);
void showposfixa(noArv *arvore);
int src(char *str, int inicio, int fim, char letra);
noArv* tree(char *infixa, char *prefixa, int inInicio, int inFim);

short indice;



noArv* novoNo(char letra)
{

	noArv *no = (noArv *) malloc(sizeof(noArv));
	no->letra = letra;
	no->esq = no->dir = NULL;

	return no;
}

int src(char *str, int inicio, int fim, char letra)
{

	short i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == letra)
			return i;

	return -1;

}

noArv* tree(char *infixa, char *prefixa, int inInicio, int inFim)
{

	int infixaIndice;

	if (inInicio > inFim)
		return NULL;

	noArv *no = novoNo(prefixa[indice++]);
	if (inInicio == inFim)
		return no;

	infixaIndice = src(infixa, inInicio, inFim, no->letra);
	no->esq = tree(infixa, prefixa, inInicio, infixaIndice - 1);
	no->dir = tree(infixa, prefixa, infixaIndice + 1, inFim);

	return no;

}
// funcao para ver mostrar a ordem pos fixa
void showposfixa(noArv *no)
{

	if (no == NULL)
		return;

	showposfixa(no->esq);
	showposfixa(no->dir);
	printf("%c", no->letra);

}
void main ()
{

	short qtsCasos;
	short qtsNodes, i;
	char prefixa[MAXSIZE], infixa[MAXSIZE];

	scanf("%hu", &qtsCasos);

	while (qtsCasos--)
	{

		scanf("%hu %s %s%*c", &qtsNodes, prefixa, infixa);
		indice = 0;
		noArv *raiz = tree(infixa, prefixa, 0, qtsNodes - 1);
		showposfixa(raiz);
		printf("\n");

	}

}
