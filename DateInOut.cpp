#include "DateInOut.h"

void DateInOut::gen_Date_in(){
    struct tm *data_tempo;
    time_t segundos;
    time(&segundos);
    data_tempo = localtime(&segundos);

    //Estrutura para armazenar a data na variável date
    struct Date *date = new struct Date();
    date->day = data_tempo->tm_mday;
    date->mon = data_tempo->tm_mon + 1;
    date->year = data_tempo->tm_year + 1900;
    date->hour = data_tempo->tm_hour;
    date->min = data_tempo->tm_min;
    date->sec = data_tempo->tm_sec;
    in = date;
    // Salva quando o usuário entrou
}

void DateInOut::gen_Date_out(){
    struct tm *data_tempo;
    time_t segundos;
    time(&segundos);
    data_tempo = localtime(&segundos);

    //Estrutura para armazenar a data na variável date
    struct Date *date = new struct Date();
    date->day = data_tempo->tm_mday;
    date->mon = data_tempo->tm_mon + 1;
    date->year = data_tempo->tm_year + 1900;
    date->hour = data_tempo->tm_hour;
    date->min = data_tempo->tm_min;
    date->sec = data_tempo->tm_sec;
    out = date;
    // Salva quando o usuário saiu
}

struct Date DateInOut::get_Date_in(){
    return *in;
}

struct Date DateInOut::get_Date_out(){
    return *out;
}
