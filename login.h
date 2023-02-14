#ifndef LOGIN_H
#define LOGIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "student.h"
#include "control_panel.h"

typedef struct admin
{
    char username[MAX_username_length];
    char password[MAX_password_length];
}Admin;

void admin_login(void);
void student_login(void);
void login(void);

#endif