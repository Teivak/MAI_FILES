//main.c
#include <stdio.h>

int isInArea(int i, int j) {

    int dist = (i - 10) * (i - 10) + (j - 10) * (j - 10);

    if (dist > 25 && dist < 100) return 1;
    else return 0;
}


int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}


int sign(int n) {
    if (n < 0) return -1;
    else if (n > 0) return 1;
    else return 0;
}


int abs(int n) {
    return sign(n) * n;
}


int mod(int a, int b) {
    int remainder = a % b;
    if (remainder < 0) {
        remainder += b;
    }
    return remainder;
}


int main() {
    int i = 0;
    int j = -3;
    int l = -7;

    int k = 0;
    int max_val = max(i * j, j * l);

    while (!isInArea(i, j) && k <= 50) {
        i = abs(i - j + l) / (3 - sign(i - j + k)) + 10;
        j = abs(i + j - l) / (3 - sign(j - i + k)) + 10;
        l = mod((max_val * (k + 1)), 40);

        max_val = max(i * j, j * l);
        k++;
        //printf("Step %d: i=%d, j=%d, l=%d\n", k, i, j, l);
    }

    if (isInArea(i, j)) {
        printf("Попадание в заданную область плоскости не более чем за 50 шагов!\n\n");
        printf("Время окончания движения: %d\n", k);
    } else {
        printf("Промах. Количество шагов превысило 50...\n\n");
    }
    
    printf("Конечные координаты точки:\n");
    printf("\t\ti: %d\n", i);
    printf("\t\tj: %d\n", j);
    printf("Значение динамического параметра движения (l): %d\n", l);

    return 0;
}

