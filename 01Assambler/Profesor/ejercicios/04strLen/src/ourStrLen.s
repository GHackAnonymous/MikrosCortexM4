			 
	AREA    |.text|, CODE, READONLY
		
ourStrLen  PROC
	EXPORT ourStrLen
	mov r1,#0
loop		 
	ldrb r2,[r0]
	;cmp r2,#00
  ;beq endOurStrLen
  cbz r2, endOurStrLen
  add r1,#1
	add r0,#1
  b loop	
endOurStrLen
  mov r0, r1
	bx lr
	ENDP
  END