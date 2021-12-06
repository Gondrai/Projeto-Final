#include <string>
#include <vector>
#include <iostream>
#include "ArquivoPacientes.h"

using namespace std;
//Construtor
ArquivoPacientes::ArquivoPacientes()
{
    struct tm *data_tempo;
    time_t segundos;
    time(&segundos);

    data_tempo = localtime(&segundos);

    //inclusao de data e hora ao criar o arquivo
    data_in_out[0] = data_tempo->tm_mday;
    data_in_out[1] = data_tempo->tm_mon + 1;
    data_in_out[2] = data_tempo->tm_year + 1900;
    data_in_out[3] = data_tempo->tm_hour;
    data_in_out[4] = data_tempo->tm_min;
    data_in_out[5] = data_tempo->tm_sec;
}

//Método para criar pacientes
void ArquivoPacientes::Create(Paciente p)
{
    struct tm *data_tempo;
    time_t segundos;
    time(&segundos);
    data_tempo = localtime(&segundos);

    //Estrutura para armazenar a data na variável date
    DateInOut dateIn;
    struct Date date;
    date.day = data_tempo->tm_mday;
    date.mon = data_tempo->tm_mon + 1;
    date.year = data_tempo->tm_year + 1900;
    date.hour = data_tempo->tm_hour;
    date.min = data_tempo->tm_min;
    date.sec = data_tempo->tm_sec;
    date.valid = false;      
    dateIn.in = date;
    dateIn.out = date;           // Como valid é falso, essa não é uma data de saída valida, logo não sera utilizada, pois o paciente acabou de entrar
    
    this->pacientes.push_back(p);      // pushback adiciona um novo
    this->dateInOut.push_back(dateIn); // pushback date in
}

//Método que marca a saída (alta) de um paciente
void ArquivoPacientes::MarcarSaida(string cpf)
{
    struct tm * data_tempo;
    time_t segundos;
    time(&segundos);
    data_tempo = localtime(&segundos);

    struct Date date;
    date.day = data_tempo->tm_mday;
    date.mon = data_tempo->tm_mon + 1;
    date.year = data_tempo->tm_year + 1900;
    date.hour = data_tempo->tm_hour;
    date.min = data_tempo->tm_min;
    date.sec = data_tempo->tm_sec;
    date.valid = true;      // Marca como uma data de saida valida

    // Marca a saída do paciente
    int pos = this->ReadPos(cpf);
    this->dateInOut[pos].out = date;
    this->pacientes[pos].set_situacao("alta");
}

//Retorna um paciente pela posição
Paciente ArquivoPacientes::Read(int i)
{
    return this->pacientes[i];
}

//Método que atualiza um paciente, passando seus dados e a posição
void ArquivoPacientes::Update(Paciente p, int i)
{
    this->pacientes[i] = p;
}

//Remove o último paciente
void ArquivoPacientes::Delete()
{
    this->pacientes.pop_back(); //remove o ultimo elemento do vetor
}

//Remove o paciente pelo CPF
void ArquivoPacientes::DeleteWithCpf(string cpf)
{
    for (int i = 0; i < this->pacientes.size(); i++)
    {
        if (this->pacientes[i].get_cpf() == cpf)
        {
            this->pacientes.erase(this->pacientes.begin() + i);
            this->dateInOut.erase(this->dateInOut.begin() + i);
            break;
        }
    }
}

//Retorna as datas de entrada e saída, caso houver
DateInOut ArquivoPacientes::getDataPaciente(int pos) {
    return this->dateInOut[pos];
}

//Retorna um paciente pelo CPF
Paciente ArquivoPacientes::Read(string cpf)
{
  int pos;
    for (int i = 0; i < this->pacientes.size(); i++)
      if (this->pacientes[i].get_cpf() == cpf)
        pos = i;
  return this->pacientes[pos];
        
}

//Obtém a posição no vetor de um paciente
int ArquivoPacientes::ReadPos(string cpf)
{
    for (int i = 0; i < this->pacientes.size(); i++)
        if (this->pacientes[i].get_cpf() == cpf)
            return i;
    return -1;
}

//Obtém o total de pacientes
int ArquivoPacientes::Total() {
    return this->pacientes.size();
}

//Retorna o total de altas
int ArquivoPacientes::TotalAlta()
{
    int totalAlta = 0;
    for (int i = 0; i < this->pacientes.size(); i++)
        if (this->pacientes[i].get_situacao() == "alta")
            totalAlta++;
    return totalAlta;
}

//Retorna o total de internados
int ArquivoPacientes::TotalInternados()
{
    int totalInternado = 0;
    for (int i = 0; i < this->pacientes.size(); i++)
        if (this->pacientes[i].get_situacao() == "internado")
            totalInternado++;
    return totalInternado;
}
