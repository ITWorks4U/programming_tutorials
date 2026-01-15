# ---
# setup.py
#
# Required to build a temporary C file for your desired operation(s).
# ---

from setuptools import setup
from Cython.Build import cythonize
from numpy import get_include

setup(
	ext_modules=cythonize("bubble_sort.pyx"),                  # use the desired pyx file
	include_dirs=[get_include()]                               # followed by the header files
)