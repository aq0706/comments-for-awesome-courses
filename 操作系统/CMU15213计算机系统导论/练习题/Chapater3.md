# Program Encodings

## 3.1

| Operand        | Value | Comment          |
| -------------- | ----- | ---------------- |
| %rax           | 0x100 | Register         |
| 0x104          | 0xAB  | Absolute Address |
| $0x108         | 0x108 | Immediate        |
| (%rax)         | 0xFF  | Address 0x100    |
| 4(%rax)        | 0xAB  | Address 0x104    |
| 9(%rax,%rdx)   | 0x11  | Address 0x10C    |
| 260(%rcx,%rdx) | 0x13  | Address 0x108    |
| 0xFC(,%rcx,4)  | 0xFF  | Address 0x100    |
| (%rax,%rdx,4)  | 0x11  | Address 0x10C    |

## 3.2

| movl | %eax, (%rsp)       |
| ---- | ------------------ |
| movw | (%rax), %dx        |
| movb | $0xFF, %bl         |
| movb | (%rsp,%rdx,4), %dl |
| movq | (%rdx), %rax       |
| movw | %dx, (%rax)        |

## 3.3

| movb $0xF, (%ebx)   | Cannot use %ebx as address register                          |
| ------------------- | ------------------------------------------------------------ |
| movl %rax, (%rsp)   | Mismatch between instruaction suffix and register ID         |
| movw (%rax),4(%rsp) | Cannot have both source and destination be memory references |
| movb %al,%sl        | No register named %sl                                        |
| movl %eax,$0x123    | Cannot have immediate as destination                         |
| movl %eax,%dx       | Destination operand incorrect size                           |
| movb %si, 8(%rbp)   | Mismatch between instruction suffix and register ID          |

## 3.4

| src_t         | dest_t        | Instruction         | Comments                  |
| ------------- | ------------- | ------------------- | ------------------------- |
| long          | long          | movq (%rdi),%rax    | Read 8 bytes              |
|               |               | movq %rax, (%rsi)   | Store 8 bytes             |
| char          | int           | movsbl (%rdi),%eax  | Convert char to int       |
|               |               | movl %eax,(%rsi)    | Store 4 bytes             |
| char          | unsigned      | movsbl (%rdi), %eax | Convert char to int       |
|               |               | movl %eax,(%rsi)    | Store 4 bytes             |
| unsigned char | long          | movzbl (%rdi), %eax | Read byte and zero-extend |
|               |               | movq %rax, (%rsi)   | Store 8 bytes             |
| int           | char          | movl (%rdi), %eax   | Read 4 bytes              |
|               |               | movb %al, (%rsi)    | Store low-order byte      |
| unsigned      | unsigned char | movl (%rdi), %eax   | Read 4 bytes              |
|               |               | movb %al, (%rsi)    | Store low-order byte      |
| char          | short         | movsbw (%rdi), %ax  | Read byte and sign-extend |
|               |               | movw %ax, (%rsi)    | Store 2 bytes             |

## 3.5

```c
void decode1(long *xp, long *yp, long *zp) {
    long r8 = *xp;
    long rcx = *yp;
    long rax = *zp;
    *yp = r8;
    *zp = rdx;
    *xp = rax;
}
```

## 3.6

| Instruction               | Result |
| ------------------------- | ------ |
| leaq 9(%rdx), %rax        | 9+q    |
| leaq (%rdx,%rbx), %rax    | q+p    |
| leaq (%rdx,%rbx,3), %rax  | q+3p   |
| leaq 2(%rbx,%rbx,7), %rax | 2+8p   |
| leaq 0xE(,%rdx,3), %rax   | 14+3q  |
| leaq 6(%rbx,%rdx,7), %rax | 6+p+7q |

## 3.7

```c
short scale3(short x, short y, short z) {
    short r = 10 * y + z + x * y;
    return r;
}
```

## 3.8

