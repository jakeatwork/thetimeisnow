#include <pebble.h>
 
Window *window;
TextLayer *text_layer;
 
void window_load(Window *window)
{
  //We will add the creation of the Window's elements here soon!
  text_layer = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_background_color(text_layer, GColorBlack);
  text_layer_set_text_color(text_layer, GColorClear);
 
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  text_layer_set_text(text_layer, "the time is now");
  
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD)); 
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  
}
 
void window_unload(Window *window)
{
  //We will safely destroy the Window's elements here!
  text_layer_destroy(text_layer);
}
 
void init()
{
  //Initialize the app elements here!
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  window_stack_push(window, true);
}
 
void deinit()
{
  //De-initialize elements here to save memory!
  window_destroy(window);
}
 
int main(void)
{
  init();
  app_event_loop();
  deinit();
}