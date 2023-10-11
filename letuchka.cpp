//@brief приблизительная сигнатура функции
//@param num число которое, должно быть преобразовано в строку
//@return C-строка  согласно варианту
// Панова Дарья ИУ10-16 Вариант 2
#include <iostream>


// Ошибки по стилю кода:
// Правлю первый и последний раз
// 1. Необходимо использовать camelCase либо under_score
// 2. Необходимо использовать const там, где это возможно
// 3. Добавляйте в .gitignore файлы, которые не должны попадать в репозиторий к примеру файлы сборки

// Можем собраться и подумать
// get_int_lengh - название функции не соответствует ее действию -> правильно length
// Нужна ли нам эта функция вообще
// Максимальное int число 2147483647 -> 10 символов, следовательно мы можем выделить 11 + 3 символов
// 10 для числа 1 для знака два для 0x и один для \0
// Зато сложность нашего алгоритма будет O(n) где n - длина числа
// Мы же проходим по числу дважды, следовательно сложность O(2n), что конечно в глобальном смысле роли не играет
// Но все же

// Необходимо добавить в .gitignore файлы сборки
// Необходимо написать тесты используя assert()

// хау ту юз ассерт ?
// #include <cassert>
// assert(1 == 2);

using namespace std;

int get_int_lenght(int num) { // length ? -> get_int_length ? глицин ?
    int result = 0;
    if (num == 0) { // <- стиль кода
        return 1;
    }

    while (num != 0) {// <- стиль кода
        result += 1;// <- стиль кода
        num /= 10;
// <- стиль кода
    }
    return result;
}


char *intToDec(int num) {// <- стиль кода
    int two_or_one;
    bool is_negative;
    if (num < 0) {// <- стиль кода
        two_or_one = 2;
        is_negative = true;
        num = -num;

    } else {
        two_or_one = 1;
        is_negative = false;
    }
    int total_lenght = 3;
    if (is_negative) {// <- стиль кода
        total_lenght += 1;

    }

    total_lenght += get_int_lenght(num);
    char *result = new char[total_lenght];// динамическая память new // <- стиль кода

    for (int index = total_lenght - 2; index > two_or_one; --index) {// <- стиль кода
        int rem = num % 10;
        char symdol = rem + '0';// <- стиль кода
        result[index] = symdol;
        num /= 10;// <- стиль кода
    }
    if (is_negative) {// <- стиль кода
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

int main() {
    int n;
    cin >> n;
    cout << intToDec(n) << endl;
}