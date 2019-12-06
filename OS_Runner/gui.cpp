#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

#include <FL/Enumerations.H>

#include "gui.hpp"

static void redraw_callback(void * arg) {
  GlGui * window = static_cast<GlGui *>(arg);
  Fl::focus(window);
  window->redraw();
}

GlGui::GlGui(Fl_Window * parent, int x, int y, int w, int h, const char * l) : Fl_Gl_Window(x, y, w, h, l) {
  this->parent = parent;
  title += l;
  initialized = false;
  Fl::add_idle(redraw_callback, this);

  game_data = alloc_game_data();
  if (game_data == NULL) {
    std::cerr << "Failed to allocate memory for the game map." << std::endl;
    exit(EXIT_FAILURE);
  } else
    init_game_data(game_data);
}

void GlGui::draw() {
  if (!initialized) {
    opengl::initialize(game_data);
    initialized = true;
  }

  opengl::display(game_data);
}

int GlGui::handle(int event) {
  switch(event) {
  case FL_FOCUS:
    return 1;
  case FL_KEYBOARD:
    switch(Fl::event_key()) {
    case 'w':
    case FL_Up:
      if (can_move(game_data, game_data->characters[0].x - 1, game_data->characters[0].y))
        game_data->characters[0].x -= 1;
      return 1;
      break;
    case 'a':
    case FL_Left:
      if (can_move(game_data, game_data->characters[0].x, game_data->characters[0].y - 1))
        game_data->characters[0].y -= 1;
      return 1;
      break;
    case 's':
    case FL_Down:
      if (can_move(game_data, game_data->characters[0].x + 1, game_data->characters[0].y))
        game_data->characters[0].x += 1;
      return 1;
      break;
    case 'd':
    case FL_Right:
      if (can_move(game_data, game_data->characters[0].x, game_data->characters[0].y + 1))
        game_data->characters[0].y += 1;
      return 1;
      break;
    }
    break;
  }

  return Fl_Gl_Window::handle(event);
}
