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
    int r = a % b;
    if (r < 0) {
        r += b;
        return r;
    }
}


int main() {
    int i0 = 0;
    int j0 = -3;
    int l0 = -7;

    int k = 0;
    int i, j, l;

    while (!isInArea(i0, j0) && k <= 50) {
        i = abs(i0 - j0 + l0) / (3 - sign(i0 - j0  + k)) + 10;
        j = abs(i0 + j0 - l0) / (3 - sign(j0  - i0 + k)) + 10;
        l = mod(max(i0 * j0, j0 * l0) * (k + 1), 40);
        k++;

        printf("Step %d: i=%d, j=%d, l=%d\n", k, i, j, l);

        i0 = i;
        j0 = j;
        l0 = l;
    }   

    if (isInArea(i0, j0)) {
        printf("Попадание в заданную область плоскости не более чем за 50 шагов.\n\n");
        printf("Время окончания движения (k): %d\n", k);
    } else {
        printf("Промах. Количество шагов превысило 50...\n\n");
    }
    
    printf("Конечные координаты точки:\n");
    printf("\t\ti: %d\n", i);
    printf("\t\tj: %d\n", j);
    printf("Значение динамического параметра движения (l): %d\n", l);
    return 0;
}

