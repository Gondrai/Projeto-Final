#include Leito.h

Leito::Leito() {}

//Armazena o valor 0 = livre/ 1 = ocupado
Leito::Leito(int valor) {
    this->ocupado = valor;
}

Leito::~Leito() {}

//Define a situação do leito
void Leito::set_ocupacao(int valor)
{
    //0 = livre / 1 = ocupado
    this->ocupado = valor;
}

//Retorna a situação do leito
int Leito::get_ocupacao()
{
    return this->ocupado;
}
