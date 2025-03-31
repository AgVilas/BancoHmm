#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <fstream>
#include <string>

// Classe responsável por manipular arquivos
class Arquivo {
private:
    std::fstream arquivo; // Objeto para manipulação de arquivos

public:
    // Método para gravar texto em um arquivo
    // Parâmetros:
    // - texto: conteúdo a ser gravado no arquivo
    // - nomeArquivo: nome do arquivo onde o texto será salvo
    void arquivar(const std::string& texto, const std::string& nomeArquivo);

    // Método para exibir o conteúdo de um arquivo no console
    // Parâmetro:
    // - nomeArquivo: nome do arquivo cujo conteúdo será exibido
    void mostrararq(const std::string& nomeArquivo);
};

#endif // ARQUIVO_HPP