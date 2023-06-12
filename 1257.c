#include <iostream>
#include <cstring>

int main()
{
    unsigned short casos; // Número de casos
    unsigned short qtsLinhas; // Quantidade de linhas
    unsigned short i, j; // Variáveis de iteração
    unsigned short qtsCaso; // Quantidade de casos atual
    unsigned short qtsLetra; // Quantidade de letras em uma linha
    unsigned somaLetras; // Soma das letras

    char string[60]; // String de entrada

    std::cin >> casos; // Leitura do número de casos

    while (casos--)
    {
        std::cin >> qtsLinhas; // Leitura da quantidade de linhas

        qtsCaso = 0; // Inicialização da quantidade de casos
        somaLetras = 0; // Inicialização da soma das letras

        while (qtsLinhas--)
        {
            std::cin >> string; // Leitura da string

            i = 0; // Inicialização do índice
            qtsLetra = 0; // Inicialização da quantidade de letras

            while (string[i])
            {
                somaLetras += (string[i] - 65) + qtsCaso + qtsLetra; // Cálculo da soma das letras
                qtsLetra++; // Incremento da quantidade de letras
                i++; // Incremento do índice
            }

            qtsCaso++; // Incremento da quantidade de casos

            std::memset(string, 0, sizeof(string)); // Limpeza da string
        }

        std::cout << somaLetras << std::endl; // Impressão da soma das letras
    }

    return 0;
}
