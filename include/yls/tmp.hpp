#ifndef INCLUDE_YLS_TMP_HPP_
#define INCLUDE_YLS_TMP_HPP_

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef MYLIB_BUILD
    #define MYLIB_API __declspec(dllexport)
  #else
    #define MYLIB_API __declspec(dllimport)
  #endif
#else
  #define MYLIB_API __attribute__((visibility("default")))
#endif

namespace yls::TMP {
  extern "C" {
    MYLIB_API int parse();
    MYLIB_API int stringify();
  }
}

#endif  // INCLUDE_YLS_TMP_HPP_
