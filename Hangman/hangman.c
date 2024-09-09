#include "hangman_helpers.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("wrong number of arguments\n");
        printf("usage: ./hangman <secret word or phrase>\n");
        printf("if the secret is multiple words, you must quote it\n");
        return 1;
    }
    char secret_word[MAX_LENGTH] = "";
    strcpy(secret_word, argv[1]);
    if (validate_secret(secret_word) == false) {
        exit(1);
    }
    int secret_word_length = (int) (strlen(secret_word));
    //unsigned long secret_word_length_l = strlen(secret_word);
    //unsigned long z;
    //for (z=0; z<secret_word_length_l; z++){
    //      secret_word_length+=1;
    //}
    int finished = 0;
    int repeat = 0;
    char guessed_wrong_letters[LOSING_MISTAKE + 1];
    char guessed_right_letters[secret_word_length + 1];
    for (int e = 0; e < LOSING_MISTAKE; e++){
	    guessed_wrong_letters[e] = ';';
    }
    guessed_wrong_letters[LOSING_MISTAKE] = '\0';
    for (int z = 0; z < secret_word_length; z++){
	    guessed_right_letters[z] = ';';
    }
    guessed_right_letters[secret_word_length] = '\0';
    int num_of_guessed_wrong_letters = 0;
    int num_of_guessed_right_letters = 0;

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int another_counter;
    char l;
    int tc;
    int fc;

    for (fc = 0; fc < secret_word_length; fc++) {
        if (secret_word[fc] == ' ') {
            guessed_right_letters[num_of_guessed_right_letters] = ' ';
            num_of_guessed_right_letters += 1;
        }
        if (secret_word[fc] == '\'') {
            guessed_right_letters[num_of_guessed_right_letters] = '\'';
            num_of_guessed_right_letters += 1;
        }
        if (secret_word[fc] == '-') {
            guessed_right_letters[num_of_guessed_right_letters] = '-';
            num_of_guessed_right_letters += 1;
        }
    }
    if (num_of_guessed_right_letters == secret_word_length){
	printf(CLEAR_SCREEN);
	printf("%s\n\n", arts[0]);
	printf("    Phrase: ");
	printf("\n");
        printf("Eliminated: ");
	printf("\n\n");
        printf("You win! The secret phrase was: %s\n", secret_word);
	return 0;

    }
    while (finished == 0) {
        printf(CLEAR_SCREEN);
        printf("%s\n\n", arts[num_of_guessed_wrong_letters]);
        printf("    Phrase: ");
        int pc;
        for (pc = 0; pc < secret_word_length; pc++) {
            if (string_contains_character(guessed_right_letters, secret_word[pc])) {
                printf("%c", secret_word[pc]);
            } else {
                printf("_");
            }
        }
        printf("\n");
        printf("Eliminated: ");

        for (another_counter = 0; another_counter < 26; another_counter++) {
            if (string_contains_character(guessed_wrong_letters, alphabet[another_counter])) {
                printf("%c", alphabet[another_counter]);
            }
        }
        another_counter = 0;
        printf("\n\n");

        while (repeat == 0) {
            l = read_letter();
            if (!(string_contains_character(guessed_right_letters, l)
                    || string_contains_character(guessed_wrong_letters, l))
                && (is_lowercase_letter(l))) {
                repeat = 1;
            }
        }
        repeat = 0;
        for (tc = 0; tc < secret_word_length; tc++) {
            if (l == secret_word[tc]) {
                guessed_right_letters[num_of_guessed_right_letters] = l;
                num_of_guessed_right_letters += 1;
            }
        }

        tc = 0;

        if (!(string_contains_character(secret_word, l))) {
            guessed_wrong_letters[num_of_guessed_wrong_letters] = l;
            num_of_guessed_wrong_letters += 1;
        }

        if (num_of_guessed_right_letters == secret_word_length) {
            printf(CLEAR_SCREEN);
            printf("%s\n\n", arts[num_of_guessed_wrong_letters]);
            printf("    Phrase: ");
            printf("%s\n", secret_word);
            printf("Eliminated: ");
            for (another_counter = 0; another_counter < 26; another_counter++) {
                if (string_contains_character(guessed_wrong_letters, alphabet[another_counter])) {
                    printf("%c", alphabet[another_counter]);
                }
            }
            printf("\n\n");
            printf("You win! The secret phrase was: %s\n", secret_word);
            return 0;
        }
        if (num_of_guessed_wrong_letters == LOSING_MISTAKE) {
            printf(CLEAR_SCREEN);
            printf("%s", arts[6]);
            printf("\n\n");
            printf("    Phrase: ");
            for (pc = 0; pc < secret_word_length; pc++) {
                if (string_contains_character(guessed_right_letters, secret_word[pc])) {
                    printf("%c", secret_word[pc]);
                } else {
                    printf("_");
                }
            }
            printf("\n");
            printf("Eliminated: ");
            for (another_counter = 0; another_counter < 26; another_counter++) {
                if (string_contains_character(guessed_wrong_letters, alphabet[another_counter])) {
                    printf("%c", alphabet[another_counter]);
                }
            }
            printf("\n\n");
            printf("You lose! The secret phrase was: %s\n", secret_word);
            return 0;
        }
    }

    return 0;
}
