#include "student.h"

int LastIndex=0;

void get_id_from_user(int *id);
int is_max(void);
void get_usernameandpassword(char*newUsername,char*newPassword);
void press_any_key_to_continue(void);

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
            fflush(stdin);
            strcspn(gets(name),"\n");
            //gets take string until press enter then add a new line . to remove the new line (get string until \n) I used strcspn()
            printf("grade : ");
            scanf("%d",&grade);
            add_into_student(LastIndex,id,name,grade);
            LastIndex++;
            printf("# added successfully\n");
        }
        press_any_key_to_continue();
    }
    else{
        printf("# You have reached the maximum number of students\n");
        press_any_key_to_continue();
    }
        
}

void delete_student(void){
    int id=0;
    get_id_from_user(&id);
    if(delete_from_student(id,&LastIndex)){
        printf("# Deleted successfully\n");
        press_any_key_to_continue();
    }
    else{
        printf("# This id not exist , please try again\n");
        press_any_key_to_continue();
    }
}

void studet_info(void){
    int id,grade;
    char name[MAX_LENGTH]="";
    char username[MAX_username_length]="";
    char password[MAX_password_length]="";
    get_id_from_user(&id);
    system("cls");
    if(get_from_student(LastIndex,id,name,&grade,username,password)){
        printf("------------\nStudent Info\n------------\n");
        printf("id        : %d\n",id);
        printf("name      : %s\n",name);
        printf("garde     : %d\n",grade);
        printf("username  : %s\n",username);
        printf("password  : %s\n",password);
        press_any_key_to_continue();
    }
    else{
        printf("# This id not exist , please try agin\n");
        press_any_key_to_continue();
    }
}

void student_list(void){
    int id,grade;
    char name[MAX_LENGTH]="";
    if(LastIndex!=0){
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
    
        press_any_key_to_continue();
    }
    else{
        printf("# You haven't added any students yet\n");
        press_any_key_to_continue();
    }
}

void student_login_check(char inputUsername[MAX_username_length],char inputPassword[MAX_password_length]){
    int id=0,grade=0;
    char answer;
    char name[MAX_LENGTH],newUsername[MAX_username_length],newPassword[MAX_password_length];
    if(display_info_for_loggedin_student(inputUsername,inputPassword,&id,&grade,name,LastIndex)){
        info:
        printf("-------------------------------\n");
        printf("%s profile\n",name);
        printf("-------------------------------\n");
        printf("id    : %d\n",id);
        printf("name  : %s\n",name);
        printf("garde : %d\n",grade);
        printf("-------------------------------\n");
        printf("0.logout\n");
        printf("1.change username and password\n");
        printf("-------------------------------\n");
        if((answer=getch())=='1'){
            get_usernameandpassword(newUsername,newPassword);
            if(change_username_password(id,LastIndex,newUsername,newPassword)){
                printf("# User Name & password changed Successfully\n");
                press_any_key_to_continue();
                system("cls");
                goto info;
            }
        }
        else if((answer=getch())=='0'){
            goto logout;
        }
    }
    else{
        printf("# username or password you enterd is not exist , please try agin\n");
    }
        
    logout:press_any_key_to_continue();
}
//-------------------------------
void get_id_from_user(int *id){
    printf("Enter Student id : ");
    scanf("%d",id);
}
int is_max(void){
        return MAX_STUDENT<=LastIndex;
}
void get_usernameandpassword(char*newUsername,char*newPassword){
    int un=0,pw=0;
    char ch;
    printf("username : ");
    while ((ch=getche())!='\r'&&un<MAX_username_length){
        newUsername[un]=ch;
        un++;
    }
    newUsername[un]='\0';
    printf("\n");
    printf("password : ");
    while ((ch=getch())!='\r'&&pw<MAX_password_length){
        newPassword[pw]=ch;
        printf("*");
        pw++;
    }
    newPassword[pw]='\0';
    printf("\n");
}
void press_any_key_to_continue(void){
    printf("# press any key to continue ..");
    getch();
    system("cls");
}