#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_GRADES 5
#define MAX_STUDENTS 30
float calculate_average(float grades[], int num_grades) {
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
    float grades[MAX_GRADES];
    float average;
}student;

int main(void) {
    int choice;
    student students[MAX_STUDENTS];
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
        printf("6- Calculate average of the whole class \n");
        printf("7- Exit \n");
        printf("**______________________________**\n");
        printf("\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:     
                printf("You chose to add a student.\n");
                if (num_students >= MAX_STUDENTS) {
                    printf("Maximum number of students reached!\n");
                    break;
                }
                printf("how many students do you want to enter? : ");
                scanf("%d", &num_students);
                printf("Please fill in the following information:\n");
                for ( int i = 0 ; i < num_students ; i++){
                    printf("Enter name of student [%d] : \n",i+1);
                    scanf("%s", students[i].name);
                    printf("Enter age of student [%d] : \n",i+1);
                    scanf("%d", &students[i].age);
                    printf("Enter ID of student [%d] : \n",i+1);
                    scanf("%s", students[i].id);
                }
                break;
                
            case 2:
                printf("You chose to add grades for a student.\n");
                if (num_students == 0) {
                    printf("No students available. Add a student first.\n");
                    break;
                }
                int student_index = -1;
                printf("Select a student to add grades for (1 to %d): ", num_students);
                scanf("%d",&student_index);
                printf("How many grades do you want to enter? : ");
                scanf("%d", &num_grades);
                if (num_grades > MAX_GRADES) {
                    printf("You can only enter up to %d grades.\n", MAX_GRADES);
                }
                for ( int i = 0 ; i < num_grades ; i++){
                    printf("Enter grade [%d] : \n",i+1);
                    scanf("%d", &students[student_index].grades[i]);

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
                if (num_students == 0) {
                    printf("No students available.\n");
                    break;
                }
                int report_index = -1;
                printf("Select a student to view report (1 to %d): ", num_students);
                scanf("%d",&report_index);
                printf("Report for %s:\n", students[report_index].name);
                printf("Age: %d, ID: %s\n", students[report_index].age, students[report_index].id);
                for (int i = 0; i < num_grades; i++) {
                printf("Grade [%d]: %.2f\n", i+1, students[report_index].grades[i]);
                }
                break;
                
            case 5: 
                printf("Calculating average grade.\n");
                if (num_students == 0) {
                    printf("No students available.\n");
                    break;
                }
                int avg_index = -1;
                printf("Select a student to calculate average (1 to %d): ", num_students);
                scanf("%d",&avg_index);
                students[avg_index].average = calculate_average(students[avg_index].grades, num_grades);
                printf("Average grade for %s: %.2f\n", students[avg_index].name, students[avg_index].average);
                break;

            case 6:
                printf("Calculating class average of the whole class.\n");
                
            case 7:
            exit(0);
                printf("Exiting the program.....\n");
                break;
                
            default:
                printf("Invalid choice, please try again.\n");
                break;  
        }
        printf("\n");
        
    } while (choice != 7);

    return 0;
}