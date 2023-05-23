from pickletools import uint8
import serial
from typing import List, Deque

def _calc_urc(data: List[uint8]) -> uint8:
    crc = 0x00
    for i, arg in enumerate(data[2:]):
        crc += (((arg + i) * ((i % 4) + 1)))
        crc %= 256
        # rospy.logerr("> i " + str(i))
        # rospy.logerr("crc " + str(crc))
        # rospy.logerr("val " + str((((arg + i) * ((i % 4) + 1)))))
    return crc % 256

with serial.Serial('COM8', 115200, timeout=1) as ser:
    while True:
        crc_data = []
        crc = 0

        cmd = int(input("cmd:  "))
        crc_data.append(cmd)

        args = input("args: ").split(' ')
        if args[0] == "":
            args = []
        args_num = len(args)

        crc_data.append(len(args))
        for arg in args:
            crc_data.append(int(arg))

        crc = 0
        for c in crc_data:
            crc ^= c

        print("crc:  " + str(crc))

        frame = bytearray([cmd, int(args_num)])

        for arg in args:
            frame.append(int(arg))

        urc = _calc_urc(frame)
        print(urc)

        frame.insert(0, ord('<'))
        frame.append(crc)
        frame.append(urc)

        print(frame)
        ser.write(frame)