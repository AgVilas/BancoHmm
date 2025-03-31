#include "Pessoa.hpp"
#include <string>

// Construtor da classe Pessoa.
Pessoa::Pessoa(const string& nomeCompleto, int idade, const string& genero)
    : nomeCompleto(nomeCompleto), idade(idade), genero(genero) {}

// Retorna o nome completo da pessoa.
string Pessoa::getNomeCompleto() const {
    return nomeCompleto;
}

// Define o nome completo da pessoa.
void Pessoa::setNomeCompleto(const string& nomeCompleto) {
    this->nomeCompleto = nomeCompleto;
}

// Retorna a idade da pessoa.
int Pessoa::getIdade() const {
    return idade;
}

// Define a idade da pessoa.
void Pessoa::setIdade(int idade) {
    this->idade = idade;
}

// Retorna o gênero da pessoa.
string Pessoa::getGenero() const {
    return genero;
}

// Define o gênero da pessoa.
void Pessoa::setGenero(const string& genero) {
    this->genero = genero;
}

// Obtém os detalhes da pessoa em formato de string.
string Pessoa::obterDetalhes() const {
    return "Nome: " + nomeCompleto + "\nIdade: " + std::to_string(idade) +
           "\nGênero: " + genero;
}
