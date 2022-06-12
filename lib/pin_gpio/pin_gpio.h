#ifndef PIN_GPIO_H
#define PIN_GPIO_H
#include <stm32f1xx.h>
#include <stdbool.h>

typedef struct Pin{
    GPIO_TypeDef *puerto;
    int pin;
} Pin;

void Pin_init(Pin *self, GPIO_TypeDef *puerto,int pin);

bool Pin_lee(Pin *self);

#endif
