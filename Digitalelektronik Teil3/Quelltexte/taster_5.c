void taster_7(){
	byte taster_alt = 0b00000000;
	byte taster_neu = 0b00000000;
	byte counter = 0;
	TRISB = 0b00000000;
	TRISA = 0b111111;
	
	while(1){
		delay_ms(10);
		if(PORTA){
			delay_ms(10);
			while(PORTA){
			}//end of while(!PORTA)
			counter++;
			LATB = counter;
		}//end of if(taster_neu != taster_alt)
	}//end of while(1)
}//end of function taster_7()

void ProcessIO(void){
	BlinkUSBStatus();
	// User Application USB tasks
	if((usb_device_state < CONFIGURED_STATE)||(UCONbits.SUSPND==1)) return;
	// Fügen Sie hier Ihren Code ein ######################################

	// handleCommands();	// Wertet Kommandozeichen aus,
							// die über USB geschickt wurden
							// kann erstmal auskommentiert bleiben!
	// User-Code Ende #####################################################
}//end ProcessIO
