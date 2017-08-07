#ifndef INCLUDE_CB_H
#define INCLUDE_CB_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

enum {
	PUSH_OK,
	CB_FULL, //estourado
	POP_OK,
	CB_EMPTY //sem nada
}typedef RET;

struct {
	uint8_t * buffer;
	uint8_t * buffer_end;
	uint8_t * head;
	uint8_t * tail;
	//uint8_t size;//
	uint8_t max; //tamanho máximo
	uint8_t count;//qtd de elementos
}typedef CB;

//set max size, 
void cbInit(CB *cb, uint8_t max, uint8_t *buffer );

void cvFree(CB *cb);

//add on head
int cbPush(CB *cb, uint8_t* new_element); // return 0

//return from tail
int cbPop(CB *cb, uint8_t* element);

//return converted int pointer
int* cbBufferToInt(CB *cb);

void cbBufferToIntArray(CB *cb, int *array);


#endif /*INCLUDE_CB_H*/
