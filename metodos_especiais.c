//METODOS_ESPECIAI.C
#include "types.h"
#include"cliente.h"
#include<Windows.h>
#include "view.h"
#include"medico.h"

FILE * criarArquivoIndexado(char nome[], TArvoreBB **raiz) {  //funcao do tipo FILE
	FILE * arq;

	arq = fopen(nome, "r+b");
	if (arq == NULL) {
		arq = fopen(nome, "w+b");
	}
	else if(strcmp(nome, "Clientes.bin") == 0) {
		indexarArqCliente(&(*raiz), arq);
	}
	else if(strcmp(nome, "Medicos.bin") == 0) {
		indexarArqMedico(&(*raiz), arq);
	}
	return arq;
}
FILE * criarArquivo(char nome[]) {  //funcao do tipo FILE
	FILE * arq;

	arq = fopen(nome, "r+t");
	if (arq == NULL) {
		arq = fopen(nome, "w+t");
	}
	return arq;
}



//funçao utilizada pelo procedimento inseirNo, essa função retorna a posição onde o nó deve ser inserido
TNomes *posicao(TNomes *l, char nome[]) {//funçao utilizada pelo procedimento inseirNo, essa função retorna a posição onde o nó deve ser inserido
	TNomes *aux = l;


	if (l == NULL) {
		return aux;
	}
	else if (aux->prox == NULL) {
		if (strcmp(aux->nome, nome) == 0) {
			return NULL;
		}
		else {
			return aux;
		}
	}
	else { // obs
		while (aux->prox != NULL) {
			if (strcmp(aux->nome, nome) >  0) {
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}
} 

//procedimento utilizado para construir um lista encadeada de nomes
void inserirNo(TNomes**l, char nome[], int posArquivo) {
	TNomes *novo, *pos, *aux = *l;

	novo = (TNomes*)malloc(sizeof(TNomes));
	pos = posicao(*l, nome);

	strcpy(novo->nome, nome);
	novo->pos = posArquivo;

	if (pos == NULL) { // lista vazia
		*l = novo;
		novo->ant = NULL;
		novo->prox = NULL;
	}
	else if (pos->ant == NULL && pos->prox == NULL) { //apenas 1 nó
		if (strcmp(novo->nome, pos->nome) > 0) {
			novo->ant = pos;
			pos->prox = novo;
			novo->prox = NULL;
		}
		else {
			novo->prox = pos;
			novo->ant = NULL;
			pos->ant = novo;
			*l = novo;
		}
	}
	else {
		if (pos->ant == NULL) {
			if (strcmp(novo->nome, pos->nome) > 0) { // primeiro nó
				novo->prox = pos->prox;
				novo->ant = pos;
				pos->prox->ant = novo;
				pos->prox = novo;
			}
			else {
				novo->prox = pos;
				novo->ant = NULL;
				pos->ant = novo;
				*l = novo;
			}
		}
		else if (pos->prox != NULL) { // inserir no meio
			novo->prox = pos;
			pos->ant->prox = novo;
			novo->ant = pos->ant;
			pos->ant = novo;
		}
		else if (pos->prox == NULL && strcmp(novo->nome, pos->nome) > 0) { // inserir no final
			novo->prox = NULL;
			novo->ant = pos;
			pos->prox = novo;
		}
		else {
			novo->prox = pos;
			pos->ant->prox = novo;
			novo->ant = pos->ant;
			pos->ant = novo;
		}
	}
}

void exibirLista(TNomes *l,int vet[] ){
	TNomes *aux = l;
	int i = 1;

	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄRESULTADOS DA PESQUISAÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\n");
		while (aux != NULL) {
			printf("   %s\n", aux->nome);
			vet[i] = aux->pos;
			i++;
			aux = aux->prox;
		}
		printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄPRESSIONE ESC PARA VOLTARÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\n");

}
//exibi o resultado da pesquisa e retorna a posição do nome escolhido
int resultadoPesquisa(TNomes *l) {
	int pos = 0;
	int ch, x, y, opc = 0, sair = FALSE;
	TNomes *aux = l;
	int i = 1, resp;
	int vet[10000];
	
	if (l == NULL) {
		printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄRESULTADOS DA PESQUISAÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\n");
		x = 16; y = 6;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³        SEM RESULTADOS!      ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
		system("pause");
		return pos = -1;//nao achou nenhum nome relacionado
	}
	else {
		exibirLista(l, vet);
	}
	if (pos != -1) {

		x = 1, y = 5;
		posicaoCursor(x, y);
		printf(">");
		while (sair == FALSE) {
			ch = getch();
			setbuf(stdin, NULL);
			if (ch == 224) {
				switch (getch()) {
				case acima:
					if (y < i+3) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, ++y);
						printf(">");
					} break;
				case abaixo:
					if (y > 5) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, --y);
						printf(">");
					}  break;
				defalte: break;
				}  setbuf(stdin, NULL);
			}
			else if (ch == enter) {
				pos = vet[y-4];
				sair = TRUE;
			}
			else if (ch == voltar1 || ch == voltar2) {
				pos = -1; opc = 7; sair = TRUE;
			}
		}
	}

	return pos;
}



void limparLista(TNomes**l) {
	TNomes *aux;

	while (*l != NULL) {
		aux = *l;
		*l = (*l)->prox;
		free(aux);
	}
}


int comparaNome(char str1[], char str2[], TNomes **nameList, int posArquivo) {
	int i, contSpc = 0, resp;;

	for (i = 0; i <= strlen(str2); ++i) {
		if (str1[i] == str2[i]) {
			if (str1[i] == ' ' || strcmp(str2, str1) < 0 || strcmp(str1, str2) == 0) {
				contSpc++;
				if (contSpc == 1) {
					inserirNo(&(*nameList), str1, posArquivo);
				}
			}
		}
		else {
			return -1;
		}
	}
	return 0;

}
//FIM METODOS_ESPECIAI.C