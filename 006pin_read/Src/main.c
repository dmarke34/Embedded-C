/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#include<stdio.h>
#include<stdint.h>

int main(void)
{

	// added volatile type to variables
	uint32_t volatile *pClkCtrlReg = (uint32_t*)0x40023830;
	uint32_t volatile *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t volatile *pPortDOutReg = (uint32_t*)0x40020C14;

	uint32_t volatile *pPortAModeReg = (uint32_t*)0x40020000;
	uint32_t volatile *pPortAInReg = (uint32_t*)0x40020010;



	//enable the clock for GPOID, GPDIOA peripheral in the AHB1ENR
	*pClkCtrlReg |= (1 << 3);
	*pClkCtrlReg |= (1 << 0);


	//configuring PD12 as output
	*pPortDModeReg &= ~(3 << 24);
	//b. make 24th bit position as 1 (SET)
	*pPortDModeReg |= (1 << 24);

	//configure PA0 as input mode (GPIOA Mode Register)
	*pPortAModeReg &= ~(3 << 0);


	while(1) {
		//read the pin status of the pin PA0 (GPIOA Input Data Register)
			uint8_t pinStatus = (uint8_t)(*pPortAInReg & 0x1);

			if(pinStatus) {
				//turn on the LED
				*pPortDOutReg |= (1 << 12);
			}
			else {
				*pPortDOutReg &= ~(1 << 12);
			}
	}



}
