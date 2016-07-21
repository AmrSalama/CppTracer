#ifndef INCLUDE_TRACER_UTILITY_GL_H_
#define INCLUDE_TRACER_UTILITY_GL_H_

#include <string>
#include "GL/gl.h"
#include "GL/freeglut.h"
#include "tracer/color.h"
#include "tracer/utility/general.h"

namespace tracer {
namespace utility {
namespace gl {

  // Draw a rectangle with a specific x, w, width, height and the data to be
  // visualized, and with optional background color, text color and padding.
  // This is a useful utility to be used in many tracers (e.g. 1d array, ...).
  template<typename T>
  void draw_rect(const float &x,
                 const float &y,
                 const float &width,
                 const float &height,
                 const T &data,
                 const Color &background_color = Color(70, 70, 70),
                 const Color &font_color = Color(255, 255, 255),
                 const int &padding = 2) {
      // Draw the rectangle.
      glColor4f(background_color.r,
                background_color.g,
                background_color.b,
                background_color.a);
      glBegin(GL_POLYGON);
          glVertex2f(x + padding,         y + padding);           // lower left
          glVertex2f(x + padding,         y + height - padding);  // upper left
          glVertex2f(x + width - padding, y + height - padding);  // upper right
          glVertex2f(x + width - padding, y + padding);           // lower right
      glEnd();

      // Draw the data.
      // The used font is GLUT_BITMAP_9_BY_15,
      // in which each character takes 9x15.
      glColor4f(font_color.r,
                font_color.g,
                font_color.b,
                font_color.a);
      std::string text = utility::general::stringify(data);
      glRasterPos2f(x + (width / 2.0) - ((9 * text.size()) / 2.0),  // Center
                    y + (height/2.0) - (15 / 2.0));                 // Middle
      for (int i = 0; i < text.size(); i++) {
          glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
      }
  }

}  // namespace gl
}  // namespace utility
}  // namespace tracer

#endif  // INCLUDE_TRACER_UTILITY_GL_H_
