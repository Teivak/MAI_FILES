//main.c
#include <stdio.h>
// Hello, 1234, -3\n57 2jlk345,650\t\n


int stupid_pow(int a, int b) {
    int res = 1;
    if (b == 0) {return 1; }
    for(b--; b > 0; b--) {
        res *= a;
    }
    return res;
}


int print_in_bin(int n) {
    int power = 0;
    while (n > stupid_pow(10, power + 1)) { 
        power++; 
    }

    int d = n / stupid_pow(10, power);
    printf("%d: ", n);

    for (power; power > 0; power--) {
        switch (d) {
            case 0: printf("00%d ", 0); break;
            case 1: printf("00%d ", 1); break;
            case 2: printf("0%d ", 10); break;
            case 3: printf("0%d ", 11); break;
            case 4: printf("%d ", 100); break;
            case 5: printf("%d ", 101); break;
            case 6: printf("%d ", 110); break;
            case 7: printf("%d ", 111); break;
        }

        n %= stupid_pow(10, power);
        d = n / stupid_pow(10, power - 1);
    }

    printf("\n");
    return 0;
}


int main() {
    int num = 0;
    int pos_target = 1;
    int slash = 0;
    char c = getchar();

    while (c != EOF) {
        if (c == ',' || c == ' ' || (slash && (c == 't' || c == 'n'))) {
            if (num != 0) {
                print_in_bin(num);
                num = 0;
            }
            pos_target = 1;
            slash = 0;
        } 

        else if (c >= 48 && c <= 55 && pos_target) {
            num *= 10;
            num += c - 48;
            slash = 0;
        }

        else if (c == '\\') {
            slash = 1;
        }

        else {
            num = 0;
            pos_target = 0;
            slash = 0;
        }
        c = getchar();

    }

    return 0;
}