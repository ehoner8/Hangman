#include "hangman_helpers.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alph[26] = "abcdefghijklmnopqrstuvwxyz";

bool is_lowercase_letter(char c) {
    //alph = "abcdefghijklmnopqrstuvwxyz";
    if (strchr(alph, c) != NULL) {
        return true;
    } else {
        return false;
    }
}

char legit_chars[29] = "abcdefghijklmnopqrstuvwxyz -'";
int i;
int word_length;
unsigned long word_length_l;
unsigned long qq;

bool validate_secret(const char *secret) {
    if ((int) (strlen(secret)) > MAX_LENGTH) {
        printf("the secret phrase is over 256 characters\n");
        return false;
    }
    //legit_chars = "abcdefghijklmnopqrstuvwxyz -'";
    word_length = 0;
    word_length_l = strlen(secret);
    for (qq = 0; qq < word_length_l; qq++) {
        word_length += 1;
    }
    for (i = 0; i < word_length; i++) {
        if (strchr(legit_chars, secret[i]) == NULL) {
            printf("invalid character: '%c'\n", secret[i]);
            printf("the secret phrase must contain only lowercase letters, spaces, hyphens, and "
                   "apostrophes\n");
            return false;
        }
    }
    return true;
}

bool string_contains_character(const char *s, char c) {
    if (strchr(s, c) != NULL) {
        return true;
    } else {
        return false;
    }
}

char g;

char read_letter(void) {
    /*    printf("Guess a letter: ");
    //g = (char) getchar();
    scanf(" %c", &g);
    return g; */

    printf("Guess a letter: ");
    do {
        g = (char) getchar();
    } while (g == '\n');
    if (g == EOF) {
        return g;
    }
    return g;
}
