#include "Arquivo.hpp"
#include <iostream>
#include <fstream>

// Método para salvar texto em um arquivo
void Arquivo::salvarTextoEmArquivo(const std::string& texto, const std::string& nomeDoArquivo) {
    // Abre o arquivo no modo de saída (escrita)
    arquivo.open(nomeDoArquivo, std::ios::out);

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo.is_open()) {
        // Escreve o texto no arquivo e adiciona uma nova linha
        arquivo << texto << "\n";

        // Fecha o arquivo após a escrita
        arquivo.close();
    } else {
        // Exibe uma mensagem de erro caso o arquivo não possa ser aberto
        std::cout << "Erro ao abrir o arquivo para escrita!" << std::endl;
    }
}

// Método para exibir o conteúdo de um arquivo no console
void Arquivo::exibirConteudoDoArquivo(const std::string& nomeDoArquivo) {
    // Abre o arquivo no modo de entrada (leitura)
    arquivo.open(nomeDoArquivo, std::ios::in);

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo.is_open()) {
        std::string linha;

        // Lê o arquivo linha por linha e exibe no console
        while (std::getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }

        // Fecha o arquivo após a leitura
        arquivo.close();
    } else {
        // Exibe uma mensagem de erro caso o arquivo não possa ser aberto
        std::cout << "Erro ao abrir o arquivo para leitura!" << std::endl;
    }
}