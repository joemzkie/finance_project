#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <numeric>
#include <cmath> // Needed for sqrt and pow

namespace py = pybind11;

class FinancialTools {
public:
    // Keep your original SMA function
    std::vector<double> calculate_sma(const std::vector<double>& prices, int window) {
        std::vector<double> sma_values;
        if (prices.size() < window) return sma_values;

        for (size_t i = 0; i <= prices.size() - window; ++i) {
            double sum = 0.0;
            for (size_t j = 0; j < window; ++j) {
                sum += prices[i + j];
            }
            sma_values.push_back(sum / window);
        }
        return sma_values;
    }

    // NEW: Calculate Bollinger Bands
    // Returns a Python Tuple: (SMA, Upper Band, Lower Band)
    std::tuple<std::vector<double>, std::vector<double>, std::vector<double>> 
    calculate_bollinger(const std::vector<double>& prices, int window, double num_std_dev) {
        
        std::vector<double> sma;
        std::vector<double> upper;
        std::vector<double> lower;

        if (prices.size() < window) return std::make_tuple(sma, upper, lower);

        // Loop through the data
        for (size_t i = 0; i <= prices.size() - window; ++i) {
            // 1. Calculate Mean (SMA)
            double sum = 0.0;
            for (size_t j = 0; j < window; ++j) {
                sum += prices[i + j];
            }
            double mean = sum / window;
            sma.push_back(mean);

            // 2. Calculate Standard Deviation
            double sq_sum = 0.0;
            for (size_t j = 0; j < window; ++j) {
                double val = prices[i + j];
                sq_sum += std::pow(val - mean, 2);
            }
            double std_dev = std::sqrt(sq_sum / window);

            // 3. Calculate Bands
            upper.push_back(mean + (std_dev * num_std_dev));
            lower.push_back(mean - (std_dev * num_std_dev));
        }

        return std::make_tuple(sma, upper, lower);
    }
};

PYBIND11_MODULE(finance_core, m) {
    py::class_<FinancialTools>(m, "FinancialTools")
        .def(py::init<>())
        .def("calculate_sma", &FinancialTools::calculate_sma)
        .def("calculate_bollinger", &FinancialTools::calculate_bollinger);
}