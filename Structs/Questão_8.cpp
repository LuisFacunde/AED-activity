#include <iostream>
#include <stdlib.h>

typedef struct Retangulo
{
    float base;
    float altura;
} Retangulo;

double calcularArea(Retangulo r)
{
    return (r.base * r.altura) / 2;
}

double calcularPerimetro(Retangulo r)
{
    return (r.base * 2) + (r.altura * 2);
}

int main()
{
    Retangulo retangulo;

    std::cout << "Digite o tamanho da base do retangulo: " << std::endl;
    std::cin >> retangulo.base;
    std::cout << "Digite a altura do retangulo: " << std::endl;
    std::cin >> retangulo.altura;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Area do retangulo: " << calcularArea(retangulo) << " m²" << std::endl;
    std::cout << "Perimetro do retangulo: " << calcularPerimetro(retangulo) << " m" << std::endl;

    return 0;
}