#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

namespace py = boost::python;

namespace sort {

    template<typename T>
    inline void swap(T& x, T&y) {
        const T tmp = x;
        x = y;
        y = tmp;
    }

    template<typename T>
    inline void _bubble_sort(std::vector<T>& data) {
        const std::size_t length = data.size();
        for (std::size_t i=0; i < length; i++) {
            for (std::size_t j=length-1; j > i; j--) {
                if (data[j-1] > data[j]) {
                    swap(data[j-1], data[j]);
                }
            }
        }
    }

    template<typename T>
    inline void _bubble_sort(py::list& data) {
        const std::size_t length = py::len(data);
        for (std::size_t i=0; i < length; i++) {
            for (std::size_t j=length-1; j > i; j--) {
                const T x = py::extract<T>(data[j-1]);
                const T y = py::extract<T>(data[j]);
                if (x > y) {
                    data[j-1] = y;
                    data[j] = x;
                }
            }
        }
    }

    template<typename T>
    inline std::vector<T> convert_list_to_vector(const py::list& list) {
        const std::size_t length = py::len(list);
        std::vector<T> data(length);

        for (std::size_t i=0; i < length; i++) {
            data[i] = py::extract<T>(list[i]);
        }

        return data;
    }

    template<typename T>
    inline py::list convert_vector_to_list(const std::vector<T>& data) {
        const py::object iter = py::iterator<std::vector<T> >()(data);
        const py::list list(iter);

        return list;
    }

    void bubble_sort(py::list& list) {
        _bubble_sort<int>(list);
    }

    std::vector<int> bubble_sort_return_vector(const py::list& list) {
        std::vector<int> data = convert_list_to_vector<int>(list);
        _bubble_sort(data);

        return data;
    }

    py::list bubble_sort_return_list(const py::list& list) {
        std::vector<int> data = convert_list_to_vector<int>(list);
        _bubble_sort(data);

        return convert_vector_to_list(data);
    }

};

BOOST_PYTHON_MODULE(sort) {
    using namespace sort;

    py::class_<std::vector<int> >("IntVector")
        .def(py::vector_indexing_suite<std::vector<int> >());
    py::def("bubble_sort", bubble_sort);
    py::def("bubble_sort_return_vector", bubble_sort_return_vector,
            py::return_value_policy<py::return_by_value>());
    py::def("bubble_sort_return_list", bubble_sort_return_list,
            py::return_value_policy<py::return_by_value>());
}
