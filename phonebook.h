#include <stdio.h>
#include <string.h>
#include "phonebook.h"

// 연락처 추가 함수
void insertContact(Contact *contacts, int *size) {
    printf("이름을 입력해주세요: ");
    fgets(contacts[*size].name, sizeof(contacts[*size].name), stdin);
    contacts[*size].name[strcspn(contacts[*size].name, "\n")] = 0; 

    printf("핸드폰 번호를 입력해주세요: ");
    fgets(contacts[*size].phone, sizeof(contacts[*size].phone), stdin);
    contacts[*size].phone[strcspn(contacts[*size].phone, "\n")] = 0;  

    (*size)++;  // 연락처 수 증가
}

// 연락처 삭제 함수
void deleteContact(Contact *contacts, int *size) {
    char name[50];
    printf("삭제할 이름을 입력해주세요: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  

    for (int i = 0; i < *size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            printf("연락처가 삭제되었습니다.\n");
            return;
        }
    }
    printf("연락처를 찾을 수 없습니다.\n");
}

// 연락처 검색 함수
void searchContact(Contact *contacts, int size) {
    char name[50];
    printf("찾을 이름을 입력해주세요: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("이름: %s, 전화번호: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("연락처를 찾을 수 없습니다.\n");
}

// 연락처 목록 출력 함수
void listContacts(Contact *contacts, int size) {
    printf("연락처 목록:\n");
    for (int i = 0; i < size; i++) {
        printf("이름: %s, 핸드폰: %s\n", contacts[i].name, contacts[i].phone);
    }
}
