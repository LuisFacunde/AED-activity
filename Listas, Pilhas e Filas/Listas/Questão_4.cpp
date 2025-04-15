#include <iostream>
#include <stdlib.h>

typedef struct No 
{
    int valor;
    No *prox;
} No;

No* inserirInicio(int valor, No* lista)
{
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = lista;
    return novoNo;
}

No* inserirFinal(int valor, No* lista)
{
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (!lista)
        return novoNo;

    No* temp = lista;
    while (temp->prox)
        temp = temp->prox;
    temp->prox = novoNo;
    return lista;
}

No* removerNo(int valor, No* lista)
{
    No* atual = lista;
    No* anterior = NULL;

    if (atual != NULL && atual->valor == valor)
    {
        lista = atual->prox;
        free(atual);
        return lista;
    }

    while (atual != NULL && atual->valor != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return lista;

    anterior->prox = atual->prox;
    free(atual);
    return lista;
}

int contarElementos(No* lista)
{
    int cont = 0;
    No* temp = lista;
    while (temp)
    {
        cont++;
        temp = temp->prox;
    }
    return cont;
}

No* inserirOrdenado(int valor, No* lista)
{
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (!lista || valor < lista->valor)
    {
        novoNo->prox = lista;
        return novoNo;
    }

    No* atual = lista;
    while (atual->prox && atual->prox->valor < valor)
    {
        atual = atual->prox;
    }

    novoNo->prox = atual->prox;
    atual->prox = novoNo;
    return lista;
}

No* reverterLista(No* lista)
{
    No* anterior = NULL;
    No* atual = lista;
    No* proximo = NULL;

    while (atual)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}

void exibeLista(No* lista)
{
    No* temp = lista;
    while (temp)
    {
        std::cout << temp->valor << " -> ";
        temp = temp->prox;
    }
    std::cout << "NULL \n";
}

int main()
{
    No* lista = NULL;

    lista = inserirOrdenado(50, lista);
    lista = inserirOrdenado(10, lista);
    lista = inserirOrdenado(30, lista);
    lista = inserirOrdenado(20, lista);
    lista = inserirOrdenado(40, lista);

    std::cout << "Lista ordenada: ";
    exibeLista(lista);

    std::cout << "Numero de elementos: " << contarElementos(lista) << "\n";

    std::cout << "Removendo o valor 30:\n";
    lista = removerNo(30, lista);
    exibeLista(lista);

    std::cout << "Lista revertida:\n";
    lista = reverterLista(lista);
    exibeLista(lista);

    return 0;
}
