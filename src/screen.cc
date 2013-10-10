#include "screen.h"

namespace nightwing {

Screen* Screen::instance_ = 0;

Screen* Screen::Instance() {
  if (instance_ == 0) {
    instance_ = new Screen();
    instance_->has_errors_ = false;
  }
  
  return instance_;
}

void Screen::Release() {
  if (instance_)
    delete instance_;
  
  instance_ = 0;
}

// It is safe to initialize things in constructor due to nature of singleton
Screen::Screen() {
  dpy_ = xcb_connect(NULL, NULL);
  if (xcb_connection_has_error(dpy_)) {
    has_errors_ = true; 
    return;
  }
  
  screen_ = xcb_setup_roots_iterator(xcb_get_setup(dpy_)).data;
  root_ = screen_->root;
}

Screen::~Screen() {
  
}

void Screen::MainLoop() {
  while(1) {
    usleep(20);
  }
}


} // namespace nightwing
