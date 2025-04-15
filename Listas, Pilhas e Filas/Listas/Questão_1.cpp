#include <iostream>
#include <stdlib.h>

typedef struct No 
{
    int valor;
    No *prox;
} No;

No* inserirInicio (int valor, No* lista)
{
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = lista;
    return novoNo;
}

No* inserirFinal (int valor, No* lista)
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

void exibeLista (No* lista)
{
    No* temp = lista;
    while(temp)
    {
        std::cout << temp->valor << " -> ";
        temp = temp->prox;
    }
    std::cout << "NULL \n";
}

int main()
{
    No* lista = NULL;
    lista = inserirInicio(30, lista);
    lista = inserirInicio(20, lista);
    lista = inserirInicio(10, lista);
    lista = inserirFinal(40, lista);
    lista = inserirFinal(50, lista);
    lista = inserirFinal(60, lista);
    lista = inserirFinal(70, lista);
    exibeLista(lista);

    lista = removerNo(50, lista);
    exibeLista(lista);

    lista = removerNo(10, lista);
    exibeLista(lista);

    lista = removerNo(70, lista);
    exibeLista(lista);

    return 0;
}
