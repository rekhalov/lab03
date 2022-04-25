#include <iostream>
#include <vector>
#include <math.h>
#include "svg.h"

using namespace std;

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

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='"<< x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"' stroke='"<< stroke <<"' fill='"<< fill <<"'></rect>\n";

}

void show_histogram_svg(const vector<size_t>& bins, size_t BIN_HEIGHT)//BIN_HEIGHT-высоота столбца, которую мы вводим
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 700;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BLOCK_WIDTH = 10;
    const auto HISTOGRAM_MAX_WIDTH = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;
    size_t max_bin = bins[0];
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;

    for (size_t bin : bins)
    {
        if (max_bin < bin) max_bin = bin;//больше этого значения
    }

    test_height(BIN_HEIGHT,bins.size(),IMAGE_HEIGHT);

    for (size_t bin : bins)
    {
        size_t height = bin;

        const double bin_width = BLOCK_WIDTH * bin;

        if (max_bin * BLOCK_WIDTH > HISTOGRAM_MAX_WIDTH)
        {
            height = HISTOGRAM_MAX_WIDTH * (static_cast<double> (bin) / (max_bin * BLOCK_WIDTH));
        }

        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "#CD5C5C", "#CD5C5C");
        top += BIN_HEIGHT;

    }
    svg_end();

}
void test_height(size_t &height_bin,size_t bins_count, const size_t IMAGE_HEIGHT)
{
    if (height_bin * bins_count > IMAGE_HEIGHT)
    {
        height_bin = (IMAGE_HEIGHT/bins_count);
    }
}
