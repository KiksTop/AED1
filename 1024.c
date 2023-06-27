#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Inverte(char *M) {
    int tamanho = strlen(M);

    for (int i = 0; i < tamanho / 2; i++) {
        // Inverte os caracteres
        char temp = M[i];
        M[i] = M[tamanho - i - 1];
        M[tamanho - i - 1] = temp;

        // Adiciona +2 usando a tabela ASCII
        M[i] += 2;
        M[tamanho - i - 1] += 2;

        // Se houver espaço, substituir por '\n'
        if (M[i] == ' ') {
            M[i] = '\n';
        }
    
    }
    Print(M); 
}

void Leitura(char *M, int N) {
    for (int i = 0; i < N; i++) {
        fgets(M, 1000, stdin);
        M[strcspn(M, "\n")] = '\0'; // Remove o caractere de nova linha
    }
}

void Print(char * M){
    printf("%s", M);
    free(M); // Libera a memória alocada
}


int main() {
    int N;
    char *M;
    M = (char *) malloc(1000 * sizeof(char));

    scanf("%d", &N);
    
    
    Leitura(M, N);
    Inverte (M);
    

    return 0;
}
