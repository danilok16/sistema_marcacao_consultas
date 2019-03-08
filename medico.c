//MEDICO.C
#include"types.h"
#include"metodos_especiais.h"
#include"tree.h"
#include"validações.h"



char *especialidadesMedicas() {
	int ch, x, y, opc = 0, sair = FALSE;
	int i;
	TEspecialidadesMedicas list[32];

	strcpy(list[0].nome, "Alergia e Imunologia");
	strcpy(list[1].nome, "Anestesiologia");
	strcpy(list[2].nome, "Cancerologia (oncologia)");
	strcpy(list[3].nome, "Cardiologia");
	strcpy(list[4].nome, "Cirurgia Geral");
	strcpy(list[5].nome, "Cirurgia Pediatrica");
	strcpy(list[6].nome, "Cirurgia Plastica");
	strcpy(list[7].nome, "Cirurgia Toracica");
	strcpy(list[8].nome, "Cirurgia Vascular");
	strcpy(list[9].nome, "Coloproctologia");
	strcpy(list[10].nome, "Dermatologia");
	strcpy(list[11].nome, "Endocrinologia");
	strcpy(list[12].nome, "Endoscopia");
	strcpy(list[13].nome, "Geriatria");
	strcpy(list[14].nome, "Ginecologia");
	strcpy(list[15].nome, "Infectologia");
	strcpy(list[16].nome, "Mastologia");
	strcpy(list[17].nome, "Medicina do Trabalho");
	strcpy(list[18].nome, "Neurocirurgia");
	strcpy(list[19].nome, "Neurologia");
	strcpy(list[20].nome, "Nutrologia");
	strcpy(list[21].nome, "Obstetricia");
	strcpy(list[22].nome, "Oncologia");
	strcpy(list[23].nome, "Oftalmologia");
	strcpy(list[24].nome, "Ortopedia");
	strcpy(list[25].nome, "Traumatologia");
	strcpy(list[26].nome, "Patologia");
	strcpy(list[27].nome, "Pediatria");
	strcpy(list[28].nome, "Psiquiatria");
	strcpy(list[29].nome, "Radiologia");
	strcpy(list[30].nome, "Urologia");
	x = 60, y = 0;
	posicionarTela(x, y++);//exibir especialidades
	printf(" ÚÄÄÄÄÄÄÄÄÄÄESPECIALIDADESÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	for (i = 0; i <= 30; i++) {
		posicionarTela(x, y++);
		printf(" ³ %s                 \n", list[i].nome);
	}
	x = 98, y = 1;
	for (i = 0; i <= 30; i++) {
		posicionarTela(x, y++);
		printf("³");
	}
	x = 61, y = 32;
	posicionarTela(x, y++);
	printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
	x = 59, y = 1;
	posicaoCursor(x, y);
	printf(">");
	while (sair == FALSE) {// navegar entre as especialidades
		ch = getch();
		setbuf(stdin, NULL);
		if (ch == 224) {
			switch (getch()) {
			case acima:
				if (y < 31) {
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
			strupr(list[y - 1].nome);
			return list[y-1].nome;
		}
		else if (ch == voltar1 || ch == voltar2) {
			//*pos = -1; opc = 7; sair = TRUE;
		}
	}



}

void agendaDeAtendimento(int agenda[][5]) {//ajeita pra função alterar
	int linha, coluna, x, y, i, cont = 0, ch, sair = FALSE;


	telaAviso(22);
	telaMedico(15);//tabela para selecionar os horarios de atentimento
	for (linha = 0; linha < 2; linha++) {//preencher as posições que não foram escolhidas
		for (coluna = 0; coluna < 5; coluna++) {
			//posicionarTela(x, y);
			if (agenda[linha][coluna] != TRUE) {
				agenda[linha][coluna] = FALSE;
			}
		}
	}
	x = 13; y = 16;//preenchendo a tabela vazia com x ou -
	posicaoCursor(x, y);
	for (linha = 0; linha < 2; linha++) {
		for (coluna = 0; coluna < 5; coluna++) {
			posicionarTela(x-1, y-1);
			if (agenda[linha][coluna] == TRUE) {
				printf("x");
			}
			else {
				printf("-");
			}
			x += 10;
		}
		x = 13;y += 2;
	}

	x = 9; y = 15;
	while (sair == FALSE) {//navegar entre os horarios de atendimento
		posicaoCursor(x, y);
		printf(">");
		setbuf(stdin, NULL);
		ch = getch();setbuf(stdin, NULL);
		setbuf(stdin, NULL);
		if (ch == 224) {
			switch (getch()) {
			case direita:
				if (x < 40) {
					posicaoCursor(x, y);
					printf(" ");
					posicaoCursor(x += 10, y);
					printf(">");
				} break;

			case esquerda:
				if (x > 9) {
					posicaoCursor(x, y);
					printf(" ");
					posicaoCursor(x -= 10, y);
					printf(">");
				} break;
			case acima:
				if (y < 16) {
					posicaoCursor(x, y);
					printf(" ");
					posicaoCursor(x, y += 2);
					printf(">");
				} break;
			case abaixo:
				if (y > 15) {
					posicaoCursor(x, y);
					printf(" ");
					posicaoCursor(x, y -= 2);
					printf(">");
				}  break;

			}
		}
		else if (ch == enter) {
			printf("  x");
			if (x == 9 && y == 15) {// linha 1 coluna 1
				agenda[0][0] = TRUE;
			}
			else if (x == 19 && y == 15) {//linha 1 coluna 2
				agenda[0][1] = TRUE;
			}
			else if (x == 29 && y == 15) {//linha 1 coluna 3
				agenda[0][2] = TRUE;
			}
			else if (x == 39 && y == 15) {//linha 1 coluna 4
				agenda[0][3] = TRUE;
			}
			else if (x == 49 && y == 15) {//linha 1 coluna 5
				agenda[0][4] = TRUE;
			}
			else if (x == 9 && y == 17) {// linha 2 coluna 1
				agenda[1][0] = TRUE;
			}
			else if (x == 19 && y == 17) {//linha 2 coluna 2
				agenda[1][1] = TRUE;
			}
			else if (x == 29 && y == 17) {//linha 2 coluna 3
				agenda[1][2] = TRUE;
			}
			else if (x == 39 && y == 17) {//linha 2 coluna 4
				agenda[1][3] = TRUE;
			}
			else if (x == 49 && y == 17) {//linha 2 coluna 5
				agenda[1][4] = TRUE;
			}
		}
		else if (ch == voltar2) {
			printf("  -");
			if (x == 9 && y == 15) {// linha 1 coluna 1
				agenda[0][0] = FALSE;
			}
			else if (x == 19 && y == 15) {//linha 1 coluna 2
				agenda[0][1] = FALSE;
			}
			else if (x == 29 && y == 15) {//linha 1 coluna 3
				agenda[0][2] = FALSE;
			}
			else if (x == 39 && y == 15) {//linha 1 coluna 4
				agenda[0][3] = FALSE;
			}
			else if (x == 49 && y == 15) {//linha 1 coluna 5
				agenda[0][4] = FALSE;
			}
			else if (x == 9 && y == 17) {// linha 2 coluna 1
				agenda[1][0] = FALSE;
			}
			else if (x == 19 && y == 17) {//linha 2 coluna 2
				agenda[1][1] = FALSE;
			}
			else if (x == 29 && y == 17) {//linha 2 coluna 3
				agenda[1][2] = FALSE;
			}
			else if (x == 39 && y == 17) {//linha 2 coluna 4
				agenda[1][3] = FALSE;
			}
			else if (x == 49 && y == 17) {//linha 2 coluna 5
				agenda[1][4] = FALSE;
			}
		}
		else if (ch == voltar1) {
			telaAviso(13);
			x = 1, y = 21;;
			while (sair == FALSE) {
			posicaoCursor(x, y);
			printf(">");
			setbuf(stdin, NULL);
			ch = getch();setbuf(stdin, NULL);
			setbuf(stdin, NULL);
			if (ch == 224) {
				switch (getch()) {
				case direita:
					if (x < 18) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x += 18, y);
						printf(">");
					} break;

				case esquerda:
					if (x > 1) {
						posicaoCursor(x, y);
						printf(" ");
						posicaoCursor(x -= 18, y);
						printf(">");
					} break;
				}
				}
			else if (ch == enter) {
				if (x == 1) {
					sair = TRUE;
				}
				else {
					limparTelaDeAviso(1, 20, 4);
					x = 9; y = 15;
					break;
				}
			}
			}
		}
	}
	
//	system("pause");
}

TMedico criarMedico(char crm[]) {
	TMedico m;
	int x, y;

	strcpy(m.crm, crm);
	x = 8; y = 2;
	posicionarTela(x, y);
	gets(m.medico.nome);
	setbuf(stdin, NULL);
	while (validarNome(m.medico.nome) == FALSE) {
		telaAviso(2);
		x = 8; y = 2;
		limparLinha(m.medico.nome, x, y);
		posicionarTela(x, y);
		gets(m.medico.nome);
		setbuf(stdin, NULL);
	}
	limparTelaDeAviso(15, 7, 3);
	strupr(m.medico.nome);
	x = 12; y = 3;
	posicionarTela(x, y);
	gets(m.medico.telefone);
	setbuf(stdin, NULL);
	while (validarTelefone(m.medico.telefone) == FALSE) {
		telaAviso(3);
		x = 12; y = 3;
		limparLinha(m.medico.telefone, x, y);
		posicionarTela(x, y);
		gets(m.medico.telefone);
		setbuf(stdin, NULL);
	}
	limparTelaDeAviso(15, 7, 3);
	x = 10; y = 4;
	posicionarTela(x, y);
	gets(m.medico.email);
	setbuf(stdin, NULL);
	while (validarEmail(m.medico.email) == FALSE) {
		telaAviso(4);
		x = 10; y = 4;
		limparLinha(m.medico.email, x, y);
		posicionarTela(x, y);
		gets(m.medico.email);
		setbuf(stdin, NULL);
	}
	limparTelaDeAviso(15, 7, 3);
	strcpy(m.especialidade, especialidadesMedicas());
	x = 17; y = 5;
	posicionarTela(x, y);
	printf("%s", m.especialidade);
	agendaDeAtendimento(m.tabelaHorario);
	m.medico.status = TRUE;
	return m;
}

void cadastrarMedico(TArvoreBB **raiz, FILE *arqMedico, char crm[]) {
	int teste, x, y, result, pos;
	TMedico medico;

	result = buscaPorCrm(*raiz, crm);
	if (result != -1) {
		x = 5; y = 7;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      *MEDICO JA ESTA CADASTRADO*        ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		x = 5; y = 25;
		posicionarTela(x, y++);
		system("pause");
	}
	else {
		fseek(arqMedico, 0, 2);
		medico = criarMedico(crm);
		teste = fwrite(&medico, sizeof(TMedico), 1, arqMedico);
		if (teste != 1) {
			printf("Erro ao gravar no arquivo\n");
			exit(1);
		}
		else {
			pos = ftell(arqMedico) / sizeof(TMedico) - 1;
			inserirIndice(&(*raiz), medico.crm, pos);
			x = 5; y = 7;
			posicionarTela(x, y++);
			printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
			posicionarTela(x, y++);
			printf("³      *MEDICO CADASTRADO COM SUCESSO*    ³\n");
			posicionarTela(x, y++);
			printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
			x = 5; y = 25;
			posicionarTela(x, y++);
			system("pause");
		}
	}
}

void listarMedico(TArvoreBB *raiz, FILE *arqMedico) {// procedimento provisório
	int teste;
	TMedico m;

	if (raiz != NULL) {
		fseek(arqMedico, raiz->pos * sizeof(TMedico), 0);
		teste = fread(&m, sizeof(TMedico), 1, arqMedico);
		if (teste != 1) {
			if (!feof(arqMedico))
				printf("Erro na leitura\n");
		}
		else {
			printf("\n");
			printf("NOME: %s\n", m.medico.nome);
			printf("CRM: %s\n", m.crm);
			printf("E-MAIL: %s\n", m.medico.email);
			printf("TELEFONE: %s\n", m.medico.telefone);
			printf("ESPECIALIDADE: %s\n", m.especialidade);
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
		}
		listarMedico(raiz->esq, arqMedico);
		listarMedico(raiz->dir, arqMedico);
	}
}

void indexarArqMedico(TArvoreBB **raiz, FILE *arqMedico) {
	int teste, cont = -1;
	TMedico m;

	fseek(arqMedico, 0, 0);
	while (1) {
		teste = fread(&m, sizeof(TMedico), 1, arqMedico);
		if (teste != 1) {
			if (!feof(arqMedico)) {
				printf("Erro na leitura!\n");
			}
			break;
		}
		else if (feof(arqMedico)) {
			break;
		}
		else {
			if (m.medico.status != 0) {
				cont++;
				inserirIndice(&(*raiz), m.crm, cont);
			}
		}
	}
}

void desindexarArqMedico(TArvoreBB **raiz) {

	if (*raiz != NULL) {
		desindexarArqMedico(&((*raiz)->esq));
		desindexarArqMedico(&((*raiz)->dir));
		free(*raiz);
		*raiz = NULL;
	}
}

void buscarMedicoPorNome(FILE * arqMedico, TNomes **nameList, char nome[]) {
	int teste, posArquivo = -1, pos, result = -1;
	int linha, coluna, x = 13, y = 7;
	TMedico m;

	fseek(arqMedico, 0, 0);
	while (1) {
		teste = fread(&m, sizeof(TMedico), 1, arqMedico);
		posArquivo++;
		if (teste != 1) {
			if (!feof(arqMedico))
				printf("Erro na leitura!\n");
			system("pause");
			return;
			break;
		}
		else {
			if (m.medico.status == 1) {
				comparaNome(m.medico.nome, nome, &(*nameList), posArquivo); // compara e exibi os nomes relacionados.
			}
		}
	}
	result = resultadoPesquisa(*nameList);
	limparLista(&(*nameList));
	if (result != -1) {
		fseek(arqMedico, result * sizeof(TMedico), 0);
		teste = fread(&m, sizeof(TMedico), 1, arqMedico);
		if (teste != 1) {
			if (!feof(arqMedico)) {
				printf("Erro na leitura");
			}
		}
		else {
			system("cls");
			printf("\n");
			printf("MEDICO: %s\n", m.medico.nome);
			printf("CRM: %s\n", m.crm);
			telaMedico(16);
			for (linha = 0; linha < 2; linha++) {
				for (coluna = 0; coluna < 5; coluna++) {
					posicionarTela(x-1, y-1);
					if (m.tabelaHorario[linha][coluna] == TRUE) {
						printf("x");
					}
					x += 10;
				}
				x = 13;y += 2;
			}
		}
		posicionarTela(2, 15);
		system("pause");
	}
	//return pos;
}

int buscaPorCrm(TArvoreBB *raiz, char crm[]) {
	int result;

	result = buscar(raiz, crm);
	return result;
}

void alterarCadastroMedico(TArvoreBB *raiz, FILE *arqMedico, char crm[]) {
	TMedico m;
	int result, teste, ch, sair = FALSE, x, y, opc = 0;


	result = buscaPorCrm(raiz, crm);
	if (result == -1) {
		telaAviso(9);
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
			system("cls");
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ALTERAR CADASTRO ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
			printf("  NOME: %s                                            \n", m.medico.nome);
			printf("  TELEFONE: %s                                        \n", m.medico.telefone);
			printf("  E-MAIL: %s                                          \n", m.medico.email);
			printf("  AGENDA                                              \n");
			printf("  ESPECIALIDADE: %s                                   \n", m.especialidade);
			printf("  SALVAR                                              \n");
			printf("  CANCELAR                                            \n");
			printf("                                                      \n");
			printf("                                                      \n");
			printf("                                                      \n");
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
			/*telaAviso(14);
			x = 1, y = 7;
			while (sair == FALSE) {
				posicaoCursor(x, y);
				printf(">");
				setbuf(stdin, NULL);
				ch = getch();setbuf(stdin, NULL);
				setbuf(stdin, NULL);
				if (ch == 224) {
					switch (getch()) {
					case direita:
						if (x < 18) {
							posicaoCursor(x, y);
							printf(" ");
							posicaoCursor(x += 18, y);
							printf(">");
						} break;

					case esquerda:
						if (x > 1) {
							posicaoCursor(x, y);
							printf(" ");
							posicaoCursor(x -= 18, y);
							printf(">");
						} break;
					}
				}
				else if (ch == enter) {
					if (x == 1) {// escolha == sim
						sair = TRUE;//sair do loop
						limparTelaDeAviso(1, 20, 4);
					}
					else {//escolha == não
						return;
					}
				}
			}
			*/
			//limparTelaDeAviso(1, 6, 4);
			x = 0, y = 1;
			while (opc != 7) {
				posicaoCursor(x, y);
				printf(">");
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
					defalte: break;//??
					}  setbuf(stdin, NULL);
				}

				else if (ch == enter) {
					switch (y) {
					case 1: x = 8; y = 1;
						limparLinha(m.medico.nome, x, y);
						posicionarTela(x, y);
						gets(m.medico.nome);
						setbuf(stdin, NULL);
						while (validarNome(m.medico.nome) == FALSE) {
							telaAviso(2);
							limparLinha(m.medico.nome, x, y);
							posicionarTela(x, y);
							gets(m.medico.nome);
							setbuf(stdin, NULL);
						}
						strupr(m.medico.nome);
						limparTelaDeAviso(15, 7, 3);
						break;
					case 2:
						x = 12; y = 2;
						limparLinha(m.medico.telefone, x, y);
						posicionarTela(x, y);
						gets(m.medico.telefone);
						setbuf(stdin, NULL);
						while (validarTelefone(m.medico.telefone) == FALSE) {
							telaAviso(3);
							limparLinha(m.medico.telefone, x, y);
							posicionarTela(x, y);
							gets(m.medico.telefone);
							setbuf(stdin, NULL);
						}
						limparTelaDeAviso(15, 7, 3);
						break;
					case 3:
						x = 10; y = 3;
						limparLinha(m.medico.email, x, y);
						posicionarTela(x, y);
						gets(m.medico.email);
						setbuf(stdin, NULL);
						while (validarEmail(m.medico.email) == FALSE) {
							telaAviso(4);
							limparLinha(m.medico.email, x, y);
							posicionarTela(x, y);
							gets(m.medico.email);
							setbuf(stdin, NULL);
						}
						limparTelaDeAviso(15, 7, 3);
						break;
					case 4:
						agendaDeAtendimento(m.tabelaHorario);
						break;
					case 5:strcpy(m.especialidade, especialidadesMedicas());
						x = 17; y = 5;
						posicionarTela(x, y);
						printf("                             ");
						posicionarTela(x, y);
						printf("%s", m.especialidade);
						break;
					case 6:sair = TRUE;opc = 7;break;
					case 7: opc = 7;break;
					}
					x = 0;
				}
			}
			if (sair == TRUE) {
				fseek(arqMedico, -1 * sizeof(TMedico), 1);
				teste = fwrite(&m, sizeof(TMedico), 1, arqMedico);
				if (teste != 1) {
					printf("Erro na gravacao!\n");
				}
				else {
					telaAviso(15);
				}
			}
		}
	}
}

void removerMedico(TArvoreBB **raiz, FILE *arqMedico, char indice[]) {
	TMedico m;
	int result, teste;

	result = buscaPorCrm(*raiz, indice);
	if (result == -1) {
		mensagemErro(9);
		return;
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
			m.medico.status = 0;
			fseek(arqMedico, -1 * sizeof(TMedico), 1);
			teste = fwrite(&m, sizeof(TMedico), 1, arqMedico);
			if (teste != 1) {
				printf("Erro na gravacao!\n");
			}
			else {
				removerIndice(&(*raiz), indice);
				telaAviso(12);
				posicionarTela(2, 15);
				system("pause");
			}
		}
	}
}

void consultarAgenda(TArvoreBB *raiz, FILE *arqMedico, char crm[]) {
	TMedico m;
	int result, teste;
	int linha, coluna, x, y;


    result = buscaPorCrm(raiz, crm);
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
			system("cls");
			telaMedico(16);
			x = 13; y = 4;
			for (linha = 0; linha < 2; linha++) {
				for (coluna = 0; coluna < 5; coluna++) {
					posicionarTela(x-1, y-1);
					if (m.tabelaHorario[linha][coluna] == TRUE) {
						printf("x");
					}
					x += 10;
				}
				x = 13;y += 2;
			}
			x = 10; y = 20;
			posicionarTela(x, y);
		}
	}
}

void manutencaoArqMedico(FILE * arq) {
	int teste = 0;
	FILE * aux;
	TMedico m;

	aux = fopen("auxiliar.bin", "w+b"); // arquivo auxliar
	if (aux == NULL) {
		printf("Erro ao criar arquivo");
	}
	fseek(arq, 0, 0);
	while (1) {
		teste = fread(&m, sizeof(TMedico), 1, arq);
		if (teste != 1) {
			if (!feof)
				printf("Erro de leitura\n");
			break;
		}
		if (m.medico.status == TRUE) {
			teste = fwrite(&m, sizeof(TMedico), 1, aux);
			if (teste != 1)
				printf("Erro de gravacao\n");
		}
	}
	fclose(aux);//testar
	fclose(arq);//testar
	remove("Medicos.bin");
	rename("auxiliar.bin", "Medicos.bin");

}

void pesquisarPorEspecialidade(FILE *arqMedico, char especialidade[]) {
	int teste, posArquivo = -1, result, flag = 0;
	int linha, coluna, x = 13, y = 7;
	TMedico m;
	
	posicaoCursor(0, 0);
	fseek(arqMedico, 0, 0);
	while (1) {
		teste = fread(&m, sizeof(TMedico), 1, arqMedico);
		if (teste != 1) {
			if (!feof(arqMedico))
				printf("Erro na leitura!\n");
			system("pause");
			return;
			break;
		}
		else {
			if (m.medico.status == 1 && strcmp(m.especialidade, especialidade) == 0) {
				printf("\n");
				printf("MEDICO: %s\n", m.medico.nome);
				printf("CRM: %s\n", m.crm);
				telaMedico(16);
				for (linha = 0; linha < 2; linha++) {
					for (coluna = 0; coluna < 5; coluna++) {
						posicionarTela(x-1, y-1);
						if (m.tabelaHorario[linha][coluna] == TRUE) {
							printf("x");
						}
						x += 10;
					}
					x = 13;y += 2;
				}
				printf("\n\n\n");
				y += 7;//incrementa o y para a proxima tabela
				flag = 1;
			}
		}
	}
    if (flag == 0) {
		telaAviso(19);
		posicionarTela(3, 10);
	}
	system("pause");
}

int verificarHorarioDeAtendimento(FILE *arqMedico, int dia, int turno, int posicao) {
	int teste;
	int linha, coluna;
	TMedico m;

	fseek(arqMedico, posicao * sizeof(TMedico), 0);
	teste = fread(&m, sizeof(TMedico), 1, arqMedico);
	if (teste != 1) {
		if (!feof(arqMedico)) {
			printf("Erro na leitura");
		}
	}
	else {
		for (linha = 0; linha < 2; linha++) {
			for (coluna = 0; coluna < 5; coluna++) {
				if (m.tabelaHorario[linha][coluna] == TRUE && dia == coluna && turno == linha) {
					return TRUE;
				}
			}
		}
		return FALSE;
	}
}

//FIM MEDICO.C