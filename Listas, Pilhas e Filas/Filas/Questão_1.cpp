#include <iostream>
#include <stdlib.h>

typedef struct No
{
    int valor;
    No *prox;
} No;

No *inserirInicio(int valor, No *lista)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = lista;
    return novoNo;
}

No *inserirFinal(int valor, No *lista)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    // Se a lista estiver vazia esse será o novo elemeno
    if (!lista)
        return novoNo;

    // Criação do temporário para armazenar o endereço da lista e
    No *temp = lista;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = novoNo;
    return lista;
}

void imprimirLista(No *lista)
{
    No *temp = lista;
    while (temp)
    {
        std::cout << temp->valor << " -> ";
        temp = temp->prox;
    }
    std::cout << "NULL \n";
}

int main()
{
    No *lista = NULL;

    lista = inserirInicio(10, lista);
    lista = inserirInicio(20, lista);
    lista = inserirInicio(30, lista);
    lista = inserirFinal(40, lista);
    imprimirLista(lista);

    return 0;
}