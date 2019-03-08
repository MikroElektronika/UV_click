/*
Example for UV Click

    Date          : Nov 2018.
    Author        : Nenad Filipovic

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI, GPIO and LOG structures,
     set AN pin as input, CS and RST pins as output.
- Application Initialization - Initialization driver enable's - SPI,
     set ML8511 IC sensor enable and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of UV Click board.
     UV Click communicates by reading digital voltage output from MCP3201 via SPI.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart when the result is changed.

Additional Functions :

- UART
- Conversions

*/

#include "Click_UV_types.h"
#include "Click_UV_config.h"


float uvData;
float uvDataOld = 1.0;
float sensitivity = 20.0;
char logText[50];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_UV_SPI_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    uv_spiDriverInit( (T_UV_P)&_MIKROBUS1_GPIO, (T_UV_P)&_MIKROBUS1_SPI );

    uv_enableSensor();
    Delay_100ms();

    mikrobus_logWrite( "------------------", _LOG_LINE );
    mikrobus_logWrite( "     UV Click     ", _LOG_LINE );
    mikrobus_logWrite( "------------------", _LOG_LINE );
    mikrobus_logWrite( "    Ultraviolet   ", _LOG_LINE );
    mikrobus_logWrite( "------------------", _LOG_LINE );
}

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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}