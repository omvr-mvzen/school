#include "control_panel.h"

void control_panel(void){
    while(TRUE){
        int answer=0;
        printf("---------------------\n");
        printf("1.add new student\n");
        printf("2.Delete student\n");
        printf("3.student information\n");
        printf("4.students List\n");
        printf("---------------------\n");
        answer=getch();
        switch(answer){
            case '1':
                add_student();
            break;
            case '2':
                delete_student();
            break;
            case '3':
                studet_info();
            break;
            case '4':
                student_list();
            break;
            default:
                printf("Wrong choice please try again\n");
        }
    }
}