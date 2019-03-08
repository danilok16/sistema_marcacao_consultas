#include"types.h"

void marcarConsulta(TArvoreBB *arvore_cliente, TArvoreBB *arvore_medico, FILE *arqConsulta, FILE *arqMedico);
void consultarPacientes(TArvoreBB *arvore_cliente, FILE *arqConsulta, FILE *arqCliente, TConsulta consultap);
int validarMarcarConsulta(FILE *arqConsulta, TConsulta consultap);
void desmarcarConsulta(char cpf[], char crm[], TData dat, int turno, FILE *arqConsulta, TArvoreBB *arvore_cliente);
void consultarConsultas(FILE *arqConsulta, FILE *arqMedico, TArvoreBB *arvore_cliente, TArvoreBB *arvore_medico, char cpf[]);
void listarFilaDeEspera(FILE *arqConsulta, TConsulta consultap, TArvoreBB *arvore_cliente, FILE *arqCliente, FILE *arqMedico, TArvoreBB *arvore_medico);
int consultarVagas(FILE *arqConsulta, char crm[], int turno, TData data);
int colocarClienteNalistaDeAtendimento(FILE *arqConsulta, TConsulta consultap);
void finalizarConsultas(FILE *arqConsulta);