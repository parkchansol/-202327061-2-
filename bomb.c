#include "bomb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 8
#define MAX_SEQUENCE 8

void shuffle_array(char** array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        if (i != j) {
            char* temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

void clear_console_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        continue;
}

void game_bomb() {
    char* colors[MAX_COLORS] = { "빨간색", "파란색", "노란색", "초록색", "주황색", "보라색", "검정색", "하얀색" };  // 폭탄선의 색깔
    char* sequence[MAX_SEQUENCE] = { "빨간색", "파란색", "노란색", "초록색", "보라색", "주황색", "검정색", "하얀색" };  // 폭탄선을 자를 순서
    char* user_cut[MAX_SEQUENCE];  // 사용자가 자른 순서

    shuffle_array(colors, MAX_COLORS);
    shuffle_array(sequence, MAX_SEQUENCE);

    printf("\n\n\n\n\n--------------스토리-------------\n");
    printf("주인공은 아프가니스탄 내전에 참전한 크리스 카일이다\n");
    printf("911테러를 보고 자극을 받아 애국심으로 NAVY SEAL에 입대하였다\n\n\n\n\n");
    printf("주인공은 멘탈이 강하고 순발력이 뛰어난 사람이라 극박한 순간에서도 생각을하고 결정을 내릴수있다\n\n\n\n\n");
    printf("주인공의 첫번째 임무는 폭탄해체하는것이다\n");
    printf("아군들이 적들을 다 사살하고 주인공은 이제 폭탄해체를 시작한다\n");
    printf("폭탄해체 작업에 들어갑니다.\n\n\n");

    printf("잘라야 하는 폭탄 선 색깔 순서입니다 작업에들어가면 아래의 순서를 기억하고 순서대로 폭탄선을 자르십시오\n");
    for (int i = 0; i < MAX_SEQUENCE; i++) {
        printf("%d. %s\n", i + 1, sequence[i]);
    }

    printf("소문자 x 키를 누르면 지시문이 사라지고 작업에 들어갑니다.\n");

    int input;
    while ((input = getchar()) != 'x') {
        continue;
    }

    system("cls");

    for (int i = 0; i < MAX_SEQUENCE; i++) {
        system("cls");  // 화면을 지우는 명령어 (Linux/macOS에서는 "clear" 사용)

        printf("현재 폭탄선 색깔: ");
        for (int j = 0; j < MAX_COLORS; j++) {
            printf("%d. %s ", j + 1, colors[j]);
        }
        printf("\n지시문을 기억해 순서대로 폭탄선을 자르세요.\n");

        int choice;
        scanf("%d", &choice);

        // 선택한 색깔의 인덱스를 확인
        int index = choice - 1;

        if (index < 0 || index >= MAX_COLORS) {
            printf("잘못된 선택입니다. 폭탄이 터져 죽었습니다.\n");
            printf("--------------베드엔딩----------------\n");
            return;
        }

        user_cut[i] = colors[index];

        // 선택한 색깔을 폭탄선에서 제거
        for (int j = index; j < MAX_COLORS - 1; j++) {
            colors[j] = colors[j + 1];
        }

        // 사용자가 자른 순서와 정답 순서를 비교
        if (strcmp(user_cut[i], sequence[i]) != 0) {
            printf("잘못된 순서입니다. 주인공은 첫번째 임무도 완수하지 못하고 폭탄이 터져 죽었습니다.\n");
            printf("--------------베드엔딩----------------\n");

            // 다시 도전할지 묻기
            char answer[10];
            printf("다시 도전하시겠습니까? (yes/no): ");
            scanf("%s", answer);

            if (strcmp(answer, "yes") == 0) {
                system("cls");
                game_bomb(); // 다시 도전
                return;
            }
            else {
                exit(0);
                return; // 종료
            }
        }
    }

    printf("\n폭탄 해체에 성공하였습니다!\n");
    printf("\n임무수행 점수 +20점을 받으셨습니다!\n");
}
