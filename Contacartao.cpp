#include "ContaCartao.hpp"
#include <iostream>
#include <string>

// Construtor da classe ContaCartao.
ContaCartao::ContaCartao(const string& nomeCompleto, int idade, const string& genero, const string& tipoConta)
    : Pessoa(nomeCompleto, idade, genero), saldo(0), tipoConta(tipoConta), valorEmprestimo(0) {}

// Retorna o saldo da conta.
int ContaCartao::getSaldo() const {
    return saldo;
}

// Retorna o tipo da conta.
string ContaCartao::getTipoConta() const {
    return tipoConta;
}

// Retorna o valor do empréstimo.
int ContaCartao::getValorEmprestimo() const {
    return valorEmprestimo;
}

// Realiza um depósito na conta.
void ContaCartao::depositar(int valor) {
    saldo += valor;
    std::cout << "Depósito realizado com sucesso." << std::endl;
}

// Realiza um levantamento (saque) se houver saldo suficiente.
void ContaCartao::levantar(int valor) {
    if (saldo >= valor) {
        saldo -= valor;
        std::cout << "Levantamento realizado com sucesso." << std::endl;
    } else {
        std::cout << "Saldo insuficiente, recarregue a conta." << std::endl;
    }
}

// Define o valor do empréstimo realizado.
void ContaCartao::definirValorEmprestimo(int valor) {
    valorEmprestimo = valor;
}

// Retorna os detalhes da conta, combinando dados financeiros e pessoais.
string ContaCartao::obterDetalhes() const {
    return "Informações do Cliente:\nSaldo Atual: " + std::to_string(saldo) +
           "\nTipo de Conta: " + tipoConta +
           "\nValor do Empréstimo: " + std::to_string(valorEmprestimo) +
           "\nDados Pessoais:\n" + Pessoa::obterDetalhes();
}
