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

| Instruction             | Destinatino | Value |
| ----------------------- | ----------- | ----- |
| addq %rcx,(%rax)        | 0x100       | 0x100 |
| subq %rdx,8(%rax)       | 0x108       | 0xA8  |
| imulq $16,(%rax,%rdx,8) | 0x118       | 0x110 |
| incq 16(%rax)           | 0x110       | 0x14  |
| decq %rcx               | %rcx        | 0x0   |
| subq %rdx,%rax          | %rax        | 0xFD  |

## 3.9

```assembly
shift_left4_rightn:
	movq %rdi, %rax # Get x
	salq $4, %rax # x <<= 4
	movl %esi, %ecx # Get n (4 bytes)
	sarq %cl, %rax # x >>= n
```

## 3.10

```c
short p1 = y | z;
short p2 = p1 >> 9;
short p3 = ~p2;
short p4 = y - p3;
```

## 3.11

A. x = 0

B. movq $0,%rcx.

C. movl $0,%ecx

## 3.12

```assembly
uremdiv:
	movq %rdx, %r8 Copy qp
	movq %rdi, %rax Move x to lower 8 bytes of dividend
	movl $0, %edx #Set upper 8 bytes of dividend to 0
	divq %rsi #Divide by y
	movq %rax, (%r8) #Store quotient at qp
	movq %rdx, (%rcx) #Store remainder at rp
	ret
```

## 3.13

A. < int

B. >= short

C. <= unsigned char

D. != long, unsigned long, pointer

## 3.14

A. >= long

B. == short, unsigned short

C. > unsigned char

D. < int

## 3.15

A. 0x4003fc + 0x02 = 0x4003fe

B. 0x0x400431 − 12 = 0x400425

C. 400543 400545

D. 4005e8 - 141 = 400560

## 3.16

```c
void goto_cond(short a, short *p) {
    if (a == 0) {
        goto done;
    }
    if (*p >= a) {
        goto done;
    }
    *p = a;
done:
    return;
}

```

B. && If first condition is false, will skip second condition

## 3.17

```c
long gotodiff_se_alt(long x, long y) {
    long result;
    if (x < y)
    	goto x_lt_y;
    ge_cnt++;
    result = x - y;
    return result;
x_lt_y:
    lt_cnt++;
    result = y - x;
    return result;
}
```

## 3.18

```c
short test(short x, short y, short z) {
    short val = y + z - x;
    if (z > 5) {
        if (y > 2) {
            val = x / z;
        } else {
            val = x / y;
        }
    } else if (z < 3) {
        val = z / y;
    }
    return val;
}
```

## 3.19

A. 2*(45-25) = 40

B. 25+40 = 65
