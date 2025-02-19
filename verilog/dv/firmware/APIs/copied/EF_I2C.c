#ifndef EF_I2C_C
#define EF_I2C_C

#include <EF_I2C.h>

void EF_I2C_setGclkEnable (uint32_t i2c_base, int value){
    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    i2c->GCLK = value;
}

void EF_I2C_writeToAddress(uint32_t i2c_base, char addr, char data){
    EF_I2C_writeData(i2c_base, data);
    EF_I2C_writeCmd(i2c_base, addr);
    EF_I2C_stopCmd(i2c_base);
    EF_I2C_waitBusy(i2c_base);
}

void EF_I2C_readCommand(uint32_t i2c_base, char addr){
    EF_I2C_readCmd(i2c_base, addr);
    EF_I2C_stopCmd(i2c_base);
    EF_I2C_waitBusy(i2c_base);
}
void EF_I2C_writeAddress(uint32_t i2c_base, char addr){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    // Clear the field bits in the register using the defined mask
    int command =  i2c->COMMAND & ~EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK;

    // Set the bits with the given value at the defined offset
    i2c->COMMAND = command | ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) & EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK);
}

void EF_I2C_startCmd(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    i2c->COMMAND |= ((1 << EF_I2C_COMMAND_REG_CMD_START_BIT) & EF_I2C_COMMAND_REG_CMD_START_MASK);
}

void EF_I2C_readCmd(uint32_t i2c_base, char addr){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT ) | EF_I2C_COMMAND_REG_CMD_READ_MASK);
}

void EF_I2C_writeCmd(uint32_t i2c_base, char addr){
    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) | EF_I2C_COMMAND_REG_CMD_WRITE_MASK);
}

void EF_I2C_writeMultipleCmd(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    i2c->COMMAND |= ((1 << EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_BIT) & EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_MASK);
}

void EF_I2C_stopCmd(uint32_t i2c_base){
    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    i2c->COMMAND = ((1 << EF_I2C_COMMAND_REG_CMD_STOP_BIT) & EF_I2C_COMMAND_REG_CMD_STOP_MASK);
}

void EF_I2C_setCommandReg(uint32_t i2c_base, int value){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    i2c->COMMAND = value;
}

int EF_I2C_getCommandReg(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    return(i2c->COMMAND);
}

void EF_I2C_writeData(uint32_t i2c_base, char data){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    // Clear the field bits in the register using the defined mask
    // i2c->DATA &= ~EF_I2C_DATA_REG_DATA_MASK;

    // Set the bits with the given value at the defined offset
    
    i2c->DATA = ((data << EF_I2C_DATA_REG_DATA_BIT) & EF_I2C_DATA_REG_DATA_MASK);
}

char EF_I2C_readData(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    int data = i2c->DATA;
    bool valid = (data & EF_I2C_DATA_REG_DATA_VALID_MASK) >> EF_I2C_DATA_REG_DATA_VALID_BIT;
    if (valid)
        return (data & EF_I2C_DATA_REG_DATA_MASK) >> EF_I2C_DATA_REG_DATA_BIT;
    else
        return -1;
}

void EF_I2C_setDataValid(uint32_t i2c_base, bool valid){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    if (valid)
        i2c->DATA |= ((1 << EF_I2C_DATA_REG_DATA_VALID_BIT) & EF_I2C_DATA_REG_DATA_VALID_MASK);
    else
        i2c->DATA &= ~EF_I2C_DATA_REG_DATA_VALID_MASK;
}

bool EF_I2C_getDataValid(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    if ((i2c->DATA & EF_I2C_DATA_REG_DATA_VALID_MASK) >> EF_I2C_DATA_REG_DATA_VALID_BIT)
        return true;
    else
        return false;
}

void EF_I2C_setDataLast(uint32_t i2c_base, bool valid){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    if (valid)
        i2c->DATA |= ((1 << EF_I2C_DATA_REG_DATA_LAST_BIT) & EF_I2C_DATA_REG_DATA_LAST_MASK);
    else
        i2c->DATA &= ~EF_I2C_DATA_REG_DATA_LAST_MASK;
}

bool EF_I2C_getDataLast(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    if ((i2c->DATA & EF_I2C_DATA_REG_DATA_LAST_MASK) >> EF_I2C_DATA_REG_DATA_LAST_BIT)
        return true;
    else
        return false;
}

void EF_I2C_setDataReg(uint32_t i2c_base, int value){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    i2c->DATA = value;
}

int EF_I2C_getDataReg(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    return(i2c->DATA);
}

void EF_I2C_setPrescaler(uint32_t i2c_base, int value){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    i2c->PR = value;
}

int EF_I2C_getPrescaler(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;

    return(i2c->PR);
}

int EF_I2C_getRIS(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    return (i2c->RIS);
}

int EF_I2C_getMIS(uint32_t i2c_base){

    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    return (i2c->MIS);
}

void EF_I2C_setIM(uint32_t i2c_base, int mask){
   
    EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    i2c->IM = mask;
}

int EF_I2C_getIM(uint32_t i2c_base){

   EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    return (i2c->IM);
}

void EF_I2C_waitBusy(uint32_t i2c_base){

   EF_I2C_TYPE* i2c = (EF_I2C_TYPE*)i2c_base;
    while(i2c->STATUS & 0b1 == 1);
}

#endif
