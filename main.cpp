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
    // ���� ������
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(cin,number_count); //������� ������ �����

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;


    // ��������� ������
    // ����� min � max
    double min, max;
    find_minmax(numbers, min, max);

    // ������ ���������� ����� � �������� �����������
    const auto bins = make_histogram(numbers, min, max, bin_count);

    // ����� ������
    // ����������� �����������
    show_histogram_svg(bins);

    return 0;
}
