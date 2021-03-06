// Implementierung der eigenen Funktion
void test_speed_delay_2(){
	TRISB = 0b00000000;
	
	while(1){
		LATBbits.LATB0 = 1;
		delay_us(1);
		LATBbits.LATB1 = 1;
		delay_us(2);
		LATBbits.LATB2 = 1;
		delay_10us(0);
		LATBbits.LATB3 = 1;
		delay_10us(1);
		LATBbits.LATB4 = 1;
		delay_ms(0);
		LATBbits.LATB5 = 1;
		delay_ms(1);
		LATBbits.LATB6 = 1;
		delay_ms(65535);
		LATBbits.LATB7 = 1;
		
		delay_ms(65535);
		
		LATB = 0b00000000;
		
		delay_ms(65535);
		
		//taster 7 gemessen
		
	}//end of while(1)
}//end of function test_speed_delay_2()


void test_speed_delay_3(){
	TRISB = 0b00000000;
	
	while(1){
		delay_us(25);
		LATBbits.LATB0 = 1;
		delay_us(25);
		LATBbits.LATB1 = 0;
	}//end of while(1)
}//end of function test_speed_delay_3()

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
