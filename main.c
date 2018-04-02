#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int io=0;
struct student{
    int age;
    char name[20];
    char StudentID[20];
    char sex[5];
    int _class;
    int tel;
}student[100];
struct course{
    int ID;
    char _name[20];
    char _xingzhi[10];
    int time;
    int p_num;
    int term;
}course[100];
void _scanf(int i){
    printf("您的姓名：");
    scanf("%s",student[i].name);
    printf("您的学号：");
    scanf("%s",student[i].StudentID);
    printf("您的年龄：");
    scanf("%d",&student[i].age);
    printf("您的性别：");
    scanf("%s",student[i].sex);
    printf("您的电话：");
    scanf("%d",&student[i].tel);
    printf("您的班级：");
    scanf("%d",&student[i]._class);
    io++;
}
void _print(int i){
    printf("===================\n");
    printf("姓名：%s\n",student[i].name);
    printf("学号：%s\n",student[i].StudentID);
    printf("年龄：%d\n",student[i].age);
    printf("性别：%s\n",student[i].sex);
    printf("电话：%d\n",student[i].tel);
    printf("班级：%d\n",student[i]._class);
    printf("===================\n");
}
int check(){
    char id[20];
    int i;
    int checkid=-1;
    printf("请输入您要修改的学号:　");
    scanf("%s",id);
    for(i=0;i<io;i++){
        if(!strcmp(student[i].StudentID,id)){
            checkid=i;
        }
    }
    if(!(checkid+1)){
        printf("未查询到学生信息\n");
        return -1;
    }
    return checkid;
}
void edit(){
    char id[20];
    int i;
    int checkid=check();
    printf("===================\n");
    printf("[1] 修改姓名\n[2] 修改年龄\n[3] 修改学号\n[4] 修改电话\n[5] 修改班级\n");
    printf("===================\n");
    int choose;
    scanf("%d",&choose);
    switch(choose){
        case 1:
            printf("您的姓名:");
            scanf("%s",student[checkid].name);
            break;
        case 2:
            printf("您的年龄:");
            scanf("%d",&student[checkid].age);
            break;
        case 3:
            printf("您的学号:");
            scanf("%s",student[checkid].StudentID);
            break;
        case 4:
            printf("您的电话:");
            scanf("%d",&student[checkid].tel);
            break;
        case 5:
            printf("您的班级:");
            scanf("%d",&student[checkid]._class);
            break;
        default:
            return;
    }
}
void count(){
    printf("=====================\n");
    printf("已录入学生人数: %d\n",io);
    printf("=====================\n");
     
}
void pcheck(){
    int i=check();
    if(i!=-1) _print(i);
    else return;
}
void _del(int id){
    int i;
    for(i=id;i<io;i++){
        strcpy(student[i].name,student[i+1].name);
        student[i].age = student[i+1].age;
        strcpy(student[i].StudentID,student[i+1].StudentID);
        strcpy(student[i].sex,student[i+1].sex);
        student[i].tel=student[i+1].tel;
        student[i]._class=student[i+1]._class;
        io--; 
    }
}
void del(){
    int id = check();
    char ch[1];
    while(1){
        printf("确定删除此数据吗(Y/N)\n"); 
        scanf("%s",ch);
        if(!strcmp(ch,"Y")){
            _del(id);
            printf("删除成功"); 
            return; 
        }
        else if(!strcmp(ch,"N")){
            return;
        } 
    }
} 

void fun(){
    int i;
    while(1){
        printf("\n选择功能\n[1] 录入\n[2] 读取信息或查询\n[3] 编辑\n[4] 统计\n[5] 删除信息\n[6] 退出\n请输入选择：");
        scanf("%d",&i);
        switch(i){
            case 1:
                _scanf(io);
                break;
            case 2:
                pcheck();
                break;
            case 3:
                edit();
                break;
            case 4:
                count();
                break;
            case 5:
                del();
                break;
            case 6:
                exit(0);
            default:
                printf("ERROR");
        }
    }
}
int main(){
    printf("=================================\n");
    printf("学生选修课系统：powered by W8Cloud\n");
    printf("=================================\n");
    fun();
}
