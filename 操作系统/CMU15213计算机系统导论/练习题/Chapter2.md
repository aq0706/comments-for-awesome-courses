# Information Storage

| N   | 2^1  | 2^2  |      | 2^3  |      |      |      |
| --- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| DEC | 2    | 4    | 6    | 8    | 10   | 12   | 14   |
| BIN | 0010 | 0100 | 0110 | 1000 | 1010 | 1100 | 1110 |
| HEX | 0x2  | 0x4  | 0x6  | 0x8  | 0xA  | 0xC  | 0xE  |

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

| n   | 2^n(decimal) | 2^n*(hexadecimal) |
| --- | ------------ | ----------------- |
| 5   | 32           | 0x20              |
| 23  | 8388608      | 0x800000          |
| 15  | 32768        | 0x8000            |
| 13  | 8192         | 0x2000            |
| 6   | 64           | 0x40              |
| 8   | 256          | 0x100             |

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

# Integer Prepresentations

## 2.17

| Hex | Binary | B2U      | B2T       |
| --- | ------ | -------- | --------- |
| 0xA | 1010   | 8+2=10   | -8+2=-6   |
| 0x1 | 0001   | 2^0=1    | 1         |
| 0xB | 1011   | 8+2+1=11 | -8+2+1=-5 |
| 0x2 | 0010   | 2^1=2    | 2         |
| 0x7 | 0111   | 4+2+1=7  | 7         |
| 0xC | 1100   | 8+4=12   | -8+4=4    |

## 2.18

A. 0x2e0 = 2 * 16^2 + 14*16^2 = 738

B. -88

C.40

D.-48

E.120

G.504

H.192

I.-72

## 2.19

| x   | T2U4(x) |
| --- | ------- |
| -1  | 1111=15 |
| -5  | 1011=11 |
| -6  | 1010=10 |
| -4  | 1100=12 |
| 1   | 0001=1  |
| 8   | 1000=8  |

## 2.21

| Expression                    | Type     | Evaluation |
| ----------------------------- | -------- | ---------- |
| -2147483647-1  == 2147483648U | Unsigned | 1*         |
| -2147483647-1  < 2147483647   | Signed   | 1          |
| -2147483647-1U < 2147483647   | Unsigned | 0          |
| -2147483647-1 < -2147483647   | Signed   | 1          |
| -2147483647-1U < -2147483647  | Unsigned | 1          |

## 2.22

A . -8+4=4

B. -16+8+4=4

C. -32+16+8+4=4

## 2.23

```c
int fun1(unsigned word) {
    return (int)((word << 24) >> 24);
}

int fun2(unsigned word) {
    return ((int)word << 24) >> 24;
}
```

| w          | fun1(w)    | fun2(w)    |
| ---------- | ---------- | ---------- |
| 0x00000076 | 0x00000076 | 0x00000076 |
| 0x87654321 | 0x00000021 | 0x00000021 |
| 0x000000C9 | 0x000000C9 | 0xFFFFFFC9 |
| 0xEDCBA987 | 0x00000087 | 0xFFFFFF87 |

## 2.24

| Original | Truncated |
| -------- | --------- |
| 1        | 1         |
| 3        | 3         |
| 5        | 5         |
| 12       | 4         |
| 14       | 6         |

| Original | Truncated |
| -------- | --------- |
| 1        | 1         |
| 3        | 3         |
| 5        | 5         |
| -4       | 4         |
| -2       | 6         |

## 2.25

`i <= length - 1` change to `i < length`

# Integer Arithmetic

## 2.27

```c
int uadd_ok(unsigned x, unsigned y) {
    unsigned s = x + y;
    return s >= x;
}
```

## 2.28

| x   |         | -u4x    |     |
| --- | ------- | ------- | --- |
| Hex | Decimal | Decimal | Hex |
| 1   | 1       | 16-1=15 | 0xF |
| 4   | 4       | 12      | 0xC |
| 7   | 7       | 9       | 0x9 |
| A   | 10      | 6       | 0x6 |
| E   | 14      | 2       | 0x2 |

## 2.29

| x           | y           | x + y        | x + t5y    | Case |
| ----------- | ----------- | ------------ | ---------- | ---- |
| 10100 (-12) | 10001 (-15) | 100101 (-27) | 00101 (5)  | 1    |
| 11000 (-8)  | 11000 (-8)  | 110000(-16)  | 10000(-16) | 2    |
| 10111(-9)   | 01000(8)    | 11111(-1)    | 11111(-1)  | 2    |
| 00010(2)    | 00101(5)    | 00111(7)     | 00111(7)   | 3    |
| 01100(12)   | 00100(4)    | 010000(16)   | 10000(-16) | 4    |

## 2.30

```c
int tadd_ok(int x, int y) {
    int sum = x+y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >= 0 && y >= 0 && sum < 0;
    return !neg_over && !pos_over;
}
```

## 2.31

x+y-x=y=y

10100(-12) + 10001(-15) = 00101(5) + 01100(12) = 10001(-15)

## 2.32

y = 1000, -y = 01000 = 1000

x = 1000, x + y will overflow, x - y will not overflow

```c
int tusb_ok(int x, int y) {
    int sub = x - y;
    return (y >= 0 && sub <= x) || (y < 0 && sub > x);
}
```

## 2.33

| x      |             | -t4x    |     |
| ------ | ----------- | ------- | --- |
| Hex    | Decimal     | Decimal | Hex |
| 2 0010 | 01110 = 2   | -2      | E   |
| 3 0011 | 01101 = 3   | -3      | D   |
| 9 1001 | 10111 = -9  | 7       | 7   |
| B 1011 | 10101 = -11 | 5       | 5   |
| C 1100 | 10100 = -12 | 4       | 4   |

## 2.34

| Mode             | x      | y      | x * y        | Truncated x * y |
| ---------------- | ------ | ------ | ------------ | --------------- |
| Unsigned         | 100 4  | 101 5  | 10100 = 20   | 100 = 4         |
| Tow's complement | 100 -4 | 101 -3 | 01100 = 12   | 100 = -4        |
| Unsigned         | 010 2  | 111 7  | 01110 = 14   | 110 = 6         |
| Tow's complement | 010 2  | 111 -1 | 110 = -2     | 110 = -2        |
| Unsigned         | 110 6  | 110 6  | 0100100 = 36 | 100 = 4         |
| Tow's complement | 110 -2 | 110 -2 | 100 = 4      | 100 = -4        |

## 2.36

```c
int tmult_ok(int x, int y) {
    int64_t p = (int64_t) (x * y);
    return p == (int)p;
}
```

## 2.37

A. malloc(int x) will convert 64bit to 32bit, so it will be overflow.

B. when overflow, just return null.

```c
uint64_t required_size = ele_cnt * (uint64_t) ele_size;
size_t request_size = (size_t) required_size;
if (required_size != request_size)
    /* Overflow must have occurred. Abort operation */
    return NULL;
void *result = malloc(request_size);
```

## 2.38

2^k or 2^k+1 

k=0 -> 1,2

k=1 -> 2,3

k=2 -> 4,5

k=3 -> 8,9

## 2.39

n=31 x<<n+1=0 

(x<<(n + 1)) - (x<<m) = - (x<<m)

## 2.40

x*k

| K   | Shifts | Add/Subs | Expression                  |
| --- | ------ | -------- | --------------------------- |
| 7   | 1      | 1        | x<<3-x                      |
| 30  | 4      | 3        | (x<<4)+(x<<3)+(x<<2)+(x<<1) |
| 28  | 2      | 1        | (x<<5)-(x<<2)               |
| 55  | 2      | 2        | (x<<6)-(x<<3)-x             |

## 2.41

which operate less

## 2.42

```c
int div16(int x) {
    int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;
}
```

## 2.43

M=31,N=8

## 2.44

A.False x=min_value

B.True

C.false overflow

D.True

E. False x=min_value

F. True

G. True

# Floating Point

## 2.45

| Fractional value | Binary representation | Decimal representation |
| ---------------- | --------------------- | ---------------------- |
| 1/8              | 0.001                 | 0.125                  |
| 3/4              | 0.11                  | 0.75                   |
| 5/16             | 0.0101                | 0.3125                 |
| 2 11/16          | 10.1011               | 0.6875                 |
| 1 1/8            | 1.001                 | 1.125                  |
| 5 7/8            | 101.111               | 5.875                  |
| 3 3/16           | 11.0011               | 3.1875                 |

## 2.46

| Bits    | e    | E    | 2^E  | f    | M    | 2^E * M | V       | Deciaml |
| ------- | ---- | ---- | ---- | ---- | ---- | ------- | ------- | ------- |
| 0 00 00 | 0    | 0    | 1    | 0/4  | 0/4  | 0/8     | 0       | 0.0     |
| 0 00 01 | 0    | 0    | 1    | 1/4  | 1/4  | 1/4     | 1/4     | 0.25    |
| 0 00 10 | 0    | 0    | 1    | 2/4  | 2/4  | 2/4     | 1/2     | 0.5     |
| 0 00 11 | 0    | 0    | 1    | 3/4  | 3/4  | 3/4     | 3/4     | 0.75    |
| 0 01 00 | 1    | 0    | 1    | 0/4  | 4/4  | 4/4     | 1       | 1.0     |
| 0 01 01 | 1    | 0    | 1    | 1/4  | 5/4  | 5/4     | 5/4     | 1.25    |
| 0 01 10 | 1    | 0    | 1    | 2/4  | 6/4  | 6/4     | 3/2     | 1.5     |
| 0 01 11 | 1    | 0    | 1    | 3/4  | 7/4  | 7/4     | 7/4     | 1.75    |
| 0 10 00 | 2    | 1    | 2    | 0/4  | 4/4  | 8/4     | 2       | 2.0     |
| 0 10 01 | 2    | 1    | 2    | 1/4  | 5/4  | 10/4    | 5/2     | 2.5     |
| 0 10 10 | 2    | 1    | 2    | 2/4  | 6/4  | 12/4    | 3       | 3.0     |
| 0 10 11 | 2    | 1    | 2    | 3/4  | 7/4  | 14/4    | 7/2     | 3.5     |
| 0 11 00 |      |      |      |      |      |         | Infinit |         |
| 0 11 01 |      |      |      |      |      |         | NaN     |         |
| 0 11 11 |      |      |      |      |      |         | NaN     |         |

## 2.48

11 0101 1001 0001 0100 0001 * 2^21

E = 127 + 21 = 148 (10010100)

0 10010100 1101 0110 0100 0101 0000 010

## 2.49

2^(n+1) + 1

## 2.50

A. 10.111 = 11

B. 11.010 = 11

C. 11.000 = 11

D. 10.110 = 11

## 2.51

A.0

B.0

## 2.52

| Bits     | Format A | Format B        |
| -------- | -------- | --------------- |
| 011 0000 | 1        | 0111 000 = 1    |
| 101 1110 | 15/2     | 1001 111 = 15/2 |
| 010 1001 | 25/32    | 0110 100 = 3/4  |
| 110 1111 | 31/2     | 1011 000 = 16   |
| 000 0001 | 1/64     | 0001 000 = 1/64 |

