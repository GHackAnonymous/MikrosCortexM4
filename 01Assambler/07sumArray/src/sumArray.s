             AREA    |.text|, CODE, READONLY
				 
;/*---- uint32_t min(uint32_t n, uint32_t m) ---------------------------------------
;  arguments: r0, 
;  return:    r0,
;---------------------------------------------------------------------------*/		


;/*---uint32_t sumArray( uint32_t *bektore , uint32_t dim) -------------
;     {
;         uint32_t sum=0;
;         while( dim>0)
;		  {
;		      sum+=*bektore;
;			  bektore++;
;			  dim--;
;		  }
;      return sum;
;}---------------------------------------------------------------------*/	
	
sumArray PROC
	EXPORT 	sumArray
	mov r2, #0
loop
	cbz r1, endSumArray
	; Esto es igual que esto
	;cmp r1, #0
	;beq aurrera
	ldr r3,[r0]
	add r2,r3
	sub r1, #1
	add r0, #4
	b loop
endSumArray
	mov r0, r2
	bx lr
	ENDP
	END