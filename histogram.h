#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include <vector>
#include <iostream>
using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(const vector<double>& numbers, size_t min, size_t max, size_t& bin_count);
void show_histogram_text(const vector<size_t>& bins);

#endif // HISTOGRAM_H_INCLUDED
