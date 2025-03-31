#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Contacartao.hpp"
#include "Gestor.hpp"
#include "Atendente.hpp"
#include "Arquivo.hpp"
#include "Menu.hpp"
#include <iostream>

int main() {
    // Código principal conforme original
    Atendente at("Mandinho", 30, "Masculino", 50000, "258+::", 156, "Economia");
    Contacartao ct = at.abrirConta("Joao", 18, "Masculino", "Poupanca");
    Gestor ge("Saldina", 35, "Feminino", 70000, "258++::", "RH", "Gerente", 10);

    // Restante do código...
    return 0;
}