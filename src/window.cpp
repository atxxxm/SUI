#include <SFML/Graphics.hpp>
#include <string>
#include "../include/window.hpp"
#include "../include/sfml_aliases.hpp"
#include "../include/sui_func.hpp"

sui::Window::Window()
{
    window.create(sf::VideoMode({800, 600}), "SUI", sui::Style::Default);
}

sui::Window::Window(const unsigned int x, const unsigned int y, const std::string &title, unsigned int style)
{
    window.create(sf::VideoMode({x, y}), title, style);
}

void sui::Window::setPosition(const int x, const int y)
{
    window.setPosition(sf::Vector2i(x, y));
}

void sui::Window::setSize(const unsigned int width, const unsigned int height)
{
    window.setSize(sf::Vector2u(width, height));
}

void sui::Window::setTitle(const std::string& title)
{
    window.setTitle(title);
}

sui::UICoord sui::Window::getPosition() const
{
    sui::UICoord crd;
    crd.x = window.getPosition().x;
    crd.y = window.getPosition().y;
    return crd;
}

sui::UIScale sui::Window::getSize()
{
    sui::UIScale scl;
    scl.width = window.getSize().x;
    scl.height = window.getSize().y;
    return scl;
}

void sui::Window::clear()
{
    window.clear();
}

void sui::Window::clear(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    window.clear(sf::Color(red, green, blue));
}   

void sui::Window::clear(std::string HEX)
{
    window.clear(sui::func::color::hexToRGB(HEX));
}

void sui::Window::clear(sui::Color color)
{
    window.clear(sui::func::color::enum_to_color(color));
}

bool sui::Window::isOpen()
{
    return window.isOpen();
}

void sui::Window::checkClose(UIEvent& event)
{
    if (event.type == UIEvent::Event::Closed)
    {
        window.close();
    }
}   

bool sui::Window::checkEvent(UIEvent& event)
{
    return window.pollEvent(event);
}

void sui::Window::run()
{
    window.display();
}

void sui::Window::close()
{
    window.close();
}

void sui::Window::add(const UIElement& element)
{
    window.draw(element);
}

sui::UIWindow& sui::Window::data()
{
    return window;
}