# boost-sample

A sample module using the Boost.Python.  
This module provides sorting functions by the Bubble Sort.

## Installation
### MacOS
```shell
$ brew install boost-python3
$ python3 setup.py install
```

## Usage
### Python interpreter
```python
>>> from sort import bubble_sort
>>> data = [30, 99, 71, 59, 75, 9, 57, 10]
>>> bubble_sort(data)
>>> data
[9, 10, 30, 57, 59, 71, 75, 99]
```

### Jupyter Notebook
```shell
$ cd notebooks
$ jupyter notebook
```
