#include <stdio.h>

// Function to read and display integers and characters from a file
void readIntAndCharFromFile(void) {
    FILE *a;
    int z;

    a = fopen("numbers_and_chars.txt", "rt");
    if (a == NULL) {
        printf("ERROR: File not found!\n");
        return;
    }

    while (fread(&z, sizeof(z), 1, a)) {
        printf("\n%i  %c", z, z);
    }

    fclose(a);
}

// Function to write characters to a file
void writeCharsToFile(void) {
    FILE *a;
    a = fopen("chars_to_file.txt", "wt");
    if (a == NULL) {
        printf("ERROR: Unable to create file!\n");
        return;
    }

    fputc('a', a);
    fputc('b', a);
    fputc('c', a);
    fputc('\n', a);
    fputc('D', a);
    fputc('E', a);
    fputc('F', a);
    fputc('\n', a);

    fclose(a);
}

// Function to copy contents from one file to another
void copyFileContents(void) {
    FILE *source, *destination;
    char c;

    source = fopen("source_file.txt", "rt");
    destination = fopen("destination_file.txt", "wt");

    if (source == NULL || destination == NULL) {
        printf("ERROR: Unable to open files!\n");
        return;
    }

    while ((c = fgetc(source)) != EOF) {
        fputc(c, destination);
    }

    fclose(source);
    fclose(destination);
}

// Function to read and display a line from a file
void readLineFromFile(void) {
    FILE *a;
    char line[100];

    a = fopen("line_from_file.txt", "rt");
    if (a == NULL) {
        printf("ERROR: File not found!\n");
        return;
    }

    fgets(line, sizeof(line), a);
    printf("%s", line);

    fclose(a);
}

// Function to write multiple lines to a file
void writeMultipleLinesToFile(void) {
    FILE *a;
    a = fopen("multiple_lines.txt", "wt");
    if (a == NULL) {
        printf("ERROR: Unable to create file!\n");
        return;
    }

    fputs("First line\n", a);
    fputs("Second line\n", a);
    fputs("Third line\n", a);
    fputs("Fourth line\n", a);

    fclose(a);
}

// Function to convert decimal to binary recursively
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    decimalToBinary(decimal / 2);
    printf("%d", decimal % 2);
}

int main() {
    readIntAndCharFromFile();
    writeCharsToFile();
    copyFileContents();
    readLineFromFile();
    writeMultipleLinesToFile();
    decimalToBinary(10); // Example decimal value for conversion
    return 0;
}
