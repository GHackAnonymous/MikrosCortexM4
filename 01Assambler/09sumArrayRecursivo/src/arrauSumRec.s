             AREA    |.text|, CODE, READONLY
	
arrauSumRec PROC
	EXPORT 	arrauSumRec
	push{r4,lr}
	cbnz r1, endArrauSumRec ;if (dim == 0)
	mov r0, #0
	b saltoReturn0

endArrauSumRec

	
	
	
	;; al llegar a 1 en la dimension del array 
	;; este descuenta 4 y la sirecion del registro 
	;; R1 pasa a ser 0xfffffffd lo que proboca que 
	;; este al pasar de nuevo por la instrucion 
	;; cbz r1, endArraauSumRec esta compara si el contenido 
	;; del reguistro es dero pero en este caso no lo es 
	;; por lo tanto no sale del bucle 
	;;
	;; Solucion: en instrución en la que se suma 4 en R1
	;; deveria ser suma de 1
	
	ldr r4,[r0] ; tmp = *vector
	add r0, #4  ; vector++
	sub r1, #1  ; dim--
	bl arrauSumRec
    add r0, r4	; r0 = r0 + r4; 
saltoReturn0	
    pop{r4,lr}
	bx lr
	ENDP
	END