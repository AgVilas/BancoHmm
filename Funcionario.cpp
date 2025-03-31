#include "Funcionario.hpp"
#include <iostream>
#include <string>

// Construtor da classe Funcionario.
Funcionario::Funcionario(const string& nomeCompleto, int idade, const string& genero, int salario, const string& identificacao)
    : Pessoa(nomeCompleto, idade, genero), salario(salario), identificacao(identificacao) {}

// Retorna o salário do funcionário.
int Funcionario::getSalario() const {
    return salario;
}

// Define o salário do funcionário.
void Funcionario::setSalario(int salario) {
    this->salario = salario;
}

// Retorna o número de identificação do funcionário.
string Funcionario::getIdentificacao() const {
    return identificacao;
}

// Define o número de identificação do funcionário.
void Funcionario::setIdentificacao(const string& identificacao) {
    this->identificacao = identificacao;
}

// Exibe o salário atual do funcionário.
void Funcionario::exibirSalario() const {
    std::cout << "Salário atual: " << salario << std::endl;
}

// Obtém os detalhes do funcionário, incluindo dados pessoais.
string Funcionario::obterDetalhes() const {
    return "Salário: " + std::to_string(salario) +
           "\nIdentificação: " + identificacao +
           "\nDados Pessoais:\n" + Pessoa::obterDetalhes();
}
