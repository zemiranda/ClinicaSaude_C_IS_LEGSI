typedef struct utente{
    int codigo, codigoMed;
    char nome[100];
    struct utente* proximo;
}Utente;

typedef struct medico{
    int codigo; 
    char nome[100];
    Utente * fila_espera;
    struct medico* proximo;
}Medico;
