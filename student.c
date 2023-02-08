#include "student.h"
#include "student_data_handler.h"

int LastIndex=0;

void add_student(void){
    int grade=0,id=0;
    char name[MAX_LENGTH];
    printf("id    : ");
    scanf("%d",&id);
    printf("name  : ");
    scanf("%s",name);
    printf("grade : ");
    scanf("%d",&grade);
    add_into_student(LastIndex,id,name,grade);
    LastIndex++;
}
void get_studet_info(void){
    int id,grade;
    //char name[MAX_LENGTH];
    printf("enter id : ");
    scanf("%d",&id);
    get_from_student(LastIndex,id,&grade);
    printf("id: %d\ngrade: %d\n",id,grade);
}