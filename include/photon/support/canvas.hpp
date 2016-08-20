/*=================================================================================================   Copyright (c) 2016 Joel de Guzman   Licensed under a Creative Commons Attribution-ShareAlike 4.0 International.   http://creativecommons.org/licenses/by-sa/4.0/=================================================================================================*/#if !defined(PHOTON_GUI_LIB_CANVAS_MAY_3_2016)#define PHOTON_GUI_LIB_CANVAS_MAY_3_2016#include <photon/support/color.hpp>#include <photon/support/rect.hpp>namespace photon{   class view;   struct canvas_impl;   class canvas   {   public:      void              fill_color(color c);      void              fill_rect(rect r);      void              fill_round_rect(rect r, float radius);   private:                        canvas(canvas_impl* impl)                         : _impl(impl)                        {}      friend class view;      canvas_impl*      _impl;   };}#endif