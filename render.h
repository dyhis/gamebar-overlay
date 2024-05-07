#define IMGUI_DEFINE_MATH_OPERATORS
#include "loop.h"
#include "icons.h"
#include <D3D11.h>
#include "icon.h"
#include "fonts.h"
#include <format>

#include "image.h"
#include "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\D3DX11core.h"
#include "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\D3DX11.h"
#include "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\D3DX11tex.h"
#include "logoperception.h"
#include "impl/inc.hpp"

#pragma comment(lib, "D3DX11.lib")

static const char* keyNames[] =
{

    "Keybind",
    "Left Mouse",
    "Right Mouse",
    "Cancel",
    "Middle Mouse",
    "Mouse 5",
    "Mouse 4",
    "",
    "Backspace",
    "Tab",
    "",
    "",
    "Clear",
    "Enter",
    "",
    "",
    "Shift",
    "Control",
    "Alt",
    "Pause",
    "Caps",
    "",
    "",
    "",
    "",
    "",
    "",
    "Escape",
    "",
    "",
    "",
    "",
    "Space",
    "Page Up",
    "Page Down",
    "End",
    "Home",
    "Left",
    "Up",
    "Right",
    "Down",
    "",
    "",
    "",
    "Print",
    "Insert",
    "Delete",
    "",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "",
    "",
    "",
    "",
    "",
    "Numpad 0",
    "Numpad 1",
    "Numpad 2",
    "Numpad 3",
    "Numpad 4",
    "Numpad 5",
    "Numpad 6",
    "Numpad 7",
    "Numpad 8",
    "Numpad 9",
    "Multiply",
    "Add",
    "",
    "Subtract",
    "Decimal",
    "Divide",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
};

static const char* keyNamesTB[] =
{

    "Keybind",
    "Left Mouse",
    "Right Mouse",
    "Cancel",
    "Middle Mouse",
    "Mouse 5",
    "Mouse 4",
    "",
    "Backspace",
    "Tab",
    "",
    "",
    "Clear",
    "Enter",
    "",
    "",
    "Shift",
    "Control",
    "Alt",
    "Pause",
    "Caps",
    "",
    "",
    "",
    "",
    "",
    "",
    "Escape",
    "",
    "",
    "",
    "",
    "Space",
    "Page Up",
    "Page Down",
    "End",
    "Home",
    "Left",
    "Up",
    "Right",
    "Down",
    "",
    "",
    "",
    "Print",
    "Insert",
    "Delete",
    "",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "",
    "",
    "",
    "",
    "",
    "Numpad 0",
    "Numpad 1",
    "Numpad 2",
    "Numpad 3",
    "Numpad 4",
    "Numpad 5",
    "Numpad 6",
    "Numpad 7",
    "Numpad 8",
    "Numpad 9",
    "Multiply",
    "Add",
    "",
    "Subtract",
    "Decimal",
    "Divide",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
};

const int KeyCodes[] = {
    0x00,   // "Keybind"
    VK_LBUTTON, // "Left Mouse"
    VK_RBUTTON, // "Right Mouse"
    VK_CANCEL,  // "Cancel"
    VK_MBUTTON, // "Middle Mouse"
    VK_XBUTTON2, // "Mouse 5"
    VK_XBUTTON1, // "Mouse 4"
    0,          // ""
    VK_BACK,    // "Backspace"
    VK_TAB,     // "Tab"
    0, 0, 0, 0,      // "", ""
    VK_CLEAR,   // "Clear"
    VK_RETURN,  // "Enter"
    0, 0,       // "", ""
    VK_SHIFT,   // "Shift"
    VK_CONTROL, // "Control"
    VK_MENU,    // "Alt"
    VK_PAUSE,   // "Pause"
    VK_CAPITAL, // "Caps"
    0, 0, 0, 0, 0, 0, // "", "", "", "", "", ""
    VK_ESCAPE,  // "Escape"
    0, 0, 0, 0, // "", "", "", ""
    VK_SPACE,   // "Space"
    VK_PRIOR,   // "Page Up"
    VK_NEXT,    // "Page Down"
    VK_END,     // "End"
    VK_HOME,    // "Home"
    VK_LEFT,    // "Left"
    VK_UP,      // "Up"
    VK_RIGHT,   // "Right"
    VK_DOWN,    // "Down"
    0, 0, 0,    // "", "", ""
    VK_SNAPSHOT,// "Print"
    VK_INSERT,  // "Insert"
    VK_DELETE,  // "Delete"
    0,          // ""
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', // "0" to "9"
    0, 0, 0, 0, 0, 0, 0, // "", "", "", "", "", "", ""
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', // "A" to "Z"
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""
    VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9, // "Numpad 0" to "Numpad 9"
    VK_MULTIPLY, VK_ADD, 0, VK_SUBTRACT, VK_DECIMAL, VK_DIVIDE, // "Multiply", "Add", "", "Subtract", "Decimal", "Divide"
    VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12 // "F1" to "F12"
};

const int KeyCodesTB[] = {
    0x00,   // "Keybind"
    VK_LBUTTON, // "Left Mouse"
    VK_RBUTTON, // "Right Mouse"
    VK_CANCEL,  // "Cancel"
    VK_MBUTTON, // "Middle Mouse"
    VK_XBUTTON2, // "Mouse 5"
    VK_XBUTTON1, // "Mouse 4"
    0,          // ""
    VK_BACK,    // "Backspace"
    VK_TAB,     // "Tab"
    0, 0, 0, 0,      // "", ""
    VK_CLEAR,   // "Clear"
    VK_RETURN,  // "Enter"
    0, 0,       // "", ""
    VK_SHIFT,   // "Shift"
    VK_CONTROL, // "Control"
    VK_MENU,    // "Alt"
    VK_PAUSE,   // "Pause"
    VK_CAPITAL, // "Caps"
    0, 0, 0, 0, 0, 0, // "", "", "", "", "", ""
    VK_ESCAPE,  // "Escape"
    0, 0, 0, 0, // "", "", "", ""
    VK_SPACE,   // "Space"
    VK_PRIOR,   // "Page Up"
    VK_NEXT,    // "Page Down"
    VK_END,     // "End"
    VK_HOME,    // "Home"
    VK_LEFT,    // "Left"
    VK_UP,      // "Up"
    VK_RIGHT,   // "Right"
    VK_DOWN,    // "Down"
    0, 0, 0,    // "", "", ""
    VK_SNAPSHOT,// "Print"
    VK_INSERT,  // "Insert"
    VK_DELETE,  // "Delete"
    0,          // ""
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', // "0" to "9"
    0, 0, 0, 0, 0, 0, 0, // "", "", "", "", "", "", ""
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', // "A" to "Z"
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""
    VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9, // "Numpad 0" to "Numpad 9"
    VK_MULTIPLY, VK_ADD, 0, VK_SUBTRACT, VK_DECIMAL, VK_DIVIDE, // "Multiply", "Add", "", "Subtract", "Decimal", "Divide"
    VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12 // "F1" to "F12"
};

namespace m_interface
{

    struct c_tab {
        int m_num;
        const char* m_label;

        std::function< void() > page;

        c_tab(int num, const char* label) {
            m_num = num;
            m_label = label;
        }
    };

    class c_interface
    {
        bool hover_element = ud::hover_element;
        fvector2d drag_position{};

        flinearcolor color_menu_bg = { };
        flinearcolor color_menu_bar = { };
        flinearcolor color_menu_fg = { };
        flinearcolor color_menu_theme = { };

        flinearcolor color_checkbox_bg = { };
        flinearcolor color_checkbox_active = { };
        flinearcolor color_checkbox_hovered = { };
        m_interface::c_interface* active_showcase;

        // New member for enabling/disabling the showcase
        bool enabler = false;

    public:

        c_interface();

        void draw_frames();
        void draw_interface();
        void begin(fvector2d start, fvector2d size);
        void begin_parent(const std::string& title, fvector2d start, fvector2d size);
        void handler();
        int handle_tab_click(int index);

        fvector2d get_cursor();

        bool is_hovered(fvector2d Start, fvector2d Size);
        bool button(std::string Title, fvector2d size);
        bool tab(int icon_id, std::string title, int tab_id, fvector2d size);
        void slider(std::string Title, float* Option, float Min, float Max);
        void check_box(std::string Title, bool* Option);
        void colour_showcase(std::string Title, std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, flinearcolor& selected_color, bool& enabler);
        void dropdown(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, const std::string label, std::vector<std::string>& items, std::int32_t& selected_item);
        void dropdowncfg(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, const std::string label, std::vector<std::string>& items, std::int32_t& selected_item);
        void dropdownextra(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, const std::string label, std::vector<std::string>& items, std::int32_t& selected_item);
        void draw_circle(float x, float y, float radius);

        bool add_widget(fvector2d size)
        {
            auto current = fvector2d(this->position.x + this->offset.x, this->position.y + this->offset.y);

            /*	m_framework.get()->rect(current.x, current.y, size.x, size.y, m_framework.get()->get_color(255, 38, 38, 38), 5);*/
            m_framework.get()->filled_rect(current.x, current.y, size.x, size.y, this->color_menu_bar, true, 5, 5);

            return true;
        }

        auto current_offset()
        {
            return fvector2d(this->position.x + this->offset.x, this->position.y + this->offset.y);
        }

        bool hotkey(int k) {
            auto current = fvector2d(this->position.x + this->offset.x, this->position.y + this->offset.y);
            auto size = fvector2d(70, 20);

            bool is_hovered = this->is_hovered(current, size);
            bool clicked = is_hovered && this->LeftMouseClicked;

            flinearcolor color = is_hovered ? m_framework.get()->get_color(255, 100, 100, 100) : m_framework.get()->get_color(255, 38, 38, 38);

            static bool waitingforkey = false;
            static bool ignoreMouseClick = false;

            if (clicked && !waitingforkey) {
                waitingforkey = true;
                ignoreMouseClick = true;
            }
            else if (waitingforkey) {
                if (ignoreMouseClick) {
                    ignoreMouseClick = false;
                }
                else {
                    for (int i = 0; i < sizeof(KeyCodes) / sizeof(KeyCodes[0]); ++i) {
                        if (this->LeftMouseClicked)
                        {
                            k = 0x01;
                            waitingforkey = false;
                            std::cout << "Mouse clicked, k set to 0x01." << std::endl;
                            break;
                        }

                        if (GetAsyncKeyState(KeyCodes[i]) & 0x01) {  // Check if the key was pressed.
                            ud::aimkey = KeyCodes[i];
                            k = ud::aimkey;
                            waitingforkey = false;
                            std::cout << "Key pressed, k set to " << std::hex << k << std::endl;
                            break;
                        }
                    }
                }
            }

            std::string string = waitingforkey ? "..." : keyNames[k];
            m_framework.get()->text(string, current.x + 35.0f, current.y + 16.0f, m_framework.get()->get_color(255, 163, 163, 163), 10, true, true);
            m_framework.get()->rect(current.x, current.y, size.x, size.y, color, 1.f);

            return true;
        }

        bool hotkeyTB(int k) {
            auto current = fvector2d(this->position.x + this->offset.x, this->position.y + this->offset.y);
            auto size = fvector2d(70, 20);

            bool is_hovered = this->is_hovered(current, size);
            bool clicked = is_hovered && this->LeftMouseClicked;

            flinearcolor color = is_hovered ? m_framework.get()->get_color(255, 100, 100, 100) : m_framework.get()->get_color(255, 38, 38, 38);

            static bool waitingforkey = false;
            static bool ignoreMouseClick = false;

            if (clicked && !waitingforkey) {
                waitingforkey = true;
                ignoreMouseClick = true;
            }
            else if (waitingforkey) {
                if (ignoreMouseClick) {
                    ignoreMouseClick = false;
                }
                else {
                    for (int i = 0; i < sizeof(KeyCodesTB) / sizeof(KeyCodesTB[0]); ++i) {
                        if (this->LeftMouseClicked)
                        {
                            k = 0x01;
                            waitingforkey = false;
                            std::cout << "Mouse clicked, k set to 0x01." << std::endl;
                            break;
                        }

                        if (GetAsyncKeyState(KeyCodesTB[i]) & 0x01) {  // Check if the key was pressed.
                            ud::TBkey = KeyCodesTB[i];
                            k = ud::TBkey;
                            waitingforkey = false;
                            std::cout << "Key pressed, k set to " << std::hex << k << std::endl;
                            break;
                        }
                    }
                }
            }

            std::string string = waitingforkey ? "..." : keyNamesTB[k];
            m_framework.get()->text(string, current.x + 35.0f, current.y + 16.0f, m_framework.get()->get_color(255, 163, 163, 163), 10, true, true);
            m_framework.get()->rect(current.x, current.y, size.x, size.y, color, 1.f);

            return true;
        }

        auto interactive_rect(fvector2d size, bool static_color = false, flinearcolor static_color_code = flinearcolor(255, 38, 38, 38))
        {
            auto current = this->current_offset();
            bool is_hovered = this->is_hovered(current, size);
            bool clicked = is_hovered && this->LeftMouseClicked;

            auto hover_color = m_framework.get()->get_color(255, 239, 158, 255);

            if (is_hovered && !static_color)
            {
                hover_color = m_framework.get()->get_color(255, 239, 158, 255);
            }
            else
            {
                hover_color = m_framework.get()->get_color(255, 38, 38, 38);
            }

            if (static_color)
                hover_color = static_color_code;

            m_framework.get()->filled_rect(current.x, current.y, size.x, size.y, hover_color, true, 2, 2);
            m_framework.get()->rect(current.x, current.y, size.x, size.y, m_framework.get()->get_color(255, 83, 83, 83), 1);

            return clicked;
        }

        bool header(std::string Title)
        {
            fvector2d size = fvector2d{ 46.0f, 25.0f };

            const auto current = fvector2d(this->position.x + this->offset.x, this->position.y + this->offset.y);


            //Outline
            //m_framework.get( )->rect( Current.x, Current.y, size.x, size.y, m_framework.get( )->get_color( 255, 38, 38, 38 ), true, 2, 2 );
            //m_framework.get( )->filled_rect( Current.x, Current.y, size.x, size.y, m_framework.get( )->get_color( 255, 32, 32, 32 ), true, 2, 2 );

            //Text
            auto text_pos = fvector2d{ current.x + size.x / 2, current.y + size.y / 1.25 };
            m_framework.get()->filled_rect(current.x, current.y, size.x, size.y, this->color_menu_bar, true, 2, 2);
            m_framework.get()->text(Title.c_str(), text_pos.x, text_pos.y, m_framework.get()->get_color(255, 255, 255, 255), 12, true, true);

            this->offset.y += size.y + this->ItemSpacing;
            //this->offset.x += size.x + 15;

            return true;

        }

        void set_position(fvector2d value);

        std::vector< m_interface::c_tab > m_tab{
            { 0, "Aimbot" },
            { 1, "Visuals" },
            { 2, "World" },
            { 3, "Customize" },
            { 4, "Config" }
        };

        float ItemSpacing;
        fvector2d position, size, offset, cursor;
        bool initialized = false;
        bool LeftMouseClicked, LeftMouseDown;

    private:

        int current_page = ud::page;

        void add_page(int tab, std::function< void() > code);
        void render_page();
    };
};

m_interface::c_interface::c_interface()
{

    this->color_menu_bg = flinearcolor(255, 18, 9, 15);
    this->color_menu_fg = flinearcolor(150, 23, 21, 30);
    this->color_menu_bar = flinearcolor(255, 22, 10, 25);
    this->color_menu_theme = flinearcolor(255, 216, 169, 255);


    this->color_checkbox_bg = flinearcolor(255, 18, 9, 15);         // Checkbox background color
    this->color_checkbox_hovered = flinearcolor(155, 239, 158, 255); // Checkbox hovered color
    this->color_checkbox_active = flinearcolor(255, 239, 158, 255);  // Checkbox active color
    this->active_showcase = nullptr;

    //m_setting.get()->load();
}

auto m_interface::c_interface::draw_interface() -> void
{
    this->add_page(0, [&]() {

        this->begin_parent("Aimbot", fvector2d(0, 0), fvector2d(750, 500));
        {
            this->set_position(fvector2d{ 265.f, 65.f });

            this->add_widget(fvector2d(213.0f, 250.f));
            {
                // HEADER/PIN
                this->set_position(fvector2d{ 265.f, 82.f });
                m_framework.get()->text("Aimbot Options", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

                this->set_position(fvector2d{ 265.f, 95.f });
                this->check_box("Aimbot", &ud::u_aimbot);

                this->set_position(fvector2d{ 360.f, 105.f });
                this->hotkey(ud::aimkey);

                this->set_position(fvector2d{ 265.f, 120.f });
                this->check_box("FOV Circle", &ud::u_render_fov);

                this->set_position(fvector2d{ 275.f, 175.f });
                this->slider("FOV Radius", &ud::u_aimfov, 0.f, 350.0f);

                this->set_position(fvector2d{ 275.f, 212.f });
                this->slider("Smooth", &ud::u_smooth, 1.f, 30.f);
                /*float unlock = 20.f;
                int debugKey = 0x0;
                if (debugKey == 0x78)
                {
                    unlock = 10.f;
                }
                else
                {
                    unlock = 20.f;
                }*/

                //this->slider("Smoothing", &ud::u_smooth, unlock, 30.0f);

                this->set_position(fvector2d{ 265.f, 237.f });
                this->check_box("Filled FOV", &ud::u_render_fov_filled);

                this->set_position(fvector2d{ 275.f, 292.f });
                this->slider("opacity", &ud::filled_fov_opacity, 10.f, 75.f);


            }

            this->set_position(fvector2d{ 265.f, 335.f });
            this->add_widget(fvector2d(213.0f, 150.f));
            {
                // HEADER/PIN
                this->set_position(fvector2d{ 265.f, 350 });
                m_framework.get()->text("Checks", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

                this->set_position(fvector2d{ 265.f , 365.f });
                this->check_box("Sniper Only Prediction", &ud::sniperonlyprediction);

                this->set_position(fvector2d{ 265.f, 390.f });
                //this->check_box("Ignore Knocked", &m_setting.get()->aim.ignore_knocked);

                //this->set_position(uemath::fvector2d{ 265.f, 415.f });
                this->check_box("Ignore downed", &ud::u_ignore_downed);

                std::vector<std::string> hitboxes = { "head", "neck", "chest", "pelvis" };
                this->dropdown(position.x + 275.f, position.y + 430, 80, 30, "hitbox", hitboxes, ud::u_hitbox);


            }


            this->set_position(fvector2d{ 500.f, 65.f });
            this->add_widget(fvector2d(213.0f, 200.f));
            {
                // HEADER/PIN
                this->set_position(fvector2d{ 500.f, 82.f });
                m_framework.get()->text("Triggerbot", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

                this->set_position(fvector2d{ 500.f, 95.f });
                this->check_box("Triggerbot", &ud::u_triggerbot);

                this->set_position(fvector2d{ 610.f, 105.f });
                this->hotkeyTB(ud::TBkey);

                this->set_position(fvector2d{ 500.f, 120.f });
                this->check_box("Shotgun Only", &ud::shotgun_only);

                this->set_position(fvector2d{ 510.f, 175.f });
                this->slider("Activation Range", &ud::u_maximum_distance, 1.f, 25.f);

                this->set_position(fvector2d{ 510.f, 212.f });
                this->slider("Delay", &ud::u_custom_delay, 1.f, 300.f);

                this->set_position(fvector2d{ 500.f, 228.f });
                this->check_box("Auto Aimbot", &ud::u_auto_aim_when_tb);

            }

            this->set_position(fvector2d{ 500.f, 285.f });
            this->add_widget(fvector2d(213.0f, 200.f));
            {
                // HEADER/PIN
                this->set_position(fvector2d{ 500.f, 300 });
                m_framework.get()->text("Weapon Config", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

                this->set_position(fvector2d{ 500.f, 313.f });
                this->check_box("Enable Configs", &ud::u_weapon_cfg);

                std::vector<std::string> Guns = { "shotgun", "AR", "SMG", "Sniper" };
                this->dropdowncfg(position.x + 510.f, position.y + 353.f, 80, 30, "Guns", Guns, ud::active_gun);

                if (ud::active_gun == 0)
                {
                    //ImGui::SliderInt("Shotgun FOV", &shotgun::aim_fov, 0, 300);
                    //ImGui::SliderInt("Shotgun smooth", &shotgun::smooth, 1, 20);
                    //ImGui::Combo(E("Shotgun Aim Bone"), &shotgun::hitbox, E("Head\0\Neck\0\Chest\0\Pelvis\0"));

                    this->set_position(fvector2d{ 510.f, 408.f });
                    this->slider("Shotgun FOV", &shotgun::aim_fov, 1.f, 300.f);

                    this->set_position(fvector2d{ 510.f, 463.f });
                    this->slider("Shotgun Smooth", &shotgun::smooth, 1.f, 30.f);

                    std::vector<std::string> shottybones = { "head", "neck", "chest", "pelvis" };
                    this->dropdownextra(position.x + 275.f, position.y + 430, 80, 30, "hitbox", shottybones, shotgun::hitbox);

                }
                else if (ud::active_gun == 1)
                {
                    this->set_position(fvector2d{ 510.f, 408.f });
                    this->slider("AR FOV", &rifle::aim_fov, 1.f, 300.f);

                    this->set_position(fvector2d{ 510.f, 463.f });
                    this->slider("AR Smooth", &rifle::smooth, 1.f, 30.f);

                    std::vector<std::string> ARboxes = { "head", "neck", "chest", "pelvis" };
                    this->dropdownextra(position.x + 275.f, position.y + 430, 80, 30, "hitbox", ARboxes, rifle::hitbox);
                }
                else if (ud::active_gun == 2)
                {
                    this->set_position(fvector2d{ 510.f, 408.f });
                    this->slider("SMG FOV", &smg::aim_fov, 1.f, 300.f);

                    this->set_position(fvector2d{ 510.f, 463.f });
                    this->slider("SMG Smooth", &smg::smooth, 1.f, 30.f);

                    std::vector<std::string> smgboxes = { "head", "neck", "chest", "pelvis" };
                    this->dropdownextra(position.x + 275.f, position.y + 430, 80, 30, "hitbox", smgboxes, smg::hitbox);
                }
                else if (ud::active_gun == 3)
                {
                    this->set_position(fvector2d{ 510.f, 408.f });
                    this->slider("Sniper FOV", &rifle::aim_fov, 1.f, 300.f);

                    this->set_position(fvector2d{ 510.f, 463.f });
                    this->slider("Sniper Smooth", &rifle::smooth, 1.f, 30.f);

                    std::vector<std::string> Sniperboxes = { "head", "neck", "chest", "pelvis" };
                    this->dropdownextra(position.x + 275.f, position.y + 430, 80, 30, "hitbox", Sniperboxes, sniper::hitbox);
                }
            }

        }

        });


    this->add_page(1, [&]() {
        this->set_position(fvector2d{ 750.f , 0.f });
        m_framework.get()->filled_rect(current_offset().x, current_offset().y, 315, 500, flinearcolor(255, 18, 9, 15), true, 5, 5);
        m_framework.get()->text("ESP Preview", current_offset().x + 10.f, current_offset().y + 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
        m_framework.get()->line(current_offset().x, current_offset().y + 24.f, current_offset().x + 315.f, current_offset().y + 24.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

        /*if (m_setting.get()->visuals.filled)
        {
            m_framework.get()->filled_rect(current_offset().x + 60, current_offset().y + 60, 190, 400, m_setting.get()->customize.filled_box, false, 0, 0);
        }*/

        if (ud::u_box_esp)
        {
            m_framework.get()->rect(current_offset().x + 60, current_offset().y + 60, 190, 400, ud::u_color_Visible, ud::u_box_thick);
        }

        if (ud::u_skeleton) {
            if (ud::u_skeleton) {
                float boxX = current_offset().x + 60 + 100;
                float boxY = current_offset().y - 60;
                float boxWidth = 190;
                float boxHeight = 400;
                float scaleFactor = 1.5;


                m_framework->line(boxX + scaleFactor * Preview::head_bone_x, boxY + scaleFactor * Preview::head_bone_y, boxX + scaleFactor * Preview::neck_bone_x, boxY + scaleFactor * Preview::neck_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::neck_bone_x, boxY + scaleFactor * Preview::neck_bone_y, boxX + scaleFactor * Preview::chest_bone_x, boxY + scaleFactor * Preview::chest_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::chest_bone_x, boxY + scaleFactor * Preview::chest_bone_y, boxX + scaleFactor * Preview::left_shoulder_bone_x, boxY + scaleFactor * Preview::left_shoulder_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::left_shoulder_bone_x, boxY + scaleFactor * Preview::left_shoulder_bone_y, boxX + scaleFactor * Preview::left_elbow_bone_x, boxY + scaleFactor * Preview::left_elbow_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::left_elbow_bone_x, boxY + scaleFactor * Preview::left_elbow_bone_y, boxX + scaleFactor * Preview::left_hand_bone_x, boxY + scaleFactor * Preview::left_hand_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::chest_bone_x, boxY + scaleFactor * Preview::chest_bone_y, boxX + scaleFactor * Preview::right_shoulder_bone_x, boxY + scaleFactor * Preview::right_shoulder_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::right_shoulder_bone_x, boxY + scaleFactor * Preview::right_shoulder_bone_y, boxX + scaleFactor * Preview::right_elbow_bone_x, boxY + scaleFactor * Preview::right_elbow_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::right_elbow_bone_x, boxY + scaleFactor * Preview::right_elbow_bone_y, boxX + scaleFactor * Preview::right_hand_bone_x, boxY + scaleFactor * Preview::right_hand_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::chest_bone_x, boxY + scaleFactor * Preview::chest_bone_y, boxX + scaleFactor * Preview::pelvis_bone_x, boxY + scaleFactor * Preview::pelvis_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::pelvis_bone_x, boxY + scaleFactor * Preview::pelvis_bone_y, boxX + scaleFactor * Preview::left_thigh_bone_x, boxY + scaleFactor * Preview::left_thigh_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::left_thigh_bone_x, boxY + scaleFactor * Preview::left_thigh_bone_y, boxX + scaleFactor * Preview::left_knee_bone_x, boxY + scaleFactor * Preview::left_knee_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::left_knee_bone_x, boxY + scaleFactor * Preview::left_knee_bone_y, boxX + scaleFactor * Preview::left_foot_bone_x, boxY + scaleFactor * Preview::left_foot_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::left_foot_bone_x, boxY + scaleFactor * Preview::left_foot_bone_y, boxX + scaleFactor * Preview::left_footfinger_bone_x, boxY + scaleFactor * Preview::left_footfinger_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::pelvis_bone_x, boxY + scaleFactor * Preview::pelvis_bone_y, boxX + scaleFactor * Preview::right_thigh_bone_x, boxY + scaleFactor * Preview::right_thigh_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::right_thigh_bone_x, boxY + scaleFactor * Preview::right_thigh_bone_y, boxX + scaleFactor * Preview::right_knee_bone_x, boxY + scaleFactor * Preview::right_knee_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::right_knee_bone_x, boxY + scaleFactor * Preview::right_knee_bone_y, boxX + scaleFactor * Preview::right_foot_bone_x, boxY + scaleFactor * Preview::right_foot_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);
                m_framework->line(boxX + scaleFactor * Preview::right_foot_bone_x, boxY + scaleFactor * Preview::right_foot_bone_y, boxX + scaleFactor * Preview::right_footfinger_bone_x, boxY + scaleFactor * Preview::right_footfinger_bone_y, ud::u_color_Visible, ud::u_skeleton_thick);

            }


        }


        if (ud::u_distance)
        {
            if (ud::u_white_text_color)
            {
                m_framework.get()->text("[12m]", current_offset().x + 140.f, current_offset().y + 460.0f, flinearcolor(255, 255, 255, 255), 13, false, false);
            }
            else
            {
                m_framework.get()->text("[12m]", current_offset().x + 140.f, current_offset().y + 460.0f, ud::u_color_Visible, 13, false, false);
            }

        }

        if (ud::u_username)
        {
            if (ud::u_white_text_color)
            {
                m_framework.get()->text(ud::local_username, current_offset().x + 120.f, current_offset().y + 34.0f, flinearcolor(255, 255, 255, 255), 13, false, false);
            }
            else
            {
                m_framework.get()->text(ud::local_username, current_offset().x + 120.f, current_offset().y + 34.0f, ud::u_color_Visible, 13, false, false);
            }

        }

        this->begin_parent("Visuals", fvector2d(0, 0), fvector2d(750, 500));
        {


            this->set_position(fvector2d{ 265.f, 65.f });
            this->add_widget(fvector2d(213.0f, 420.0f));
            {
                this->set_position(fvector2d{ 265.f, 82.f });
                m_framework.get()->text("Main Options", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

                this->set_position(fvector2d{ 265.f, 95.f });
                this->check_box("ESP", &ud::u_enable_esp);

                if (ud::u_enable_esp)
                {
                    this->set_position(fvector2d{ 265.f, 130.f });
                    this->check_box("Box", &ud::u_box_esp);

                    /*this->set_position(fvector2d{ 265.f, 155.f });
                    this->check_box("Filled Box", &ud::u_box_type);*/

                    this->set_position(fvector2d{ 265.f,  190.f });
                    this->check_box("Skeleton", &ud::u_skeleton);

                    this->set_position(fvector2d{ 265.f,  215.f });
                    this->check_box("Snapline", &ud::u_line);

                    this->set_position(fvector2d{ 265.f,  240.f });
                    this->check_box("Distance", &ud::u_distance);

                    this->set_position(fvector2d{ 265.f, 275.f });
                    this->check_box("Name ESP", &ud::u_username);

                    this->set_position(fvector2d{ 265.f, 300.f });
                    this->check_box("Weapon ESP", &ud::u_weapon_esp);

                    this->set_position(fvector2d{ 265.f, 335.f });
                    this->check_box("Team ID", &ud::u_teamid);

                    this->set_position(fvector2d{ 265.f, 370 });
                    this->check_box("WASD", &ud::showwasd);

                    //this->set_position(uemath::fvector2d{ 265.f,  275.f });
                    //this->check_box("Bot Check", &m_setting.get()->visuals.);
                }
            }

            this->set_position(fvector2d{ 500.f, 65.f });
            this->add_widget(fvector2d(213.0f, 200.f));
            {
                // HEADER/PIN
                this->set_position(fvector2d{ 500.f, 82.f });
                m_framework.get()->text("Extra", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

                /*this->set_position(fvector2d{ 510.f, 115.f });
                this->slider("Box Width", &m_setting.get()->visuals.box_width, 0.2f, 1.f);*/

                this->set_position(fvector2d{ 510.f, 95.f });
                this->check_box("ESP Auto Thickness", &ud::esp_auto_thick);
                if (!ud::esp_auto_thick)
                {
                    this->set_position(fvector2d{ 510.f, 152.f });
                    this->slider("Box Thickness", &ud::u_box_thick, 0.5f, 5.f);

                    this->set_position(fvector2d{ 510.f, 189.f });
                    this->slider("Skeleton Thickness", &ud::u_skeleton_thick, 1.f, 8.f);

                    this->set_position(fvector2d{ 510.f, 226.f });
                    this->slider("Maximum Distance", &ud::u_render_distance, 10.f, 350.f);
                }
            }

            this->set_position(fvector2d{ 500.f, 285.f });
            this->add_widget(fvector2d(213.0f, 200.f));
            {
                // HEADER/PIN
                this->set_position(fvector2d{ 500.f, 300 });
                m_framework.get()->text("Checks", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

                this->set_position(fvector2d{ 500.f, 313.f });
                this->check_box("Vis Check", &ud::u_visible_check);

                this->set_position(fvector2d{ 500.f, 338.f });
                this->check_box("Ignore Dying", &ud::u_ignore_dead);

                this->set_position(fvector2d{ 500.f, 363.f });
                this->check_box("Ignore DBNO/Knocked", &ud::u_ignore_downed);

                this->set_position(fvector2d{ 500.f, 398.f });
                this->check_box("Crosshair", &ud::u_enable_crosshair);
            }
        }

        });


    this->add_page(3, [&]() {

        this->set_position(fvector2d{ 750.f , 0.f });
        m_framework.get()->filled_rect(current_offset().x, current_offset().y, 315, 500, flinearcolor(255, 18, 9, 15), true, 5, 5);
        m_framework.get()->text("ESP Preview", current_offset().x + 10.f, current_offset().y + 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
        m_framework.get()->line(current_offset().x, current_offset().y + 24.f, current_offset().x + 315.f, current_offset().y + 24.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

        /*if (m_setting.get()->visuals.filled)
        {
            m_framework.get()->filled_rect(current_offset().x + 60, current_offset().y + 60, 190, 400, m_setting.get()->customize.filled_box, false, 0, 0);
        }*/

        if (ud::u_box_esp)
        {
            m_framework.get()->rect(current_offset().x + 60, current_offset().y + 60, 190, 400, ud::u_color_Visible, ud::u_box_thick);
        }

        if (ud::u_distance)
        {
            if (ud::u_white_text_color)
            {
                m_framework.get()->text("[10m]", current_offset().x + 140.f, current_offset().y + 460.0f, flinearcolor(255, 255, 255, 255), 13, false, false);
            }
            else
            {
                m_framework.get()->text("[10m]", current_offset().x + 140.f, current_offset().y + 460.0f, ud::u_color_Visible, 13, false, false);
            }

        }

        if (ud::u_username)
        {
            if (ud::u_white_text_color)
            {
                m_framework.get()->text("[Local Player]", current_offset().x + 140.f, current_offset().y - 20.0f, flinearcolor(255, 255, 255, 255), 13, false, false);
            }
            else
            {
                m_framework.get()->text("[Local Player]", current_offset().x + 140.f, current_offset().y - 20.0f, ud::u_color_Visible, 13, false, false);
            }

        }

        this->begin_parent("Customise", fvector2d(0, 0), fvector2d(750, 500));
        {

            this->set_position(fvector2d{ 265.f, 65.f });
            this->add_widget(fvector2d(213.0f, 420.0f));
            {
                this->set_position(fvector2d{ 265.f, 82.f });
                m_framework.get()->text("Vis/Invis Color", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(ud::u_color_Visible.a, ud::u_color_Visible.r, ud::u_color_Visible.g, ud::u_color_Visible.b), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(ud::u_color_invisible.a, ud::u_color_invisible.r, ud::u_color_invisible.g, ud::u_color_invisible.b), 1.0f);

                /*this->set_position(fvector2d{ 265.f, 95.f });
                this->colour_showcase("Box Visible", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.box, m_setting.get()->customize.bool_box);

                this->set_position(fvector2d{ 265.f, 120.f });
                this->colour_showcase("Box Invisible", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.invis_box, m_setting.get()->customize.bool_invis_box);


                this->set_position(fvector2d{ 265.f, 165.f });
                this->colour_showcase("Filled Box Visible", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.filled_box, m_setting.get()->customize.bool_filled_box);

                this->set_position(fvector2d{ 265.f, 190.f });
                this->colour_showcase("Filled Box Invisible", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.invis_filled_box, m_setting.get()->customize.bool_invis_filled_box);


                this->set_position(fvector2d{ 265.f, 235.f });
                this->colour_showcase("Skeleton Visible", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.skeleton, m_setting.get()->customize.bool_skeleton);

                this->set_position(fvector2d{ 265.f, 260.f });
                this->colour_showcase("Skeleton Invisible", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.invis_skeleton, m_setting.get()->customize.bool_invis_skeleton);


                this->set_position(fvector2d{ 265.f, 310.f });
                this->colour_showcase("Text Visible", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.text, m_setting.get()->customize.bool_text);

                this->set_position(fvector2d{ 265.f, 335.f });
                this->colour_showcase("Text Invisible", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.invis_text, m_setting.get()->customize.bool_invis_text);*/


            }

            this->set_position(fvector2d{ 500.f, 65.f });
            this->add_widget(fvector2d(213.0f, 420.0f));
            {
                // HEADER/PIN
                this->set_position(fvector2d{ 500.f, 82.f });
                m_framework.get()->text("Other Color", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

                /*this->set_position(fvector2d{ 500.f, 95.f });
                this->colour_showcase("FOV Circle", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.fov, m_setting.get()->customize.bool_fov);

                this->set_position(fvector2d{ 500.f, 120.f });
                this->colour_showcase("Crosshair", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.crosshair, m_setting.get()->customize.bool_crosshair);

                this->set_position(fvector2d{ 500.f, 145.f });
                this->colour_showcase("Snapline", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.snapline, m_setting.get()->customize.bool_snapline);

                this->set_position(fvector2d{ 500.f, 170.f });
                this->colour_showcase("DBNO/Knocked", 100.f, 100.f, 256.0f, 256.0f, m_setting.get()->customize.dbno, m_setting.get()->customize.bool_dbno);*/
            }

        }

        });


    this->add_page(4, [&]() {

        this->begin_parent("Misc", fvector2d(0, 0), fvector2d(750, 500));
        {

            this->set_position(fvector2d{ 265.f, 65.f });
            this->add_widget(fvector2d(213.0f, 420.0f));
            {
                this->set_position(fvector2d{ 265.f, 82.f });
                m_framework.get()->text("Misc", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);

                this->set_position(fvector2d{ 265.f, 95.f });
                this->check_box("Debug Mode", &ud::u_debug);

                /*this->set_position(fvector2d{ 265.f, 120.f });
                this->check_box("Debug Mode", &m_setting.get()->misc.debug_mode);*/

                /*if (m_setting.get()->misc.debug_mode)
                {

                    this->set_position(fvector2d{ 265.f, 140.f });
                    m_framework.get()->text("To unlock debug mode please enter \nthe hotkey passcode ", current_offset().x + 9.0f, current_offset().y + 20.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);

                    this->set_position(fvector2d{ 270.f, 195.f });
                    m_framework.get()->text("Press Key:", current_offset().x + 5.0f, current_offset().y - 3.0f, m_framework.get()->get_color(255, 88, 88, 88), 15, false, true);
                    this->set_position(fvector2d{ 350.f, 195.f });
                    this->hotkey(&m_setting.get()->misc.debug_key);

                    this->set_position(fvector2d{ 270.f, 225.f });

                    if (m_setting.get()->misc.debug_key == 0x75)
                    {
                        m_framework.get()->text("Correct Pass", current_offset().x + 5.0f, current_offset().y - 3.0f, m_framework.get()->get_color(255, 60, 250, 2), 15, false, true);
                    }
                    else
                    {
                        m_framework.get()->text("Incorrect Pass", current_offset().x + 5.0f, current_offset().y - 3.0f, m_framework.get()->get_color(255, 252, 3, 3), 15, false, true);
                    }
                }*/

            }


            this->set_position(fvector2d{ 500.f, 65.f });
            this->add_widget(fvector2d(213.0f, 420.0f));
            {
                // HEADER/PIN
                this->set_position(fvector2d{ 500.f, 82.f });
                m_framework.get()->text("Config", current_offset().x + 9.0f, current_offset().y - 10.0f, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);
                m_framework.get()->line(current_offset().x, current_offset().y + 6.f, current_offset().x + 213.f, current_offset().y + 6.f, m_framework.get()->get_color(255, 46, 34, 51), 1.0f);


            }

        }

        });

    this->begin(ud::menu_pos, fvector2d(730, 500));
    {
        // nav bar

        auto sidebar_length = fvector2d(250.0f, 500.0f);

        m_framework.get()->filled_rect(position.x, position.y, sidebar_length.x, sidebar_length.y, this->color_menu_bar, true, 5, 5);

        flinearcolor border_color = m_framework.get()->get_color(255, 46, 34, 51);

        m_framework.get()->line(position.x + 250.0f, position.y + 55, position.x + 730.f, position.y + 55, border_color, 1.0f);
        m_framework.get()->line(position.x + sidebar_length.x, position.y, position.x + sidebar_length.x, position.y + sidebar_length.y, border_color, 1.0f);

        //m_framework.get()->icon(framework::icon_holder::m_logo_first, position.x + 13.0f, position.y + 9.0f, m_framework.get()->get_color(255, 239, 68, 68), 26.0f);
        //m_framework.get()->icon(framework::icon_holder::m_logo_second, position.x + 15.0f, position.y + 10.0f, m_framework.get()->get_color(255, 255, 255, 255), 23.0f);

        m_framework.get()->text("fortnite ", position.x + 24.0f, position.y + 11.0f, m_framework.get()->get_color(255, 255, 255, 255), 25, false, true);
        //m_framework.get()->text("private", position.x + 74.0f, position.y + 11.0f, m_framework.get()->get_color(255, 239, 158, 255), 25, false, true);

        m_framework.get()->text("private", position.x + 95.0f, position.y + 42.0f, m_framework.get()->get_color(255, 88, 88, 88), 16, false, true);


        m_framework.get()->line(position.x, position.y + 420, position.x + 250, position.y + 420, border_color, 1.0f);

        char computerName[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD s1ze = sizeof(computerName);

        m_framework.get()->circle(position.x + 45.f, position.y + 460.f, 30, border_color, true);
        m_framework.get()->text("User:", position.x + 80.f, position.y + 435.f, m_framework.get()->get_color(255, 88, 88, 88), 13, false, true);

        if (GetUserNameA(computerName, &s1ze)) {

            m_framework.get()->text(computerName, position.x + 115.f, position.y + 435.f, m_framework.get()->get_color(255, 163, 163, 163), 13, false, true);
        }

        m_framework.get()->text("Product:", position.x + 80.f, position.y + 455, m_framework.get()->get_color(255, 88, 88, 88), 13, false, true);
        m_framework.get()->text("Fortnite Private", position.x + 135.f, position.y + 455, flinearcolor(255, 239, 158, 255), 13, false, true);

        //uint32_t expiryDate = 0;
        //int result = 1;//GetLicenseExpiryDate(&expiryDate);
        //time_t currentTime = time(NULL);
        //if (expiryDate > currentTime) {
        //    int daysLeft = (expiryDate - currentTime) / 86400;
        //    std::string daysLeftStr = std::to_string(daysLeft);
        //    m_framework.get()->text("Days left:", position.x + 80.f, position.y + 475, m_framework.get()->get_color(255, 88, 88, 88), 9, false, true);
        //    m_framework.get()->text(daysLeftStr, position.x + 125.f, position.y + 475, flinearcolor(255, 239, 158, 255), 9, false, true);
        //}

        this->set_position(fvector2d{ 10.f, 40.0f });

        for (auto i = 0; i < m_tab.size(); i++) {
            if (m_tab[i].m_num == 0) {
                m_framework.get()->text("Main", position.x + 18.f, position.y + 70, m_framework.get()->get_color(255, 88, 88, 88), 10.0f, false, true);
                this->tab(NULL, m_tab[i].m_label, m_tab[i].m_num, fvector2d(62, 25));
            }
            if (m_tab[i].m_num == 1) {

                this->tab(NULL, m_tab[i].m_label, m_tab[i].m_num, fvector2d(62, 27));
            }
            if (m_tab[i].m_num == 2) {
                this->tab(NULL, m_tab[i].m_label, m_tab[i].m_num, fvector2d(62, 31));
            }
            if (m_tab[i].m_num == 3) {
                this->set_position(fvector2d{ 10.f, 150.0f });
                m_framework.get()->text("Misc", position.x + 18.f, position.y + 200.f, m_framework.get()->get_color(255, 88, 88, 88), 10.0f, false, true);
                this->tab(NULL, m_tab[i].m_label, m_tab[i].m_num, fvector2d(62, 36));
            }
            if (m_tab[i].m_num == 4) {
                this->tab(NULL, m_tab[i].m_label, m_tab[i].m_num, fvector2d(62, 31));
            }
        }

        this->render_page();



    }

}

auto m_interface::c_interface::add_page(
    int tab, std::function< void() > code) -> void {
    this->m_tab[tab].page = code;
}

auto m_interface::c_interface::render_page() -> void {
    if (this->m_tab[current_page].page == nullptr)
        return;

    this->m_tab[current_page].page();
}

auto m_interface::c_interface::set_position(
    fvector2d value) -> void {

    this->offset = value;
}

auto m_interface::c_interface::get_cursor() -> fvector2d {

    POINT CursorPoint = {};

    GetCursorPos(&CursorPoint);

    return fvector2d(double(CursorPoint.x), double(CursorPoint.y));
}

auto m_interface::c_interface::handler() -> void {
    static bool LeftMouseAlreadyDown = false;
    this->LeftMouseDown = GetAsyncKeyState(0x1);

    if (this->LeftMouseDown)
    {
        if (LeftMouseAlreadyDown)
        {
            this->LeftMouseClicked = false;
        }
        else
        {
            this->LeftMouseClicked = true;
        }

        LeftMouseAlreadyDown = true;
    }
    else
    {
        this->LeftMouseClicked = false;
        LeftMouseAlreadyDown = false;
    }
}

int m_interface::c_interface::handle_tab_click(int clickedTabIndex) {
    int current_page = clickedTabIndex;
    return current_page;
}


bool m_interface::c_interface::is_hovered(fvector2d Start, fvector2d Size) {

    auto cursor_pos = get_cursor();

    if (cursor_pos.x > Start.x && cursor_pos.y > Start.y)
    {
        if (cursor_pos.x < Start.x + Size.x && cursor_pos.y < Start.y + Size.y)
        {
            return true;
        }
    }

    return false;
}

int frame_rate() {

    static int iFps, iLastFps;
    static float flLastTickCount, flTickCount;

    flTickCount = clock() * 0.001f;
    iFps++;

    if ((flTickCount - flLastTickCount) >= 1.0f) {
        flLastTickCount = flTickCount;
        iLastFps = iFps;
        iFps = 0;
    }

    return iLastFps;
}


auto m_interface::c_interface::draw_frames() -> void {

    if (ud::show_targetting_enemy)
    {
        /*if ((GetAsyncKeyState(m_setting.get()->aim.aim_keycode) & 0x8000))
        {
            m_framework.get()->text("targeting", m_render.get()->m_width_2 - 35, m_render.get()->m_height_2 + 15, flinearcolor(255, 239, 158, 255), 18, false, false);
        }*/
    }


    if (ud::showwasd)
    {
        if (GetAsyncKeyState('W') & 0x8000) {
            m_framework.get()->filled_rect(100, 95, 50, 50, flinearcolor(200, 1, 1, 1), true, 3, 3); // W
        }
        else {
            m_framework.get()->filled_rect(100, 95, 50, 50, flinearcolor(100, 1, 1, 1), true, 3, 3); // W
        }
        if (GetAsyncKeyState('A') & 0x8000) {
            m_framework.get()->filled_rect(45, 150, 50, 50, flinearcolor(200, 1, 1, 1), true, 3, 3); // A
        }
        else {
            m_framework.get()->filled_rect(45, 150, 50, 50, flinearcolor(100, 1, 1, 1), true, 3, 3); // A
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            m_framework.get()->filled_rect(100, 150, 50, 50, flinearcolor(200, 1, 1, 1), true, 3, 3); // S
        }
        else {
            m_framework.get()->filled_rect(100, 150, 50, 50, flinearcolor(100, 1, 1, 1), true, 3, 3); // S
        }
        if (GetAsyncKeyState('D') & 0x8000) {
            m_framework.get()->filled_rect(155, 150, 50, 50, flinearcolor(200, 1, 1, 1), true, 3, 3); // D
        }
        else {
            m_framework.get()->filled_rect(155, 150, 50, 50, flinearcolor(100, 1, 1, 1), true, 3, 3); // D
        }

        m_framework.get()->rect(100, 95, 50, 50, flinearcolor(255, 239, 158, 255), 1.5); // W
        m_framework.get()->text("W", 117, 107, flinearcolor(255, 255, 255, 255), 18, false, false);

        m_framework.get()->rect(45, 150, 50, 50, flinearcolor(255, 239, 158, 255), 1.5); // A
        m_framework.get()->text("A", 62, 162, flinearcolor(255, 255, 255, 255), 18, false, false);

        m_framework.get()->rect(100, 150, 50, 50, flinearcolor(255, 239, 158, 255), 1.5); // S
        m_framework.get()->text("S", 120, 162, flinearcolor(255, 255, 255, 255), 18, false, false);

        m_framework.get()->rect(155, 150, 50, 50, flinearcolor(255, 239, 158, 255), 1.5); // D
        m_framework.get()->text("D", 172, 162, flinearcolor(255, 255, 255, 255), 18, false, false);
    }
    bool showshit = false;
    if (showshit)
    {
        std::string fps = "fps -> " + std::to_string(frame_rate());
        m_framework.get()->filled_rect(10, 10, 140, 50, flinearcolor(200, 1, 1, 1), false, 0, 0);
        m_framework.get()->text("Fortnite", 12, 12, this->color_menu_theme, 18, false, false);
        m_framework.get()->text("wtf", 42, 12, flinearcolor(255, 239, 158, 255), 18, false, false);
        m_framework.get()->text(fps, 12, 32, this->color_menu_theme, 18, false, false);
    }
    else
    {
        m_framework.get()->text("Fortnite", 10, 5, flinearcolor(255, 255, 255, 255), 18, false, false);
    }
}


void m_interface::c_interface::slider(std::string Title, float* Option, float Min, float Max) {

    auto Current = fvector2d(this->position.x + offset.x, this->position.y + offset.y);
    auto slider_size = fvector2d{ 170, 5 };
    auto padding = fvector2d{ 10, 15 };

    bool Hovered = this->is_hovered(fvector2d{ Current.x, Current.y + slider_size.y + padding.y - 34 }, fvector2d{ slider_size.x, slider_size.y + 30 });
    bool Pressed = Hovered && this->LeftMouseDown;

    if (Pressed) {
        auto cursorPos = get_cursor();
        *Option = ((cursorPos.x - Current.x) / (slider_size.x - 5.0f)) * (Max - Min) + Min;

        // Clamp the value to ensure it stays within the Min and Max range.
        if (*Option < Min) *Option = Min;
        if (*Option > Max) *Option = Max;
    }

    // Render the background of the slider based on hover state
    if (Hovered) {
        m_framework.get()->filled_rect(Current.x, Current.y + slider_size.y, slider_size.x - 5.0f, slider_size.y, m_framework.get()->get_color(255, 31, 30, 43), false, 0, 0);
        ud::hover_element = true;
    }
    else {
        m_framework.get()->filled_rect(Current.x, Current.y + slider_size.y, slider_size.x - 5.0f, slider_size.y, m_framework.get()->get_color(255, 23, 22, 31), false, 0, 0);
        //ud::hover_element = false;
    }

    // Render the text label for the slider
    auto text_position = fvector2d{ Current.x + 0.0f, Current.y - 20.0f };
    m_framework.get()->text(Title.c_str(), text_position.x, text_position.y, m_framework.get()->get_color(255, 163, 163, 163), 11, false, true);

    float calc = (*Option - Min) / (Max - Min) * (slider_size.x - 5.0f); // Subtract the width of the red box from the slider width.
    // Ensure that 'calc' does not exceed the graphical bounds of the slider
    float calc_max = slider_size.x - 5; // 5 is the offset to prevent overlap with the text
    if (calc > calc_max) calc = calc_max;

    // Render the fill for the slider
    m_framework.get()->filled_rect(Current.x, Current.y + slider_size.y, calc, slider_size.y, m_framework.get()->get_color(255, 239, 158, 255), false, 0, 0);

    // Render the draggable circle for the slider
    m_framework.get()->circle(Current.x + calc, Current.y + slider_size.y + 2.66f, 7.0f, m_framework.get()->get_color(255, 239, 158, 255), true, true);

    // Render the text for the slider's current value
    auto text_layout = std::format("{:.0f}", *Option);
    auto value_position = fvector2d{ Current.x + slider_size.x - 20.0f, Current.y - 3.0f };
    m_framework.get()->text(text_layout.c_str(), value_position.x, value_position.y, m_framework.get()->get_color(255, 163, 163, 163), 12, true, true);

    // Increment the y offset for the next UI element
    this->offset.y += slider_size.y + 10;
}


bool m_interface::c_interface::tab(int icon_id, std::string title, int tab_id, fvector2d size) {

    auto padding = fvector2d{ 25, 10 };
    auto Current = fvector2d(this->position.x + this->offset.x, this->position.y + this->offset.y);

    fvector2d bg_size = { 222.0f, 34.0f };

    fvector2d clickable_area_top_left = { Current.x - 12.0f, Current.y - 2.0f + size.y / 0.5f };

    auto is_hovered = this->is_hovered(clickable_area_top_left, bg_size);

    auto selected = current_page == tab_id;
    auto Clicked = is_hovered && this->LeftMouseClicked;

    auto text_pos = fvector2d{ Current.x + size.x / 4.0f, Current.y + size.y / 0.6f };

    flinearcolor Textcolor;
    flinearcolor Bgcolor;

    if (selected)
    {
        Textcolor = m_framework.get()->get_color(255, 250, 250, 250);
        Bgcolor = m_framework.get()->get_color(20, 239, 158, 255);
    }

    else if (is_hovered)
    {
        if (Clicked) {

            ud::page = tab_id;
        }

        Textcolor = m_framework.get()->get_color(255, 250, 250, 250);
        Bgcolor = m_framework.get()->get_color(5, 239, 158, 255);
        ud::hover_element = true;
    }
    else {
        Textcolor = m_framework.get()->get_color(255, 163, 163, 163);
        Bgcolor = m_framework.get()->get_color(0, 0, 0, 0);
        //ud::hover_element = false;
    }

    //text
    m_framework.get()->filled_rect(text_pos.x - 12.0f, text_pos.y - 2.0f, 222.0f, 34.0f, Bgcolor, true, 5, 5);
    m_framework.get()->text(title.c_str(), text_pos.x + 19.0f, text_pos.y + 5.0f, Textcolor, 14, false, true);
    /*m_framework.get()->icon(icon_id, text_pos.x - 4.0f, text_pos.y + 7.0f, m_framework.get()->get_color(255, 239, 68, 68), 14.0f);*/

    this->offset.y += size.y + padding.y;

    return true;
}

bool m_interface::c_interface::button(std::string Title, fvector2d size) {

    const auto Current = fvector2d(this->position.x + this->offset.x, this->position.y + this->offset.y);

    bool is_hovered = this->is_hovered(Current, size);
    bool Clicked = is_hovered && this->LeftMouseClicked;

    flinearcolor color = is_hovered ? m_framework.get()->get_color(255, 100, 100, 100) : m_framework.get()->get_color(255, 88, 88, 88);

    if (is_hovered)
    {
        //ud::hover_element = true;
    }
    else
    {
        //ud::hover_element = false;
    }

    //m_framework.get( )->filled_rect( Current.x, Current.y, size.x, size.y, color, false, 0, 0 );

    //Outline
    m_framework.get()->rect(Current.x, Current.y, size.x, size.y, color, 1);

    //Text
    auto text_pos = fvector2d{ Current.x + size.x / 2, Current.y + size.y / 1.25 };
    m_framework.get()->text(Title.c_str(), text_pos.x, text_pos.y, m_framework.get()->get_color(255, 205, 204, 206), 12, true, true);

    this->offset.y += size.y + this->ItemSpacing;
    //this->offset.x += size.x + 15;

    return Clicked;
}

void m_interface::c_interface::check_box(std::string Title, bool* Option) {

    auto padding = fvector2d{ 10, 10 };
    auto Current = fvector2d(this->position.x + padding.x + offset.x, this->position.y + padding.y + offset.y);
    auto size = fvector2d(20, 20);

    bool is_hovered = this->is_hovered(Current, size);
    bool Clicked = is_hovered && this->LeftMouseClicked;

    //Background
    if (is_hovered) {
        /*m_framework.get()->rect(Current.x, Current.y, size.x, size.y, m_framework.get()->get_color(255, 88, 88, 88),  1);*/
        m_framework.get()->filled_rect(Current.x, Current.y, size.x, size.y, this->color_checkbox_hovered, true, 4, 4);
    }
    else {
        /*	m_framework.get()->rect(Current.x, Current.y, size.x, size.y, m_framework.get()->get_color(255, 88, 88, 88), 1);*/
        m_framework.get()->filled_rect(Current.x, Current.y, size.x, size.y, this->color_checkbox_bg, true, 4, 4);
    }

    // checkbox
    if (*Option)
    {
        m_framework.get()->filled_rect(Current.x + 3, Current.y + 3, size.x - 6, size.y - 6, this->color_checkbox_active, true, 3, 3);
    }

    auto text_position = fvector2d{ Current.x + size.x + 7.0f, Current.y + size.y - 19 };

    m_framework.get()->text(Title.c_str(), text_position.x, text_position.y, m_framework.get()->get_color(255, 163, 163, 163), 12, false, true);

    if (is_hovered && Clicked)
    {
        *Option = !*Option;
    }

    this->offset.y += size.y + 2 + this->ItemSpacing;
}

POINT cursorr;
POINT cursor_corrected;
bool dropdown_acitve = false;

void m_interface::c_interface::dropdown(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, const std::string label, std::vector<std::string>& items, std::int32_t& selected_item) {
    //m_framework.get()->text(label, x, y - 16, m_framework.get()->get_color(255, 255, 255, 255), 14, true, false);

    h = static_cast<std::int32_t>(h * 0.7);

    m_framework.get()->filled_rect(x, y, w, h, color_checkbox_bg, false, 5.0f, 5.0f);
    m_framework.get()->rect(x, y, w, h, m_framework.get()->get_color(150, 23, 21, 30), 1.0);

    m_framework.get()->text(items[selected_item], x + 5, y + h / 2 - 8, m_framework.get()->get_color(255, 239, 158, 255), 13, false, false);

    GetCursorPos(&cursorr);
    if ((cursorr.x > x) && (cursorr.x < x + w) && (cursorr.y > y) && (cursorr.y < y + h) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        dropdown_acitve = !dropdown_acitve;
        Sleep(100);
    }

    if (dropdown_acitve) {
        for (std::size_t i = 0; i < items.size(); ++i) {
            if ((cursorr.x > x) && (cursorr.x < x + w) && (cursorr.y > y + (i + 1) * h) && (cursorr.y < y + (i + 2) * h) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                selected_item = i;
                dropdown_acitve = false;
                Sleep(100);
            }

            m_framework.get()->filled_rect(x, y + (i + 1) * h, w, h, m_framework.get()->get_color(255, 239, 158, 255), false, 0.0f, 0.0f);
            m_framework.get()->text(items[i], x + 5, y + (i + 1) * h + h / 2 - 8, m_framework.get()->get_color(255, 255, 255, 255), 13, false, false);
        }
    }
}

POINT cursorrcfg;
POINT cursor_correctedcfg;
bool dropdown_acitvecfg = false;

void m_interface::c_interface::dropdowncfg(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, const std::string label, std::vector<std::string>& items, std::int32_t& selected_item) {
    //m_framework.get()->text(label, x, y - 16, m_framework.get()->get_color(255, 255, 255, 255), 14, true, false);

    h = static_cast<std::int32_t>(h * 0.7);

    m_framework.get()->filled_rect(x, y, w, h, color_checkbox_bg, false, 5.0f, 5.0f);
    m_framework.get()->rect(x, y, w, h, m_framework.get()->get_color(150, 23, 21, 30), 1.0);

    m_framework.get()->text(items[selected_item], x + 5, y + h / 2 - 8, m_framework.get()->get_color(255, 239, 158, 255), 13, false, false);

    GetCursorPos(&cursorrcfg);
    if ((cursorrcfg.x > x) && (cursorrcfg.x < x + w) && (cursorrcfg.y > y) && (cursorrcfg.y < y + h) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        dropdown_acitvecfg = !dropdown_acitvecfg;
        Sleep(100);
    }

    if (dropdown_acitvecfg) {
        for (std::size_t i = 0; i < items.size(); ++i) {
            if ((cursorrcfg.x > x) && (cursorrcfg.x < x + w) && (cursorrcfg.y > y + (i + 1) * h) && (cursorrcfg.y < y + (i + 2) * h) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                selected_item = i;
                dropdown_acitvecfg = false;
                Sleep(100);
            }

            m_framework.get()->filled_rect(x, y + (i + 1) * h, w, h, m_framework.get()->get_color(255, 239, 158, 255), false, 0.0f, 0.0f);
            m_framework.get()->text(items[i], x + 5, y + (i + 1) * h + h / 2 - 8, m_framework.get()->get_color(255, 255, 255, 255), 13, false, false);
        }
    }
}

POINT cursorrextra;
POINT cursor_correctedextra;
bool dropdown_acitveextra = false;

void m_interface::c_interface::dropdownextra(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, const std::string label, std::vector<std::string>& items, std::int32_t& selected_item) {
    //m_framework.get()->text(label, x, y - 16, m_framework.get()->get_color(255, 255, 255, 255), 14, true, false);

    h = static_cast<std::int32_t>(h * 0.7);

    m_framework.get()->filled_rect(x, y, w, h, color_checkbox_bg, false, 5.0f, 5.0f);
    m_framework.get()->rect(x, y, w, h, m_framework.get()->get_color(150, 23, 21, 30), 1.0);

    m_framework.get()->text(items[selected_item], x + 5, y + h / 2 - 8, m_framework.get()->get_color(255, 239, 158, 255), 13, false, false);

    GetCursorPos(&cursorrextra);
    if ((cursorrextra.x > x) && (cursorrextra.x < x + w) && (cursorrextra.y > y) && (cursorrextra.y < y + h) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        dropdown_acitveextra = !dropdown_acitveextra;
        Sleep(100);
    }

    if (dropdown_acitveextra) {
        for (std::size_t i = 0; i < items.size(); ++i) {
            if ((cursorrextra.x > x) && (cursorrextra.x < x + w) && (cursorrextra.y > y + (i + 1) * h) && (cursorrextra.y < y + (i + 2) * h) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                selected_item = i;
                dropdown_acitveextra = false;
                Sleep(100);
            }

            m_framework.get()->filled_rect(x, y + (i + 1) * h, w, h, m_framework.get()->get_color(255, 239, 158, 255), false, 0.0f, 0.0f);
            m_framework.get()->text(items[i], x + 5, y + (i + 1) * h + h / 2 - 8, m_framework.get()->get_color(255, 255, 255, 255), 13, false, false);
        }
    }
}

// Global variables to store mouse position and left mouse button state
POINT mouse_position;
bool LeftMouseDown = false;

// Function to update mouse position
void update_mouse_position() {
    GetCursorPos(&mouse_position);
}

bool is_point_inside_circle(float point_x, float point_y, float circle_x, float circle_y, float radius) {
    float distance_squared = (point_x - circle_x) * (point_x - circle_x) + (point_y - circle_y) * (point_y - circle_y);
    return distance_squared <= radius * radius;
}

void m_interface::c_interface::draw_circle(float x, float y, float radius) {
    m_framework.get()->circle(x, y, radius, flinearcolor(255, 255, 255, 255), 0.0f, true);
}

void m_interface::c_interface::colour_showcase(std::string Title, std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, flinearcolor& selected_color, bool& enabler) {
    auto padding = fvector2d{ 10, 10 };
    auto Current = fvector2d(this->position.x + padding.x + offset.x, this->position.y + padding.y + offset.y);
    auto size = fvector2d(20, 20);

    bool is_hovered = (mouse_position.x >= Current.x && mouse_position.x <= Current.x + size.x &&
        mouse_position.y >= Current.y && mouse_position.y <= Current.y + size.y);

    bool clicked = (is_hovered && LeftMouseDown);

    if (clicked) {
        if (active_showcase != nullptr && active_showcase != this) {
            // Close other active color pickers
            active_showcase->enabler = false;
        }
        // Toggle the state of this color picker
        enabler = !enabler;
        active_showcase = this;
        Sleep(100); // Introduce a slight delay to prevent multiple rapid clicks
    }

    m_framework.get()->filled_rect(Current.x, Current.y, size.x, size.y, selected_color, true, 4, 4);

    auto text_position = fvector2d{ Current.x + size.x + 7.0f, Current.y + size.y - 19 };
    m_framework.get()->text(Title.c_str(), text_position.x, text_position.y, m_framework.get()->get_color(255, 163, 163, 163), 12, false, true);

    update_mouse_position();

    if (enabler) {
        // Draw the background
        m_framework.get()->filled_rect(x - 23, y - 30, w + 50, h + 50, flinearcolor(255, 18, 9, 15), false, 1, 1);

        // Draw the header
        m_framework.get()->text("Color Picker", x - 17, y - 25, m_framework.get()->get_color(255, 88, 88, 88), 10, false, true);

        // Draw the color picker rectangle with a black background
        m_framework.get()->filled_rect(x, y, w, h, flinearcolor(255, 0, 0, 0), false, 2, 2);

        // Define the step size for sampling colors
        int step_size_x = 7; // You can adjust this value to change the density of sampled colors
        int step_size_y = 7; // You can adjust this value to change the density of sampled colors

        for (int i = 0; i < w; i += step_size_x) {
            for (int j = 0; j < h; j += step_size_y) {
                // Calculate the color for this sampled pixel
                uint8_t r = static_cast<uint8_t>((static_cast<float>(i) / static_cast<float>(w)) * 255);
                uint8_t g = static_cast<uint8_t>((static_cast<float>(j) / static_cast<float>(h)) * 255);
                uint8_t b = static_cast<uint8_t>((static_cast<float>(w - i) / static_cast<float>(w)) * 255); // Blue inversely proportional to red

                // Draw the sampled pixel
                m_framework.get()->filled_rect(x + i, y + j, step_size_x, step_size_y, flinearcolor(255, r, g, b), false, 2, 2);
            }
        }

        // Calculate circle position based on selected color
        float circle_x = x + (selected_color.r / 255.0f) * w;
        float circle_y = y + (selected_color.g / 255.0f) * h;
        float circle_radius = 5.0f; // Adjust the radius as needed

        // Check if the mouse is hovered over the color picker
        bool is_hovered = (mouse_position.x >= x && mouse_position.x <= x + w && mouse_position.y >= y && mouse_position.y <= y + h);

        // Check if the left mouse button is pressed and the mouse is hovered over the color picker
        if (is_hovered && LeftMouseDown) {
            // Update the selected color based on the mouse position
            selected_color.r = static_cast<float>(mouse_position.x - x) / static_cast<float>(w) * 255;
            selected_color.g = static_cast<float>(mouse_position.y - y) / static_cast<float>(h) * 255;
            selected_color.b = static_cast<float>((w - (mouse_position.x - x)) / static_cast<float>(w)) * 255; // Adjust blue component based on mouse position
        }

        // Check if the mouse is hovered over the circle
        bool circle_hovered = is_point_inside_circle(mouse_position.x, mouse_position.y, circle_x, circle_y, circle_radius);

        // Check if the left mouse button is pressed and the circle is clicked
        if (circle_hovered && LeftMouseDown) {
            // Update the circle position based on mouse movement
            circle_x = mouse_position.x;
            circle_y = mouse_position.y;
        }

        // Draw draggable circle at the updated selected color position
        draw_circle(circle_x, circle_y, circle_radius);
    }

    this->offset.y += size.y + 2 + this->ItemSpacing;
}
auto m_interface::c_interface::begin_parent(
    const std::string& title,
    fvector2d start,
    fvector2d size) -> void
{
    // 400, 450

    ////m_render.get( )->filled_rect( position.x + 50, position.y + 85, size.x - 100, size.y - 120, m_render.get( )->get_color( 255, 16, 14, 24 ), true, 5, 5 );
    //m_framework.get( )->filled_rect( position.x + 48, position.y + 85, size.x, size.y, m_framework.get( )->get_color( 255, 16, 14, 24 ), true, 5, 5 );

    ////m_render.get( )->line( position.x + 50, position.y + 130, position.x + size.x, position.y + 130, m_render.get( )->get_color( 255, 23, 21, 30 ) );
    //m_framework.get( )->line( position.x + 50, position.y + 130, position.x + size.x * 1.16, position.y + 130, m_framework.get( )->get_color( 255, 23, 21, 30 ) );

    ////m_render.get( )->text( "Aimbot", position.x + size.x / 6, position.y + 100, m_render.get( )->get_color( 255, 210, 209, 210 ), 14, false, true );
    //m_framework.get( )->text( title.c_str( ), position.x + size.x / 4.5, position.y + 100, m_framework.get( )->get_color( 255, 210, 209, 210 ), 14, false, true );

}

void m_interface::c_interface::begin(fvector2d start, fvector2d size) {

    if (!this->initialized) {

        this->position = start;
        this->ItemSpacing = 6;
        this->size = size;

        this->initialized = true;
    }

    this->handler();

    auto is_hovered = this->is_hovered(this->position, this->size);

    //Drag that nigger icg didnt bother making the fat nigger
    if (ud::hover_element && GetAsyncKeyState_Spoofed(0x1))
    {

    }
    else if ((is_hovered || drag_position.x != 0) && !ud::hover_element)
    {


        if (this->LeftMouseDown)
        {

            auto cursorPosORIG = get_cursor();
            fvector2d changeInPos = { 0, 0 };
            fvector2d menuPosBuff = { 0, 0 };
            fvector2d currentPosMenu = ud::menu_pos;

            auto cursorPosNEW = get_cursor();
            changeInPos.x = cursorPosORIG.x - cursorPosNEW.x;
            changeInPos.y = cursorPosORIG.y - cursorPosNEW.y;

            menuPosBuff = { changeInPos.x, changeInPos.y };

            ud::menu_pos = { currentPosMenu.x - (changeInPos.x * 50) , (currentPosMenu.y - changeInPos.y * 50) };
        }
        else
        {
            drag_position = fvector2d{ 0, 0 };
        }
    }
    ud::hover_element = false;
    this->offset = fvector2d(0, 0);

    /*m_framework.get()->rect(position.x, position.y, size.x, size.y, m_framework.get()->get_color(255, 88, 87, 86), 1);*/

    m_framework.get()->filled_rect(
        position.x,
        position.y,
        size.x,
        size.y,
        this->color_menu_bg,
        true,
        5,
        5
    );


}

namespace n_render {
    class c_render {
    public:


        auto draw() -> void {

            u_main->actor_loop();
            u_main->LevelDrawing();

            //menu();

        }

        auto render() -> bool {
            SPOOF_FUNC

                auto ipc = m_ipc.get()->initialize(
                    "perception_ipc"
                );

            if (!ipc) {
                std::printf(" [ipc] -> initialization failed.\n");
            }

            while (true) {

                m_framework.get()->begin_scene();
                {
                    //m_framework->filled_rect(0, 0, screen_width, screen_height, flinearcolor(200, 0, 0, 0), false, 0, 0);

                    m_framework->text(
                        "private fortnite 29 V2",
                        134,
                        25,
                        m_framework->get_color(255, 255, 255, 255),
                        16,
                        true,
                        true
                    );
                    
                    draw();
                    if (GetAsyncKeyState_Spoofed(VK_INSERT) & 1)
                    {
                        ud::renderframeworkmenu = !ud::renderframeworkmenu;
                    }

                    if (GetAsyncKeyState_Spoofed(VK_F3) & 1)
                    {
                        ud::fly = !ud::fly;
                    }

                    if (ud::renderframeworkmenu)
                    {
                        m_interface::c_interface nigga;
                        nigga.draw_interface(); 
                    }

                    if (ud::u_render_fov)
                    {
                        m_framework->circle(screen_width / 2, screen_height / 2, ud::u_aimfov, flinearcolor(ud::fov_color.a, ud::fov_color.r, ud::fov_color.g, ud::fov_color.b), 1.5f, false);
                        m_framework->circle(screen_width / 2, screen_height / 2, ud::u_aimfov + 1, flinearcolor(255, 0, 0, 0), 0.7f, false);
                        m_framework->circle(screen_width / 2, screen_height / 2, ud::u_aimfov - 1, flinearcolor(255, 0, 0, 0), 0.7f, false);

                        if (ud::u_render_fov_filled)
                        {
                            m_framework->circle(screen_width / 2, screen_height / 2, ud::u_aimfov, flinearcolor(ud::fov_color.a * (ud::filled_fov_opacity / 100), ud::fov_color.r, ud::fov_color.g, ud::fov_color.b), 1.5f, true);
                        }
                    }

                    if (ud::u_enable_crosshair) {
                        float halfSize = static_cast<float>(ud::crosshair_size) / 2.0f;

                        // black outline
                        m_framework->line(screen_width / 2 - halfSize, screen_height / 2, screen_width / 2 - halfSize - 7, screen_height / 2, flinearcolor(0, 0, 0, 255), 2);
                        m_framework->line(screen_width / 2 + halfSize, screen_height / 2, screen_width / 2 + halfSize + 7, screen_height / 2, flinearcolor(0, 0, 0, 255), 2);
                        m_framework->line(screen_width / 2, screen_height / 2 - halfSize, screen_width / 2, screen_height / 2 - halfSize - 7, flinearcolor(0, 0, 0, 255), 2);
                        m_framework->line(screen_width / 2, screen_height / 2 + halfSize, screen_width / 2, screen_height / 2 + halfSize + 7, flinearcolor(0, 0, 0, 255), 2);

                        // white inner lines
                        flinearcolor innerColorWhite(255, 255, 255, 128);
                        m_framework->line(screen_width / 2 - halfSize - 1, screen_height / 2, screen_width / 2 - halfSize - 6, screen_height / 2, innerColorWhite, 1);
                        m_framework->line(screen_width / 2 + halfSize + 1, screen_height / 2, screen_width / 2 + halfSize + 6, screen_height / 2, innerColorWhite, 1);
                        m_framework->line(screen_width / 2, screen_height / 2 - halfSize - 1, screen_width / 2, screen_height / 2 - halfSize - 6, innerColorWhite, 1);
                        m_framework->line(screen_width / 2, screen_height / 2 + halfSize + 1, screen_width / 2, screen_height / 2 + halfSize + 6, innerColorWhite, 1);
                    }

                    if (ud::draw_aim_mode)
                    {
                        if (ud::u_aimbot && ud::u_prediction)
                        {
                            m_framework->text(
                                "prediction aim active",
                                15,
                                35,
                                m_framework->get_color(255, 205, 150, 255),
                                16,
                                false
                            );
                        }
                        else if (ud::u_aimbot && !ud::u_prediction)
                        {
                            m_framework->text(
                                "normal aim active",
                                15,
                                35,
                                m_framework->get_color(255, 205, 150, 255),
                                16,
                                false
                            );
                        }
                    }

                }
                m_framework.get()->end_scene();


            }
            return true;
        }

    };
} static n_render::c_render* render = new n_render::c_render();