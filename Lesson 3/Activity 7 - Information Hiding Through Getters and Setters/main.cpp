#include <iostream>

// Class definition
class Coordinates {
  private:
    float latitude;
    float longitude;
 
 // Getters and setters
  public:
    void set_latitude(float value){ latitude = value; }
    void set_longitude(float value){ longitude = value; }
    float get_latitude(){ return latitude; }
    float get_longitude(){ return longitude; }
};



int main() {
  Coordinates washington_dc;
  std::cout << "Object named washington_dc of type Coordinates created." << std::endl;
  
  washington_dc.set_latitude(38.8951);
  washington_dc.set_longitude(-77.0364);
  std::cout << "Object's latitude and longitude set." << std::endl;
  
  std::cout << "Washington DC has a latitude of " << washington_dc.get_latitude() << " and longitude of " << washington_dc.get_longitude() << std::endl;
}
