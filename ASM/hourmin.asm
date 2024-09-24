.MODEL SMALL
.STACK 100H
.DATA
    SEC DW 3969
    HOUR DW ?
    MIN DW ?
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AX, SEC
    MOV BX, 3600D
    CWD
    DIV BX
    MOV SEC, DX
    MOV HOUR, AX
    
    MOV AX, SEC
    MOV BX, 60D
    CWD
    DIV BX
    MOV SEC, DX
    MOV MIN, AX 
    
    MOV DX, HOUR
    ADD DX, '0'
    MOV AH, 02H
    INT 21H  
    CALL NEWLINE
    MOV DX, MIN
    ADD DX, '0'
    MOV AH, 02H
    INT 21H
    CALL NEWLINE
    MOV DX, SEC
    ADD DX, '0'
    MOV AH, 02H
    INT 21H
    
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