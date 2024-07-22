#include "libmorton/morton.h"
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(pylibmorton, m) {
  m.doc() = "Python bindings for libmorton using pybind11";

  m.def("encode_3d", &libmorton::morton3D_32_encode, 
        py::arg("x"), py::arg("y"), py::arg("z"), 
        "Encode 3D coordinates to Morton code");
  m.def(
      "decode_3d",
      [](uint_fast32_t morton) {
        uint_fast16_t x, y, z;
        libmorton::morton3D_32_decode(morton, x, y, z);
        return std::make_tuple(x, y, z);
      },
      py::arg("morton"), "Decode Morton code to 3D coordinates");
}