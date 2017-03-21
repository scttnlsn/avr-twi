# avr-twi

Nonblocking TWI/I2C master driver for Atmel AVR

## API

###### `void twi_init(uint32_t f_scl)`

Initializes the driver.  Should be called once before calling any other TWI functions.

* `f_scl` - SCL clock frequency (e.g. 100kHz is typical for Atmega328)

###### `void twi_write(uint8_t address, uint8_t* data, uint8_t length, void (*callback)(uint8_t address, uint8_t *data))`

Writes data to the given address.

* `address` - TWI slave address
* `data` - pointer to data buffer
* `length` - numer of bytes to write from the given data buffer
* `callback` - function pointer to callback (called when write completes)

The callback should accept two arguments:

* `address` - TWI slave address
* `data` - pointer to data buffer that was written

###### `void twi_read(uint8_t address, uint8_t length, void (*callback)(uint8_t address, uint8_t *data))`

Reads data from the given address.

* `address` - TWI slave address
* `length` - number of bytes to read
* `callback` - function pointer to callback (called when read is complete)

The callback should accept two arguments:

* `address` - TWI slave address
* `data` - pointer to data buffer that was written

###### `uint8_t *twi_wait()`

This will block until the current operation (read or write) completes or return immediately if there is no operation in progress.  It returns a pointer to the internal TWI buffer.  This is useful for performing initialization read/writes where asynchrony may be unnecessary.  Call it between read/write calls.

    twi_write(address, &data, 2, NULL);
    twi_wait();
    twi_read(address, 2, NULL);
    uint8_t *result = twi_wait();
