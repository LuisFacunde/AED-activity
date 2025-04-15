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

No *removerNo(int valor, No *lista)
{
    if (!lista)
        return NULL;

    if (lista->valor == valor)
    {
        No *temp = lista;
        lista = lista->prox;
        free(temp);
        return lista;
    }

    No *anterior = lista;
    No *atual = lista->prox;

    while (atual != NULL && atual->valor != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL)
    {
        anterior->prox = atual->prox;
        free(atual);
    }

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

    lista = removerNo(20, lista);
    imprimirLista(lista);

    lista = removerNo(30, lista);
    imprimirLista(lista);

    lista = removerNo(40, lista);
    imprimirLista(lista);

    return 0;
}