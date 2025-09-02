#include "../include/draw.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/sfml_aliases.hpp"
#include "../include/sui_func.hpp"

const std::string path_to_time_arial = "../arial.ttf";

sui::UIFont sui::Font::loadFont(std::string path_to_font)
{
    sui::UIFont fon_t;
    fon_t.loadFromFile(path_to_font);

    return fon_t;
}

void sui::Frame::edit_frame()
{
    frame_rect.setPosition(sf::Vector2f(frame_x, frame_y));
    frame_rect.setSize(sf::Vector2f(frame_width, frame_height));
    frame_rect.setFillColor(color_frame);
    frame_rect.setOutlineThickness(outline_size);
    frame_rect.setOutlineColor(color_frame_outline);
}

sui::Frame::Frame()
{
    edit_frame();
}

sui::Frame::Frame(const int x, const int y) : frame_x(x), frame_y(y)
{
    edit_frame();
}

sui::Frame::Frame(const int x, const int y, const int width, const int height) : frame_x(x), frame_y(y), frame_width(width), frame_height(height)
{
    edit_frame();
}

void sui::Frame::setPosition(const int x, const int y)
{
    frame_x = x;
    frame_y = y;
    edit_frame();
}

void sui::Frame::setSize(const int width, const int height)
{
    frame_width = width;
    frame_height = height;
    edit_frame();
}

void sui::Frame::setColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    color_frame = sui::UIColor(red, green, blue);
    edit_frame();
}

void sui::Frame::setColor(std::string HEX)
{
    color_frame = func::color::hexToRGB(HEX);
    edit_frame();
}

void sui::Frame::setColor(Color color)
{
    color_frame = func::color::enum_to_color(color);
    edit_frame();
}

void sui::Frame::setOutLine(const int size)
{
    outline_size = size;
    edit_frame();
}

void sui::Frame::setOutLineColor(const uint8_t red, const uint8_t green, const int blue)
{
    color_frame_outline = sui::UIColor(red, green, blue);
    edit_frame();
}

void sui::Frame::setOutLineColor(std::string HEX)
{
    color_frame_outline = sui::func::color::hexToRGB(HEX);
    edit_frame();
}

void sui::Frame::setOutLineColor(sui::Color color)
{
    color_frame_outline = sui::func::color::enum_to_color(color);
    edit_frame();
}

sui::UICoord sui::Frame::getPosition() const
{
    sui::UICoord ui_crd;
    ui_crd.x = frame_rect.getPosition().x;
    ui_crd.y = frame_rect.getPosition().y;
    return ui_crd;
}

sui::UIScale sui::Frame::getSize() const
{
    sui::UIScale ui_scl;
    ui_scl.width = frame_rect.getSize().x;
    ui_scl.height = frame_rect.getSize().y;
    return ui_scl;
}

void sui::Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(frame_rect, states);
}



void sui::Button::edit_button()
{   
    button_rect.setPosition(sf::Vector2f(button_x, button_y));
    button_rect.setSize(sf::Vector2f(button_width, button_height));
    button_rect.setFillColor(button_backround_color);

    button_rect.setOutlineThickness(outline_size);
    button_rect.setOutlineColor(background_color_outline);

    button_text.setFont(button_font);
    button_text.setString(button_label_text);
    button_text.setCharacterSize(button_text_size);
    button_text.setFillColor(button_text_color);

    sf::Vector2f pos_btn = button_rect.getPosition();
    sf::Vector2f size_btn = button_rect.getSize();
    sf::Vector2f size_txt = button_text.getGlobalBounds().getSize();

    int fmt_x = pos_btn.x + ((size_btn.x / 2) - (size_txt.x / 2));
    int fmt_y = pos_btn.y + ((size_btn.y / 2) - (size_txt.y / 2) - (size_txt.y / 4));

    button_text.setPosition(sf::Vector2f(fmt_x, fmt_y));
}

sui::Button::Button()
{
    if (!button_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    edit_button();
}

sui::Button::Button(const std::string& label) : button_label_text(label)
{
    if (!button_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    edit_button();
}

sui::Button::Button(const int x, const int y, const std::string& label) : button_x(x), button_y(y)
{
    if (!button_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    edit_button();
}

sui::Button::Button(const int x, const int y, const int width, const int height, const std::string& label) : button_x(x), button_y(y), button_width(width), button_height(height)
{
    if (!button_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }

    edit_button();
}

void sui::Button::setPosition(const int x, const int y)
{
    button_x = x;
    button_y = y;
    edit_button();
}

void sui::Button::setSize(const int width, const int height)
{
    button_width = width;
    button_height = height;
    edit_button();
}

void sui::Button::setBagroundColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    button_backround_color = sui::UIColor(red, green, blue);
    edit_button();
}

void sui::Button::setBagroundColor(std::string HEX)
{
    button_backround_color = sui::func::color::hexToRGB(HEX);
    edit_button();
}

void sui::Button::setBagroundColor(Color color)
{
    button_backround_color = sui::func::color::enum_to_color(color);
    edit_button();
}

void sui::Button::setText(const std::string& label)
{
    button_label_text = label;
    edit_button();
}

void sui::Button::setSizeText(const unsigned int size)
{
    button_text_size = size;
    edit_button();
}

void sui::Button::setTextColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    button_text_color = sui::UIColor(red, green, blue);
    edit_button();
}

void sui::Button::setTextColor(std::string HEX)
{
    button_text_color = sui::func::color::hexToRGB(HEX);
    edit_button();
}

void sui::Button::setTextColor(Color color)
{
    button_text_color = sui::func::color::enum_to_color(color);
    edit_button();
}

void sui::Button::setOutLine(const int size)
{
    outline_size = size;
    edit_button();
}

void sui::Button::setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    background_color_outline = sui::UIColor(red, green, blue);
    edit_button();
}

void sui::Button::setOutLineColor(std::string HEX)
{
    background_color_outline = sui::func::color::hexToRGB(HEX);
    edit_button();
}   

void sui::Button::setOutLineColor(sui::Color color)
{
    background_color_outline = sui::func::color::enum_to_color(color);
    edit_button();
}

sui::UICoord sui::Button::getPosition() const
{
    sui::UICoord crd;
    crd.x = button_rect.getPosition().x;
    crd.y = button_rect.getPosition().y;
    return crd;
}

sui::UIScale sui::Button::getSize() const
{
    sui::UIScale scl;
    scl.width = button_rect.getSize().x;
    scl.height = button_rect.getSize().y;
    return scl;
}

void sui::Button::setTextFont(Font& font)
{
    button_font = font.font;
    edit_button();
}

bool sui::Button::isClick(const UIWindow& window)
{
    sui::UICoord crd = sui::func::mouse::getMousePos(window);
    return (crd.x >= button_x && crd.x <= button_x + button_width) && 
    (crd.y >= button_y && crd.y <= button_y + button_height) && 
    sui::func::mouse::isClick();
}

bool sui::Button::isHover(const UIWindow& window)
{
    sui::UICoord crd = sui::func::mouse::getMousePos(window);   
    return (crd.x >= button_x && crd.x <= button_x + button_width) && (crd.y >= button_y && crd.y <= button_y + button_height);
}

void sui::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(button_rect, states);
    target.draw(button_text, states);
}



void sui::Label::editLabel()
{
    label_label.setFont(label_font);
    label_label.setString(label_text);
    label_label.setCharacterSize(size_label);
    label_label.setFillColor(label_color);
    label_label.setPosition(sf::Vector2f(label_x, label_y));
}

sui::Label::Label(const std::string& label) : label_text(label)
{
    if (!label_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    editLabel();
}

sui::Label::Label(const std::string& label, const int x, const int y) : label_text(label), label_x(x), label_y(y)
{
    if (!label_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    editLabel();
}

sui::Label::Label(const std::string& label, const int x, const int y, const unsigned int size) : label_text(label), label_x(x), label_y(y), size_label(size)
{
    if (!label_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    editLabel();
}

sui::Label::Label(const std::string& label, const int x, const int y, const unsigned int size, const Font& font) : label_text(label), label_x(x), label_y(y), size_label(size), label_font(font.font)
{
    editLabel();
}

void sui::Label::setText(const std::string &label)
{
    label_text = label;
    editLabel();
}

void sui::Label::setFont(const Font& font)
{
    label_font = font.font;
    editLabel();
}   

void sui::Label::setColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    label_color = sui::UIColor(red, green, blue);
    editLabel();
}

void sui::Label::setColor(std::string HEX)
{
    label_color = sui::func::color::hexToRGB(HEX);
    editLabel();
}

void sui::Label::setColor(Color color)
{
    label_color = sui::func::color::enum_to_color(color);
    editLabel();
}

void sui::Label::setSize(const unsigned int size)
{
    size_label = size;
    editLabel();
}

void sui::Label::setPosition(int x, int y)
{
    label_x = x;
    label_y = y;
    editLabel();
}

sui::UICoord sui::Label::getPosition() const
{
    sui::UICoord coord_label;
    coord_label.x = label_label.getPosition().x;
    coord_label.y = label_label.getPosition().y;
    return coord_label;
}

sui::UIScale sui::Label::getSize() const
{
    sui::UIScale label_scale;
    label_scale.width = label_label.getScale().x;
    label_scale.height = label_label.getScale().y;
    return label_scale;
}

void sui::Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(label_label, states);
}



void sui::InputText::editInputText()
{
    input_text_rect.setPosition(sf::Vector2f(input_text_rect_x, input_text_rect_y));
    input_text_rect.setSize(sf::Vector2f(input_text_rect_width, input_text_rect_height));
    input_text_rect.setFillColor(background_color_input_text);

    input_text_rect.setOutlineThickness(outline_size);
    input_text_rect.setOutlineColor(background_color_input_text_outline);

    input_text_text.setPosition(sf::Vector2f(input_text_rect_x + 10, input_text_rect_y + 10));
    input_text_text.setFont(input_text_font);
    input_text_text.setFillColor(text_color_input_text);
    input_text_text.setCharacterSize(input_text_size);
}

sui::InputText::InputText()
{
    if (!input_text_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    editInputText();
}

sui::InputText::InputText(const int x, const int y) : input_text_rect_x(x), input_text_rect_y(y)
{   
    if (!input_text_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    editInputText();
}

sui::InputText::InputText(const int x, const int y, const int width, const int height) : input_text_rect_x(x), input_text_rect_y(y), 
input_text_rect_width(width), input_text_rect_height(height)
{
    if (!input_text_font.loadFromFile(path_to_time_arial))
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    editInputText();
}

sui::InputText::InputText(const Font& font) : input_text_font(font.font)
{
    editInputText();
}

void sui::InputText::setPosition(const int x, const int y)
{
    input_text_rect_x = x;
    input_text_rect_y = y;
    editInputText();
}

void sui::InputText::setSize(const int width, const int height)
{
    input_text_rect_width = width;
    input_text_rect_height = height;
    editInputText();
}

void sui::InputText::setBackgroundColor(const u_int8_t red, const uint8_t green, const uint8_t blue)
{
    background_color_input_text = sui::UIColor(red, green, blue);
    editInputText();
}

void sui::InputText::setBackgroundColor(std::string HEX)
{
    background_color_input_text = sui::func::color::hexToRGB(HEX);
    editInputText();
}

void sui::InputText::setBackgroundColor(Color color)
{
    background_color_input_text = sui::func::color::enum_to_color(color);
    editInputText();
}

void sui::InputText::setOutLine(const int size)
{
    outline_size = size;
    editInputText();
}

void sui::InputText::setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    background_color_input_text_outline = sui::UIColor(red, green, blue);
    editInputText();
}   

void sui::InputText::setOutLineColor(std::string HEX)
{
    background_color_input_text_outline = sui::func::color::hexToRGB(HEX);
    editInputText();
}

void sui::InputText::setOutLineColor(sui::Color color)
{
    background_color_input_text_outline = sui::func::color::enum_to_color(color);
    editInputText();
}

void sui::InputText::setTextColor(const u_int8_t red, const uint8_t green, const uint8_t blue)
{
    text_color_input_text = sui::UIColor(red, green, blue);
    editInputText();
}

void sui::InputText::setTextColor(std::string HEX)
{
    text_color_input_text = sui::func::color::hexToRGB(HEX);
    editInputText();
}

void sui::InputText::setTextColor(Color color)
{
    text_color_input_text = sui::func::color::enum_to_color(color);
    editInputText();
}

void sui::InputText::setTextSize(const unsigned int size)
{
    input_text_size = size;
    editInputText();
}

void sui::InputText::setTextFont(const Font& font)
{
    input_text_font = font.font;
    editInputText();
}

void sui::InputText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(input_text_rect, states);
    target.draw(input_text_text, states);
}

void sui::InputText::setFocus(const UIWindow& window)
{
    sui::UICoord crd = sui::func::mouse::getMousePos(window);
    if ((crd.x >= input_text_rect_x && crd.x <= input_text_rect_x + input_text_rect_width) && 
    (crd.y >= input_text_rect_y && crd.y <= input_text_rect_y + input_text_rect_height) && 
    sui::func::mouse::isClick()) isFocus = true;
}

std::string sui::InputText::isPrint(UIEvent& event)
{
    if (!isFocus) return "";

    if (event.type == UIEvent::TextEntered)
    {
        
        if (event.text.unicode == '\b' && !input_text_txt.empty())
        {
            input_text_txt.pop_back();
            col_char = std::max(0, col_char - 1);
        }
        else if (event.text.unicode < 128 && event.text.unicode != '\r' && event.text.unicode != '\n')
        {
            const int max_chars_per_line = input_text_rect_width / 15;
            const int max_lines = input_text_rect_height / 30;
            
            input_text_txt += static_cast<char>(event.text.unicode);
            col_char++;

            if (col_char >= max_chars_per_line)
            {
                input_text_txt += '\n';
                col_char = 0;
            }

            std::vector<std::string> lines;
            std::string current_line;
            for (char c : input_text_txt)
            {
                if (c == '\n')
                {
                    lines.push_back(current_line);
                    current_line.clear();
                }
                else
                {
                    current_line += c;
                }
            }
            if (!current_line.empty())
            {
                lines.push_back(current_line);
            }
            if (lines.size() > max_lines)
            {
                std::string new_text;
                size_t start = lines.size() - max_lines;
                for (size_t i = start; i < lines.size(); ++i)
                {
                    new_text += lines[i];
                    if (i < lines.size() - 1)
                    {
                        new_text += '\n';
                    }
                }
                input_text_txt = new_text;
                col_char = static_cast<int>(lines.back().length());
            }
            input_text_text.setString(input_text_txt);
        }
    }

    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        isFocus = false;
        return input_text_txt;
    }

    return "";
}



void sui::Image::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(img_sprite, states);
}

void sui::Image::edit_img()
{
    if (!img_texture.loadFromFile(path_to_image))
    {
        throw std::runtime_error("Couldn't upload image! Check that the path to the image is correct");
        return;
    }

    img_sprite.setTexture(img_texture);
    img_sprite.setPosition(sf::Vector2f(img_x, img_y));
    img_sprite.setScale(sf::Vector2f(img_width, img_height));
}

sui::Image::Image(const std::string& path) : path_to_image(path)
{
    edit_img();
}

void sui::Image::setPosition(const float x, const float y)
{
    img_x = x;
    img_y = y;
    edit_img();
}

void sui::Image::setSize(const float width, const float height)
{
    img_width = width;
    img_height = height;
    edit_img();
}



void sui::CheckBox::editCheckBox()
{
    checkbox_rect.setPosition(sf::Vector2f(checkbox_x, checkbox_y));
    checkbox_rect.setSize(sf::Vector2f(checkbox_width, checkbox_height));
    checkbox_rect.setFillColor(checkbox_color);

    checkbox_rect.setOutlineThickness(outline_size);
    checkbox_rect.setOutlineColor(outline_color);

    cross_rect_1.setPosition(sf::Vector2f(checkbox_x + (checkbox_width / 2), checkbox_y + (checkbox_height / 2)));
    cross_rect_1.setSize(sf::Vector2f(checkbox_width / 10, checkbox_height));
    cross_rect_1.setFillColor(cross_color);

    cross_rect_2.setPosition(sf::Vector2f(checkbox_x + (checkbox_width / 2), checkbox_y + (checkbox_height / 2)));
    cross_rect_2.setSize(sf::Vector2f(checkbox_width / 10, checkbox_height));
    cross_rect_2.setFillColor(cross_color);

    cross_rect_1.setOrigin(cross_rect_1.getSize().x / 2, cross_rect_1.getSize().y / 2);
    cross_rect_2.setOrigin(cross_rect_2.getSize().x / 2, cross_rect_2.getSize().y / 2);

    cross_rect_1.setRotation(45.0f);
    cross_rect_2.setRotation(-45.0f);
}

sui::CheckBox::CheckBox()
{
    editCheckBox();
}

sui::CheckBox::CheckBox(const int x, const int y): checkbox_x(x), checkbox_y(y)
{
    editCheckBox();
}

sui::CheckBox::CheckBox(const int x, const int y, const int width, const int height) : checkbox_x(x), checkbox_y(y),
checkbox_width(width), checkbox_height(height)
{
    editCheckBox();
}

void sui::CheckBox::setPosition(const int x, const int y)
{
    checkbox_x = x;
    checkbox_y = y;
    editCheckBox();
}

void sui::CheckBox::setSize(const int width, const int height)
{
    checkbox_width = width;
    checkbox_height = height;
    editCheckBox();
}

void sui::CheckBox::setBackgroundColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    checkbox_color = sui::UIColor(red, green, blue);
    editCheckBox();
}

void sui::CheckBox::setBackgroundColor(std::string HEX)
{
    checkbox_color = sui::func::color::hexToRGB(HEX);
    editCheckBox();
}

void sui::CheckBox::setBackgroundColor(Color color)
{
    checkbox_color = sui::func::color::enum_to_color(color);
    editCheckBox();
}

void sui::CheckBox::setColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    cross_color = sui::UIColor(red, green, blue);
    editCheckBox();
}

void sui::CheckBox::setColor(std::string HEX)
{
    cross_color = sui::func::color::hexToRGB(HEX);
    editCheckBox();
}

void sui::CheckBox::setColor(Color color)
{
    cross_color = sui::func::color::enum_to_color(color);
    editCheckBox();
}

void sui::CheckBox::setOutLine(const int size)
{
    outline_size = size;
    editCheckBox();
}

void sui::CheckBox::setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    outline_color = sui::UIColor(red, green, blue);
    editCheckBox();
}

void sui::CheckBox::setOutLineColor(std::string HEX)
{
    outline_color = sui::func::color::hexToRGB(HEX);
    editCheckBox();
}

void sui::CheckBox::setOutLineColor(sui::Color color)
{
    outline_color = sui::func::color::enum_to_color(color);
    editCheckBox();
}

bool sui::CheckBox::isMarked(const UIWindow& window)
{
    sui::UICoord crd = sui::func::mouse::getMousePos(window);

    if ((crd.x >= checkbox_x && crd.x <= checkbox_x + checkbox_width) && (crd.y >= checkbox_y && crd.y <= checkbox_y + checkbox_height) && 
    sui::func::mouse::isClick()) isMarked_bool = !isMarked_bool;

    return isMarked_bool;
}

void sui::CheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(checkbox_rect, states);
    if (isMarked_bool)
    {
        target.draw(cross_rect_1, states);
        target.draw(cross_rect_2, states);
    }
}



void sui::Slider::editSlider()
{
    slide_bar.setPosition(sf::Vector2f(slide_bar_x, slide_bar_y));
    slide_bar.setSize(sf::Vector2f(slide_bar_size, slide_bar_size / 10));
    slide_bar.setFillColor(slide_bar_color);

    slide_button.setRadius((slide_bar_size / 10));
    slide_button.setOrigin(slide_button.getRadius(), slide_button.getRadius());
    slide_button.setPosition(sf::Vector2f(slide_bar_x + (slide_button.getRadius() / 2), slide_bar_y + (slide_button.getRadius() / 2)));
    slide_button.setFillColor(slide_button_color);
}

void sui::Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(slide_bar, states);
    target.draw(slide_button, states);
}

sui::Slider::Slider()
{
    editSlider();
}

sui::Slider::Slider(const float min_val, const float max_val) : min_value(min_val), max_value(max_val)
{
    editSlider();
}

sui::Slider::Slider(const int x, const int y) : slide_bar_x(x), slide_bar_y(y)
{
    editSlider();
}

sui::Slider::Slider(const int x, const int y, const int size) : slide_bar_x(x), slide_bar_y(y), slide_bar_size(size)
{
    editSlider();
}

void sui::Slider::setPosition(const int x, const int y)
{
    slide_bar_x = x;
    slide_bar_y = y;
    editSlider();
}

void sui::Slider::setSize(const int size)
{
    slide_bar_size = size;
    editSlider();
}

void sui::Slider::setBackgroundColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    slide_bar_color = sui::UIColor(red, green, blue);
    editSlider();
}

void sui::Slider::setBackgroundColor(std::string HEX)
{
    slide_bar_color = sui::func::color::hexToRGB(HEX);
    editSlider();
}

void sui::Slider::setBackgroundColor(Color color)
{
    slide_bar_color = sui::func::color::enum_to_color(color);
    editSlider();
}

void sui::Slider::setColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    slide_button_color = sui::UIColor(red, green, blue);
    editSlider();
}

void sui::Slider::setColor(std::string HEX)
{
    slide_button_color = sui::func::color::hexToRGB(HEX);
    editSlider();
}

void sui::Slider::setColor(Color color)
{
    slide_button_color = sui::func::color::enum_to_color(color);
    editSlider();
}

void sui::Slider::setRange(const float min_val, const float max_val) 
{
    min_value = min_val;
    max_value = max_val;
}

float sui::Slider::getValue() const
{
    float slider_pos = slide_button.getPosition().x - slide_bar_x;
    float range_length = slide_bar_size;
    float normalized = slider_pos / range_length;
    return min_value + normalized * (max_value - min_value);
}

void sui::Slider::isMove(const UIWindow& window, UIEvent& event)
{
    sui::UICoord crd = sui::func::mouse::getMousePos(window);

    bool isArea = (crd.x >= slide_button.getPosition().x - slide_button.getRadius() * 1.5 && 
                    crd.x <= slide_button.getPosition().x + slide_button.getRadius() * 1.5 && 
                    crd.y >= slide_button.getPosition().y - slide_button.getRadius() * 1.5 && 
                    crd.y <= slide_button.getPosition().y + slide_button.getRadius() * 1.5);
    
    if (isArea && sui::func::mouse::isClick() && 
    (crd.x - slide_button.getRadius() >= slide_bar.getPosition().x - slide_button.getRadius()) && 
    (crd.x + slide_button.getRadius() <= slide_bar.getPosition().x + slide_bar.getSize().x + slide_button.getRadius()))
    {
        slide_button.setPosition(sf::Vector2f(crd.x, slide_button.getPosition().y));
    }
}



sui::DropdownList::DropdownList(const std::vector<std::string>& items) : items(items) 
{
    if (!dropdown_font.loadFromFile(path_to_time_arial)) 
    {
        throw std::runtime_error("Font could not be loaded\nPlease download the font via Font::loadFont()\n");
    }
    
    main_rect.setSize(sf::Vector2f(dropdown_size, dropdown_size / 5));
    main_rect.setFillColor(main_color);
    main_rect.setOutlineThickness(1);
    main_rect.setOutlineColor(sf::Color::Black);
    
    main_text.setFont(dropdown_font);
    main_text.setCharacterSize(20);
    main_text.setFillColor(text_color);
    main_text.setString(items.empty() ? "" : items[0]);
    
    editDropdownList();
}

void sui::DropdownList::editDropdownList() 
{
    main_rect.setPosition(dropdown_x, dropdown_y);
    main_rect.setOutlineThickness(outline_size);
    main_rect.setOutlineColor(outline_color);

    main_text.setPosition(dropdown_x + 5, dropdown_y + 5);
    
    dropdown_rect.setSize(sf::Vector2f(dropdown_size, isOpen ? items.size() * (dropdown_size / 5) : 0));
    dropdown_rect.setPosition(dropdown_x, dropdown_y + (dropdown_size / 5));
    dropdown_rect.setFillColor(main_color);
    dropdown_rect.setOutlineThickness(outline_size);
    dropdown_rect.setOutlineColor(outline_color);
    
    items_text.resize(items.size());

    for (size_t i = 0; i < items.size(); ++i) 
    {
        items_text[i].setFont(dropdown_font);
        items_text[i].setCharacterSize(20);
        items_text[i].setFillColor(text_color);
        items_text[i].setString(items[i]);
        items_text[i].setPosition(dropdown_x + 5, dropdown_y + (dropdown_size / 5) * (i + 1) + 5);
    }
}

void sui::DropdownList::setPosition(const int x, const int y) 
{
    dropdown_x = x;
    dropdown_y = y;
    editDropdownList();
}

void sui::DropdownList::setSize(const int size)
{
    dropdown_size = size;
    editDropdownList();
}

void sui::DropdownList::setOutLine(const int size)
{
    outline_size = size;
    editDropdownList();

}

void sui::DropdownList::setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    outline_color = sui::UIColor(red, green, blue);
    editDropdownList();
}

void sui::DropdownList::setOutLineColor(std::string HEX)
{
    outline_color = sui::func::color::hexToRGB(HEX);
    editDropdownList();
}

void sui::DropdownList::setOutLineColor(sui::Color color)
{
    outline_color = sui::func::color::enum_to_color(color);
    editDropdownList();
}   

void sui::DropdownList::setItems(const UIStrList& new_items) 
{
    items = new_items;
    if (!items.empty()) 
    {
        main_text.setString(items[0]);
    }
    editDropdownList();
}

void sui::DropdownList::checkEvent(const UIWindow& window, const UIEvent& event) 
{
    if (sui::func::mouse::isClick()) 
    {   
        sui::UICoord crd = sui::func::mouse::getMousePos(window);
        
        if (main_rect.getGlobalBounds().contains(crd.x, crd.y)) 
        {
            isOpen = !isOpen;
            editDropdownList();
        }
        else if (isOpen && dropdown_rect.getGlobalBounds().contains(crd.x, crd.y)) 
        {
            for (size_t i = 0; i < items.size(); ++i) 
            {
                if (items_text[i].getGlobalBounds().contains(crd.x, crd.y)) 
                {
                    selected_index = i;
                    main_text.setString(items[i]);
                    isOpen = false;
                    editDropdownList();
                    break;
                }
            }
        }
        else 
        {
            isOpen = false;
            editDropdownList();
        }
    }
}

void sui::DropdownList::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    target.draw(main_rect, states);
    target.draw(main_text, states);
    
    if (isOpen) 
    {
        target.draw(dropdown_rect, states);

        for (const auto& text : items_text) 
        {
            target.draw(text, states);
        }
    }
}

std::string sui::DropdownList::getSelectedItem() const 
{
    return selected_index >= 0 ? items[selected_index] : "";
}

int sui::DropdownList::getSelectedIndex() const 
{
    return selected_index;
}



void sui::ProgressBar::editProgressBar()
{
    bar_rect.setPosition(sf::Vector2f(bar_x, bar_y));
    bar_rect.setSize(sf::Vector2f(bar_width, bar_height));
    bar_rect.setFillColor(bar_color);
    
    bar_rect.setOutlineThickness(outline_size);
    bar_rect.setOutlineColor(outline_color);

    progress_rect.setPosition(sf::Vector2f(bar_x, bar_y));
    progress_rect.setSize(sf::Vector2f(bar_width * progress, bar_height));
    progress_rect.setFillColor(progress_color);
}

sui::ProgressBar::ProgressBar()
{
    editProgressBar();
}

sui::ProgressBar::ProgressBar(const int x, const int y) : bar_x(x), bar_y(y)
{
    editProgressBar();
}

sui::ProgressBar::ProgressBar(const int x, const int y, const int width, const int height)
    : bar_x(x), bar_y(y), bar_width(width), bar_height(height)
{
    editProgressBar();
}

void sui::ProgressBar::setPosition(const int x, const int y)
{
    bar_x = x;
    bar_y = y;
    editProgressBar();
}

void sui::ProgressBar::setSize(const int width, const int height)
{
    bar_width = width;
    bar_height = height;
    editProgressBar();
}

void sui::ProgressBar::setOutLine(const int size)
{
    outline_size = size;
    editProgressBar();
}

void sui::ProgressBar::setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    outline_color = sui::UIColor(red, green, blue);
    editProgressBar();
}

void sui::ProgressBar::setOutLineColor(std::string HEX)
{   
    outline_color = sui::func::color::hexToRGB(HEX);
    editProgressBar();
}

void sui::ProgressBar::setOutLineColor(sui::Color color)
{
    outline_color = sui::func::color::enum_to_color(color);
    editProgressBar();
}

void sui::ProgressBar::setBackgroundColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    bar_color = sui::UIColor(red, green, blue);
    editProgressBar();
}

void sui::ProgressBar::setBackgroundColor(std::string HEX)
{
    bar_color = sui::func::color::hexToRGB(HEX);
    editProgressBar();
}

void sui::ProgressBar::setBackgroundColor(sui::Color color)
{
    bar_color = sui::func::color::enum_to_color(color);
    editProgressBar();
}

void sui::ProgressBar::setColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    progress_color = sui::UIColor(red, green, blue);
    editProgressBar();
}

void sui::ProgressBar::setColor(std::string HEX)
{
    progress_color = sui::func::color::hexToRGB(HEX);
    editProgressBar();
}

void sui::ProgressBar::setColor(sui::Color color)
{
    progress_color = sui::func::color::enum_to_color(color);
    editProgressBar();
}

void sui::ProgressBar::setProgress(float value)
{
    if (value < 0.0f) value = 0.0f;
    if (value > 1.0f) value = 1.0f;
    progress = value;
    editProgressBar();
}

float sui::ProgressBar::getProgress() const
{
    return progress;
}

sui::UICoord sui::ProgressBar::getPosition() const
{
    sui::UICoord crd;
    crd.x = bar_rect.getPosition().x;
    crd.y = bar_rect.getPosition().y;
    return crd;
}

sui::UIScale sui::ProgressBar::getSize() const
{
    sui::UIScale scl;
    scl.width = bar_rect.getSize().x;
    scl.height = bar_rect.getSize().y;
    return scl;
}

void sui::ProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(bar_rect, states);
    target.draw(progress_rect, states);
}



void sui::SwitchButton::editSwitchButton()
{
    resize = size / 1.2;

    center.setPosition(sf::Vector2f(x, y));
    center.setSize(sf::Vector2f(size, resize));
    center.setFillColor(background_color);

    left.setRadius(resize / 2);
    left.setOrigin(resize, resize);
    left.setPosition(sf::Vector2f(x + (resize / 2), y + resize));
    left.setFillColor(background_color);

    right.setRadius(resize / 2);
    right.setOrigin(resize, resize);
    right.setPosition(sf::Vector2f((x + size) + (resize / 2), y + resize));
    right.setFillColor(background_color);

    btn.setRadius(resize / 2);
    btn.setOrigin(resize, resize);
    btn.setPosition(sf::Vector2f(pos_btn, y + resize));
    btn.setFillColor(btn_color);

}

void sui::SwitchButton::mode()
{
    if (!is_on)
    {
        pos_btn = x + (resize / 2);
        background_color = background_color_off;
    }
    else
    {
        pos_btn = (x + size) + (resize / 2);
        background_color = background_color_on;
    }
}

sui::SwitchButton::SwitchButton()
{
    background_color = background_color_off;
    mode();
    editSwitchButton();
}

void sui::SwitchButton::setPosition(const int x, const int y)
{
    this->x = x;
    this->y = y;
    editSwitchButton();
}

void sui::SwitchButton::setSize(const int size)
{
    this->size = size;
    editSwitchButton();
}

void sui::SwitchButton::setBackgroundColorON(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    background_color_on = sui::UIColor(red, green, blue);
    editSwitchButton();
}

void sui::SwitchButton::setBackgroundColorON(std::string HEX)
{
    background_color_on = sui::func::color::hexToRGB(HEX);
    editSwitchButton();
}

void sui::SwitchButton::setBackgroundColorON(sui::Color color)
{
    background_color_on = sui::func::color::enum_to_color(color);
    editSwitchButton();
}

void sui::SwitchButton::setBackgroundColorOFF(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    background_color_off = sui::UIColor(red, green, blue);
    editSwitchButton();
}

void sui::SwitchButton::setBackgroundColorOFF(std::string HEX)
{
    background_color_off = sui::func::color::hexToRGB(HEX);
    editSwitchButton();
}

void sui::SwitchButton::setBackgroundColorOFF(sui::Color color)
{
    background_color_off = sui::func::color::enum_to_color(color);
    editSwitchButton();
}

bool sui::SwitchButton::isClick(const sui::UIWindow& window)
{
    sui::UICoord crd = sui::func::mouse::getMousePos(window);

    if 
    (   (crd.x >= this->x - resize && crd.x <= this->x + this->size + resize) && 
        (crd.y >= this->y && crd.y <= this->y + this->resize) && 
        sui::func::mouse::isClick()
    )
    {
        is_on = !is_on;
        mode();
        editSwitchButton();
    }
        

    return is_on;
}

void sui::SwitchButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(center, states);
    target.draw(left, states);
    target.draw(right, states);
    target.draw(btn, states);
}



void sui::RadioButton::editRadioButton()
{
    radio_btn_vector.clear();
    for (int i = 1; i <= count; ++i)
    {
        radio_btn_cirlce.setRadius(size);
        radio_btn_cirlce.setPosition(sf::Vector2f(x, (y * i) + size * i));
        radio_btn_cirlce.setFillColor(radio_btn_color);

        radio_btn_cirlce.setOutlineThickness(outline_size);
        radio_btn_cirlce.setOutlineColor(outline_color);

        radio_btn_vector.push_back(radio_btn_cirlce);

        mark_btn_circle.setRadius(size / 2);
        mark_btn_circle.setPosition(sf::Vector2f(mark_x, mark_y));
        mark_btn_circle.setFillColor(radio_btn_color);
        mark_btn_circle.setOutlineThickness(size / 5);
        mark_btn_circle.setOutlineColor(mark_btn_color);
    }
}

sui::RadioButton::RadioButton(int count) : count(count)
{
    editRadioButton();
}

void sui::RadioButton::setPosition(const int x, const int y)
{
    this->x = x;
    this->y = y;
    editRadioButton();
}

void sui::RadioButton::setSize(const int size)
{
    this->size = size;
    editRadioButton();
}

void sui::RadioButton::setCount(const int count)
{
    this->count = count;
    editRadioButton();
}

void sui::RadioButton::setBackgroundColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    radio_btn_color = sui::UIColor(red, green, blue);
    editRadioButton();
}

void sui::RadioButton::setBackgroundColor(std::string HEX)
{
    radio_btn_color = sui::func::color::hexToRGB(HEX);
    editRadioButton();
}

void sui::RadioButton::setBackgroundColor(sui::Color color)
{
    radio_btn_color = sui::func::color::enum_to_color(color);
    editRadioButton();
}

void sui::RadioButton::setColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    mark_btn_color = sui::UIColor(red, green, blue);
    editRadioButton();
}

void sui::RadioButton::setColor(std::string HEX)
{
    mark_btn_color = sui::func::color::hexToRGB(HEX);
    editRadioButton();
}

void sui::RadioButton::setColor(sui::Color color)
{
    mark_btn_color = sui::func::color::enum_to_color(color);
    editRadioButton();
}

void sui::RadioButton::setOutLine(const int size)
{
    outline_size = size;
    editRadioButton();
}

void sui::RadioButton::setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    outline_color = sui::UIColor(red, green, blue);
    editRadioButton();
}

void sui::RadioButton::setOutLineColor(std::string HEX)
{
    outline_color = sui::func::color::hexToRGB(HEX);
    editRadioButton();
}

void sui::RadioButton::setOutLineColor(sui::Color color)
{
    outline_color = sui::func::color::enum_to_color(color);
    editRadioButton();
}

bool sui::RadioButton::isMarked(const sui::UIWindow& window)
{
    if (radio_btn_vector.empty()) return is_marked;
    
    sui::UICoord crd = sui::func::mouse::getMousePos(window);

    for (int i = 0; i < radio_btn_vector.size(); ++i)
    {
        if ((crd.x >= radio_btn_vector[i].getPosition().x - size && crd.x <= radio_btn_vector[i].getPosition().x + size) && 
        (crd.y >= radio_btn_vector[i].getPosition().y - size && crd.y <= radio_btn_vector[i].getPosition().y + size) && 
        sui::func::mouse::isClick())
        {
            value = i;
            is_marked = true;
            mark_x = radio_btn_vector[i].getPosition().x + size / 2;
            mark_y = radio_btn_vector[i].getPosition().y + size / 2;
            editRadioButton();
            return true;
        }
    }

    return is_marked;
}

int sui::RadioButton::getValue() const
{
    return value;
}

void sui::RadioButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (radio_btn_vector.empty()) return;

    for (const auto& rb_vec : radio_btn_vector)
    {
        target.draw(rb_vec, states);
    }

    if (is_marked) target.draw(mark_btn_circle, states);
}



void sui::ScrollBar::editPos()
{
    switch (scroll_mode)
    {
        case 0:
            scroll_line_x = win_width - size;
            scroll_line_y = 0;
            scroll_line_height = win_height;
            scroll_line_width = size;
            scroll_btn_width = size;
            scroll_btn_height = 50;
            break;
        
        case 1:
            scroll_line_x = 0;
            scroll_line_y = 0;
            scroll_line_height = win_height;
            scroll_line_width = size;
            scroll_btn_width = size;
            scroll_btn_height = 50;
            break;

        case 2:
            scroll_line_x = 0;
            scroll_line_y = win_height - size;
            scroll_line_width = win_width;
            scroll_line_height = size;
            scroll_btn_width = 50;
            scroll_btn_height = size;
            break;
        
        case 3:
            scroll_line_x = 0;
            scroll_line_y = 0;
            scroll_line_width = win_width;
            scroll_line_height = size;
            scroll_btn_width = 50;
            scroll_btn_height = size;
            break;
        
        default:
            scroll_line_x = win_width - size;
            scroll_line_y = 0;
            scroll_line_height = win_height;
            scroll_line_width = size;
            scroll_btn_width = size;
            scroll_btn_height = 50;
            break;
    }
}

void sui::ScrollBar::editScrollBar()
{
    scroll_line.setPosition(sf::Vector2f(scroll_line_x, scroll_line_y));
    scroll_line.setSize(sf::Vector2f(scroll_line_width, scroll_line_height));
    scroll_line.setFillColor(scroll_line_color);

    if (scroll_mode == Mode::Horizontal_RIGHT || scroll_mode == Mode::Horizontal_LEFT)
    {
        scroll_btn_x = scroll_line_x;
        scroll_btn_y = scroll_line_y + scroll_position * (scroll_line_height - scroll_btn_height);
    }
    else
    {
        scroll_btn_x = scroll_line_x + scroll_position * (scroll_line_width - scroll_btn_width);
        scroll_btn_y = scroll_line_y;
    }

    scroll_btn.setPosition(sf::Vector2f(scroll_btn_x, scroll_btn_y));
    scroll_btn.setSize(sf::Vector2f(scroll_btn_width, scroll_btn_height));
    scroll_btn.setFillColor(scroll_btn_color);
}

sui::ScrollBar::ScrollBar(const sui::UIWindow& window, int ScrollBarMode) : scroll_mode(ScrollBarMode)
{
    win_width = window.getSize().x;
    win_height = window.getSize().y;
    editPos();
    editScrollBar();
}

void sui::ScrollBar::setMode(const int mode)
{
    scroll_mode = mode;
    editPos();
    editScrollBar();
    
}

void sui::ScrollBar::setSize(const int size)
{
    this->size = size;
    editPos();
    editScrollBar();
}

void sui::ScrollBar::setLineColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    scroll_line_color = sui::UIColor(red, green, blue);
    editScrollBar();
}

void sui::ScrollBar::setLineColor(std::string HEX)
{
    scroll_line_color = sui::func::color::hexToRGB(HEX);
    editScrollBar();
}

void sui::ScrollBar::setLineColor(sui::Color color)
{
    scroll_line_color = sui::func::color::enum_to_color(color);
    editScrollBar();
}

void sui::ScrollBar::setButtonColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    scroll_btn_color = sui::UIColor(red, green, blue);
    editScrollBar();
}

void sui::ScrollBar::setButtonColor(std::string HEX)
{
    scroll_btn_color = sui::func::color::hexToRGB(HEX);
    editScrollBar();
}

void sui::ScrollBar::setButtonColor(sui::Color color)
{
    scroll_btn_color = sui::func::color::enum_to_color(color);
    editScrollBar();
}

void sui::ScrollBar::Update(const sui::UIWindow& window, const UIEvent& event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sui::UICoord mouse_pos = sui::func::mouse::getMousePos(window);

        if (mouse_pos.x >= scroll_btn_x && mouse_pos.x <= scroll_btn_x + scroll_btn_width &&
            mouse_pos.y >= scroll_btn_y && mouse_pos.y <= scroll_btn_y + scroll_btn_height) is_dragging = true;

    }

    else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        is_dragging = false;
    }

    else if (event.type == sf::Event::MouseMoved && is_dragging)
    {
        sui::UICoord mouse_pos = sui::func::mouse::getMousePos(window);

        if (scroll_mode == Mode::Horizontal_RIGHT || scroll_mode == Mode::Horizontal_LEFT)
        {
            float new_y = mouse_pos.y - scroll_btn_height / 2;
            new_y = std::max(float(scroll_line_y), std::min(new_y, float(scroll_line_y + scroll_line_height - scroll_btn_height)));
            scroll_position = (new_y - scroll_line_y) / (scroll_line_height - scroll_btn_height);
        }

        else
        {
            float new_x = mouse_pos.x - scroll_btn_width / 2;
            new_x = std::max(float(scroll_line_x), std::min(new_x, float(scroll_line_x + scroll_line_width - scroll_btn_width)));
            scroll_position = (new_x - scroll_line_x) / (scroll_line_width - scroll_btn_width);
        }
        editScrollBar();
    }
}

float sui::ScrollBar::getScrollPosition() const
{
    return scroll_position;
}

void sui::ScrollBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(scroll_line, states);
    target.draw(scroll_btn, states);
}