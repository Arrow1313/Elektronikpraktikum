// Implementierung der eigenen Funktion
void test_speed_delay_1(){
	int i;
	TRISB = 0b00000000;
	
	while(1){
		Delay10TCYx(100);
		LATBbits.LATB0 = 1;
		Delay100TCYx(100);
		LATBbits.LATB1 = 1;
		Delay1KTCYx(100);
		LATBbits.LATB2 = 1;
		Delay10KTCYx(100);
		LATBbits.LATB3 = 1;
		Delay10TCYx(255);
		LATBbits.LATB4 = 1;
		Delay100TCYx(255);
		LATBbits.LATB5 = 1;
		Delay1KTCYx(255);
		LATBbits.LATB6 = 1;
		Delay10KTCYx(255);
		LATBbits.LATB7 = 1;
		Delay10KTCYx(100);
		LATB = 0b00000000;
		
	}//end of while(1)
}//end of function test_speed_delay_1()

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
