#include <gpio.h>

void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

// зеленый PD13
// красный P14
// желтый PD15

void writeGreenWithDelay(uint32_t delay) {
	HAL_GPIO_WritePin(GPIOD, GREEN, GPIO_PIN_SET);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOD, GREEN, GPIO_PIN_RESET);
}

void writeYellow() {
	HAL_GPIO_WritePin(GPIOD, YELLOW, GPIO_PIN_SET);
	HAL_Delay(YELLOW_DELAY);
	HAL_GPIO_WritePin(GPIOD, YELLOW, GPIO_PIN_RESET);
}

void writeRed() {
	HAL_GPIO_WritePin(GPIOD, RED, GPIO_PIN_SET);
	HAL_Delay(YELLOW_DELAY);
	HAL_GPIO_WritePin(GPIOD, RED, GPIO_PIN_RESET);
}

uint32_t readBtnState() {
	uint32_t last_time = HAL_GetTick();
	uint32_t button_state = 1;
	uint32_t min_delay=20;
	while (HAL_GetTick() < last_time + min_delay) {
		last_time = HAL_GetTick();
		button_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);
		return button_state;
	}
	return button_state;
}
