void adc_2(){
	TRISD = 0b00000000;
	TRISC = 0b00000000;
	TRISB = 0b00000000;
	TRISAbits.TRISA0 = 1;
	byte value;
	
	setup_adc_ports(AN0_TO_AN1);
	
	setup_adc(ADC_CLOCK_DIV_32);
	
	set_adc_channel(0);
	
	read_adc(ADC_START_ONLY);
	
	while(1){
		delay_ms(10);
		
		value = read_adc(ADC_READ)>>2;
		
		valH = value>>4;
		valL = (value & 0b00001111)>>4;
		
		LATD = dec_7seg[valH];
		LATC = dec_7seg[valL];
		
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
