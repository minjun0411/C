#include <stdio.h>

void a(int store[]) {
    int id;
    int select;

    printf("입고 수량 입력: 전체 상품 입고 수량 입력 1, 개별 상품 입력 2를 선택: ");
    scanf("%d", &select);
    if (select == 1) {
        printf("전체 상품 입고 수량을 입력하세요 (5개):\n");
        for (int i = 0; i < 5; i++) {
            if (scanf("%d", &store[i]) != 1) {
                printf("잘못된 입력입니다.\n");
                return;
            }
        }
    } else if (select == 2) {
        printf("상품 ID (1-5): ");
        scanf("%d", &id);
        if (id < 1 || id > 5) {
            printf("유효한 ID는 1에서 5 사이여야 합니다.\n");
            return;
        }
        printf("입고수량: ");
        scanf("%d", &store[id - 1]);
    }
}

void b(int sale[]) {
    int id;
    int select;

    printf("전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택: ");
    scanf("%d", &select);
    if (select == 1) {
        printf("전체 상품 판매 수량을 입력하세요 (5개):\n");
        for (int i = 0; i < 5; i++) {
            if (scanf("%d", &sale[i]) != 1) {
                printf("잘못된 입력입니다.\n");
                return;
            }
        }
    } else if (select == 2) {
        printf("상품 ID (1-5): ");
        scanf("%d", &id);
        if (id < 1 || id > 5) {
            printf("유효한 ID는 1에서 5 사이여야 합니다.\n");
            return;
        }
        printf("판매수량: ");
        scanf("%d", &sale[id - 1]);
    }
}

void c(int store[], int sale[], char name[][20]) {
    int total_sales = 0;
    float sales_rate;
    int max_sales = 0;
    int max_sales_id = 0;
    int min_sales;
    int min_sales_id = 0;

    for (int i = 0; i < 5; i++) {
        total_sales += sale[i];

        if (sale[i] > max_sales) {
            max_sales = sale[i];
            max_sales_id = i + 1;
        }
        if (i == 0) {
            min_sales = sale[i];
            min_sales_id = i + 1;
        } else if (sale[i] < min_sales) {
            min_sales = sale[i];
            min_sales_id = i + 1;
        }
    }

    printf("재고수량 : ");
    for (int i = 0; i < 5; i++) {
        int remaining = store[i] - sale[i];
        printf("%d ", remaining);
    }

    if (total_sales > 0) {
        float a = 0, b = 0;
        for (int i = 0; i < 5; i++) {
            a += sale[i];
            b += store[i];
        }
        sales_rate = (a / b) * 100;

        printf("\n총 판매량 : %d (판매율 %.2f%%)\n", total_sales, sales_rate);
        printf("가장 많이 판매된 상품 ID: %d, 상품명 : %s 판매량: %d\n", max_sales_id, name[max_sales_id-1], max_sales);
        printf("가장 적게 판매된 상품 ID: %d, 상품명 : %s 판매량: %d\n", min_sales_id, name[min_sales_id-1], min_sales);
        for (int i = 0; i < 5; i++) {
        int remaining = store[i] - sale[i];
        if (remaining <= 2) {
            printf("상품 ID %d : 상품명 : %s 재고 부족 (%d)\n", i + 1, name[i], remaining);
        }
    }
    } else {
        printf("판매가 이루어지지 않았습니다.\n");
    }
}

void d(char name[][20]) {
    for (int i = 0; i < 5; i++) {
        printf("ID %d 상품명: ", i + 1);
        scanf("%s", name[i]);  // 각 상품명 입력
    }
}

int main() {
    int menu;
    int store[5] = {0}; // 재고 배열 초기화
    int sale[5] = {0};  // 판매 배열 초기화
    char name[5][20];   // 상품명을 저장할 2차원 배열
    while (1) {
        printf("> 원하는 메뉴를 선택하세요 (1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력, 5. 종료): ");
        scanf("%d", &menu);
        if (menu == 1) {
            a(store);
        } else if (menu == 2) {
            b(sale);
        } else if (menu == 3) {
            c(store, sale, name);  // 상품명 배열 전달
        } else if (menu == 4) {
            d(name);
        } else if (menu == 5) {
            break;
        } else {
            printf("잘못된 선택입니다.\n");
        }
    }
    return 0;
}
