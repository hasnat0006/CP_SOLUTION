.MODEL SMALL
.STACK 100H
.DATA

    N DB ?
    M DB ?
    X DB ?
    VAL DB ? 
    SPACE DB ?
    STAR DB ?
    
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
           
    MOV AH, 01H           
    INT 21H    
     
    MOV N, AL
    SUB N, 48
    
    MOV AH, 02H    
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    
    ;--------------------;
    ;   THIS PROTION:    ;
    ;          *         ;
    ;         ***        ;
    ;        *****       ;
    ;       *******      ;
    ;--------------------;
    
    MOV AL, N
    MOV SPACE, AL
    DEC SPACE 
    
    ;MOV STAR, AL
    ;DEC STAR, SPACE
    MOV CL, N
    MOV CH, 0   
    OUTER1:  
        ;STAR = N - SPACE
        MOV AL, N
        MOV STAR, AL
        MOV AL, SPACE
        SUB STAR, AL
        ;STAR = 2 * STAR - 1  
        MOV AL, STAR
        ADD STAR, AL
        DEC STAR 
        MOV AL, SPACE
        MOV X, AL
        CMP X, 0 
        ; VAL = 1
        MOV VAL, 1
        JE SKIP_SPACE1 
        PRINT_SPACE1:
            MOV DL, 32
            MOV AH, 02H
            INT 21H
            DEC X
            CMP X, 0
            JNE PRINT_SPACE1 
        SKIP_SPACE1:
        PRINT_VALUE1:
            ; FOR PRINTING 0 AND 1 WE USE THE CONCEPT OF BITWISE AND
            ; EVEN NUM & 1 = 0
            ; ODD  NUM & 1 = 1
            AND VAL, 1
            MOV DL, VAL
            ADD DL, 48
            MOV AH, 02H
            INT 21H    
            INC VAL
            DEC STAR
            CMP STAR, 0
            JNE PRINT_VALUE1    
        DEC SPACE   
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
        LOOP OUTER1 
     
        ;--------------------;
        ;   THIS PROTION:    ;
        ;      *****         ;
        ;       ***          ;
        ;        *           ;
        ;--------------------;                     
        
        MOV SPACE, 1
        MOV CL, N 
        MOV CH, 0
        DEC CL
        
        OUTER2:
            MOV VAL, 1
            ;STAR = N - SPACE
            MOV AL, N
            MOV STAR, AL
            MOV AL, SPACE
            SUB STAR, AL
            ;STAR = 2 * STAR - 1
            MOV AL, STAR
            ADD STAR, AL
            DEC STAR    
            MOV AL, SPACE
            MOV X, AL
            PRINT_SPACE2:
                MOV DL, 32
                MOV AH, 02H
                INT 21H    
                DEC X
                CMP X, 0
                JNE PRINT_SPACE2
            PRINT_STAR2:
                AND VAL, 1
                MOV DL, VAL
                ADD DL, 48
                MOV AH, 02H
                INT 21H
                INC VAL
                DEC STAR
                CMP STAR, 0
                JNE PRINT_STAR2
            INC SPACE
            MOV DL, 0AH
            INT 21H
            MOV DL, 0DH
            INT 21H
            LOOP OUTER2                  

MAIN ENDP
    END MAIN