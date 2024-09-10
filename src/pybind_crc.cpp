#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <motor_crc.h>
#include "unitree_go/msg/low_cmd.hpp"
#include "unitree_go/msg/motor_cmd.hpp"
#include "unitree_go/msg/bms_cmd.hpp"

int add(int i, int j) { return i + j; }

uint32_t py_test_get_crc()
{
    unitree_go::msg::LowCmd msg;
    get_crc(msg);
    return msg.crc;
}

uint32_t py_test_get_crc_mcmd0q1()
{
    unitree_go::msg::LowCmd msg;
    msg.motor_cmd[0].q = 1.0f;
    get_crc(msg);
    return msg.crc;
}

void py_get_crc(unitree_go::msg::LowCmd& msg)
{
    get_crc(msg);
}

namespace py = pybind11;

PYBIND11_MODULE(pybind_crc, m)
{
    py::class_<unitree_go::msg::BmsCmd>(m, "BmsCmd")
    .def(py::init<>())
    .def_readwrite("off", &unitree_go::msg::BmsCmd::off)
    .def_readwrite("reserve", &unitree_go::msg::BmsCmd::reserve);

    py::class_<unitree_go::msg::MotorCmd>(m, "MotorCmd")
    .def(py::init<>())
    .def_readwrite("mode", &unitree_go::msg::MotorCmd::mode)
    .def_readwrite("q", &unitree_go::msg::MotorCmd::q)
    .def_readwrite("dq", &unitree_go::msg::MotorCmd::dq)
    .def_readwrite("tau", &unitree_go::msg::MotorCmd::tau)
    .def_readwrite("kp", &unitree_go::msg::MotorCmd::kp)
    .def_readwrite("kd", &unitree_go::msg::MotorCmd::kd)
    .def_readwrite("reserve", &unitree_go::msg::MotorCmd::reserve);


    py::class_<unitree_go::msg::LowCmd>(m, "LowCmd")
    .def(py::init<>())
    .def_readwrite("head", &unitree_go::msg::LowCmd::head)
    .def_readwrite("level_flag", &unitree_go::msg::LowCmd::level_flag)
    .def_readwrite("frame_reserve", &unitree_go::msg::LowCmd::frame_reserve)
    .def_readwrite("sn", &unitree_go::msg::LowCmd::sn)
    .def_readwrite("version", &unitree_go::msg::LowCmd::version)
    .def_readwrite("bandwidth", &unitree_go::msg::LowCmd::bandwidth)
    .def_readwrite("motor_cmd", &unitree_go::msg::LowCmd::motor_cmd)
    .def_readwrite("bms_cmd", &unitree_go::msg::LowCmd::bms_cmd)
    .def_readwrite("wireless_remote", &unitree_go::msg::LowCmd::wireless_remote)
    .def_readwrite("led", &unitree_go::msg::LowCmd::led)
    .def_readwrite("fan", &unitree_go::msg::LowCmd::fan)
    .def_readwrite("gpio", &unitree_go::msg::LowCmd::gpio)
    .def_readwrite("reserve", &unitree_go::msg::LowCmd::reserve)
    .def_readwrite("crc", &unitree_go::msg::LowCmd::crc);

    m.def("py_get_crc", &get_crc, "Calculate CRC for LowCmd", py::arg("msg"));
    m.def("py_test_get_crc", &py_test_get_crc, "A function which test get_crc");
    m.def("py_test_get_crc_mcmd0q1", &py_test_get_crc_mcmd0q1, "A function which test get_crc with motor_cmd[0].q = 1");
    
}
