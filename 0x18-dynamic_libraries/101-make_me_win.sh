#!/bin/bash
wget -P .. https://raw.github.com/KagisoMakgaba1/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libinject.so
export LD_PRELOAD="$PWD/../libinject.so"
