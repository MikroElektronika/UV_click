![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# UV Click

---

- **CIC Prefix**  : UV
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

### Software Support

We provide a library for the UV Click on our [LibStock](https://libstock.mikroe.com/projects/view/1090/uv-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control UV Click board.
UV click communicates with the target board via SPI. 
This library contains drivers for enable and disable ML8511 sensor,
write and read data from register address and calculating ultraviolet radiation levels.


Key functions :

- ``` void uv_enableSensor() ``` - Enable ML8511 sensor function
- ``` uint16_t uv_readData() ``` - Generic read 12-bit data function
- ``` float uv_calculateUV() ``` - Calculate ultraviolet radiation levels function

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI, GPIO and LOG structures,
     set AN pin as input, CS and RST pins as output.
- Application Initialization - Initialization driver enable's - SPI,
     set ML8511 IC sensor enable and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of UV Click board.
     UV Click communicates by reading digital voltage output from MCP3201 via SPI.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart when the result is changed.


```.c

void applicationTask()
{
    uvData = uv_calculateUV();

    if ( ( ( uvData - uvDataOld ) > sensitivity ) || ( ( uvDataOld - uvData ) > sensitivity ) )
    {
        mikrobus_logWrite( " UV : ", _LOG_TEXT );
        FloatToStr( uvData, logText );
        mikrobus_logWrite( logText, _LOG_TEXT );
        mikrobus_logWrite( " mV", _LOG_LINE );

        uvDataOld = uvData;
        Delay_1sec();
    }
}

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1090/uv-click-example) page.

Other mikroE Libraries used in the example:

- SPI
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
