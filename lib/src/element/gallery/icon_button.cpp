/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <elements/element/gallery/icon_button.hpp>
#include <elements/support/text_utils.hpp>

namespace cycfi { namespace elements
{
   void draw_plain_icon_button(
      context const& ctx
    , uint32_t code
    , float size
    , bool hilite
    , bool enabled
   )
   {
      auto const& theme = get_theme();
      canvas& canvas_ = ctx.canvas;
      rect bounds = ctx.bounds;

      // Draw Icon
      color icon_color = (enabled && hilite)?
         theme.icon_color.level(1.5) :
         theme.icon_color.level(0.9);
      if (!enabled)
         icon_color.opacity(icon_color.alpha * theme.disabled_opacity);
      draw_icon(canvas_, bounds.move(0.5, 0.5), code, size, icon_color);
   }

   void draw_icon_button(
      context const& ctx
    , uint32_t code
    , float size
    , color body_color_
    , bool state
    , bool hilite
    , bool enabled
   )
   {
      float corner_radius = 6;
      auto const& theme = get_theme();

      // Draw Button Body
      color body_color = state? body_color_ : body_color_.opacity(0.5).level(0.8);
      draw_button_base(ctx, ctx.bounds, body_color, enabled, corner_radius);

      canvas& canvas_ = ctx.canvas;
      rect bounds = ctx.bounds;

      // Draw Icon
      color icon_color = (enabled && hilite)?
         theme.icon_color.level(1.5) :
         theme.icon_color.level(0.9);
      if (!enabled)
         icon_color = icon_color.opacity(icon_color.alpha * theme.disabled_opacity);
      draw_icon(canvas_, bounds.move(0.5, 0.5), code, size, icon_color);
   }
}}
