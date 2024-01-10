/*
  Octopus_MAX_EZ_V1.0_map.h - driver code for STM32H7xx ARM processor on a Octopus MAX EZ V1.0.

  Part of grblHAL

  Copyright (c) 2022-2023 Joe Corelli

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 3
#error "Octopus MAX EZ V1.0 board map is only configured for 6 motors max."
#endif

#if !(defined(STM32H723xx)) || HSE_VALUE != 25000000
#error "This board has STM32H7xx processor with a 25MHz crystal, select a corresponding build!"
#endif

#define BOARD_NAME "Octopus MAX EZ V1.0"
#define BOARD_URL "https://github.com/bigtreetech/Octopus-Max-EZ/tree/master"

#define SERIAL_PORT  			1   // GPIOD: TX = 8, RX = 9
#define I2C_PORT        		1   // GPIOB: SCL2 = 10, SDA2 = 11
#define SPI_PORT        		4 //(spi4)// GPIOE: SCK = 12, MISO - 13, MOSI - 14
#define VARIABLE_SPINDLE 			// Comment out to disable variable spindle

#define HAS_BOARD_INIT

// Motor Reference:
// Motor-1: X-axis
// Motor-2: Y-axis
// Motor-3: Z-axis
// Motor-4: M3-axis
// Motor-5: M4-axis
// Motor-6: M5-axis

// Define step pulse output pins.
#define X_STEP_PORT         	GPIOC
#define X_STEP_PIN          	13
#define Y_STEP_PORT         	GPIOE
#define Y_STEP_PIN          	4
#define Z_STEP_PORT         	GPIOE
#define Z_STEP_PIN          	1

// Define step direction output pins.
#define X_DIRECTION_PORT    	GPIOC
#define X_DIRECTION_PIN     	14
#define Y_DIRECTION_PORT    	GPIOE
#define Y_DIRECTION_PIN     	5
#define Z_DIRECTION_PORT    	GPIOE
#define Z_DIRECTION_PIN     	0

// Define stepper driver enable/disable output pin.
#define X_ENABLE_PORT         	GPIOE
#define X_ENABLE_PIN          	6  		// EN for Motor-1
#define Y_ENABLE_PORT         	GPIOE
#define Y_ENABLE_PIN          	3  		// EN for Motor-2
#define Z_ENABLE_PORT         	GPIOE
#define Z_ENABLE_PIN          	2  		// EN for Motor-3

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT        	GPIOF
#define X_LIMIT_PIN         	0       // MIN1
#define Y_LIMIT_PORT        	GPIOF
#define Y_LIMIT_PIN         	2       // MIN2
#define Z_LIMIT_PORT        	GPIOF
#define Z_LIMIT_PIN         	4    	// MIN3
							
// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE                	// Motor-4
#define M3_STEP_PORT        	GPIOB
#define M3_STEP_PIN         	8
#define M3_DIRECTION_PORT   	GPIOB
#define M3_DIRECTION_PIN    	9
#define M3_LIMIT_PORT       	GPIOF
#define M3_LIMIT_PIN       	 	3       // MIN4
#define M3_ENABLE_PORT        	GPIOB
#define M3_ENABLE_PIN      		7       // EN for M3 motor
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 1	
#define M4_AVAILABLE              	   	// Motor-5
#define M4_STEP_PORT        	GPIOB
#define M4_STEP_PIN         	5
#define M4_DIRECTION_PORT   	GPIOB
#define M4_DIRECTION_PIN    	4
#define M4_LIMIT_PORT       	GPIOF
#define M4_LIMIT_PIN        	1      	// MIN5                      
#define M4_ENABLE_PORT      	GPIOB
#define M4_ENABLE_PIN       	6      	// EN for M4
#endif

// Define ganged axis or C axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 3
#define M5_AVAILABLE               		// Motor-6
#define M5_STEP_PORT        	GPIOG
#define M5_STEP_PIN         	15
#define M5_DIRECTION_PORT   	GPIOB
#define M5_DIRECTION_PIN    	3
#define M5_LIMIT_PORT       	GPIOC
#define M5_LIMIT_PIN        	15      // MIN6                      
#define M5_ENABLE_PORT        	GPIOG
#define M5_ENABLE_PIN         	9  		// EN for M5 motor
#endif

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT         GPIOA
#define SPINDLE_ENABLE_PIN          6                // FAN0
#define SPINDLE_DIRECTION_PORT      GPIOA
#define SPINDLE_DIRECTION_PIN       5                // FAN1

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT_BASE       GPIOA_BASE
#define SPINDLE_PWM_PIN             1                // Fan4 PWM

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOF
#define COOLANT_FLOOD_PIN           6                // HE0
#define COOLANT_MIST_PORT           GPIOA
#define COOLANT_MIST_PIN            0                // HE1

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define RESET_PORT              	GPIOF  			 
#define RESET_PIN              	 	13				 // PS-ON
#define FEED_HOLD_PORT          	GPIOF
#define FEED_HOLD_PIN           	11           	 // IND-PROBE
#define CYCLE_START_PORT        	GPIOF
#define CYCLE_START_PIN         	10               // FWS

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PORT           	GPIOF
#define SAFETY_DOOR_PIN            	12               // PWR-DET
#endif

#define CONTROL_INMODE              GPIO_SINGLE

// Define probe switch input pin.
#define PROBE_PORT                  GPIOB
#define PROBE_PIN                   15               // Z probe

#if TRINAMIC_UART_ENABLE

#define MOTOR_UARTX_PORT            GPIOG
#define MOTOR_UARTX_PIN             14
#define MOTOR_UARTY_PORT            GPIOG
#define MOTOR_UARTY_PIN             13
#define MOTOR_UARTZ_PORT            GPIOG
#define MOTOR_UARTZ_PIN             12

#ifdef  M3_AVAILABLE
#define MOTOR_UARTM3_PORT           GPIOG
#define MOTOR_UARTM3_PIN           	11
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_UARTM4_PORT           GPIOG
#define MOTOR_UARTM4_PIN            10
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_UARTM5_PORT           GPIOG
#define MOTOR_UARTM5_PIN            9
#endif

#elif TRINAMIC_SPI_ENABLE

// The BTT Octopus MAX EZ V1.0 uses software SPI
#define TRINAMIC_SOFT_SPI

#define TRINAMIC_MOSI_PORT          GPIOE
#define TRINAMIC_MOSI_PIN           14
#define TRINAMIC_SCK_PORT           GPIOE
#define TRINAMIC_SCK_PIN            12
#define TRINAMIC_MISO_PORT          GPIOE
#define TRINAMIC_MISO_PIN           13

#define MOTOR_CSX_PORT              GPIOG
#define MOTOR_CSX_PIN               14
#define MOTOR_CSY_PORT              GPIOG
#define MOTOR_CSY_PIN               13
#define MOTOR_CSZ_PORT              GPIOG
#define MOTOR_CSZ_PIN               12

#ifdef  M3_AVAILABLE
#define MOTOR_CSM3_PORT             GPIOG
#define MOTOR_CSM3_PIN              11
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_CSM4_PORT             GPIOG
#define MOTOR_CSM4_PIN              10
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_CSM5_PORT             GPIOG
#define MOTOR_CSM5_PIN              9
#endif

#endif

// EOF
