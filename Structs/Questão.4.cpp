#include <iostream>
#include <stdlib.h>

typedef struct Carro
{
    char modelo[30];
    int ano;
    float preco;
} Carro;

void preencheCarro(Carro *carro)
{
    std::cout << "Digite o modelo do carro: " << std::endl;
    std::cin.getline(carro->modelo, 30);
    std::cout << "Digite o ano de fabricacao do carro: " << std::endl;
    std::cin >> carro->ano;
    std::cout << "Digite o preco carro: " << std::endl;
    std::cin >> carro->preco;
}

void exibeCarro(Carro *carro)
{
    std::cout << "\n------- Dados do carro -------\n";
    std::cout << "Modelo do carro: " << carro->modelo << std::endl;
    std::cout << "Ano de fabricacao: " << carro->ano << std::endl;
    std::cout << "Digite o preco do carro: R$ " << carro->preco << ",00" << std::endl;
}

int main()
{
    Carro *carro = (Carro*) malloc(sizeof(Carro));

    preencheCarro(carro);
    exibeCarro(carro);

    free(carro);

    return 0;
}