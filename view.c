//VIEW.C
#include <stdio.h>
#include <windows.h>

void posicaoCursor(int x, int y){
HANDLE hOut;
int i;
COORD Position;

hOut = GetStdHandle(STD_OUTPUT_HANDLE);

Position.X = x;
Position.Y = y;
SetConsoleCursorPosition(hOut, Position);
}

void posicionarTela(int x, int y) {
	HANDLE hOut;
int i;
COORD Position;

hOut = GetStdHandle(STD_OUTPUT_HANDLE);

Position.X = x;
Position.Y = y;
SetConsoleCursorPosition(hOut, Position);
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { x , y });
}

void limparLinha(char str[], int x, int y) {
	int i, cont = 0;

	/*for (i = 0; i < strlen(str); i++) {
	cont++;
	}*/
	for (i = 0; i < strlen(str); i++) {
		posicionarTela(x++, y);
		printf(" ");
	}

}

void limparTelaDeAviso(int x, int y, int qtdLinhas) {
	int cont=0;
	while (cont < qtdLinhas) {
		posicionarTela(x, y);
		printf("                           ");
		y++;cont++;
	}
}

void telaConsulta(int opc) {
	int x, y;
	system("cls");
	switch (opc) {
	case 0:printf("ÚÄÄÄÄÄÄÄÄÄÄMENU DE CONSULTASÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³  MARCAR CONSULTA                   ³\n");
		printf("³  CONSULTAR PACIENTES DE UM MEDICO  ³\n");
		printf("³  CONSULTAR CONSULTAS DE UM PACIENTE³\n");
		printf("³  DESMARCAR CONSULTA                ³\n");
		printf("³  CONSULTAR FILA DE ESPERA          ³\n");
		printf("³  VOLTAR                            ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 1:printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ MARCAR CONSULTA ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ CPF:                                                    ³\n");
		printf("³ CRM:                                                    ³\n");
		printf("³ DATA:                                                   ³\n");
		printf("³ TURNO:                                                  ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 2:printf("ÚÄÄÄÄÄÄÄÄÄÄÄ CONSULTAR PACIENTES DE UM MEDICO ÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ CRM:                                                    ³\n");
		printf("³ DATA:                                                   ³\n");
		printf("³ TURNO:                                                  ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 3:printf("ÚÄÄÄÄÄÄÄÄÄ CONSULTAR CONSULTAS DE UM PACIENTE ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ CPF:                                                    ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 4:printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ DESMARCAR CONSULTA ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ CPF:                                                    ³\n");
		printf("³ CRM:                                                    ³\n");
		printf("³ DATA:                                                   ³\n");
		printf("³ TURNO:                                                  ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 5:printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ CONSULTAR FILA DE ESPERA ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ CRM:                                                    ³\n");
		printf("³ DATA:                                                   ³\n");
		printf("³ TURNO:                                                  ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("³                                                         ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	}

}

void telaCliente(int opc) {
	int x, y;
	switch (opc) {
	case 1:system("cls");
		printf("ÚÄÄÄÄÄÄÄÄÄÄMENU DE CLIENTESÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³  CADASTRAR CLIENTE                 ³\n");
		printf("³  LISTAR TODOS CLIENTES             ³\n");
		printf("³  ALTERAR CADASTRO DE UM CLIENTE    ³\n");
		printf("³  EXIBIR DADOS DE UM CLIENTE        ³\n");
		//printf("5 - CONSULTAR P/CPF OU P/NOME\n"); Sub-menu
		printf("³  REMOVER CADASTRO DE UM CLIENTE    ³\n");
		printf("³  PESQUISAR CLIENTE POR NOME        ³\n");
		printf("³  VOLTAR                            ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 2:system("cls");
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ CADASTRAR CLIENTE ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ CPF:                                             ³\n");
		printf("³ NOME:                                            ³\n");
		printf("³ TELEFONE:                                        ³\n");
		printf("³ E-MAIL:                                          ³\n");
		printf("³                                                  ³\n");
		printf("³                                                  ³\n");
		printf("³                                                  ³\n");
		printf("³                                                  ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 3:system("cls");
		printf("ÚÄÄÄÄÄÄÄÄ ALTERAR CADASTRO ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ INFORME O CPF DO CLIENTE:                 ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 4:system("cls");
		printf("ÚÄÄÄÄÄÄÄÄÄÄ DADOS DO CLIENTE ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ INFORME O CPF DO CLIENTE:                 ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 5:system("cls");
		printf("ÚÄÄÄÄÄÄEXCLUIR CADASTRO DE UM CLIENTEÄÄÄÄÄÄÄ¿\n");
		printf("³ INFORME O CPF DO CLIENTE:                 ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 6:system("cls");
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄPESQUISAR POR NOMEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ DIGITE O NOME DO CLIENTE:                                     ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	}
}

void telaMedico(int opc) {
	int x , y ;
	switch (opc) {

	case 1:
		printf("ÚÄÄÄÄÄÄÄÄÄÄ MENU MEDICOS ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³  CADASTRAR MEDICO                  ³\n");
		printf("³  EXIBIR TODOS OS MEDICOS           ³\n");
		printf("³  ALTERAR CADASTRO DE UM MEDICO     ³\n");
		printf("³  BUSCAR MEDICO POR NOME            ³\n");
		printf("³  EXCLUIR CADASTRO DE UM MEDICO     ³\n");
		printf("³  PROCURAR MEDICO POR ESPECIALIDADE ³\n");
		printf("³  CONSULTAR HORARIOS DE ATENDIMENTO ³\n");
		printf("³  VOLTAR                            ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 2:
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ CADASTRAR MEDICO ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ CRM:                                             ³\n");
		printf("³ NOME:                                            ³\n");
		printf("³ TELEFONE:                                        ³\n");
		printf("³ E-MAIL:                                          ³\n");
		printf("³ ESPECIALIDADE:                                   ³\n");
		printf("³                                                  ³\n");
		printf("³                                                  ³\n");
		printf("³                                                  ³\n");
		printf("³                                                  ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 3:
		system("cls");
		printf("ÚÄÄÄÄÄÄÄÄ ALTERAR CADASTRO ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ INFORME O CRM DO MEDICO:                  ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 4:
		system("cls");
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄCONSULTAR POR NOMEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ DIGITE O NOME DO MEDICO:                                      ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 5:
		system("cls");
		printf("ÚÄÄÄÄÄÄÄÄÄÄ EXCLUIR CADASTRO ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³ INFORME O CRM DO MEDICO:                  ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 6:
		system("cls");
		printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄ PESQUISAR POR ESPECIALIDADE ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
		break;
	case 15://criar medico
		x = 0, y = 12;
		posicionarTela(x, y);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ HORARIOS DE ATENDIMENTO ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³       ³ SEGUNDA ³  TERCA  ³ QUARTA  ³ QUINTA  ³  SEXTA  ³\n");
		printf("³ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ³\n");
		printf("³MANHA  ³   -     ³   -     ³   -     ³   -     ³   -     ³\n");
		printf("³ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ³\n");
		printf("³TARDE  ³   -     ³   -     ³   -     ³   -     ³   -     ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
		break;
	case 16://consultar medico
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ HORARIOS DE ATENDIMENTO ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³       ³ SEGUNDA ³  TERCA  ³ QUARTA  ³ QUINTA  ³  SEXTA  ³\n");
		printf("³ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ³\n");
		printf("³MANHA  ³   -     ³   -     ³   -     ³   -     ³   -     ³\n");
		printf("³ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ³\n");
		printf("³TARDE  ³   -     ³   -     ³   -     ³   -     ³   -     ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
		break;
	}

}

void telaAviso(int opc) {
	int x = 15, y = 7;

	switch (opc) {
	case 1:
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      CPF INVALIDO!      ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 2:
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      NOME INVALIDO!     ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 3:
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³    TELEFONE INVALIDO    ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 4:
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³     E-MAIL INVALIDO!    ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 7:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      CPF INVALIDO!      ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 8:
		x = 6; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³ CLIENTE NAO ESTA CADASTRADO!³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
		break;
	case 9:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³ MEDICO NAO ESTA CADASTRADO! ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
		break;
	case 10:
		x = 6; y = 7;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³*PRESSIONE ESC PARA CANCELAR*³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 12:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³  REMOVIDO COM SUCESSO   ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 13:
		x = 0, y = 19;
		posicionarTela(x, y);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³         FINALIZAR?      ³\n");
		printf("³  SIM               NAO  ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 14://talvez não precise
		x = 0, y = 5;
		posicionarTela(x, y);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³    ALTERAR CADASTRO?    ³\n");
		printf("³  SIM               NAO  ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 15:
		//x = 8; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³  ALTERARDO COM SUCESSO! ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
		break;
	case 19:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³     NENHUM RESULTADO    ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 20:
		x = 10; y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      CRM INVALIDO!      ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 21:
		x = 10; y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      DATA INVALIDA      ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
		case 22:
		x = 3; y = 25;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³   PRESSIONE ESC PARA FINALIZAR  ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	}
	
}

void mensagemErro(int opc) {
	int x = 15, y = 7;

	switch (opc) {
	case 1:
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      CPF INVALIDO!      ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 2:
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      NOME INVALIDO!     ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 3:
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³    TELEFONE INVALIDO    ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 4:
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³     E-MAIL INVALIDO!    ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 7:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      CPF INVALIDO!      ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 8:
		x = 6; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³ CLIENTE NAO ESTA CADASTRADO!³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
		break;
	case 9:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³ MEDICO NAO ESTA CADASTRADO! ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
		break;
	case 10:
		x = 6; y = 7;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³*PRESSIONE ESC PARA CANCELAR*³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 12:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³  REMOVIDO COM SUCESSO   ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 13:
		x = 1, y = 20;
		posicionarTela(x, y);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³   FINALIZAR CADASTRO?   ³\n");
		printf("³  SIM               NAO  ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 14://talvez não precise
		x = 1, y = 6;
		posicionarTela(x, y);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("³    ALTERAR CADASTRO?    ³\n");
		printf("³  SIM               NAO  ³\n");
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 15:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³  ALTERARDO COM SUCESSO! ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
	}
}

void telaAvisoConsulta(int opc) {
	int x, y;

	switch (opc) {
	case 1:
		x = 15, y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³      CPF INVALIDO!      ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 2:
		x = 15, y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³     CRM INVALIDO!       ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 4:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³CLIENTE JA TEM CONSULTA PARA ESSE HORARIO ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 5:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³     O MEDICO NAO ATENDE NESSO HORARIO    ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 6:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³SEM VAGAS PARA ESSA DATA, DESEJA ENTRAR NA FILA DE ESPETA?     ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 7:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³            CONSULTA MARCADA        ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 8:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³            FILA DE ESPERA          ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 9:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³         CONSULTA DESMARCADA        ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	case 10:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		posicionarTela(x, y++);
		printf("³        SEM CONSULTAS MARCADAS      ³\n");
		posicionarTela(x, y++);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		break;
	}
}

//FIM VIEW.C