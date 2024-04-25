/**********
Project Name: Student Management System (CLI)
Description: Simple CLI program to manage pseudo student info
***********/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Initialize student number for addition to the student array
int i = 0;

// Structure for holding information about each of the students
struct sinfo {
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid[10];
} st[55];


// Collecting user data
void add_student() {
    printf("-----------------------------------------------");
    printf("\nAdding a student...\n");
    printf("Add the Students Details\n");
    printf("\nEnter the first name of student > ");
    scanf("%s", st[i].fname);
    printf("Enter the last name of student > ");
    scanf("%s", st[i].lname);
    printf("Enter the Roll Number > ");
    scanf("%d", &st[i].roll);
    printf("Enter the CGPA you obtained > ");
    scanf("%f", &st[i].cgpa);
    printf("Enter the course ID of each course > ");
    printf("\n");
    for (int j = 1; j <= 5; j++) {
        printf("\t\tCourse %d: ", j);
        scanf("%d", &st[i].cid[j-1]);
    }
    i = i + 1;
    printf("-----------------------------------------------");
    printf("\nCurrent number of students: %d", i);
    printf("\n-----------------------------------------------");
}

// For printing out student info
void print_studinfo(int num) {
    printf("\n\n[+] Found student...");
    printf("\nName of student: %s %s", st[num].fname, st[num].lname);
    printf("\nRoll ID: %d", st[num].roll);
        printf("\nCGPA Of student: %.1f", st[num].cgpa);
        for (int k = 0; k < 5; k++) {
            printf("\nCourse ID registered: %d", st[num].cid[k]);
        }
}

// Search for student using Roll ID
void find_roll() {
    printf("-----------------------------------------------");
    printf("\n[+] Finding a student...");
    int x;
    printf("\nEnter the roll ID you want to search for: ");
    scanf("%d", &x);
    for (int j = 0; j <= i; j++) {
        if (x == st[j].roll) {
            print_studinfo(j);
        }
    }
    printf("\n-----------------------------------------------");
}

// Search for student by first name
void find_fname() {
    printf("-----------------------------------------------");
    char sname[50];
    printf("\n[+] Finding a student...");
    printf("\nEnter the first name of student you want to search for: ");
    scanf("%s", &sname);
    for (int j = 0; j <= i; j++) {
        if (!strcmp(sname, st[j].fname)) {
            print_studinfo(j);
        }
    }
    printf("\n-----------------------------------------------");
}

// Find student based on registered courses
void find_course() {
    printf("-----------------------------------------------");
    int course_id;
    printf("\n[+] Finding a student...");
    printf("\nEnter the course id you want to search match: ");
    scanf("%d", &course_id);
    for (int j = 0; j <= i; j++) {
        for (int k = 0; k < 5; k++) {
            if (course_id == st[j].cid[k]) {
                print_studinfo(j);
            }
        }
    }
    printf("\n-----------------------------------------------");
}

void total_studs() {
    printf("-----------------------------------------------\n");
    printf("Total number of registered students: %d", i);
    printf("\n-----------------------------------------------");
}

void del_student() {
    printf("-----------------------------------------------");
    int roll_id;
    printf("\n[+] Deleting a student record...");
    //Printing all students names and their roll ID
    for (int j = 0; j < i; j++) {
        printf("\n[+] Student Name: %s %s, Roll: %d\n", st[j].fname, st[j].lname, st[j].roll);
    }
    printf("\nEnter the roll id you want to delete: ");
    scanf("%d", &roll_id);
    for (int j = 0; j <= i; j++) {
        if (roll_id == st[j].roll) {
            for (int k = j; k < 49; k++) {
                st[k] = st[k + 1];
            }
        }

    }
    i--;
    printf("\n-----------------------------------------------");
}


void update_stud() {
    printf("-----------------------------------------------");
    int roll_id;
    printf("\n[+] Updating a student record...");
    //Printing all students names and their roll ID
    for (int j = 0; j < i; j++) {
        printf("\n[+] Student Name: %s %s, Roll: %d\n", st[j].fname, st[j].lname, st[j].roll);
    }
    printf("\nEnter the roll id you want to update: ");
    scanf("%d", &roll_id);
    char *actions[] = {
        "Update first name",
        "Update last name",
        "Update roll ID",
        "Update CGPA",
        "Update Course IDs"
    };

    for (int j = 0; j < sizeof(actions)/sizeof(actions[0]); j++) {
            printf("[%d] %s\n",j, actions[j]);
    }

    for (int j = 0; j < i; j++) {
        if (roll_id == st[j].roll) {
            print_studinfo(j);
            printf("\n\nMake a choice > ");
        int change_id;
        scanf("%d", &change_id);
        switch (change_id) {
            case 0:
                printf("\nEnter new input for First name: >");
                scanf("%s", &st[j].fname);
                break;
            case 1:
                printf("\nEnter new input for Last name: >");
                scanf("%s", &st[j].lname);
                break;
            case 2:
                printf("\nEnter new input for Roll ID: >");
                scanf("%d", &st[j].roll);
                break;
            case 3:
                printf("\nEnter new input for CGPA: >");
                scanf("%f", &st[j].cgpa);
                break;
            case 4:
                printf("\nEnter new input for Course IDs: >");
                scanf("%d%d%d%d%d", &st[j].cid[0], &st[j].cid[1], &st[j].cid[2], &st[j].cid[3], &st[j].cid[4]);
                break;
            default:
                printf("Option not available");
        }
        print_studinfo(j);
    }
    
    printf("\n-----------------------------------------------");
    }
}


// Driver function
void main () {
    printf("\nWelcome to my simple student management system\nWhat can i do for you today: ");
    char *actions[] = {
        "Add student details", 
        "Find student details by roll number", 
        "Find student details by first name", 
        "Find Student by registered courses",
        "Total number of registered students",
        "Delete student by roll ID",
        "Update student info by roll id",
        "exit"};
    while (1) {
        printf("\n-----------------------------------------------");
        printf("\n\nAction Menu\n");
        printf("-----------\n");
        for (int j = 0; j < sizeof(actions)/sizeof(actions[0]); j++) {
            printf("[%d] %s\n",j, actions[j]);
        }
        int choice;
        printf("Total Number of students: %d", i);
        printf("\n-----------------------------------------------\n");
        printf("Make a choice > ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                add_student();
                break;
            case 1:
                find_roll();
                break;
            case 2:
                find_fname();
                break;
            case 3:
                find_course();
                break;
            case 4:
                total_studs();
                break;
            case 5:
                del_student();
                break;
            case 6:
                update_stud();
                break;
            case 7:
                printf("\n[*] Exiting now...");
                exit(0);
                break;
            default:
                printf("Oops not available yet");
                exit(0);
        }
        

    }
}
