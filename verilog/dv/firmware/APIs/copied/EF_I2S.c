#ifndef EF_I2S_C
#define EF_I2S_C

#include <EF_I2S.h>

void EF_I2S_setGclkEnable (uint32_t i2s_base, int value){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    i2s->GCLK = value;
}

void EF_I2S_enable (uint32_t i2s_base){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    int control = i2s->CTRL;
    control |= EF_I2S_CTRL_REG_EN_MASK;
    i2s->CTRL = control;
}

void EF_I2S_disable (uint32_t i2s_base){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    int control = i2s->CTRL;
    control &= ~EF_I2S_CTRL_REG_EN_MASK;
    i2s->CTRL = control;
}

void EF_I2S_enableFifo(uint32_t i2s_base){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    int control = i2s->CTRL;
    control |= EF_I2S_CTRL_REG_FIFO_EN_MASK;
    i2s->CTRL = control;
}

void EF_I2S_disableFifo(uint32_t i2s_base){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    int control = i2s->CTRL;
    control &= ~EF_I2S_CTRL_REG_FIFO_EN_MASK;
    i2s->CTRL = control;
}

void EF_I2S_enableAVG(uint32_t i2s_base){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    int control = i2s->CTRL;
    control |= EF_I2S_CTRL_REG_AVG_EN_MASK;
    i2s->CTRL = control;
}

void EF_I2S_enableZCR(uint32_t i2s_base){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    int control = i2s->CTRL;
    control |= EF_I2S_CTRL_REG_ZCR_EN_MASK;
    i2s->CTRL = control;
}

void EF_I2S_disableAVG(uint32_t i2s_base){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    int control = i2s->CTRL;
    control &= ~EF_I2S_CTRL_REG_AVG_EN_MASK;
    i2s->CTRL = control;
}

void EF_I2S_disableZCR(uint32_t i2s_base){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    int control = i2s->CTRL;
    control &= ~EF_I2S_CTRL_REG_ZCR_EN_MASK;
    i2s->CTRL = control;
}



void EF_I2S_setConfigReg (uint32_t i2s_base, int config){

    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    
    i2s->CFG = config;

}

int EF_I2S_getConfigReg (uint32_t i2s_base){

    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    
    return (i2s->CFG);

}

void EF_I2S_setPrescaler(uint32_t i2s_base, int prescaler){

    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    i2s->PR = prescaler;
}


int EF_I2S_getPrescaler(uint32_t i2s_base){

    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    return (i2s->PR);
}

void EF_I2S_setAVGT(uint32_t i2s_base, int average){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    i2s->AVGT = average;
}

void EF_I2S_setZCRT(uint32_t i2s_base, int average){
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    i2s->ZCRT = average;
}



int EF_I2S_getRxFifoLevel(uint32_t i2s_base){

    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    return (i2s->RX_FIFO_LEVEL);
}

void EF_I2S_setRxFifoThreshold(uint32_t i2s_base, int threshold){

    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    i2s->RX_FIFO_THRESHOLD = threshold;
}

int EF_I2S_getRxFifoThreshold(uint32_t i2s_base){

    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    return (i2s->RX_FIFO_THRESHOLD) ;
}

// bit 0: RX FIFO is Empty
// bit 1: RX FIFO level is above the value in the RX FIFO Level Threshold Register
// bit 2: RX FIFO is Full


int EF_I2S_getRIS(uint32_t i2s_base){
    
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;
    
    return (i2s->RIS);
}



int EF_I2S_getMIS(uint32_t i2s_base){

    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    return (i2s->MIS);
}

void EF_I2S_setIM(uint32_t i2s_base, int mask){
 
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    i2s->IM = mask;
}

void EF_I2S_setIC(uint32_t i2s_base, int mask){
 
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    i2s->IC = mask;
}



int EF_I2S_getIM(uint32_t i2s_base){
    
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    return (i2s->IM);
}


void EF_I2S_clearIrqRxLevel(uint32_t i2s_base){
    
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    i2s->IC = 0x2;
}

void EF_I2S_clearIrqRxempty(uint32_t i2s_base){
    
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    i2s->IC = 0x1;
}

int EF_I2S_readData(uint32_t i2s_base){
    
    EF_I2S_TYPE* i2s = (EF_I2S_TYPE*)i2s_base;

    while((EF_I2S_getRIS(i2s_base) & 0x2) == 0x0); // wait over RX fifo is above Flag to unset  
    //while (EF_I2S_getRIS(i2s_base) & 0x1);
    int data = i2s->RXDATA;
    EF_I2S_clearIrqRxLevel(i2s_base);
    //EF_I2S_clearIrqRxLevel(i2s_base);
    return data;
}

#endif