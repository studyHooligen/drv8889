#ifndef drv8889_H
//powered by studyhooligen@HUST_STI_K10
#define drv8889_H

//!!!
//when use other hardware structure ,you must refit these pins!!!
#define nSLEEP_Pin GPIO_PIN_11
#define nSLEEP_GPIO_Port GPIOE

#define DRV_OFF_Pin GPIO_PIN_12
#define DRV_OFF_GPIO_Port GPIOE

#define DIR_Pin GPIO_PIN_13
#define DIR_GPIO_Port GPIOE

#define STEP_Pin GPIO_PIN_14
#define STEP_GPIO_Port GPIOE
//when use other hardware structure ,you must refit above pins!!!!

typedef struct writeDataStructure{
	__UINT8_TYPE__ address;
	__UINT8_TYPE__ data;
}SPIsendData;

typedef struct getDataStructure{
	__UINT8_TYPE__ status;
	__UINT8_TYPE__ report;
}SPIgetData;

#define FAULT_STATUS	0X00
#define DIAG_STATUS_1 0X01
#define DIAG_STATUS_2 0X02
#define CTRL1					0X03
#define CTRL2					0X04
#define CTRL3					0X05
#define CTRL4					0x06
#define CTRL5					0x07
#define CTRL6					0x08
#define CTRL7					0x09

/* status register from MSE to LSE
--FAULT_STATUS
	--FAULT(r-0b)			this bit = ~nFault Pin
	--SPI_ERROR(r-0b)	if SPI clock happen error ,this bit become high
	--UVLO(r-0b)			Indicates an undervoltage lockout fault condition. Latched high after power-up, remains set until it is cleared through the CLR_FLT bit or an nSLEEP reset pulse.
	--CPUV(r-0b)			Indicates charge pump undervoltage fault condition. Latched high after power-up, remains set until it is cleared through the CLR_FLT bit or an nSLEEP reset pulse. 
	--OCP(r-0b)				Indicates overcurrent fault condition
	--STL(r-0b)				Indicates motor stall condition
	--TF(r-0b)				Logic OR of the overtemperature warning, undertemperature warning and overtemperature shutdown.
	--OL(r-0b)				Indicates open-load condition
	
--DIAG_STATUS_1(r)
	--OCP_LS2_B				Indicates overcurrent fault on the low-side FET of half bridge 2 in BOUT 
	--OCP_HS2_B				Indicates overcurrent fault on the high-side FET of half bridge 2 in BOUT 
	--OCP_LS1_B				Indicates overcurrent fault on the low-side FET of half bridge 1 in BOUT 
	--OCP_HS1_B 			Indicates overcurrent fault on the high-side FET of half bridge 1 in BOUT 
	--OCP_LS2_A 			Indicates overcurrent fault on the low-side FET of half bridge 2 in AOUT 
	--OCP_HS2_A 			Indicates overcurrent fault on the high-side FET of half bridge 2 in AOUT 
	--OCP_LS1_A 			Indicates overcurrent fault on the low-side FET of half bridge 1 in AOUT 
	--OCP_HS1_A 			Indicates overcurrent fault on the high-side FET of half bridge 1 in AOUT

--DIAG_STATUS_2(r)
	--UTW					Indicates undertemperature warning
	--OTW					overtemperature warning
	--OTS					overtemperature shutdown
	--STL_LRN_OK	stall detection learning is successful 
	--STALL				motor stall condition 
	--RSVD				Reserved. (none)
	--OL_B 				open-load detection on BOUT 
	--OL_A 				open-load detection on AOUT

*/

/*  control register
--CTRL1(R/W)
	--TRQ_DAC[7:4]			default:0000b(100%)
	--RSVD[3:2]
	--SLEW_RATE[1:0]		default:00b(10V/us)
	
--CTRL2(R/W)
	--DIS_OUT[7]			default:0b(normal output)
	--RSVD[6:5]
	--TOFF[1:0]				default:01b(16us)
	--DECAY[2:0]			default:111b(smart tune ripple control)
	
--CTRL3(R/W)
	--DIR[7]							default:0b	attention:Direction input. Logic '1' sets the direction of stepping, when SPI_DIR = 1. 
	--STEP[6]							default:0b	attention:Step input. Logic '1' causes the indexer to advance one step, when SPI_STEP = 1. 
	--SPI_DIR[5]					default:0b(outputs follow input pin DIR)
	--SPI_STEP[4]					default:0b(outputs follow input pin STEP)
	--MICROSTEP_MODE[3:0]	default:0000b(full step with 100% current)

--CTRL4(R/W)
	--CLR_FLT[7]     default:0b  attention:write1 to clear all latched fault bits!
	--LOCK[6:4]      default:011b(unlock all register)
	--EN_OL[3]       default:0b  attention:write 1 to enable open load detection
	--OCP_MODE[2]    default:0b(Overcurrent condition causes a latched fault )
	--OTSD_MODE[1]   default:0b(Overtemperature condition will cause latched fault )
	--TW_REP[0]      default:0b(Overtemperature or undertemperature warning is not reported on the nFAULT line )

--CTRL5(R/W)
	--RSVD[7:6]
	--STL_LRN[5]      	default:0b  attention:Write '1' to learn stall count for stall detection. This bit automatically returns to '0' when the stall learning process is complete
	--DIS_STL[4]				default:0b(stall detecion is enabled)
	--STL_REP[3]        default:1b(stall detecion is reported on nFAULT)
	--RSVD[2:0]
	
--CTRL6[R/W]
	--STALL_TH[7:0]  default:00001111b
	
--CTRL7(R/W)
--TRQ_COUNT[7:0]   default:11111111b
*/




//before using following function ,you must have initiallization all used gpio!
void Sleep_Device8889()  {
	
}

void LockMotor_Device8889()  {

}

void reset_Device8889()  {  //if use OS ,had better redefine delay of this function to improve  efficiency
	
}

void changeCurrentDiv_Device8889(__UINT32_TYPE__ divLevel)  {

}

void changeRatio_Device8889(__UINT32_TYPE__ ratio)  {
}

#endif