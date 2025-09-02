#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

namespace sui
{
    typedef sf::VertexArray UIObject;
    typedef sf::Font UIFont;
    typedef sf::Text UIText;
    typedef sf::Color UIColor;
    typedef sf::RenderWindow UIWindow;
    typedef sf::Event UIEvent;
    typedef sf::Drawable UIElement;
    typedef sf::RectangleShape UIRect;
    typedef sf::CircleShape UICircle;

    typedef std::vector<std::string> UIStrList;

    struct UICoord
    {
        int x;
        int y;
    };

    struct UIScale
    {
        int width;
        int height;
    };
}
