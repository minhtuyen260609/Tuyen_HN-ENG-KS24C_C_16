#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void inputString(char **str);
void printString(char *str);
int countLetters(char *str);
int countDigits(char *str);
int countSpecialChars(char *str);
int main(){
    char *str = NULL;
    int choice;
    do{
        printf("\n\tMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        if (choice == 1) {
            inputString(&str);
        } else if (choice == 2) {
            printString(str);
        } else if (choice == 3) {
            printf("So luong chu cai trong chuoi: %d\n", countLetters(str));
        } else if (choice == 4) {
            printf("So luong chu so trong chuoi: %d\n", countDigits(str));
        } else if (choice == 5) {
            printf("So luong ky tu dac biet trong chuoi: %d\n", countSpecialChars(str));
        } else if (choice == 6) {
            printf("Thoat chuong trinh.\n");
        } else {
            printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while(choice != 6);
    	if(str){
        	free(str); 
    	}
    return 0;
}

void inputString(char **str) {
    char temp[1000];
    printf("Nhap vao chuoi: ");
    fgets(temp, 1000, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    *str = (char*)malloc((strlen(temp) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    strcpy(*str, temp);
}

void printString(char *str) {
    if (str != NULL) {
        printf("Chuoi da nhap: %s\n", str);
    } else {
        printf("Chua co chuoi nao duoc nhap.\n");
    }
}

int countLetters(char *str) {
    int count = 0;
    if (str != NULL) {
        while (*str) {
            if (isalpha(*str)) count++;
            str++;
        }
    }
    return count;
}

int countDigits(char *str) {
    int count = 0;
    if (str != NULL) {
        while (*str) {
            if (isdigit(*str)) count++;
            str++;
        }
    }
    return count;
}

int countSpecialChars(char *str) {
    int count = 0;
    if (str != NULL) {
        while (*str) {
            if (!isalnum(*str) && !isspace(*str)) count++;
            str++;
        }
    }
    return count;
}

