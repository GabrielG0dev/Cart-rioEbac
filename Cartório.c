#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
    //início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
    scanf("%s",cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar o valor das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo valor da variavel
    fclose(file); //fechar o arquivo
    
    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite um nome para ser cadastrado: "); //coletando informações do usuário
    scanf("%s",nome);//%s refere-se a string
 
    file=fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");//coletando informações do usuário
    scanf("%s",sobrenome);//%s refere-se a string
    
    file=fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);//%s refere-se a string
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause"); //pausa a tela
}
int consulta()
{
  setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
  
  char cpf[40];
  char conteudo[200];
  
  printf("Digite o cpf a ser consultado: "); //digitar o cpf em consulta.
  scanf("%s",cpf);
  
  FILE *file;
  file =fopen(cpf, "r");//busca o cpf e o "r" significa ler.
  
  if(file == NULL)
  {
  	printf("Não foi possível abrir o arquivo, não localizado!.\n");//opção caso o arquivo não seja encontrado
  }
  
  while(fgets(conteudo, 200, file) != NULL)
  {
  	printf("Essas são as informações do usuário: "); //mostra as informações do usuário desejado.
  	printf("%s", conteudo); //mostra o conteúdo
  	printf("\n\n");//espaçamento
  }
  
  system("pause");
   
}
int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: "); //coletando informações do usuário
    scanf("%s",cpf); //%s refere-se a string
    
    remove(cpf); //responsavel por remover o usuário pelo CPF
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL);
    {
    	printf("Esse usuário não se encontra no sistema!. \n");
    	system("pause"); //pausa a tela
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	   system("cls");
	   
	   setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
   
       printf("### Cartório da EBAC ###\n\n"); //início do menu
       printf("Escolha a opção desejada do menu:\n\n");
       printf("\t1 - Registrar nomes\n");
       printf("\t2 - Consultar nomes\n");
       printf("\t3 - Deletar nomes\n");
       printf("\t4 - Sair do Sistema\n");
       printf("Opção: "); //fim do menu
   
       scanf("%d", &opcao); //armazenando a escolha do usuário
   
       system("cls"); //responsavel por limpar a tela
        
        switch(opcao) //início da seleção
        {
        	case 1:
        	registro(); //chamada de funções
   	        break;
   	        
   	        case 2:
   	        consulta(); //consulta de funções
   	        break;
   	        
   	        case 3:
   	        deletar(); //deletar funções
   	        break;
   	        
   	        case 4:
   	        printf("Obrigado por utilizar o sistema");
   	        return 0;
   	        break;
   	        
   	        default:
   	        printf("Essa opção não está disponível!\n");
   	        system("pause");
   	        break;
   	   	} //Fim da seleção    
}
}
