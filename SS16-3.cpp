#include <stdio.h>
void tinhTong(int *a, int *b, int *ketQua);
int main() {
    int x = 5, y = 7, ketQua;
    tinhTong(&x, &y, &ketQua);
    printf("Tong: %d\n", ketQua);
    return 0;
}

void tinhTong(int *a, int *b, int *ketQua) {
    *ketQua = *a + *b;
}
