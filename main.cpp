/*!****************************************************************************
 * @file main.cpp
 * @brief Activate the alarm when gas is detected
 * This program was built and tested on the NUCLEO F429ZI ARMC6,
 * connected to a Dip Switch and it takes care of turning on and off
 * the LED1 based on the selected state of the dip switch. Additionally,
 * it prints in the terminal the "Hello World" string when the process
 * is initialized.
 * The pin is set into a PullDown mode so the dip switch should be connected 
 * to 3.3V pin
 * @author Quattrone Martin
 * @author Vazquez Rodrigo
 *******************************************************************************/

#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2);          //! Creates a gasDetector digital input object in the D2 pin

    DigitalOut alarmLed(LED1);          //! Creates an alarmLed digital output object in LED1 

    gasDetector.mode(PullDown);         //! Assigns a Pulldown internal resistor to the gasDetector object

    alarmLed = OFF;                     //! Assigns an OFF state (from the arm_book_lib library) to the alarmLed object
    
    while (true) {
        printf("%s\n","Hello World");   //! prints a simple message to test the console output
        if ( gasDetector == ON ) {      //! Condition to detect the digitalinput state
            alarmLed = ON;              //! The LED turns on if the digitalinput has an ON state
        }       
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;             //! The LED turns OFF if the digitalinput has an OFF state
        }
    }
}