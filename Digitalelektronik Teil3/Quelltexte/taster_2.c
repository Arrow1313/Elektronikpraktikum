// Implementierung der eigenen Funktion
void taster_2(){
	byte i;
	TRISB = 0b00000000;
	TRISA = 0b111111;
	
	while(1){
		if(PORTA == 0b00000001){
			if(LATB == 0b00000001)
				LATB == 0b00000000;
			else
				LATB == 0b00000001;
		}
		delay_ms(25);
	}//end of while(1)
}//end of function taster_1()

void taster_3(){
	byte i;
	TRISB = 0b00000000;
	TRISA = 0b11111111;
	
	while(1){
		if(PORTAbits.RA1 == 0b1){
			if(LATB == 0b00000001)
				LATB == 0b00000000;
			else
				LATB == 0b00000001;
		}
		delay_ms(25);
	}//end of while(1)
}//end of function taster_3()

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
