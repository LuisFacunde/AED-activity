#include <iostream>

typedef struct Aluno
{
    char nome[50];
    int matricula;
    float nota;
} Aluno;

int main()
{
    Aluno aluno[5];

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Nome do aluno: " << std::endl;
        std::cin.getline(aluno[i].nome, 50);
        std::cout << "Matrícula: " << std::endl;
        std::cin >> aluno[i].matricula;
        std::cout << "Nota: " << std::endl;
        std::cin >> aluno[i].nota;
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Nome do aluno: " << aluno[i].nome << std::endl;
        std::cout << "Matrícula: " << aluno[i].matricula << std::endl;
        std::cout << "Nota: " << aluno[i].nota << std::endl;
    }

    return 0;
}