#include "cb.h"


void cbInit(CB *cb, uint8_t max,uint8_t *buffer ){
	
	cb->buffer = buffer;
	cb->buffer_end = cb->buffer + max*sizeof(uint8_t); // max * byte
	cb->head = cb->buffer;
	cb->tail = cb->buffer;
	cb->count = 0;
	cb->max = max;
	
}


void cvFree(CB *cb){

	free(cb->buffer);
}

//add on head
int cbPush(CB *cb, uint8_t* new_element){
	//buffer completo
	if(cb->count == cb->max){
		// 
		return CB_FULL;
	}
	memcpy(cb->head, new_element, sizeof(uint8_t)); // 1 byte
	cb->head = cb->head + sizeof(uint8_t);
	if(cb->head == cb->buffer_end){ //ultima posição do buffer 
		cb->head = cb->buffer;
	}
	cb->count++;
	return PUSH_OK;
}

//return from tail
int cbPop(CB *cb, uint8_t *element){
	//buffer vazio
	if(cb->count == 0){
		// 
		return CB_EMPTY;
	}
	memcpy(element, cb->tail,sizeof(uint8_t));
	cb->tail = cb->tail + sizeof(uint8_t);
	if(cb->tail == cb->buffer_end){
		cb->tail = cb->buffer;
	}
	cb->count--;
	return POP_OK;
}

int* cbBufferToInt(CB *cb){
	int * int_pointer = (int*)cb->buffer;
	return int_pointer;
}
void cbBufferToIntArray(CB *cb, int *array){
	memcpy(array,cb->buffer, sizeof(uint8_t)*cb->max);
}

