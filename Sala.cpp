#include <string>
#include <vector>
#include <iostream>
#include "Sala.h"

Sala::Sala() {}

//Cria uma sala com o total de leitos desejável
Sala::Sala(int total_leitos)
{
    for (int i = 0; i < total_leitos; i++)
    {
        Leito leito;
        leito.set_ocupacao(0);
        this->leitos.push_back(leito);
    }
}

//Adiciona um leito  na sala
void Sala::Create()
{
    Leito leito;
    this->leitos.push_back(leito);
}

//Adiciona um leito na sala passando o leito desejado
void Sala::Create(Leito leito)
{
    this->leitos.push_back(leito);
}

//Deleta um leito da sala
void Sala::Delete()
{
    this->leitos.pop_back();
}

//Deleta um leito informando a posição no vetor
void Sala::Delete(int pos)
{
    this->leitos.erase(this->leitos.begin() + pos);
}

Sala::~Sala() {}

//Retorna o número de leitos
int Sala::get_numero_leitos()
{
    return this->leitos.size();
}

//Retorna o número de leitos ocupados(ocupado = 1)
int Sala::get_numero_leitos_ocupados()
{
    int total = 0;
    for (int i = 0; i < this->leitos.size(); i++)
        if (this->leitos[i].get_ocupacao() == 1)
            total += 1;
    return total;
}

//Retorna o número de leitos desocupados(ocupado = 0)
int Sala::get_numero_leitos_desocupados()
{
    int total = 0;
    for (int i = 0; i < this->leitos.size(); i++)
        if (this->leitos[i].get_ocupacao() == 0)
            total += 1;
    return total;
}
