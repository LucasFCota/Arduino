#include "DS1302.h"
#include "ThreeWire.h"
#include "RtcDS1302.h"
#include "Arduino.h"

DS1302::DS1302(int dat, int clk, int res){
   _dat = dat;
   _clk = clk;
   _res = res;
}

void DS1302::begin(){
  ThreeWire myWire(4, 5, 2);
  RtcDS1302<ThreeWire> Rtc(myWire);
  Rtc.Begin();
  RtcDateTime now = RtcDateTime(__DATE__, __TIME__);
  DS1302 *pointer = &Rtc;
}

void printDT(){
  RtcDateTime now = *pointer.GetDateTime();
  snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"), //FORMATO DE EXIBIÇÃO DAS INFORMAÇÕES
            now.Day(), //DIA
            now.Month(), //MÊS
            now.Year(), //ANO
            now.Hour(), //HORA
            now.Minute(), //MINUTOS
            now.Second() ); //SEGUNDOS
  Serial.print(datestring); //IMPRIME NO MONITOR SERIAL AS INFORMAÇÕES
}