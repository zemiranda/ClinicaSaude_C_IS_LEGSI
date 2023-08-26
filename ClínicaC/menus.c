#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h> 
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<unistd.h>

#include"utentes.h"
#include"medicos.h"
#include"structs.h"
#include"menus.h"
#include"fila.h"

void interface()
{

printf("\n");                                                               
printf("\n ¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦    ¦¦ ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦   ¦¦¦¦¦¦      ¦¦¦¦¦¦  ¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦    ¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦¦ ");
printf("\n¦¦      ¦¦      ¦¦¦¦   ¦¦    ¦¦    ¦¦   ¦¦ ¦¦    ¦¦     ¦¦   ¦¦ ¦¦          ¦¦      ¦¦   ¦¦ ¦¦    ¦¦ ¦¦   ¦¦ ¦¦      ");
printf("\n¦¦      ¦¦¦¦¦   ¦¦ ¦¦  ¦¦    ¦¦    ¦¦¦¦¦¦  ¦¦    ¦¦     ¦¦   ¦¦ ¦¦¦¦¦       ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦    ¦¦ ¦¦   ¦¦ ¦¦¦¦¦   ");
printf("\n¦¦      ¦¦      ¦¦  ¦¦ ¦¦    ¦¦    ¦¦   ¦¦ ¦¦    ¦¦     ¦¦   ¦¦ ¦¦               ¦¦ ¦¦   ¦¦ ¦¦    ¦¦ ¦¦   ¦¦ ¦¦      ");
printf("\n ¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦¦¦    ¦¦    ¦¦   ¦¦  ¦¦¦¦¦¦      ¦¦¦¦¦¦  ¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦ ¦¦   ¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦¦ ");
printf("\n");                                                                                                                      
                                                                   
}
void interfaceUtente()
{
printf("\n"); 
printf("\n¦¦    ¦¦ ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦    ¦¦ ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦"); 
printf("\n¦¦    ¦¦    ¦¦    ¦¦      ¦¦¦¦   ¦¦    ¦¦    ¦¦     ");
printf("\n¦¦    ¦¦    ¦¦    ¦¦¦¦¦   ¦¦ ¦¦  ¦¦    ¦¦    ¦¦¦¦¦  ");
printf("\n¦¦    ¦¦    ¦¦    ¦¦      ¦¦  ¦¦ ¦¦    ¦¦    ¦¦     ");
printf("\n ¦¦¦¦¦¦     ¦¦    ¦¦¦¦¦¦¦ ¦¦   ¦¦¦¦    ¦¦    ¦¦¦¦¦¦¦");
printf("\n");     
printf("\n"); 
printf("\n"); 
printf("\n");                                                 
                                                     
}
void interfaceMedico(){
printf("\n");
printf("\n¦¦¦    ¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦  ");
printf("\n¦¦¦¦  ¦¦¦¦ ¦¦      ¦¦   ¦¦ ¦¦ ¦¦      ¦¦    ¦¦ ");
printf("\n¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦   ¦¦   ¦¦ ¦¦ ¦¦      ¦¦    ¦¦ ");
printf("\n¦¦  ¦¦  ¦¦ ¦¦      ¦¦   ¦¦ ¦¦ ¦¦      ¦¦    ¦¦ ");
printf("\n¦¦      ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦  ");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
}
void interfaceFilaEspera(){
printf("\n");
printf("\n\t¦¦¦¦¦¦¦ ¦¦ ¦¦       ¦¦¦¦¦      ¦¦¦¦¦¦  ¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦¦ ¦¦¦¦¦¦   ¦¦¦¦¦"); 
printf("\n\t¦¦      ¦¦ ¦¦      ¦¦   ¦¦     ¦¦   ¦¦ ¦¦          ¦¦      ¦¦      ¦¦   ¦¦ ¦¦      ¦¦   ¦¦ ¦¦   ¦¦");
printf("\n\t¦¦¦¦¦   ¦¦ ¦¦      ¦¦¦¦¦¦¦     ¦¦   ¦¦ ¦¦¦¦¦       ¦¦¦¦¦   ¦¦¦¦¦¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦¦¦¦¦¦");
printf("\n\t¦¦      ¦¦ ¦¦      ¦¦   ¦¦     ¦¦   ¦¦ ¦¦          ¦¦           ¦¦ ¦¦      ¦¦      ¦¦   ¦¦ ¦¦   ¦¦");
printf("\n\t¦¦      ¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦     ¦¦¦¦¦¦  ¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦      ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦   ¦¦");
printf("\n");
}
int menu(){
	int op;
	printf("\n");
        printf("\t\t\t     Sistema de gestão e atendimento de utentes.\n");
        printf("\t\t\t\t===================================\n");
        printf("\t\t\t\t|\t                          |\n");
        printf("\t\t\t\t|\t 1 - Gerir Lista Espera   |\n");
        printf("\t\t\t\t|\t 2 - Gerir Médicos        |\n");
        printf("\t\t\t\t|\t 3 - Gerir Utentes        |\n");
        printf("\t\t\t\t|\t 4 - Sair                 |\n");
        printf("\t\t\t\t|\t                          |\n");
        printf ("\t\t\t\t===================================\n");
        printf ("\n\n");
        printf("\t\t\t\tPor favor, selecione uma opção: ");
	scanf("%d",&op);
	switch(op){
		case 1:
		case 2:
		case 3:
		case 4:
			return op;
			break;
		default:
			printf("\n Opção inválida\n");
			system("pause");
			system("CLS");
			main();
			break;
	}
}
void criaFiles() {
	FILE* reg = fopen("utentes.txt", "r");
	if (reg == NULL) {
		reg = fopen("utentes.txt", "a");
		fclose(reg);
	}
	fclose(reg);
	FILE* med = fopen("medicos.txt", "r");
	if (med == NULL) {
		med = fopen("medicos.txt", "a");
		fclose(med);
	}
	fclose(med);
}

void sairPrograma(){
    exit(0);
}

void gerirListaEspera() {
    system("CLS"); 
    interfaceFilaEspera();
    Utente utente;
	int pergunta;
	printf("\n");
        printf("\t\t\t\t===========================================\n");
        printf("\t\t\t\t|                                         |\n");
        printf("\t\t\t\t| 1 - Inserir Utente na fila              |\n");
        printf("\t\t\t\t| 2 - Remover o primeiro utente da fila   |\n");
        printf("\t\t\t\t| 3 - Ver lista de espera dos medicos     |\n");
        printf("\t\t\t\t| 4 - Ver Medico com maior lista de espera|\n");
    	printf("\t\t\t\t| 5 - Ver numero de utentes por medico	  |\n");
        printf("\t\t\t\t| 6 - Voltar               		  |\n");
        printf("\t\t\t\t|                      	  		  |\n");
        printf("\t\t\t\t===========================================\n");
        printf("\n\n");

	printf("\t\t\t\tInsira uma opção: ");
	scanf("%d", &pergunta);
	
	if(pergunta == 1)
	{
	int op, cu;
	Utente utente;
	int existe = 0;
	
    FILE* reg;
    reg = fopen("utentes.txt", "r");

	
    if (reg == NULL) {
    	perror("error");
	    	fclose(reg);
	    	exit(0);
	
    }
	printf("Inserir código de utente?\n ");
    printf("1- Inserir  2- Registrar Utente  3- Voltar\n");
    printf("Opção: ");
    scanf("%d", &op);

    if (op == 1) {
  			
	            reg = fopen("utentes.txt", "r");
	            printf("Insira o seu código de utente : ");
	            scanf("%d", &cu);
	            existe = 0; // redefine a variável "existe" para cada vericação
	            while (fscanf(reg, "%d,%[^,],%d", &utente.codigo, utente.nome, &utente.codigoMed) == 3) {
	                fgetc(reg);
	                if (cu == utente.codigo) {
	                 
	                    existe = 1;
	                    break; // sai do loop se encontrar o registro
	                }
	            }
	        if (existe == 0){
	        	printf("Utente inexistente!\n");
	        	system("pause");
	        	gerirListaEspera();
			}
	         
	        fclose(reg); // fecha o arquivo no final do loop
	        Medico medico;
			char nomeMed[100];
	        FILE* med;
    		med = fopen("medicos.txt", "r");
    		
    		if (med == NULL) {
    		perror("error");
	    	fclose(med);
	    	exit(0);
    		}
	        
	         while (fscanf(med, "%d,%[^\n]", &medico.codigo, medico.nome) == 2) {
			 if(utente.codigoMed==medico.codigo){
			 	strcpy(nomeMed,medico.nome);
			 	break;
			 }
			 }
	         
	      
	        Criar_Medico_Apontador(utente.codigoMed, nomeMed);
			Colocar_Utente_Fila_Espera(&utente);
			//listarteste(utente.codigoMed);
			gerirListaEspera();
			
	    }
	    else if (op == 2) {
	        registarUtente();
	    }
	    else if(op == 3)
	    {
	    	main();
		}
	    else {
	        printf("\n Opção invalida\n");
	        system("pause");
	        gerirListaEspera();
	    }
	}
	
    else if(pergunta == 2)
    {
    	Medico medico;
    	int qualmedico=0;
    	FILE*med;
		med=fopen("medicos.txt", "r");
		if(med==NULL)
			{
  				perror("error");
	    		fclose(med);
	    		exit(0);
			}
		int code, i = 1,j = 1;
		char name[100];
		printf("Insira o codigo de Medico que pretende remover o primeiro Utente na fila de espera\n");
		
			while (fscanf(med,"%d,%[^\n]s", &code, name) == 2) {
    			printf("(código,nome) %d,%s\n", code,name);
    			i++;
			}
		fclose(med);
		med=fopen("medicos.txt", "r");
		scanf("%d", &qualmedico);
		
		
		 while (fscanf(med,"%d,%[^\n]s", &medico.codigo, medico.nome) != EOF) {
			 if(medico.codigo == qualmedico){

			 	break;
			 	}
			}
		    fclose(med);
		    
        Remover_Primeiro_Utente_Fila_Espera(medico.codigo);
    	gerirListaEspera();
    	
    
	}else if(pergunta == 3){
		int opcao;
		printf(" 1-Procurar por Codigo de Medico  2-Listar todas as filas de espera\n");
		printf("Opção: ");
		scanf("%d", &opcao);
		
		if(opcao==1){
		
		
		FILE*med;
		med=fopen("medicos.txt", "r");
		if(med==NULL)
			{
  				perror("error");
	    		fclose(med);
	    		exit(0);
			}
		int code, i = 1,j = 1,codigoMedico;
		char name[100];
		printf("Insira o codigo de Medico que pretende ver a fila de espera\n");
		
			while (fscanf(med,"%d,%[^\n]s", &code, name) != EOF) {
    			printf("%d-(código,nome) %d,%s\n", i, code,name);
    			i++;
			}
		fclose(med);
		scanf("%d", &codigoMedico);
		listarIndividual(codigoMedico);
		gerirListaEspera();
		
	}else if(opcao==2){
	
	system("CLS");	
	ListarTodasFilas();
	gerirListaEspera();
		
	}else{
		printf("\nOpcao Invalida\n");
		system("pause");
		gerirListaEspera();
	}
		
	}else if(pergunta == 4){
	
		MedicoComMaisUtentes();
		system("pause");
		gerirListaEspera();
		
	}
	else if(pergunta == 5){
		numeroUtentesporMedico();
		system("pause");
		gerirListaEspera();
		
	}
	else if(pergunta == 6){
		main();
	}else{
		printf("\n Opção invalida\n");
        system("pause");
        gerirListaEspera();
	}
	
	
}
