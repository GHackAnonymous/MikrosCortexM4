             AREA    |.text|, CODE, READONLY
				 
;/*---- uint32_t min(uint32_t n, uint32_t m) ---------------------------------------
;  arguments: r0, 
;  return:    r0,
;---------------------------------------------------------------------------*/		


;/*---- uint32_t min(uint32_t n, uint32_t m) ---------------------------------------
;  if(n<m){
;		return n;
;	}else{
;		return m;
;	}
;---------------------------------------------------------------------------*/		




	AREA |.TEXT|, CODE, READONLY
	
min PROC
	EXPORT 	min
	cmp r0,r1
	bhs endMin
	bx lr
endMin
	mov r0,r1
	bx lr
	ENDP
	END