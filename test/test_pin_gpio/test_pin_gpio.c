#include <unity.h>
#include <timer_systick.h>
#include <pin_gpio.h>
#include <stm32f1xx.h>
#include <stdbool.h>

static GPIO_TypeDef miPuerto;
#define MI_PIN 13

void setUp(void)
{
    miPuerto = (GPIO_TypeDef){.CRH=0x44444444,.CRL=0x44444444};

}
void tearDown(void){}

static void pin_debePermitirLeerEstado_0(void)
{
    Pin miPin;
    Pin_init(&miPin,&miPuerto,MI_PIN);
    const bool estado = Pin_lee(&miPin);
    TEST_ASSERT_FALSE(estado);    
}

static void pin_debePermitirLeerEstado_1(void)
{
    Pin miPin;
    Pin_init(&miPin,&miPuerto,MI_PIN);
    miPuerto.IDR = 1<<MI_PIN;
    const bool estado = Pin_lee(&miPin);
    TEST_ASSERT_TRUE(estado);
}


int main(void)
{
    TimerSysTick_init();
    TimerSysTick_esperaMilisegundos(500);
    UNITY_BEGIN();
    RUN_TEST(pin_debePermitirLeerEstado_0);
    RUN_TEST(pin_debePermitirLeerEstado_1);
    UNITY_END();   
}

