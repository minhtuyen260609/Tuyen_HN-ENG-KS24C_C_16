#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPrime(int num);
void inputArray(int **arr, int *size);
void printEvenNumbers(int *arr, int size);
void printPrimeNumbers(int *arr, int size);
void reverseArray(int *arr, int size);
void sortArray(int *arr, int size, bool ascending);
void searchElement(int *arr, int size);

int main() {
    int *arr = NULL;
    int size = 0;
    int choice;

    do {
        printf("\n\tMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        if (choice == 1) {
            inputArray(&arr, &size);
        } else if (choice == 2) {
            if (arr == NULL || size == 0) {
                printf("Mang trong. Vui long nhap mang truoc.\n");
            } else {
                printEvenNumbers(arr, size);
            }
        } else if (choice == 3) {
            if (arr == NULL || size == 0) {
                printf("Mang trong. Vui long nhap mang truoc.\n");
            } else {
                printPrimeNumbers(arr, size);
            }
        } else if (choice == 4) {
            if (arr == NULL || size == 0) {
                printf("Mang trong. Vui long nhap mang truoc.\n");
            } else {
                reverseArray(arr, size);
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        } else if (choice == 5) {
            if (arr == NULL || size == 0) {
                printf("Mang trong. Vui long nhap mang truoc.\n");
            } else {
                int sortChoice;
                printf("\tMENU SAP XEP\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &sortChoice);
                if (sortChoice == 1) {
                    sortArray(arr, size, true);
                    printf("Mang sau khi sap xep tang dan: ");
                } else if (sortChoice == 2) {
                    sortArray(arr, size, false);
                    printf("Mang sau khi sap xep giam dan: ");
                } else {
                    printf("Lua chon khong hop le.\n");
                    continue;
                }
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        } else if (choice == 6) {
            if (arr == NULL || size == 0) {
                printf("Mang trong. Vui long nhap mang truoc.\n");
            } else {
                searchElement(arr, size);
            }
        } else if (choice == 7) {
            printf("Thoat chuong trinh.\n");
        } else {
            printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 7);

    free(arr);
    return 0;
}

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void inputArray(int **arr, int *size) {
    printf("Nhap so phan tu: ");
    scanf("%d", size);
    *arr = (int *)malloc(*size * sizeof(int));
    if (*arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    for (int i = 0; i < *size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}

void printEvenNumbers(int *arr, int size) {
    printf("Cac so chan trong mang: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void printPrimeNumbers(int *arr, int size) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void sortArray(int *arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void searchElement(int *arr, int size) {
    int target, found = 0;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &target);
    printf("Phan tu %d xuat hien o vi tri: ", target);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", target);
    } else {
        printf("\n");
    }
}
