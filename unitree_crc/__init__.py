from unitree_crc.pybind_crc import *

from unitree_crc.pybind_crc import LowCmd as PB_LowCmd
from unitree_crc.pybind_crc import MotorCmd as PB_MotorCmd
from unitree_crc.pybind_crc import BmsCmd as PB_BmsCmd

def convert_to_pybind_lowcmd(ros_msg):
    pybind_msg = PB_LowCmd()
    pybind_msg.head = ros_msg.head
    pybind_msg.level_flag = ros_msg.level_flag
    pybind_msg.frame_reserve = ros_msg.frame_reserve
    pybind_msg.sn = ros_msg.sn
    pybind_msg.version = ros_msg.version
    pybind_msg.bandwidth = ros_msg.bandwidth
    pybind_msg.motor_cmd = [convert_to_pybind_motorcmd(mcmd_msg) for mcmd_msg in ros_msg.motor_cmd]
    pybind_msg.bms_cmd = convert_to_pybind_bmscmd(ros_msg.bms_cmd)  # Perform conversion if necessary
    pybind_msg.wireless_remote = ros_msg.wireless_remote
    pybind_msg.led = ros_msg.led
    pybind_msg.fan = ros_msg.fan
    pybind_msg.gpio = ros_msg.gpio
    pybind_msg.reserve = ros_msg.reserve
    return pybind_msg

def convert_to_pybind_motorcmd(ros_msg):
    pybind_msg = PB_MotorCmd()
    pybind_msg.mode = ros_msg.mode
    pybind_msg.q = ros_msg.q
    pybind_msg.dq = ros_msg.dq
    pybind_msg.tau = ros_msg.tau
    pybind_msg.kp = ros_msg.kp
    pybind_msg.kd = ros_msg.kd
    pybind_msg.reserve = ros_msg.reserve
    return pybind_msg

def convert_to_pybind_bmscmd(ros_msg):
    pybind_msg = PB_BmsCmd()
    pybind_msg.off = ros_msg.off
    pybind_msg.reserve = ros_msg.reserve
    return pybind_msg
