#include "ArquivoPacientes.h"

using namespace std;
//Construtor
ArquivoPacientes::ArquivoPacientes()
{
}

//MÃ©todo para criar pacientes
void ArquivoPacientes::Create(Paciente p)
{   
    DateInOut dateIn;
    dateIn.gen_Date_in();
    this->pacientes.push_back(p);      // pushback adiciona um novo
    this->dateInOut.push_back(dateIn); // pushback date
    
}

//Método que marca a saída (alta) de um paciente
void ArquivoPacientes::MarcarSaida(string cpf)
{
    // Marca a saída do paciente
    int pos = this->ReadPos(cpf);
    this->dateInOut[pos].gen_Date_out();
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
    this->pacientes.pop_back(); //remove o ultimo paciente do vetor
    this->dateInOut.pop_back();
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
DateInOut ArquivoPacientes::getDataPaciente(int pos){
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
