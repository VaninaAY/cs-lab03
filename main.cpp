#include <iostream>
#include <vector>

using namespace std;

#include "histogram.h"
#include "svg.h"
#include "check.h"


vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

vector<double>
input_numbers(istream& in, size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        in >> result[i];
    }
    return result;
}

int main()
{
    // Ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(cin,number_count); //функция ввовда чисел

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;


    // Обработка данных
    // поиск min и max
    double min, max;
    find_minmax(numbers, min, max);

    // расчет количества чисел в столбцах гистограммы
    const auto bins = make_histogram(numbers, min, max, bin_count);

    // Вывод данных
    // отображение гистограммы
    show_histogram_svg(bins);

    return 0;
}
