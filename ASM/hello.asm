.MODEL SMALL
.STACK 100H
.DATA

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    
    MOV AH, 4CH
    INT 21H 

MAIN ENDP
 
    
    
    NEWLINE PROC
        MOV AH, 02H
        MOV DX, 0AH
        INT 21H
        MOV DX, 0DH
        INT 21H
        RET
    NEWLINE ENDP  




END MAIN