
list p=16F887
    
#include    "Definiciones.inc"
    
CBLOCK	0x20
    bcd_h
    bcd_l
    val_Inic
    bin
    bin_aux
    j
    i
    k
    m
ENDC	
    
ORG .0
call	Conf_osc
call	Conf_P
GOTO	Main
ORG .5
Main:
    call    val_inic
    movf    PORTA,0
    movwf   val_Inic
Rein_conv:
    call    Bin_BCD
    movf    bcd_h,0
    movwf   PORTC
    movf    bcd_l,0
    movwf   PORTB
    call    Retardo_50ms
    btfss   PORTE,0
	goto	Main
    incf    i,1
    movlw   .20	
    xorwf   i,0
    btfsc   STATUS,Z
	goto	Sig_Sec
    goto    $-8
Sig_Sec:
    clrf    i
    movlw   .255	
    xorwf   val_Inic,0
    btfsc   STATUS,Z
	goto	Sec_Inter
    incf    val_Inic,1
    goto    Rein_conv
Sec_Inter:
    movf    j,0
    call    Tabla
    movwf   PORTB
    movlw   .60
    addwf   j,0
    call    Tabla
    movwf   PORTC
    incf    j,1
    clrf    i
Ret_Ret:
    call    Retardo_50ms
    btfss   PORTE,0
	goto	Main
    movlw   .20
    xorwf   i,0
    btfss   STATUS,Z
	goto	Aux_rut
    movlw   .60
    xorwf   j,0
    btfss   STATUS,Z
	goto	Sec_Inter
    goto    Main
#include    "Configuracion.inc"
#include    "Conversor.inc"  
#include    "Retardo.inc"
end    
