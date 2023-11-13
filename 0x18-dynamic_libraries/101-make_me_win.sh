#!/bin/bash
wget -P /tmp/ https://raw.github.com/Taha-Hakkou/alx-low_level_programming/master/0x18-dynamic_libraries/libgm.so
export LD_PRELOAD=/tmp/libgm.so
