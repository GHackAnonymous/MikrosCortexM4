			 
	AREA    |.text|, CODE, READONLY
    
               IMPORT lehenaAlDa

;r4 batura gordetzeko
;r5 zerrenda izateko zeren eta r0 beste zerbaitetarako behar dugu
;r6 dim kopiatzeko zeren eta deitzen dugun beste prozedurak r1 alda dezake

    
lehenenBatura  PROC
	             EXPORT lehenenBatura
          push {r4,r5,r6,lr}  ;r12 satck a 8 bytetara alienatuta egon dadin
	        mov r4,#0
          mov r5, r0	
          mov r6,r1
          
loop      cbz r6, endF1
          ldr r0,[r5]
	        bl lehenaAlDa
          cbz r0,avanti
          add r4,#1
avanti    sub r6,#1
	        add r5,#4
          b loop	
endF1     mov r0, r4
          pop{r4,r5,r6,lr}
	        bx lr
	   ENDP
  END
 
 lehenenBatura  PROC
	             EXPORT lehenenBatura
          mov r2,#0
          mov r3, r0
          
loop      cbz r1, endF1
          ldr r0,[r3]
          push {r1,r2,r3,lr}
	        bl lehenaAlDa
          pop {r1,r2,r3,lr}
          cbz r0,avanti
          add r2,#1
avanti    sub r1,#1
	        add r3,#4
          b loop	
endF1     mov r0, r2
          bx lr
	   ENDP
  END