#include "speaker.hpp"

Speaker::Speaker()
{

	//enables the clock to port B
	PMC->PMC_PCER0 = 1 << ID_PIOB;

	//disable PIO control on B25 and set up for peripheral B TIOAO
	PIOB->PIO_PDR = PIO_PB25;
	PIOB->PIO_ABSR |= PIO_PB25;

	//enable output on B25
	PIOB->PIO_OER = PIO_PB25;
	// enable the clock to the TC0 (peripheral # 27)
    PMC->PMC_PCER0 = 1 << ID_TC0;
}

void Speaker::set_frequency(int frequency)
{
		// configure TC0 channel 0 for WAVSEL=10 mode 
	    // using the main clock / 2 as source
	    // and reset on C match 
	    TC0->TC_CHANNEL[ 0 ].TC_CMR =  
	    TC_CMR_WAVE 
	    | TC_CMR_TCCLKS_TIMER_CLOCK1 
	    | TC_CMR_WAVSEL_UP_RC;   

	    // configure pin A match clear
	    TC0->TC_CHANNEL[ 0 ].TC_CMR |= TC_CMR_ACPC_SET | TC_CMR_ACPA_CLEAR; 
	   	
	   	// set C match/clear for 36 kHz  
		TC0->TC_CHANNEL[ 0 ].TC_RC = 41'000'000 / frequency;
	    
	    // set 50% duty cycle
		TC0->TC_CHANNEL[ 0 ].TC_RA = TC0->TC_CHANNEL[ 0 ].TC_RC / 2;
	    set( 0 );
	   
	   	// enable and start 
	   	TC0->TC_CHANNEL[ 0 ].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

void Speaker::set(bool b)
{
	     if( b ){
         // eable C match -> pin set
         TC0->TC_CHANNEL[ 0 ].TC_CMR |= TC_CMR_ACPC_SET;         
      	}
      	else {
         // remove pin C match action
         TC0->TC_CHANNEL[ 0 ].TC_CMR &= ~ ( 0x3 << 18);
     }
}
