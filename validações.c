//VALIDAÇÕES.C
#include"types.h"

int validarCpf(char cpf[]) {
	int i, j, digito1 = 0, digito2 = 0;
	if (strlen(cpf) != 11){
		return 0;
	}
	else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) ||
		(strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
		(strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) ||
		(strcmp(cpf, "99999999999") == 0)){
		return 0; ///se o CPF tiver todos os números iguais ele é inválido.
	}
	else	{
		///digito 1---------------------------------------------------
		for (i = 0, j = 10; i < strlen(cpf) - 2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
			digito1 += (cpf[i] - 48) * j;
		digito1 %= 11;
		if (digito1 < 2)
			digito1 = 0;
		else
			digito1 = 11 - digito1;
		if ((cpf[9] - 48) != digito1){
			return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
		}
		else{
			for (i = 0, j = 11; i < strlen(cpf) - 1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
				digito2 += (cpf[i] - 48) * j;
			digito2 %= 11;
			if (digito2 < 2)
				digito2 = 0;
			else
				digito2 = 11 - digito2;
			if ((cpf[10] - 48) != digito2){
				return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
		}
	}
	return 1;
	}
}

int validarNome(char nome[]) {
	int i, j = 1;

	if (strlen(nome) < 3) {
		return 0;
	}
	for (i = 1; nome[i]; i++) { //remove espaços em excesso
		if (nome[i] != ' ' || (nome[i - 1] != ' ')) {
			nome[j] = nome[i];
			j++;
		}
	}
	nome[j] = '\0';
	for (i = 0; i != strlen(nome); i = i + 1) {
		if (!isalpha(nome[i]) && !isspace(nome[i])) {
			return 0;
		}
	}
	return 1;
}

int validarTelefone(char telefone[]) {
	int i, cont = 0;

	if (strlen(telefone) < 7) {
		return 0;
	}
	for (i = 0; i != strlen(telefone); i++) {
		cont++;//??
		if (telefone[i] != '0' && telefone[i] != '1' && telefone[i] != '2' && telefone[i] != '3' && telefone[i] != '4' && telefone[i] != '5' && telefone[i] != '6' && telefone[i] != '7' && telefone[i] != '8' && telefone[i] != '9')
			return 0;
	}

	if (strlen(telefone) > 14)
		return 0;
	else
		return 1;
}

int validarEmail(char email[]) {
	int qtdArroba = 0, i;

	for (i = 0; i < strlen(email); i++) {
		if (email[i] == '@') {
			qtdArroba++;
		}
		if (qtdArroba > 1) {
			return 0;
		}
	}
	if (qtdArroba == 0) {
		return 0;
	}
	else
		return 1;
}

char *lerCpf(int X, int Y) {
	int  x = X, y = Y, cont = 0, ch, sair = FALSE;
	int i = 0, flag;
	char cpf[12];

	while (i < 11) {
		setbuf(stdin, NULL);
		cpf[i] = getche(); setbuf(stdin, NULL);
		if (cpf[i] == 13) {//caso o usario pressione enter
			break;	   //break;
		}
		else if (cpf[i] == 27) {//caso o usario pressione esc para cancelar a operação
		    strcpy(cpf, "cancelar\0");
			return;
		}
		if (cpf[i] == 8 && i > 0) {//caso o usario apague alguma letra;
			i = i - 1;
			if (x > X) {
				x = x - 1;
			}
			printf(" ");
			posicaoCursor(x, y);
		}
		else {
			x = x + 1;
			i = i + 1;
		}
	}
	cpf[11] = '\0';
	return cpf;
}

char *lerCrm(int X, int Y) {
	int  x = X, y = Y, cont = 0, ch, sair = FALSE;
	int i = 0, flag;
	char crm[11];

	while (i < 8) {
		setbuf(stdin, NULL);
		crm[i] = getche(); setbuf(stdin, NULL);
		if (crm[i] == 13) {//caso o usario pressione enter
			break;	   //break;
		}
		else if (crm[i] == 27) {//caso o usario pressione esc para cancelar a operação
			strcpy(crm, "cancelar\0");
			return;
		}
		if (crm[i] == 8 && i > 0) {//caso o usario apague alguma letra;
			i = i - 1;
			if (x > X) {
				x = x - 1;
			}
			printf(" ");
			posicaoCursor(x, y);
		}
		else {
			x = x + 1;
			i = i + 1;
		}
	}
	crm[i] = '\0';
	strupr(crm);
	return crm;
}


int validarCrm(char crm[]) {
	int tamanho = strlen(crm), i;
	char estado[3];
	strupr(crm);
	estado[0] = crm[0];
	estado[1] = crm[1];
	estado[2] = '\0';

	if (tamanho<3 || tamanho>8) {
		return 0;
	}
	for (i = 2; i<tamanho; i++) {
		if (isdigit(crm[i]) == 0) {
			return 0;
		}

	}
	if (strcmp(estado, "AC") != 0 && strcmp(estado, "AL") != 0 && strcmp(estado, "AP") != 0 && strcmp(estado, "AM") != 0 &&
		strcmp(estado, "BA") != 0 && strcmp(estado, "GO") != 0 && strcmp(estado, "MG") != 0 && strcmp(estado, "PE") != 0 &&
		strcmp(estado, "CE") != 0 && strcmp(estado, "MA") != 0 && strcmp(estado, "PA") != 0 && strcmp(estado, "PI") != 0 &&
		strcmp(estado, "DF") != 0 && strcmp(estado, "MI") != 0 && strcmp(estado, "PB") != 0 && strcmp(estado, "RN") != 0 &&
		strcmp(estado, "ES") != 0 && strcmp(estado, "MS") != 0 && strcmp(estado, "PR") != 0 && strcmp(estado, "RS") != 0 &&
		strcmp(estado, "RJ") != 0 && strcmp(estado, "RO") != 0 && strcmp(estado, "RR") != 0 && strcmp(estado, "SC") != 0 &&
		strcmp(estado, "SP") != 0 && strcmp(estado, "SE") != 0 && strcmp(estado, "TO")) {

		return 0;
	}
	return 1;

}

char *lerData(int X, int Y) {

	int x = 8, y = Y, cont = 0, ch, sair = FALSE;
	int i = 0, flag;
	char data[11];
	//char data[] = "01.01.2016";
	data[2] = '.';
	data[5] = '.';
	posicaoCursor(x, y);
	while (i < 10) {
		if (i == 2 || i == 5) {
			i++;
		}
		setbuf(stdin, NULL);
		data[i] = getche(); setbuf(stdin, NULL);
		
		if ((data[i] == 8 || data[i] == 13 ) && i > 0) {//caso o usario apague alguma letra;
			i = i - 1;
			if (x > 8) {
				x = x - 1;
			}
			printf(" ");
			posicaoCursor(x, y);
		}
		else {
			x = x + 1;
			i = i + 1;
		}
		if (i == 2 || i == 5) {
			x = x + 1;
			printf("/");
			
		}
		
	}
	//sscanf(data, "%d.%d.%d", &date.dia, &date.mes, &date.ano);
	//printf("\%d", date.ano);
	data[10] = '\0';
	return data;
}

TData dataDoSistema() {
	TData data;
	time_t tempo = time(NULL);
	struct tm *temp = localtime(&tempo);

	data.dia = temp->tm_mday;
	data.mes = temp->tm_mon + 1;
	data.ano = temp->tm_year + 1900;
	return data;
}

int bissexto(int ano) {
	if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) {
		return TRUE;
	}

	return FALSE;
}

int validarData(char dataStr[]) {
	TData dataSistema = dataDoSistema();
	int i, dia, mes, ano;
	//printf("%s", data);

	/*printf("%s", dataStr);
	printf("Data: %d/%d/%d", dataSistema.dia, dataSistema.mes, dataSistema.ano);*/

	//printf("\n%d / %d / %d", dia, mes, ano);
	//system("pause");
	for (i = 0; i != strlen(dataStr); i++) {
		if (dataStr[i] != '0' && dataStr[i] != '1' && dataStr[i] != '2' && dataStr[i] != '3' &&
			dataStr[i] != '4' && dataStr[i] != '5' && dataStr[i] != '6' && dataStr[i] != '7' && dataStr[i] != '8' && dataStr[i] != '9' && dataStr[i] != '.') {
			return 0;
		}
	}
	sscanf(dataStr, "%d.%d.%d", &dia, &mes, &ano);
	if (dia < 1 || dia > 31) { //validar dia
		return 0;
	}
	if (mes == 2 && bissexto(ano)==FALSE && dia > 28) {//validar se o ano é bissexto
		return 0;
	}
	if (mes == 2 && bissexto(ano) == TRUE && dia > 29) {//validar se o ano é bissexto
		return 0;
	}
	if (mes < 1 || mes > 12) {//validar mes
		return 0;
	}
	if (ano < 1900 || ano > 2100) {// validar ano
		return 0;
	}
	if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {//validar dias nos meses 4,6,9,11
		return 0;
	}
	if (dia < dataSistema.dia && mes < dataSistema.mes && ano < dataSistema.ano) {
		return 0;
	}
	if (mes == dataSistema.mes && dia < dataSistema.dia && ano == dataSistema.ano) {
		return 0;
	}
	if (ano < dataSistema.ano) {
		return 0;
	}
	return 1;
}

//FIM VALIDAÇÕES.C