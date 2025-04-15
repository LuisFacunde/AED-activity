#include <iostream>

typedef struct Produto
{
    char nome[30];
    int codigo;
    float preco;
} Produto;

void exibirProduto(Produto produto)
{
    std::cout << "---------------------" << std::endl;
    std::cout << "Nome do produto: " << produto.nome << std::endl;
    std::cout << "Codigo do produto: " << produto.codigo << std::endl;
    std::cout << "Preco do produto: R$ " << produto.preco << ",00" << std::endl;
}

int main()
{
    Produto produto;

    std::cout << "Nome do produto: " << std::endl;
    std::cin.getline(produto.nome, 30);
    std::cout << "Codigo do produto: " << std::endl;
    std::cin >> produto.codigo;
    std::cout << "Preco do produto: " << std::endl;
    std::cin >> produto.preco;
    
    exibirProduto(produto);
    
    return 0;
}