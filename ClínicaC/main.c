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

int main()
{
    system("CLS");
    setlocale(LC_ALL, "Portuguese"); 
    criaFiles();
    interface();
    int op = menu();
    if(op){ //Menu de opções
        if(op==1)
        gerirListaEspera();

        else if(op==2)
        gerirMedico();

        else if(op==3)
        gerirUtente();

        else if(op==4)
        sairPrograma();

    }else{
        return 0;
    }
}
