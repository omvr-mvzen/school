#include "student.h"
#include "student_data_handler.h"

int LastIndex=0;

void get_id_from_user(int *id);
int is_max();

void add_student(void){
    int id=0,grade=0,numberOfStudent=0;
    char name[MAX_LENGTH];
    if(!is_max()){
        printf("Enter the number of students you want to add : ");
        scanf("%d",&numberOfStudent);
        for (int i = 0; i <numberOfStudent; i++)
        {
            printf("---------------\nadd new student\n---------------\n");
            printf("id    : ");
            scanf("%d",&id);
            printf("name  : ");
            scanf("%s",name);
            printf("grade : ");
            scanf("%d",&grade);
            add_into_student(LastIndex,id,name,grade);
            LastIndex++;
        }
    }
    else
        printf("You have reached the maximum number of students");
}

void delete_student(void){
    int id=0;
    get_id_from_user(&id);
    if(delete_from_student(id,&LastIndex)){
        printf("Deleted successfully\n");
    }
    else
        printf("something wrong , please try again\n");
}

void studet_info(void){
    int id,grade;
    char name[MAX_LENGTH]="";
    get_id_from_user(&id);
    if(get_from_student(LastIndex,id,name,&grade)){
        printf("------------\nStudent Info\n------------\n");
        printf("id    : %d\n",id);
        printf("name  : %s\n",name);
        printf("garde : %d\n",grade);
    }
    else
        printf("This id not exist , please try agin/n");
}

void student_list(void){
    int id,grade;
    char name[MAX_LENGTH]="";
    printf("------------\nStudent list\n------------\n");
    for (int i = 0; i < LastIndex; i++)
    {
        get_all_from_student(i,LastIndex,&id,name,&grade);
        printf("student(%d)\n",i+1);
        printf("id    : %d\n",id);
        printf("name  : %s\n",name);
        printf("garde : %d\n",grade);
        printf("------------------\n");
    }
    
}

//-------------------------------
void get_id_from_user(int *id){
    printf("Enter Student id : \n");
    scanf("%d",id);
}
int is_max(){
    if(LastIndex<=MAX_STUDENT)
        return 0;
    else
        return 1;
}