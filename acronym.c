#include "acronym.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// # Instructions
// Convert a phrase to its acronym.
// Techies love their TLA (Three Letter Acronyms)!
// Help generate some jargon by writing a program that converts a long name like
// Portable Network Graphics to its acronym (PNG). Punctuation is handled as
// follows: hyphens are word separators (like whitespace); all other punctuation
// can be removed from the input. For example:
//
// |Input                       |Output |
// |-                           |-      |
// |As Soon As Possible         |ASAP   |
// |Liquid-crystal display      |LCD    |
// |Thank George It's Friday!   |TGIF   |
char *abbreviate(const char *phrase) {
    if (!phrase || !(*phrase)) {
        return NULL;
    }

    int len = strlen(phrase);
    char *acr = (char *)malloc(len + 1);
    acr[0] = phrase[0];
    acr[1] = '\0';
    for (int i = 0; i < len; i++) {
        if (phrase[i] == ' ' || phrase[i] == '-') {
            int c_len = strlen(acr);
            if (islower(phrase[i + 1])) {
                acr[c_len] = phrase[i + 1] - 32;
            } else {
                acr[c_len] = phrase[i + 1];
            }
            acr[c_len + 1] = '\0';
        }
    }

    return acr;
}

// int main(void) {
    // char a[] = "Hello World!";
    // char b[] = "As Soon As Possible";
    // char c[] = "Liquid-crystal display";
    // char d[] = "Thank George It's Friday!";
    //
    // char *r = abbreviate(a);
    // if (strcmp(" ", " ") == 0) {
    //     printf("WOHAAA");
    // }
    // printf("%s\n", r);
    // return 0;
// }
