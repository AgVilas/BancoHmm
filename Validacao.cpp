#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <random>
#include <unordered_set>

// Prototipos dos métodos 
/*
    usei porque estava a mudar sempre metodos
    e acabei colocando metodos abaixo de outros e isso faz com que o programa nao reconheca o codigo
    mas tambem eh mais recomendavel usar sempre prototipos dos metodos
*/
bool isValidName(const std::string& text);
std::string formatName(const std::string& text);
std::string removeExtraSpace(const std::string& text);
std::string trim(const std::string& text);
bool containsOnlyAlphabet(const std::string& text);
bool isNumber(const std::string& num);

// Classe de validação
class Validacao {
public:
    int ValidarInt(std::string msg, int ini, int max);
    double ValidarSalario(std::string msg, double min, double max);
    std::string ValidarID_de_uma_classe(std::string msg);
    std::string ValidarString(std::string msg);
    std::string ValidarNome(std::string msg);

    // Validando ID, esse será usado para o usuário fazer algo do tipo login (não necessariamente login no trabalho)
    // O mais importante é o GerarID() que vai gerar um ID único para cada Funcionário
    int GerarID();
    bool validID(const std::string& text);

private:
    std::unordered_set<int> IDS_GERADOS;
};

// esse metodo vai gerar uma ID unica que nem em base de dados (chave primaria)
int Validacao::GerarID() {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<int> distrib(1000, 9999);

    int newID;
    do {
        newID = distrib(gen);
    } while (IDS_GERADOS.find(newID) != IDS_GERADOS.end());
    IDS_GERADOS.insert(newID);

    return newID;
}

//vou querer validar id que um gerente quando quer dar salarion a um funcionario, o gerente precisa do id do funcionario
bool Validacao::validID(const std::string& text) {
    if (text.empty()) {
        std::cout << "Err, ID can't be empty\n";
        return false;
    }
    
    if (text.length() < 4 || text.length() > 6) {
        std::cout << "Err, ID must be in ]4, 6[ digits\n";
        return false;
    }
    
    for (char txt : text) {
        if (!std::isdigit(txt)) {
            std::cout << "Err, ID must contain only numbers\n";
            return false;
        }
    }
    return true;
}

//esse eh a valodacao mais cao, ainda vou dimiuir, (explicacao dentro do metodo)
std::string Validacao::ValidarNome(std::string msg){
    /*
    Essa eh minha definicao de Validacao de String nome, depois vcs melhoram

    um nome:
    -nao pode conter espacos descenessarios (so vai executar se passar por todos testes asseguir)
    -nao pode aceitar numeros

   -deve parecer um nome real: esse eh o mais dificil, usariamos Machine Learning mas teremos de usar APIS, entao optei por (Regra de Estruturacao)
    Regra de estruturacao: verificar se as palavras tem pelo menos uma vogal e comecam com letra maiuscula
        Comeca com letra maiuscula
        tem pelo menos 2 caracteres
        Possui pelo menos uma vogal
        Evita muitas consoantes seguidas ex: sahjdghskdgjj
        Evita repeticoes estranhas ex: Lino sjdksjd
            se o nome possui uma dessas opcoes entao nao eh um nome real

    - nao pode conter carateres que nao sejam letras do alfabeto

    */

    std::string name;
    do{
        std::cout << msg;
        std::getline(std::cin, name);
        name = removeExtraSpace(name);
        name = formatName(name);
        if(!isValidName(name)){
            std::cout << "invalid name, please try again\n";
        }
    }while(!isValidName(name));

    return name;
}


//aqui noa usei muita logica, eh para diminuir as linhas de codigo
double Validacao::ValidarSalario(std::string msg, double min, double max) {
    double salario;
    std::string str;

    while(true){
        std::cout << "type salario: ";
        std::cin >> str;

        if(!isNumber(str)){
            std::cout << "invalid number\n";
            continue;
        }

        try{
            salario = std::stod(str);
        }catch(...){
            std::cerr << "error converting\n";
            continue;
        }

        if(salario < min || salario > max){
            std::cout << "Err: value should be in [" << min << ", " << max << "]\n";
            continue;
        }else{
            return salario;
        }
    }
}


//esses todos metos servem como logica para metodo validarInt, ValidarString, ValidarNome, validarSalario etc
bool isNumber(const std::string& num) {
    if (!num.empty()) {
        for (char str : num) {
            if (!std::isdigit(str)) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

int Validacao::ValidarInt(std::string msg, int min, int max) {
    std::string str;
    int val;

    while (true) {
        std::cout << msg;
        std::getline(std::cin, str);

        if (!isNumber(str)) {
            std::cout << "Err: invalid integer\n";
            continue;
        }

        try {
            val = std::stoi(str);
        } catch (...) {
            std::cout << "Err: invalid value\n";
            continue;
        }

        if (val < min || val > max) {
            std::cout << "Err: value should be in [" << min << ", " << max << "]\n";
        } else {
            return val;
        }
    }

    return val;
}

std::string Validacao::ValidarString(std::string msg) {
    std::string text;

    while (true) {
        std::cout << msg;

        try {
            std::getline(std::cin, text);
        }
        catch (...) {
            std::cerr << "Error occurred\n";
            continue;
        }

        text = trim(text);
        text = removeExtraSpace(text);

        if (text.empty()) {
            std::cout << "Err, box can't be empty\n";
            continue;
        }

        if (!containsOnlyAlphabet(text)) {
            std::cout << "Only (a-z) (A-Z) are allowed\n";
            continue;
        }
        return text;
    }
}

// Funções auxiliares
std::string trim(const std::string& text) {
    size_t first = text.find_first_not_of(" \t");
    size_t last = text.find_last_not_of(" \t");
    bool firstCondition, secondCondition;
    firstCondition = first == std::string::npos;
    secondCondition = last == std::string::npos;
    std::string substring = text.substr(first, (last - first + 1));
    return (firstCondition || secondCondition) ? "" : substring;
}

std::string removeExtraSpace(const std::string& text) {
    std::stringstream ss(text);
    std::string word, result;
    while (ss >> word) {
        if (!result.empty()) result += " ";
        result += word;
    }
    return result;
}

bool containsOnlyAlphabet(const std::string& text) {
    return std::all_of(text.begin(), text.end(), ::isalpha);
}

bool hasVowel(const std::string& text) {
    return text.find_first_of("aeiouAEIOU") != std::string::npos;
}

bool hasTooManyConsonants(const std::string& text) {
    int consonantCount = 0;
    for (char c : text) {
        if (std::isalpha(c) && std::string("aeiouAEIOU").find(c) == std::string::npos) {
            consonantCount++;
            if (consonantCount >= 4) return true;
        } else {
            consonantCount = 0;
        }
    }
    return false;
}

bool hasExcessiveRepetition(const std::string& text) {
    char lastChar = '\0';
    int repeatCount = 0;
    for (char c : text) {
        if (c == lastChar) {
            repeatCount++;
            if (repeatCount >= 2) return true;
        } else {
            repeatCount = 0;
        }
        lastChar = c;
    }
    return false;
}

bool hasValidWordCount(const std::string& text) {
    std::stringstream ss(text);
    std::string word;
    int wordCount = 0;
    while (ss >> word) {
        wordCount++;
    }
    return wordCount >= 2;
}

std::string formatName(const std::string& text) {
    std::stringstream ss(text);
    std::string word, result;
    while (ss >> word) {
        if (!word.empty()) {
            word[0] = std::toupper(word[0]);
            for (size_t i = 1; i < word.size(); i++) {
                word[i] = std::tolower(word[i]);
            }
        }
        if (!result.empty()) result += " ";
        result += word;
    }
    return result;
}

bool isValidName(const std::string& text) {
    if (!hasValidWordCount(text)) return false;

    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        if (!hasVowel(word) || hasTooManyConsonants(word) || 
            hasExcessiveRepetition(word) || !containsOnlyAlphabet(word)) {
            return false;
        }
    }
    return true;
}

// Função principal
int main() {

    system("clear");

    /*
    
        apenas testando a classe Validacao, depois vamos organizar o codigo e tirar partes descenesarias

    */
    Validacao validar;

    const int min{18};
    const int max{65};

    std::cout<<"primeiro testando validarNome e ValidarINt\n\n";

    std::string name = validar.ValidarNome("Type your name: ");
    int age = validar.ValidarInt("Type your age: ", min, max);
    int id = validar.GerarID();

    std::cout << "ID: " << id << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";

    std::cout << "Agora testando validarSalario\n\n";
    const int minSalarioFuncionario{200};
    const int maxSalarioFuncionario{1000};
    double salario = validar.ValidarSalario("Type the salary", minSalarioFuncionario, maxSalarioFuncionario);

    std::cout << "Salary: " << salario << "\n";
    
    return 0;
}
