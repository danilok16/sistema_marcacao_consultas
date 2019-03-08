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
	case 0:printf("�����������MENU DE CONSULTAS��������Ŀ\n");
		printf("�  MARCAR CONSULTA                   �\n");
		printf("�  CONSULTAR PACIENTES DE UM MEDICO  �\n");
		printf("�  CONSULTAR CONSULTAS DE UM PACIENTE�\n");
		printf("�  DESMARCAR CONSULTA                �\n");
		printf("�  CONSULTAR FILA DE ESPERA          �\n");
		printf("�  VOLTAR                            �\n");
		printf("��������������������������������������");
		break;
	case 1:printf("����������������� MARCAR CONSULTA ����������������������Ŀ\n");
		printf("� CPF:                                                    �\n");
		printf("� CRM:                                                    �\n");
		printf("� DATA:                                                   �\n");
		printf("� TURNO:                                                  �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("����������������������������������������������������������");
		break;
	case 2:printf("������������ CONSULTAR PACIENTES DE UM MEDICO ������������Ŀ\n");
		printf("� CRM:                                                    �\n");
		printf("� DATA:                                                   �\n");
		printf("� TURNO:                                                  �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("����������������������������������������������������������");
		break;
	case 3:printf("���������� CONSULTAR CONSULTAS DE UM PACIENTE �����������Ŀ\n");
		printf("� CPF:                                                    �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�����������������������������������������������������������");
		break;
	case 4:printf("���������������� DESMARCAR CONSULTA �������������������Ŀ\n");
		printf("� CPF:                                                    �\n");
		printf("� CRM:                                                    �\n");
		printf("� DATA:                                                   �\n");
		printf("� TURNO:                                                  �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�����������������������������������������������������������");
		break;
	case 5:printf("��������������� CONSULTAR FILA DE ESPERA ��������������Ŀ\n");
		printf("� CRM:                                                    �\n");
		printf("� DATA:                                                   �\n");
		printf("� TURNO:                                                  �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("�                                                         �\n");
		printf("����������������������������������������������������������");
		break;
	}

}

void telaCliente(int opc) {
	int x, y;
	switch (opc) {
	case 1:system("cls");
		printf("�����������MENU DE CLIENTES���������Ŀ\n");
		printf("�  CADASTRAR CLIENTE                 �\n");
		printf("�  LISTAR TODOS CLIENTES             �\n");
		printf("�  ALTERAR CADASTRO DE UM CLIENTE    �\n");
		printf("�  EXIBIR DADOS DE UM CLIENTE        �\n");
		//printf("5 - CONSULTAR P/CPF OU P/NOME\n"); Sub-menu
		printf("�  REMOVER CADASTRO DE UM CLIENTE    �\n");
		printf("�  PESQUISAR CLIENTE POR NOME        �\n");
		printf("�  VOLTAR                            �\n");
		printf("��������������������������������������");
		break;
	case 2:system("cls");
		printf("��������������� CADASTRAR CLIENTE ����������������Ŀ\n");
		printf("� CPF:                                             �\n");
		printf("� NOME:                                            �\n");
		printf("� TELEFONE:                                        �\n");
		printf("� E-MAIL:                                          �\n");
		printf("�                                                  �\n");
		printf("�                                                  �\n");
		printf("�                                                  �\n");
		printf("�                                                  �\n");
		printf("����������������������������������������������������");
		break;
	case 3:system("cls");
		printf("��������� ALTERAR CADASTRO ����������������Ŀ\n");
		printf("� INFORME O CPF DO CLIENTE:                 �\n");
		printf("���������������������������������������������");
		break;
	case 4:system("cls");
		printf("����������� DADOS DO CLIENTE ��������������Ŀ\n");
		printf("� INFORME O CPF DO CLIENTE:                 �\n");
		printf("���������������������������������������������");
		break;
	case 5:system("cls");
		printf("�������EXCLUIR CADASTRO DE UM CLIENTE������Ŀ\n");
		printf("� INFORME O CPF DO CLIENTE:                 �\n");
		printf("���������������������������������������������");
		break;
	case 6:system("cls");
		printf("�������������������PESQUISAR POR NOME��������������������������Ŀ\n");
		printf("� DIGITE O NOME DO CLIENTE:                                     �\n");
		printf("�����������������������������������������������������������������");
		break;
	}
}

void telaMedico(int opc) {
	int x , y ;
	switch (opc) {

	case 1:
		printf("����������� MENU MEDICOS �����������Ŀ\n");
		printf("�  CADASTRAR MEDICO                  �\n");
		printf("�  EXIBIR TODOS OS MEDICOS           �\n");
		printf("�  ALTERAR CADASTRO DE UM MEDICO     �\n");
		printf("�  BUSCAR MEDICO POR NOME            �\n");
		printf("�  EXCLUIR CADASTRO DE UM MEDICO     �\n");
		printf("�  PROCURAR MEDICO POR ESPECIALIDADE �\n");
		printf("�  CONSULTAR HORARIOS DE ATENDIMENTO �\n");
		printf("�  VOLTAR                            �\n");
		printf("��������������������������������������");
		break;
	case 2:
		printf("���������������� CADASTRAR MEDICO ����������������Ŀ\n");
		printf("� CRM:                                             �\n");
		printf("� NOME:                                            �\n");
		printf("� TELEFONE:                                        �\n");
		printf("� E-MAIL:                                          �\n");
		printf("� ESPECIALIDADE:                                   �\n");
		printf("�                                                  �\n");
		printf("�                                                  �\n");
		printf("�                                                  �\n");
		printf("�                                                  �\n");
		printf("����������������������������������������������������");
		break;
	case 3:
		system("cls");
		printf("��������� ALTERAR CADASTRO ����������������Ŀ\n");
		printf("� INFORME O CRM DO MEDICO:                  �\n");
		printf("���������������������������������������������");
		break;
	case 4:
		system("cls");
		printf("�������������������CONSULTAR POR NOME��������������������������Ŀ\n");
		printf("� DIGITE O NOME DO MEDICO:                                      �\n");
		printf("�����������������������������������������������������������������");
		break;
	case 5:
		system("cls");
		printf("����������� EXCLUIR CADASTRO ��������������Ŀ\n");
		printf("� INFORME O CRM DO MEDICO:                  �\n");
		printf("���������������������������������������������");
		break;
	case 6:
		system("cls");
		printf("�������������� PESQUISAR POR ESPECIALIDADE ����������������\n");
		break;
	case 15://criar medico
		x = 0, y = 12;
		posicionarTela(x, y);
		printf("���������������� HORARIOS DE ATENDIMENTO ����������������Ŀ\n");
		printf("�       � SEGUNDA �  TERCA  � QUARTA  � QUINTA  �  SEXTA  �\n");
		printf("���������������������������������������������������������ĳ\n");
		printf("�MANHA  �   -     �   -     �   -     �   -     �   -     �\n");
		printf("���������������������������������������������������������ĳ\n");
		printf("�TARDE  �   -     �   -     �   -     �   -     �   -     �\n");
		printf("�����������������������������������������������������������\n");
		break;
	case 16://consultar medico
		printf("���������������� HORARIOS DE ATENDIMENTO ����������������Ŀ\n");
		printf("�       � SEGUNDA �  TERCA  � QUARTA  � QUINTA  �  SEXTA  �\n");
		printf("���������������������������������������������������������ĳ\n");
		printf("�MANHA  �   -     �   -     �   -     �   -     �   -     �\n");
		printf("���������������������������������������������������������ĳ\n");
		printf("�TARDE  �   -     �   -     �   -     �   -     �   -     �\n");
		printf("�����������������������������������������������������������\n");
		break;
	}

}

void telaAviso(int opc) {
	int x = 15, y = 7;

	switch (opc) {
	case 1:
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�      CPF INVALIDO!      �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 2:
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�      NOME INVALIDO!     �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 3:
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�    TELEFONE INVALIDO    �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 4:
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�     E-MAIL INVALIDO!    �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 7:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�      CPF INVALIDO!      �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 8:
		x = 6; y = 4;
		posicionarTela(x, y++);
		printf("�����������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("� CLIENTE NAO ESTA CADASTRADO!�\n");
		posicionarTela(x, y++);
		printf("�������������������������������\n\n");
		break;
	case 9:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("�����������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("� MEDICO NAO ESTA CADASTRADO! �\n");
		posicionarTela(x, y++);
		printf("�������������������������������\n\n");
		break;
	case 10:
		x = 6; y = 7;
		posicionarTela(x, y++);
		printf("�����������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�*PRESSIONE ESC PARA CANCELAR*�\n");
		posicionarTela(x, y++);
		printf("�������������������������������");
		break;
	case 12:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�  REMOVIDO COM SUCESSO   �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 13:
		x = 0, y = 19;
		posicionarTela(x, y);
		printf("�������������������������Ŀ\n");
		printf("�         FINALIZAR?      �\n");
		printf("�  SIM               NAO  �\n");
		printf("���������������������������");
		break;
	case 14://talvez n�o precise
		x = 0, y = 5;
		posicionarTela(x, y);
		printf("�������������������������Ŀ\n");
		printf("�    ALTERAR CADASTRO?    �\n");
		printf("�  SIM               NAO  �\n");
		printf("���������������������������");
		break;
	case 15:
		//x = 8; y = 4;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�  ALTERARDO COM SUCESSO! �\n");
		posicionarTela(x, y++);
		printf("���������������������������\n\n");
		break;
	case 19:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�     NENHUM RESULTADO    �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 20:
		x = 10; y = 5;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�      CRM INVALIDO!      �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 21:
		x = 10; y = 5;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�      DATA INVALIDA      �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
		case 22:
		x = 3; y = 25;
		posicionarTela(x, y++);
		printf("���������������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�   PRESSIONE ESC PARA FINALIZAR  �\n");
		posicionarTela(x, y++);
		printf("�����������������������������������");
		break;
	}
	
}

void mensagemErro(int opc) {
	int x = 15, y = 7;

	switch (opc) {
	case 1:
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�      CPF INVALIDO!      �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 2:
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�      NOME INVALIDO!     �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 3:
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�    TELEFONE INVALIDO    �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 4:
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�     E-MAIL INVALIDO!    �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 7:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�      CPF INVALIDO!      �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 8:
		x = 6; y = 4;
		posicionarTela(x, y++);
		printf("�����������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("� CLIENTE NAO ESTA CADASTRADO!�\n");
		posicionarTela(x, y++);
		printf("�������������������������������\n\n");
		break;
	case 9:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("�����������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("� MEDICO NAO ESTA CADASTRADO! �\n");
		posicionarTela(x, y++);
		printf("�������������������������������\n\n");
		break;
	case 10:
		x = 6; y = 7;
		posicionarTela(x, y++);
		printf("�����������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�*PRESSIONE ESC PARA CANCELAR*�\n");
		posicionarTela(x, y++);
		printf("�������������������������������");
		break;
	case 12:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�  REMOVIDO COM SUCESSO   �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 13:
		x = 1, y = 20;
		posicionarTela(x, y);
		printf("�������������������������Ŀ\n");
		printf("�   FINALIZAR CADASTRO?   �\n");
		printf("�  SIM               NAO  �\n");
		printf("���������������������������");
		break;
	case 14://talvez n�o precise
		x = 1, y = 6;
		posicionarTela(x, y);
		printf("�������������������������Ŀ\n");
		printf("�    ALTERAR CADASTRO?    �\n");
		printf("�  SIM               NAO  �\n");
		printf("���������������������������");
		break;
	case 15:
		x = 8; y = 4;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�  ALTERARDO COM SUCESSO! �\n");
		posicionarTela(x, y++);
		printf("���������������������������\n\n");
	}
}

void telaAvisoConsulta(int opc) {
	int x, y;

	switch (opc) {
	case 1:
		x = 15, y = 5;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�      CPF INVALIDO!      �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 2:
		x = 15, y = 5;
		posicionarTela(x, y++);
		printf("�������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�     CRM INVALIDO!       �\n");
		posicionarTela(x, y++);
		printf("���������������������������");
		break;
	case 4:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("������������������������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�CLIENTE JA TEM CONSULTA PARA ESSE HORARIO �\n");
		posicionarTela(x, y++);
		printf("��������������������������������������������");
		break;
	case 5:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("������������������������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�     O MEDICO NAO ATENDE NESSO HORARIO    �\n");
		posicionarTela(x, y++);
		printf("��������������������������������������������");
		break;
	case 6:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("���������������������������������������������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�SEM VAGAS PARA ESSA DATA, DESEJA ENTRAR NA FILA DE ESPETA?     �\n");
		posicionarTela(x, y++);
		printf("������������������������������������������������������������������");
		break;
	case 7:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("������������������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�            CONSULTA MARCADA        �\n");
		posicionarTela(x, y++);
		printf("���������������������������������������");
		break;
	case 8:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("������������������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�            FILA DE ESPERA          �\n");
		posicionarTela(x, y++);
		printf("���������������������������������������");
		break;
	case 9:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("������������������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�         CONSULTA DESMARCADA        �\n");
		posicionarTela(x, y++);
		printf("���������������������������������������");
		break;
	case 10:
		x = 6, y = 5;
		posicionarTela(x, y++);
		printf("������������������������������������Ŀ\n");
		posicionarTela(x, y++);
		printf("�        SEM CONSULTAS MARCADAS      �\n");
		posicionarTela(x, y++);
		printf("���������������������������������������");
		break;
	}
}

//FIM VIEW.C