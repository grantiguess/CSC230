### Subroutines called from C.
    
### You should be able to compile this with each of the
### test programs to try out each of the functions.
    
    ## Expose the names of all of our subroutines.
    .global setGlobal
    .global swapGlobals
    .global sixParams
    .global formula

    ## Code goes in the text section.
    .text

### Implementation of setGlobal, assign 47 to a global variable.
setGlobal:
    movl $47, globalVar
    ret                         # Return to the caller.
    
### Implementation of swapGlobals, exchange the value of two global variables
swapGlobals:
    movl globalA, %eax
    movl globalB, %ebx
    movl %eax, globalB
    movl %ebx, globalA
    ret

### Implementation of sixParams, which adds six params and returns a * d + b * e - c * f
### a = %rdi, b = %rsi, c = %rdx, d = %rcx, e = %r8 f = %r9
sixParams:
    imul %rdi, %rcx
    imul %rsi, %r8
    imul %rdx, %r9
    sub %r9, %r8
    add %r8, %rcx
    mov %rcx, %rax
    ret

### Implementation of formula, which calculates (a + b) * (c - d)
### x = %rdi, y = %rsi
formula:
    
    ret
