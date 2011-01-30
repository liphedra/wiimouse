/********************************************************************************
Wii Nunchuk Driver
 
Name: drv_nunchuck.h

This is a driver for the Wii Nunchuck.


Author: Dan Riedler
Created: 2-11-10
 
*********************************************************************************/
#include <stdio.h>

/*-------------------------------------------------------------------------------
	Includes
--------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------
	Local function prototypes
--------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------
	Class Defines
--------------------------------------------------------------------------------*/
#define NUNCHUCK_INIT_TIMEOUT    500

/**********************************************************
	I2C Setup Constants
**********************************************************/
#define NUNCHUCK_ADDR			0xA4			// Nunchuck Slave address
// TODO: make these dynamic	with PCLK
#define NUNCHUCK_SCLH			29				// Clock pulse HIGH time
#define NUNCHUCK_SCLL			23				// Clock pulse LOW time

/**********************************************************
	Nunchuk Constants
***********************************************************/
#define	NUNCHUCK_MEM_ADDR	0x40			// Memory address
#define	NUNCHUCK_ZERO		0x00			// Zero valued data

#define DATA_PCKT_LEN	6				// Number of bytes in data packet

#define	Z_BTN_MSK		0x01			// Z button mask
#define	C_BTN_MSK		0x02			// C button mask


/*-------------------------------------------------------------------------------
	Class Constants
--------------------------------------------------------------------------------*/
uint8 REQUEST_PCKT[] = { NUNCHUCK_ADDR, NUNCHUCK_ZERO };



/*-------------------------------------------------------------------------------
	Class data members
--------------------------------------------------------------------------------*/
uint8 nunchuck_buffer[DATA_PCKT_LEN];
static bool nunchuck_rdy = FALSE;

/*-------------------------------------------------------------------------------
	Global Functions
--------------------------------------------------------------------------------*/ 

bool nunchuck_ready()
{
	return nunchuck_rdy;
}
/********************************************************************************
Nunchuck Initialization	

Name: nunchuck_init

Description:

Initializes the Nunchuck.

*********************************************************************************/
bool nunchuck_init( void ){
	bool initialized;
	uint8 buffer[32];
	uint32 i;
	uint8 i2c_msg;


	initialized = FALSE;

	i2c_init( I2C_NUNCHUCK, NUNCHUCK_SCLL, NUNCHUCK_SCLH );
	

	printf("Initializing nunchuck...\n");

	for( i = 0; i < NUNCHUCK_INIT_TIMEOUT; ){
		
		buffer[0] = NUNCHUCK_ADDR;
		buffer[1] = 0xF0;
		buffer[2] = 0x55;
		
		i2c_msg = i2c_send(I2C_NUNCHUCK, 3, buffer);
    	if( i2c_msg )
		{
			printf("\tfailed sending first init code\n");
			goto nunchuck_init_fail;
		}
    	delay_ms(30);

		buffer[0] = NUNCHUCK_ADDR;
		buffer[1] = 0xFB;
		buffer[2] = 0x00;

		i2c_msg = i2c_send(I2C_NUNCHUCK, 3, buffer);
    	if( i2c_msg )
		{
			printf("\tfailed sending second init code\n");
			goto nunchuck_init_fail;
		}
    	delay_ms(30);


		// Identity request
		buffer[0] = NUNCHUCK_ADDR;
		buffer[1] = 0xFA;
		
		i2c_msg = i2c_send(I2C_NUNCHUCK, 2, buffer);
    	if( i2c_msg )
		{
			printf("\tfailed sending identity request command\n");
			goto nunchuck_init_fail;
		}

    	delay_ms(1);

		// Identity read
		buffer[0] = NUNCHUCK_ADDR | I2C_READ;

		i2c_msg = i2c_receive(I2C_NUNCHUCK, 6, buffer);
		if( i2c_msg )
		{
			printf("\tfailed readiing device ID \n");
			goto nunchuck_init_fail;
		}
		printf("\tNunchuck device ID: %X\n",buffer[3]);

		delay_ms(30);


		// Enable encryption
		buffer[0] = NUNCHUCK_ADDR;
		buffer[1] = 0xF0;
		buffer[2] = 0xAA;
	
		i2c_msg = i2c_send(I2C_NUNCHUCK, 3, buffer);
    	if( i2c_msg )
		{
			printf("\tfailed enabling encryption\n");
			goto nunchuck_init_fail;
		}
    	delay_ms(30);

		// send first 6 bytes of encryption code
		buffer[0] = NUNCHUCK_ADDR;
		buffer[1] = 0x40;
		buffer[2] = 0x00;
		buffer[3] = 0x00;
		buffer[4] = 0x00;
		buffer[5] = 0x00;
		buffer[6] = 0x00;
		buffer[7] = 0x00;
	
		i2c_msg = i2c_send(I2C_NUNCHUCK, 8, buffer);	
    	if( i2c_msg )
		{
			printf("\tfailed sending first 6 bytes of encryption code\n");
			goto nunchuck_init_fail;
		}
    	delay_ms(30);

		// send next 6 bytes of encryption code
		buffer[0] = NUNCHUCK_ADDR;
		buffer[1] = 0x46;
		buffer[2] = 0x00;
		buffer[3] = 0x00;
		buffer[4] = 0x00;
		buffer[5] = 0x00;
		buffer[6] = 0x00;
		buffer[7] = 0x00;
		
		i2c_msg = i2c_send(I2C_NUNCHUCK, 8, buffer);
    	if( i2c_msg )
		{
			printf("\tfailed sending next 6 bytes of encryption code\n");
			goto nunchuck_init_fail;
		}
    	delay_ms(30);

		// send last 4 bytes of encryption code
		buffer[0] = NUNCHUCK_ADDR;
		buffer[1] = 0x4C;
		buffer[2] = 0x00;
		buffer[3] = 0x00;
		buffer[4] = 0x00;
		buffer[5] = 0x00;
		
		i2c_msg = i2c_send(I2C_NUNCHUCK, 6, buffer);
    	if( i2c_msg )
		{	
			printf("\tfailed sending last 4 bytes of encryption code\n");
			goto nunchuck_init_fail;
		}
    	delay_ms(30);

		/*
		// Read calibration data
		buffer[0] = NUNCHUCK_ADDR;
		buffer[1] = 0x20;
		
    	if(msg = i2c_send(I2C_NUNCHUCK, 2, buffer))
		{
			printf("\tfailed sending read calibration command\n");
			goto nunchuck_init_fail;
		}

    	delay_us(50);

		// read calibration
		buffer[0] = NUNCHUCK_ADDR | I2C_READ;

		if(msg = i2c_receive(I2C_NUNCHUCK, 7, buffer))
		{
			printf("\tfailed readiing calibration data \n");
			goto nunchuck_init_fail;
		}
		delay_ms(35);


		// Read calibration data
		buffer[0] = NUNCHUCK_ADDR;
		buffer[1] = 0x30;
		
    	if(msg = i2c_send(I2C_NUNCHUCK, 2, buffer))
		{
			printf("\tfailed sending read calibration command\n");
			goto nunchuck_init_fail;
		}

    	delay_us(50);

		// read calibration
		buffer[0] = NUNCHUCK_ADDR | I2C_READ;

		if(msg = i2c_receive(I2C_NUNCHUCK, 7, buffer))
		{
			printf("\tfailed readiing calibration data \n");
			goto nunchuck_init_fail;
		}

		*/

		break;

nunchuck_init_fail:
    	i++;
		if( i < NUNCHUCK_INIT_TIMEOUT )
		{
			printf("i2c error: %X\n", i2c_msg);
			printf("Failed to initialized nunchuck, trying again...\n");
			delay_ms(250);
		}
	}


	if( i == NUNCHUCK_INIT_TIMEOUT )
	{
		printf("\n **** Nunchuck initialization timedout! ********\n");
	} 
	else 
	{
		printf("Nunchuck ready.\n");
		initialized = TRUE;
	}

	return initialized;
}

/********************************************************************************
Read Nunchuck Data	

Name: nunchuck_read

Description:

Reads data from the nunchuck and stores in static buffer.

Data Packet format:

 					Bit
Byte	7	6	5	4	3	2	1	0
0					SX<7:0>
1					SY<7:0>
2					AX<9:2>
3					AY<9:2>
4					AZ<9:2>
5	   AZ<1:0> AY<1:0> AX<1:0> BC  BZ

*********************************************************************************/
bool nunchuck_read( void ){
	int i;
	bool read;
	uint8 i2c_msg;
	uint8 data[] = { NUNCHUCK_ADDR, 0x00 } ;

	read = FALSE;

	//printf("Reading the nunchuck...\n");

	i2c_msg = i2c_send(I2C_NUNCHUCK, 2, data);
	if( i2c_msg )
	{
		printf("\tfailed to send read command\n");
		goto nunchuck_read_fail;
	}

	delay_us(600);

    nunchuck_buffer[0] = NUNCHUCK_ADDR | I2C_READ;
	i2c_msg = i2c_receive(I2C_NUNCHUCK, DATA_PCKT_LEN, nunchuck_buffer);
	if( i2c_msg )
	{
		printf("\tfailed receive nunchuck packet\n");
		goto nunchuck_read_fail;
	}

	// decrypt the data
	for( i = 0; i < DATA_PCKT_LEN; i++ )
	{
		nunchuck_buffer[i] = (nunchuck_buffer[i]^0x17) + 0x17;
	}

	read = TRUE;
	nunchuck_rdy = TRUE;

	return read;

nunchuck_read_fail:
    printf("Failed to read nunchuck\n");

	return read;

}


/********************************************************************************
Get Nunchuck Joystick Position

Name: nunchuck_get_joystick

Description:

Returns the last read joystick position.

NOTE: nunchuck_read() should be called before using this function.

*********************************************************************************/
void nunchuck_get_joystick( uint8 *x_val, uint8 *y_val ){
	*x_val = nunchuck_buffer[0];
	*y_val = nunchuck_buffer[1];
}


/********************************************************************************
Get Nunchuck Accelerometer Data

Name: nunchuck_get_accelerometer

Description:

Returns the last read accelerometer data.

NOTE: nunchuck_read() should be called before using this function.

*********************************************************************************/
void nunchuck_get_accelerometer( uint16 *x_val, uint16 *y_val, uint16 *z_val ){
	*x_val = ((uint16)nunchuck_buffer[2] << 2) | ((uint16)nunchuck_buffer[5] & 0x0C);
	*y_val = ((uint16)nunchuck_buffer[3] << 2) | ((uint16)nunchuck_buffer[5] & 0x30);
	*z_val = ((uint16)nunchuck_buffer[4] << 2) | ((uint16)nunchuck_buffer[5] & 0xC0);
}


/********************************************************************************
Get Nunchuck Button Values

Name: nunchuck_get_buttons

Description:

Returns the last read button values.

NOTE: nunchuck_read() should be called before using this function.

*********************************************************************************/
void nunchuck_get_buttons( uint8 *btn_val ){
	*btn_val = nunchuck_buffer[5] & 0x03;	

}

/********************************************************************************
Z Nunchuck Button Pressed

Name: nunchuck_z_pressed

Description:

Returns TRUE if the last read value of the Z button was pressed, FALSE else.

NOTE: nunchuck_read() should be called before using this function.

*********************************************************************************/
bool nunchuck_z_pressed( void ){
	return (nunchuck_buffer[5] & Z_BTN_MSK) ? FALSE : TRUE;
}


/********************************************************************************
C Nunchuck Button Pressed

Name: nunchuck_c_pressed

Description:

Returns TRUE if the last read value of the C button was pressed, FALSE else.

NOTE: nunchuck_read() should be called before using this function.

*********************************************************************************/
bool nunchuck_c_pressed( void ){
	return (nunchuck_buffer[5] & C_BTN_MSK) ? FALSE : TRUE;
}


/*-------------------------------------------------------------------------------
	Local Functions
--------------------------------------------------------------------------------*/
/********************************************************************************
Write Nunchuck Register	

Name: write_reg

Description:

Write register of nunchuck

address - one byte address of register to write
data - data to write

Returns TRUE if write suceeded, FALSE else

*********************************************************************************/

