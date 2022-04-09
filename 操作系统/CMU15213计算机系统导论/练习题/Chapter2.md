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
