#ifndef LEITO_H
#define LEITO_H

using std::bool;

class Leito
{
private:
    bool ocupado;

public:
    Leito();
    Leito(bool valor);
    ~Leito();
    void set_ocupacao(bool valor); //Definir como ocupado ou desocupado
    bool get_ocupacao();
};

#endif
