#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char sentence[500], *word;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++)
        sentence[i] = tolower(sentence[i]);

    word = strtok(sentence, " \n");
    while (word != NULL) {
        int len = strlen(word);
        char last_char = '\0';
        if (ispunct(word[len - 1])) {
            last_char = word[len - 1];
            word[len - 1] = '\0';
        }
        if (strchr("aeiou", word[0]))
            printf("%syay", word);
        else {
            int consonant_count = 0;
            while (consonant_count < len && !strchr("aeiou", word[consonant_count]))
                consonant_count++;
            printf("%s%say", word + consonant_count, strndup(word, consonant_count));
        }
        if (last_char != '\0')
            printf("%c", last_char);
        printf(" ");
        word = strtok(NULL, " \n");
    }

    return 0;
}