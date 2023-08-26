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

void registarMedico(){
	system("CLS");
	interfaceMedico();
	Medico medico;
	char nomeAux[100];
	int codigos, k;
	FILE*med; 
	printf("Insira o nome do m�dico a registar(n�o � permitido inserir n�meros): ");
	fflush(stdin);
	gets(nomeAux); 	
	for(k=0;k<(strlen(nomeAux));k++){
		
	if(isdigit(nomeAux[k]))
	{
			printf("O nome n�o pode ter n�meros!\n");
			system("pause");
			registarMedico();
	}
		
	}
	strcpy(medico.nome,nomeAux);
	srand(time(NULL));
    // Gera um n�mero aleat�rio entre 0 e 998 e adiciona 1 para obter um n�mero entre 1 e 999
    medico.codigo = (rand() % 999) + 1;
	
	med=fopen("medicos.txt", "r");
	if(med==NULL)
		{
			perror("error");
	    	fclose(med);
	    	exit(0);
		}
	while (fscanf(med, "%d", &codigos) != EOF) {
        fgetc(med);
        if(codigos == medico.codigo)
        {
        while(codigos == medico.codigo)
        {
        	medico.codigo = rand();
		}
		}

	}
	
	fclose(med);
	fopen("medicos.txt", "a");
	fprintf(med, "%d,%s\n", medico.codigo, medico.nome);
	fclose(med);
	printf("%s, foi lhe atribu�do o c�digo %d e foi colocado com sucesso na base de dados.\n", medico.nome, medico.codigo);
	system("pause");
	
	Criar_Medico_Apontador(medico.codigo, medico.nome);
	
	gerirMedico();
}
void gerirMedico(){
		
	int op;
	system("CLS");
	interfaceMedico();
	printf("1- Registar M�dico 2- Editar M�dico  3- Consultar M�dico  4- Remover M�dico  5- Listar M�dicos  6- Voltar ");
	printf("\n Op��o: ");
	scanf("%d", &op);
	if(op == 1)
	{
		registarMedico();
	}
	else if(op == 2)
	{
		editarMedico();
	}
	else if(op == 3)
	{
		consultarMedico();
	}
	else if(op == 4)
	{
		eliminarMedico();
	}
	else if(op == 5)
	{
		listarMedico();
	}
	else if(op == 6)
	{
		main();
	}
	else{
	
	printf("\n Op��o invalida");
	printf("\n Press any key to continue......");
	getch();
	gerirMedico();
	}
	
	
	
}
void editarMedico(){
	Medico medico;
	int existe = 0, codg, code;
	char novonome[100], name[100];
	system("CLS");
	interfaceMedico();
	FILE *med;
	med = fopen("medicos.txt","r");
	    if(med == NULL){
	    	perror("error");
	    	fclose(med);
	    	exit(0);
		}
		FILE *auxmed;
		auxmed = fopen("auxfile.txt","w");
		printf("Insira o c�digo do m�dico que deseja editar:\n");
		while (fscanf(med,"%d,%[^\n]s", &code, name) != EOF) {
    	printf("(c�digo,nome) %d,%s\n", code,name);
		}
		printf("C�digo :");
		scanf("%d", &codg);
		verificarMedico(codg);
	
    		rewind(med);

   		while (fscanf(med, "%d,%[^\n]", &medico.codigo, medico.nome) == 2) {
           
        if(codg == medico.codigo){
        		existe = 1;
				int op;
				printf("\n Quer editar o nome [%s]? (1- Sim  2- N�o)",medico.nome);
				printf("\n Op��o: ");
				scanf("%d",&op);
				if(op == 1)
				{
				printf("\n Insira o novo nome do m�dico com o codigo %d: ", medico.codigo);
				fflush(stdin);
				gets(novonome);

				}
				else if(op == 2)
				{
					gerirMedico();
				}
				else{
					printf("\n Op��o invalida");
					printf("\n Press any key to continue......");
					getch();
					editarMedico();
				}
			fprintf(auxmed, "%d,%s\n", medico.codigo, novonome);
   
        }
        else{
        	fprintf(auxmed, "%d,%s\n", medico.codigo, medico.nome);
		}
    }


	fclose(med);
	fclose(auxmed);
		if(existe == 0)
		{
			printf("Medico n�o existente...\n");
			system("pause");
			editarMedico();
		}
		if(existe == 1){
				printf("\n\n Conta editada com sucesso.\n");
				printf("\n Pressiona qualquer tecla para continuar...");
				getch();
				remove("medicos.txt");
				rename("auxfile.txt","medicos.txt");
				gerirMedico();		
		}

	
}
void consultarMedico(){
	Medico medico;
	system("CLS");
	interfaceMedico();
	FILE*med = fopen("medicos.txt", "r");
	if(med == NULL)
	{
			perror("error");
	    	fclose(med);
	    	exit(0);
	}
	int codg, existe = 0;
	
	printf("Insira o c�digo da conta que deseja consultar:");
	scanf("%d", &codg);
	while(fscanf(med, "%d,%[^\n]", &medico.codigo, medico.nome) != EOF)
	{
		if(medico.codigo == codg)
		{
			existe = 1;
			printf("O Utente %s tem o c�digo %d.",medico.nome, medico.codigo);
		}
		
	}
	
	if(existe == 0)
	{
		printf("M�dico n�o existente...\n");
		system("pause");
		consultarMedico();
	}
	fclose(med);
	getch();
	gerirMedico();
}
void eliminarMedico(){
	Medico medico; 
	system("CLS");
	interfaceMedico();
	printf("\n =======AVISO=======");
    printf("\n Esta a��o � irrevers�vel.\n\n");
	printf("\n Deseja Continuar? 1- Sim 2- N�o\n ");
	printf("Op��o : ");
	int op;
	scanf("%d",&op);
	if(op==2){
		gerirMedico();
	}
	else if(op == 1)
	{
	    FILE *med;
	    med = fopen("medicos.txt","r");
	    if(med == NULL){
	    	perror("error");
	    	fclose(med);
	    	exit(0);
		}
		FILE *auxreg;
		auxreg = fopen("auxfile.txt","w");
		int codg,code, apagar = 0;
		char name[100];
		system("CLS");
		interfaceMedico();
		while (fscanf(med,"%d,%[^\n]s", &code, name) != EOF) {
    	printf("(c�digo,nome) %d,%s\n", code,name);
		}
		
		printf("Insira o c�digo da conta que deseja eliminar:\n");
		printf("C�digo :");
		scanf("%d", &codg);
		verificarMedico(codg);
				rewind(med);

			while (fscanf(med, "%d,%[^\n]", &medico.codigo, medico.nome) == 2) {
			
			if(medico.codigo == codg){
			apagar = 1;
			}else{
			fprintf(auxreg, "%d,%s\n", medico.codigo, medico.nome);
			}
		}
		
		fclose(med);
		fclose(auxreg);
		if(apagar == 0)
		{
			printf("M�dico n�o existente...\n");
			system("pause");
			eliminarMedico();
		}
		if(apagar == 1){
			printf("\n\n Conta eliminada com sucesso.\n");
			printf("\n Pressiona qualquer tecla para continuar...");
			getch();
			remove("medicos.txt");
			rename("auxfile.txt","medicos.txt");
		}
		gerirMedico();
	}
	else{
		printf("\n Op��o invalida");
		printf("\n Press any key to continue......");
		getch();
		eliminarMedico();
	}
}
void listarMedico(){
	system("CLS");
	interfaceMedico();
    Medico medico;
    FILE*med = fopen("medicos.txt", "r");
    char *linha = malloc(100*sizeof(char));
    int i = 1;
    if(med == NULL)
    {
        	perror("error");
	    	fclose(med);
	    	exit(0);
    }

    while(fgets(linha, 100*sizeof(char), med))
    {
        printf("Medico %d(codigo, nome): %s", i,linha);
        strcpy(linha, " ");
        i++;
    }
    fclose(med);
    free(linha);
    system("pause");
    gerirMedico();
}
