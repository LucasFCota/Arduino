#ifndef DS1302_H
#define DS1302_H
#define countof(a) (sizeof(a) / sizeof(a[0]))

#include "ThreeWire.h"
#include "RtcDS1302.h"
#include "Arduino.h"

class DS1302{
  public:
    DS1302(int dat,int clk, int res);
    void begin();
	  void printDT();
	
  private:
    int _dat;
	  int _clk;
	  int _res;
	  char datestring[20];
	  DS1302 *pointer;
};

#endif
