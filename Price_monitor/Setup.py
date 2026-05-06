from setuptools import setup, Extension
import pybind11

# Define the extension module
cpp_args = ['-std=c++20'] # Using C++17 as you prefer

ext_modules = [
    Extension(
        'finance_core',
        ['finance_core.cpp'],
        include_dirs=[pybind11.get_include()],
        language='c++',
        extra_compile_args=cpp_args,
    ),
]

setup(
    name='finance_core',
    version='1.0',
    description='C++ Technical Analysis Extensions',
    ext_modules=ext_modules,
)