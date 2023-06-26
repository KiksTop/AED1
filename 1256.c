#include <iostream>
#include <cstdlib>

struct Node {
    int key;
    Node* next;
};

int main() {
    int teste, endereco_base, chaves;
    std::cin >> teste;

    while (teste > 0) {
        std::cin >> endereco_base >> chaves;
        Node** hash = new Node*[endereco_base];  // Cria um array de ponteiros para nós

        for (int i = 0; i < endereco_base; i++) {
            hash[i] = nullptr;  // Inicializa todos os ponteiros com nullptr
        }

        for (int i = 0; i < chaves; i++) {
            int chaveamento;
            std::cin >> chaveamento;
            int aux = chaveamento % endereco_base;  // Calcula o índice onde a chave será armazenada

            Node* newNode = new Node;  // Cria um novo nó
            newNode->key = chaveamento;
            newNode->next = nullptr;

            if (hash[aux] == nullptr) {  // Se o índice estiver vazio, insere o nó diretamente
                hash[aux] = newNode;
            } else {  // Caso contrário, percorre a lista até o último nó e insere o novo nó no final
                Node* current = hash[aux];
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        // Imprime a tabela de hash
        for (int i = 0; i < endereco_base; i++) {
            std::cout << i << " ->";

            if (hash[i] == nullptr) {  // Se o índice estiver vazio, imprime apenas o símbolo '\'
                std::cout << " \\";
            } else {  // Caso contrário, imprime os elementos da lista encadeada
                Node* current = hash[i];
                while (current != nullptr) {
                    std::cout << " " << current->key << " ->";
                    current = current->next;
                }
                std::cout << " \\";
            }

            if(i + 1 != endereco_base) {  // Verifica se é o último elemento para imprimir uma nova linha
                std::cout << std::endl;
            }
        }

        // Libera a memória alocada pelos nós da lista encadeada
        for (int i = 0; i < endereco_base; i++) {
            Node* current = hash[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }

        delete[] hash;  // Libera a memória alocada pelo array de ponteiros
        if(teste - 1 != 0) {
            std::cout << std::endl << std::endl;
        } else {
            std::cout << std::endl;
        }
        teste--;
    }

    return 0;
}
