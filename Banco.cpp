#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Superclass: Pessoa
class Pessoa {
protected:
    string name; // Nome da pessoa
    int idade;   // Idade da pessoa
    string sexo; // Sexo da pessoa

public:
    // Construtor da classe Pessoa
    Pessoa(string n, int id, string s) : name(n), idade(id), sexo(s) {}

    // Métodos getters e setters para os atributos
    string getName() { return name; }
    void setName(string n) { name = n; }

    int getIdade() { return idade; }
    void setIdade(int id) { idade = id; }

    string getSexo() { return sexo; }
    void setSexo(string s) { sexo = s; }

    // Método para obter os detalhes da pessoa
    string getDetalhes1() {
        return "Nome: " + name + "\nIdade: " + to_string(idade) + "\nSexo: " + sexo;
    }
};

// Subclass: Funcionario
class Funcionario : public Pessoa {
protected:
    int salario;   // Salário do funcionário
    string numero; // Número do funcionário

public:
    // Construtor da classe Funcionario
    Funcionario(string name, int idade, string sexo, int s, string nu)
        : Pessoa(name, idade, sexo), salario(s), numero(nu) {}

    // Métodos getters e setters para os atributos
    int getSalario() { return salario; }
    void setSalario(int s) { salario = s; }

    string getNumero() { return numero; }
    void setNumero(string nu) { numero = nu; }

    // Método para consultar o salário
    void consultarS() { cout << "Salario atual: " << getSalario() << endl; }

    // Método para obter os detalhes do funcionário
    string getDetalhes2() {
        return "Salario: " + to_string(salario) + "\nNumero Trabalhador: " + numero +
               "\nDados pessoais:\n" + getDetalhes1();
    }
};

// Subclass: Contacartao
class Contacartao : public Pessoa {
protected:
    int saldo;        // Saldo da conta
    string tipoConta; // Tipo da conta
    int emprestimo;   // Valor do empréstimo

public:
    // Construtor da classe Contacartao
    Contacartao(string name, int idade, string sexo, string tC)
        : Pessoa(name, idade, sexo), saldo(0), tipoConta(tC), emprestimo(0) {}

    // Métodos getters e setters para os atributos
    int getSaldo() { return saldo; }
    string getTipoConta() { return tipoConta; }

    // Método para depositar dinheiro na conta
    void Depositar(int d) {
        saldo += d;
        cout << "Deposito feito com sucesso" << endl;
    }

    // Método para levantar dinheiro da conta
    void levantar(int l) {
        if (saldo > l) {
            saldo -= l;
            cout << "Levantamento feito com sucesso" << endl;
        } else {
            cout << "Saldo insuficiente, recarregue a conta primeiro" << endl;
        }
    }

    // Método para definir o valor do empréstimo
    void setFazerEmprestimo(int E) { emprestimo = E; }

    // Método para obter os detalhes da conta
    string getDetalhes3() {
        return "Informacao do cliente:\nSaldo atual: " + to_string(saldo) +
               "\nTipo de conta: " + tipoConta +
               "\nValor da divida: " + to_string(emprestimo) +
               "\nDados pessoais:\n" + getDetalhes1();
    }
};

// Subclass: Gestor
class Gestor : public Funcionario {
private:
    string setor;      // Setor do gestor
    string cargo;      // Cargo do gestor
    int numFunciona;   // Número de funcionários sob gestão

public:
    // Construtor da classe Gestor
    Gestor(string name, int idade, string sexo, int s, string nu, string sd, string c, int nf)
        : Funcionario(name, idade, sexo, s, nu), setor(sd), cargo(c), numFunciona(nf) {}

    // Métodos getters e setters para os atributos
    string getSetor() { return setor; }
    void setSetor(string st) { setor = st; }

    string getCargo() { return cargo; }

    int getNumfunciona() { return numFunciona; }
    void setNumfunciona(int nuf) { numFunciona = nuf; }

    // Método para autorizar empréstimos
    bool AutorizarEmprest(string tipo) { return tipo == "Conta Corente"; }

    // Método para obter os detalhes do gestor
    string getDetalhes() {
        return "Informacao do Gestor:\nSetor do gestor: " + setor +
               "\nCargo do gestor: " + cargo +
               "\nQuantidade de funcionarios: " + to_string(numFunciona) +
               "\nDados do gestor:\n" + getDetalhes2();
    }
};

// Subclass: Atendente
class Atendente : public Funcionario {
private:
    int nrbalcao;      // Número do balcão
    string categoria;  // Categoria do atendente

public:
    // Construtor da classe Atendente
    Atendente(string name, int idade, string sexo, int s, string nu, int nrb, string ct)
        : Funcionario(name, idade, sexo, s, nu), nrbalcao(nrb), categoria(ct) {}

    // Métodos getters e setters para os atributos
    int getNrbalcao() { return nrbalcao; }
    void setNrbalcao(int nrb) { nrbalcao = nrb; }

    string getCategoria() { return categoria; }

    // Método para abrir uma nova conta
    Contacartao abrirConta(string name, int idade, string sexo, string tipoc) {
        return Contacartao(name, idade, sexo, tipoc);
    }

    // Método para obter os detalhes do atendente
    string getDetalhes4() {
        return "Informacao do Atendente:\nNumero de balcao: " + to_string(nrbalcao) +
               "\nCategoria: " + categoria + "\n" + getDetalhes2();
    }
};

// Class: Arquivo
class Arquivo {
protected:
    fstream arquivo; // Objeto para manipulação de arquivos

public:
    Arquivo() {}

    // Método para salvar informações em um arquivo
    void arquivar(string t, string b) {
        arquivo.open(b, ios::out);
        arquivo << t << "\n";
        arquivo.close();
        cout << "Arquivo criado com sucesso" << endl;
    }

    // Método para exibir o conteúdo de um arquivo
    void mostrararq(string b) {
        string linha;
        arquivo.open(b, ios::in);
        cout << "Informacao do arquivo:\n";
        if (arquivo.is_open()) {
            while (getline(arquivo, linha)) {
                cout << linha << endl;
            }
            arquivo.close();
        } else {
            cout << "Nao foi possivel abrir o arquivo" << endl;
        }
    }
};

// Main function
int main() {
    string b, c, e; // Variáveis para armazenar informações
    int op, d, l, Em; // Variáveis para opções e valores monetários
    bool a; // Variável para verificar autorização de empréstimo

    // Criação de objetos
    Atendente at = Atendente("Mandinho", 30, "Masculino", 50000, "258+::", 156, "Area da economica");
    Contacartao ct = at.abrirConta("Joao", 18, "Masculino", "Conta ponpanca");
    Gestor ge = Gestor("Saldina", 35, "Feminino", 70000, "258++::", "Atendimento", "Gestor da economia", 10);

    // Menu de opções
    cout << "Selecione uma opcao:\n1 - Saldo\n2 - Depositar dinheiro\n3 - Levantar dinheiro\n4 - Fazer emprestimo\n";
    cin >> op;
    cout << endl;

    // Processamento das opções
    switch (op) {
        case 1:
            cout << "Saldo: " << ct.getSaldo() << endl;
            break;
        case 2:
            cout << "Quanto deseja depositar? ";
            cin >> d;
            cout << endl;
            ct.Depositar(d);
            break;
        case 3:
            cout << "Quanto deseja levantar? ";
            cin >> l;
            cout << endl;
            ct.levantar(l);
            break;
        case 4:
            a = ge.AutorizarEmprest(ct.getTipoConta());
            if (a) {
                cout << "Digite o valor de emprestimo: ";
                cin >> Em;
                ct.setFazerEmprestimo(Em);
            } else {
                cout << "Nao e possivel fazer o emprestimo" << endl;
            }
            break;
        default:
            cout << "Opcao invalida" << endl;
    }

    // Salvar informações em arquivos
    b = ct.getDetalhes3();
    c = at.getDetalhes4();
    e = ge.getDetalhes();

    Arquivo aq;
    aq.arquivar(b, "infclient.txt");
    aq.arquivar(c, "infatendent.txt");
    aq.arquivar(e, "infgesto.txt");

    // Exibir informações dos arquivos
    aq.mostrararq("infclient.txt");
    aq.mostrararq("infatendent.txt");
    aq.mostrararq("infgesto.txt");

    return 0;
}
