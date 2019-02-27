#include <iostream>

// Class definition
class Coordinates {
  private:
    float _latitude;
    float _longitude;
    
 // Getters
  public:
    Coordinates(float latitude, float longitude) 
      : _latitude(latitude), _longitude(longitude) {}

    float get_latitude(){ return _latitude; }
    float get_longitude(){ return _longitude; }
};



int main() {
  Coordinates washington_dc(38.8951, -77.0364);
  std::cout << "Object named washington_dc of type Coordinates created." << std::endl;
  
  std::cout << "Washington DC has a latitude of " << washington_dc.get_latitude() << " and longitude of " << washington_dc.get_longitude() << std::endl;
}
