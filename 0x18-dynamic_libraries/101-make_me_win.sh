#!/bin/bash
wget -P .. https://github.com/KagisoMakgaba1/alx-low_level_programming/blob/master/libhack.so
export LD_PRELOAD="$PWD/../libhack.so"
