; FILE AUTO GENERATED BY COMPILER
; --------------------
; Translator tpc -> asm
;
; authors : Elliott FALGUEROLLE & Antonin JEAN

section .data
<<<<<<< HEAD
vga: dd 0
vgb: dd 0
vgc: dd 0
vgd: db 0
vge: db 0
vgf: db 0
=======
i: dd 0
>>>>>>> 566be5bc237dac0c81fecad5631f3a70bd5d7d68
section .text
global: main

t:
push rbpmov rbp, rsp
mov rsp, rbp
pop rbp
ret

fun:
push rbpmov rbp, rsp
mov rsp, rbp
pop rbp
ret

main:
; End of Program: Print -1 as Fine-Output
mov rdi, -1
call printInt
mov rax, 60
mov rdi, 0
syscall