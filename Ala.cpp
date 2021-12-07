#include <string>
#include <vector>
#include <iostream>
#include "Ala.h"
Ala::Ala() {}

//Cria uma ala passando o total desejado de salas
Ala::Ala(int total_salas)
{
    for (int i = 0; i < total_salas; i++)
    {
        Sala sala;
        this->salas.push_back(sala);
    }
}

Ala::~Ala() {}

//Cria uma sala nova na ala
void Ala::Create()
{
    Sala sala;
    this->salas.push_back(sala);
}

//Insere uma sala na ala
void Ala::Create(Sala sala)
{
    this->salas.push_back(sala);
}

//Retorna uma sala pela posição no vetor
Sala Ala::Read(int pos)
{
    return this->salas[pos];
}

//Atualiza uma sala com sua posição no vetor
void Ala::Update(Sala sala, int pos)
{
    this->salas[pos] = sala;
}

//Deleta a última sala
void Ala::Delete()
{
    this->salas.pop_back();
}

//Deleta uma sala informando a posição no vetor
void Ala::Delete(int pos)
{
    this->salas.erase(this->salas.begin() + 1);
}

//Retorna a taxa de ocupação de leitos na ala
float Ala::TaxaOcupacaoLeito()
{
    int total = 0;
    int ocupacao = 0;
    for (int i = 0; i < this->salas.size(); i++)
    {
        ocupacao += this->salas[i].get_numero_leitos_ocupados();
        total += this->salas[i].get_numero_leitos();
    }
    return ((float)ocupacao / total) * 100;
}

//Retorna a taxa de desocupação de leitos na ala
float Ala::TaxaDesocupacaoLeito()
{
    int total = 0;
    int desocupacao = 0;
    for (int i = 0; i < this->salas.size(); i++)
    {
        desocupacao += this->salas[i].get_numero_leitos_desocupados();
        total += this->salas[i].get_numero_leitos();
    }
    return ((float)desocupacao / total) * 100;
}

//Retorna o total de leitos da ala
int Ala::TotalLeitos()
{
    int total = 0;
    for (int i = 0; i < this->salas.size(); i++)
        total += this->salas[i].get_numero_leitos();
    return total;
}

//Retorna o total de salas na ala
int Ala::TotalSalas()
{
    return this->salas.size();
}
