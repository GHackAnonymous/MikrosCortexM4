            AREA    |.data|, READWRITE
x1 DCD 7
x2 DCD 3
x3 DCD 45
x4 DCD 11
result DCB 0
			 
			 AREA    |.text|, CODE, READONLY
main    PROC
        EXPORT main
		
		ldr r0,=x1
		ldr r0,[r0]
        
		ldr r1,=x2
		ldr r1,[r1]
		sub r0,r1
		
		ldr r1,=x3
		ldr r1,[r1]
		add r0,r1
		
		ldr r1,=x4
		ldr r1,[r1]
		sub r0,r1
		
		ldr r1,=result
		str r0,[r1]
		
		b .
    ENDP
	END