## 4.1

```assembly
0x100: 30 f3 0f 00 00 00 00 00 00 00	 |  irmovq $15,%rbx
0x10a: 20 31						   |  rrmovq %rbx,%rcx
0x10c: 40 13 fd ff ff ff ff ff ff ff     | rmmovq %rcx,-3(%rbx)
0x116: 60 31                             | addq %rbx,%rcx
0x118: 700c01000000000000                | jmp loop
```

## 4.19

```assembly
bool need_valC =
	icode in { IIRMOVQ, IRMMOVQ, IMRMOVQ, IJXX, ICALL };
```

## 4.20

```assembly
word srcB = [
    icode in { IOPQ, IRMMOVQ, IMRMOVQ } : rB;
    icode in { IPUSHQ, IPOPQ, ICALL, IRET } : RRSP;
    1 : RNONE; # Don’t need register
];
```

## 4.21

```assembly
word dstM = [
    icode in { IMRMOVQ, IPOPQ } : rA;
    1 : RNONE; # Don’t write any register
];
```



























