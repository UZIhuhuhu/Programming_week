#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int io=0;
int cid=0;
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
void replace(char * a){
	int len = strlen(a);
	a[len]='\x00';
}
int if_in(char * a){
	int checkid=-1;
	int i;
    for(i=0;i<io;i++){
        if(!strcmp(student[i].StudentID,a)){
            printf("��ѧ���Ѿ�����!\n"); 
            return 1;
        }
	}
	if(!(checkid+1)){
        strcpy(student[io].StudentID,a); 
        return 0;
    }
}
void c_scanf(){
    printf("�γ����֣�");
    scanf("%s",course[cid]._name);
    printf("�γ����ʣ�");
    scanf("%s",course[cid]._xingzhi);
    printf("ѧʱ��");
    scanf("%d",&course[cid].time);
    printf("�γ�������");
    scanf("%d",&course[cid].p_num);
    printf("����ѧ�ڣ�");
    scanf("%d",&course[cid].term);
    cid++;
}
void _scanf(int i){
	char a[20];
	printf("����ѧ�ţ�");
	scanf("%s",a);
    if(if_in(a)){
    	return ;
	};
    printf("����������");
    scanf("%s",student[i].name);
    printf("�������䣺");
    scanf("%d",&student[i].age);
    printf("�����Ա�");
    scanf("%s",student[i].sex);
    printf("���ĵ绰��");
    scanf("%d",&student[i].tel);
    printf("���İ༶��");
    scanf("%d",&student[i]._class);
    io++;
}

void _print(int i){
    printf("===================\n");
    printf("������%s\n",student[i].name);
    printf("ѧ�ţ�%s\n",student[i].StudentID);
    printf("���䣺%d\n",student[i].age);
    printf("�Ա�%s\n",student[i].sex);
    printf("�绰��%d\n",student[i].tel);
    printf("�༶��%d\n",student[i]._class);
    printf("===================\n");
}
void c_print(int i){
    printf("===================\n");
    printf("�γ����ƣ�%s\n",course[i]._name);
    printf("�γ����ʣ�%s\n",course[i]._xingzhi);
    printf("����ѧ�ڣ�%d\n",course[i].term);
    printf("�γ�������%d\n",course[i].p_num);
    printf("��ʱ��%d\n",course[i].time);
    printf("===================\n");
}
int check(){
    char id[20];
    int i;
    int checkid=-1;
    printf("��������Ҫ�޸ĵ�ѧ��:��");
    scanf("%s",id);
    for(i=0;i<io;i++){
        if(!strcmp(student[i].StudentID,id)){
            checkid=i;
        }
    }
    if(!(checkid+1)){
        printf("δ��ѯ��ѧ����Ϣ\n");
        return -1;
    }
    return checkid;
}
void edit(){
    char id[20];
    int i;
    int checkid=check();
    printf("===================\n");
    printf("[1] �޸�����\n[2] �޸�����\n[3] �޸�ѧ��\n[4] �޸ĵ绰\n[5] �޸İ༶\n");
    printf("===================\n");
    int choose;
    scanf("%d",&choose);
    switch(choose){
        case 1:
        	printf("��������:");
            scanf("%s",student[checkid].name);
            break;
        case 2:
        	printf("��������:");
            scanf("%d",&student[checkid].age);
            break;
        case 3:
        	printf("����ѧ��:");
            scanf("%s",student[checkid].StudentID);
            break;
        case 4:
        	printf("���ĵ绰:");
            scanf("%d",&student[checkid].tel);
            break;
        case 5:
        	printf("���İ༶:");
            scanf("%d",&student[checkid]._class);
            break;
        default:
            return;
    }
}
void count(){
	printf("=====================\n");
	printf("��¼��ѧ������: %d\n",io);
	printf("=====================\n");
	 
}
void pcheck(){
	int i=check();
	if(i!=-1) _print(i);
	else return;
}
int ccheck(){
	int i,checkid=-1;
	char name[20];
	printf("������γ�����:");
	scanf("%s",name); 
    for(i=0;i<cid;i++){
        if(!strcmp(course[i]._name,name)){
            checkid=i;
        }
    }
    if(!(checkid+1)){
        printf("δ��ѯ���γ���Ϣ\n");
        return -1;
    }
    return checkid;
}
void c_check(){
	int i=ccheck();
	if(i!=-1) c_print(i);
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
		printf("ȷ��ɾ����������(Y/N)\n"); 
		scanf("%s",ch);
		if(!strcmp(ch,"Y")){
			_del(id);
			printf("ɾ���ɹ�\n"); 
			return;	
		}
		else if(!strcmp(ch,"N")){
			return;
		} 
	}
} 
void save(){
	FILE * fp ;
	fp = fopen("message.txt","w");
	int i;
	for(i=0;i<io;i++){
		fprintf(fp,"0\n");
    	fprintf(fp,"%s\n",student[i].StudentID);
    	fprintf(fp,"%s\n",student[i].name);
    	fprintf(fp,"%d\n",student[i].age);
    	fprintf(fp,"%s\n",student[i].sex);
    	fprintf(fp,"%d\n",student[i].tel);
    	fprintf(fp,"%d\n",student[i]._class);
	}
	fprintf(fp,"1");
	fclose(fp);
	printf("===============\n");
	printf("[*]�ļ�����ɹ�\n");
	printf("===============\n"); 
}
void csave(){
	FILE * fp ;
	fp = fopen("course.txt","w");
	int i;
	for(i=0;i<cid;i++){
		fprintf(fp,"0\n");
    	fprintf(fp,"%s\n",course[i]._name);
    	fprintf(fp,"%s\n",course[i]._xingzhi);
    	fprintf(fp,"%d\n",course[i].time);
    	fprintf(fp,"%d\n",course[i].p_num);
    	fprintf(fp,"%d\n",course[i].term);
	}
	fprintf(fp,"1");
	fclose(fp);
	printf("===============\n");
	printf("[*]�ļ�����ɹ�\n");
	printf("===============\n"); 
}
void read(){
	FILE * fp;
	fp = fopen("message.txt","r");
	while(1){
		int flag=0; 
		fscanf(fp,"%d",&flag);
		if(flag){
			return;
		} 
		fscanf(fp,"%s",student[io].StudentID);
		replace(student[io].StudentID); 
    	fscanf(fp,"%s",student[io].name);
    	fscanf(fp,"%d",&student[io].age);
    	fscanf(fp,"%s",student[io].sex);
    	fscanf(fp,"%d",&student[io].tel);
    	fscanf(fp,"%d",&student[io]._class);
    	io+=1;
	}
	printf("===============\n");
	printf("[*]�ļ���ȡ�ɹ�\n"); 
	printf("===============\n");
}
void cread(){
	FILE * fp;
	fp = fopen("course.txt","r");
	while(1){
		int flag=0; 
		fscanf(fp,"%d",&flag);
		if(flag){
			return;
		} 
		fscanf(fp,"%s",course[cid]._name);
		replace(student[cid].StudentID); 
    	fscanf(fp,"%s",course[cid]._xingzhi);
    	fscanf(fp,"%d",&course[cid].time);
    	fscanf(fp,"%d",&course[cid].p_num);
    	fscanf(fp,"%d",&course[cid].term);
    	cid+=1;
	}
	printf("===============\n");
	printf("[*]�ļ���ȡ�ɹ�\n"); 
	printf("===============\n");
}
void stdu(){
    int i;
    while(1){
        printf("\nѡ����\n[1] ¼��\n[2] ��ѯѧ����Ϣ\n[3] �༭\n[4] ͳ��\n[5] ɾ����Ϣ\n[6] �洢��Ϣ���ļ�\n[7] ��ȡ�ļ���Ϣ\n[9] �뿪�ӳ���\n������ѡ��");
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
            	save();
            	break;
            case 7:
            	read();
            	break;
            case 9:
				return; 
            default:
                printf("ERROR");
        }
    }
}
void cour(){
	int i;
    while(1){
        printf("\nѡ����\n[1] ¼��\n[2] ��ѯ�γ���Ϣ\n[3]�洢��Ϣ���ļ�\n[4] ��ȡ�ļ���Ϣ\n[9] �뿪�ӳ���\n������ѡ��");
        scanf("%d",&i);
        switch(i){
            case 1:
                c_scanf();
                break;
            case 2:
				c_check();
				break; 
			case 3:
				csave();
				break; 
			case 4:
				cread();
				break; 
            case 9:
				return; 
            default:
                printf("ERROR");
        }
    }
} 
int main(){
    printf("==================================\n");
    printf("ѧ��ѡ�޿�ϵͳ��Powered by W8Cloud\n");
    printf("==================================\n");
    int i;
    while(1){
    	    printf("\n===================\n[1] ѧ����Ϣ����\n[2] �γ���Ϣ����\n[3] ѧ��ѡ��\n[4] �뿪����\n===================\n������ѡ��"); 
    	scanf("%d",&i);
    	switch(i){
			case 1: 
    			stdu();
    			break;
			case 2:
				cour(); 
				break;
			case 4:
				return 0;
			default:
				printf("ERROR\n");
				break; 
    	} 
    } 
}

