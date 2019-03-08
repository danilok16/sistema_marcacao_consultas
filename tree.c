//TREE.C
#include"types.h"

void inserirIndice(TArvoreBB **raiz, char indice[], int pos) {

	if (*raiz == NULL) {
		*raiz = (TArvoreBB*)malloc(sizeof(TArvoreBB));
		strcpy((*raiz)->indice, indice);
		(*raiz)->pos = pos;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
	}
	else if (strcmp(indice, (*raiz)->indice) < 0) {
		inserirIndice(&((*raiz)->esq), indice, pos);
	}
	else {
		inserirIndice(&((*raiz)->dir), indice, pos);
	}
}

int buscar(TArvoreBB *raiz, char indice[]) {
	TArvoreBB *aux = raiz;

	if (aux == NULL) {
		return -1;
	}
	else {
		while (aux != NULL) {
			if (strcmp(aux->indice, indice) == 0) {
				return aux->pos;
			}
			else if (strcmp(indice, aux->indice) < 0) {
				aux = aux->esq;
			}
			else {
				aux = aux->dir;
			}
		}
	}
	return -1;
}

TArvoreBB *maior(TArvoreBB **raiz) {
	TArvoreBB *aux;

	aux = *raiz;
	if (aux->dir == NULL) {
		*raiz = (*raiz)->esq;
		return aux;
	}
	else {
		return maior(&((*raiz)->dir));
	}
}

void removerNo(TArvoreBB **raiz) {
	TArvoreBB *pos;
	pos = *raiz;
	if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
		*raiz = NULL;
	}
	else if ((*raiz)->esq == NULL) {
		*raiz = (*raiz)->dir;
	}
	else if ((*raiz)->dir == NULL) {
		*raiz = (*raiz)->esq;
	}
	else {
		pos = maior(&((*raiz)->esq));
		strcpy((*raiz)->indice, pos->indice);
		(*raiz)->pos = pos->pos;
	}
	free(pos);
}

void removerIndice(TArvoreBB **raiz, char indice[]) {

	if (strcmp(indice, (*raiz)->indice) == 0) {
		removerNo(&(*raiz));
	}
	else {
		if (strcmp(indice, (*raiz)->indice) < 0) {
			removerIndice(&(*raiz)->esq, indice);
		}
		else {
			removerIndice(&(*raiz)->dir, indice);
		}
	}
}

//FIM TREE.C
