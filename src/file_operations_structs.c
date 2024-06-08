#include <stdio.h>

// Define a struct for student information
struct Student {
    int prn;
    char name[30];
    float cgpa;
    char division;
};

// Function to read and write student data to a file
void readWriteStudentData() {
    struct Student students[2], studentsRead[2];
    FILE *fileWrite, *fileRead;
    fileWrite = fopen("student_data.txt", "w");

    for (int i = 0; i < 2; i++) {
        printf("Enter name of student %i: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter PRN of student %i: ", i + 1);
        scanf("%i", &students[i].prn);
        printf("Enter CGPA of student %i: ", i + 1);
        scanf("%f", &students[i].cgpa);
        printf("Enter division of student %i: ", i + 1);
        scanf(" %c", &students[i].division); // Note the space before %c to consume the newline character

        fwrite(&students[i], sizeof(struct Student), 1, fileWrite);
    }

    fclose(fileWrite);

    fileRead = fopen("student_data.txt", "r");

    for (int i = 0; i < 2; i++) {
        fread(&studentsRead[i], sizeof(struct Student), 1, fileRead);
        printf("Name: %s, PRN: %i, CGPA: %f, Division: %c\n",
               studentsRead[i].name, studentsRead[i].prn,
               studentsRead[i].cgpa, studentsRead[i].division);
    }

    fclose(fileRead);
}

// Main function
int main() {
    readWriteStudentData();
    return 0;
}
