#include <stdio.h>
#include "menu.h"
#include <conio.h>
#include <time.h>
#include "bomb.h"
#define _CRT_SECURE_NO_WARNINGS 


void clearScreen() {
    //메뉴화면 치워주는데 씀
    system("cls");
}

int introduce_screen() {
    printf("         -게임설명-        .\n");
    printf("선택을 하여 게임을 하십시오.\n");
    printf("당신의 선택하나하나가 이야기를 바꿉니다 신중히 선택하세요.\n");
    printf("m값은 주인공의 멘탈을 나타냅니다 .\n");
    printf("i값은 주인공의 임무수행 점수를 나타냅니다 .\n");
    printf("y값은 윤리 점수를 나타냅니다 .\n");
    printf("당신의 결정에따라 위 점수 3개가 오르거나 내립니다.\n");
    printf("각 점수에 의거하여 엔딩이 결정됩니다 잘 선택하세요 .\n");
    printf("선택에는 15초의 시간제한시간이 있습니다 .\n");
    return 0;
}

int game_impl() {
    int m = 100; // 주인공의 멘탈 변수
    int i = 100; // 주인공의 임무 수행 점수
    int y = 100; // 윤리점수
    int choice;


    


    while (i > 0 && m > 0) {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("현재 i: %d, m: %d, y: %d\n", i, m, y);
        printf("주인공에게 새로운 임무가 떨어졌다 탈레반 폭군 <오사마 살라드> 를 찾아내 사살하는것이다 \n\n");
        printf("전쟁 지역 민간인에게  <오사마 살라드>에 대한 정보를 얻어내면 좋겠지만 그들은 우리랑 협조했다는 이유로 보복을 당할수도있다\n\n");



        printf("ENTER를 누르면 선택지가 표시됩니다.\n");
        getch(); // 사용자의 입력을 기다림
        clearScreen();
                            
        
        printf("\n어떤 행동을 할 것인가?\n\n");

        printf("1. 선택지 1: 민간인에게 지켜준다 거짓말을하고 협력을 얻어낸다 .\n");
        printf("2. 선택지 2: 민간인과 협력하지않는다.\n");
        // ... 추가 스토리 선택지 ...
        printf("선택: ");

        time_t start_time = time(NULL); // 시작 시간 기록
        int input_timeout = 15; // 제한 시간 (초)

        while (!_kbhit()) { // 키보드 입력 대기
            time_t current_time = time(NULL);
            if (current_time - start_time >= input_timeout) { // 제한 시간 초과 시
                choice = 1; // 자동으로 1번 선택
                break;
            }
        }

        if (!_kbhit()) { // 키보드 입력이 없는 경우
            printf("%d (자동 선택)\n", choice);
            clearScreen();
        }
        else {
            scanf("%d", &choice);
            clearScreen();
        }
        
        switch (choice) {
        case 1:
            printf("임무는 그 가족들이 제공해준 정보로 성공하였지만 그 민간인 가족들은 탈레반 대원들에게 복수를 당하여 어린아이까지 몰살을 당했다,\n");
            // 스토리 1에 따른 변수 값 변경
            i += 15;
            m -= 20;
            y -= 20;
            break;
        case 2:
            printf("민간인은 무사했지만 임무에는 실패했다\n");
            // 스토리 2에 따른 변수 값 변경
            i -= 20;
            m -= 5;
            y += 10;
            break;
            // ... 추가 스토리에 대한 처리 ...
        default:
            printf("잘못된 선택입니다.\n");
            continue;
        }
        {
            printf("\n\n\n\n\n\n\n\n\n");
            printf("현재 i: %d, m: %d, y: %d\n", i, m, y);
            printf("10대 중반으로 보이는 탈레반 병사가 다리가 잘려 고통스러워하고있다\n\n");

            printf("ENTER를 누르면 선택지가 표시됩니다.\n");
            getch(); // 사용자의 입력을 기다림
            clearScreen();

            printf("\n어떤 행동을 할 것인가?\n\n");

            printf("1. 선택지 1: 고통을끝내준다.\n");
            printf("2. 선택지 2: 적이지만 어린소년이니 지혈해주어 살려준다 .\n");
            // ... 추가 스토리 선택지 ...
            printf("3. 선택지 3: 그냥 내버려둔다.\n");
            printf("선택: ");

            time_t start_time = time(NULL); // 시작 시간 기록
            int input_timeout = 10; // 제한 시간 (초)

            while (!_kbhit()) { // 키보드 입력 대기
                time_t current_time = time(NULL);
                if (current_time - start_time >= input_timeout) { // 제한 시간 초과 시
                    choice = 3; // 자동으로 1번 선택
                    break;
                }
            }

            if (!_kbhit()) { // 키보드 입력이 없는 경우
                printf("%d (자동 선택)\n", choice);
                clearScreen();
            }
            else {
                scanf("%d", &choice);
                clearScreen();
            }

            switch (choice) {
            case 1:
                printf("소년의 고통스러워하는 비명소리가 멈추었다  \n");
                // 스토리 1에 따른 변수 값 변경
                i -= 0;
                m -= 0;
                y += 3;
                break;
            case 2:
                printf("지혈하여 그 탈레반 병사는 살았고 주인공에게 고마움을 표시했다\n");
                // 스토리 2에 따른 변수 값 변경
                i -= 0;
                m += 5;
                y += 10;
                break;
                // ... 추가 스토리에 대한 처리 ...
            case 3:
                printf("소년은 비명을 지르며 고통스럽게 죽어갔고 주인공은 살짝 죄책감을 느꼇다\n");
                // 스토리 3에 따른 변수 값 변경
                i += 1;
                m -= 5;
                y -= 5;
                break;
            default:
                printf("잘못된 선택입니다.\n");
                continue;
            }

            {
                printf("\n\n\n\n\n\n\n\n\n");
                printf("현재 i: %d, m: %d, y: %d\n", i, m, y);
                printf("주인공은 탈레반 장군 제거 작전에 6명의 정예병사들과함께 투입되었고\n\n");
                printf("그가있는 탈레반과 협조적인 마을에 잠입하여 그를 사살해야한다\n\n");
                printf("산을통해 마을에 접근하던도중 산속에서 탈레반과 협조적인 마을에 민간인 3명을 마주쳤고 붙잡았다\n\n");
                printf("이들을 어떻게 처리할지 대원들은 논의를 시작하였고 \n\n");
                printf("임무를 위해 사살하자는 측과 윤리와 미국특수부대가 민간인을 죽였다는것이 알려지면 받을 비난을 생각해 살려주자는 측이 대립하였다 \n\n");
                printf("이에대한 투표가 진행되었고 \n\n");
                printf("주인공만 결정하면된다\n\n");


                printf("ENTER를 누르면 선택지가 표시됩니다.\n");
                getch(); // 사용자의 입력을 기다림
                clearScreen();

                printf("\n어떤 행동을 할 것인가?\n\n");

                printf("1. 선택지 1: 민간인을 놓아준다.\n");
                printf("2. 선택지 2: 민간인을 묶어놓고 작전을 진행한다.\n");
                // ... 추가 스토리 선택지 ...
                printf("3. 선택지 3: 민간인을 죽이고 땅에 뭍어 은폐한다.\n");
                printf("선택: ");

                time_t start_time = time(NULL); // 시작 시간 기록
                int input_timeout = 10; // 제한 시간 (초)

                while (!_kbhit()) { // 키보드 입력 대기
                    time_t current_time = time(NULL);
                    if (current_time - start_time >= input_timeout) { // 제한 시간 초과 시
                        choice = 3; // 자동으로 1번 선택
                        break;
                    }
                }

                if (!_kbhit()) { // 키보드 입력이 없는 경우
                    printf("%d (자동 선택)\n", choice);
                    clearScreen();
                }
                else {
                    scanf("%d", &choice);
                    clearScreen();
                }
                
                switch (choice) {
                case 1:
                    printf("민간인을 놓아주었고 그 결과로 탈레반한테 쫒겨 임무에 실패하였고 주인공 외에 1명만이 살아남고 모두 전사하였다 \n");
                    // 스토리 1에 따른 변수 값 변경
                    i -= 15;
                    m -= 10;
                    y += 5;
                    break;
                case 2:
                    printf("작전은 수월하게 진행되었고 결국 사살하는데 성공했으나 그 민간인들은 죽었는지 살았는지 모른다\n");
                    // 스토리 2에 따른 변수 값 변경
                    i += 15;
                    m -= 0;
                    y -= 10;
                    break;
                    // ... 추가 스토리에 대한 처리 ...
                case 3:
                    printf("죽이고 땅에 뭍었기 때문에 발각되지는 않았고 언론도 모르겠지만 인륜을 저버린 짓을 저지른건 확실하다.임무에는 성공하였다\n");
                    // 스토리 3에 따른 변수 값 변경
                    i += 15;
                    m -= 35;
                    y -= 50;
                    break;
                default:
                    printf("잘못된 선택입니다.\n");
                    continue;
                }
                {
                    printf("\n\n\n\n\n\n\n\n\n");
                    printf("현재 i: %d, m: %d, y: %d\n", i, m, y);
                    printf("주인공과 7명의 특수대원들은 다음 임무에관한 정보를 입수하고 상부에 보고하기위해 임무에서 복귀하던중\n");
                    printf("수많은 적군을 마추쳤다\n");
                    printf("이 중요한정보를 얼릉 보고하지않으면 아군측에 사상자가 생길지도 모른다\n");
                    printf("이들을 어떻게든 뚫고나가야한다\n");
                    printf("그때 주인공의 눈앞에 탈레반이 쓰던 세상에서 가장 잔인한 무기 백린탄이 있었다\n");



                    printf("ENTER를 누르면 선택지가 표시됩니다.\n");
                    getch(); // 사용자의 입력을 기다림
                    clearScreen();

                    printf("\n어떤 행동을 할 것인가?\n\n");

                    printf("1. 선택지 1: 백린탄을 사용한다.\n");
                    printf("2. 선택지 2: 우회한다.\n");
                    // ... 추가 스토리 선택지 ...
                    printf("3. 선택지 3: 위험을 무릎쓰고 교전을 시도한다.\n");
                    printf("선택: ");

                    time_t start_time = time(NULL); // 시작 시간 기록
                    int input_timeout = 10; // 제한 시간 (초)

                    while (!_kbhit()) { // 키보드 입력 대기
                        time_t current_time = time(NULL);
                        if (current_time - start_time >= input_timeout) { // 제한 시간 초과 시
                            choice = 1; // 자동으로 1번 선택
                            break;
                        }
                    }

                    if (!_kbhit()) { // 키보드 입력이 없는 경우
                        printf("%d (자동 선택)\n", choice);
                        clearScreen();
                    }
                    else {
                        scanf("%d", &choice);
                        clearScreen();
                    }

                    switch (choice) {
                    case 1:
                        printf("적들은 다 쓸어버렸지만 너무 잔인했고 몇몇 민간인 사상자도 발생하였다..주인공은 큰 죄책감에 빠졌다\n");
                        // 스토리 1에 따른 변수 값 변경
                        i += 10;
                        m -= 40;
                        y -= 55;
                        break;
                    case 2:
                        printf("우회하여 교전을 피했지만 늦게 복귀하여 작전에 차질이 생겼다\n");
                        // 스토리 2에 따른 변수 값 변경
                        i -= 5;
                        m -= 3;
                        y += 5;
                        break;
                        // ... 추가 스토리에 대한 처리 ...
                    case 3:
                        printf("교전을 하여 갖가스로 승리하였으나 주인공과 단2명의 대원만이 살아남고 모두 전사하였다 \n");
                        // 스토리 3에 따른 변수 값 변경
                        i += 3;
                        m -= 10;
                        y += 5;
                        break;
                    default:
                        printf("잘못된 선택입니다.\n");
                        continue;
                    }





                    {
                        printf("\n\n\n\n\n\n\n\n\n");
                        printf("현재 i: %d, m: %d, y: %d\n", i, m, y);
                        printf("탈레반 소속의 악행을 저질러온 간부 아흐메드 샤 를 암살하기 위해 적진에 잠입한 주인공\n\n");
                        printf("\n\n\n\n\n\n");
                        printf("첩보에 따르면 그의 인상 착의는 덥수룩한 검은색수염에 검은색선글라스안경을 쓰고 키는 180중반에 건장한 키다 ");
                        printf("이슬람 전통모자 터번을쓰고있고 이슬람 전통옷을 입었고 그위에 방탄복을 입었고 그리고 등뒤에는 PKM 소총을 매고잇다 ");
                        printf("이 인상착의를 잘 기억하자 ");



                        printf("ENTER를 누르면 이야기가 진행됩니다.\n");
                        getch(); // 사용자의 입력을 기다림
                        clearScreen();

                        printf("\n탈레반 간부회의에 \n\n");
                        printf("\n8명의 사람이 보인다 저중 <아흐마드 샤> 가있다 \n\n");
                        printf("\n아흐마드 샤의 인상착의가 뭐였지? \n\n");
                        printf("\n아하마드 인상착의를 기억하고 한명을 사살하여라 \n\n");
                        printf("다 탈레반 대원처럼 보이지만 탈레반에 잠입한 미국스파이와 그가 외부에서 고용한 경호원도있다하니 조심해서 사살하자 ");
                        printf("\n시간은 30초이다 \n\n");




                        printf("1. 선택지 1: .\n");
                        printf("짦은 검은색수염에 날카로운 눈매 키는 180대에 건장한 키\n ");
                        printf("이슬람 전통모자 터번을쓰고있고 이슬람 전통옷을 입었고  그리고 등뒤에는 AK-47 소총을 매고있는 남자를 사살한다 ");
                        printf("\n\n\n\n");



                        printf("2. 선택지 2: .\n");
                        printf("긴 검은색수염에 졸린눈 키는 180대에 건장한 키\n ");
                        printf("헝클어진머리 이슬람 전통옷을 입었고  그리고 등뒤에는 AK-47 소총을 매고있는 남자를 사살한다 ");
                        printf("\n\n\\nn");


                        
                        printf("3. 선택지 3: .\n");
                        printf("덥수룩한 흰수염에 검은색선글라스 안경을 쓰고 키는 180대에 건장한 키\n ");
                        printf("이슬람 전통모자 터번을쓰고있고 이슬람 전통옷을 입었고 그위에 방탄복을 입었고 그리고 등뒤에는 RPG-7 로켓런쳐를 매고있는 남자를 사살한다 ");
                        printf("\n\n\n\n");


                        printf("4. 선택지 4: .\n");
                        printf("덥수룩한 검은색수염에 검은색선글라스 안경을 쓰고 키는 160대에 비교적 외소한 키\n ");                       
                        printf("이슬람 전통모자 터번을쓰고있고 이슬람 전통옷을 입었고 그위에 가디건을 입었고 그리고 등뒤에는 AK-47을 매고있는 남자를 사살한다 ");
                        printf("\n\n\n\n");
                        
                        
                        
                        printf("5. 선택지 5: .\n");
                        printf("덥수룩한 검은색수염에 검은색선글라스 안경을 쓰고 키는 180대에 건장한 키\n ");
                        printf("이슬람 전통모자 터번을쓰고있고 이슬람 전통옷을 입었고 그위에 방탄복을 입었고 그리고 등뒤에는 PKM을 매고있는 남자를 사살한다 ");
                        printf("\n\n\n\n");


                        printf("6. 선택지 6: .\n");
                        printf("깔끔한 면도에 검은색선글라스 안경을 쓰고 키는 180대에 건장한 키\n ");
                        printf("이슬람 전통모자 터번을쓰고있고 이슬람 전통옷을 입었고 그위에 가디건을 입었고 그리고 등뒤에는 PKM을 매고있는 남자를 사살한다 ");
                        printf("\n\n\n\n");


                        printf("7. 선택지 7: .\n");
                        printf("긴수염에 검은색선글라스 안경을 쓰고 키는 170대에 보통 키\n ");
                        printf("이슬람 전통모자 터번을쓰고있고 이슬람 전통옷을 입었고 그위에 가디건을 입었고 그리고 권총을 매고있는 남자를 사살한다 ");
                        printf("\n\n\n\n");



                        printf("8. 선택지 8: .\n");
                        printf("긴수염에 검은색선글라스 안경을 쓰고 키는 170대에 보통 키 \n");
                        printf("대머리에 방탄복을 두른 중무장을 하였고 그리고 등뒤에는 AK-47 매고있는 남자를 사살한다 ");
                        printf("\n\n\n\n");



                        printf("9. 선택지 9: .\n");
                        printf("깔끔한 면도에 검은색선글라스 안경을 쓰고 키는 160대에 외소한 키 \n");
                        printf("대머리에 방탄복을 두른 중무장을 하였고 그리고 등뒤에는 AK-47 매고있는 남자를 사살한다 ");
                        printf("\n\n\n\n");


                        printf("10. 선택지 10: 인상착의가 기억이안난다...그냥 아무도 사살하지않는다.\n");
                        printf("선택: ");
                        printf("\n\n\n\n");

                        printf("11. 선택지 11: 수류탄을 던져 모두 죽여버린다.\n");
                        printf("선택: ");
                        printf("\n\n\n\n");



                        time_t start_time = time(NULL); // 시작 시간 기록
                        int input_timeout = 180; // 제한 시간 (초)

                        while (!_kbhit()) { // 키보드 입력 대기
                            time_t current_time = time(NULL);
                            if (current_time - start_time >= input_timeout) { // 제한 시간 초과 시
                                choice = 10; // 자동으로 1번 선택
                                break;
                            }
                        }

                        if (!_kbhit()) { // 키보드 입력이 없는 경우
                            printf("%d (자동 선택)\n", choice);
                            clearScreen();
                        }
                        else {
                            scanf("%d", &choice);
                            clearScreen();
                        }

                        switch (choice) {
                        case 1:
                            printf("주인공은 그의 머리에 총알을 박아 사살하고 현장에서 빠져나왔다 하지만 알고보니 그는 아흐마드 샤가 아니였다! 주인공은 임무실패와 죄책감에 빠졌다\n");
                            // 스토리 1에 따른 변수 값 변경
                            i -= 35;
                            m -= 10;
                            y -= 5;
                            break;
                        case 2:
                            printf("주인공은 그의 머리에 총알을 박아 사살하고 현장에서 빠져나왔다 하지만 알고보니 그는 아흐마드 샤가 아니였다! 주인공은 임무실패와 죄책감에 빠졌다\n");
                            // 스토리 2에 따른 변수 값 변경
                            i -= 35;
                            m -= 10;
                            y -= 5;
                            break;
                            // ... 추가 스토리에 대한 처리 ...
                        case 3:
                            printf("주인공은 그의 머리에 총알을 박아 사살하고 현장에서 빠져나왔다 하지만 알고보니 그는 아흐마드 샤가 아니였다! 주인공은 임무실패와 죄책감에 빠졌다\n");
                            // 스토리 3에 따른 변수 값 변경
                            i -= 35;
                            m -= 10;
                            y -= 5;
                            break;
                        case 4:
                            printf("주인공은 그의 머리에 총알을 박아 사살하고 현장에서 빠져나왔다 하지만 알고보니 그는 아흐마드 샤가 아니였다! 주인공은 임무실패와 죄책감에 빠졌다\n");
                            // 스토리 3에 따른 변수 값 변경
                            i -= 35;
                            m -= 10;
                            y -= 5;
                            break;
                        case 5:
                            printf("아흐마드 샤를 사살하였다 임무성공!\n");
                            // 스토리 3에 따른 변수 값 변경
                            i += 30;
                            m += 15;
                            y += 10;
                            break;
                        case 6:
                            printf("주인공은 그의 머리에 총알을 박아 사살하고 현장에서 빠져나왔다 하지만 알고보니 그는 아흐마드 샤가 아니였다! 주인공은 임무실패와 죄책감에 빠졌다!\n");
                            // 스토리 3에 따른 변수 값 변경
                            i -= 35;
                            m -= 10;
                            y -= 5;
                            break;
                        case 7:
                            printf("주인공은 그의 머리에 총알을 박아 사살하고 현장에서 빠져나왔다 하지만 알고보니 그는 아흐마드 샤가 아니였다! 주인공은 임무실패와 죄책감에 빠졌다\n");
                            // 스토리 3에 따른 변수 값 변경
                            i -= 35;
                            m -= 10;
                            y -= 5;
                            break;
                        case 8:
                            printf("주인공은 그의 머리에 총알을 박아 사살하고 현장에서 빠져나왔다 하지만 알고보니 그는 아흐마드 샤가 아니였다! 주인공은 임무실패와 죄책감에 빠졌다\n");
                            // 스토리 3에 따른 변수 값 변경
                            i -= 35;
                            m -= 10;
                            y -= 5;
                            break;
                        case 9:
                            printf("주인공은 그의 머리에 총알을 박아 사살하고 현장에서 빠져나왔다 하지만 알고보니 그는 아흐마드 샤가 아니였다! 주인공은 임무실패와 죄책감에 빠졌다\n");
                            // 스토리 3에 따른 변수 값 변경
                            i -= 35;
                            m -= 10;
                            y -= 5;
                            break;
                        case 10:
                            printf("주인공은 임무에 실패하였다\n");
                            // 스토리 3에 따른 변수 값 변경
                            i -= 35;
                            m -= 5;
                            y -= 0;
                            break;
                        case 11:
                            printf("아흐마드 샤는 죽었지만 주인공은 미국스파이와 경호원까지 죽여버렸다..주인공은 심한최잭감에 빠졌고 나중에 군재판에 회부될지도 모른다\n");
                            // 스토리 3에 따른 변수 값 변경
                            i += 5;
                            m -= 40;
                            y -= 10;
                            break;
                        default:
                            printf("잘못된 선택입니다.\n");
                            continue;
                        }
                        {

                           





                            printf("\n\n\n\n\n\n\n\n\n");
                            printf("현재 i: %d, m: %d, y: %d\n", i, m, y);
                            printf("지상에서 아군들은 적군과 교전중이고 주인공은 옥상에서 <Tac-338>를 들고 아군들을 엄호하고 있다\n\n");
                            printf("아프가니스탄 탈레반 소속 10살정도로 보이는 어린 소년이 떨어져 있는 수류탄을 드는 것을 스코프를 통해 목격하였다\n\n");
                            printf("아군들은 근처에 있고 그 장면을 보지 못하였다\n\n");

                            printf("ENTER를 누르면 선택지가 표시됩니다.\n");
                            getch(); // 사용자의 입력을 기다림

                            printf("\n어떤 행동을 할 것인가?\n\n");

                            printf("1. 선택지 1: 어린 소년이니 일단 지켜본다.\n");
                            printf("2. 선택지 2: 소년을 사살한다.\n");
                            // ... 추가 스토리 선택지 ...
                            printf("3. 선택지 3: 소년 근처에 위협사격을 한다.\n");
                            printf("선택: ");

                            time_t start_time = time(NULL); // 시작 시간 기록
                            int input_timeout = 10; // 제한 시간 (초)

                            while (!_kbhit()) { // 키보드 입력 대기
                                time_t current_time = time(NULL);
                                if (current_time - start_time >= input_timeout) { // 제한 시간 초과 시
                                    choice = 1; // 자동으로 1번 선택
                                    break;
                                }
                            }

                            if (!_kbhit()) { // 키보드 입력이 없는 경우
                                printf("%d (자동 선택)\n", choice);
                                clearScreen();
                            }
                            else {
                                scanf("%d", &choice);
                                clearScreen();
                            }

                            switch (choice) {
                            case 1:
                                printf("어린소년이 아군들에게 수류탄을 던져 아군들이 전사하였고 주인공은 심한 죄책감에 빠졌다\n");
                                // 스토리 1에 따른 변수 값 변경
                                i -= 15;
                                m -= 10;
                                y -= 10;
                                break;
                            case 2:
                                printf("아군들은 무사하였고 주인공은 죄책감을 가졌지만 어쩔 수 없는 선택이였다고 생각한다\n");
                                // 스토리 2에 따른 변수 값 변경
                                i += 10;
                                m -= 5;
                                y -= 10;
                                break;
                                // ... 추가 스토리에 대한 처리 ...
                            case 3:
                                printf("소년 근처에 위협사격을 했고 소년은 자기 주변에 총알이 날아온것에 깜짝 놀라 수류탄을 떨어트리고 도망쳤다\n");
                                printf("결과는 좋았지만 위험한 시도였다\n");
                                // 스토리 3에 따른 변수 값 변경
                                i += 10;
                                m += 10;
                                y += 0;
                                break;
                            default:
                                printf("잘못된 선택입니다.\n");
                                continue;
                            }

                            // 시간 제한 기능
                            printf("\n\n\n\n\n\n\n\n");
                            printf("현재 i: %d, m: %d, y: %d \n", i, m, y);
                            printf("상부에서 탈레반에게 협조적인 민간인을 모두 사살하라고한다\n");

                            printf("ENTER를 누르면 선택지가 표시됩니다.\n");
                            getch(); // 사용자의 입력을 기다림
                            clearScreen();

                            printf("\n어떤 선택을 할 것인가?\n\n");

                            printf("1. 선택지 1: 명령에 따라 민간인을 사살한다.\n");
                            printf("2. 선택지 2: 명령에 반항하여 민간인을 살려낸다.\n");
                            // ... 추가 스토리 선택지 ...
                            printf("3. 선택지 3: 명령에 따라 민간인을 사살하지 않고, 명령에 대해 고발한다.\n");
                            printf("4. 선택지 4: 명령에 따라 민간인을 사살하지 않고, 사살한척하고 그 사실을 숨긴다..\n");
                            printf("선택: ");

                            start_time = time(NULL); // 시작 시간 기록

                            while (!_kbhit()) { // 키보드 입력 대기
                                time_t current_time = time(NULL);
                                if (current_time - start_time >= input_timeout) { // 제한 시간 초과 시
                                    choice = 1; // 자동으로 1번 선택
                                    break;
                                }
                            }

                            if (!_kbhit()) { // 키보드 입력이 없는 경우
                                printf("%d (자동 선택)\n", choice);
                                clearScreen();
                            }
                            else {
                                scanf("%d", &choice);
                                clearScreen();
                            }

                            switch (choice) {
                            case 1:
                                printf("주인공은 명령에 따라 행동하게 되고, 이로 인해 민간인이 희생되는 비참한 결과가 발생하였다 \n");
                                printf("주인공은 내면적인 갈등과 죄책감에 빠졌다 \n");
                                // 스토리 1에 따른 변수 값 변경
                                i += 20;
                                m -= 35;
                                y -= 35;
                            case 2:
                                printf("명령을 거부하고, 민간인을 구해내는 선택을 한다\n");
                                // 스토리 2에 따른 변수 값 변경
                                i -= 35;
                                m += 5;
                                y += 30;
                                break;
                                // ... 추가 스토리에 대한 처리 ...
                     
                            case 3:
                                printf("주인공은 명령을 거부하고 민간인을 살려낸 후, 언론에 폭로한다 .\n");
                                printf("주인공은 동료들과 상부의 질책을 받았지만 옳은 일을하였다고 생각한다 .\n");
                                // 스토리 3에 따른 변수 값 변경
                                i -= 40;
                                m += 20;
                                y += 30;
                                break;
                            case 4:
                                printf("주인공은 민간인을 살려낼 방법을 찾았습니다. 그렇게 해서 명령에는 따르지 않았지만,  .\n");
                                printf("상부는 이 사실을 모르고 언젠가 비밀이 밝혀질수 있습니다. . .\n\n");
                                // 스토리 3에 따른 변수 값 변경
                                i += 10;
                                m += 20;
                                y += 0;
                                break;
                            default:
                                printf("잘못된 선택입니다.\n");
                                continue;
                            }

                        }
                        //엔딩장치
                        printf("\n\n\n\n");
                        printf("-----------------------------엔딩---------------------------------");
                        if (m <= 0 ) {
                            printf("주인공은 죄책감에 못이겨 스스로 자신의 머리에 방아쇠를 당겼습니다.\n");
                        }
                     
                        else {
                            printf("현재 i: %d, m: %d, y: %d \n", i, m, y);
                            // 엔딩 조건에 따라 결과를 출력
                            if (i >= 80 && y >= 50 && m>=50) {
                                printf("\n\n\n해피 엔딩: 주인공은  뛰어난 임무 수행으로 인해 군인훈장을 받게 되었습니다.\n");
                            }
                            else if (i >= 80 && y <= 30 && m <= 40) {
                                printf("\n\n\n새드 엔딩: 주인공은 훈장을 받았지만 피묻은 훈장이였고 전쟁에서 겪은 ptsd로 힘든 삶을 살았다.\n");
                            }
                            else if (i >= 10 && y <= 10 && m <= 10) {
                                printf("\n\n\n베드 엔딩: 주인공은 전역후 전쟁ptsd에 시달리다 못이겨 스스로 목숨을 끊었다.\n");
                            }
                            else if (i <= 20 && y >= 50 && m >= 50) {
                                printf("\n\n\n배드엔딩:주인공은 명령 불복종 및 임무실패의 책임을 물어 군사법원에 회부됨.\n");
                            }
                            else {
                                printf("\n\n\n노멀엔딩:주인공은 군인으로써 나라에 애국하였고 전역하여 일반인으로써 별 ptsd없이 평범하게 살았다");
                            }
                 
                        }
                        return 0;
                    }
                }
            }
        }
    }
}
int main() {
    int game_state = 0; // 게임 상태 변수, 0 = 메뉴, 1 = 게임 실행 중
    int game_running = 1;
    int screen = 1; // 화면 상태 변수, 1 = 타이틀 스크린, 0 = 게임 설명 스크린
    char key_input = 0; // 사용자 입력을 저장할 변수

    while (game_running) {
        if (game_state == 0) { // 메뉴 상태일 때
            if (screen == 1) { // 타이틀 스크린 표시
                title_screen();
                screen = 0;
            }

            scanf(" %c", &key_input);

            if (key_input == '2') {
                introduce_screen();
                screen = 0; // 게임 설명 화면 출력
            }
            else if (key_input == '3') {
                break;
            }
            else if (key_input == '1') {
                clearScreen();
                game_bomb();
                game_impl(); // 게임 구현체 실행
                break;
            }
        }
        else { // 게임 설명 상태일 때
            introduce_screen();
            printf("Return to menu?\n");
            printf("1. Yes\n");
            printf("2. No\n");

            scanf(" %c", &key_input);

            if (key_input == '1') {
                game_state = 0;
                screen = 1; // 메뉴 화면 출력
            }
            else if (key_input == '2') {
                introduce_screen();
                printf("Return to menu?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                screen = 0; // 게임 설명 화면 출력
            }
        }
    }

    return 0;
}
