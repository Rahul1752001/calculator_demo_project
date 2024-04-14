#!/bin/bash

# Compilation command
g++ -std=c++11 -g -o calculator main.cpp gui.cpp calculator.cpp memory.cpp `fltk-config --cxxflags --ldflags`
