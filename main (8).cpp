#include <iostream>
#include <string>

using namespace std;

/*
    Singleton é um padrão de projeto de software (do inglês Design Pattern). Este padrão
    garante a existência de apenas uma instância de uma classe, mantendo um ponto global
    de acesso ao seu objeto.
*/

class Logger {
private:
    static Logger* instance; // Membro estático para armazenar a única instância da classe
    Logger() {} // Construtor privado para evitar instanciação direta fora da classe

public:
    static Logger* getInstance() { // função-membro que retorna sempre a mesma instância do objeto
        if (!instance) { // Verifica se a instância ainda não foi criada
            instance = new Logger(); // Se não foi criada, cria uma nova instância
        }
        return instance; // Retorna a instância única
    }

    void doLog(const std::string& message) {
        cout << "Log: " << message << endl; // Imprime a mensagem de log na saída padrão
    }

    ~Logger(){
        instance = nullptr;
    }
};

// Inicialização estática da variável instance
Logger* Logger::instance = nullptr;

int main() {
    Logger* logger = Logger::getInstance(); // Obtém a instância única do Logger
    logger->doLog("Logging message 1"); // Usa o método doLog para fazer o log de uma mensagem

    Logger* logger2 = Logger::getInstance(); // Obtém a mesma instância do Logger novamente
    logger2->doLog("Logging message 2"); // Faz outro log de mensagem

    return 0;
}
