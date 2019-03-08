#include"types.h"

void cadastrarMedico(TArvoreBB **raiz, FILE *arqMedico, char crm[]);
void listarMedico(TArvoreBB *raiz, FILE *arqMedico);
void indexarArqMedico(TArvoreBB **raiz, FILE *arqMedico);
void desindexarArqMedico(TArvoreBB **raiz);
void buscarMedicoPorNome(FILE * arqMedico, TNomes **nameList, char nome[]);
int buscaPorCrm(TArvoreBB *raiz, char crm[]);
void alterarCadastroMedico(TArvoreBB *raiz, FILE *arqMedico, char crm[]);
void removerMedico(TArvoreBB **raiz, FILE *arqMedico, char indice[]);
char *especialidadesMedicas();
void agendaDeAtendimento(int *agenda[][5]);
void consultarAgenda(TArvoreBB *raiz, FILE *arqMedico, char crm[]);
void manutencaoArqMedico(FILE * arq);
void pesquisarPorEspecialidade(FILE *arqMedico, char especialidade[]);
int verificarHorarioDeAtendimento(FILE *arqMedico, int dia, int turno, int posicao);
