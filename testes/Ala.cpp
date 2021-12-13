#include <iostream>
#include "Ala.h"

using namespace std;

Ala::Ala(){
	Sala sala;
	salas.push_back(sala);
}

Ala::Ala(int total_salas)
{
    for (int i = 0; i < total_salas; i++)
    {
        Sala sala;
        this->salas.push_back(sala);
    }
}

Ala::~Ala() {}

void Ala::Create()
{
    Sala sala;
    this->salas.push_back(sala);
}

void Ala::Create(Sala sala)
{
    this->salas.push_back(sala);
}

Sala Ala::Read(int pos)
{
    return this->salas[pos];
}

void Ala::Update(Sala sala, int pos)
{
    this->salas[pos] = sala;
}

void Ala::Delete()
{
    this->salas.pop_back();
}

void Ala::Delete(int pos)
{
    this->salas.erase(this->salas.begin() + 1);
}

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

int Ala::TotalLeitos()
{
    int total = 0;
    for (int i = 0; i < this->salas.size(); i++)
        total += this->salas[i].get_numero_leitos();
    return total;
}

int Ala::TotalSalas()
{
    return this->salas.size();
}

