void oszi_1(){
	byte counter = 0;
	TRISB = 0b00000000;
	TRISA = 0b111111;
	
	while(PORTAbits.RA0){
		counter++;
		LATB = counter;
	}//end of while(LATAbits.LATA0)
}//end of function oszi_1()

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
