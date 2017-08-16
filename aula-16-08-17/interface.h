#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdint.h>
//addr register

#define SLOP 0x0120
#define TAP  0x0130
#define DTAP 0x0140
#define X    0x0150
#define Y    0x0160
#define Z    0x0170

//opCode- Addr
typedef enum {
	Write,
	Read

}ICCommandType;

typedef struct{
    uint8_t *value;
    uint8_t lenght;
} ICData;

typedef struct{
    union {
		uint16_t full;
		struct{
		    uint8_t low;
		    uint8_t high;
		} bytes;
	} address;
	ICCommandType type;
//	ICData data;
	uint8_t data
} ICCommand;


void DataInit(ICData *data, uint8_t * value, uint8_t lenght);

void CommandSet (ICCommand* cmd,ICCommandType type, uint16_t addr, uint8_t data);



void DriverInit(void (*open) (),
                void (*write) (uint8_t data ),
                uint8_t (*read),
                void (*close) () );


#endif // INTERFACE_H
