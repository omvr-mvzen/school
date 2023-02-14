#include "student_data_handler.h"

void search_by_id(int LastIndex,int id,int *StudentIndex);
int is_username_password_correct(char inputUsername[MAX_username_length],char inputPassword[MAX_password_length],int studentIndex);
void tostring(char str[], int num);

void add_into_student(int LastIndex,int id,char name[MAX_LENGTH],int grade){
    student[LastIndex].id=id;
    strcpy(student[LastIndex].name ,name);
    student[LastIndex].grade=grade;
    //default username & password = id
    char idstr[10];
    tostring(idstr,id);
    strcpy(student[LastIndex].user_name,idstr);
    strcpy(student[LastIndex].password,idstr);
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
int get_from_student(int LastIndex,int id,char*name,int *grade,char*username,char*password){
    int studentIndex;
    search_by_id(LastIndex,id,&studentIndex);
    if(student[studentIndex].id==id && LastIndex!=0){
        strcpy(name,student[studentIndex].name);
        *grade=student[studentIndex].grade;
        strcpy(username,student[studentIndex].user_name);
        strcpy(password,student[studentIndex].password);
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
int display_info_for_loggedin_student(char inputUsername[MAX_username_length],char inputPassword[MAX_password_length],int * id,int * grade,char*name,int LastLndex){
    for (int studentIndex = 0; studentIndex < LastLndex; studentIndex++)
    {
        if(is_username_password_correct(inputUsername,inputPassword,studentIndex)){
            *id=student[studentIndex].id;
            strcpy(name,student[studentIndex].name);
            *grade=student[studentIndex].grade;
            return 1;
        }
    }
    return 0;
    
}
int change_username_password(int id,int LastIndex,char newUsername[MAX_username_length],char newPassword[MAX_password_length]){
    int StudentIndex;
    search_by_id(LastIndex,id,&StudentIndex);
    strcpy(student[StudentIndex].user_name,newUsername);
    strcpy(student[StudentIndex].password,newPassword);
    return 1;
}
//----------------------------------------------------------
void search_by_id(int LastIndex,int id,int *StudentIndex){
    for(int i=0;i<=LastIndex;i++)
        if(student[i].id==id){
          *StudentIndex=i;
            break;
    }
}
int is_username_password_correct(char inputUsername[MAX_username_length],char inputPassword[MAX_password_length],int studentIndex){
    return(!strcmp(student[studentIndex].user_name,inputUsername)&&!strcmp(student[studentIndex].password,inputPassword));
}
void tostring(char str[], int num)
{
    int i, rem, len = 0, n;
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}