//main.c
#include <stdio.h>
#include "labfuncs.h"

int main() {
    int i0 = 0;
    int j0 = -3;
    int l0 = -7;

    int k = 0;
    int i, j, l;

    while (!isInArea(i0, j0) && k <= 50) {
        i = abs(i0 - j0 + l0) / (3 - sign(i0 - j0  + k)) + 10;
        j = abs(i0 + j0 - l0) / (3 - sign(j0  - i0 + k)) + 10;
        l = (max(i0 * j0, j0 * l0) * (k + 1)) % 40;
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

