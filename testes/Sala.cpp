#include "Sala.h"

Sala::Sala()
{
	Leito leito;
	this->leitos.push_back(leito);
}

Sala::Sala(int total_leitos)
{
    for (int i = 0; i < total_leitos; i++)
    {
        Leito leito;
        leito.set_ocupacao(0);
        this->leitos.push_back(leito);
    }
}

void Sala::Create()
{
    Leito leito;
    this->leitos.push_back(leito);
}

void Sala::Create(Leito leito)
{
    this->leitos.push_back(leito);
}

void Sala::Delete()
{
    this->leitos.pop_back();
}

void Sala::Delete(int pos)
{
    this->leitos.erase(this->leitos.begin() + pos);
}

Sala::~Sala() {}


int Sala::get_numero_leitos()
{
    return this->leitos.size();
}

int Sala::get_numero_leitos_ocupados()
{
    int total = 0;
    for (int i = 0; i < this->leitos.size(); i++)
        if (this->leitos[i].get_ocupacao())
            total += 1;
    return total;
}

int Sala::get_numero_leitos_desocupados()
{
    int total = 0;
    for (int i = 0; i < this->leitos.size(); i++)
        if (!this->leitos[i].get_ocupacao())
            total += 1;
    return total;
}
