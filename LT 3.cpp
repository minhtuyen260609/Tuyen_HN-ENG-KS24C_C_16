#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void inputString(char **str);
void printReverseString(char *str);
int countWords(char *str);
void compareStrings(char *str);
void convertToUpper(char *str);
void appendStrings(char **str);
int main(){
    char *str=NULL;
    int choice;
    do {
        printf("\n\tMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. So sanh chuoi khac voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Them chuoi khac vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        if (choice == 1) {
            inputString(&str);
        } else if (choice == 2) {
            printReverseString(str);
        } else if (choice == 3) {
            printf("So luong tu trong chuoi: %d\n", countWords(str));
        } else if (choice == 4) {
            compareStrings(str);
        } else if (choice == 5) {
            convertToUpper(str);
            printf("Chuoi in hoa: %s\n", str);
        } else if (choice == 6) {
            appendStrings(&str);
        } else if (choice == 7) {
            printf("Thoat chuong trinh.\n");
        } else {
            printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 7);
	    if (str) {
	        free(str);
    }
    return 0;
}

void inputString(char **str) {
    char temp[1000];
    printf("Nhap vao chuoi: ");
    fgets(temp, 1000, stdin);
    temp[strcspn(temp, "\n")] = '\0'; // Lo?i b? k? t? xu?ng d?ng

    *str = (char *)malloc((strlen(temp) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    strcpy(*str, temp);
}

void printReverseString(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao duoc nhap.\n");
        return;
    }
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int countWords(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao duoc nhap.\n");
        return 0;
    }
    int count = 0, inWord = 0;
    while (*str) {
        if (isspace(*str)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

void compareStrings(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao duoc nhap.\n");
        return;
    }
    char temp[1000];
    printf("Nhap vao chuoi khac: ");
    fgets(temp, 1000, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    int len1 = strlen(str);
    int len2 = strlen(temp);

    if (len1 > len2) {
        printf("Chuoi vua nhap ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi vua nhap dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void convertToUpper(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao duoc nhap.\n");
        return;
    }
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void appendStrings(char **str) {
    if (*str == NULL) {
        printf("Chua co chuoi nao duoc nhap.\n");
        return;
    }
    char temp[1000];
    printf("Nhap vao chuoi khac: ");
    fgets(temp, 1000, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    *str = (char *)realloc(*str, (strlen(*str) + strlen(temp) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    strcat(*str, temp);
    printf("Chuoi sau khi noi: %s\n", *str);
}

