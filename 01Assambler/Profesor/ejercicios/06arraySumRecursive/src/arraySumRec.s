			 
	AREA    |.text|, CODE, READONLY

arraySumRec  PROC
	 EXPORT arraySumRec
    push {r4,lr}		 
	  cbnz r1, casoNoTrivial
    mov r0,#0
    b endArraySum
casoNoTrivial
    ldr r4,[r0]
    add r0,#4
    sub r1,#1
    bl arraySumRec	
	  add r0,r4
endArraySum
    pop {r4,lr}
	  bx lr
	 ENDP
  END
