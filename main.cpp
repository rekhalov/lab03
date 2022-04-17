#include <iostream>
#include <vector>
#include <math.h>
#include <locale.h>
#include "histogram.h"

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

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}
void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='"<< baseline << "'>'"<< text <<"'</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black"){
    cout << "<rect x='"<< x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"' stroke='"<< stroke <<"' fill='"<< fill <<"'></rect>\n";

}

void show_histogram_svg(const vector<size_t>& bins)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t bin : bins)
    {
        const double bin_width = BLOCK_WIDTH * bin;

        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "#CD5C5C", "#CD5C5C");
        top += BIN_HEIGHT;

    }
    svg_end();

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

    // Обработка данных
    double min, max;
    find_minmax(numbers,min,max);

    const auto bins = make_histogram(numbers, bin_count, min, max);

    // Вывод данных
    /*show_histogram_text(bins);
    */


    show_histogram_svg(bins);

    return 0;
}
