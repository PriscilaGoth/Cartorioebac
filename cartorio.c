#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdio.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salva o valor da variável no arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // abre o arquivo
    fprintf(file,","); // adciona uma virgula ao arquivo ","
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); // coletando informação do usuário
    scanf("%s",nome); // %s refere-se a string  
    
    file = fopen(arquivo, "a"); // "a" vamos atualizar uma informação no arquivo
    fprintf(file,nome); // salva o nome no arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" atualiza o arquiva
    fprintf(file,","); //adciona uma virgula ","
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
    scanf("%s",sobrenome); // %s refere-se a string onde vai ser armazenado
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,sobrenome); //adciona o sobrenome no arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualiza o arquivo "a"
    fprintf(file,","); // adciona a virgula
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário
    scanf("%s",cargo); // refere-se a string cargo 
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,cargo); //adciona o cargo no arquivo
    fclose(file); //fecha o aqrquivo
    
    system("pause");
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //coleta de informaçõs com o usuário
	scanf("%s",cpf); // refere-se a string cpf
	
	FILE *file; //acessa e consulta o arquivo
	file = fopen(cpf,"r"); //abre e faz a leitura do arquivo "r" cpf
	
	if(file == NULL) //comparando se o arquivo é nulo
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); //mensagem de retorno para o usuário se o arquivo for nulo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //laço de repetição enquanto for diferente de nulo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //refere-se a string conteudo
		printf("\n\n"); //pula linhas
	}
	
	system("pause");
		
		
}

int deletar()
{
	char cpf[40]; //inicio da criação de variáveis
	
	printf("Digite o CPF do usuário a ser deletado: "); //coleta de informações a serem deletadas com o usuário
	scanf("%s",cpf); //refere-se a string cpf e local a ser salvo
	
	remove(cpf); //remove o cpf 
	
	FILE *file;
	file = fopen(cpf,"r"); //faz a leitura do arquivo
	
	if(file == NULL) //compara se o arquivo é nulo
	{
		printf("O usuário não se encontra no sistema!.\n"); //resposta ao usuário
		system("pause");
	}
	
}

int main ()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	 printf("### Cartório da EBAC ###\n\n"); //Início do menu
	 printf("Escolha a opção desejada no menu: \n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("Opção: "); //Fim do menu
	
	 scanf("%d", &opcao); //armazenando a escolha do usuário
	
	 system("cls"); //responsável por limpar a tela
	 
	 
	
	 switch(opcao) //inicio da seleção do menu
	   {
	 	 case 1:
	 	 registro(); //chamada de funções
		 break;
		 
		 case 2:
		 consulta();
		 break;
		 
		 case 3:
		 deletar();
	 	 break;
	 	 
	 	 default:
		 printf("Essa opção não está disponível!\n");
		 system("pause");
		 break;
	    } //fim da seleção
	 
	 

   }
}


