#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//#include "cb.h"

#define MAX 80
#define DELAY 100

#define __PACKED __attribute__((__packed__))

typedef uint16_t command_t;

typedef enum{
	A1,
	A2,
	S1,
	S2
} Device;

typedef union{
	uint8_t data[20];
	
	struct {
		unsigned int enA1  : 1;
		unsigned int cmdA1 : 8;
		unsigned int enA2  : 1;
		unsigned int cmdA2 : 1;
		unsigned int enS1  : 1;
		unsigned int cmdS1 : 8;
		unsigned int enS2  : 1;
		unsigned int cmdS2 : 10;
		
	}field __PACKED;
} OpCode;


void addCmd(OpCode *opCode, Device dev, command_t cmd){
	
	switch(dev){
		case A1:
			opCode->field.enA1 = 1;
			opCode->field.cmdA1 = cmd;
			break;
		case A2:
			opCode->field.enA2 = 1;
			opCode->field.cmdA2 = cmd;
			break;
		case S1:
			opCode->field.enS1 = 1;
			opCode->field.cmdS1 = cmd;			
			break;
		case S2:
			opCode->field.enS2 = 1;
			opCode->field.cmdS2 = cmd;
			break;
		
	}
}

void printCmd(OpCode *opCode, Device dev){
	command_t cmd;
	uint8_t en;
	switch(dev){
		case A1:
			en  = opCode->field.enA1;
			cmd = opCode->field.cmdA1;
			break;
		case A2:
			en  = opCode->field.enA2;
			cmd = opCode->field.cmdA2;
			break;
		case S1:
			en  = opCode->field.enS1;
			cmd = opCode->field.cmdS1;
			break;
		case S2:
			en  = opCode->field.enS2;
			cmd = opCode->field.cmdS2;
			break;
	}
	printf("Print CMD: %d\nEN  : %d \nCMD : %x\n",dev,en,cmd);
	
}
void decoder(OpCode *opCode, uint8_t *raw){
	memcpy(opCode, raw, sizeof(opCode));
}


int main(){
	OpCode opCode;
	OpCode opCode2;
//	opCode.field.enA1 = 0;
	printf("Size of = %ld\n",sizeof(opCode.data));
	
	addCmd(&opCode, A1, 0b1000111100);
	addCmd(&opCode, A2, 0b1);
	//addCmd(&opCode, S1, 0b001111000);	
	addCmd(&opCode, S2, 0b1000111100);


	printCmd(&opCode,A1);
	printCmd(&opCode,A2);
	printCmd(&opCode,S1);
	printCmd(&opCode,S2);
	addCmd(&opCode, S1, 0b001111000);
	decoder(&opCode2,&opCode.data);
	printf("OpCode 2 \n");
	printCmd(&opCode2,A1);
	printCmd(&opCode2,A2);
	printCmd(&opCode2,S1);
	printCmd(&opCode2,S2);
	
	return 0;
}
