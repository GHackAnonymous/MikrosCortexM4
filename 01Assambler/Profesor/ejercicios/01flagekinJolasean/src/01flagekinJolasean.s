
   	        AREA    |.text|, CODE, READONLY
main    PROC
        EXPORT main
		
		mov r0,#2
		mov r1,#3
        
		adds r0,r0,r1  ;r0 <-- 5
		subs r1,r0,r1  ;r1 <-- 2
		subs r1,r1,r0  ;r1 <-- -3  !!!!!!
    subs r0,#5 	   ;r0 <-- 0
		adds r1,r1,r1  ;  to see C<--1 in a sum
		
		b .
    ENDP
	END