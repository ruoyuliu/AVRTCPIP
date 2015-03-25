/*
 * IP_send_comm.c
 *
 * Created: 2015-03-23 11:29:58 AM
 * Author: Ryan Walmsley
 */ 

#include <avr/io.h>
#include "ETH_send.h"
#include "IP_Send.h"

typedef enum  {Idle, Attach, Write, S2, S3, S4, S5, S6, Write_Dest_IP, S8, Eth_Send_State, S10, IP_Release} IP_send_comm_states;
	
typedef struct
{
	IP_send_comm_states state;
}IP_send_comm_struct;

volatile IP_send_comm_struct IP_send_comm_data; // global variable for the IP send communication data 
uint8_t ETH_Send_Release(void);

uint8_t IP_send_comm(void)
{
	uint8_t ret_val=0;
	switch (IP_send_comm_data.state)
	{
		case Idle:

		break;
		case Attach:

		break;
		case Write:

		break;
		case S2:

		break;
		case S3:

		break;
		case S4:

		break;
		case S5:

		break;
		case S6:

		break;
		case Write_Dest_IP:

		break;
		case S8:

		break;
		case Eth_Send_State:

		break;
		case S10:

		break;
		case IP_Release:

		break;
		default: // state is corrupt.

		break;
	}
	return ret_val;	
}

uint8_t IP_send_attach(void)
{
	uint8_t ret_val=0;
	if (ETH_send_attach()){
	if (IP_send_comm_data.state==Idle) {
		IP_send_comm_data.state=Attached;
		ret_val=1;
		// initialize SPI timer here.  For now it is not implemented.
		// timer_set_delay(0,10);
	}
	}
	return ret_val;
}

uint8_t IP_Send_Start (void)
{
	uint8_t ret_val=0;
	if (spi_data.len==0 && IP_data.state==S0A)
	{
		IP_data.state=S1;
		ret_val=1;
	}
	return ret_val;
}

uint8_t IP_Send_Release (void)
{
	uint8_t ret_val=0;
	
	if (ETH_Send_Release(void))
	{
		if (spi_data.len==0 && IP_data.state==Complete)
		{
			IP_data.state=Idle;
			ret_val=1;
		}
	}

	return ret_val;

}
