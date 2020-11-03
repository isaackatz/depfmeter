/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32l4xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32l4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint8_t rx_buffer[3];
uint16_t C[7];
uint32_t D1, D2;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
 * @brief This function handles Non maskable interrupt.
 */
void NMI_Handler(void) {
	/* USER CODE BEGIN NonMaskableInt_IRQn 0 */

	/* USER CODE END NonMaskableInt_IRQn 0 */
	/* USER CODE BEGIN NonMaskableInt_IRQn 1 */

	/* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
 * @brief This function handles Hard fault interrupt.
 */
void HardFault_Handler(void) {
	/* USER CODE BEGIN HardFault_IRQn 0 */

	/* USER CODE END HardFault_IRQn 0 */
	while (1) {
		/* USER CODE BEGIN W1_HardFault_IRQn 0 */
		/* USER CODE END W1_HardFault_IRQn 0 */
	}
}

/**
 * @brief This function handles Memory management fault.
 */
void MemManage_Handler(void) {
	/* USER CODE BEGIN MemoryManagement_IRQn 0 */

	/* USER CODE END MemoryManagement_IRQn 0 */
	while (1) {
		/* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
		/* USER CODE END W1_MemoryManagement_IRQn 0 */
	}
}

/**
 * @brief This function handles Prefetch fault, memory access fault.
 */
void BusFault_Handler(void) {
	/* USER CODE BEGIN BusFault_IRQn 0 */

	/* USER CODE END BusFault_IRQn 0 */
	while (1) {
		/* USER CODE BEGIN W1_BusFault_IRQn 0 */
		/* USER CODE END W1_BusFault_IRQn 0 */
	}
}

/**
 * @brief This function handles Undefined instruction or illegal state.
 */
void UsageFault_Handler(void) {
	/* USER CODE BEGIN UsageFault_IRQn 0 */

	/* USER CODE END UsageFault_IRQn 0 */
	while (1) {
		/* USER CODE BEGIN W1_UsageFault_IRQn 0 */
		/* USER CODE END W1_UsageFault_IRQn 0 */
	}
}

/**
 * @brief This function handles System service call via SWI instruction.
 */
void SVC_Handler(void) {
	/* USER CODE BEGIN SVCall_IRQn 0 */

	/* USER CODE END SVCall_IRQn 0 */
	/* USER CODE BEGIN SVCall_IRQn 1 */

	/* USER CODE END SVCall_IRQn 1 */
}

/**
 * @brief This function handles Debug monitor.
 */
void DebugMon_Handler(void) {
	/* USER CODE BEGIN DebugMonitor_IRQn 0 */

	/* USER CODE END DebugMonitor_IRQn 0 */
	/* USER CODE BEGIN DebugMonitor_IRQn 1 */

	/* USER CODE END DebugMonitor_IRQn 1 */
}

/**
 * @brief This function handles Pendable request for system service.
 */
void PendSV_Handler(void) {
	/* USER CODE BEGIN PendSV_IRQn 0 */

	/* USER CODE END PendSV_IRQn 0 */
	/* USER CODE BEGIN PendSV_IRQn 1 */

	/* USER CODE END PendSV_IRQn 1 */
}

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void) {
	/* USER CODE BEGIN SysTick_IRQn 0 */

	/* USER CODE END SysTick_IRQn 0 */
	HAL_IncTick();
	/* USER CODE BEGIN SysTick_IRQn 1 */

	/* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32L4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32l4xx.s).                    */
/******************************************************************************/

/**
 * @brief This function handles RCC global interrupt.
 */
void RCC_IRQHandler(void) {
	/* USER CODE BEGIN RCC_IRQn 0 */

	/* USER CODE END RCC_IRQn 0 */
	/* USER CODE BEGIN RCC_IRQn 1 */

	/* USER CODE END RCC_IRQn 1 */
}

/**
 * @brief This function handles EXTI line[9:5] interrupts.
 */
void EXTI9_5_IRQHandler(void) {
	/* USER CODE BEGIN EXTI9_5_IRQn 0 */

	/* USER CODE END EXTI9_5_IRQn 0 */
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
	/* USER CODE BEGIN EXTI9_5_IRQn 1 */

	/* USER CODE END EXTI9_5_IRQn 1 */
}

/**
 * @brief This function handles TIM1 update interrupt and TIM16 global interrupt.
 */
void TIM1_UP_TIM16_IRQHandler(void) {
	/* USER CODE BEGIN TIM1_UP_TIM16_IRQn 0 */

	/* USER CODE END TIM1_UP_TIM16_IRQn 0 */
	HAL_TIM_IRQHandler(&htim1);
	/* USER CODE BEGIN TIM1_UP_TIM16_IRQn 1 */

	/* USER CODE END TIM1_UP_TIM16_IRQn 1 */
}

/**
 * @brief This function handles I2C1 event interrupt.
 */
void I2C1_EV_IRQHandler(void) {
	/* USER CODE BEGIN I2C1_EV_IRQn 0 */

	/* USER CODE END I2C1_EV_IRQn 0 */
	HAL_I2C_EV_IRQHandler(&hi2c1);
	/* USER CODE BEGIN I2C1_EV_IRQn 1 */

	/* USER CODE END I2C1_EV_IRQn 1 */
}

/**
 * @brief This function handles I2C1 error interrupt.
 */
void I2C1_ER_IRQHandler(void) {
	/* USER CODE BEGIN I2C1_ER_IRQn 0 */

	/* USER CODE END I2C1_ER_IRQn 0 */
	HAL_I2C_ER_IRQHandler(&hi2c1);
	/* USER CODE BEGIN I2C1_ER_IRQn 1 */

	/* USER CODE END I2C1_ER_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == GPIO_PIN_8) {
		void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {	//if diver holds button for 5 secs calcul starts
			if (htim->Instance == TIM1) {
				//resetting the device first
				HAL_I2C_Master_Transmit_IT(&hi2c1, DEVICE_ADDR, RES_DEVICE, COMMAND_LENGTH);
				//receiving the coefs
				for (uint8_t i = 0; i < 7; i++) {
					uint8_t prom_buff[2];
					HAL_I2C_Master_Transmit_IT(&hi2c1, DEVICE_ADDR, PROM_READ + i * 2, COMMAND_LENGTH);

					HAL_I2C_Master_Receive_IT(&hi2c1, DEVICE_ADDR, prom_buff, PROM_LENGTH);

					C[i] = (prom_buff[0] << 8) | (prom_buff[1]);

				}
				//initializing D1 conversion
				HAL_I2C_Master_Transmit_IT(&hi2c1, DEVICE_ADDR, CONVERT_D1, COMMAND_LENGTH);
				HAL_Delay(10);

				uint8_t adc_buff[3];
				//reading D1 data
				HAL_I2C_Master_Transmit_IT(&hi2c1, DEVICE_ADDR, ADC_READ, COMMAND_LENGTH);
				HAL_I2C_Master_Receive_IT(&hi2c1, DEVICE_ADDR, adc_buff, ADC_LENGTH);

				D1 = (adc_buff[0] << 16) | (adc_buff[1] << 8) | (adc_buff[2]);

				//initializing D2 conversion
				HAL_I2C_Master_Transmit_IT(&hi2c1, DEVICE_ADDR, CONVERT_D2, COMMAND_LENGTH);
				HAL_Delay(10);

				//reading D2 data
				HAL_I2C_Master_Transmit_IT(&hi2c1, DEVICE_ADDR, ADC_READ, COMMAND_LENGTH);
				HAL_I2C_Master_Receive_IT(&hi2c1, DEVICE_ADDR, adc_buff, ADC_LENGTH);

				D2 = (adc_buff[0] << 16) | (adc_buff[1] << 8) | (adc_buff[0]);



			}
		}
	}
}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/