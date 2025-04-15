#include <iostream>

typedef struct Pessoa
{
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main()
{
    Pessoa pessoa;

    std::cout << "Digite o seu nome: " << std::endl;
    std::cin.getline(pessoa.nome, 50);
    std::cout << "Informe a sua idade: " << std::endl;
    std::cin >> pessoa.idade;
    std::cout << "Informe a sua altura: " << std::endl;
    std::cin >> pessoa.altura;

    std::cout << "Nome: " << pessoa.nome << std::endl;
    std::cout << "Idade: " << pessoa.idade << std::endl;
    std::cout << "Altura: " << pessoa.altura << std::endl;

    return 0;
}