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

Medico *medicos = NULL;

void Criar_Medico_Apontador(int codigoMed, char *nome){
	int medico_ja_criado = 0;
	Medico* atualMedico = medicos;
	//percorrer pela lista de medicos para verificar se o medico ja esta na fila de espera
    while (atualMedico != NULL) { 
        if (atualMedico->codigo == codigoMed) {
            medico_ja_criado = 1;
            return;
        }
        atualMedico = atualMedico->proximo;
    }
	if(medico_ja_criado == 0){
		//Adicionar Medico na lista de medicos com os parametros recebidos do ficheiro 
	    Medico* novoMedico = malloc(sizeof(Medico));
	    novoMedico->codigo = codigoMed;
	    strcpy(novoMedico->nome, nome);
	    novoMedico->fila_espera = NULL;
	    
	    // Adiciona o novo médico à lista
	    novoMedico->proximo = medicos;
	    medicos = novoMedico;
	}
}

void Colocar_Utente_Fila_Espera( Utente *utente){
	//Criar um auxiliar para adicionar um utente a fila de espera dos utentes
	Utente* novoUtenteFila = malloc(sizeof(Utente));
	novoUtenteFila->codigo = utente->codigo;
	strcpy(novoUtenteFila->nome, utente->nome);
	novoUtenteFila->proximo = NULL;	
	
	//Apontador auxiliar para a lista medicos
	Medico* atualMedico = medicos;
	//Percorrer pelos Medicos ate encontrar o medico com o codigo correspondente ao medico de familia do utente
	while (atualMedico != NULL) {
	    if (atualMedico->codigo == utente->codigoMed) {
	        Utente* atualUtente = atualMedico->fila_espera;
	        //Introduzir o utente caso a fila esteja vazia
	        if (atualUtente == NULL) {
	            atualMedico->fila_espera = novoUtenteFila;
	            printf("\n%s, foi lhe atribuído o código %d e foi colocado com sucesso na lista de espera do médico %s.\n",utente->nome, utente->codigo,atualMedico->nome);
	        } else {
	        	//Verificar se o utente ja esta presente na fila de espera
	            while (atualUtente != NULL) {
				    if (atualUtente->codigo == novoUtenteFila->codigo) {
				        printf("\nEsse utente ja se encontra na fila de espera!\n");
				        break;
				    }
				    //Caso a lista nao esteja vazia avancar com o apontador auxiliar ate encontrar uma posição vazia
				    if (atualUtente->proximo == NULL) {
				        atualUtente->proximo = novoUtenteFila;
	            	printf("\n%s, foi lhe atribuído o código %d e foi colocado com sucesso na lista de espera do médico %s.\n",utente->nome, utente->codigo,atualMedico->nome);
				        break;
				    }
				    atualUtente = atualUtente->proximo;
				}

	        }				        
	        break;
	    }
	    atualMedico = atualMedico->proximo;
	}
		
	system("pause");
}

void Remover_Primeiro_Utente_Fila_Espera(int cod_medico) {
	Medico* atualMedico = medicos;

	//loop para procurar o medico atraves do cod_medico introduzido de modo a eleminar o primeiro utente na sua fila
	while(atualMedico != NULL){
		if(atualMedico->codigo == cod_medico){
			//verificar se a fila do atualMedico esta vazia
			if(atualMedico->fila_espera == NULL){
				printf("Erro: Nao ha ninguem na fila de espera!\n");
			}else{
    			Utente *primeiroUtente = atualMedico->fila_espera;
    			//verificar se a fila do atualMedico esta vazia
				if (primeiroUtente == NULL) {
					printf("Fila de espera vazia.\n");
					return;
				}
				//Coloca o segundo Utente no lugar do primeiro
				//Como se trata de uma lista ligada o novo primeiro vai estar ligado ao antigo terceiro elemento
				atualMedico->fila_espera = primeiroUtente->proximo;
				printf("Primeiro utente - (%s) da fila de espera de %s removido.\n", primeiroUtente->nome, atualMedico->nome);
				free(primeiroUtente);
				break;
			}
		}
		atualMedico = atualMedico->proximo;
		
	}
    system("pause");
}

void listarIndividual(int codigo_medico){

            //auxiliar para a lista medicos        
            Medico* atualMedico = medicos;
			while (atualMedico != NULL) {
				//atraves do codigo de medico lista a fila de utentes 
			    if(atualMedico->codigo == codigo_medico){
			    	//auxiliar para percorrer pela fila dos utentes
			    	Utente* atualUtente = atualMedico->fila_espera;
			    	printf("Utentes na atual fila de espera de %s\n", atualMedico->nome);
				    while (atualUtente != NULL) {
				        printf("\nNome: %s, Código: %d\n", atualUtente->nome, atualUtente->codigo);
				        atualUtente = atualUtente->proximo;
				        
				    }
				}
			    atualMedico = atualMedico->proximo;
			}     
			system("pause");
}

void MedicoComMaisUtentes(){

Medico* atualMedico = medicos;	

if(atualMedico==NULL){
	gerirListaEspera();
}
int numMedicoComMaisUtentes=0,maiorFila=0,qtdUtentes=0;
char nomeMedicoComMaisUtentes[100];
	while (atualMedico != NULL) {
		qtdUtentes=0;
		Utente* atualUtente = atualMedico->fila_espera;
		//percorre a lista de espera de cada medico e conta os seus utentes
		while (atualUtente != NULL){	
	
		atualUtente = atualUtente->proximo;
		qtdUtentes++;
		}
		//compara o valor obtido com o antigo maior e guarda o codigo do medico com mais utentes
		if(qtdUtentes>=maiorFila){
			maiorFila=qtdUtentes;
			numMedicoComMaisUtentes=atualMedico->codigo;
			strcpy(nomeMedicoComMaisUtentes,atualMedico->nome);
		}
		

		 atualMedico = atualMedico->proximo;
	}

	printf("\nO medico com mais utentes na fila de espera: \n Nome: %s  Codigo: %d Quantidade de Utentes: %d\n", nomeMedicoComMaisUtentes,numMedicoComMaisUtentes,maiorFila);

}
void ListarTodasFilas(){
	Medico* atualMedico = medicos;
	//percorre a lista dos medicos e executar sucessivamente a função listarIndividual
		while (atualMedico != NULL) {
		listarIndividual(atualMedico->codigo);
		printf("\n");
		 atualMedico = atualMedico->proximo;
		}
	
}

void verificarUtente(int codigo){
 
 
Medico* atualMedico = medicos;	


while(atualMedico!=NULL){
	Utente* atualUtente = atualMedico->fila_espera;	
	while(atualUtente!=NULL){
		if(codigo==atualUtente->codigo){
			printf("Não é possivel gerir utente que esteja na lista de espera!\n");
			system("pause");
			gerirListaEspera();
		}
		 atualUtente = atualUtente->proximo;
	}
	 atualMedico = atualMedico->proximo;
}
}

void verificarMedico(int codigo){
	
	Medico* atualMedico = medicos;	
	
	while(atualMedico!=NULL){
			if(codigo==atualMedico->codigo){
				printf("Não é possivel gerir médico que esteja na lista de espera!\n");
				system("pause");
				gerirListaEspera();
			}
			 atualMedico = atualMedico->proximo;
	}
}

void numeroUtentesporMedico(){
	
Medico* atualMedico = medicos;	

if(atualMedico==NULL){
	gerirListaEspera();
}
int numMedicoComMaisUtentes=0,maiorFila=0,qtdUtentes=0;

	while (atualMedico != NULL) {
		qtdUtentes=0;
		Utente* atualUtente = atualMedico->fila_espera;
		while (atualUtente != NULL){	
	    
		 atualUtente = atualUtente->proximo;
		qtdUtentes++;
		}	
 		printf("\nNome: %s  Codigo: %d Quantidade de Utentes: %d\n", atualMedico->nome,atualMedico->codigo,qtdUtentes);
		atualMedico = atualMedico->proximo;
		
	}

}

