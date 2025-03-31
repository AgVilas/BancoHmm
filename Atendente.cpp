#include "Atendente.hpp"

// Construtor da classe Atendente
// Inicializa os atributos herdados de Funcionario e os atributos específicos de Atendente
Atendente::Atendente(std::string nome, int idade, std::string genero, 
                     int salario, std::string numeroUnico, int numeroBalcao, std::string categoriaAtendente)
    : Funcionario(nome, idade, genero, salario, numeroUnico), // Chamada ao construtor da classe base
      numeroDoBalcao(numeroBalcao), categoria(categoriaAtendente) {} // Inicialização dos atributos específicos

// Getter para o número do balcão
int Atendente::getNumeroDoBalcao() { 
    return numeroDoBalcao; 
}

// Setter para o número do balcão
void Atendente::setNumeroDoBalcao(int numeroBalcao) { 
    numeroDoBalcao = numeroBalcao; 
}

// Getter para a categoria do atendente
std::string Atendente::getCategoria() { 
    return categoria; 
}

// Método para abrir uma conta cartão
// Cria e retorna um objeto Contacartao com os dados fornecidos
Contacartao Atendente::abrirContaCartao(std::string nome, int idade, 
                                        std::string genero, std::string tipoContaCartao) {
    return Contacartao(nome, idade, genero, tipoContaCartao);
}

// Método para obter os detalhes do atendente
// Retorna uma string com informações do atendente, incluindo balcão e categoria
std::string Atendente::getDetalhesAtendente() {
    return "Informacoes do Atendente:\nBalcao: " + std::to_string(numeroDoBalcao) 
           + "\nCategoria: " + categoria + "\n" + getDetalhesFuncionario(); // getDetalhesFuncionario() é presumivelmente da classe base
}