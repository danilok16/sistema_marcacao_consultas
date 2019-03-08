//CLIENTE.C
#include"types.h"
#include"metodos_especiais.h"
#include"tree.h"
#include <conio.h>
#include"validações.h"

int buscaPorCpf(TArvoreBB *raiz, char cpf[]) {
	int result;

	result = buscar(raiz, cpf);
	return result;
}


int buscarClientePorNome(FILE * arqCliente,TNomes **nameList, char nome[]) {
	int teste, posArquivo = -1, pos, result = 0;
	TCliente c;

	fseek(arqCliente, 0, 0);
	while (1) {
		teste = fread(&c, sizeof(TCliente), 1, arqCliente);
		posArquivo++;
		if (teste != 1) {
			if (!feof(arqCliente))
				return -1;
			break;
		}
		else {
			if (c.cliente.status == 1) {
				comparaNome(c.cliente.nome, nome, &(*nameList), posArquivo); // compara os nomes relacionados.
			}
		}
	}
	result = resultadoPesquisa(*nameList);// exibi uma lista alocado dinamicamente
	limparLista(&(*nameList));//desalocar a lista criada anteriormente
	//result = pos;
	return result;// retorna a posição do nome procurado
}

TCliente criarCliente(char cpf[]) {
	TCliente c;
	int x, y;

	
	strcpy(c.cpf, cpf);
	x = 8; y = 2;
	posicionarTela(x, y);
	gets(c.cliente.nome);
	setbuf(stdin, NULL);
	while (validarNome(c.cliente.nome) == FALSE) {
		mensagemErro(2);
		x = 8; y = 2;
		limparLinha(c.cliente.nome, x, y);
		posicionarTela(x, y);
		gets(c.cliente.nome);
		setbuf(stdin, NULL);
	}
	strupr(c.cliente.nome);
	x = 12; y = 3;
	posicionarTela(x, y);
	gets(c.cliente.telefone);
	setbuf(stdin, NULL);
	while (validarTelefone(c.cliente.telefone) == FALSE) {
		mensagemErro(3);
		x = 12; y = 3;
		limparLinha(c.cliente.telefone, x, y);
		posicionarTela(x, y);
		gets(c.cliente.telefone);
		setbuf(stdin, NULL);
	}
	x = 10; y = 4;
	posicionarTela(x, y);
	gets(c.cliente.email);
	setbuf(stdin, NULL);
	while (validarEmail(c.cliente.email) == FALSE) {
		mensagemErro(4);
		x = 10; y = 4;
		limparLinha(c.cliente.email, x, y);
		posicionarTela(x, y);
		gets(c.cliente.email);
		setbuf(stdin, NULL);
	}
	c.cliente.status = TRUE;
	return c;
}

void cadastrarCliente(TArvoreBB **arvore_cliente, FILE *arqCliente, char cpf[]) {
	int teste, x, y, result, posicaoCliente;
	TCliente cliente;

	result = buscaPorCpf(*arvore_cliente, cpf);
	if (result != -1) {
		x = 4; y = 6;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³     *CLIENTE JA ESTA CADASTRADO*        ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		x = 4; y = 24;
		posicionarTela(x, y++);
		system("pause");
	}
	else{
		fseek(arqCliente, 0, 2);
		cliente = criarCliente(cpf);
		teste = fwrite(&cliente, sizeof(TCliente), 1, arqCliente);
		if (teste != 1) {
			printf("Erro ao gravar no arquivo\n");
			exit(1);
		}
		else {
			posicaoCliente = ftell(arqCliente) / sizeof(TCliente) - 1;
			inserirIndice(&(*arvore_cliente),cliente.cpf, posicaoCliente);
			x = 4; y = 6;
			posicionarTela(x, y++);
			printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
			posicionarTela(x, y++);
			printf("³     *CLIENTE CADASTRADO COM SUCESSO*    ³\n");
			posicionarTela(x, y++);
			printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
			x = 4; y = 24;
			posicionarTela(x, y++);
			system("pause");
		}
	}
	
}

void alterarCadastroCliente(TArvoreBB *raiz, FILE *arqCliente, char cpf[]) {
	TCliente c;
	int result, teste, x, y, resp, sair = FALSE, ch, opc = 0;
	//char linha[50] = "                                    ";//apagar o campo para fazer a alteração do cadastro

	
	result = buscaPorCpf(raiz, cpf);
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
			system("cls");
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ALTERAR CADASTRO ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
			printf("  NOME: %s                                         \n", c.cliente.nome);
			printf("  TELEFONE: %s                                     \n", c.cliente.telefone);
			printf("  E-MAIL: %s                                       \n",c.cliente.email);
			printf("                                                   \n");
			printf("  SALVAR                                           \n");
			printf("  CANCELAR                                         \n");
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
			x = 0, y = 1;
			while (opc != 6) {
				posicaoCursor(x, y);
				printf(">");
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
					defalte: break;//??
					}  setbuf(stdin, NULL);
				}

				else if (ch == enter && y != 4) {
					switch (y) {
					case 1: x = 8; y = 1;
						limparLinha(c.cliente.nome, x, y);
						posicionarTela(x, y);
						gets(c.cliente.nome);
						setbuf(stdin, NULL);
						while (validarNome(c.cliente.nome) == FALSE) {
							mensagemErro(2);
							limparLinha(c.cliente.nome, x, y);
							posicionarTela(x, y);
							gets(c.cliente.nome);
							setbuf(stdin, NULL);
						}
						strupr(c.cliente.nome);
						break;
					case 2:x = 12; y = 2;
						limparLinha(c.cliente.telefone, x, y);
						posicionarTela(x, y);
						gets(c.cliente.telefone);
						setbuf(stdin, NULL);
						while (validarTelefone(c.cliente.telefone) == FALSE) {
							mensagemErro(3);
							limparLinha(c.cliente.telefone, x, y);
							posicionarTela(x, y);
							gets(c.cliente.telefone);
							setbuf(stdin, NULL);
						}
						break;
					case 3:x = 10; y = 3;
						limparLinha(c.cliente.email, x, y);
						posicionarTela(x, y);
						gets(c.cliente.email);
						setbuf(stdin, NULL);
						while (validarEmail(c.cliente.email) == FALSE) {
							mensagemErro(4);
							limparLinha(c.cliente.email, x, y);
							posicionarTela(x, y);
							gets(c.cliente.email);
							setbuf(stdin, NULL);
						}
						break;
					case 5:sair = TRUE;opc = 6;break;
					case 6: opc = 6;break;
					}
					x = 0;
				}
			}
			if (sair == TRUE) {
				fseek(arqCliente, -1 * sizeof(TCliente), 1);
				teste = fwrite(&c, sizeof(TCliente), 1, arqCliente);
				if (teste != 1) {
					printf("Erro na gravacao!\n");
				}
				else {
					mensagemErro(15);
				}
			}
		}
	}
}

void exibirCliente(TArvoreBB *raiz, FILE *arqCliente, char cpf[]) {
	TCliente c;
	int result, teste;


	result = buscaPorCpf(raiz, cpf);
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
			system("cls");
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄ DADOS DO CLIENTE ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
			printf(" NOME: %s                                         \n", c.cliente.nome);
			printf(" CPF : %s                                         \n", c.cpf);
			printf(" TELEFONE: %s                                     \n", c.cliente.telefone);
			printf(" E-MAIL: %s                                       \n", c.cliente.email);
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
		}
	}
}

void removerCliente(TArvoreBB **raiz, FILE *arqCliente, char indice[]) {
	TCliente c;
	int result, teste;

	result = buscaPorCpf(*raiz, indice);
	if (result == -1) {
		mensagemErro(8);
		return;
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
			c.cliente.status = 0;
			fseek(arqCliente, -1 * sizeof(TCliente), 1);
			teste = fwrite(&c, sizeof(TCliente), 1, arqCliente);
			if (teste != 1) {
				printf("Erro na gravacao!\n");
			}
			else {
				removerIndice(&(*raiz), indice);
				mensagemErro(12);
				Sleep(1100);
			}
		}
	}
}

void indexarArqCliente(TArvoreBB **raiz, FILE *arqCliente) {
	int teste, pos;
	TCliente c;

	fseek(arqCliente, 0, 0);
	while (1) {
		teste = fread(&c, sizeof(TCliente), 1, arqCliente);
		if (teste != 1) {
			if (!feof(arqCliente)) {
				printf("Erro na leitura!\n");
			}
			break;
		}
		else if (feof(arqCliente)) {
			break;
		}
		else {
			if (c.cliente.status != 0) {
				pos = ftell(arqCliente) / sizeof(TCliente) - 1;
				inserirIndice(&(*raiz), c.cpf, pos);
			}
		}
	}
}

void desindexarArqCliente(TArvoreBB **raiz) {

	if (*raiz != NULL) {
		desindexarArqCliente(&((*raiz)->esq));
		desindexarArqCliente(&((*raiz)->dir));
		free(*raiz);
		*raiz = NULL;
	}
}

void listarCliente(TArvoreBB *raiz, FILE *arqCliente) {// procedimento provisório
	int teste;
	TCliente c;
	
	if (raiz != NULL) {
		fseek(arqCliente, raiz->pos * sizeof(TCliente), 0);
		teste = fread(&c, sizeof(TCliente), 1, arqCliente);
		if (teste != 1) {
			if (!feof(arqCliente))
				printf("Erro na leitura\n");
		}
		else if(c.cliente.status != 0){
		    printf("\n");
			printf("nome: %s\n", c.cliente.nome);
			printf("cpf: %s\n", c.cpf);
			printf("email: %s\n", c.cliente.email);
			printf("telefone: %s\n", c.cliente.telefone);
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
		}
		listarCliente(raiz->esq, arqCliente);
		listarCliente(raiz->dir, arqCliente);
	}
}

void manutencaoArqCliente(FILE * arq) {
	int teste = 0;
	FILE * aux;
	TCliente c;

	aux = fopen("auxiliar.bin", "w+b"); // arquivo auxliar
	if (aux == NULL) {
		printf("Erro ao criar arquivo");
	}
	fseek(arq, 0, 0);
	while (1) {
		teste = fread(&c, sizeof(TCliente), 1, arq);
		if (teste != 1) {
			if (!feof)
				printf("Erro de leitura\n");
			break;
		}
		if (c.cliente.status == TRUE) { 
			teste = fwrite(&c, sizeof(TCliente), 1, aux);
			if (teste != 1)
				printf("Erro de gravacao\n");
		}
	}
	fclose(aux);//testar
	fclose(arq);//testar
	remove("Clientes.bin");              
	rename("auxiliar.bin", "Clientes.bin");
									
}
//FIM CLIENTE.C