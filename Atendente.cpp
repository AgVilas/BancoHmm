#include "Atendente.hpp"

// Construtor da classe Atendente.
Atendente::Atendente(const string& nomeCompleto, int idade, const string& genero, int salario, const string& identificacao,
                     int numeroBalcao, const string& categoriaAtendente)
    : Funcionario(nomeCompleto, idade, genero, salario, identificacao),
      numeroBalcao(numeroBalcao), categoriaAtendente(categoriaAtendente) {}

// Retorna o número do balcão.
int Atendente::getNumeroBalcao() const {
    return numeroBalcao;
}

// Define o número do balcão.
void Atendente::setNumeroBalcao(int numeroBalcao) {
    this->numeroBalcao = numeroBalcao;
}

// Retorna a categoria do atendente.
string Atendente::getCategoriaAtendente() const {
    return categoriaAtendente;
}

// Cria e retorna uma nova ContaCartao para o cliente.
ContaCartao Atendente::abrirConta(const string& nomeCompleto, int idade, const string& genero, const string& tipoConta) const {
    return ContaCartao(nomeCompleto, idade, genero, tipoConta);
}

// Obtém os detalhes do atendente.
string Atendente::obterDetalhes() const {
    return "Informações do Atendente:\nNúmero do Balcão: " + std::to_string(numeroBalcao) +
           "\nCategoria: " + categoriaAtendente +
           "\nDados do Funcionário:\n" + Funcionario::obterDetalhes();
}
