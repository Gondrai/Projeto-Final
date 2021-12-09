#include "DateInOut.h"

DateInOut::DateInOut(){
	this->in.day = -1;
	this->in.mon = -1;
	this->in.year = -1;
	this->in.hour = -1;
	this->in.min = -1;
	this->in.sec = -1;
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
