#include <iostream>
#include <vector>
#include <windows.h>

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
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD mask_2 = 0x000000ff;
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    if ((info & 0x80000000) == 0)
    {
        DWORD version_major = version & mask_2;
        DWORD version_minor = version >> 8;
        DWORD build = platform;
        printf("Windows v%u.%u (build %u)\n", version_major, version_minor, build);
    }

    DWORD size = MAX_COMPUTERNAME_LENGTH+1;
    char computer_name[size];
    GetComputerNameA(computer_name, &size);
    printf("Computer name: %s\n", computer_name);

    return 0;

   /* // Ввод данных
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
*/
    return 0;
}
