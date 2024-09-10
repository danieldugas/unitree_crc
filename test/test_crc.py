from unitree_crc.pybind_crc import py_get_crc
from unitree_crc.pybind_crc import py_test_get_crc, py_test_get_crc_mcmd0q1
from unitree_crc import convert_to_pybind_lowcmd
from unitree_go.msg import LowCmd



print("EMPTY MESSAGE TEST")
print("------------------")
msg = LowCmd()
msg = convert_to_pybind_lowcmd(msg)
print("BEFORE")
print(msg.crc)
py_get_crc(msg)
print("AFTER")
print(msg.crc)
print("TEST")
print(py_test_get_crc())
print("")

print("Q MESSAGE TEST")
print("------------------")
msg = LowCmd()
msg.motor_cmd[0].q = 1
msg = convert_to_pybind_lowcmd(msg)
print("BEFORE")
print(msg.crc)
py_get_crc(msg)
print("AFTER")
print(msg.crc)
print("TEST")
print(py_test_get_crc_mcmd0q1())
print("")
