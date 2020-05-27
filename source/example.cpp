#define _USE_MATH_DEFINES
#include "window.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  Color       green{ 0.6, 0.9, 0.6 };
  Color       blue{ 0.6, 0.9, 1.0 };
  Color       turquis{ 0.1, 0.8, 0.7 };
  Circle      cir_1{ {400, 400}, 300, blue };
  Circle      cir_2{ {400, 400}, 6, blue };
  Circle      cir_3{ {400, 400}, 280, turquis };
  Rectangle   left{ {120, 380},{100, 400}, turquis };
  Rectangle   right{ {580, 380},{620, 400}, turquis };
  Rectangle   top{ {412, 120},{375, 100}, turquis };
  Rectangle   bottom{ {412, 580},{375, 630}, turquis };

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    int   second = int(t) % 60;
    int   minute = t / 60;
    int   hour = t / 3600;
    float segments = (2 * M_PI) / 60; // for analog clock

    std::string time_to_string = "time: " + std::to_string(hour)
        + "h "
        + std::to_string(minute)
        + "min "
        + std::to_string(second)
        + "sec";

    // display time since the start 
    win.draw_text(10, 760, 30, time_to_string);

    // second 
    win.draw_line(400, 400, 180 * std::cos(segments * (second - 15)) + 400,
        180 * std::sin(segments * (second - 15)) + 400, 1.0, 0.5, 0, 1.5);
    // minute 
    win.draw_line(400, 400, 160 * std::cos(segments * (minute - 15)) + 400,
        160 * std::sin(segments * (minute - 15)) + 400, 0.6, 0.5, 1.0, 2.8);
    // hour              
    win.draw_line(400, 400, 110 * std::cos(segments * 5 * (hour - 15)) + 400,
        110 * std::sin(segments * 5 * (hour - 15)) + 400, 0.3, 1.0, 0.3, 5.0);


    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}
