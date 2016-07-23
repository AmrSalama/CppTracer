#ifndef INCLUDE_TRACER_CORE_CONFIGURE_H_
#define INCLUDE_TRACER_CORE_CONFIGURE_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// General project configuration file,
// defines OS type, compiler type, ...
// to be used with system-specific code needs conditional includes.

#if defined(__WIN32__)
    || defined(_WIN32)
    || defined(WIN32)
    || defined(_WIN64)
    || defined(__WINDOWS__)
    || defined(__TOS_WIN__)
#define OS_WINDOWS
#endif

#endif  // INCLUDE_TRACER_CORE_CONFIGURE_H_