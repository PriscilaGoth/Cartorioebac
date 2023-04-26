#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdio.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salva o valor da vari�vel no arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // abre o arquivo
    fprintf(file,","); // adciona uma virgula ao arquivo ","
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); // coletando informa��o do usu�rio
    scanf("%s",nome); // %s refere-se a string  
    
    file = fopen(arquivo, "a"); // "a" vamos atualizar uma informa��o no arquivo
    fprintf(file,nome); // salva o nome no arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" atualiza o arquiva
    fprintf(file,","); //adciona uma virgula ","
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
    scanf("%s",sobrenome); // %s refere-se a string onde vai ser armazenado
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,sobrenome); //adciona o sobrenome no arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualiza o arquivo "a"
    fprintf(file,","); // adciona a virgula
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rio
    scanf("%s",cargo); // refere-se a string cargo 
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,cargo); //adciona o cargo no arquivo
    fclose(file); //fecha o aqrquivo
    
    system("pause");
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coleta de informa��s com o usu�rio
	scanf("%s",cpf); // refere-se a string cpf
	
	FILE *file; //acessa e consulta o arquivo
	file = fopen(cpf,"r"); //abre e faz a leitura do arquivo "r" cpf
	
	if(file == NULL) //comparando se o arquivo � nulo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); //mensagem de retorno para o usu�rio se o arquivo for nulo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //la�o de repeti��o enquanto for diferente de nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //refere-se a string conteudo
		printf("\n\n"); //pula linhas
	}
	
	system("pause");
		
		
}

int deletar()
{
	char cpf[40]; //inicio da cria��o de vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coleta de informa��es a serem deletadas com o usu�rio
	scanf("%s",cpf); //refere-se a string cpf e local a ser salvo
	
	remove(cpf); //remove o cpf 
	
	FILE *file;
	file = fopen(cpf,"r"); //faz a leitura do arquivo
	
	if(file == NULL) //compara se o arquivo � nulo
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //resposta ao usu�rio
		system("pause");
	}
	
}

int main ()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	 printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	 printf("Escolha a op��o desejada no menu: \n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("Op��o: "); //Fim do menu
	
	 scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	 system("cls"); //respons�vel por limpar a tela
	 
	 
	
	 switch(opcao) //inicio da sele��o do menu
	   {
	 	 case 1:
	 	 registro(); //chamada de fun��es
		 break;
		 
		 case 2:
		 consulta();
		 break;
		 
		 case 3:
		 deletar();
	 	 break;
	 	 
	 	 default:
		 printf("Essa op��o n�o est� dispon�vel!\n");
		 system("pause");
		 break;
	    } //fim da sele��o
	 
	 

   }
}


