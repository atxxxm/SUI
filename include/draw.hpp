#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include "sfml_aliases.hpp"
#include <vector>
#include "sui_func.hpp"

namespace sui
{
    struct Font
    {
        sui::UIFont font;
        sui::UIFont loadFont(std::string path_to_font);
    };

    class Frame : public sui::UIElement
    {
    private:
        int frame_x = 100, frame_y = 100, frame_width = 200, frame_height = 400;
        sui::UIColor color_frame = sui::UIColor(255, 255, 255);
        sui::UIColor color_frame_outline = sui::UIColor(200, 200, 200);
        sui::UIRect frame_rect;
        int outline_size = 0;
        void edit_frame();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    public:
        Frame();
        Frame(const int x, const int y);
        Frame(const int x, const int y, const int width, const int height);

        void setPosition(const int x, const int y);
        void setSize(const int width, const int height);
        void setColor(const uint8_t red, const uint8_t green, const uint8_t blue);
        void setColor(std::string HEX);
        void setColor(sui::Color color);

        void setOutLine(const int size);
        void setOutLineColor(const uint8_t red, const uint8_t green, const int blue);
        void setOutLineColor(std::string HEX);
        void setOutLineColor(sui::Color color);
        sui::UICoord getPosition() const;
        sui::UIScale getSize() const;

        ~Frame() {};
    };

    class Button : public sui::UIElement
    {
    private:
        sui::UIRect button_rect;
        sui::UIText button_text;
        sui::UIFont button_font;
        std::string button_label_text = "Click";
        int button_x = 100, button_y = 100, button_width = 250, button_height = 100;
        unsigned int button_text_size = 30;
        sui::UIColor button_backround_color = sui::UIColor(255, 255, 255);
        sui::UIColor button_text_color = sui::UIColor(0, 0, 0);

        sui::UIColor background_color_outline = sui::UIColor(200, 200, 200);
        int outline_size = 0;

        void edit_button();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    public:
        Button();
        Button(const std::string& label);
        Button(const int x, const int y, const std::string& label);
        Button(const int x, const int y, const int width, const int height, const std::string& label);

        void setPosition(const int x, const int y);
        void setSize(const int width, const int height);
        void setBagroundColor(const uint8_t red, const uint8_t green, const uint8_t blue);
        void setBagroundColor(std::string HEX);
        void setBagroundColor(sui::Color color);

        void setText(const std::string& label);
        void setSizeText(const unsigned int size);
        void setTextColor(const uint8_t red, const uint8_t green, const uint8_t blue);
        void setTextColor(std::string HEX);
        void setTextColor(sui::Color color);
        void setTextFont(sui::Font& font);

        void setOutLine(const int size);
        void setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue);
        void setOutLineColor(std::string HEX);
        void setOutLineColor(sui::Color color);

        sui::UICoord getPosition() const;
        sui::UIScale getSize() const;

        bool isClick(const sui::UIWindow& window);
        bool isHover(const sui::UIWindow& window);

        ~Button() {};
    };

    class Label : public sui::UIElement
    {
        private:
            unsigned int size_label = 40;
            int label_x = 200, label_y = 100;
            std::string label_text = "Label";
            sui::UIText label_label;
            sui::UIFont label_font;
            sui::UIColor label_color = sui::UIColor(255, 255, 255);

            void editLabel();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        public:
            Label(const std::string& label);
            Label(const std::string& label, const int x, const int y);
            Label(const std::string& label, const int x, const int y, const unsigned int size);
            Label(const std::string& label, const int x, const int y, const unsigned int size, const Font& font);

            void setText(const std::string &label);
            void setFont(const sui::Font& font);
            void setColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setColor(std::string HEX);
            void setColor(sui::Color color);
            void setSize(const unsigned int size);
            void setPosition(const int x, const int y);

            sui::UICoord getPosition() const;
            sui::UIScale getSize() const;

            ~Label() {};
            
    };

    class InputText : public sui::UIElement
    {
        private:
            sui::UIRect input_text_rect;
            sui::UIText input_text_text;
            sui::UIFont input_text_font;
            sui::UIColor background_color_input_text = sui::UIColor(255, 255, 255);
            sui::UIColor text_color_input_text = sui::UIColor(0, 0, 0);
            std::string input_text_txt;
            bool isFocus = false;

            int input_text_rect_x = 100, input_text_rect_y = 100;
            int input_text_rect_width = 200, input_text_rect_height = 100;

            unsigned int input_text_size = 25;
            int col_char = 0;

            sui::UIColor background_color_input_text_outline = sui::UIColor(200, 200, 200);
            int outline_size = 0;

            void editInputText();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        public:
            InputText();
            InputText(const int x, const int y);
            InputText(const int x, const int y, const int width, const int height);
            InputText(const sui::Font& font);

            void setPosition(const int x, const int y);
            void setSize(const int width, const int height);
            void setBackgroundColor(const u_int8_t red, const uint8_t green, const uint8_t blue);
            void setBackgroundColor(std::string HEX);
            void setBackgroundColor(sui::Color color);

            void setOutLine(const int size);
            void setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setOutLineColor(std::string HEX);
            void setOutLineColor(sui::Color color);

            void setTextColor(const u_int8_t red, const uint8_t green, const uint8_t blue);
            void setTextColor(std::string HEX);
            void setTextColor(sui::Color color);
            void setTextSize(const unsigned int size);
            void setTextFont(const sui::Font& font);

            void setFocus(const sui::UIWindow& window);
            std::string isPrint(sui::UIEvent& event);
    
            ~InputText() {};

    };

    class Image : public sui::UIElement
    {
        private:
            sf::Texture img_texture;
            sf::Sprite img_sprite;
            std::string path_to_image;

            float img_x = 100, img_y = 100, img_width = 0.5, img_height = 0.5;

            void edit_img();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        public:
            Image(const std::string& path);
            void setPosition(const float x, const float y);
            void setSize(const float width, const float height);
            ~Image() {};

    };

    class CheckBox : public sui::UIElement
    {
        private:
            sui::UIRect checkbox_rect;
            sui::UIRect cross_rect_1;
            sui::UIRect cross_rect_2;
            sui::UIColor checkbox_color = sui::UIColor(255, 255, 255);
            sui::UIColor cross_color = sui::UIColor(0, 0, 0);

            sui::UIColor outline_color = sui::UIColor(200, 200, 200);
            int outline_size = 0;

            bool isMarked_bool = false;
            int checkbox_x = 100, checkbox_y = 100, checkbox_width = 50, checkbox_height = 50;
            void editCheckBox();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        public:
            CheckBox();
            CheckBox(const int x, const int y);
            CheckBox(const int x, const int y, const int width, const int height);
            void setPosition(const int x, const int y);
            void setSize(const int width, const int height);
            void setBackgroundColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setBackgroundColor(std::string HEX);
            void setBackgroundColor(sui::Color color);

            void setOutLine(const int size);
            void setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setOutLineColor(std::string HEX);
            void setOutLineColor(sui::Color color);

            void setColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setColor(std::string HEX);
            void setColor(sui::Color color);

            bool isMarked(const sui::UIWindow& window);

            ~CheckBox() {};

    };

    class Slider : public sui::UIElement
    {
        private:
            sui::UIRect slide_bar;
            sui::UICircle slide_button;
            sui::UIColor slide_bar_color = sui::UIColor(255, 255, 255);
            sui::UIColor slide_button_color = sui::UIColor(0, 0, 255);
            int slide_bar_x = 100, slide_bar_y = 100, slide_bar_size = 200;
            float min_value = 0.0f, max_value = 100.0f;

            void editSlider();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        public:
            Slider();
            Slider(const float min_val, const float max_val);
            Slider(const int x, const int y);
            Slider(const int x, const int y, const int size);
            void setPosition(const int x, const int y);
            void setSize(const int size);
            void setBackgroundColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setBackgroundColor(std::string HEX);
            void setBackgroundColor(sui::Color color);

            void setColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setColor(std::string HEX);
            void setColor(sui::Color color);
            void isMove(const sui::UIWindow& window, sui::UIEvent& event);

            void setRange(const float min_val, const float max_val);
            float getValue() const;

            ~Slider() {};
    };

    class DropdownList : public sui::UIElement
    {
        private:
            sui::UIRect main_rect;
            sui::UIRect dropdown_rect;
            sui::UIText main_text;
            std::vector<UIText> items_text;
            sui::UIFont dropdown_font;
            
            sui::UIColor main_color = sui::UIColor::White;
            sui::UIColor hover_color = sui::UIColor(200, 200, 200);
            sui::UIColor text_color = sui::UIColor::Black;
            sui::UIColor outline_color = sui::UIColor(200, 200, 200);
            
            int dropdown_x = 100, dropdown_y = 50, dropdown_size = 200, selected_index = -1;
            int outline_size = 0;
            bool isOpen = false;
            sui::UIStrList items;

            void editDropdownList();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        public:
            DropdownList(const sui::UIStrList& items);
            void setPosition(const int x, const int y);
            void setSize(const int size);

            void setOutLine(const int size);
            void setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setOutLineColor(std::string HEX);
            void setOutLineColor(sui::Color color);

            void setItems(const sui::UIStrList& new_items);
            void checkEvent(const sui::UIWindow& window, const sui::UIEvent& event);
            std::string getSelectedItem() const;
            int getSelectedIndex() const;
            ~DropdownList() {}
    };

    class ProgressBar : public sui::UIElement
    {
        private:
            sui::UIRect bar_rect; 
            sui::UIRect progress_rect; 
            sui::UIColor bar_color = sui::UIColor(200, 200, 200); 
            sui::UIColor progress_color = sui::UIColor(0, 255, 0); 
            int bar_x = 100, bar_y = 100, bar_width = 200, bar_height = 20;
            float progress = 0.0f;

            sui::UIColor outline_color = sui::UIColor(200, 200, 200);
            int outline_size = 0;

            void editProgressBar();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override; 

        public:
            ProgressBar();
            ProgressBar(const int x, const int y);
            ProgressBar(const int x, const int y, const int width, const int height);

            void setPosition(const int x, const int y);
            void setSize(const int width, const int height);

            void setOutLine(const int size);
            void setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setOutLineColor(std::string HEX);
            void setOutLineColor(sui::Color color);

            void setBackgroundColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setBackgroundColor(std::string HEX);
            void setBackgroundColor(sui::Color color);
            void setColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setColor(std::string HEX);
            void setColor(sui::Color color);

            void setProgress(float value);
            float getProgress() const;

            sui::UICoord getPosition() const;
            sui::UIScale getSize() const;

            ~ProgressBar() {};
    };

    class SwitchButton : public sui::UIElement
    {
        private:
            sui::UIRect center;
            sui::UICircle left;
            sui::UICircle right;
            sui::UIColor background_color;
            sui::UIColor background_color_off = sui::UIColor(255, 255, 255);
            sui::UIColor background_color_on = sui::UIColor(66, 170, 255);

            sui::UICircle btn;
            sui::UIColor btn_color = sui::UIColor(100, 100, 100);
            int pos_btn;

            int x = 100, y = 100, size = 200, resize = size / 1.2;
            bool is_on = false;

            void editSwitchButton();
            void mode();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        public:
            SwitchButton();
            void setPosition(const int x, const int y);
            void setSize(const int size);

            void setBackgroundColorON(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setBackgroundColorON(std::string HEX);
            void setBackgroundColorON(sui::Color color);

            void setBackgroundColorOFF(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setBackgroundColorOFF(std::string HEX);
            void setBackgroundColorOFF(sui::Color color);

            bool isClick(const sui::UIWindow& window);

            ~SwitchButton() {}
    };

    class RadioButton : public sui::UIElement
    {
        private:
            sui::UICircle radio_btn_cirlce;
            sui::UICircle mark_btn_circle;

            sui::UIColor radio_btn_color = sui::UIColor(255, 255, 255);
            sui::UIColor mark_btn_color = sui::UIColor(0, 0, 0);

            std::vector<sui::UICircle> radio_btn_vector;
            int size = 20, count = 0, x = 100, y = 50;
            int mark_x = 0, mark_y = 0;
            int value = 0;

            sui::UIColor outline_color = sui::UIColor(200, 200, 200);
            int outline_size = 0;

            bool is_marked = false;

            void editRadioButton();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        public:
            RadioButton(int count);
            void setPosition(const int x, const int y);
            void setSize(const int size);
            void setCount(const int count);

            void setBackgroundColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setBackgroundColor(std::string HEX);
            void setBackgroundColor(sui::Color color);

            void setColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setColor(std::string HEX);
            void setColor(sui::Color color);

            void setOutLine(const int size);
            void setOutLineColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setOutLineColor(std::string HEX);
            void setOutLineColor(sui::Color color);

            bool isMarked(const sui::UIWindow& window);
            int getValue() const;
            ~RadioButton() {}


    };

    class ScrollBar : public sui::UIElement
    {
        private:
            sui::UIRect scroll_line;
            sui::UIRect scroll_btn;

            sui::UIColor scroll_line_color = sui::UIColor(255, 255, 255);
            sui::UIColor scroll_btn_color = sui::UIColor(200, 200, 200);

            int scroll_line_x = 0, scroll_line_y = 0, scroll_line_width = 0, scroll_line_height = 0;
            int scroll_btn_x = 0, scroll_btn_y = 0, scroll_btn_width = 0, scroll_btn_height = 0;
            int win_width = 0, win_height = 0;
            int scroll_mode = 0, size = 20;
            float scroll_position = 0.0f;
            bool is_dragging = false;

            void editPos();
            void editScrollBar();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            
        public:
            ScrollBar(const sui::UIWindow& window, int ScrollBarMode = sui::Mode::Horizontal_RIGHT);
            void setMode(const int mode);
            void setSize(const int size);

            void setLineColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setLineColor(std::string HEX);
            void setLineColor(sui::Color color);

            void setButtonColor(const uint8_t red, const uint8_t green, const uint8_t blue);
            void setButtonColor(std::string HEX);
            void setButtonColor(sui::Color color);

            float getScrollPosition() const;
            void Update(const sui::UIWindow& window, const sui::UIEvent& event);
            ~ScrollBar() {}
    };
}