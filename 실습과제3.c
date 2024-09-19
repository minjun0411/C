#include <stdio.h>
int a(){
    
    int store[5];
    int id;

    printf("상품 별 입고 수량 입력 : ");
    for (int i = 0; i < 5; i++) {
        if (scanf("%d", &store[i]) != 1) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }
    }


    printf("id 입력 : ");
    if (scanf("%d", &id) != 1) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    if (id < 1 || id > 5) {
        printf("유효한 ID는 1에서 5 사이여야 합니다.\n");
        return 1;
    }
    printf("입고 수량 : %d", store[id-1]);

}
int b(){
    
    int sale[5];
    int id;

    printf("상품 별 판매 수량 입력 : ");
    for (int i = 0; i < 5; i++) {
        if (scanf("%d", &sale[i]) != 1) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }
    }


    printf("id 입력 : ");
    if (scanf("%d", &id) != 1) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    if (id < 1 || id > 5) {
        printf("유효한 ID는 1에서 5 사이여야 합니다.\n");
        return 1;
    }
    printf("판매 수량 : %d", sale[id-1]);
}
int c(){
    int store[5];
    int sale[5];
    int id;
    int total_sales = 0;
    float sales_rate;
    int max_sales = 0;
    int max_sales_id = 0;
    int min_sales;
    int min_sales_id = 0;
    int list[5];

    
    

    printf("상품 별 입고 수량 입력 : ");
    for (int i = 0; i < 5; i++) {
        if (scanf("%d", &store[i]) != 1) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }
    }

    printf("상품 별 판매 수량 입력 : ");
    for (int i = 0; i < 5; i++) {
        if (scanf("%d", &sale[i]) != 1) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }
        total_sales += sale[i];  // 각 판매 수량을 더해서 총 판매량 계산

        // 최대 판매량을 찾는 부분
        if (sale[i] > max_sales) {
            max_sales = sale[i];
            max_sales_id = i + 1;  // ID는 1부터 시작하므로 i + 1로 설정
        }
        // 최소 판매량을 첫 번째 상품으로 초기화 후 찾는 부분
        if (i == 0) {
            min_sales = sale[i];
            min_sales_id = i + 1;
        }
        else if (sale[i] < min_sales) {
            min_sales = sale[i];
            min_sales_id = i + 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        list[i] = store[i] - sale[i];
    }


    printf("id 입력 : ");
    if (scanf("%d", &id) != 1) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    if (id < 1 || id > 5) {
        printf("유효한 ID는 1에서 5 사이여야 합니다.\n");
        return 1;
    }

    printf("%d\n", list[id - 1]);
    for (int i = 0; i < sizeof(list) / sizeof(int); i++)
    {
        printf("%d ", list[i]);
    }

    float a = 0, b = 0;
    for (int i = 0; i<5;i++){
        a += sale[i];
        b += store[i];
    }

    sales_rate = a/b*100;

    printf("\n총 판매량 : %d (판매율 %.2f%% )\n", total_sales, sales_rate);

    printf("가장 많이 판매된 상품 ID: %d, 판매량: %d\n", max_sales_id, max_sales);

    printf("가장 적게 판매된 상품 ID: %d, 판매량: %d\n", min_sales_id, min_sales);

    for (int i = 0; i < 5; i++) {
        if (list[i] <= 2) {
            printf("상품 ID %d : 재고 부족 (%d)\n", i + 1, list[i]);
        }
    }
}
int main()
{
    int menu;
    while(1){
        printf("> 원하는 메뉴를 선택하세요 (1. 입고, 2. 판매, 3. 상품현황, 4. 종료) \n> ");
        scanf("%d", &menu);
        if(menu==1) a();
        else if(menu==2) b();
        else if(menu==3) c();
        else if(menu==4) break;
    }

    return 0;
}
