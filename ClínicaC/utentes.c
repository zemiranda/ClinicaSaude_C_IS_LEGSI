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


void registarUtente(){
	system("CLS");
	interfaceUtente();
	Utente utente;
	char nomeAux[100];
	int codigos, k;
	FILE*reg; 
	printf("Insira o nome do utente a registar(não é permitido inserir números): ");
	fflush(stdin);
	gets(nomeAux); 	
	//verificar se o nome inserido pelo utilizador tem numeros
	for(k=0;k<(strlen(nomeAux));k++){
		
		if(isdigit(nomeAux[k]))
		{
			printf("O nome não pode ter números!\n");
			system("pause");
			registarUtente();
		}
		
	}
	strcpy(utente.nome,nomeAux);
	srand(time(NULL));
    // Gera um número aleatório entre 0 e 998 e adiciona 1 para obter um número entre 1 e 999
    utente.codigo = (rand() % 999) + 1;
	
	reg=fopen("utentes.txt", "r");
	if(reg==NULL)
		{
		perror("error");
	    	fclose(reg);
	    	exit(0);
		}
	while (fscanf(reg, "%d", &codigos) != EOF) {
        fgetc(reg);
        if(codigos == utente.codigo)
        {
        while(codigos == utente.codigo)
        {
        	utente.codigo = rand();
		}
		}

	}
	
	fclose(reg);
	
	Medico medico; int code, i = 1;
	char name[100];
	FILE*med;
	med=fopen("medicos.txt", "r");
	fseek(med, 0, SEEK_END);	
	long size = ftell(med);
    if (size== 0) {
    printf("Ainda não existem médicos registados na clínica.\n");
    system("pause");
    main();
  	fclose(med);
    }else
    {
    
	fseek(med, 0, SEEK_SET);
	printf("Escolha um dos seguintes médicos a atribuir ao utente %s:\n", utente.nome);
	if(med==NULL)
		{
	    	perror("error");
	    	fclose(med);
	    	exit(0);
		}

		while (fscanf(med,"%d,%[^\n]s", &code, name) != EOF) {
    printf("(código,nome) %d,%s\n", code,name);
}
	fclose(med);
	med=fopen("medicos.txt", "r");
	if(med==NULL)
		{
  	perror("error");
	    	fclose(med);
	    	exit(0);
		}
	int qualmedico, existe = 0;
	char name1[50];
	
	printf("Insira o código do médico a atribuir: ");
	scanf("%d", &qualmedico);
	while (fscanf(med,"%d,%[^\n]", &medico.codigo, medico.nome) != EOF) {  
	
    if (medico.codigo == qualmedico) {
    	existe = 1;
    
        break;
    }
    
}
	if (existe == 0) {
    printf("Médico não encontrado!\n");
    system("pause");
    registarUtente();
	}
    

	fclose(med);
	fopen("utentes.txt", "a");
	fprintf(reg, "%d,%s,%d\n", utente.codigo, utente.nome, medico.codigo);
	fclose(reg);
	utente.codigoMed = medico.codigo;
	Criar_Medico_Apontador(medico.codigo, medico.nome);
	Colocar_Utente_Fila_Espera(&utente);
	gerirUtente();
	}
	
}

void gerirUtente(){
	
	int op;
	system("CLS");
	interfaceUtente();
	printf("1- Criar Utente  2- Editar Utente  3- Consultar Utente  4- Remover Utente  5- Listar Utentes  6- Voltar ");
	printf("\n Opção: ");
	scanf("%d", &op);
	if(op == 1)
	{
		registarUtente();
	}
	else if(op == 2)
	{
		editarUtente();
	}
	else if(op == 3)
	{
		consultarUtente();
	}
	else if(op == 4)
	{
		eliminarUtente();
	}
	else if(op == 5)
	{
		listarUtente();
	}
	else if(op == 6)
	{
		main();
	}
	else{
	
	printf("\n Opção invalida");
	printf("\n Press any key to continue......");
	getch();
	gerirUtente();
	}
	
	
}
void editarUtente(){
	
	Utente utente;
	interfaceUtente();
	int existe = 0, codg, code, codeMed;
	char name[100];
	system("CLS");
	interfaceUtente();
	FILE *reg;
	reg = fopen("utentes.txt","r");
	    if(reg == NULL){
	    	perror("error");
	    	fclose(reg);
	    	exit(0);
		}
		FILE *auxreg;
		auxreg = fopen("auxfile.txt","w");
		printf("Insira o código do utente que deseja editar:\n");
		while (fscanf(reg,"%d,%[^,],%d", &code, name,&codeMed) != EOF) {
    	printf("(código,nome,código médico) %d,%s,%d\n", code,name,codeMed);
		}
		printf("Código: ");
		scanf("%d", &codg);

		verificarUtente(codg);
	
    	int naonome = 0;
    			rewind(reg);

   		while (fscanf(reg, "%d,%[^,],%d", &utente.codigo, utente.nome, &utente.codigoMed) == 3) {

        
        if(codg == utente.codigo){
        		int novomedicocodigo;char novomediconome[100];

        		existe = 1;
				int op;
				char name[100];
				printf("\n Quer editar o nome [%s]? (1- Sim  2- Não)",utente.nome);
				printf("\n Opção: ");
				scanf("%d",&op);
				if(op == 1)
				{
			
				printf("\n Insira o novo nome do utente com o codigo %d: ", utente.codigo);
				fflush(stdin);
				gets(name);
				naonome = 1;
				}
				else if(op == 2)
				{
				naonome = 1;
				}
				else{
					printf("\n Opção invalida");
					printf("\n Press any key to continue......");
					getch();
					editarUtente();
				}
				int opcao;

				if(naonome == 1)
				{
				
					
					Medico medico;
					FILE*med;
					med = fopen("medicos.txt","r");
					if(med == NULL)
					{
						perror("error");
						fclose(med);
						exit(0);
					}
					int CODIGO;char nomeMed[100];

					while (fscanf(med,"%d,%[^\n]", &CODIGO, nomeMed) != EOF) {
						printf("%d %d",utente.codigoMed , CODIGO);
						system("pause");
						if(utente.codigoMed == CODIGO)
						{
							break;
						}
					}
					if(op == 1)
					printf("\n Quer editar o medico[%s] do utente [%s]? (1- Sim  2- Não): ",nomeMed, name);
					if(op==2)
					printf("\n Quer editar o medico[%s] do utente [%s]? (1- Sim  2- Não): ",nomeMed, utente.nome);
					scanf("%d", &opcao);
					if(opcao == 1)
					{
					int i = 1, j = 1;
					int CODIGO;char nomeMed[100];
					rewind(med);
					while (fscanf(med,"%d,%[^\n]", &CODIGO, nomeMed) != EOF) {
						
        			printf("%d-(código,nome) %d,%s\n", i, CODIGO,nomeMed);
 					i++;
					}
					
					fclose(med);
					med=fopen("medicos.txt", "r");
					if(med==NULL)
					{
				  	perror("error");
					  	fclose(med);
					  	exit(0);
					}
					int qualmedico;
					char name1[50], line[100];
					do{
					printf("Insira o número do medico que deseja selecionar : ");
					scanf("%d", &qualmedico);
					}while(qualmedico>=i);
				
					while (fscanf(med,"%d,%[^\n]", &novomedicocodigo, novomediconome) != EOF) {  
					
				    if (j == qualmedico) {
				        break;
				    }
				    
				    j++;
					}
					if (j != qualmedico) {
				    printf("Médico não encontrado!\n");
				    system("pause");
				    registarUtente;
					}
	
					
					}
					else if(opcao == 2)
					{
						if(op == 1)
						fprintf(auxreg, "%d,%s,%d\n", utente.codigo, name, utente.codigoMed);
						if(op == 2)
						fprintf(auxreg, "%d,%s,%d\n", utente.codigo, utente.nome, utente.codigoMed);
						break;
					}
					else{
						printf("\n Opção invalida");
						printf("\n Press any key to continue......");
						getch();
						editarUtente();
					}	
			}
		if(opcao == 1)	
		{
							
		if(op==1)	
   		fprintf(auxreg, "%d,%s,%d\n", utente.codigo, name, novomedicocodigo);
   		if(op==2)
   		fprintf(auxreg, "%d,%s,%d\n", utente.codigo, utente.nome, novomedicocodigo);
   		}
    	}
        else{
        	fprintf(auxreg, "%d,%s,%d\n", utente.codigo, utente.nome, utente.codigoMed);
		}				
}

	fclose(reg);
	fclose(auxreg);
		if(existe == 0)
		{
			printf("Utente não existente...\n");
			system("pause");
			editarUtente();
		}
		if(existe == 1){
			
				printf("\n\n Conta editada com sucesso.\n");
				printf("\n Pressiona qualquer tecla para continuar...");
				getch();
				remove("utentes.txt");
				rename("auxfile.txt","utentes.txt");
				gerirUtente();
				
			}

}	

void consultarUtente(){
	Utente utente;
	system("CLS");
	interfaceUtente();
	FILE*reg = fopen("utentes.txt", "r");
	if(reg == NULL)
	{
		perror("error");
	    fclose(reg);
	    exit(0);
	}
	int codg, existe = 0;
	printf("Insira o código da conta que deseja consultar:");
	scanf("%d", &codg);
	while (fscanf(reg, "%d,%[^,],%d", &utente.codigo, utente.nome, &utente.codigoMed) == 3) {

		if(utente.codigo == codg)
		{
			existe = 1;
			printf("O Utente %s tem o código %d e o código do seu médico é %d.",utente.nome, utente.codigo, utente.codigoMed);
		}
		
	}
	
	if(existe == 0)
	{
		printf("Utente não existente...\n");
		system("pause");
		consultarUtente();
	}
	fclose(reg);
	getch();
	gerirUtente();
}
void eliminarUtente(){
	Utente utente;
	system("CLS");
	interfaceUtente();
	printf("\n =======AVISO=======");
    printf("\n Esta ação é irreversível.\n\n");
	printf("\n Deseja Continuar? 1- Sim 2- Não\n ");
	printf("Opção: ");
	int op;
	scanf("%d",&op);
	if(op==2){
		gerirUtente();
	}
	else if(op == 1)
	{
	    FILE *reg;
	    reg = fopen("utentes.txt","r");
	    if(reg == NULL){
	    	perror("error");
	    	fclose(reg);
	    	exit(0);
		}
		FILE *auxreg;
		auxreg = fopen("auxfile.txt","w");
		int codg,code, codeMed, apagar = 0;
		char name[100];

		printf("Insira o código da conta que deseja eliminar:");
		while (fscanf(reg,"%d,%[^,],%d", &code, name,&codeMed) == 3) {
    	printf("(código,nome,código médico) %d,%s,%d\n", code,name,codeMed);
		}
		rewind(reg);
		scanf("%d", &codg);
		verificarUtente(codg);
		while(fscanf(reg, "%d,%[^\n]", &utente.codigo, utente.nome) != EOF){
			
			if(utente.codigo == codg){
			apagar = 1;
			}else{
			fprintf(auxreg, "%d,%s\n", utente.codigo, utente.nome);
			}
		}
		
		fclose(reg);
		fclose(auxreg);
		if(apagar == 0)
		{
			printf("Utente não existente...\n");
			system("pause");
			eliminarUtente();
		}
		if(apagar == 1){
			printf("\n\n Conta eliminada com sucesso.\n");
			printf("\n Pressiona qualquer tecla para continuar...");
			getch();
			remove("utentes.txt");
			rename("auxfile.txt","utentes.txt");
		}
		gerirUtente();
	}
	else{
		printf("\n Opção invalida");
		printf("\n Press any key to continue......");
		getch();
		eliminarUtente();
	}
}
void listarUtente(){
	system("CLS");
	interfaceUtente();
	Utente utente;
	FILE*reg = fopen("utentes.txt", "r");
	char *linha = malloc(100*sizeof(char));
	int i = 1;
	if(reg == NULL)
	{
		perror("error");
		fclose(reg);
		exit(0);
	}
	
	while(fgets(linha, 100*sizeof(char), reg))
	{
		printf("Utente %d(codigo, nome, código do médico): %s", i,linha);
		strcpy(linha, " ");
		i++;
	}
	fclose(reg);
	free(linha);
	getch();
	gerirUtente();
}











