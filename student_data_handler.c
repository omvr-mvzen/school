#include "student_data_handler.h"
void search_by_id(int LastIndex,int id,int *StudentIndex);

void add_into_student(int LastIndex,int id,char name[MAX_LENGTH],int grade){
    student[LastIndex].id=id;
    strcpy(student[LastIndex].name ,name);
    student[LastIndex].grade=grade;
}
void get_from_student(int LastIndex,int id,int *grade){
    int studentIndex;
    search_by_id(LastIndex,id,&studentIndex);
    //strcpy(student[studentIndex].name,name);
    *grade=student[studentIndex].grade;
}

//----------------------------------------------------------
void search_by_id(int LastIndex,int id,int *StudentIndex){
    for(int i=0;i<=LastIndex;i++){
        if(student[i].id==id)
            *StudentIndex=i;
    }
}