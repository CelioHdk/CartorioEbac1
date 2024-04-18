#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��o de textos por regi�o
#include <string.h> // biblioteca responsavel por cuidar dos strings


int registro() // fun��o responsavel por cadastrar os usuarios no sistema
{
	// inicio cria��o de vari�veis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/ string	
	
	printf("Digite o CPF a ser cadastrado: " ); //coletando a informa��o do usu�rio
	scanf("%s", cpf); // faz a varredura da informa��o acima digitada, na variavel do tipo string (CPF), salvando na mem�ria
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo	
	file = fopen(arquivo, "w"); // cria o arquivo, e o "w" significa escrever
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
		
	
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, ","); // imprimi na tela a "v�rgula", ap�s o CPF digitado pelo usuario
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: "); //  coletando a informa��o do usuario
	scanf("%s", nome); // faz a varredura na informa��o acima digitada (nome), salvando na mem�ria
		
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, nome); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
		
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, ","); // imprimi na tela a "v�rgula", ap�s o nome digitado pelo usuario
	fclose(file); // fecha o arquivo
	
	
	printf ("Digite o sobrenome a ser cadastrado:  "); // coletando a informa��o do usuario
	scanf("%s", sobrenome); // faz a varredura da informa��o acima digitada (sobrenome), salvando na mem�ria
	
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, sobrenome); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, ","); // imprimi na tela a "v�rgula", ap�s o sobrenome digitado pelo usuario
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o cargo a ser cadastrado:  "); // coletando a informa��o do usu�rio
	scanf("%s", cargo); // faz a varredura da informa��o acima digitada (cargo)
	
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, cargo); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	system("pause"); // comando de pausa
	
}

int consulta()	// fun��o respons�vel por consultar a vari�vel digitada, e avaliar a sua validade
{
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	// in�cio das vari�veis string
	char cpf[40];
	char conteudo[200];
	// fim das vari�veis string
	
	printf("Digite o CPF a ser consultado: "); // coletando a informa��o do usu�rio
	scanf("%s", cpf); // faz a varredura da informa��o acima digitada (cpf)
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e realiza a leitura do cpf digitado
	
	if (file == NULL) // la�o condicional, "Se o arquivo for igual a NULO"
	{
		// in�cio da condi��o do la�o "if"
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); // imprime na tela a informa��o
	   // fim do la�o "if"
	}
	
	while(fgets(conteudo, 200, file) != NULL) // la�o "while", "enquanto" variavel "conteudo" contiver ate 200 caracteres, o arquivo ser� diferente de NULO 
	{
		// in�cio das condi��es do la�o "while"
		printf("Essas s�o as informa��es do usu�rio:  "); // imprime na tela a informa��o
		printf("%s", conteudo); // imprime as informa��es de conteudo
		printf("\n\n"); // pula duas linhas
		// fim do la�o "while"
	}
	
	system("pause"); // comando de pausa
	  
	
}


int deletar() // fun��o responsavel por deletar o conte�do das vari�veis
{
	// in�cio da vari�vel string
	char cpf[40];
	printf ("Digite o CPF do usu�rio a ser deletado:  "); // coletando a informa��o do usu�rio
	scanf("%s", cpf); // faz a varredura da informa��o acima digitada, CPF a ser deletado
	remove(cpf); // remove o cpf
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // abre o arquivo e realiza a leitura do cpf digitado
	
	if (file == NULL) // la�o "if", "se" o arquivo for igual a NULO
	{
		printf ("O usu�rio n�o se encontra no sistema! \n"); // imprime a informa��o e pula uma linha
		
		system("pause"); // comando de pausa
	}
}


int main() // in�cio da fun��o principal

{
	
	int opcao=0; // definindo vari�veis
	int laco=1; // definindo vari�vel para contagem de looping
	
	for(laco=1;laco=1;) // la�o "for", la�o de repeti��o
	{
		system ("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	
		printf(" ###Cart�rio da EBAC ### \n\n"); // in�cio do menu 
		printf("Escolha a op��o desejada do menu: \n\n"); // imprime informa��o, pula 2 linhas
		printf("\t1 - Registrar Nomes\n"); // imprime informa��o, pula 1 linha
		printf("\t2 - Consultar Nomes\n"); // imprime informa��o, pula 1 linha
		printf("\t3 - Deletar Nomes\n\n"); // imprime informa��o, pula 2 linhas
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op�ao:  "); //fim do menu
	
		scanf("%xd" , &opcao);  //armazenamento a escolha do usuario 
	
		system ("cls"); // limpa  a tela
		
		switch(opcao) // chamada da vari�vel "opcao"
		{
			case 1: // caso o usu�rio digite "1"
				registro(); // executa a fun��o "registro"
				system("pause"); // pausa
				break; // interrompe o comando de repeti��o
				
			case 2: // caso o usu�rio digite "2"
				consulta(); // executa a fun��o "consulta"
				system("pause"); // pausa
				break; // interrompe o comando de repeti��o
				
			case 3:	// caso o usu�rio digite "3"
				deletar(); // executa a fun��o "deletar"
				system("pause"); // pausa
				break; // interrompe o comando de repeti��o
				
			case 4:
			printf("Obrigado por utilizar o sistema!!!\n");
			return 0;
			break;
				
			default: // se os valores digitados por diferentes, dos definidos em "case".
				printf("Essa op��o n�o est� dispon�vel!\n"); // imprime a informa��o, pula uma linha
				system("pause"); // pausa
				break; // interrompe o comando de repeti��o
		} // fim da sele��o
	
		
		
	} // fim do la�o for
	
} // fim da fun��o principal
