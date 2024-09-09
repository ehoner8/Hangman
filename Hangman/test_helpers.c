#include "hangman_helpers.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sec1[] = "qwertyyuiopaasdfghhjkklzxccvbbnm";
char sec2[] = "giguljRguigui";
char sec3[] = "li5gj";
char sec4[] = "- '  -";
char sec5[] = "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";


int main(void) {
    printf("Testing is_lowercase_letter()\n");
    if (is_lowercase_letter('T') == true){
	    printf("Invalid output in is_lowercase_letter().\n");
	    return 1;
    }
    if (is_lowercase_letter('5') == true){
	    printf("Invalid output in is_lowercase_letter().\n");
	    return 1;
    }
    if (is_lowercase_letter('<') == true){
	    printf("Invalid output in is_lowercase_letter().\n");
	    return 1;
    }
    if (is_lowercase_letter('u') == false){
	    printf("Invalid output in is_lowercase_letter().\n");
    }
    printf("is_lowercase_letter passed.\n");
    printf("Testing string_contains_character().\n");
    if (string_contains_character("abc", 'a') == false){
	    printf("1Invalid output in string_contains_character().\n");
	    return 1;
    }
    if (string_contains_character("def", 'k') == true){
	    printf("2Invalid output in string_contains_character().\n");
	    return 1;
    }
    if (string_contains_character ("yyy", 'y') == false){
	    printf("3Invalid output in string_contains_character().\n");
	    return 1;
    }
    printf("string_contains_character() passed.\n");
    printf("Testing validate_secret().\n");
    if (validate_secret(sec1) == false){
	    printf("Invalid output in string_contains_character().\n");
	    return 1;
    }
    if (validate_secret(sec2) == true){
	    printf("Invalid output in string_contains_character().\n");
	    return 1;
    }
    if (validate_secret(sec3) == true){
	    printf("Invalid output in string_contains_character().\n");
	    return 1;
    }
    if (validate_secret(sec4) == false){
	    printf("Invalid output in string_contains_character().\n");
	    return 1;
    }
    if (validate_secret(sec5) == true){
	    printf("Invalid output in string_contains_character().\n");
	    return 1;
    }
    printf("validate_secret() passed.\n");
    printf("All tests passed.\n");
    return 0;


}
