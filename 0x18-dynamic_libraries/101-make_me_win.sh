#!/bin/bash
wget -q -O /tmp/libinject.so https://raw.githubusercontent.com/KagisoMakgaba1/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libinject.so
export LD_PRELOAD=/tmp/libinject.so
