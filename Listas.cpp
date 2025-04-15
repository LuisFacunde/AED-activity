#include <iostream>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

// Inserir no início da lista
No* inserirInicio(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = lista;
    return novo;
}

// Inserir no final da lista
No* inserirFim(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    if (!lista) return novo;
    
    No* temp = lista;
    while (temp->prox) temp = temp->prox;
    temp->prox = novo;
    return lista;
}

// Imprimir a lista
void imprimirLista(No* lista) {
    No* temp = lista;
    while (temp) {
        std::cout << temp->dado << " -> ";
        temp = temp->prox;
    }
    std::cout << "NULL \n";
}

int main() {
    No* lista = NULL;
    lista = inserirInicio(lista, 10);
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 30);
    lista = inserirFim(lista, 40);
    lista = inserirFim(lista, 50);
    imprimirLista(lista);
    return 0;
}
