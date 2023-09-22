section .data
    format db "Hello, Holberton",10,0  ; The format string with a newline character (10) and null terminator (0)

section .text
    global main

extern printf  ; Declare the external printf function from the C library

main:
push rbp
mov rdi, format  ; Set the format string as the first argument (printf expects it in rdi)
call printf     ; Call the printf function
add rsp, 8      ; Restore the stack pointer (adjust for the printf call)
pop rbp
; Exit the program
mov rax, 60     ; System call number for exit (60 on x86_64)
xor rdi, rdi    ; Exit status (0)
syscall
