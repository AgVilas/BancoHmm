#include "Contacartao.hpp"
#include <iostream>

// Construtor da classe Contacartao
// Inicializa os atributos da classe, incluindo os herdados de Pessoa
Contacartao::Contacartao(std::string nome, int idade, 
                        std::string sexo, std::string tC)
    : Pessoa(nome, idade, sexo), saldo(0), tipoConta(tC), emprestimo(0) {}

// Retorna o saldo atual da conta
int Contacartao::getSaldo() { 
    return saldo; 
}

// Retorna o tipo de conta
std::string Contacartao::getTipoConta() { 
    return tipoConta; 
}

// Realiza um depósito na conta
void Contacartao::Depositar(int valor) {
    saldo += valor;
    std::cout << "Depósito feito com sucesso" << std::endl;
}

// Realiza um levantamento (saque) da conta
void Contacartao::levantar(int valor) {
    if (saldo >= valor) {
        saldo -= valor;
        std::cout << "Levantamento feito com sucesso" << std::endl;
    } else {
        std::cout << "Saldo insuficiente" << std::endl;
    }
}

// Define o valor de empréstimo associado à conta
void Contacartao::setFazerEmprestimo(int valor) { 
    emprestimo = valor; 
}

// Retorna os detalhes da conta e do cliente em formato de string
std::string Contacartao::getDetalhes3() {
    return "Informação do cliente:\nSaldo atual: " + std::to_string(saldo) 
           + "\nTipo de conta: " + tipoConta + "\nValor da dívida: " 
           + std::to_string(emprestimo) + "\nDados pessoais:\n" + getDetalhes1();
}