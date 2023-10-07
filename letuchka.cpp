//@brief приблизительная сигнатура функции
//@param num число которое, должно быть преобразовано в строку
//@return C-строка  согласно варианту
// Панова Дарья ИУ10-16 Вариант 2
#include <iostream>
using namespace std;

int get_int_lenght(int num){
    int result = 0;
    if (num == 0){
        return 1;
    }
    
    while (num != 0){
        result +=1;
        num /= 10;
    
    }
    return result;
}


char * intToDec(int num){
    int two_or_one;
    bool is_negative;
    if (num < 0){
        two_or_one = 2;
        is_negative = true;
        num = -num;

    } else {
        two_or_one = 1;
        is_negative = false;
    }
    int total_lenght = 3;
    if (is_negative){
        total_lenght += 1;

    }

    total_lenght += get_int_lenght(num);
    char* result = new char[total_lenght];// динамическая память new

    for (int index = total_lenght - 2;index > two_or_one; --index){
        int rem = num % 10;
        char symdol = rem +'0';
        result[index] = symdol;
        num /=10;
         
    }
    if (is_negative){
        result[0] = '-';
        result[1] = '0';
        result[2] = 'd';
    } else {
        result[0] = '0';
        result[1] = 'd';
    }
    result[total_lenght - 1] = '\0';

    return result;
  
    // return nullptr;
}
int main(){
    int n;
    cin >>n;
    cout << intToDec(n) << endl;
}