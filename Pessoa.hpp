#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
using std::string;

/**
 * @brief Classe base que representa uma pessoa.
 */
class Pessoa {
protected:
    string nomeCompleto;  // Nome completo da pessoa
    int idade;            // Idade da pessoa
    string genero;        // Gênero da pessoa

public:
    // Construtor com inicialização dos atributos.
    Pessoa(const string& nomeCompleto, int idade, const string& genero);

    // Métodos de acesso (getters) e modificação (setters)
    string getNomeCompleto() const;
    void setNomeCompleto(const string& nomeCompleto);
    int getIdade() const;
    void setIdade(int idade);
    string getGenero() const;
    void setGenero(const string& genero);

    // Retorna os detalhes da pessoa formatados em string.
    string obterDetalhes() const;
};

#endif // PESSOA_HPP
