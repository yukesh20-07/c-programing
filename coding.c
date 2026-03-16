#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    char attendance[10]; // Present or Absent
};

int main() {

    struct Student s;
    int choice;
    FILE *fp;

    while(1) {
        printf("\n--- Student Attendance Management System ---\n");
        printf("1. Add Attendance\n");
        printf("2. View Attendance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            fp = fopen("attendance.txt", "a");

            printf("Enter Roll Number: ");
            scanf("%d", &s.roll);

            printf("Enter Name: ");
            scanf("%s", s.name);

            printf("Enter Attendance (Present/Absent): ");
            scanf("%s", s.attendance);

            fprintf(fp, "%d %s %s\n", s.roll, s.name, s.attendance);

            fclose(fp);

            printf("Attendance Added Successfully!\n");
            break;

        case 2:
            fp = fopen("attendance.txt", "r");

            printf("\nRoll\tName\tAttendance\n");
            printf("------------------------------\n");

            while(fscanf(fp, "%d %s %s", &s.roll, s.name, s.attendance) != EOF) {
                printf("%d\t%s\t%s\n", s.roll, s.name, s.attendance);
            }

            fclose(fp);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
