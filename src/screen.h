#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <xcb/xcb.h>
#include <unistd.h>

namespace nightwing {

// TODO: class description 
class Screen {
 public:
  // Create new single instance of Screen.
  static Screen* Instance();
 
  // Destroy Screen instance.
  static void Release();
  
  // Main loop. Check for events and etc.
  void MainLoop();

  // Getters
  bool HasErrors() { return has_errors_; } 
  xcb_connection_t* get_dpy() { return dpy_; }

 private:
  Screen();
  ~Screen();
  
 protected:
  static Screen* instance_;

  bool has_errors_; 
  xcb_connection_t* dpy_;
  xcb_screen_t* screen_; 
  xcb_drawable_t root_; 
  
};

} // namespace nightwing

#endif /* _SCREEN_H_ */
