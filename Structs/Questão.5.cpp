#include <iostream>
#include <stdlib.h>

typedef struct Funcionarios
{
    char nome[50];
    char cargo[30];
    float salario;
} Funcionarios;

void preencheFuncionario(Funcionarios *funcionario)
{
    std::cout << "\n------ Cadastro de funcionario ------\n";

    std::cout << "Informe o nome do funcionario: " << std::endl;
    std::cin.getline(funcionario->nome, 50);

    std::cout << "Cargo do funcionario: " << std::endl;
    std::cin.getline(funcionario->cargo, 30);

    std::cout << "Salario: " << std::endl;
    std::cin >> funcionario->salario;
    std::cin.ignore();
}

void exibeFuncionario(Funcionarios *funcionario)
{
    std::cout << "\n====== Lista de funcionarios ======\n";
    std::cout << "Nome do funcionario: " << funcionario->nome << std::endl;
    std::cout << "Cargo do funcionario: " << funcionario->cargo << std::endl;
    std::cout << "Salario: R$ " << funcionario->salario << ",00" << std::endl;
}

int main()
{
    int quantidade;

    std::cout << "Quanto funcinarios deseja cadastrar?" << std::endl;
    std::cin >> quantidade;
    std::cin.ignore();

    Funcionarios *funcionario = (Funcionarios *)malloc(quantidade * sizeof(Funcionarios));

    for (int i = 0; i < quantidade; i++)
    {
        preencheFuncionario(&funcionario[i]);
    }

    for (int i = 0; i < quantidade; i++)
    {
        exibeFuncionario(&funcionario[i]);
    }

    free(funcionario);

    return 0;
}