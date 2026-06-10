#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct selfref { // 자기참조 구조체 정의
    int n;
    struct selfref* next; // 자기 자신을 가리키는 포인터
};

typedef struct selfref list; // struct selfref를 list라는 이름으로 사용

int main(void)
{
    // 두 구조체 포인터 변수 선언
    list* first = NULL;
    list* second = NULL;

    // malloc을 사용하여 메모리 동적 할당
    first = (list*)malloc(sizeof(list));
    second = (list*)malloc(sizeof(list));

    // 멤버 n에 값 저장 및 next 초기화
    first->n = 100;
    second->n = 200;
    first->next = second->next = NULL;

    // first 다음에 second를 연결
    first->next = second; 

    // 결과 출력
    printf("%p\n", first);
    printf("%d %p\n", first->n, first->next);
    printf("%d\n\n", first->next->n);

    // 동적 할당 메모리 해제
    free(first);
    free(second);

    return 0;
}