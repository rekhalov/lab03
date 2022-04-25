#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max); //ôóíêöèÿ ïîèñêà ìèíèìóìà è ìàêñ
vector<size_t> make_histogram (vector<double>numbers, size_t bin_count);
void show_histogram_text(vector<size_t> bins);

#endif // HISTOGRAM_H_INCLUDED
