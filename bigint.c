// src/bigint.c
#include "bigint.h"
#include <string.h>
#include <stdio.h>

// Initialize BigInt from a string
void initBigInt(BigInt *num, const char *str) {
    num->length = strlen(str);
    for (int i = 0; i < num->length; i++) {
        num->digits[i] = str[num->length - i - 1] - '0';
    }
}

// Compare two BigInt numbers
int compareBigInt(const BigInt *a, const BigInt *b) {
    if (a->length > b->length) return 1;
    if (a->length < b->length) return -1;
    for (int i = a->length - 1; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) return 1;
        if (a->digits[i] < b->digits[i]) return -1;
    }
    return 0;
}

// Add two BigInt numbers
void addBigInt(BigInt *result, const BigInt *a, const BigInt *b) {
    int carry = 0, i;
    result->length = (a->length > b->length) ? a->length : b->length;
    for (i = 0; i < result->length; i++) {
        int sum = (i < a->length ? a->digits[i] : 0) + (i < b->length ? b->digits[i] : 0) + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) result->digits[result->length++] = carry;
}

// Subtract two BigInt numbers (assume a > b)
void subtractBigInt(BigInt *result, const BigInt *a, const BigInt *b) {
    int borrow = 0;
    result->length = a->length;
    for (int i = 0; i < result->length; i++) {
        int diff = a->digits[i] - (i < b->length ? b->digits[i] : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result->digits[i] = diff;
    }
    while (result->length > 1 && result->digits[result->length - 1] == 0) result->length--;
}

// Multiply two BigInt numbers
void multiplyBigInt(BigInt *result, const BigInt *a, const BigInt *b) {
    memset(result->digits, 0, sizeof(result->digits));
    result->length = a->length + b->length;
    for (int i = 0; i < a->length; i++) {
        int carry = 0;
        for (int j = 0; j < b->length || carry; j++) {
            int product = result->digits[i + j] + a->digits[i] * (j < b->length ? b->digits[j] : 0) + carry;
            result->digits[i + j] = product % 10;
            carry = product / 10;
        }
    }
    while (result->length > 1 && result->digits[result->length - 1] == 0) result->length--;
}

void fibonacciBigInt(BigInt *result, int n) {
    BigInt a, b;
    initBigInt(&a, "0");
    initBigInt(&b, "1");

    for (int i = 2; i <= n; i++) {
        addBigInt(result, &a, &b);
        a = b;
        b = *result;
    }
}

void factorialBigInt(BigInt *result, int n) {
    initBigInt(result, "1");
    for (int i = 2; i <= n; i++) {
        BigInt temp;
        char buffer[5];
        sprintf(buffer, "%d", i);
        initBigInt(&temp, buffer);
        multiplyBigInt(result, result, &temp);
    }
}


