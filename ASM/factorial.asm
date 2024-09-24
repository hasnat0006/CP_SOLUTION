.MODEL SMALL
.STACK 100H
.DATA
    N DW ?
    FACT DW 1  
    INPUT DW 'ENTER THE VALUE OF N: $'
    OUTPUT DW 'FACTORIAL IS: $'
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    
    MOV AH, 09H
    LEA DX, INPUT
    INT 21H
    
    MOV AH, 01H
    INT 21H
    XOR AH, AH
    MOV N, AX
    CMP N, '0'
    JZ ANS_IS_ZERO
    SUB N, '0'
    
    
        
    MOV CX, N
    FACTORIAL:
        MOV AX, CX
        MUL FACT            ;AX = AX * FACT
        MOV FACT, AX            
        LOOP FACTORIAL
    
    
    
    ;PRINTING NEW LINE
    MOV DX, 0AH
    MOV AH, 02H
    INT 21H    
    MOV DX, 0DH
    INT 21H
    
    LEA DX, OUTPUT
    MOV AH, 09H
    INT 21H
    
    MOV DX, FACT
    ADD DX, '0'
    MOV AH, 02H
    INT 21H
    JMP SESH
     
     
    ANS_IS_ZERO: 
        ;PRINTING NEW LINE
        MOV DX, 0AH
        MOV AH, 02H
        INT 21H    
        MOV DX, 0DH
        INT 21H
        
        LEA DX, OUTPUT
        MOV AH, 09H
        INT 21H
        MOV DX, '1'
        MOV AH, 02H
        INT 21H   
    SESH:

MAIN ENDP
    END MAIN






    ;; X = 1
    123
    NUM = 0

    FOR(INT I = 3; I > 0; I++){
        NUM += X * A[I]
        X *= 10;
    }