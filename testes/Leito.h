#ifndef LEITO_H
#define LEITO_H

class Leito{
private:
    int ocupado;

public:
    Leito();
    Leito(int valor); //Cria um leito com o valor desejado (ocupado ou desocupado)
    ~Leito();
    void set_ocupacao(int valor); //Definir como ocupado ou desocupado
    int get_ocupacao(); //Retorna o valor armazenado no atributo "ocupado"
};

#endif
