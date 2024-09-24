; find the longest increasing substring
; input: fghdefgh
; output: defgh
.model small
.stack 100h
.data
str db 100 dup(?)
dp db 100 dup(1)
sz db 0
mx db 0
ind db 0

.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea si, str
    lea di, dp
    
    inp:
        mov ah, 1
        int 21h
        cmp al, 13
        je endInp
        mov [si], al
        inc si
        inc sz
        jmp inp
        
    endInp:    
    
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    
    mov ch, 0
    mov cl, sz
    
    lea si, str
    
    mov bl, 1
    
    solve:
        lea si, str 
        mov bh, 0
        add si, bx
        mov ah, [si]
        dec si
        mov al, [si]
        sub ah, 1
        cmp ah, al
        jne notEq
        lea di, dp
        add di, bx
        dec di
        mov dl, [di]
        add dl, 1
        inc di
        mov [di], dl
        
        notEq:
        inc bl
        cmp bl, sz
        jne solve   
        
    lea di, dp
    mov bl, 0
    
    find:
        mov dl, [di]
        cmp dl, mx
        jle less
        mov mx, dl
        mov ind, bl
        
        less:
        inc di
        inc bl
        cmp bl, sz
        jne find
        
                   
    mov bl, mx
    sub ind, bl
    inc ind      
    mov bl, 0
    
    prnt:   
        lea si, str
        mov dx, 0
        mov dl, bl
        add dl, ind
      
        add si, dx
        mov dl, [si]
        mov ah, 2
        int 21h
        inc bl
        cmp bl, mx
        jl prnt
        
    main endp
end main