#include <stdio.h>
#include <locale.h>
#include "phonebook.h"

#define MAX_CONTACTS 100  // 최대 연락처 수

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // 입력 버퍼 비우기
}

int main() {
    setlocale(LC_ALL, "ko_KR.UTF-8");

    Contact contacts[MAX_CONTACTS];  // 연락처 배열
    int size = 0;  // 현재 연락처 수
    int choice;  // 사용자 메뉴 선택

    do {
        printf("\n전화번호부 메뉴:\n");
        printf("1. 연락처 추가\n");
        printf("2. 연락처 삭제\n");
        printf("3. 연락처 검색\n");
        printf("4. 연락처 목록\n");
        printf("5. 종료\n");
        printf("번호를 입력해주세요: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        switch (choice) {
            case 1:
                insertContact(contacts, &size);
                break;
            case 2:
                deleteContact(contacts, &size);
                break;
            case 3:
                searchContact(contacts, size);
                break;
            case 4:
                listContacts(contacts, size);
                break;
            case 5:
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    } while (choice != 5);

    return 0;
}
