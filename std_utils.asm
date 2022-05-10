; std_utils.asm
section .data
    format_registers db "rbx:0x%lx r12:0x%lx r13:%ld r14:%ld", 10, 0
    format_stack db "sommet (rsp): 0x%lx, base du bloc (rbp): 0x%lx", 10, 0
    format_printInt db "Val rdi : %d", 10, 0
section .text
global show_registers
global show_stack
global printInt
global exit
extern printf
show_registers:
    push rbp
    mov rbp, rsp
    
    mov r8,  r14
    mov rcx, r13
    mov rdx, r12
    mov rsi, rbx
    mov rdi, format_registers
    mov rax, 0
    call printf 
        
    pop rbp
    ret
printInt:
    push rbp
    mov rbp, rsp

    mov rsi, rdi
    mov rdi, format_printInt
    mov rax, 0
    call printf

    pop rbp
    ret
show_stack:
    push rbp
    mov rbp, rsp

    mov rdx, [rsp]
    mov rax, rsp
    add rax, 16
    mov rsi, rax
    mov rdi, format_stack
    mov rax, 0
    call printf WRT ..plt
    
    pop rbp
    ret

exit:
    mov rax, 60
    mov rdi, 0
    syscall