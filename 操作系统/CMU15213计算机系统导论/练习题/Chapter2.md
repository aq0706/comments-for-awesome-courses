| N    | 2^1  | 2^2  |      | 2^3  |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| DEC  | 2    | 4    | 6    | 8    | 10   | 12   | 14   |
| BIN  | 0010 | 0100 | 0110 | 1000 | 1010 | 1100 | 1110 |
| HEX  | 0x2  | 0x4  | 0x6  | 0x8  | 0xA  | 0xC  | 0xE  |

## 2.1

A. 0x25B9D2 to binary

- 0010 0101 1011 1001 1101 0010

B. binary 1010 1110 0100 1001 to hexadecimal

- 0xAE49

C. 0xA8B3D to binary

- 1010 1000 1011 0011 1101

D. binary  11 0010  0010 1101 1001 0110 to hexadecimal

- 0x322D96

## 2.2

| n    | 2^n(decimal) | 2^n*(hexadecimal) |
| ---- | ------------ | ----------------- |
| 5    | 32           | 0x20              |
| 23   | 8388608      | 0x800000          |
| 15   | 32768        | 0x8000            |
| 13   | 8192         | 0x2000            |
| 6    | 64           | 0x40              |
| 8    | 256          | 0x100             |

## 2.3

| Decimal | Binary    | Hexadecimal |
| ------- | --------- | ----------- |
| 0       | 0000 0000 | 0x00        |
| 158     | 1001 1110 | 0x9E        |
| 76      | 0100 1100 | 0x4C        |
| 174     | 1010 1110 | 0xAE        |
| 60      | 0011 1100 | 0x3C        |
| 241     | 1111 0001 | 0xF1        |
| 117     | 0111 0101 | 0x75        |
| 189     | 1011 1101 | 0xBD        |
| 245     | 1111 0101 | 0xF5        |

## 2.4

A. 0x605C + 0x5 = 0x0x6061

B. 0x605C - 0x20 = 0x603C

C. 0x605C + 32 = 0x607C

D. 0x60FA - 0x605C = 0x9E

## 2.5

```c
#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i ;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = val;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main() {
    test_show_bytes(12345);
    return 0;
}
```



A. Little endian: 0x78, Gig endian: 0x12

B. Little endian: 0x7856, Gig endian: 0x1234

C. Little endian: 0x785634, Gig endian: 0x123456

## 2.6

A. 0x0027C8F8 

0000 0000 0010 0111 1100 1000 1111 1000

0x4A1F23E0

0100 1010 0001 1111 0010 0011 1110 0000

B. second >> 2 can match 21bits

C. int significant bit 0 don't match

## 2.7

0x6D 6E 6F 70 71 72

## 2.8

| Operation | Result    |
| --------- | --------- |
| a         | 0100 1110 |
| b         | 1110 0001 |
| ~a        | 1011 0001 |
| ~b        | 0001 1110 |
| a & b     | 0100 0000 |
| a \| b    | 1110 1111 |
| a ^ b     | 1010 1111 |

## 2.9

B. 

Blue | Green = Cyan

Yellow & Cyan = Green

Red ^ Magenta = Blue

## 2.10

```c
void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}
```



| Step      | *x                      | *y                      |
| --------- | ----------------------- | ----------------------- |
| Initially | a                       | b                       |
| Step1     | a                       | a ^ b                   |
| Step2     | a ^ (a ^ b) = 0 ^ b = b | a ^ b                   |
| Step3     | b                       | b ^ (a ^ b) = 0 ^ a = a |

## 2.11

A. first = 0, last = 2k

B. first == last, step1 will let *x = *y = 0, then 0 ^ 0 = 0...

C `first <= last` change to `first < last`

## 2.12

A. 0x87654321 & 0xFF = 0x00000021

B. 0x87654321 ^ ~0xFF = 0x789ABC21

C. 0x87654321 | 0xFF = 0x876543FF

## 2.13

```c
int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y) {
    int result = bis(bic(x, y), bic(y, x));
    return result;
}
```

## 2.14

a=0x55 b=0x46

| Expression | Value                                     |
| ---------- | ----------------------------------------- |
| a & b      | 0101 0101 & 0100 0110 = 0100 0100 = 0x44  |
| a \| b     | 0101 0101 \| 0100 0110 = 0101 0111 = 0x57 |
| ~a \| ~b   | 0111 0111 = 0xBB                          |
| a & !b     | a & 0 = 0                                 |
| a && b     | 0x01                                      |
| a \|\| b   | 0x01                                      |
| !a \|\| !b | 0x00                                      |
| a && ~b    | 0x01                                      |

## 2.15

!(x ^ y)

## 2.16

|      |           | a << 2    | a << 2 | a >> 3 (Logical) | a >> 3 (Logical) | a >> 3 (A) | a >> 3 (A) |
| ---- | --------- | --------- | ------ | ---------------- | ---------------- | ---------- | ---------- |
| Hex  | Binary    | Binary    | Hex    | Binary           | Hex              | Binary     | Hex        |
| 0xD4 | 1101 0100 | 0101 0000 | 0x50   | 0001 1010        | 0x1A             | 1111 1010  | 0xFA       |
| 0x64 | 0110 0100 | 1001 0000 | 0x90   | 0000 1100        | 0x0C             | 0000 1100  | 0x0C       |
| 0x72 | 0111 0010 | 1100 1000 | 0xC8   | 0000 1110        | 0x0E             | 0000 1110  | 0x0E       |
| 0x44 | 0100 0100 | 0001 0000 | 0x10   | 0000 1000        | 0x08             | 0000 1000  | 0x08       |

## 2.17

| Hex  | Binary | B2U      | B2T       |
| ---- | ------ | -------- | --------- |
| 0xA  | 1010   | 8+2=10   | -8+2=-6   |
| 0x1  | 0001   | 2^0=1    | 1         |
| 0xB  | 1011   | 8+2+1=11 | -8+2+1=-5 |
| 0x2  | 0010   | 2^1=2    | 2         |
| 0x7  | 0111   | 4+2+1=7  | 7         |
| 0xC  | 1100   | 8+4=12   | -8+4=4    |

