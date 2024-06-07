#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
struct student {
    char name[30];
    int prn;
    char div;
};

// Function to input and write student information to a file
void inputStudentInfo(void) {
    struct student s[2];
    FILE *fp;

    fp = fopen("student_records.txt", "w");
    for (int i = 0; i < 2; i++) {
        printf("\nEnter name: ");
        fgets(s[i].name, 30, stdin);

        printf("Enter PRN: ");
        scanf("%i", &s[i].prn);
        getchar(); // Consume newline

        printf("Enter division: ");
        scanf("%c", &s[i].div);
        getchar(); // Consume newline

        fwrite(&s[i], sizeof(struct student), 1, fp);
    }
    fclose(fp);
}

// Function to read and display student information from a file
void displayStudentInfo(void) {
    struct student r[2];
    FILE *fp;

    printf("\nStudent info:\n");
    fp = fopen("student_records.txt", "r");
    for (int j = 0; j < 2; j++) {
        fread(&r[j], sizeof(struct student), 1, fp);
        printf("Name: %s", r[j].name);
        printf("PRN: %i\n", r[j].prn);
        printf("Division: %c\n\n", r[j].div);
    }
    fclose(fp);
}

int main() {
    inputStudentInfo();
    displayStudentInfo();
    return 0;
}
