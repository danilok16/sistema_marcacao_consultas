#include"types.h"

void inserirIndice(TArvoreBB **raiz, char indice[], int pos);
int buscar(TArvoreBB *raiz, char indice[]);
void removerNo(TArvoreBB **raiz);
void removerIndice(TArvoreBB **raiz, char indice[]);
TArvoreBB *maior(TArvoreBB **raiz);