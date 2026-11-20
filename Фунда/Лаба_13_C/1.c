#include <stdio.h>

unsigned int GetUnicode() {
    unsigned int c = getchar();
    if (c == EOF) {
        return EOF;
    }
    if ((c >> 7) == 0) {
        return c;
    }

    if ((c >> 5) == 6u) {
        return ((((1u << 5) - 1u) & c) << 6) | (((1u << 6) - 1u) & getchar());
    }

    // дописать для трех и четырех байт
    return c;
}

void PutUnicode(unsigned int c) {
    if (c <= 0x7F) {
        putchar(c);
    } else if (c <= 0x7FF) {
        putchar((c >> 6) | (6 << 5));
        putchar((c & ((1u << 6) - 1)) | (1 << 7));
    }
    // дописать для трех и четырех байт
}

unsigned int ToUnicode(const char *text) {
    const unsigned char *utext = (unsigned char *)text;
    unsigned int c = utext[0];
    if (c == EOF) {
        return EOF;
    }
    if ((c >> 7) == 0) {
        return c;
    }

    if ((c >> 5) == 6u) {
        return ((((1u << 5) - 1u) & c) << 6) | (((1u << 6) - 1u) & utext[1]);
    } 
    // дописать для трех и четырех байт
    return c;

}
