/*
g++ pleakyReLU.cpp -o pleakyReLU -I/usr/include/python3.9 -I./env/lib/python3.9/site-packages/numpy/core/include -lpython3.9                          
*/

#include <iostream>
#include <vector>
#include <functional>
#include <boost/math/differentiation/finite_difference.hpp>
#include <boost/format.hpp>

#include "matplotlibcpp.h"

using namespace boost::math::differentiation;
using namespace std::placeholders;
namespace plt = matplotlibcpp;

double pleakyReLU(double x, double alpha)
{
    if (x < 0)
        return alpha * x;
    return 0;
}

namespace fn
{
    std::vector<double> arange(double start, double end, double step)
    {
        std::vector<double> res;
        for (double x = start; x < end; x += step)
            res.push_back(x);

        return res;
    }

    std::vector<double> linspace(double start, double end, double n, bool endpoint = false)
    {
        double step = (end - start) / (n - endpoint);
        return arange(start, end, step);
    }
};

int main()
{
    std::vector<double> xs = fn::linspace(-10, 10, 1e4, true), errs, ys, dfdxs;

    double defaultAlpha = 0.5;
    auto f = bind(pleakyReLU, _1, defaultAlpha);

    for (auto &x : xs)
    {
        double err;
        double y = f(x);
        double dReLUdx = finite_difference_derivative(f, x, &err);

        errs.push_back(err);
        ys.push_back(y);
        dfdxs.push_back(dReLUdx);
    }

    plt::title("Pleaky ReLU representation");
    plt::plot(xs, errs, {{"label", "Errors"}});
    plt::plot(xs, dfdxs, {{"label", "Pleaky ReLU Derivative"}});
    plt::plot(xs, ys, {{"label", "Pleaky ReLU"}});
    plt::grid(true);
    plt::legend();
    plt::show();

    return 0;
}