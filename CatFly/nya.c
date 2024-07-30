#include <stdio.h>
#include <string.h>
#include <stdbool.h>

unsigned int dword_E1E8 = 0x1106;
unsigned int dword_E120[50] = {0x27FB, 0x27A4, 0x464E, 0x0E36, 0x7B70, 0x5E7A, 0x1A4A, 0x45C1, 0x2BDF, 0x23BD, 0x3A15, 0x5B83, 0x1E15, 0x5367, 0x50B8, 0x20CA, 0x41F5, 0x57D1, 0x7750, 0x2ADF, 0x11F8, 0x9BB, 0x5724, 0x7374, 0x3CE6, 0x646E, 0x10C, 0x6E10, 0x64F4, 0x3263, 0x3137, 0x0B8, 0x229C, 0x7BCD, 0x73BD, 0x480C, 0x14DB, 0x68B9, 0x5C8A, 0x1B61, 0x6C59, 0x5707, 0x9E6, 0x1FB9, 0x2AD3, 0x76D4, 0x3113, 0x7C7E, 0x11E0, 0x6C70};

int a1 = 0;
int a2 = 18;
// int a3 = 4; // .. 53;

int dword_108E0 = 0;

// 计算数字的位数
int getDigits(int num) {
    int count = 0;
    if (num == 0) {
        return 1;
    }
    while (num > 0) {
        count++;       // 增加位数计数
        num /= 10;     // num除以10
    }
    return count;
}

bool sub_62E3(char a)
{
    return (a & 0x7Fu) <= 0x7E && (a & 0x7Fu) > 0x20;
}

int sub_62B5()
{
    dword_E1E8 = 1103515245 * dword_E1E8 + 12345;
    return (dword_E1E8 >> 10) & 0x7FFF;
}

int main() {
    char flag[50];
    while (1) {
        for (int i = 5; i < 55; i++) {
            dword_E120[i - 5] ^= sub_62B5();
            if ( sub_62E3(dword_E120[i - 5]) ) {
                flag[i - 5] = dword_E120[i - 5] & 0x7F;
            } else {
                flag[i - 5] = 32;
            }
        }
        if (!strncmp(flag, "CatCTF", 6)) {
            printf("%s", flag);
            break;
        }
        dword_E1E8 += 41; // printf return char count.
        dword_E1E8 += getDigits(++dword_108E0);
    }
    return 0;
}