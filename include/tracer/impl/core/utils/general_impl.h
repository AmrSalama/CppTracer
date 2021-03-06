#ifndef INCLUDE_TRACER_IMPL_CORE_UTILS_GENERAL_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_UTILS_GENERAL_IMPL_H_

// Copyright © 2017.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of general.h utility header file.

#include "tracer/core/utils/general.h"
#include <string>
#include <sstream>                  // ostringstream
#include <iomanip>                  // setprecision
#include <limits>                   // numeric_limits
#include "tracer/core/config.h"     // defines OS_WINDOWS, etc.

#ifdef OS_WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace tracer {
namespace core {
namespace utils {
namespace general {

// Stringify
template<typename T> std::string Stringify(const T& data) {
  std::ostringstream string_stream;
  string_stream << data;
  return string_stream.str();
}

template<> std::string Stringify<bool>(const bool& data) {
  std::ostringstream string_stream;
  string_stream << std::boolalpha << data;
  return string_stream.str();
}

template<> std::string Stringify<double>(const double& data) {
  const int sigdigits = std::numeric_limits<double>::digits10;
  std::ostringstream string_stream;
  string_stream << std::setprecision(sigdigits) << data;
  return string_stream.str();
}

template<> std::string Stringify<float>(const float& data) {
  const int sigdigits = std::numeric_limits<float>::digits10;
  std::ostringstream string_stream;
  string_stream << std::setprecision(sigdigits) << data;
  return string_stream.str();
}

template<> std::string Stringify<long double>(const long double& data) {  // NOLINT
  const int sigdigits = std::numeric_limits<long double>::digits10;
  std::ostringstream string_stream;
  string_stream << std::setprecision(sigdigits) << data;
  return string_stream.str();
}


// Delay
void Delay(float seconds) {
  #ifdef OS_WINDOWS
  int milisec = static_cast<int>(seconds * 1000);
  Sleep(milisec);
  #else
  int microsec = static_cast<int>(seconds * 1000000);
  usleep(microsec);
  #endif
}

}  // namespace general
}  // namespace utils
}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_UTILS_GENERAL_IMPL_H_
