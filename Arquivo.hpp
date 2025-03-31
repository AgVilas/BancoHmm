#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <string>
using std::string;

/**
 * @brief Classe para manipulação de arquivos (salvar e exibir conteúdo).
 */
class Arquivo {
public:
    Arquivo(); // Construtor

    // Salva o conteúdo informado em um arquivo com o nome especificado.
    void salvarConteudo(const string& conteudo, const string& nomeArquivo) const;

    // Exibe o conteúdo do arquivo especificado.
    void exibirConteudo(const string& nomeArquivo) const;
};

#endif // ARQUIVO_HPP
