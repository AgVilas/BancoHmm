#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

/**
 * @brief Classe para interação com o usuário através de um menu.
 */
class Menu {
public:
    // Construtor que exibe o menu e trata as opções.
    Menu();

    // Método que processa a opção de entrar na conta.
    void entrarNaConta();
};

#endif // MENU_HPP
