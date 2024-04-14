// main.cpp

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <iostream>
#include "gui.h"

CalculatorGUI* calculator;

int main() {
    calculator = new CalculatorGUI();
    calculator->show();
    return Fl::run();
}
