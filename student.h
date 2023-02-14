#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include<curses.h> //to use getch() in linux(alternative to <conio.h>
#include "student_data_handler.h"

void add_student(void);
void delete_student(void);
void studet_info(void);
void student_list(void);
void student_login_check(char inputUsername[MAX_username_length],char inputPassword[MAX_password_length]);

#endif