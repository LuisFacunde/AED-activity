#include <iostream>

int contarDigitos(int n)
{
    if (n < 10 && n > -10)
        return 1;

    return 1 + contarDigitos(n / 10);
}

int main()
{
    int numero;
    std::cout << "Digite um numero inteiro: ";
    std::cin >> numero;
    
    std::cout << "O numero " << numero << " possui " << contarDigitos(numero) << " digitos." << std::endl;

    return 0;
}