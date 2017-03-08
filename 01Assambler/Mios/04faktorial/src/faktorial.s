             AREA    |.text|, CODE, READONLY
				 
;/*---- uint32_t factorial(uint32_t n) ---------------------------------------
;  arguments: r0, the number of wich factorial must be calculated
;  return:    r0,
;---------------------------------------------------------------------------*/				 
factorial    PROC
             EXPORT factorial

         mov r1, #1
bucle
         cmp r0, #1
         bls faktEnd
         mul r1, r0
         sub r0, #1
         b bucle
faktEnd
         mov r0, r1
         bx lr
     ENDP
		 END