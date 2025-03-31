#include "Gestor.hpp"

// Construtor da classe Gestor
// Inicializa os atributos herdados da classe Funcionario e os atributos específicos de Gestor
Gestor::Gestor(std::string nome, int idade, std::string sexo, 
               int s, std::string nu, std::string sd, std::string c, int nf)
    : Funcionario(nome, idade, sexo, s, nu), // Chamada ao construtor da classe base
      setor(sd), cargo(c), numFunciona(nf) {}

// Getter para o atributo 'setor'
std::string Gestor::getSetor() { 
    return setor; 
}

// Setter para o atributo 'setor'
void Gestor::setSetor(std::string st) { 
    setor = st; 
}

// Getter para o atributo 'cargo'
std::string Gestor::getCargo() { 
    return cargo; 
}

// Getter para o atributo 'numFunciona' (número de funcionários)
int Gestor::getNumfunciona() { 
    return numFunciona; 
}

// Setter para o atributo 'numFunciona'
void Gestor::setNumfunciona(int nuf) { 
    numFunciona = nuf; 
}

// Método para autorizar empréstimos
// Retorna true apenas se o tipo de conta for "Conta Corrente"
bool Gestor::AutorizarEmprest(std::string tipo) {
    return tipo == "Conta Corrente";
}

// Método para obter os detalhes do gestor
// Retorna uma string formatada com as informações do gestor
std::string Gestor::getDetalhes() {
    return "Informacao do Gestor:\nSetor: " + setor + 
           "\nCargo: " + cargo + 
           "\nFuncionarios: " + std::to_string(numFunciona) + 
           "\nDados:\n" + getDetalhes2(); // Chama um método adicional (presumivelmente da classe base)
}