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
read_input(istream& in) {
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    cerr << "Enter column count: ";
    in >> data.bin_count;

    return data;
}

int main()
{
    Input input;
    input = read_input(cin);

    // ������ ���������� ����� � �������� �����������
    const auto bins = make_histogram(input);

    // ����� ������
    // ����������� �����������
    show_histogram_svg(bins);

    return 0;
}
