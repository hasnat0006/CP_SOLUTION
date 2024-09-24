.MODEL SMALL
.STACK 100H
.DATA
    N DW ?  
    NUM DW ?
    DIGIT DW 0
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    CALL DECIMAL_INPUT
    
    CALL NEWLINE
    
    CALL DECIMAL_OUTPUT
    
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
    
    
    DECIMAL_INPUT PROC
        XOR DX, DX
        ; 
        FOR:
            MOV AH, 01H
            INT 21H
            CMP AL, 0DH
            JE FOR_END
            XOR AH, AH  ; AH = 0
            SUB AX, '0' ; CONVERT TO NUMBER
            MOV N, AX   ; N = USER INPUT (SINGLE DIGIT)
            MOV AX, 10  ; AX = 10 FOR MUL WITH DX
            MUL DX      ; AX = AX * DX  ; AX = 10 * DX(PREVIOUS NUMBER)
            ADD AX, N   ; AX = AX + N   ; N -> NEW INPUT
            MOV DX, AX  ; STORE IN DX
            INC DIGIT
            JMP FOR 
            
        FOR_END:
        MOV NUM, DX
        RET
    DECIMAL_INPUT ENDP

    DECIMAL_OUTPUT PROC
        XOR CX, CX
        MOV AX, NUM
        MOV BX, 10
        MOV CX, DIGIT
        
        FOR2:
            CWD
            DIV BX  ;NUM / 10 -> AX = AX / BX -> REMIDER IN DX
            PUSH DX ;PUSH DX INTO THE STACK
            LOOP FOR2
        
        XOR CX, CX
        MOV CX, DIGIT
        FOR3:
            POP DX        ; POP THE LAST ELEMENT FROM STACK
            ADD DX, '0'   ; ADD CHAR 0
            MOV AH, 02H
            INT 21H
            LOOP FOR3
        
        RET
    DECIMAL_OUTPUT ENDP


END MAIN