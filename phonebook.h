#ifndef PHONEBOOK_H
#define PHONEBOOK_H

// 연락처 구조체 정의
typedef struct {
    char name[50];  // 이름 필드
    char phone[15]; // 전화번호 필드
} Contact;

// 함수 선언
void insertContact(Contact *contacts, int *size);
void deleteContact(Contact *contacts, int *size);
void searchContact(Contact *contacts, int size);
void listContacts(Contact *contacts, int size);

#endif
