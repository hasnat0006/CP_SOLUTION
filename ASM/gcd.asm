.MODEL SMALL
.STACK 100H
.DATA
    INPUTA DW 'Enter the value of A: $'
    INPUTB DW 'Enter the value of B: $'
    A DW ?
    B DW ?
    ANS DW ?
    MIN DW ? 
    REMA DW ?
    REMB DW ?  
    N DW ?  
    NUM DW ?
    DIGIT DW 0

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ;PRINT MSG FOR A
    LEA DX, INPUTA
    MOV AH, 09H
    INT 21H    
    
    ; INPUT A
    CALL DECIMAL_INPUT
    MOV AX, NUM
    MOV A, AX
    CALL NEWLINE  
    
    ;PRINT MSG FOR B
    LEA DX, INPUTB
    MOV AH, 09H
    INT 21H    
    
    ; INPUT B
    CALL DECIMAL_INPUT
    MOV AX, NUM
    MOV B, AX
    CALL NEWLINE
    
    CALL GCD
    
    MOV AX, ANS
    MOV NUM, AX
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
    
    
    GCD PROC       
        FIND_GCD:
            MOV AX, A
            MOV BX, B
            CWD
            DIV BX 
            MOV A, BX
            MOV B, DX
            CMP B, 0
            JE KAJ_SESH
            JMP FIND_GCD
            
        KAJ_SESH:    
            MOV AX, A
            MOV ANS, AX
        RET
    GCD ENDP
    
    
    DECIMAL_INPUT PROC
        XOR DX, DX
        MOV DIGIT, 0
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