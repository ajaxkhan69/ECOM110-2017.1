#include <stdio.h>


#include "interface.h"


int main (){
	ICCommand cmd;
	//ICData data;
	uint8_t value = 0xC;
	uint8_t lenght = 1;
	uint16_t addr = SLOP;
	uint8_t data;
	
	//DataInit(&data, &value, lenght);
	CommandSet(&cmd, Write ,addr, data);

    return 0;
}
