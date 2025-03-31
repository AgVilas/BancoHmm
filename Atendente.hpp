#ifndef ATENDENTE_HPP
#define ATENDENTE_HPP

#include "Funcionario.hpp"
#include "Contacartao.hpp"

// Classe Atendente, derivada da classe Funcionario
class Atendente : public Funcionario {
    int nrbalcao;              // Número do balcão onde o atendente trabalha
    std::string categoria;     // Categoria do atendente

public:
    // Construtor da classe Atendente
    Atendente(std::string nome, int idade, std::string sexo, 
              int s, std::string nu, int nrb, std::string ct);

    // Getter para o número do balcão
    int getNrbalcao();

    // Setter para o número do balcão
    void setNrbalcao(int nrb);

    // Getter para a categoria do atendente
    std::string getCategoria();

    // Método para abrir uma conta-cartão
    Contacartao abrirConta(std::string nome, int idade, 
                           std::string sexo, std::string tipoc);

    // Método para obter detalhes específicos do atendente
    std::string getDetalhes4();
};

#endif