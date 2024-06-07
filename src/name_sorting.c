#include <stdio.h>

char name[50][39], temp[39]; // Global variables to store names

/**
 * @brief Sorts names entered by the user.
 */
void name_sorting() {
    int number_of_names;
    printf("\nHow many names do you want to enter? (max 50, min 1)\n");
    scanf("%d", &number_of_names);
    printf("\nEnter %i names\n", number_of_names);

    // Getting names from user
    for (int l = 0; l <= number_of_names; l++) {
        gets(name[l]);
    }

    // Convert to lowercase and uppercase first letter of each word
    for (int row = 0; row <= 50; row++) {
        for (int column = 0; column < 39; column++) {
            if (name[row][column] >= 'A' && name[row][column] <= 'Z') {
                name[row][column] = name[row][column] + ('a' - 'A');
            }
        }

        for (int letter = 0; letter < 39; letter++) {
            if ((letter == 0 || name[row][letter - 1] == ' ') && (name[row][letter] >= 'a' && name[row][letter] <= 'z')) {
                name[row][letter] =  name[row][letter] - ('a' - 'A');
            }
        }
    }

    // Sort the names
    for (int i = 0; i <= number_of_names - 1; i++) {
        for (int letter = i + 1; letter <= number_of_names; letter++) {
            if (strcmp(name[i], name[letter]) > 0) {
                for (int letter_first_switch = 0; letter_first_switch < 39; letter_first_switch++) {
                    temp[letter_first_switch] = name[i][letter_first_switch];
                }

                for (int letter_second_switch = 0; letter_second_switch < 39; letter_second_switch++) {
                    name[i][letter_second_switch] = name[letter][letter_second_switch];
                }

                for (int letter_third_switch = 0; letter_third_switch < 39; letter_third_switch++) {
                    name[letter][letter_third_switch] = temp[letter_third_switch];
                }
            }
        }
    }

    // Print sorted names
    for (int k = 0; k <= number_of_names; k++) {
        printf("%s\n", name[k]);
    }
}

int main() {
    name_sorting(); // Call the sorting function
    return 0;
}
