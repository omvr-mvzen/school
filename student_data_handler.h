#ifndef STUDENT_DATA_HANDLER_H
#define STUDENT_DATA_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT 50
#define MAX_LENGTH 30
#define MAX_username_length 10
#define MAX_password_length 10

typedef struct Student
{
    int id;
    char name[MAX_LENGTH];
    int grade;
    char user_name[MAX_username_length];
    char password[MAX_password_length];
}Student;
Student student[MAX_STUDENT];

void add_into_student(int index,int id,char name[MAX_LENGTH],int grade);
int delete_from_student(int id,int * LastIndex);
int get_from_student(int LastIndex,int id,char*name,int *grade,char*username,char*password);
void get_all_from_student(int currentIndex,int LastIndex,int *id,char*name,int *grade);
int display_info_for_loggedin_student(char inputUsername[MAX_username_length],char inputPassword[MAX_password_length],int * id,int * grade,char*name,int LastLndex);
int change_username_password(int id,int LastIndex,char newUsername[MAX_username_length],char newPassword[MAX_password_length]);
#endif
