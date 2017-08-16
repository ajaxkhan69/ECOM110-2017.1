#include "interface.h"


static void 	(*_open) 	();
static void 	(*_write) 	(uint8_t);
static uint8_t 	(*_read)	();
static void 	(*_close) 	();


void DriverInit(void (*open) (),void (*write) (uint8_t ),uint8_t (*read),void (*close) () ) {
	_open = open;
	_write = write;
	_read = read;
	_close = close;
    }

void DataInit (ICData * data, uint8_t * value, uint8_t lenght){
	data->value = value;
	data->lenght = lenght;
	}
void CommandSet (ICCommand* cmd, ICCommandType type, uint16_t addr, uint8_t data) 
{
	cmd->address.full = addr;
	cmd->type = type;
//	cmd->data.value = value;
//	cmd->data.lenght = lenght;
	cmd->data = data;
}

void CommandExec(ICCommand *cmd){
	_open();
	_write(cmd->address.bytes.high);
	_write(cmd->address.bytes.low);
	_write(cmd->type);
	if (cmd->type == Write){
		_write(cmd->data); //CONFIG
	}else{
		_read(&cmd->data);
	}
	
}







