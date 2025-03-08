#!/bin/sh

g++ -std=c++17 -I src/Common -I src/Libraries -I src/Robot $(find src -name "*.cpp") -o movingTowardsBall

./movingTowardsBall