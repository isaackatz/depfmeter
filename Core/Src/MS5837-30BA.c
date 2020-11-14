#include "main.h"

extern uint32_t D1, D2;
extern uint16_t C[7];

int32_t calculate()
{
	int32_t dT = 0;
	int32_t TEMP = 0;
	int64_t OFF = 0;
	int64_t SENS = 0;
	int32_t P = 0;

	int32_t SENSi = 0;
	int32_t OFFi = 0;
	int32_t Ti = 0;
	int64_t OFF2 = 0;
	int64_t SENS2 = 0;

	int32_t P2 = 0;
	int32_t TEMP2 = 0;

	//first order compensation
	dT = D2 - C[5]*256l;
	TEMP = 2000l + dT*C[6]/8388608LL;
	OFF = C[2]*65536l + (C[4]*dT)/128l;
	SENS = C[1]*32768l + (C[3]*dT)/256l;
	P = ((D1 * SENS)/((2097152l) - OFF))/8192l;

	//second order compensation
	if (TEMP/100 < 20)
	{
		Ti = (3*dT*dT)/8589934592LL;
		OFFi = (3*(TEMP-2000)*(TEMP - 2000))/2;
		SENSi = (5*(TEMP - 2000)*(TEMP-2000))/8;
		if (TEMP/100 < -15)
		{
			OFFi = OFFi + 7*(TEMP + 1500l)*(TEMP + 1500l);
			SENSi = SENSi + 4*(TEMP + 1500l)*(TEMP + 1500l);
		}
	} else
	{
		Ti = (2*dT*dT)/1.37438953E11;
		OFFi = ((TEMP-2000)*(TEMP - 2000))/16;
		SENSi = 0;
	}

	OFF2 = OFF - OFFi;
	SENS2 = SENS - SENSi;

	TEMP2 = (TEMP - Ti) / 100; //C
	P2 = (((D1*SENS2)/(2097152 - OFF2))/8192)/10; //mbar
	int32_t res[2];
	res[0] = P2;
	res[1] = TEMP2;



	return res[1];
}
