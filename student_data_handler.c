#include "student_data_handler.h"

void search_by_id(int LastIndex,int id,int *StudentIndex);

void add_into_student(int LastIndex,int id,char name[MAX_LENGTH],int grade){
    student[LastIndex].id=id;
    strcpy(student[LastIndex].name ,name);
    student[LastIndex].grade=grade;
}
int delete_from_student(int id,int * LastIndex){
    int studentIndex=0,lastindex=*LastIndex;
    search_by_id(lastindex,id,&studentIndex);
    if(student[studentIndex].id==id){
        for(int i=studentIndex;i<lastindex;i++){
            student[i]=student[i+1];
        }
        *LastIndex-=1;
        return 1;
    }
    else
        return 0;
}
int get_from_student(int LastIndex,int id,char*name,int *grade){
    int studentIndex;
    search_by_id(LastIndex,id,&studentIndex);
    if(student[studentIndex].id==id && LastIndex!=0){
        strcpy(name,student[studentIndex].name);
        *grade=student[studentIndex].grade;
        return 1;
    }
    else
        return 0;
}
void get_all_from_student(int currentIndex,int LastIndex,int *id,char*name,int *grade){
    *id=student[currentIndex].id;
    strcpy(name,student[currentIndex].name);
    *grade=student[currentIndex].grade;
}

//----------------------------------------------------------
void search_by_id(int LastIndex,int id,int *StudentIndex){
    for(int i=0;i<=LastIndex;i++)
        if(student[i].id==id){
          *StudentIndex=i;
    }
}