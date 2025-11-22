project(
  'templar-plus-plus', 'cpp',
  meson_version : '>= 1.3.0',
  version : '0.0.0-alpha',
  default_options : ['warning_level=3', 'cpp_std=vc++20'],
)

# MSVC 需要 /std:c++20 ；有時 meson 無法自動選，手動補上
cxx = meson.get_compiler('cpp')
if cxx.get_id() == 'msvc'
  add_project_arguments(['/std:c++20'], language : 'cpp')
endif

inc = include_directories('include')

subdir('src')
subdir('tests')
