#ifndef INCLUDE_TRACER_CORE_UTIL_GL_H_
#define INCLUDE_TRACER_CORE_UTIL_GL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// freeglut (openGL) core utilities for the whole library.
// In general, this utilities define the basic shapes drawing with some
// data visualization (e.g. rectangles, circles, arrows, ...).

#include "tracer/core/util/color.h"

namespace tracer {
namespace core {
namespace util {
namespace gl {

// Draw a rectangle with the specified x, w, width, height and the data to be
// visualized, and with optional background color, text color and padding.
// This is a useful utility to be used in many tracers (e.g. array, matrix, ...)
//
// Examples:
//    DrawRectangle(0, 0, 100, 100, 11, Color(255, 0, 0));
//    DrawRectangle(0, 0, 100, 100, 22, Color(255, 0, 0), Color(0, 0, 0));
//    DrawRectangle(0, 0, 100, 100, 33, Color(255, 0, 0), Color(0, 0, 0), 5);
template<typename T>
void DrawRectangle(int x,
                   int y,
                   int width,
                   int height,
                   const T& data,
                   const Color& background_color = Color("#464646"),
                   const Color& font_color = Color("#FFFFFF"),
                   int padding = 2);

}  // namespace gl
}  // namespace util
}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/util/gl_impl.h"

#endif  // INCLUDE_TRACER_CORE_UTIL_GL_H_
