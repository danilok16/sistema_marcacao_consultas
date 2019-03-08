#define TRUE 1
#define FALSE 0
#define MARCADO 1
#define ESPERA 2
#define CONCLUIDO 3
#define CANCELADO 4

#include<stdio.h>
#include<stdlib.h>
//TYPES.H
#include<string.h>
#include<Windows.h>
#include <locale.h>
#include <time.h>
#include"view.h"
#include <conio.h>

#ifndef ESTRUTURAS
#define ESTRUTURAS

typedef struct ArvoreBB{
	char indice[11]; //ajustar
	int pos;
	struct ArvoreBB *esq, *dir;
}TArvoreBB;

typedef struct Data {
	int ano;
	int mes;
	int dia;
}TData;
typedef struct Pessoa {
	char nome[50];
	char telefone[60];
	char email[50];
	int status;
}TPessoa;

typedef struct Cliente {
	char cpf[11];
	TPessoa cliente;
}TCliente;

typedef struct Medico {
	char crm[9];
	char especialidade[30];
	TPessoa medico;
	int tabelaHorario[2][5];


}TMedico;

typedef struct Consulta {
	TCliente cliente;
	TMedico medico;
	TData data;
	int turno;
	int status;
}TConsulta;


typedef struct Nomes {
	char nome[50];
	int pos;
	struct Nomes *ant;
	struct Nomes *prox;
}TNomes;

typedef struct EspecialidadesMedicas {
	char nome[100];
	int pos;
}TEspecialidadesMedicas;

#endif

//FIM TYPES.H



