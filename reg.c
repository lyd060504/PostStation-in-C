#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include"common.h"
static int user_id = 1;
static int admin_id = 1;
static int postman_id = 1;

#define key 114514

#define next user_fd
#define phone_str phone

user* creat(void) {
    user* head;
    head = (user*)malloc(sizeof(user));
    head->next = NULL;
    return head;
}

user* add(user* head, user* newman) {//insert at the end
    user* p = head;
    if (head == NULL) {
        head = newman;
        head->next = NULL;
        return head;
    }
    else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newman;
        newman->next = NULL;
        return head;
    }
}

static user* password(user* newman) {
    while (1) {
        printf("�������������(����������ֺʹ�Сд)");
        fgets(newman->password, MAX_PASSWD_LEN, stdin);
        size_t len = strlen(newman->password);
        if (len > 0 && newman->password[len - 1] == '\n') {
            newman->password[len - 1] = '\0';
        }
        int i = 0, a = 0, b = 0, c = 0, d = 0;
        for (i = 0; newman->password[i] != '\0'; i++) {
            if (isdigit(newman->password[i])) {
                a++;
            }
            else if (isupper(newman->password[i])) {
                b++;
            }
            else if (islower(newman->password[i])) {
                c++;
            }
            else {
                d++;
            }
        }
        if (a != 0 && b != 0 && c != 0 && d == 0) {
            break;
        }
        else {
            printf("����̫ѷ�ˣ��ٻ����µ�\n");
            memset(newman->password, 0, sizeof(newman->password));
        }
    }
    return newman;
}

user* perfect(user* newman) {
    printf("�������������o(*�����*)o�������� %d): ", MAX_NAME_LEN);
    if (scanf("%9s", newman->username) != 1) {
        while (getchar() != '\n');
        printf("Invalid input for name.\n");
        return NULL;
    }
    while (getchar() != '\n');
    password(newman);
    while (1) {
        int m = 0;
        printf("��������ĵ绰: ");
        if (scanf("%11s", newman->phone_str) != 1) {
            while (getchar() != '\n');
            printf("��ƭ�ˣ��绰��������.[��?�৥?? ��]\n");
        }
        for (int i = 0; i < 11; i++) {
            if (isdigit(newman->phone_str[i])) {
                m++;
            }
        }
        if (m == 11) {
            break;
        }
        else {
            printf("��ƭ�ˣ��绰��������.[��?�৥?? ��]\n");
        }
    }
    while (getchar() != '\n');
    return newman;
}

user* build(user* head) {
    user* newman = (user*)malloc(sizeof(user));
    int p;
    while (1) {
        printf("������������(0:����Ա,1:�û�,2:���Ա): ");
        if (scanf("%d", &p) != 1) {
            while (getchar() != '\n');
            printf("������������������\n");
            continue;
        }
        while (getchar() != '\n');
        if (p == 0) {
            printf("������������\n");
            int i;
            scanf("%d", &i);
            while (getchar() != '\n');
            if (i == key) {
                newman->privilege = 0;
                newman->userid = admin_id++;
                break;
            }
            else {
                printf("���������\n");
            }
        }
        else if (p == 1) {
            newman->privilege = 1;
            newman->userid = user_id++;
            break;
        }
        else if (p == 2) {
            newman->privilege = 2;
            newman->userid = postman_id++;
            break;
        }
        else {
            printf("����������ٴγ���\n");
        }
    }
    newman = perfect(newman);
    if (newman == NULL) {
        free(newman);
        return head;
    }
    newman->level = 0;
    newman->next = NULL;
    head = add(head, newman); 
    return head;
}


extern user* user_head;
int regist(){
    user_head = build(user_head);
}

