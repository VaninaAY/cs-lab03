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


int main()
{
    const char* name = "Commander Shepard";
    int year = 2154;
    printf("%s was born in %d.\n", name, year);
    printf("n = %08x\n", 0x1234567);
    return 0;

    // Ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count); //функция ввовда чисел

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    string stroke;
    cerr << "Enter stroke color (black, red, blue, green or yellow): ";
    cin >> stroke;

    string fill;
    cerr << "Enter fill color (black, red, blue,green or yellow): ";
    cin >> fill;


    if(check_color(stroke))
        return 1;

    if(check_color(fill))
        return 1;


    // Обработка данных
    // поиск min и max
    double min, max;
    find_minmax(numbers, min, max);

    // расчет количества чисел в столбцах гистограммы
    const auto bins = make_histogram(numbers, min, max, bin_count);

    // Вывод данных
    // отображение гистограммы
    show_histogram_svg(bins,stroke,fill);

    return 0;
}
