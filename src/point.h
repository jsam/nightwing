#ifndef NIGHTWING_POINT_H_
#define NIGHTWING_POINT_H_

#include <xcb/xcb.h>

namespace nightwing {

// Wrapper around xcb_point_t with operators for easier 
// manipulation and abstraction
class Point {
 public:
  Point(int x = 0, int y = 0);
  Point(xcb_point_t& point);

  inline int x() const { return x_; }

  inline int y() const { return y_; }
  
  inline void set_x(const int x) { x_ = x; }
  
  inline void set_y(const int y) { y_ = y; }
  
  Point& operator+=(const Point& rhs);

 private:
  int x_;
  int y_; 

};

inline bool operator==(const Point& lhs, const Point& rhs) {
  return lhs.x() == rhs.x() && lhs.y() == rhs.y();
}
  
inline bool operator!=(const Point& lhs, const Point& rhs) {
  return !(lhs == rhs);
}
  
inline Point operator+(const Point& lhs, const Point& rhs) {
  Point result(lhs); 
  result.set_x(lhs.x() + rhs.x());
  result.set_y(lhs.y() + rhs.y());
  return result; 
}

inline Point operator-(const Point& lhs, const Point& rhs) {
  Point result(lhs); 
  result.set_x(lhs.x() - rhs.x());
  result.set_y(lhs.y() - rhs.y());
  return result; 
}



} // namespace nightwing

#endif // NIGHTWING_POINT_H_