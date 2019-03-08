/*
  UNICAP - Universidade Católica de Pernambuco
  Pratica de Programação
  Aluno: Danilo Alves Da Silva
  Projeto: Sistema de marcação de consultas para uma clinica
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cliente.h"
#include"medico.h"
#include "consultas.h"
#include"metodos_especiais.h"
#include<Windows.h>
#include <conio.h>
#include "view.h"
#include"validações.h"


void menu();
void ajuda();
void menuConsulta(TArvoreBB **arvore_cliente, TArvoreBB **arvore_medico, FILE *arqConsulta, FILE *arqMedico, FILE *arqCliente);
void menuCliente(TArvoreBB **arvore_cliente, FILE *arqCliente, TNomes **nameList);
void menuMedico(TArvoreBB **arvore_medico, FILE *arqMedico, TNomes **nameList);


int main() {
	char cpf[15], nome[50];
	char z;
	int opc = 1, posArqCliente, x, y, sair = FALSE;
	int ch, voltar, recup;
	TArvoreBB *arvore_cliente = NULL, *arvore_medico = NULL;
	TNomes *nameList = NULL; //lista, utilazado pela funcão procurar por nome
	FILE *arqCliente, *arqMedico, *arqConsultas;
	arqCliente = criarArquivoIndexado("Clientes.bin", &arvore_cliente);//testar
	arqMedico = criarArquivoIndexado("Medicos.bin", &arvore_medico);
	arqConsultas = criarArquivo("Consultas.bin");
	finalizarConsultas(arqConsultas);
	//TMedico m;
  
	
	do {
		opc = 1;
		system("cls");
		menu();
		x = 1, y = 1;
		posicaoCursor(x, y);
		printf(">");
		while (opc != 5) {
			ch = getch();
			setbuf(stdin, NULL);
			if (ch == 224) {

				switch (getch()) {
				case acima:
					if (y < 5) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, ++y);
						printf(">");
					} break;
				case abaixo:
					if (y > 1) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, --y);
						printf(">");
					}  break;
				defalte: break;
				}  setbuf(stdin, NULL);
			}
			else if (ch == enter) {
				
				switch (y) {
				case 1:menuConsulta(&arvore_cliente, &arvore_medico, arqConsultas, arqMedico, arqCliente);opc = 5;
					break;
				case 2: menuCliente(&arvore_cliente, arqCliente, &nameList);opc = 5;
					break;
				case 3:menuMedico(&arvore_medico, arqMedico, &nameList);opc = 5;
					break;
				case 4:ajuda();opc = 5;
					break;
				case 5:opc = 5;sair = TRUE;
					break;
				}
			}
			else if (ch == voltar1 || ch == voltar2) {
				opc = 5; sair = TRUE;
			}
		}
	} while (sair == FALSE);
	manutencaoArqCliente(arqCliente);
	manutencaoArqMedico(arqMedico);
	fclose(arqCliente);//testar
	fclose(arqMedico); //testar
	fclose(arqConsultas);
	desindexarArqCliente(&arvore_cliente);
	desindexarArqMedico(&arvore_medico);
	
	system("cls");
	x = 1; y = 7;
	posicionarTela(x, y++);
	return 0;
}

void menu() {
	printf("ÚÄÄÄÄÄÄÄÄÄÄÄMENU PRINCIPALÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("³   MARCACAO DE CONSULTAS            ³\n");
	printf("³   CLIENTES                         ³\n");
	printf("³   MEDICOS                          ³\n");
	printf("³   AJUDA                            ³\n");
	printf("³   SAIR                             ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
}

void menuConsulta(TArvoreBB **arvore_cliente, TArvoreBB **arvore_medico, FILE *arqConsulta, FILE *arqMedico, FILE *arqCliente) {
	TConsulta consulta;
	int ch, sair = FALSE, flag, teste, result;
	int opc, x, y;
	char data[11];

	do {
		opc = 1;
		telaConsulta(0);//tela de menu de consultas
		x = 1, y = 1;
		posicaoCursor(x, y);
		printf(">");
		while (opc != 6) {
			ch = getch();
			setbuf(stdin, NULL);
			if (ch == 224) {

				switch (getch()) {
				case acima:
					if (y < 6) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, ++y);
						printf(">");
					} break;
				case abaixo:
					if (y > 1) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, --y);
						printf(">");
					}  break;
				defalte: break;
				}  setbuf(stdin, NULL);
			}

			else if (ch == enter) {
				switch (y) {
				case 1: setbuf(stdin, NULL);//marcar consulta
					telaConsulta(1);
					marcarConsulta(*arvore_cliente, *arvore_medico, arqConsulta, arqMedico);
					opc = 6;break;
				case 2:setbuf(stdin, NULL);
					telaConsulta(2);
					x = 8; y = 1;
					posicaoCursor(x, y);
					strcpy(consulta.medico.crm, lerCrm(x, y));
					if (strcmp(consulta.medico.crm, "cancelar") == 0) {
						opc = 6;break;
					}
					while (validarCrm(consulta.medico.crm) == 0) {
						telaAviso(20);//ajeitar
						x = 8; y = 1;
						limparLinha(consulta.medico.crm, x, y);
						posicionarTela(x, y);
						strcpy(consulta.medico.crm, lerCrm(x, y));
						if (strcmp(consulta.medico.crm, "cancelar") == 0) {
							opc = 6;break;
						}
					}
					if (strcmp(consulta.medico.crm, "cancelar") == 0) {
						opc = 6;break;
					}
					limparTelaDeAviso(10, 5, 3);
					x = 8; y = 2;
					posicaoCursor(x, y);
					strcpy(data, lerData(x, y));
					teste = validarData(data);
					while (teste == 0) {
						telaAviso(21);
						strcpy(data, lerData(x,y));
						teste = validarData(data);
					}
					sscanf(data, "%d.%d.%d", &consulta.data.dia, &consulta.data.mes, &consulta.data.ano);
					limparTelaDeAviso(10, 5, 3);
					x = 8; y = 3;
					posicaoCursor(x, y);
					scanf("%d", &consulta.turno);
					consultarPacientes(*arvore_cliente, arqConsulta,arqCliente, consulta);
					opc = 6;break;
				case 3:system("cls");
					telaConsulta(3);
					x = 8; y = 1;
					posicaoCursor(x, y);
					strcpy(consulta.cliente.cpf, lerCpf(x, y));
					if (strcmp(consulta.cliente.cpf, "cancelar") == 0) {
						opc = 6;break;
					}
					while (validarCpf(consulta.cliente.cpf) == 0) {
						telaAviso(7);
						x = 8; y = 1;
						limparLinha(consulta.cliente.cpf, x, y);
						posicionarTela(x, y);
						strcpy(consulta.cliente.cpf, lerCpf(x, y));
						if (strcmp(consulta.cliente.cpf, "cancelar") == 0) {
							opc = 6;break;
						}

					}
					if (strcmp(consulta.cliente.cpf, "cancelar") == 0) {
						opc = 6;break;
					}
					consultarConsultas(arqConsulta, arqMedico, *arvore_cliente, *arvore_medico, consulta.cliente.cpf);
					opc = 6;break;
				case 4:
					telaConsulta(4);
					x = 8; y = 1;
					posicaoCursor(x, y);
					strcpy(consulta.cliente.cpf, lerCpf(x, y));
					if (strcmp(consulta.cliente.cpf, "cancelar") == 0) {
						opc = 6;break;
					}
					while (validarCpf(consulta.cliente.cpf) == 0) {
						telaAvisoConsulta(1);
						x = 8; y = 1;
						limparLinha(consulta.cliente.cpf, x, y);
						posicionarTela(x, y);
						strcpy(consulta.cliente.cpf, lerCpf(x, y));
						if (strcmp(consulta.cliente.cpf, "cancelar") == 0) {
							opc = 6;break;
						}

					}
					if (strcmp(consulta.cliente.cpf, "cancelar") == 0) {
						opc = 6;break;
					}
					limparTelaDeAviso(15, 5, 3);
					result = buscaPorCpf(*arvore_cliente, consulta.cliente.cpf);
					if(result == -1) {
						telaAviso(8);
						system("pause");
						return;
					}
					x = 8; y = 2;
					posicaoCursor(x, y);
					setbuf(stdin, NULL);
					strcpy(consulta.medico.crm, lerCrm(x, y));
					if (strcmp(consulta.medico.crm, "cancelar") == 0) {
						opc = 6;break;
					}
					while (validarCrm(consulta.medico.crm) == 0) {
						telaAvisoConsulta(2);
						x = 8; y = 2;
						limparLinha(consulta.medico.crm, x, y);
						posicionarTela(x, y);
						strcpy(consulta.medico.crm, lerCrm(x, y));
						if (strcmp(consulta.medico.crm, "cancelar") == 0) {
							opc = 6;break;
						}
					}
					if (strcmp(consulta.medico.crm, "cancelar") == 0) {
						opc = 6;break;
					}
					limparTelaDeAviso(15, 5, 3);
					setbuf(stdin, NULL);
					result = buscaPorCrm(*arvore_medico, consulta.medico.crm);
					if (result == -1) {
						telaAviso(9);
						system("pause");
						return;
					}
					x = 8; y = 3;
					strcpy(data, lerData(x, y));
					teste = validarData(data);
					while (teste == 0) {
						telaAviso(21);
						strcpy(data, lerData(x,y));
						teste = validarData(data);
					}
					limparTelaDeAviso(10, 5, 3);
					sscanf(data, "%d.%d.%d", &consulta.data.dia, &consulta.data.mes, &consulta.data.ano);
					x = 9; y = 4;
					posicaoCursor(x, y);
					scanf("%d", &consulta.turno);
					desmarcarConsulta(consulta.cliente.cpf, consulta.medico.crm,consulta.data, consulta.turno , arqConsulta, *arvore_cliente);
					opc = 6;break;
				case 5:setbuf(stdin, NULL);
					telaConsulta(5);
					/*x = 8; y = 1;
					posicaoCursor(x, y);
					gets(consulta.medico.crm);
					x = 8; y = 2;
					posicaoCursor(x, y);
					strcpy(data, lerData(x, y));
					teste = validarData(data);
					while (teste == 0) {
						printf("data invalida!");
						system("pause");
						system("cls");
						strcpy(data, lerData(x, y));
						teste = validarData(data);
					}
					sscanf(data, "%d.%d.%d", &consulta.data.dia, &consulta.data.mes, &consulta.data.ano);
					x = 8; y = 3;
					posicaoCursor(x, y);
					scanf("%d", &consulta.turno);*/
					x = 8; y = 1;
					posicaoCursor(x, y);
					strcpy(consulta.medico.crm, lerCrm(x, y));
					if (strcmp(consulta.medico.crm, "cancelar") == 0) {
						opc = 6;break;
					}
					while (validarCrm(consulta.medico.crm) == 0) {
						telaAviso(20);//ajeitar
						x = 8; y = 1;
						limparLinha(consulta.medico.crm, x, y);
						posicionarTela(x, y);
						strcpy(consulta.medico.crm, lerCrm(x, y));
						if (strcmp(consulta.medico.crm, "cancelar") == 0) {
							opc = 6;break;
						}
					}
					if (strcmp(consulta.medico.crm, "cancelar") == 0) {
						opc = 6;break;
					}
					limparTelaDeAviso(10, 5, 3);
					x = 8; y = 2;
					posicaoCursor(x, y);
					strcpy(data, lerData(x, y));
					teste = validarData(data);
					while (teste == 0) {
						telaAviso(21);
						strcpy(data, lerData(x, y));
						teste = validarData(data);
					}
					sscanf(data, "%d.%d.%d", &consulta.data.dia, &consulta.data.mes, &consulta.data.ano);
					limparTelaDeAviso(10, 5, 3);
					x = 8; y = 3;
					posicaoCursor(x, y);
					scanf("%d", &consulta.turno);

					listarFilaDeEspera(arqConsulta, consulta, *arvore_cliente, arqCliente, arqMedico, *arvore_medico);
					opc = 6;break;
				case 6: opc = 6; sair = TRUE;
					break;
				}
			}
			else if (ch == voltar1 || ch == voltar2) {
				opc = 6; sair = TRUE;
			}
		}
	} while (sair == FALSE);

	
}

void menuCliente(TArvoreBB **arvore_cliente, FILE *arqCliente, TNomes **nameList) {
	int ch, sair = FALSE, flag;
	int opc , posArqCliente, x, y;
	char z;
	TCliente c;


	do {
		opc = 1;
		telaCliente(1);//tela menu de clientes
		x = 1, y = 1;
		posicaoCursor(x, y);
		printf(">");
		while (opc != 7) {
			ch = getch();
			setbuf(stdin, NULL);
			if (ch == 224) {

				switch (getch()) {
				case acima:
					if (y < 7) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, ++y);
						printf(">");
					} break;
				case abaixo:
					if (y > 1) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, --y);
						printf(">");
					}  break;
				defalte: break;
				}  setbuf(stdin, NULL);
			}

			else if (ch == enter) {
				switch (y) {
				case 1: setbuf(stdin, NULL);
					telaCliente(2);// tela de cadastrar cliente
					x = 8; y = 1;
					posicionarTela(x, y);
					//flag = lerCpf(c.cpf);
					strcpy(c.cpf, lerCpf(x, y));
					if (strcmp(c.cpf, "cancelar") == 0) {
						opc = 7;break;
					}
					while (validarCpf(c.cpf) == 0) {
						telaAviso(1);
						x = 8; y = 1;
						limparLinha(c.cpf, x, y);
						posicionarTela(x, y);
						strcpy(c.cpf, lerCpf(x, y));
						if (strcmp(c.cpf, "cancelar") == 0) {
							opc = 7;break;
						}
					}
					if (strcmp(c.cpf, "cancelar") == 0) {
						opc = 7;break;
					}
						setbuf(stdin, NULL);
						cadastrarCliente(&(*arvore_cliente), arqCliente, c.cpf);
						x = 4, y = 14;
						posicionarTela(x, y);
					opc = 7;
					break;
				case 2:system("cls");
					printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ CLIENTES ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
					listarCliente(*arvore_cliente, arqCliente);
					opc = 7;

					system("pause");
					break;
				case 3:setbuf(stdin, NULL);
					telaCliente(3);//tela de alterar cadastro de cliente
					mensagemErro(10);
					x = 29; y = 1;
					posicionarTela(x, y);
					strcpy(c.cpf, lerCpf(x, y));
					if (strcmp(c.cpf, "cancelar") == 0) {
						opc = 7;break;
					}
					while (validarCpf(c.cpf) == 0) {
						mensagemErro(7);
						x = 29; y = 1;
						limparLinha(c.cpf, x, y);
						posicionarTela(x, y);
						strcpy(c.cpf, lerCpf(x, y));
						if (strcmp(c.cpf, "cancelar") == 0) {
							opc = 7;break;
						}

					}
					if (strcmp(c.cpf, "cancelar") == 0) {
						opc = 7;break;
					}
				    alterarCadastroCliente(*arvore_cliente, arqCliente, c.cpf);
				    opc = 7;
					x = 3; y = 10;
				    posicionarTela(x, y++);
					system("pause");
					opc = 7;
					break;
				case 4: setbuf(stdin, NULL);
					telaCliente(4); // tela de exibir dados de um cliente
					mensagemErro(10);
					x = 29; y = 1;
					posicionarTela(x, y);
					strcpy(c.cpf, lerCpf(x, y));
					if (strcmp(c.cpf, "cancelar") == 0) {
						opc = 7;break;
					}
					while (validarCpf(c.cpf) == 0) {
						mensagemErro(7);
						x = 29; y = 1;
						limparLinha(c.cpf, x, y);
						posicionarTela(x, y);
						strcpy(c.cpf, lerCpf(x, y));
						if (strcmp(c.cpf, "cancelar") == 0) {
							opc = 7;break;
						}
					}
					if (strcmp(c.cpf, "cancelar") == 0) {
						opc = 7;break;
					}
						exibirCliente(*arvore_cliente, arqCliente, c.cpf);
						system("pause");
					opc = 7;
					break;
				case 5: setbuf(stdin, NULL);
					telaCliente(5); // tela de remover cadastro d um cliente
					mensagemErro(10);
					x = 29; y = 1;
					posicionarTela(x, y);
					strcpy(c.cpf, lerCpf(x, y));
					if (strcmp(c.cpf, "cancelar") == 0) {
						opc = 7;break;
					}
					while (validarCpf(c.cpf) == 0) {
						mensagemErro(7);
						x = 29; y = 1;
						limparLinha(c.cpf, x, y);
						posicionarTela(x, y);
						strcpy(c.cpf, lerCpf(x, y));
						if (strcmp(c.cpf, "cancelar") == 0) {
							opc = 7;break;
						}
					}
					if (strcmp(c.cpf, "cancelar") == 0) {
						opc = 7;break;
					}
						removerCliente(&(*arvore_cliente), arqCliente, c.cpf);
					opc = 7;
					break;
				case 6:setbuf(stdin, NULL);
					telaCliente(6); // tela de pesquisar cliente por nome
					x = 28; y = 1;
					posicionarTela(x, y);
					gets(c.cliente.nome);
					setbuf(stdin, NULL);
					strupr(c.cliente.nome);
					posArqCliente = buscarClientePorNome(arqCliente, &(*nameList), c.cliente.nome);
					opc = 7;
					break;
				case 7: opc = 7; sair = TRUE;
					break;
				}
			}
			else if (ch == voltar1 || ch == voltar2) {
				opc = 7; sair = TRUE;
			}
		}
	} while (sair == FALSE);

}

void menuMedico(TArvoreBB **arvore_medico, FILE *arqMedico, TNomes **nameList) {
	int opc, x, y;
	int ch, sair = FALSE;
	char z;
	TMedico m;

	do {
		opc = 1;
		system("cls");
		telaMedico(1);//tela de menu de medicos
		x = 1, y = 1;
		posicaoCursor(x, y);
		printf(">");
		while (opc != 8) {
			ch = getch();
			setbuf(stdin, NULL);
			if (ch == 224) {

				switch (getch()) {
				case acima:
					if (y < 8) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, ++y);
						printf(">");
					} break;
				case abaixo:
					if (y > 1) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x, --y);
						printf(">");
					}  break;
				defalte: break;//??
				}  setbuf(stdin, NULL);
			}

			else if (ch == enter) {
				switch (y) {
				case 1: setbuf(stdin, NULL);
					system("cls");
					telaMedico(2);//tela de cadastro
					x = 8; y = 1;
					posicionarTela(x, y);
					strcpy(m.crm, lerCrm(x, y));
					if (strcmp(m.crm, "cancelar") == 0) {
						opc = 8;break;
					}
					while (validarCrm(m.crm) == 0) {
						telaAviso(20);//ajeitar
						x = 8; y = 1;
						limparLinha(m.crm, x, y);
						posicionarTela(x, y);
						strcpy(m.crm, lerCrm(x, y));
						if (strcmp(m.crm, "cancelar") == 0) {
							opc = 8;break;
						}
					}
					if (strcmp(m.crm, "cancelar") == 0) {
						opc = 8;break;
					}
					cadastrarMedico(&(*arvore_medico), arqMedico, m.crm);
					setbuf(stdin, NULL);
					opc = 8;
					break;
				case 2: system("cls");
					printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ MEDICOS ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
					listarMedico(*arvore_medico, arqMedico);
					system("pause");
					opc = 8;
					break;
				case 3:setbuf(stdin, NULL);
					telaMedico(3);//tela de alterar cadastro
					x = 28; y = 1;
					posicionarTela(x, y);
					gets(m.crm);
					setbuf(stdin, NULL);
					alterarCadastroMedico(*arvore_medico, arqMedico, m.crm);
					system("pause");
					opc = 8;
					break;
				case 4: setbuf(stdin, NULL);
					telaMedico(4);//tela de consultar por nome
					x = 28; y = 1;
					posicionarTela(x, y);
					gets(m.medico.nome);
					setbuf(stdin, NULL);
					strupr(m.medico.nome);
					buscarMedicoPorNome(arqMedico, &(*nameList), m.medico.nome);
					opc = 8;
					break;
				case 5:setbuf(stdin, NULL);
					telaMedico(5);//tela de excluir cadastro
					x = 28; y = 1;
					posicionarTela(x, y);
					gets(m.crm);
					setbuf(stdin, NULL);
					removerMedico(&(*arvore_medico), arqMedico, m.crm);
					opc = 8;
					break;
				case 6:setbuf(stdin, NULL);
					telaMedico(6); //tela de pesquisar por especialidade
					strcpy(m.especialidade, especialidadesMedicas());
					pesquisarPorEspecialidade(arqMedico, m.especialidade);
					opc = 8;
					break;
				case 7:setbuf(stdin, NULL);
					system("cls");
					printf("ÚÄÄÄÄ CONSULTAR HORARIOS DE ATENDIMENTO ÄÄÄÄ¿\n");
					printf("³ INFORME O CRM DO MEDICO:                  ³\n");
					printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
					x = 28; y = 1;
					posicionarTela(x, y);
					gets(m.crm);
					setbuf(stdin, NULL);
					consultarAgenda(*arvore_medico, arqMedico, m.crm);
					system("pause");
					opc = 8;
					break;
				case 8: opc = 8; sair = TRUE;
					break;
				}
			}
			else if (ch == voltar1 || ch == voltar2) {
				opc = 8; sair = TRUE;
			}
		}
	} while (sair == FALSE);
}


void ajuda() {
	int x = 3, y = 10;
	system("cls");
	printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ COMO NAVEGAR ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("³                                                      ³\n");
	printf("³  UTILIZE AS SETAS PARA NAVEGAR ENTRE AS OPCOES       ³\n");
	printf("³  UTILIZE A TECLA ENTER PARA SELICONAR A OPCAO        ³\n");
	printf("³  UTILIZE A TECLA ESC / BACKSPACE PARA VOLTAR         ³\n");
	printf("³                                                      ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	posicaoCursor(x, y);
	system("pause");

}

//FIM PRINCIPAL.C