void taster_4(){
	byte counter = 0;
	TRISB = 0b00000000;
	TRISA = 0b111111;
	
	while(LATAbits.LATA0){
		for(i, i < max; i++)
			Nop();
		count++;
		LATB = count;
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
