#include <iostream>
#include <stdlib.h>

typedef struct Livro 
{
    char titulo[50];
    char autor[50];
    int anoPubli;
} Livro;

void exibeLivro(Livro biblioteca[], int ano, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (biblioteca[i].anoPubli >= ano)
        {
            std::cout << "Titulo do livro: " << biblioteca[i].titulo << std::endl;
            std::cout << "Nome do autor: " << biblioteca[i].autor << std::endl;
            std::cout << "Ano de publicacao: " << biblioteca[i].anoPubli << std::endl;
        }   
    }
}

void cadastraLivro (Livro biblioteca[], int quantidade) 
{
    for (int i = 0; i < quantidade; i++)
    {
        std::cout << "Digite o titulo do livro: " << std::endl;
        std::cin.getline(biblioteca[i].titulo, 50);
        std::cout << "Digite o nome do autor: " << std::endl;
        std::cin.getline(biblioteca[i].autor, 50);
        std::cout << "Digite o ano de publicacao: " << std::endl;
        std::cin >> biblioteca[i].anoPubli;
        std::cin.ignore();
    }
}

int main()
{
    int quantidade, ano;

    std::cout << "Quantos livros serao cadastrados?" << std::endl;
    std::cin >> quantidade;
    std::cin.ignore();

    Livro biblioteca[quantidade];
    cadastraLivro(biblioteca, quantidade);

    std::cout << "Voce quer exibir os livros lancados a partir de que ano? " << std::endl;
    std::cin >> ano;
    std::cin.ignore();
    exibeLivro(biblioteca, ano, quantidade);
}