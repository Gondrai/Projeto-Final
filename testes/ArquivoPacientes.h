#ifndef ARQUIVOPACIENTES_H
#define ARQUIVOPACIENTES_H

#include <string>
#include <vector>
#include "Paciente.h"
#include "DateInOut.h"
#include "Ala.h"

using namespace std;

class ArquivoPacientes
{
private:
    vector<Paciente> pacientes; //vetor para armazenar os pacientes
    vector<DateInOut> dateInOut; //vetor para armazenar as datas de saida e entrada de cada um
    
public:
    ArquivoPacientes();
    void Create(Paciente P);          // Cria um paciente
    void Update(Paciente p, int pos); // Atualiza um paciente
    void Delete();                    // Deleta o Ãºltimo paciente inserido
    void DeleteWithCpf(string cpf);   // Deleta um paciente em especifico
    void MarcarSaida(string cpf);     // Marca quando um paciente saiu
    Paciente Read(int i);             // Obtem um paciente por posiÃ§Ã£o
    Paciente Read(string cpf);        // Obtem um paciente pelo cpf
    int ReadPos(string cpf);          // Obtem a posiÃ§Ã£o no vetor para um paciente
    int Total();                      // Retorna total de pacientes
    int TotalAlta();                  // Obtem total de altas
    int TotalInternados();            // Total de internados
    DateInOut getDataPaciente(int pos); // Retorna as datas de um paciente
};

#endif
