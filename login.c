#include "login.h"

Admin admin_1={"admin","admin"};

void get_username_password(char*input_username,char*input_password);
int is_admin_username_password_correct(char username[10],char input_username[10],char password[10],char input_password[10]);

void admin_login(void){
    system("cls");
    char input_username[10],input_password[10];
    get_username_password(input_username,input_password);
    if(is_admin_username_password_correct(admin_1.username,input_username,admin_1.password,input_password)){
        system("cls");
        control_panel();
    }
    else
        printf("# Wrong password please try agin\n");
}

void student_login(void){
    system("cls");
    char input_username[MAX_username_length];
    char input_password[MAX_password_length];
    printf("------------------------------------------------------------------------\n");
    printf("> When logging in for the first time, use id as user name and password <\n");
    printf("------------------------------------------------------------------------\n");
    get_username_password(input_username,input_password);
    system("cls");
    student_login_check(input_username,input_password);
}

void login(void){
    char answer;
    system("cls");
    printf("1.login as admin\n2.login as Student\n");
    answer=getch();
    switch (answer)
    {
    
    case '1': 
        admin_login();
        break;
    case '2':
        student_login();
        break;
    
    default:
        printf("wrong choice please try again\n");
        break;
    }   
}

//----------------------------------------------------------
void get_username_password(char*input_username,char*input_password){
    printf("username : ");
    scanf("%s",input_username);
    printf("password : ");
    scanf("%s",input_password);
}
int is_admin_username_password_correct(char username[10],char input_username[10],char password[10],char input_password[10]){
    return(!strcmp(username,input_username)&&!strcmp(password,input_password));
}