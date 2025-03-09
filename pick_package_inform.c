#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"common.h"

extern user* cur_user;
//�˵�
void print_menu() {
    printf("***************************************\n");
    printf("\t��ӭʹ�ò�����վϵͳ\n");
    printf("\t1.��¼\n");
    printf("\t2.ע��\n");
    printf("\t3.�鿴����\n");
    printf("\t4.�����������ϵͳ\n");
    printf("\t5.���沢�˳�\n");
    printf("***************************************\n");
    int choice = 0;
    
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        cur_user = login(); 
        break;
    case 2:
        regist(); 
        break;
    case 3:
        inform_user(cur_user); 
        break;
    case 4:
        package_ctrl();
        break;
    case 5:
        destructor();//make sure to call this before exit
        exit(0);
    }
    
}


void inform_user(user* u) {
    if (u == NULL) {
        printf("���� �û�ָ��Ϊ��\n");
        return;
    }
    const char* STATUS[] = { "��","����","��ʧ" };
    int have_package = 0;
    printf("**�û�����֪ͨ**\n");
    for (int i = 0; i < MAX_INFO_LEN; i++) {
        if (u->packages[i].id == 0)
            break;
        have_package = 1;
        package* p = &(u->packages[i]);
        printf("����ID�� %d\n", p->id);
        printf("������%d\n", p->weight);
        printf("�����ˣ�%s\n", p->sender_name);
        printf("�ռ��ˣ�%s\n", p->receiver_name);
        printf("���䷽ʽ��%d\n", p->transport);
        printf("�˷ѣ�%dԪ\n", p->cost);
        printf("��ǰ״̬��%s\n", STATUS[p->status]);
        printf("==================================\n");
    }
    if (!have_package) {
        printf("����ǰû�п�ݼ�¼\n");
    }
    printf("**********************************\n");
}



