#include <pybind11/pybind11.h>

namespace py = pybind11;

// --- Function 1: Simple Addition ---
int add(int i, int j) {
    return i + j;
}

// --- Function 2: Calculate Stock Return (NEW) ---
// (New price - Old price) / Old price
double get_return(double old_price, double new_price) {
    if (old_price == 0) return 0.0; // Prevent crash
    return (new_price - old_price) / old_price;
}

PYBIND11_MODULE(fintech_math, m) {
    m.doc() = "My custom fintech library";

    // Register Function 1
    m.def("add", &add, "A function that adds two numbers");

    // Register Function 2 (NEW)
    m.def("get_return", &get_return, "Calculate percentage return");
}