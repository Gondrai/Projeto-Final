#ifndef LEITO_H
#define LEITO_H

class Leito
{
private:
    int ocupado;

public:
    Leito();
    Leito(int valor);
    ~Leito();
    void set_ocupacao(int valor); //Definir como ocupado ou desocupado
    int get_ocupacao();
};

#endif
