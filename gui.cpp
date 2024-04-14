#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#include "gui.h"
#include "calculator.h"
#include <stdexcept>
CalculatorGUI::CalculatorGUI() : Fl_Window(500, 500, "Calculator")
{
    // Set background color of the window to light gray
    color(fl_rgb_color(220, 220, 220));

    begin();
    Fl_Box* background = new Fl_Box(0, 0, 500, 500);
    background->box(FL_FLAT_BOX);
    background->color(fl_rgb_color(255, 255, 255));

    input = new Fl_Input(30, 10, 415, 50);
    input->box(FL_FLAT_BOX);
    input->color(fl_rgb_color(240, 240, 240)); 

    int x = 30, y = 70; // Adjusted position for buttons
    int w = 100, h = 80; // Adjusted width and height for buttons
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            buttons[i][j] = new Fl_Button(x + j * (w + 5), y + i * (h + 5), w, h, buttonsText[i][j]);
            buttons[i][j]->box(FL_FLAT_BOX);
            buttons[i][j]->color(fl_rgb_color(200, 200, 200));
            buttons[i][j]->labelcolor(fl_rgb_color(0, 0, 0));
            buttons[i][j]->labelsize(20); 
            buttons[i][j]->labelfont(FL_BOLD); 
            buttons[i][j]->callback(button_cb, this);
        }
    }

    end();
}

void CalculatorGUI::button_cb(Fl_Widget *widget, void *data)
{
    CalculatorGUI *calculator = static_cast<CalculatorGUI *>(data);
    Fl_Button *button = static_cast<Fl_Button *>(widget);
    const char *label = button->label();
    
    // Append the label of the clicked button to the input
    calculator->input->replace(calculator->input->size(), calculator->input->size(), label);
    
    string expression = calculator->input->value();
    
    if (label[0] == '=')
    {
        try
        {
            double result = Calculator::evaluate(expression);
            char buffer[50];
            snprintf(buffer, sizeof(buffer), "%.2f ", result);
            calculator->input->value(buffer);
        }
        catch (const invalid_argument &e)
        {
            calculator->input->value(e.what());
        }
    }
    else if (label[0] == 'C')
    {
        calculator->input->value(""); 
    }
}
