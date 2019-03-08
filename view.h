#include <stdio.h>
#include <windows.h>


#define acima 80
#define abaixo 72
#define enter 13
#define voltar1 27 //esc
#define voltar2 8 //Backspace
#define esquerda 75
#define direita 77


void posicaoCursor(int x, int y);
void posicionarTela(int x, int y);
void limparLinha(char str[], int x, int y);
void telaAviso(int opc);
void telaAvisoConsulta(int opc);
void telaConsulta(int opc);
void telaCliente(int opc);
void telaMedico(int opc);
void mensagemErro(int opc);
void limparTelaDeAviso(int x, int y, int qtdLinhas);
//13 enter
