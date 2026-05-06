#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}


double get_return(double old_price, double new_price) {
    if (old_price == 0) return 0.0; // Prevent crash
    return (new_price - old_price) / old_price;
}

PYBIND11_MODULE(fintech_math, m) {
    m.doc() = "My custom fintech library";

    
    m.def("add", &add, "A function that adds two numbers");

   
    m.def("get_return", &get_return, "Calculate percentage return");
}