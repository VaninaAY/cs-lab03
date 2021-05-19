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

Input
read_input(istream& in, bool promt) {
    Input data;

    if(promt)
    cerr << "Enter number count: ";

    size_t number_count;
    in >> number_count;

    if(promt)
    cerr << "Enter numbers: ";

    data.numbers = input_numbers(in, number_count);

    if(promt)
    cerr << "Enter column count: ";

    in >> data.bin_count;

    return data;
}

int main()
{

    const auto input = read_input(cin, true);

    // расчет количества чисел в столбцах гистограммы
    const auto bins = make_histogram(input);

    // Вывод данных
    // отображение гистограммы
    show_histogram_svg(bins);

    return 0;
}
