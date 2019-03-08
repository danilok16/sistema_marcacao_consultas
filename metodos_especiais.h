#include "types.h"


FILE * criarArquivoIndexado(char nome[],TArvoreBB **raiz);
FILE * criarArquivo(char nome[]);

int comparaNome(char str1[], char str2[], TNomes **nameList, int posArquivo);

TNomes *posicao(TNomes *l, char nome[]); //usado na função para criar um lista de nomes

void inserirNo(TNomes**l, char nome[], int posArquivo); //Criar lista de nomes

int resultadoPesquisa(TNomes *l);

void limparLista(TNomes**l); //desalocar lista de nomes

void exibirLista(TNomes *l,int vet[] );