#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>

using namespace std;

class Paciente {
private:
    string cpf;         // chave
    string nome;
    string endereco;
    string telefone_contato;
    int idade;
    string tipo_s;      // tipo sanguineo
    string classe_triagem;
    string situacao;    // internado / alta
    vector<string> historico; //vetor que armazena o historico de pacientes

public:
    Paciente(string, string, string, string, string, int); //na implementação eu explico o pq de dois construtores
    Paciente(string, string, string, string, string, string, int);
    void set_registro(string, string, string, string, string, int);
    void set_situacao(string situacao);
    void set_modificar();
    void leitura_registro();
    void leitura_situacao();
    void imprimir();
    string get_paciente();
    string get_situacao();
    string get_tipo_s();
    string get_cpf();
};

#endif
