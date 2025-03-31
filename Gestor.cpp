#include "Gestor.hpp"
#include <iostream>
#include <string>

// Construtor da classe Gestor.
Gestor::Gestor(const string& nomeCompleto, int idade, const string& genero, int salario, const string& identificacao,
               const string& setor, const string& cargo, int numeroFuncionariosGerenciados)
    : Funcionario(nomeCompleto, idade, genero, salario, identificacao),
      setor(setor), cargo(cargo), numeroFuncionariosGerenciados(numeroFuncionariosGerenciados) {}

// Retorna o setor de atuação do gestor.
string Gestor::getSetor() const {
    return setor;
}

// Define o setor de atuação do gestor.
void Gestor::setSetor(const string& setor) {
    this->setor = setor;
}

// Retorna o cargo do gestor.
string Gestor::getCargo() const {
    return cargo;
}

// Retorna o número de funcionários gerenciados.
int Gestor::getNumeroFuncionariosGerenciados() const {
    return numeroFuncionariosGerenciados;
}

// Define o número de funcionários gerenciados.
void Gestor::setNumeroFuncionariosGerenciados(int numero) {
    numeroFuncionariosGerenciados = numero;
}

// Autoriza empréstimo se a conta for do tipo "Conta Corrente".
bool Gestor::autorizarEmprestimo(const string& tipoConta) const {
    return tipoConta == "Conta Corrente";
}

// Retorna os detalhes do gestor.
string Gestor::obterDetalhes() const {
    return "Informações do Gestor:\nSetor: " + setor +
           "\nCargo: " + cargo +
           "\nNúmero de Funcionários Gerenciados: " + std::to_string(numeroFuncionariosGerenciados) +
           "\nDados do Funcionário:\n" + Funcionario::obterDetalhes();
}
