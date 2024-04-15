#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
    //in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
    scanf("%s",cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar o valor das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo valor da variavel
    fclose(file); //fechar o arquivo
    
    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite um nome para ser cadastrado: "); //coletando informa��es do usu�rio
    scanf("%s",nome);//%s refere-se a string
 
    file=fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��es do usu�rio
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
  	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");//op��o caso o arquivo n�o seja encontrado
  }
  
  while(fgets(conteudo, 200, file) != NULL)
  {
  	printf("Essas s�o as informa��es do usu�rio: "); //mostra as informa��es do usu�rio desejado.
  	printf("%s", conteudo); //mostra o conte�do
  	printf("\n\n");//espa�amento
  }
  
  system("pause");
   
}
int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��es do usu�rio
    scanf("%s",cpf); //%s refere-se a string
    
    remove(cpf); //responsavel por remover o usu�rio pelo CPF
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL);
    {
    	printf("Esse usu�rio n�o se encontra no sistema!. \n");
    	system("pause"); //pausa a tela
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	   system("cls");
	   
	   setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
   
       printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
       printf("Escolha a op��o desejada do menu:\n\n");
       printf("\t1 - Registrar nomes\n");
       printf("\t2 - Consultar nomes\n");
       printf("\t3 - Deletar nomes\n");
       printf("\t4 - Sair do Sistema\n");
       printf("Op��o: "); //fim do menu
   
       scanf("%d", &opcao); //armazenando a escolha do usu�rio
   
       system("cls"); //responsavel por limpar a tela
        
        switch(opcao) //in�cio da sele��o
        {
        	case 1:
        	registro(); //chamada de fun��es
   	        break;
   	        
   	        case 2:
   	        consulta(); //consulta de fun��es
   	        break;
   	        
   	        case 3:
   	        deletar(); //deletar fun��es
   	        break;
   	        
   	        case 4:
   	        printf("Obrigado por utilizar o sistema");
   	        return 0;
   	        break;
   	        
   	        default:
   	        printf("Essa op��o n�o est� dispon�vel!\n");
   	        system("pause");
   	        break;
   	   	} //Fim da sele��o    
}
}
