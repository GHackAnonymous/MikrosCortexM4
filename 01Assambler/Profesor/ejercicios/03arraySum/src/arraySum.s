			 
	AREA    |.text|, CODE, READONLY
		
arraySum  PROC
	 EXPORT arraySum
	mov r2,#0
loop		 
	cbz r1, endArraySum
	ldr r3,[r0]
	add r2,r3
avanti
    sub r1,#1
	add r0,#4
    b loop	
endArraySum
    mov r0, r2
	bx lr
	ENDP
  END