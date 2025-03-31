#include "Funcionario.hpp"
#include <iostream>

// Construtor da classe Funcionario
// Inicializa os atributos da classe base Pessoa e os atributos específicos de Funcionario
Funcionario::Funcionario(std::string nome, int idade, std::string sexo, 
                         int salarioFuncionario, std::string numeroFuncionario)
    : Pessoa(nome, idade, sexo), salario(salarioFuncionario), numero(numeroFuncionario) {}

// Getter para o atributo salario
int Funcionario::getSalario() { 
    return salario; 
}

// Setter para o atributo salario
void Funcionario::setSalario(int salarioFuncionario) { 
    salario = salarioFuncionario; 
}

// Getter para o atributo numero
std::string Funcionario::getNumero() { 
    return numero; 
}

// Setter para o atributo numero
void Funcionario::setNumero(std::string numeroFuncionario) { 
    numero = numeroFuncionario; 
}

// Método para consultar o salário atual do funcionário
void Funcionario::consultarSalario() {
    std::cout << "Salario atual: " << salario << std::endl;
}

// Método para obter os detalhes do funcionário
// Inclui informações sobre o salário, número do trabalhador e dados pessoais
std::string Funcionario::getDetalhesFuncionario() {
    return "Salario: " + std::to_string(salario) + "\nNumero do Trabalhador: " 
           + numero + "\nDados Pessoais:\n" + getDetalhes1();
}