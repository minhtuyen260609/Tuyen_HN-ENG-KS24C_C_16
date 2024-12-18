#include <stdio.h>
void sortArray(int *arr, int size);
int main() {
    int arr[] = {12, 4, 7, 1, 9, 15, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Mang ban dau: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    sortArray(arr, size);
    printf("Mang sau khi sap xep tang dan: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    return 0;
}
void sortArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

