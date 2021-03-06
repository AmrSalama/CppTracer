#ifndef INCLUDE_TRACER_CORE_TRACER_H_
#define INCLUDE_TRACER_CORE_TRACER_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// The base abstract tracer class, defines the core functionality of the tracer.
// Handles freeglut windows initialization, and flushes outputs to screen.

#include <string>
#include "tracer/core/theme.h"

namespace tracer {
namespace core {

class Tracer {
 public:
  Tracer(int argc,                  // [argc, argv] are required
         char** argv,               // by freeglut libarary (glutInit).
         float window_width,
         float window_height,
         float speed,
         const std::string& window_title,
         const core::Theme& theme = LIGHT_THEME);
  ~Tracer();

  // Update tracer data, and visualize all changes happened.
  //
  // Examples:
  //    update();
  //    update(0.5);
  inline void update();
  virtual void update(float speed) = 0;

  // Notify element with the specified index,
  // which means to flash the element with a different color then
  // flash again to its previous color.
  // We can select range of indices.
  //
  // Examples:
  //    notify(0);          notify index 0 with the defulat speed
  //    notify(0, 0.5);     notify index 0 for 0.5 second
  //    notify(0, 5);       notify range from 0 to 5 with default speed
  //    notify(0, 5, 0.5);  notify range from 0 to 5 for 0.5 second
  inline void notify(int index);
  inline void notify(int index, double speed);
  virtual void notify(int index, float speed) = 0;

  // Select element with the specified index,
  // which means to mark the element with a different color.
  // We can select range of indices.
  //
  // Examples:
  //    select(0);          select index 0 with the defulat speed
  //    select(0, 0.5);     select index 0 for 0.5 second
  //    select(0, 5);       select range from 0 to 5 with default speed
  //    select(0, 5, 0.5);  select range from 0 to 5 for 0.5 second
  inline void select(int index);
  inline void select(int index, double speed);
  virtual void select(int index, float speed) = 0;

  // Deselect the element with the specified index,
  // which means to mark the element with its previous color.
  // We can deselect range of indices.
  //
  // This is the opposite method to select,
  // so whenever you select an element you may want to deselect it agian.
  //
  // Examples:
  //    deselect(0);          dselect index 0 with the defulat speed
  //    deselect(0, 0.5);     dselect index 0 for 0.5 second
  //    deselect(0, 5);       dselect range from 0 to 5 with default speed
  //    deselect(0, 5, 0.5);  dselect range from 0 to 5 for 0.5 second
  inline void deselect(int index);
  inline void deselect(int index, double speed);
  virtual void deselect(int index, float speed) = 0;

 protected:
  float window_width_;
  float window_height_;
  float speed_;
  core::Theme theme_;

  // This method is the alternative to glutMainLoop().
  // FLush the screen with a new iteration of render and delay
  // the screen for the specified amount of time (speed).
  // used in every display method (e.g. notify, select, ...).
  //
  // If no speed specified or has negative value, the flush method will use
  // the default speed specified in tracer constructor.
  //
  // Index is the index of the element to be rendered,
  // negative value means render all the tracer data.
  //
  // Examples:
  //    flush();
  //    flush(0.5);
  //    flush(0.5, 1);
  void flush(float speed = -1, int index = -1);

  // Abstract render method, each subclass has to implement its own
  // render method (e.g. array, matrix, graph, ...).
  // You can pass the index of the element to be rendered.
  //
  // This is helping in optimize the number of render operations,
  // just imagine that you want to visualize 1000 elements of an array,
  // then you have to draw them each time, but fortunately we can rerender
  // the changed element only which has this index.
  virtual void render() = 0;
  virtual void render(int index) = 0;

 private:
  const float kWindowMargin;        // Margin between tracers window.
  static int window_count_;         // The number of created tracers.
  static float window_x_position_;  // The x-position of the next tracer.
  static float window_y_position_;  // The y-position of the next tracer.
  int window_id_;                   // Window identifier.
};

}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/tracer_impl.h"

#endif  // INCLUDE_TRACER_CORE_TRACER_H_
