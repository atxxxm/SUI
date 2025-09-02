#pragma once
#include <SFML/Graphics.hpp>
#include "sfml_aliases.hpp"

namespace sui
{
    enum class Color
    {
        Black, 
        White,       
        Red,       
        Green, 
        Blue,       
        Yellow, 
        Magenta,      
        Cyan
    };

    namespace func
    {
        namespace color
        {
            UIColor enum_to_color(Color color);
            UIColor hexToRGB(const std::string &hex);
        }
        
        namespace mouse
        {
            sui::UICoord getMousePos(const sui::UIWindow& window);
            bool isClick();
        }
       
    }

    namespace Style
    {
        enum
        {
            None       = 0,      
            Titlebar   = 1 << 0, 
            Resize     = 1 << 1, 
            Close      = 1 << 2, 
            Fullscreen = 1 << 3, 

            Default = Titlebar | Resize | Close
        };
    }

    namespace Mode
    {
        enum
        {
            Horizontal_RIGHT = 0,
            Horizontal_LEFT  = 1,
            Vertical_DOWN    = 2,
            Vertical_UP      = 3
        };
    }

    
}