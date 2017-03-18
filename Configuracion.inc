; config bits
__CONFIG _CONFIG1,   0XE3F4
__CONFIG _CONFIG2,   0XFEFF 
    
Conf_osc:
   bsf	    STATUS,RP0
   movlw    0xF1
   movwf    OSCCON
   bcf	    STATUS,RP0
return
   
Conf_P:
    ;0 salida, 1 entrada tristX X es el puerto
    bsf	    STATUS,RP0
    movlw   0xFF
    movwf   TRISA
    movlw   0x00
    movwf   TRISB
    movwf   TRISC
    bcf	    TRISE,0
    ;'1' ANALOG, '0' DIGITAL  Ansel y anselh
    bsf     STATUS,RP1
    ;	BANKSEL	ANSEL
    ;	bsf	    STATUS,RP0
    ;	bsf	    STATUS,RP1
    clrf    ANSEL
    clrf    ANSELH
    bcf     STATUS,RP0
    bcf     STATUS,RP1
    clrf    PORTB
    clrf    PORTC
 return
 
 val_inic:
    clrf    bcd_h
    clrf    bcd_l
    clrf    val_Inic
    clrf    bin
    clrf    bin_aux
    clrf    j
    clrf    i
    clrf    k
    clrf    m
return
