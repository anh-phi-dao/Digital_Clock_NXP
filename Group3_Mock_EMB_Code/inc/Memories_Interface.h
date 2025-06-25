#ifndef MEMORIES_INTERFACE_H
#define MEMORIES_INTERFACE_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct 
{
    volatile uint8_t FSTAT;
    volatile uint8_t FCNFG;
    volatile uint8_t FSEC;
    volatile uint8_t FOPT;
    volatile uint8_t FCCOB3;
    volatile uint8_t FCCOB2;
    volatile uint8_t FCCOB1;
    volatile uint8_t FCCOB0;
    volatile uint8_t FCCOB7;
    volatile uint8_t FCCOB6; 
    volatile uint8_t FCCOB5;
    volatile uint8_t FCCOB4;
    volatile uint8_t FCCOBB;
    volatile uint8_t FCCOBA;
    volatile uint8_t FCCOB9;
    volatile uint8_t FCCOB8;
    volatile uint8_t FPROT3;
    volatile uint8_t FPROT2;
    volatile uint8_t FPROT1;
    volatile uint8_t FPROT0;
    volatile uint8_t FEPROT;
    volatile uint8_t FDPROT;

    uint8_t Reserve[20];

    volatile uint8_t FCSESTAT;
    volatile uint8_t FERSTAT;
    volatile uint8_t FERCNFG;

}ftfc;



#define FTFC ((ftfc*)0x40020000UL)
#define EEESIZE ((volatile uint8_t*)0x03FEUL)
#define DEPART ((volatile uint8_t*)0x03FCUL)


#ifdef __cplusplus
}
#endif
#endif