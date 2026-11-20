#include <stdio.h>
#include "1.c"

// YES
//    Во этом предложении,вО\n каждОм\n слове SоderjitsА╥ БYKво О
// NO
//    Во этом предл|жении,вО\n каждОм\n слове SоderjitsА╥ БYKво О

int isLetter(unsigned int sym) {
    return ((ToUnicode("А") <= sym && sym <= ToUnicode("я")) || (sym == ToUnicode("Ё") || (sym == ToUnicode("ё"))));
}


unsigned int putVowel(unsigned int c, unsigned int word_vowels) {
    unsigned char pos;
    if ((c == ToUnicode("А")) || (c == ToUnicode("а"))) { pos = 0; }
    else if ((c == ToUnicode("Е")) || (c == ToUnicode("е"))) { pos = 1; }
    else if ((c == ToUnicode("Ё")) || (c == ToUnicode("ё"))) { pos = 2; }
    else if ((c == ToUnicode("И")) || (c == ToUnicode("и"))) { pos = 3; }
    else if ((c == ToUnicode("О")) || (c == ToUnicode("о"))) { pos = 4; }
    else if ((c == ToUnicode("У")) || (c == ToUnicode("у"))) { pos = 5; }
    else if ((c == ToUnicode("Ы")) || (c == ToUnicode("ы"))) { pos = 6; }
    else if ((c == ToUnicode("Э")) || (c == ToUnicode("э"))) { pos = 7; }
    else if ((c == ToUnicode("Ю")) || (c == ToUnicode("ю"))) { pos = 8; }
    else if ((c == ToUnicode("Я")) || (c == ToUnicode("я"))) { pos = 9; }
    else { return word_vowels; }

    return word_vowels | (1u << pos);
}      


int main() {
    // vowels bit mask
    // я ю э ы у о и ё е а
    // 9 8 7 6 5 4 3 2 1 0
    unsigned int vowels = (1u << 10) - 1u;
    unsigned int word_vowels = 0u;
    unsigned int c;
    int readingWord = 0;

    while ((c = GetUnicode()) != EOF) {
        if (isLetter(c)) {
            readingWord = 1;
            word_vowels = putVowel(c, word_vowels);
        }
        else if ((c == ToUnicode("\t")) || (c == ToUnicode(" ")) || (c == ToUnicode("\n")) || (c == ToUnicode(","))) {
            if (readingWord) { vowels &= word_vowels; }
            readingWord = 0;
            word_vowels = 0u;
        }
        else {
            readingWord = 1;
        }
    }

    if (readingWord) { vowels &= word_vowels; }

    if (vowels != 0) { printf("YES"); }
    else { printf("NO"); }
    return 0;
}