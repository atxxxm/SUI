#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "sfml_aliases.hpp"
#include "sui_func.hpp"

namespace sui
{
    class Window
    {
        private:
            sf::RenderWindow window;

        public:
            Window();
            Window(const unsigned int x, const unsigned int y, const std::string &title, unsigned int style = sui::Style::Default);

            void setPosition(const int x, const int y);
            void setSize(const unsigned int width, const unsigned int height);
            void setTitle(const std::string& title);

            sui::UICoord getPosition() const;
            sui::UIScale getSize();

            void clear();
            void clear(const uint8_t red, const uint8_t green, const uint8_t blue);
            void clear(std::string HEX);
            void clear(sui::Color color);

            bool isOpen();
            void checkClose(sui::UIEvent& event);
            bool checkEvent(sui::UIEvent& event);

            sui::UIWindow& data();
            void run();
            void add(const sui::UIElement& element);
            void close();

            ~Window() {};
        };
}