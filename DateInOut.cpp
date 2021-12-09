#include "DateInOut.h"

DateInOut::DateInOut(){
	struct Date data;
	data.day = -1;
	data.mon = -1;
	data.year = -1;
	data.hour = -1;
	data.min = -1;
	data.sec = -1;
	this->in = data;
	this->out = data;
}

void DateInOut::gen_Date_in(){
    struct tm *data_tempo;
    time_t segundos;
    time(&segundos);
    data_tempo = localtime(&segundos);

    this->in.day = data_tempo->tm_mday;
    this->in.mon = data_tempo->tm_mon + 1;
    this->in.year = data_tempo->tm_year + 1900;
    this->in.hour = data_tempo->tm_hour;
    this->in.min = data_tempo->tm_min;
    this->in.sec = data_tempo->tm_sec;
}

void DateInOut::gen_Date_out(){
    struct tm *data_tempo;
    time_t segundos;
    time(&segundos);
    data_tempo = localtime(&segundos);
	
    this->out.day = data_tempo->tm_mday;
    this->out.mon = data_tempo->tm_mon + 1;
    this->out.year = data_tempo->tm_year + 1900;
    this->out.hour = data_tempo->tm_hour;
    this->out.min = data_tempo->tm_min;
    this->out.sec = data_tempo->tm_sec;
}

struct Date DateInOut::get_Date_in(){
    return this->in;
}

struct Date DateInOut::get_Date_out(){
    return this->out;
}
