#include <time.h>
// Estrutura para salvar data de pacientes
struct Date
{
    int day;
    int mon;
    int year;
    int hour;
    int min;
    int sec;
    bool valid; //false -> acabou de entrar: só printa data de entrada
                //true -> entrou e saiu: printa entrada e saida
};

class DateInOut
{
public:
    struct Date in;  // Data de entrada
    struct Date out; // Data de saída
    DateInOut(){}
    ~DateInOut(){}
    void set_Date_in();
    void set_Date_out();
    struct Date get_Date_in();
    struct Date get_Date_out();
};
