#ifndef TWI_H
#define TWI_H

#include <stdint.h>

void twi_init();
void twi_write(uint8_t address, uint8_t* data, uint8_t length, void (*callback)(uint8_t, uint8_t *));
void twi_read(uint8_t address, uint8_t length, void (*callback)(uint8_t, uint8_t *));
uint8_t *twi_wait();

#endif
