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