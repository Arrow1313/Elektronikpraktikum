`timescale 1ns / 1ps // Diese Zeitskala (Schrittweite, Auflösung)
// ist nur bei Simulationen wichtig
//////////////////////////////////////////////////////////////////////////////////
// Company: // Engineer: VERSCHIEDENE KOMMENTARE
// Create Date: 12:22:32 01/08/2010
// ...
//////////////////////////////////////////////////////////////////////////////////
module testXC9572( // Jedes Verilog-Programm ist ein Modul mit einem Namen
   C, CE, CLR, // und in runden Klammern müssen
   segments1, segments2, LED_OUT // alle Ein-/Ausgangssignale genannt werden
   );

input C;                    // Signale als EINgänge definieren
input CE; input CLR;        // C = Clock, CLR = Clear, jeweils 1 Signal
output [7:0] segments1;     // Signale als AUSgänge definieren
output [7:0] segments2;     // hier haben wir z.B. Signalgruppen von
output [7:0] LED_OUT;       // 8 Bits, daher die Angabe [7:0]

  reg [7:0] segments1;     // Das ist erstmal noch auskommentiert,
  reg [7:0] segments2;     // weil wir es erst später brauchen.
  reg [14:0] prescaler;     // reg = Register, das ist praktisch ein D-Flipflop.
  reg [3:0]  counter;       // Hier haben wir Register mit 15 bzw. 8 Bit.
  reg [3:0] counter2;

assign LED_OUT = counter;   // Der Inhalt des 8-Bit-Zählers "counter" wird
                            // mit assign direkt den
                            // 8 Bits von LED_OUT zugeordnet.

                                     // Unser Zähler soll mit Signal C getaktet
always @ (posedge C or posedge CLR)  // und mit CLR zur¨uckgesetzt werden.
   begin                             // (posedge = ansteigende Flanke)
      if(CLR)                        // Wenn also CLR auf 1 ist ...
         begin
            prescaler = 0;           // dann setzte counter und prescaler auf 0
            counter = 0;
				counter2 = 0;
         end
      else                           // andernfalls (also wenn CLR = 0) ...
        
				if (CE)
					begin
							prescaler = prescaler +1;
						if(prescaler == 0)       // und wenn dieser auf 0 ist (das passiert
							begin                 // einmal in 2 hoch 15 Takten!) dann ...
								counter = counter + 1; // ... erhöhe den counter um 1
								if(counter[3:0] == 10)
									begin
										counter[3:0] = 0;
										counter2[3:0] = counter2 + 1;
									end
								if(counter2[3:0] == 10)
									begin
										counter2[3:0] = 0;
									end
							end
					segments1 = segment7(counter[3:0]);
					segments2 = segment7(counter2[3:0]);
					end
			
	end


// ----  FUNCTION: 7-segment-decoder ------------------------------------
function [7:0] segment7;             // Eine Funktion mit dem Namen und
                                     // 8 Bit großen Ausgabewert segment7

   input [3:0] decodeinput;          // Was an die Funktion übergeben wird,
                                     // wird innerhalb der Funktion unter dem
                                     // Namen decodeinput geführt (4 Bit).

   case (decodeinput)                // Für den Fall, daß decodeinput ...
      4'h0 : segment7 = 8'b00111111; // ... den Wert 0 hat: segment7 = Muster "0"
                        // Dgfedcba <<< Stellen f¨ur Dezimalpunkt (D) und 7 Segmente
                        // als 8-Bit-Binärzahl (daher 8'b)
                        // decodeinput schreiben wir als 4-Bit-Hexadezimalzahl, also 0-9,a-f
      4'h1 : segment7 = 8'b00000110; // das Strichmuster "1"
      4'h2 : segment7 = 8'b01011011; // diese Strichmuster müssen Sie noch ändern
      4'h3 : segment7 = 8'b01001111;
      4'h4 : segment7 = 8'b01100110;
      4'h5 : segment7 = 8'b01101101;
      4'h6 : segment7 = 8'b11111101;
      4'h7 : segment7 = 8'b00000111; 
      4'h8 : segment7 = 8'b01111111;
      4'h9 : segment7 = 8'b11101111;
      4'ha : segment7 = 8'b01110111;
      4'hb : segment7 = 8'b01111111;
      4'hc : segment7 = 8'b00111001;
      4'hd : segment7 = 8'b00111111;
      4'he : segment7 = 8'b01111001;
      4'hf : segment7 = 8'b01110001;
   endcase                              // Ende der case-Anweisung
endfunction                             // Ende der Funktion

endmodule