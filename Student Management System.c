#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100

struct Student
{
    char name[50];
    int rollNumber;
    char class[10];
    char section;
};

void Studentadd(struct Student students[], int *count);
void Studentdisplay(struct Student students[], int count);

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                Studentadd(students,&count);
                break;
            case 2:
               Studentdisplay(students,count);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid.Please enter a number between 1 and 3.\n");
        }
    } while (choice != 3);
    return 0;
}

void Studentadd(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Maximum number of students reached.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter name of the student : ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter roll number : ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter class : ");
    scanf("%s", newStudent.class);
    printf("Enter section : ");
    scanf(" %c",&newStudent.section);

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully.\n");
}

void Studentdisplay(struct Student students[],int count)
{
    if (count==0)
    {
        printf("No students to show.\n");
        return;
    }

    printf("Student List\n");
    printf("----------------------------------------------------------------\n");
    printf("Name\t\tRoll Number\tClass\tSection\n");
    printf("------------------------------------------------------------------\n");

    for (int i=0; i<count; i++)
    {
        printf("%-20s%-12d%-8s\t%c\n", students[i].name,students[i].rollNumber,students[i].class,students[i].section);
    }
}

