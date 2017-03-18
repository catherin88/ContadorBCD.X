
;    bcd_h
;    bcd_l
;    val_Inic
;    bin
;    bin_aux
;    j
;    i
    
Bin_BCD:
    clrf	bcd_h
    clrf	bcd_l
    movf	val_Inic,0
    movwf	bin

Ret_Centenas:
    movf	bin,0
    movwf	bin_aux
    movlw	.100
    subwf	bin_aux,1
    btfss	STATUS,C
	goto	Ret_Decenas
    movlw	.100
    subwf	bin,1
    incf	bcd_h,1
    goto	Ret_Centenas
Ret_Decenas:
    movf	bin,0
    movwf	bin_aux
    movlw	.10
    subwf	bin_aux,1
    btfss	STATUS,C
	goto	Ret_Unidades
    movlw	.10
    subwf	bin,1
    movlw	0x10
    addwf	bcd_l,1
    goto	Ret_Decenas
Ret_Unidades:
    incf	bin,1
Dec_bin:
    decfsz	bin,1
	goto	Inc_Und
    clrf	bin
    clrf	bin_aux
return

Inc_Und:
    incf    bcd_l,1
    goto    Dec_bin
    
Aux_rut:
    incf    i,1
    goto    Ret_Ret
	
Tabla:
    addwf   PCL,1
    ;----- portb 1 a 60 ---------------------------------------
    DT	.0,.0,.0,.128,.192,.96,.48,.24,.12,.6
    DT	.3,.6,.12,.24,.48,.96,.192,.128,.0,.0
    DT	.0,.0,.0,.0,.64,.16,.4,.1,.4,.16
    DT	.64,.0,.0,.240,.15,.240,.15,.240,.15,.240
    DT	.15,.240,.204,.51,.204,.51,.204,.51,.204,.51
    DT	.204,.85,.170,.85,.170,.85,.170,.85,.170,.85
    
    ;----- portc 61 a 120 ------------------------------------
    DT	.12,.6,.3,.1,.0,.0,.0,.0,.0,.0
    DT	.0,.0,.0,.0,.0,.0,.0,.1,.3,.6
    DT	.12,.8,.4,.1,.0,.0,.0,.0,.0,.0
    DT	.0,.1,.4,.0,.15,.0,.15,.0,.15,.0
    DT	.15,.0,.12,.3,.12,.3,.12,.3,.12,.3
    DT	.12,.5,.10,.5,.10,.5,.10,.5,.10,.5
	
    ;-----------------------------------------------------------


