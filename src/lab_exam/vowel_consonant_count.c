/**
 * Counts the number of vowels and consonants in a string.
 * @param a - The string to analyze.
 */
void ptr_vc(char *a) {
    int vowels = 0, consonants = 0;
    for (; *a != '\0'; a++) {
        if (*a >= 'A' && *a <= 'Z') {
            *a += 32; // Convert uppercase to lowercase
        }
        if (*a >= 'a' && *a <= 'z') {
            if (*a == 'a' || *a == 'e' || *a == 'i' || *a == 'o' || *a == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}
