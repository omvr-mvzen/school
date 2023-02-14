#include "control_panel.h"

void control_panel(void){
    while(TRUE){
        int answer=0;
        printf("------------------------\nSchool Management System\n------------------------\n");
        printf("1).add new student\n");
        printf("2).Delete student\n");
        printf("3).student information\n");
        printf("4).students List\n");
        printf("5).logout\n");
        printf("-------------------------\n");
        answer=getch();
        switch(answer){
            case '1':
                system("cls");
                add_student();
                
            break;
            case '2':
                system("cls");
                delete_student();
            break;
            case '3':
                system("cls");
                studet_info();
            break;
            case '4':
                system("cls");
                student_list();
            break;
            case '5':
                system("cls");
                goto logout;
            break;
            default:
                printf("Wrong choice please try again\n");
                system("cls");
        }
    }
    logout:;
}
