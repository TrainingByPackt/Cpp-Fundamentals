#include <iostream>

class Point
{
  public:
	bool operator< (const Point &other){
      return x < other.x || (x == other.x && y < other.y);
	}
 
	int x;
	int y;
};

int main() {
  Point p_1, p_2;
 
  p_1.x = 1;
  p_1.y = 2;
 
  p_2.x = 2;
  p_2.y = 1;
 
  std::cout << std::boolalpha << (p_1 < p_2) << std::endl;
}
