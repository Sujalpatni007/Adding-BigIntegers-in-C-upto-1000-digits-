
#ifndef BIGINT_H
#define BIGINT_H

#define MAX_DIGITS 1000

// Define the BigInt structure
typedef struct {
    char digits[MAX_DIGITS];
    int length;
} BigInt;

// Function declarations
void initBigInt(BigInt *num, const char *str);
int compareBigInt(const BigInt *a, const BigInt *b);
void addBigInt(BigInt *result, const BigInt *a, const BigInt *b);
void subtractBigInt(BigInt *result, const BigInt *a, const BigInt *b);
void multiplyBigInt(BigInt *result, const BigInt *a, const BigInt *b);
void fibonacciBigInt(BigInt *result, int n);
void factorialBigInt(BigInt *result, int n);

#endif // BIGINT_H
