#include <iostream>
#include <vector>
#include <math.h>
#include <locale.h>
#include "histogram.h"
#include "svg.h"
using namespace std;

vector<double> input_numbers(size_t count) //функция ввода чисел
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

int main()
{
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";

    // Ввод чисел заменен вызовом функции:
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count);

    show_histogram_svg(bins);

    return 0;
}
