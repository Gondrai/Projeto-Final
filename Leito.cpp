#include Leito.h

Leito::Leito() {}

//Armazena o valor 0 = livre/ 1 = ocupado
Leito::Leito(bool valor) {
    this->ocupado = valor;
}

Leito::~Leito() {}

//Define a situação do leito
void Leito::set_ocupacao(bool valor)
{
    //0 = livre / 1 = ocupado
    this->ocupado = valor;
}

//Retorna a situação do leito
bool Leito::get_ocupacao()
{
    return this->ocupado;
}
