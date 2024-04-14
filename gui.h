// gui.h

#ifndef GUI_H
#define GUI_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <string>
using namespace std;
class CalculatorGUI : public Fl_Window {
public:
    CalculatorGUI();

    static void button_cb(Fl_Widget* widget, void* data);

    Fl_Input* input;
    Fl_Output* output;
    Fl_Button* buttons[5][4];

    const char* buttonsText[5][4] = {
        {"(", ")", "%", "C"},
        {"7", "8", "9", "/"},
        {"4", "5", "6", "*"},
        {"1", "2", "3", "-"},
        {"0", ".", "=", "+"}
    };
};


#endif // GUI_H
