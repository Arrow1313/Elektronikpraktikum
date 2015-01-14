void taster_5(){
	byte taster_alt = 0b00000000;
	byte taster_neu = 0b00000000;
	byte counter = 0;
	TRISB = 0b00000000;
	TRISA = 0b111111;
	
	while(1){
		taster_neu = PORTA;
		if(taster_neu != taster_alt){
			taster_alt = taster_neu;
			counter++;
			LATB = counter;
			}//end of if(flag%2 == 1)
		}//end of if(taster_neu != taster_alt)
	}//end of while(1)
}//end of function taster_5()

void taster_6(){
	byte taster_alt = 0b00000000;
	byte taster_neu = 0b00000000;
	byte counter;
	byte flag = 0;
	TRISB = 0b00000000;
	TRISA = 0b111111;
	
	while(1){
		taster_neu = PORTA;
		if(taster_neu != taster_alt){
			flag++;
			taster_alt = taster_neu;
			if(flag%2 == 0){
				counter++;
				LATB = counter;
			}//end of if(flag%2 == 1)
		}//end of if(taster_neu != taster_alt)
	}//end of while(1)
}//end of function taster_6()

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
