#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de textos por região
#include <string.h> // biblioteca responsavel por cuidar dos strings


int registro() // função responsavel por cadastrar os usuarios no sistema
{
	// inicio criação de variáveis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/ string	
	
	printf("Digite o CPF a ser cadastrado: " ); //coletando a informação do usuário
	scanf("%s", cpf); // faz a varredura da informação acima digitada, na variavel do tipo string (CPF), salvando na memória
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo	
	file = fopen(arquivo, "w"); // cria o arquivo, e o "w" significa escrever
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
		
	
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, ","); // imprimi na tela a "vírgula", após o CPF digitado pelo usuario
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: "); //  coletando a informação do usuario
	scanf("%s", nome); // faz a varredura na informação acima digitada (nome), salvando na memória
		
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, nome); // salva o valor da variável
	fclose(file); // fecha o arquivo
		
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, ","); // imprimi na tela a "vírgula", após o nome digitado pelo usuario
	fclose(file); // fecha o arquivo
	
	
	printf ("Digite o sobrenome a ser cadastrado:  "); // coletando a informação do usuario
	scanf("%s", sobrenome); // faz a varredura da informação acima digitada (sobrenome), salvando na memória
	
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, sobrenome); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, ","); // imprimi na tela a "vírgula", após o sobrenome digitado pelo usuario
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o cargo a ser cadastrado:  "); // coletando a informação do usuário
	scanf("%s", cargo); // faz a varredura da informação acima digitada (cargo)
	
	file = fopen(arquivo,"a"); // abre o arquivo e o atualiza
	fprintf(file, cargo); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	system("pause"); // comando de pausa
	
}

int consulta()	// função responsável por consultar a variável digitada, e avaliar a sua validade
{
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	// início das variáveis string
	char cpf[40];
	char conteudo[200];
	// fim das variáveis string
	
	printf("Digite o CPF a ser consultado: "); // coletando a informação do usuário
	scanf("%s", cpf); // faz a varredura da informação acima digitada (cpf)
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e realiza a leitura do cpf digitado
	
	if (file == NULL) // laço condicional, "Se o arquivo for igual a NULO"
	{
		// início da condição do laço "if"
		printf("Não foi possível abrir o arquivo, não localizado!\n"); // imprime na tela a informação
	   // fim do laço "if"
	}
	
	while(fgets(conteudo, 200, file) != NULL) // laço "while", "enquanto" variavel "conteudo" contiver ate 200 caracteres, o arquivo será diferente de NULO 
	{
		// início das condições do laço "while"
		printf("Essas são as informações do usuário:  "); // imprime na tela a informação
		printf("%s", conteudo); // imprime as informações de conteudo
		printf("\n\n"); // pula duas linhas
		// fim do laço "while"
	}
	
	system("pause"); // comando de pausa
	  
	
}


int deletar() // função responsavel por deletar o conteúdo das variáveis
{
	// início da variável string
	char cpf[40];
	printf ("Digite o CPF do usuário a ser deletado:  "); // coletando a informação do usuário
	scanf("%s", cpf); // faz a varredura da informação acima digitada, CPF a ser deletado
	remove(cpf); // remove o cpf
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // abre o arquivo e realiza a leitura do cpf digitado
	
	if (file == NULL) // laço "if", "se" o arquivo for igual a NULO
	{
		printf ("O usuário não se encontra no sistema! \n"); // imprime a informação e pula uma linha
		
		system("pause"); // comando de pausa
	}
}


int main() // início da função principal

{
	
	int opcao=0; // definindo variáveis
	int laco=1; // definindo variável para contagem de looping
	
	for(laco=1;laco=1;) // laço "for", laço de repetição
	{
		system ("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	
		printf(" ###Cartório da EBAC ### \n\n"); // início do menu 
		printf("Escolha a opção desejada do menu: \n\n"); // imprime informação, pula 2 linhas
		printf("\t1 - Registrar Nomes\n"); // imprime informação, pula 1 linha
		printf("\t2 - Consultar Nomes\n"); // imprime informação, pula 1 linha
		printf("\t3 - Deletar Nomes\n\n"); // imprime informação, pula 2 linhas
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opçao:  "); //fim do menu
	
		scanf("%xd" , &opcao);  //armazenamento a escolha do usuario 
	
		system ("cls"); // limpa  a tela
		
		switch(opcao) // chamada da variável "opcao"
		{
			case 1: // caso o usuário digite "1"
				registro(); // executa a função "registro"
				system("pause"); // pausa
				break; // interrompe o comando de repetição
				
			case 2: // caso o usuário digite "2"
				consulta(); // executa a função "consulta"
				system("pause"); // pausa
				break; // interrompe o comando de repetição
				
			case 3:	// caso o usuário digite "3"
				deletar(); // executa a função "deletar"
				system("pause"); // pausa
				break; // interrompe o comando de repetição
				
			case 4:
			printf("Obrigado por utilizar o sistema!!!\n");
			return 0;
			break;
				
			default: // se os valores digitados por diferentes, dos definidos em "case".
				printf("Essa opção não está disponível!\n"); // imprime a informação, pula uma linha
				system("pause"); // pausa
				break; // interrompe o comando de repetição
		} // fim da seleção
	
		
		
	} // fim do laço for
	
} // fim da função principal
