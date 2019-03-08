//CONSULTA.C
#include "types.h"
#include "cliente.h"
#include "medico.h"
#include "validações.h"

int consultarVagas(FILE *arqConsulta, char crm[], int turno, TData data) {
	int qtdVagas = 0, teste;
	TConsulta consulta;

	fseek(arqConsulta, 0, 0);
	while (1) {
		teste = fread(&consulta, sizeof(TConsulta), 1, arqConsulta);
		if (teste != 1) {
			if (!feof(arqConsulta)) {
				printf("Erro na leitura!\n");
			}
			break;
		}
		else if (feof(arqConsulta)) {
			break;
		}
		else {
			if (strcmp(crm, consulta.medico.crm) == 0 && consulta.status == MARCADO && turno == consulta.turno 
				&& consulta.data.dia == data.dia && consulta.data.mes == data.mes && consulta.data.ano == data.ano) {
				qtdVagas++;
			}
			/*if (qtdVagas == 3) {//ajeitar
				break;
			}*/
		}
	}
	return qtdVagas;
	/*if(qtdVagas < 3) {//AJEITAR
		return 1;
	}
	else {
		return 0;
	}*/
}

void marcarConsulta(TArvoreBB *arvore_cliente, TArvoreBB *arvore_medico, FILE *arqConsulta, FILE *arqMedico) {
	int result, retorno, diaDaSemana, teste = 0, resp, flag;
	char data[11];
	int x, y;
	TConsulta consulta;
//	TData data;
	x = 8; y = 1;
	posicaoCursor(x, y);
	strcpy(consulta.cliente.cpf, lerCpf(x, y));
	if (strcmp(consulta.cliente.cpf, "cancelar") == 0) {
		return;
	}
	while (validarCpf(consulta.cliente.cpf) == 0) {
		telaAvisoConsulta(1);
		x = 8; y = 1;
		limparLinha(consulta.cliente.cpf, x, y);
		posicionarTela(x, y);
		strcpy(consulta.cliente.cpf, lerCpf(x, y));
		if (strcmp(consulta.cliente.cpf, "cancelar") == 0) {
			return;
		}

	}
	if (strcmp(consulta.cliente.cpf, "cancelar") == 0) {
		return;
	}
	limparTelaDeAviso(15, 5, 3);
	setbuf(stdin, NULL);
	result = buscaPorCpf(arvore_cliente, consulta.cliente.cpf);
	if (result == -1) {
		telaAviso(8);
		system("pause");
		return;
	}
	x = 8; y = 2;
	posicaoCursor(x, y);
	strcpy(consulta.medico.crm, lerCrm(x, y));
	if (strcmp(consulta.medico.crm, "cancelar") == 0) {
		return;
	}
	while (validarCrm(consulta.medico.crm) == 0) {
		telaAvisoConsulta(2);
		x = 8; y = 2;
		limparLinha(consulta.medico.crm, x, y);
		posicionarTela(x, y);
		strcpy(consulta.medico.crm, lerCrm(x, y));
		if (strcmp(consulta.medico.crm, "cancelar") == 0) {
			return;
		}
	}
	if (strcmp(consulta.medico.crm, "cancelar") == 0) {
		return;
	}
	limparTelaDeAviso(15, 5, 3);
	setbuf(stdin, NULL);
	result = buscaPorCrm(arvore_medico, consulta.medico.crm);
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
	//printf("\n->%d / %d / %d", consulta.data.dia, consulta.data.mes, consulta.data.ano);
	x = 9; y = 4;
	posicaoCursor(x, y);
	scanf("%d", &consulta.turno);
	diaDaSemana = calculo_dia_da_semana(consulta.data);//calcula o dia da semana, seg, terca...
	retorno = verificarHorarioDeAtendimento(arqMedico, diaDaSemana, consulta.turno, result);
	if (retorno == 0) {//ajeita
		telaAvisoConsulta(5);//tela que informa que o medico não atende nesse horario
		posicionarTela(4, 9);
		system("pause");
		return;
	}
	retorno = validarMarcarConsulta(arqConsulta, consulta);
	if (retorno == 1) {
		telaAvisoConsulta(4);//tela que informe que o cliente já foi agendado
		system("pause");
		return;
	}
	result = consultarVagas(arqConsulta, consulta.medico.crm, consulta.turno, consulta.data);
	if (result == 3) {
		consulta.status = ESPERA;
		telaAvisoConsulta(6);
		setbuf(stdin, NULL);
		scanf("%d", &resp);
		if (resp == 0) {
			return;
		}
		else {
			consulta.status = ESPERA;
			flag = 1;
		}
	}
	else {
		consulta.status = MARCADO;
	}
	fseek(arqMedico, 0, 2);
	teste = fwrite(&consulta, sizeof(TConsulta), 1, arqConsulta);
	if (teste != 1) {
		printf("Erro ao gravar no arquivo\n");
		exit(1);
	}
	else {
		if (flag != 1) {
			telaAvisoConsulta(7);
		}
		else {
			telaAvisoConsulta(8);
		}
		system("pause");
	}
}

int calculo_dia_da_semana(TData data){
	int dia, mes, ano;
	dia = data.dia; mes = data.mes; ano = data.ano;
	/*TData data = dataDoSistema();
	dia = data.dia;mes = data.mes; ano = data.ano;*/

	switch (mes)
	{
	case 1: break;
	case 2: dia += 31; break;
	case 3: dia += 59; break;
	case 4: dia += 90; break;
	case 5: dia += 120; break;
	case 6: dia += 151; break;
	case 7: dia += 181; break;
	case 8: dia += 212; break;
	case 9: dia += 243; break;
	case 10: dia += 273; break;
	case 11: dia += 304; break;
	case 12: dia += 334; break;
	}
	/* Se o ano é um ano-bisexto E
	Se o mes de fevereiro ja passou entao acrescente um dia ao deslocamento*/
	if (((ano % 4) == 0) && (((ano % 100) != 0) || ((ano % 400) == 0)) && (mes > 2))
		dia += 1;
	dia += -1 + (ano - 1) * 365 + (ano - 1) / 4 - (ano - 1) / 100 + (ano - 1) / 400;

	switch (dia % 7)
	{
	case 0: return 0;
	case 1: return 1;
	case 2: return 2;
	case 3: return 3;
	case 4: return 4;
	case 5: return 5;
	case 6: return 6;
	}
}

void consultarPacientes(TArvoreBB *arvore_cliente, FILE *arqConsulta, FILE *arqCliente, TConsulta consultap) {
	int teste, result;
	TCliente c;
	TConsulta consulta;

	fseek(arqConsulta, 0, 0);
	while (1) {
		teste = fread(&consulta, sizeof(TConsulta), 1, arqConsulta);
		if (teste != 1) {
			if (!feof(arqConsulta)) {
				printf("Erro na leitura!\n");
			}
			break;
		}
		else if (feof(arqConsulta)) {
			break;
		}
		else if (strcmp(consultap.medico.crm, consulta.medico.crm) == 0 && consulta.status == MARCADO && consultap.turno == consulta.turno
			&& consulta.data.dia == consultap.data.dia && consulta.data.mes == consultap.data.mes && consulta.data.ano == consultap.data.ano) {
			result = buscaPorCpf(arvore_cliente, consulta.cliente.cpf);
			if (result == -1) {
				mensagemErro(8);
			}
			else {
				fseek(arqCliente, result * sizeof(TCliente), 0);
				teste = fread(&c, sizeof(TCliente), 1, arqCliente);
				if (teste != 1) {
					if (!feof(arqCliente)) {
						printf("Erro na leitura");
					}
				}
				else {
					printf(" NOME: %s\n", c.cliente.nome);
				}
			}
		}
	}
	system("pause");

}

void consultarConsultas(FILE *arqConsulta, FILE *arqMedico, TArvoreBB *arvore_cliente, TArvoreBB *arvore_medico, char cpf[]) {
	int result, teste;
	TConsulta consulta;
	TMedico m;


	result = buscaPorCpf(arvore_cliente, cpf);
	if (result == -1) {
		telaAviso(8);
	}
	else {
		system("cls");
		fseek(arqConsulta, 0, 0);
		while (1) {
			teste = fread(&consulta, sizeof(TConsulta), 1, arqConsulta);
			if (teste != 1) {
				if (!feof(arqConsulta)) {
					printf("Erro na leitura!\n");
				}
				break;
			}
			else if (feof(arqConsulta)) {
				break;
			}
			else {
				if (strcmp(cpf, consulta.cliente.cpf) == 0 && consulta.status == MARCADO) {
					result = buscaPorCrm(arvore_medico, consulta.medico.crm);
					if (result == -1) {
						mensagemErro(9);//alterar
					}
					else {
						fseek(arqMedico, result * sizeof(TMedico), 0);
						teste = fread(&m, sizeof(TMedico), 1, arqMedico);
						if (teste != 1) {
							if (!feof(arqMedico)) {
								printf("Erro na leitura");
							}
						}
						else {
							printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
							printf("MEDICO: %s\n", m.medico.nome);
							printf("CRM: %s\n", m.crm);
							printf("ESPECIALIDADE: %s\n", m.especialidade);
							printf("DATA: %d/%d/%d\n", consulta.data.dia, consulta.data.mes, consulta.data.ano);
							printf("TURNO: %d\n", consulta.turno);
							printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
						}
					}
				}
				else {
					telaAvisoConsulta(10);
				}
			}
		}
	}
	system("pause");
}

void desmarcarConsulta(char cpf[], char crm[], TData data, int turno, FILE *arqConsulta, TArvoreBB *arvore_cliente) {//data
	int result, teste;
	TConsulta consulta;

	fseek(arqConsulta, 0, 0);
	while (1) {
		teste = fread(&consulta, sizeof(TConsulta), 1, arqConsulta);
		if (teste != 1) {
			if (!feof(arqConsulta)) {
				printf("Erro na leitura!\n");
			}
			break;
		}
		else if (feof(arqConsulta)) {
			break;
		}
		else {
			if (strcmp(cpf, consulta.cliente.cpf) == 0 && strcmp(crm, consulta.medico.crm) == 0 && consulta.status == MARCADO  && turno == consulta.turno
				&& consulta.data.dia == data.dia && consulta.data.mes == data.mes && consulta.data.ano == data.ano) {
				consulta.status = CANCELADO;
				fseek(arqConsulta, -1 * sizeof(TConsulta), 1);
				teste = fwrite(&consulta, sizeof(TConsulta), 1, arqConsulta);
				if (teste != 1) {
					printf("Erro na gravacao!\n");
				}
				else {
					fflush(arqConsulta);
					telaAvisoConsulta(9);
					posicionarTela(3, 8);
					colocarClienteNalistaDeAtendimento(arqConsulta, consulta);
					fseek(arqConsulta, 0, 2);
				}

			}
		}
	}

	system("pause");
}

void listarFilaDeEspera(FILE *arqConsulta, TConsulta consultap, TArvoreBB *arvore_cliente, FILE *arqCliente, FILE *arqMedico, TArvoreBB *arvore_medico) {
	int qtdVagas = 0, teste, result, diaDaSemana, retorno;
	TConsulta consulta;
	TCliente c;

	setbuf(stdin, NULL);
	result = buscaPorCrm(arvore_medico, consultap.medico.crm);
	if (result == -1) {
		telaAviso(9);
		system("pause");
		return;
	}
	diaDaSemana = calculo_dia_da_semana(consultap.data);//calcula o dia da semana, seg, terca...
	retorno = verificarHorarioDeAtendimento(arqMedico, diaDaSemana, consultap.turno, result);
	if (retorno == 0) {//ajeita
		telaAvisoConsulta(5);//tela que informa que o medico não atende nesse horario
		posicionarTela(4, 9);
		system("pause");
		return;
	}
	result = consultarVagas(arqConsulta, consultap.medico.crm, consultap.turno, consultap.data);
	system("cls");
	if (result < 3) {
		printf("\nO MEDICO POSSUI: %d VAGAS PARA ESSA DATA\n\n", 10-result);
		system("pause");
		return;
	}
	else {
		fseek(arqConsulta, 0, 0);
		while (1) {
			teste = fread(&consulta, sizeof(TConsulta), 1, arqConsulta);
			if (teste != 1) {
				if (!feof(arqConsulta)) {
					printf("Erro na leitura!\n");
				}
				break;
			}
			else if (feof(arqConsulta)) {
				break;
			}
			else {
				if (strcmp(consultap.medico.crm, consulta.medico.crm) == 0 && consulta.status == ESPERA && consultap.turno == consulta.turno
					&& consulta.data.dia == consultap.data.dia && consulta.data.mes == consultap.data.mes && consulta.data.ano == consultap.data.ano) {
					result = buscaPorCpf(arvore_cliente, consulta.cliente.cpf);
					if (result == -1) {
						mensagemErro(8);
					}
					else {
						fseek(arqCliente, result * sizeof(TCliente), 0);
						teste = fread(&c, sizeof(TCliente), 1, arqCliente);
						if (teste != 1) {
							if (!feof(arqCliente)) {
								printf("Erro na leitura");
							}
						}
						else {
							printf("\nNOME: %s\n", c.cliente.nome);
						}
					}
				}
			}
		}
	}
	system("pause");
}

int colocarClienteNalistaDeAtendimento(FILE *arqConsulta, TConsulta consultap) {
	int teste, result;
	TConsulta consulta;


	fseek(arqConsulta, 0, 0);
	while (1) {
		teste = fread(&consulta, sizeof(TConsulta), 1, arqConsulta);
		if (teste != 1) {
			if (!feof(arqConsulta)) {
				printf("Erro na leitura!\n");
			}
			break;
		}
		else if (feof(arqConsulta)) {
			break;
		}
		else {
			if (strcmp(consultap.medico.crm, consulta.medico.crm) == 0 && consulta.status == ESPERA && consultap.turno == consulta.turno
				&& consulta.data.dia == consultap.data.dia && consulta.data.mes == consultap.data.mes && consulta.data.ano == consultap.data.ano) {
				consulta.status = MARCADO;
				fseek(arqConsulta, -1 * sizeof(TConsulta), 1);
				teste = fwrite(&consulta, sizeof(TConsulta), 1, arqConsulta);
				if (teste != 1) {
					printf("Erro na gravacao!\n");
				}
				else {
					fflush(arqConsulta);
					fseek(arqConsulta, 0, 2);
				}
				
			}
		}
	}


}

int validarMarcarConsulta(FILE *arqConsulta, TConsulta consultap) {//verifica se o cliente já tem consulta marcada para aquele medico, dia e turno
	int teste, result;
	TCliente c;
	TConsulta consulta;

	fseek(arqConsulta, 0, 0);
	while (1) {
		teste = fread(&consulta, sizeof(TConsulta), 1, arqConsulta);
		if (teste != 1) {
			if (!feof(arqConsulta)) {
				printf("Erro na leitura!\n");
			}
			break;
		}
		else if (feof(arqConsulta)) {
			break;
		}
		else if (strcmp(consultap.medico.crm, consulta.medico.crm) == 0 && strcmp(consultap.cliente.cpf, consulta.cliente.cpf) == 0 && consulta.status == MARCADO && consultap.turno == consulta.turno
			&& consulta.data.dia == consultap.data.dia && consulta.data.mes == consultap.data.mes && consulta.data.ano == consultap.data.ano) {
			return 1;
		}
	}
	return 0;

}

void finalizarConsultas(FILE *arqConsulta) {
	TData dataSistema = dataDoSistema();
	int teste, flag = 0;
	TConsulta consulta;

	fseek(arqConsulta, 0, 0);
	while (1) {
		teste = fread(&consulta, sizeof(TConsulta), 1, arqConsulta);
		if (teste != 1) {
			if (!feof(arqConsulta)) {
				printf("Erro na leitura!\n");
			}
			break;
		}
		else if (feof(arqConsulta)) {
			break;
		}
		else {

			if (consulta.data.dia < dataSistema.dia && consulta.data.mes < dataSistema.mes && consulta.data.ano < dataSistema.ano) {
				consulta.status = CONCLUIDO;
				flag = 1;
			}
			else if (consulta.data.mes == dataSistema.mes && consulta.data.dia < dataSistema.dia && consulta.data.ano == dataSistema.ano) {
				consulta.status = CONCLUIDO;
				flag = 1;
			}
			else if (consulta.data.ano < dataSistema.ano) {
				consulta.status = CONCLUIDO;
				flag = 1;
			}
			if (flag == 1) {
				fseek(arqConsulta, -1 * sizeof(TConsulta), 1);
				teste = fwrite(&consulta, sizeof(TConsulta), 1, arqConsulta);
				if (teste != 1) {
					printf("Erro na gravacao!\n");
				}
				else {
					fflush(arqConsulta);
				}
			}
		}
	}
}
//FIM CONSULTA.C