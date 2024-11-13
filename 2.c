#include <stdio.h>
#include <string.h>


int is_prime(int number) {
    if (number <= 1) return 0;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}

int number_of_words(char str[]) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int nth_word_length(char str[], int n) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        if (count == n) {
            return strlen(token);
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int is_spell(char str[]) {

    char copy1[100], copy2[100];
    strcpy(copy1, str);
    strcpy(copy2, str);

    int num_words = number_of_words(copy1);

    for (int i = 1; i <= num_words; i++) {
        int word_len = nth_word_length(copy2, i);
        if (word_len > 9) return 0;
    }


    int concatenated_number = 0;
    strcpy(copy1, str);
    for (int i = 1; i <= num_words; i++) {
        int word_len = nth_word_length(copy1, i);
        concatenated_number = concatenated_number * 10 + word_len;
    }
    return is_prime(concatenated_number);
}

int main() {
    char input[100];


    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    if (is_spell(input)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}


