
# Install

```
install unitree_ros2:
https://github.com/unitreerobotics/unitree_ros2

mkdir ~/pybind_ws/src -p
cd ~/pybind_ws/src
git clone https://github.com/danieldugas/unitree_crc.git

source ~/unitree_ros2/cyclonedds_ws/install/setup.sh # ensures unitree_go messages are available
cd ~/pybind_ws
colcon build
```

# Example

```
source ~/pybind_ws/install/setup.sh
cd ~/pybind_ws/src/unitree_crc/test
python3 test_crc.py
```

should output:

```
EMPTY MESSAGE TEST
------------------
BEFORE
0
AFTER
1264208000
TEST
1264208000

Q MESSAGE TEST
------------------
BEFORE
0
AFTER
3169975056
TEST
3169975056
```
