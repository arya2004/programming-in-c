#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct representing a student
struct student {
    int roll_no;
    char name[30];
    float marks;
};

// Function to display student information
void display(struct student s[100], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n%3d\t%3d\t%-30s\t%10.2f", i + 1, s[i].roll_no, s[i].name, s[i].marks);
    }
}

// Function to add new students
int add(struct student *s, int n) {
    int m;
    printf("Enter the number of students to add: ");
    scanf("%d", &m);

    for (int i = n; i < n + m; i++) {
        printf("\nEnter information about student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d%*c", &s[i].roll_no);
        printf("Name: ");
        gets(s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    return n + m;
}

// Function to sort students by roll number
void sortby_rollno(struct student *s, int n) {
    int lasti = n - 2;

    for (int pass = 1; pass < n; pass++) {
        int flag = 0;

        for (int i = 0; i <= lasti; i++) {
            if (s[i].roll_no > s[i + 1].roll_no) {
                struct student temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                flag = 1;
            }
        }

        lasti--;

        if (flag == 0) {
            break;
        }
    }
}

// Function to sort students by marks
void sortby_marks(struct student *s, int n) {
    int lasti = n - 2;

    for (int pass = 1; pass < n; pass++) {
        int flag = 0;

        for (int i = 0; i <= lasti; i++) {
            if (s[i].marks < s[i + 1].marks) {
                struct student temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                flag = 1;
            }
        }

        lasti--;

        if (flag == 0) {
            break;
        }
    }
}

// Function to sort students by name
void sortby_name(struct student *s, int n) {
    int lasti = n - 2;

    for (int pass = 1; pass < n; pass++) {
        int flag = 0;

        for (int i = 0; i <= lasti; i++) {
            if (strcmp(s[i].name, s[i + 1].name) > 0) {
                struct student temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                flag = 1;
            }
        }

        lasti--;

        if (flag == 0) {
            break;
        }
    }
}

// Function to remove a student
int Remove(struct student *s, int n) {
    display(s, n);
    int d;

    printf("\nEnter the serial number/record number to be deleted: ");
    scanf("%d", &d);

    if (d < 1 || d > n) {
        return n;
    }

    if (d == n) {
        return n - 1;
    }

    s[d - 1] = s[n - 1];
    return n - 1;
}

// Function to store student information to a file
void storeToFile(struct student *s, int n) {
    FILE *a;
    a = fopen("student_records.txt", "wt");

    for (int i = 0; i < n; i++) {
        fprintf(a, "\n%i", s[i].roll_no);
        fprintf(a, "\n%s", s[i].name);
        fprintf(a, "\n%f", s[i].marks);
    }

    fclose(a);
}

// Function to retrieve student information from a file
int retrieveFromFile(struct student *s) {
    FILE *a;
    a = fopen("student_records.txt", "rt");

    int count = 0;
    while (fscanf(a, "%i", &s[count].roll_no) != EOF) {
        fscanf(a, "%s", &s[count].name);
        fscanf(a, "%f", &s[count].marks);
        count++;
    }

    fclose(a);
    return count;
}

int main() {
    struct student s[100] = {{5, "arya_pathak", 40}, {3, "zeiger_cat", 36}, {8, "catalyst_catt", 64}, {1, "tsgdf_sgereg", 55}, {10, "aadhf_weaf", 37}};
    int n = 5;
    int choice;

    while (1) {
        printf("\n1. Add\n2. Sort by Roll No\n3. Sort by Name\n4. Sort by Marks\n5. Store to File\n6. Retrieve from File\n7. Remove\n0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = add(s, n);
                break;
            case 2:
                sortby_rollno(s, n);
                display(s, n);
                break;
            case 3:
                sortby_name(s, n);
                display(s, n);
                break;
            case 4:
                sortby_marks(s, n);
                display(s, n);
                break;
            case 5:
                storeToFile(s, n);
                break;
            case 6:
                n = retrieveFromFile(s);
                display(s, n);
                break;
            case 7:
                n = Remove(s, n);
                display(s, n);
                break;
            case 0:
                exit(0);
        }
    }

    return 0;
}
