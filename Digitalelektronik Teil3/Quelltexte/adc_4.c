void adc_4(){
	TRISC = b011111111;
	TRISB = 0b00000000;
	TRISAbits.TRISA0 = 1;
	byte flag = 0;
	
	//setting up the adc
	setup_adc_ports(AN0_TO_AN1);
	setup_adc(ADC_CLOCK_DIV_32);
	set_adc_channel(0);
	read_adc(ADC_START_ONLY);
	
	//starting the main routine
	while(1){
		if(PORTCbits.RC0 == 0b1){
			if(flag == 0)
				flag = 1;
			else
				flag = 0;
			}//end of if(PORTCbits.RC0 == 0b1)
		if(flag == 0){
			set_adc_channel(0);
			read_adc(ADC_START_ONLY);
		} else {
			set_adc_channel(1);
			read_adc(ADC_START_ONLY);			
		}
		delay_ms(10);
		
		LATB = read_adc(ADC_READ)<<2;
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
