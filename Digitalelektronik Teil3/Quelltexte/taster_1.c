// Implementierung der eigenen Funktion
void taster_1(){
	byte i;
	TRISB = 0b00000000;
	TRISA = 0b111111;
	
	while(1){
		i = PORTA;
		
		LATB = i;
	}//end of while(1)
}//end of function taster_1()

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
