void adc_4(){
	byte val;
	
	TRISB = 0b00000000;
	TRISAbits.TRISA0 = 0b1;
	
	setup_adc_ports(AN0_TO_AN1);
	setup_adc(ADC_CLOCK_DIV_32);
	set_adc_channel(0);
	read_adc(ADC_START_ONLY);
	
	while(1){
		delay_ms(10);
		val = (read_adc(ADC_READ)>>7);

		if(val == 0b00000000)
			LATB = 0b00000000;		
		if(val == 0b00000001)
			LATB = 0b00000001;
		if(val == 0b00000010)
			LATB = 0b00000011;
		if(val == 0b00000011)
			LATB = 0b00000111;		
		if(val == 0b00000111)
			LATB = 0b00001111;
		if(val == 0b00000100)
			LATB = 0b00011111;
		if(val == 0b00000101)
			LATB = 0b00111111;
		if(val == 0b00000110)
			LATB = 0b01111111;		
		if(val == 0b00000111)
			LATB = 0b11111111;					
	}//end of while(1)
}//end of function adc_4()

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
