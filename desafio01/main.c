#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "cb.h"

#define MAX 80
#define DELAY 100

int main(){
	uint8_t seq[MAX];
	
	CB cb;
	cbInit(&cb, MAX, (uint8_t*)&seq);
	int *ret;
	int ret2[MAX/4];
	
	uint8_t rand_byte;
	while(cbPush(&cb,&rand_byte) != CB_FULL){
		rand_byte = (uint8_t) rand();
		printf("%x\n",rand_byte);
		usleep(1000*DELAY);
	}
	printf("FUDEU!!!\n");
	ret = cbBufferToInt(&cb);
	
	printf("BUFFER-int\n");
	for(int i=0;i < MAX/4 ; i++){
		printf("%d\n",ret[i]);
	}
	cbBufferToIntArray(&cb,&ret2);
	
	printf("BUFFER-int Array\n");
	for(int i=0;i < MAX/4 ; i++){
		printf("%d\n",ret2[i]);
	}

	return 0;
}
