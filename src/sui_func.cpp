#include <SFML/Graphics.hpp>
#include "../include/sfml_aliases.hpp"
#include "../include/sui_func.hpp"

sui::UIColor sui::func::color::enum_to_color(Color color)
{
    switch (color)
    {
        case Color::Black: return sui::UIColor::Black;
        case Color::White: return sui::UIColor::White;
        case Color::Red: return sui::UIColor::Red;
        case Color::Green: return sui::UIColor::Green;
        case Color::Blue: return sui::UIColor::Blue;
        case Color::Yellow: return sui::UIColor::Yellow;
        case Color::Magenta: return sui::UIColor::Magenta;
        case Color::Cyan: return sui::UIColor::Cyan;    
        default: return sui::UIColor::White;
    }
}

sui::UIColor sui::func::color::hexToRGB(const std::string &hex)
{
    std::string hexValue = hex;
    if (hexValue[0] == '#') {hexValue.erase(0, 1); }

    unsigned long hexNumber = std::stoi(hexValue, nullptr, 16);

    uint8_t red = (hexNumber >> 16) & 0xFF;
    uint8_t green = (hexNumber >> 8) & 0xFF;
    uint8_t blue = hexNumber & 0xFF;

    return sf::Color(red, green, blue);
}

sui::UICoord sui::func::mouse::getMousePos(const sui::UIWindow& window)
{
    sui::UICoord crd;
    crd.x = sf::Mouse::getPosition(window).x;
    crd.y = sf::Mouse::getPosition(window).y;
    return crd;
}

bool sui::func::mouse::isClick()
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}