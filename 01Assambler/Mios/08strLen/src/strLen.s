             AREA    |.text|, CODE, READONLY
;/*---- uint32_t ourStrLen ( char *pStr ) ---------------------------------------
;  arguments: r0, 
;  return:    r0,
;---------------------------------------------------------------------------*/		


;/*---- uint32_t ourStrLen ( char *pStr ) ---------------------------------------
;{
;	uint32_t n=0;
;	while ( *pStr !=0)
;	{
;		n++;
;		pStr++;
;	}
;	return n ;
;}
;---------------------------------------------------------------------------*/		
	
ourStrLen PROC
	EXPORT 	ourStrLen
	mov r1, #0							             ;uint32_t n=0;
loop                       							 ;while
	ldrb r2,[r0] ; mueve de la pila al reguistro
	cbz r2, endOurStrLen   							 ;( *pStr !=0)
	add r1, #1             							 ;n++;
	add r0, #1            							 ;pStr++;
	b loop
endOurStrLen
	mov r0, r1             							 ;return n ;
	bx lr
	ENDP
	END