           AREA    |.data|, READWRITE
x1 DCD 7
x2 DCD 3
result DCB 0
			 
			 AREA    |.text|, CODE, READONLY
main    PROC
        EXPORT main
		
		bl proc1
		
		ldr r1,=result
		str r0,[r1]
		
		b .
    ENDP
		
proc1    PROC
  push {lr}
	bl proc2
  add r0,#2
  pop {lr}
  bx lr
	ENDP
    
proc2    PROC
  push {lr}
	bl proc3
  add r0,#1
  pop {pc}
	ENDP
    
proc3    PROC
	mov r0,#1
  bx lr
	ENDP
  END 