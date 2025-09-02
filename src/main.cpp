#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/draw.hpp"
#include "../include/window.hpp"
#include "../include/sfml_aliases.hpp"

int main()
{   
    sui::Window win(800, 600, "SUI");
    sui::InputText it(200, 200);
    
    while (win.isOpen())
    {
        sui::UIEvent event;
        while (win.checkEvent(event))
        {
            win.checkClose(event);
            
            it.setFocus(win.data());
            it.isPrint(event);
        }
        
        win.clear();
        win.add(it);
        win.run();

    }

    return 0;
}