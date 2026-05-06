from setuptools import setup, Extension
import pybind11

# Force C++17 to ensure compatibility with VS 2022
cpp_args = ['/std:c++17']

ext_modules = [
    Extension(
        'fintech_math',
        ['example.cpp'],
        include_dirs=[pybind11.get_include(), pybind11.get_include(user=True)],
        language='c++',
        extra_compile_args=cpp_args,
    ),
]

setup(
    name='fintech_math',
    version='1.0',
    ext_modules=ext_modules,
)