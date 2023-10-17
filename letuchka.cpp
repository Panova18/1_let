//@brief приблизительная сигнатура функции
//@param num число которое, должно быть преобразовано в строку
//@return C-строка  согласно варианту
// Панова Дарья ИУ10-16 Вариант 2
#include <iostream>
#include <assert.h>


using namespace std;

int lenght(int num) { 
    int result = 0;
    if (num == 0) { 
        return 1;
    }

    while (num != 0) {
        result += 1;
        num /= 10;

    }
    return result;
}


char *intToDec(int num) {
    int two_or_one;
    bool is_negative;
    if (num < 0) {
        two_or_one = 2;
        is_negative = true;
        num = -num;

    } else {
        two_or_one = 1;
        is_negative = false;
    }
    int total_lenght = 3;
    if (is_negative) {
        total_lenght += 1;

    }

    total_lenght += lenght(num);
    char *result = new char[total_lenght];

    for (int index = total_lenght - 2; index > two_or_one; --index) {
        int rem = num % 10;
        char symdol = rem + '0';
        result[index] = symdol;
        num /= 10;
    }
    if (is_negative) {
        result[0] = '-';
        result[1] = '0';
        result[2] = 'd';
    } else {
        result[0] = '0';
        result[1] = 'd';
    }
    result[total_lenght - 1] = '\0';

    return result;
}

bool cStringsEqual(const char *left, const char *right) {
    while (*left != '\0' && *right != '\0') {
        if (*left != *right) {
            return false;
        }
        left++;
        right++;
    }
    return *left == *right;
}

int main() {
    assert(cStringsEqual(intToDec(123), "0d123"));
    assert(cStringsEqual(intToDec(-123), "-0d123"));
    assert(cStringsEqual(intToDec(0), "0d0"));
}