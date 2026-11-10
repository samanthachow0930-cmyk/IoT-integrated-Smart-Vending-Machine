#include "keypad.h"
#include "main.h"

const char keymap[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

char get_keypad_key(void)
{
    struct
    {
        GPIO_TypeDef *port;
        uint16_t pin;
    } rows[4] = {{R1_PORT, R1_PIN}, {R2_PORT, R2_PIN}, {R3_PORT, R3_PIN}, {R4_PORT, R4_PIN}};

    struct
    {
        GPIO_TypeDef *port;
        uint16_t pin;
    } cols[4] = {{C1_PORT, C1_PIN}, {C2_PORT, C2_PIN}, {C3_PORT, C3_PIN}, {C4_PORT, C4_PIN}};

    for (int row = 0; row < 4; row++)
    {
        /* Set all rows high */
        HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_SET);
        HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_SET);
        HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_SET);
        HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_SET);

        /* Set current row LOW */
        HAL_GPIO_WritePin(rows[row].port, rows[row].pin, GPIO_PIN_RESET);

        HAL_Delay(1);

        /* Check each column */
        for (int col = 0; col < 4; col++)
        {
            if (HAL_GPIO_ReadPin(cols[col].port, cols[col].pin) == GPIO_PIN_RESET)
            {
                while (HAL_GPIO_ReadPin(cols[col].port, cols[col].pin) == GPIO_PIN_RESET)
                    ;

                return keymap[row][col];
            }
        }
    }
    return 0; 
}
