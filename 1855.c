#include <stdio.h>
#include <stdbool.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Função para verificar se um mapa dado é válido
bool is_valid_map(int width, int height, char map[MAX_HEIGHT][MAX_WIDTH]) {
    // Array visitado para manter o controle das células visitadas
    bool visited[MAX_HEIGHT][MAX_WIDTH] = {false};

    // Coordenadas do ponto de partida
    int x = 0;
    int y = 0;

    // Direção inicial
    int dx = 1;
    int dy = 0;

    while (true) {
        // Verifica se a célula atual é uma célula visitada
        if (visited[y][x])
            return false;

        // Marca a célula atual como visitada
        visited[y][x] = true;

        // Obtém o símbolo na célula atual
        char symbol = map[y][x];

        // Verifica o símbolo na célula atual
        if (symbol == '*')
            return true;  // Encontrou o baú com obsidiana
        else if (symbol == '>') {
            dx = 1;
            dy = 0;
        } else if (symbol == '<') {
            dx = -1;
            dy = 0;
        } else if (symbol == 'v') {
            dx = 0;
            dy = 1;
        } else if (symbol == '^') {
            dx = 0;
            dy = -1;
        }

        // Move para a próxima célula
        x += dx;
        y += dy;

        // Verifica se a próxima célula está fora dos limites do mapa
        if (x < 0 || x >= width || y < 0 || y >= height)
            return false;
    }

    // Nenhuma condição de parada foi encontrada, o que indica um caminho inválido
    return false;
}

int main() {
    int width, height;
    char map[MAX_HEIGHT][MAX_WIDTH];

    // Lê a largura e altura do mapa
    scanf("%d", &width);
    scanf("%d", &height);

    // Descarta o caractere de nova linha '\n' após a leitura da altura
    getchar();

    // Lê os dados do mapa
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Lê cada caractere individualmente
            map[i][j] = getchar();
        }

        // Descarta o caractere de nova linha '\n' no final de cada linha
        getchar();
    }

    // Verifica se o mapa é válido
    if (is_valid_map(width, height, map))
        printf("*\n");  // Mapa é válido
    else
        printf("!\n");  // Mapa é inválido

    return 0;
}
