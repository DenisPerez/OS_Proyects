#include <FL/Fl_Roller.H>

#include "gui.hpp"

int main(int argc, char** argv)
{
  Fl_Window * window = new Fl_Window(20, 40, opengl::iWidthWindow, opengl::iHeightWindow, opengl::sWindowTitle.c_str());
  new GlGui(window, 0, 0, opengl::iWidthWindow, opengl::iHeightWindow, opengl::sWindowTitle.c_str());
  window->end();
  window->show(argc, argv);
  window->make_current();

  return Fl::run();
}
