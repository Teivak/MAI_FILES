//main.c
#include <stdio.h>

long long int stupid_pow(int a, int b) {
    if (b == 0) { return 1; }
    long long int res = 1;
    for (b--; b > 0; b--) {
        res *= a;
    }
    return res;
}


long long int switch_digits(long long int num) {
    if ((num / 1000 < 10 && num / 1000 > 0) || (num < 100 && num >= 0)) { 
        return num; 
    }
    else if (num / 100 < 10 && num / 100 > 0) { 
        return ((num / 10) % 10) * 100 + (num / 100) * 10 + num % 10; 
    } 

    long long int res = 0;
    int p = 1;
    long long int div;
    
    while (num > stupid_pow(10, p + 1)) { p++; }
    div = stupid_pow(10, p);

    res += (num / div) * div;
    div /= 10;

    int bef_last = (num / div) % 10;
    res += ((num / 10) % 10) * div;

    res += ((num % div) / 100) * 100;
    res += bef_last * 10 + num % 10;

    return res;
}


int main() {
    long long int num;
    while (1) {
        scanf("%lli", &num);
        if (num == -1) {
            break;
        }
        if (num < 0) { printf("%lli\n\n", -switch_digits(-num)); }
        else { printf("%lli\n\n", switch_digits(num)); }
    }
    return 0;
}