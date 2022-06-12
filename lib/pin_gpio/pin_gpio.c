#include <pin_gpio.h>

void Pin_init(Pin *self, GPIO_TypeDef *puerto,int pin)
{
    self->puerto = puerto;
    self->pin = pin;
}

bool Pin_lee(Pin *self)
{
    return (bool)(self->puerto->IDR & (1 << (self->pin)));
}
