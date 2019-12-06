#pragma once

#ifndef OGL_HPP
#define OGL_HPP

#include <string>

#include "data.h"

namespace opengl
{
  //globals
  extern const std::string sWindowTitle; //name of the window
  extern unsigned int iWidthWindow;
  extern unsigned int iHeightWindow;     //width & height of the viewport

  ///
  /// Function to initialize OGL
  ///
  void initialize(const data_t * data);

  ///
  /// The OGL display function
  ///
  void display(const data_t * data);

  ///
  /// The window resize function
  ///
  void reshape(int w, int h);
}

#endif
