#include <stdlib.h>
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}POINT;

int inputMenu(void){
    int input;
    printf("메뉴입력(1.구조체 만들기, 2.구조체 출력하기, -1.종료 : ");
    scanf("%d", &input);
    return input;
}

int main()
{
    int menu;
    POINT pt;
    
    do{
        menu = inputMenu();
        if(menu == 1){
            printf("구조체의 x 값을 입력하세요: ");
            scanf("%d", &pt.x);
            printf("구조체의 y 값을 입력하세요: ");
            scanf("%d", &pt.y);
        }
        else if(menu ==2){
            printf("구조체의 x 값: %d\n", pt.x);
            printf("구조체의 y 값: %d\n", pt.y);
        }
        else if(menu == -1){
            printf("프로그램을 종료합니다.\n");
        }
    }while(menu > 0);
    
    return 0;
}
