#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2); //! Creates a gasDetector digital input object in the D2 pin

    DigitalOut alarmLed(LED1); //! Creates an alarmLed digital output object in LED1 

    gasDetector.mode(PullDown); //! Assigns a Pulldown internal resistor to the gasDetector object

    alarmLed = OFF; //! Assigns an OFF state (from the arm_book_lib library) to the alarmLed object
    
    while (true) {
        printf("%s\n","Hello World"); //! prints a simple message to test the console output
        if ( gasDetector == ON ) {    //! Condition to detect the digitalinput state
            alarmLed = ON;             //! The LED turns on if the digitalinput has an ON state
        }       
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;         //! The LED turns OFF if the digitalinput has an OFF state
        }
    }
}