#include <stdio.h>
int findElement(int *arr, int n, int giaTriTimKiem) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == giaTriTimKiem) {
            return i;
        }
    }
    return -1;
}
int main() {
    int mang[] = {1, 2, 4, 5, 6, 7};
    int size = sizeof(mang) / sizeof(mang[0]);
    int giaTriTim = 7;
    int viTri = findElement(mang, size, giaTriTim);
    if (viTri != -1) {
        printf("%d", viTri);
    } else {
        printf("Khong tim thay");
    }
    return 0;
}

