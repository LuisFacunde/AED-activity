#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[50];
    struct No* prox;
} No;

typedef struct {
    No* frente;
    No* tras;
} Fila;

Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->frente = f->tras = NULL;
    return f;
}

void enfileirar(Fila* f, char nome[]) {
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (!f->tras) {
        f->frente = f->tras = novo;
        return;
    }
    f->tras->prox = novo;
    f->tras = novo;
}

void desenfileirar(Fila* f) {
    if (!f->frente) 
        return;
    No* temp = f->frente;
    f->frente = f->frente->prox;
    if (!f->frente) f->tras = NULL;
        free(temp);
}

void imprimirFila(Fila* f) {
    No* temp = f->frente;
    while (temp) {
        std::cout << temp->nome << " <- ";
        temp = temp->prox;
    }
    std::cout << "NULL \n";
}

int main() {
    Fila* fila = criarFila();
    enfileirar(fila, "Ana");
    enfileirar(fila, "Bruno");
    enfileirar(fila, "Carlos");
    imprimirFila(fila);

    desenfileirar(fila);
    imprimirFila(fila);

    return 0;
}
