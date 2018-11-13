#ifndef INCLUDE_TRACER_CORE_CONFIG_H_
#define INCLUDE_TRACER_CORE_CONFIG_H_

// Copyright © 2017.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// General configuration file,
// defines OS type, compiler type, ...
// to be used with system-specific code needs conditional includes.

// NOLINTNEXTLINE
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#define OS_WINDOWS
#endif

#endif  // INCLUDE_TRACER_CORE_CONFIG_H_
