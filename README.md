# STM32 74HC595 LED Pattern Driver

STM32 HAL library for controlling multiple 74HC595 shift registers with animated LED patterns such as:

* Left Arrow (←)
* Right Arrow (→)
* Cross (X)
* Clear Display
* All LEDs ON

Designed for traffic signs, lane indicators, warning displays, and custom LED matrices.

## Features

* Supports multiple cascaded 74HC595 shift registers
* STM32 HAL compatible
* Bit-level GPIO control
* Animated LED patterns
* Simple API for setting individual pins
* Supports dynamic pattern selection via GPIO inputs

---

## Hardware Requirements

* STM32 microcontroller
* 74HC595 shift register IC(s)
* LED matrix or discrete LEDs
* External power supply (if required)

Tested with:

* STM32F030
* STM32F103
* STM32CubeIDE
* STM32 HAL Library

---

## Connections

| 74HC595 Pin  | STM32 GPIO |
| ------------ | ---------- |
| SER (DS)     | data_Pin   |
| SHCP (CLK)   | clock_Pin  |
| STCP (LATCH) | latch_Pin  |
| MR           | mr_Pin     |
| OE           | oe_Pin     |

---

## Initialization

```c
HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port,
                  mr_Pin,
                  GPIO_PIN_SET);

HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port,
                  oe_Pin,
                  GPIO_PIN_RESET);

ClockPinSet(HIGH595);
LatchPinSet(HIGH595);
```

---

## Example Usage

### Display Right Arrow

```c
pattern_panah_kanan();
```

### Display Left Arrow

```c
pattern_panah_kiri();
```

### Display Cross

```c
pattern_silang();
```

### Clear Display

```c
ShiftRegister74HC595_clear();
```

### Turn ON All LEDs

```c
ShiftRegister74HC595_on();
```

---

## Control Individual Output

```c
ShiftRegister74HC595_setPin(index, value);
ShiftRegister74HC595_update();
```

Example:

```c
ShiftRegister74HC595_setPin(5, true);
ShiftRegister74HC595_update();
```

---

## Animated Example

```c
while (1)
{
    pattern_panah_kanan();
    HAL_Delay(1000);

    pattern_silang();
    HAL_Delay(1000);

    pattern_panah_kiri();
    HAL_Delay(1000);
}
```

---

## Project Structure

```text
├── Core/
│   ├── Src/
│   │   ├── main.c
│   │   └── 74HC595.c
│   └── Inc/
│       └── 74HC595.h
├── LICENSE
└── README.md
```

---

## License

This project is dual-licensed:

* GNU General Public License v2 (GPLv2)
* Commercial License

Open source usage follows GPLv2 terms.

For commercial licensing inquiries:

contact: [your-email@example.com](mailto:your-email@example.com)

---

## Author

Kurnia Aditya Reynaldi

Contributions, issues, and pull requests are welcome.
