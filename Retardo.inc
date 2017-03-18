    Retardo_50ms:
	clrf	    k
	movlw	    .130
	movwf	    m
	;------Tiempo-de-ejecicion-al-salir-129uS
	decfsz	    k,1
	    goto    $-1
	;--------------------------------------
	decfsz	    m,1
	    goto    $-3
    return


