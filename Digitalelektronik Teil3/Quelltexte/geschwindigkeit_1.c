// Implementierung der eigenen Funktion
void test_speed_1(){
	TRISB = 0b00000000;
	
	while(1){
		LATB = 0b1111111;
		LATB = 0b0000000;
	}//end of while(1)
}//end of function test_speed_1()

void ProcessIO(void){
	BlinkUSBStatus();
	// User Application USB tasks
	if((usb_device_state < CONFIGURED_STATE)||(UCONbits.SUSPND==1)) return;
	// Fügen Sie hier Ihren Code ein ######################################

	test_speed_1();

	// handleCommands();	// Wertet Kommandozeichen aus,
							// die über USB geschickt wurden
							// kann erstmal auskommentiert bleiben!
	// User-Code Ende #####################################################
}//end ProcessIO
