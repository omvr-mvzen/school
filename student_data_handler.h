#ifndef STUDENT_DATA_HANDLER_H
#define STUDENT_DATA_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT 50
#define MAX_LENGTH 30

typedef struct Student
{
    int id;
    char name[MAX_LENGTH];
    int grade;
}Student;
Student student[MAX_STUDENT];

void add_into_student(int index,int id,char name[MAX_LENGTH],int grade);
void get_from_student(int LastIndex,int id,char*name,int *grade);
void get_all_from_student(int currentIndex,int LastIndex,int *id,char*name,int *grade);
#endif
