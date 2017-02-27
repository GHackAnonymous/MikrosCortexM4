
	AREA |.TEXT|, CODE, READONLY
	
max PROC
	EXPORT 	max
	cmp r0,r1
	bhs endMax
	mov r0,r1
endMax
	bx lr
	ENDP
	END
	