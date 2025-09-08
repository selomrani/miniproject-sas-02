#include <stdio.h>
#include <stdlib.h>
#define MAX_GRADES 100
#define MAX_STUDENTS 30

float student_average(float grades[], int num_grades) {
    float sum = 0.0;
    for (int i = 0; i < num_grades; i++) {
        sum += grades[i];
    }
    return sum / num_grades;
}

typedef struct {
    char name[50];
    int age;
    char id[10];
} student;

int main(void) {
    int choice;
    float grade;
    student students[MAX_STUDENTS];
    float grades[MAX_GRADES][MAX_STUDENTS];
    int num_grades = 0;
    int num_students = 0;

    do {
        printf("   Welcome to grades manager v2.0\n");
        printf("**______________________________**\n");
        printf("1- Add a student \n");
        printf("2- Add grades for a student  \n");
        printf("3- Display all students  \n");
        printf("4- Display a report of a student  \n");
        printf("5- Calculate average of a student \n");
        printf("6- Exit \n");
        printf("**______________________________**\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:     
                printf("You chose to add a student.\n");
                if (num_students >= MAX_STUDENTS) {
                    printf("Maximum number of students reached!\n");
                    break;
                }
                printf("Please fill in the following information:\n");
                printf("Enter name: ");
                scanf("%s", students[num_students].name);
                printf("Enter age: ");
                scanf("%d", &students[num_students].age);
                printf("Enter ID: ");
                scanf("%s", students[num_students].id);
                num_students++;
                break;
                
            case 2:
                printf("You chose to add grades for a student.\n");
                if (num_students == 0) {
                    printf("No students available. Add a student first.\n");
                    break;
                }
                printf("How many grades do you want to enter? ");
                scanf("%d", &num_grades);
                for ( int i = 0 ; i < num_grades ; i++){
                    printf("Enter grade [%d] : \n",i+1);
                    scanf("%d",grades);

                }   
                break;                          
                
            case 3:         
                printf("Displaying all students:\n");
                if (num_students == 0) {
                    printf("No students available.\n");
                    break;
                }
                for (int i = 0; i < num_students; i++) {
                    printf("Name: %s, Age: %d, ID: %s\n", students[i].name, students[i].age, students[i].id);
                }
                break;  
                
            case 4:
                printf("Displaying report for student:\n");
                break;
                
            case 5: 
                printf("Calculating average grade.\n");
                break;
                
            case 6:
                printf("Exiting the program.....\n");
                break;
                
            default:
                printf("Invalid choice, please try again.\n");
                break;  
        }
        printf("\n");
        
    } while (choice != 6);

    return 0;
}