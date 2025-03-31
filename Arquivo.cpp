#include "Arquivo.hpp"
#include <iostream>
#include <fstream>
#include <string>

// Construtor padrão.
Arquivo::Arquivo() {}

// Salva o conteúdo no arquivo indicado.
void Arquivo::salvarConteudo(const string& conteudo, const string& nomeArquivo) const {
    std::ofstream arquivoSaida(nomeArquivo);
    if (arquivoSaida.is_open()) {
        arquivoSaida << conteudo << "\n";
        arquivoSaida.close();
    } else {
        std::cout << "Erro ao abrir o arquivo para escrita." << std::endl;
    }
}

// Exibe o conteúdo do arquivo indicado.
void Arquivo::exibirConteudo(const string& nomeArquivo) const {
    std::ifstream arquivoEntrada(nomeArquivo);
    std::string linha;
    std::cout << "Conteúdo do arquivo:\n";
    if (arquivoEntrada.is_open()) {
        while (std::getline(arquivoEntrada, linha)) {
            std::cout << linha << std::endl;
        }
        arquivoEntrada.close();
    } else {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }
}
