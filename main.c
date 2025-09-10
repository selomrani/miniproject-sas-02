#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_GRADES 100
#define MAX_STUDENTS 30

float calculate_average(float grades[], int num_grades) {
    float sum = 0.0;
    for (int i = 0; i < num_grades; i++) {
        sum += grades[i];
    }
    return sum / num_grades;
}

void swap(float *a, float *b){
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortbyaverage(float Arr[], int size){
    for (int i = 0; i < size - 1; i++){
        int min_idx = i;
        for (int j = i + 1; j < size; j++){
            if (Arr[j] < Arr[min_idx])
                min_idx = j;
        }
        swap(&Arr[min_idx], &Arr[i]);
    }
}

typedef struct {
    char name[50];
    int age;
    char id[10];
    float grades[MAX_GRADES];
    int num_grades_entered;
    float average;
} student;

int main(void) {
    int choice;
    student students[MAX_STUDENTS];
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
        printf("7- Sort students by average (lowest to highest)\n");
        printf("8- Exit \n");
        printf("**______________________________**\n");
        printf("\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1: {
                printf("You chose to add a student.\n");
                if (num_students >= MAX_STUDENTS) {
                    printf("Maximum number of students reached!\n");
                    break;
                }
                
                int students_to_add;
                printf("How many students do you want to enter? : ");
                scanf("%d", &students_to_add);
                
                if (num_students + students_to_add > MAX_STUDENTS) {
                    printf("Cannot add %d students. Maximum capacity is %d, you currently have %d.\n", 
                           students_to_add, MAX_STUDENTS, num_students);
                    students_to_add = MAX_STUDENTS - num_students;
                    printf("Adding %d students instead.\n", students_to_add);
                }
                
                while(getchar() != '\n'); 
                printf("Please fill in the following information:\n");
                
                for (int i = 0; i < students_to_add; i++) {
                    printf("Enter name of student [%d] : ", num_students + i + 1);
                    fgets(students[num_students + i].name, sizeof(students[num_students + i].name), stdin);
                    students[num_students + i].name[strcspn(students[num_students + i].name, "\n")] = 0;
                    
                    printf("Enter age of student [%d] : ", num_students + i + 1);
                    scanf("%d", &students[num_students + i].age);
                    
                    printf("Enter ID of student [%d] : ", num_students + i + 1);
                    scanf("%s", students[num_students + i].id);
                    while(getchar() != '\n');
                    
                    students[num_students + i].num_grades_entered = 0;
                    students[num_students + i].average = 0.0;
                }
                num_students += students_to_add;
                break;
            }
                
            case 2: {
                printf("You chose to add grades for a student.\n");
                if (num_students == 0) {
                    printf("No students available. Add a student first.\n");
                    break;
                }
                
                int student_index = -1;
                do {
                    printf("Select a student to add grades for (1 to %d): ", num_students);
                    scanf("%d", &student_index);
                    if (student_index < 1 || student_index > num_students) {
                        printf("Student cannot be found please check and try again!\n");
                    }
                } while (student_index < 1 || student_index > num_students);
                
                int num_grades = 0;
                do {
                    printf("How many grades do you want to enter? : ");
                    scanf("%d", &num_grades);
                    if (num_grades > MAX_GRADES || num_grades < 1) {
                        printf("You can only enter between 1 and %d grades.\n", MAX_GRADES);
                    }
                } while (num_grades > MAX_GRADES || num_grades < 1);
                
                students[student_index-1].num_grades_entered = num_grades;
                
                for (int i = 0; i < num_grades; i++) {
                    do {
                        printf("Enter grade [%d] : ", i+1);
                        scanf("%f", &students[student_index-1].grades[i]);
                        if (students[student_index-1].grades[i] < 0 || students[student_index-1].grades[i] > 20) {
                            printf("You can't add a grade smaller than 0 or greater than 20!\n");
                        }
                    } while (students[student_index-1].grades[i] < 0 || students[student_index-1].grades[i] > 20);
                }
                break;
            }
                
            case 3: {
                printf("Displaying all students:\n");
                if (num_students == 0) {
                    printf("No students available.\n");
                    break;
                }
                for (int i = 0; i < num_students; i++) {
                    printf("Name: %s, Age: %d, ID: %s\n", students[i].name, students[i].age, students[i].id);
                }
                break;
            }
                
            case 4: {
                printf("Displaying report for student:\n");
                if (num_students == 0) {
                    printf("No students available.\n");
                    break;
                }
                
                int report_index = -1;
                do {
                    printf("Select a student to view report (1 to %d): ", num_students);
                    scanf("%d", &report_index);
                    if (report_index < 1 || report_index > num_students) {
                        printf("Student cannot be found please check and try again!\n");
                    }
                } while (report_index < 1 || report_index > num_students);
                
                printf("Report for %s:\n", students[report_index-1].name);
                printf("Age: %d, ID: %s\n", students[report_index-1].age, students[report_index-1].id);
                
                if (students[report_index-1].num_grades_entered > 0) {
                    printf("Average: %.2f\n", calculate_average(students[report_index-1].grades, students[report_index-1].num_grades_entered));
                } else {
                    printf("No grades entered for this student.\n");
                }
                break;
            }
                
            case 5: {
                printf("Calculating average grade.\n");
                if (num_students == 0) {
                    printf("No students available.\n");
                    break;
                }
                
                int avg_index = -1;
                do {
                    printf("Select a student to calculate average (1 to %d): ", num_students);
                    scanf("%d", &avg_index);
                    if (avg_index < 1 || avg_index > num_students) {
                        printf("Student cannot be found please check and try again!\n");
                    }
                } while (avg_index < 1 || avg_index > num_students);
                
                if (students[avg_index-1].num_grades_entered > 0) {
                    students[avg_index-1].average = calculate_average(students[avg_index-1].grades, students[avg_index-1].num_grades_entered);
                    printf("Average grade for %s: %.2f\n", students[avg_index-1].name, students[avg_index-1].average);
                } else {
                    printf("No grades entered for %s.\n", students[avg_index-1].name);
                }
                break;
            }

            case 6: {
                printf("Calculating class average of the whole class.\n");
                if (num_students == 0) {
                    printf("No students available.\n");
                    break;
                }
                
                float sum = 0.0;
                int students_with_grades = 0;
                
                for (int i = 0; i < num_students; i++) {
                    if (students[i].num_grades_entered > 0) {
                        students[i].average = calculate_average(students[i].grades, students[i].num_grades_entered);
                        sum += students[i].average;
                        students_with_grades++;
                    }
                }
                
                if (students_with_grades > 0) {
                    float avg_class = sum / students_with_grades;
                    printf("The average grade of the whole class: %.2f\n", avg_class);
                } else {
                    printf("No students have grades entered yet.\n");
                }
                break;
            }
            
            case 7: {
                printf("You chose to sort students by average.\n");
                if (num_students == 0) {
                    printf("No students available.\n");
                    break;
                }
                
                int students_with_grades = 0;
                for (int i = 0; i < num_students; i++) {
                    if (students[i].num_grades_entered > 0) {
                        students[i].average = calculate_average(students[i].grades, students[i].num_grades_entered);
                        students_with_grades++;
                    }
                }
                
                if (students_with_grades == 0) {
                    printf("No students have grades entered yet.\n");
                    break;
                }
                
                float averages[num_students];
                int indices[num_students];
                int count = 0;
                
                for (int i = 0; i < num_students; i++) {
                    if (students[i].num_grades_entered > 0) {
                        averages[count] = students[i].average;
                        indices[count] = i;
                        count++;
                    }
                }
                
                for (int i = 0; i < count - 1; i++) {
                    int min_idx = i;
                    for (int j = i + 1; j < count; j++) {
                        if (averages[j] < averages[min_idx])
                            min_idx = j;
                    }
                    if (min_idx != i) {
                        float temp_avg = averages[min_idx];
                        averages[min_idx] = averages[i];
                        averages[i] = temp_avg;
                        
                        int temp_idx = indices[min_idx];
                        indices[min_idx] = indices[i];
                        indices[i] = temp_idx;
                    }
                }
                
                printf("Students sorted by average (lowest to highest):\n");
                for (int i = 0; i < count; i++) {
                    printf("%d. %s - Average: %.2f\n", i+1, students[indices[i]].name, averages[i]);
                }
                break;
            }
            
            case 8:
                printf("Exiting the program.....\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice, please try again.\n");
                break;  
        }
        printf("\n");
        
    } while (choice != 8);

    return 0;
}