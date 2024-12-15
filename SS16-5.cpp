#include <stdio.h>
void capNhatPhanTu(int *arr, int viTri, int giaTriMoi);
void inMang(int *arr, int n);
int main() {
    int mang[] = {1, 2, 3, 4, 5};
    int kichThuoc = sizeof(mang) / sizeof(mang[0]);
    capNhatPhanTu(mang, 2, 10);
    inMang(mang, kichThuoc);
    return 0;
}

void capNhatPhanTu(int *arr, int viTri, int giaTriMoi) {
    arr[viTri] = giaTriMoi;
}

void inMang(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

