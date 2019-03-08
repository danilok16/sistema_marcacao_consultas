#include "types.h"

int buscaPorCpf(TArvoreBB *raiz, char cpf[]);
int buscarClientePorNome(FILE * arqCliente, TNomes **nameList, char nome[]);
void cadastrarCliente(TArvoreBB **arvore_cliente, FILE *arqCliente, char cpf[]);
void alterarCadastroCliente(TArvoreBB *raiz, FILE *arqCliente, char cpf[]);
void exibirCliente(TArvoreBB *raiz, FILE *arqCliente, char cpf[]);
void removerCliente(TArvoreBB **raiz, FILE *arqCliente, char indice[]);
void indexarArqCliente(TArvoreBB **raiz, FILE *arqCliente);
void desindexarArqCliente(TArvoreBB **raiz);
void listarCliente(TArvoreBB *raiz, FILE *arqCliente);
void manutencaoArqCliente(FILE * arq);