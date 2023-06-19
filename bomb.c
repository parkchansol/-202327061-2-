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
    char* colors[MAX_COLORS] = { "������", "�Ķ���", "�����", "�ʷϻ�", "��Ȳ��", "�����", "������", "�Ͼ��" };  // ��ź���� ����
    char* sequence[MAX_SEQUENCE] = { "������", "�Ķ���", "�����", "�ʷϻ�", "�����", "��Ȳ��", "������", "�Ͼ��" };  // ��ź���� �ڸ� ����
    char* user_cut[MAX_SEQUENCE];  // ����ڰ� �ڸ� ����

    shuffle_array(colors, MAX_COLORS);
    shuffle_array(sequence, MAX_SEQUENCE);

    printf("\n\n\n\n\n--------------���丮-------------\n");
    printf("���ΰ��� �������Ͻ�ź ������ ������ ũ���� ī���̴�\n");
    printf("911�׷��� ���� �ڱ��� �޾� �ֱ������� NAVY SEAL�� �Դ��Ͽ���\n\n\n\n\n");
    printf("���ΰ��� ��Ż�� ���ϰ� ���߷��� �پ ����̶� �ع��� ���������� �������ϰ� ������ �������ִ�\n\n\n\n\n");
    printf("���ΰ��� ù��° �ӹ��� ��ź��ü�ϴ°��̴�\n");
    printf("�Ʊ����� ������ �� ����ϰ� ���ΰ��� ���� ��ź��ü�� �����Ѵ�\n");
    printf("��ź��ü �۾��� ���ϴ�.\n\n\n");

    printf("�߶�� �ϴ� ��ź �� ���� �����Դϴ� �۾������� �Ʒ��� ������ ����ϰ� ������� ��ź���� �ڸ��ʽÿ�\n");
    for (int i = 0; i < MAX_SEQUENCE; i++) {
        printf("%d. %s\n", i + 1, sequence[i]);
    }

    printf("�ҹ��� x Ű�� ������ ���ù��� ������� �۾��� ���ϴ�.\n");

    int input;
    while ((input = getchar()) != 'x') {
        continue;
    }

    system("cls");

    for (int i = 0; i < MAX_SEQUENCE; i++) {
        system("cls");  // ȭ���� ����� ��ɾ� (Linux/macOS������ "clear" ���)

        printf("���� ��ź�� ����: ");
        for (int j = 0; j < MAX_COLORS; j++) {
            printf("%d. %s ", j + 1, colors[j]);
        }
        printf("\n���ù��� ����� ������� ��ź���� �ڸ�����.\n");

        int choice;
        scanf("%d", &choice);

        // ������ ������ �ε����� Ȯ��
        int index = choice - 1;

        if (index < 0 || index >= MAX_COLORS) {
            printf("�߸��� �����Դϴ�. ��ź�� ���� �׾����ϴ�.\n");
            printf("--------------���忣��----------------\n");
            return;
        }

        user_cut[i] = colors[index];

        // ������ ������ ��ź������ ����
        for (int j = index; j < MAX_COLORS - 1; j++) {
            colors[j] = colors[j + 1];
        }

        // ����ڰ� �ڸ� ������ ���� ������ ��
        if (strcmp(user_cut[i], sequence[i]) != 0) {
            printf("�߸��� �����Դϴ�. ���ΰ��� ù��° �ӹ��� �ϼ����� ���ϰ� ��ź�� ���� �׾����ϴ�.\n");
            printf("--------------���忣��----------------\n");

            // �ٽ� �������� ����
            char answer[10];
            printf("�ٽ� �����Ͻðڽ��ϱ�? (yes/no): ");
            scanf("%s", answer);

            if (strcmp(answer, "yes") == 0) {
                system("cls");
                game_bomb(); // �ٽ� ����
                return;
            }
            else {
                exit(0);
                return; // ����
            }
        }
    }

    printf("\n��ź ��ü�� �����Ͽ����ϴ�!\n");
    printf("\n�ӹ����� ���� +20���� �����̽��ϴ�!\n");
}
