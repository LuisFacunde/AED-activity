#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No* prox;
} No;

No* empilhar(No* topo, char valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

No* desempilhar(No* topo, char* valor) {
    if (!topo) return NULL;
    No* temp = topo;
    *valor = topo->dado;
    topo = topo->prox;
    free(temp);
    return topo;
}

void inverterPalavra(char palavra[]) {
    No* pilha = NULL;
    for (int i = 0; palavra[i] != '\0'; i++)
        pilha = empilhar(pilha, palavra[i]);

    printf("Palavra invertida: ");
    char c;
    while (pilha)
        pilha = desempilhar(pilha, &c), printf("%c", c);
    std::cout << "\n";
}

int main() {
    char palavra[100];
    std::cout << "Digite uma palavra: ";
    std::cin >> palavra;
    inverterPalavra(palavra);
    return 0;
}
