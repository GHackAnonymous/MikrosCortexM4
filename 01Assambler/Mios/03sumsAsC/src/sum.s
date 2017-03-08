			 
	AREA    |.text|, CODE, READONLY
		
sum    PROC
	   EXPORT sum
	add r0,r1
	bx lr
	ENDP
  END