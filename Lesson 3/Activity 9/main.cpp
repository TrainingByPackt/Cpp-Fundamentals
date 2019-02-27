#include <iostream>
 
class managed_array {
  public:
    explicit managed_array(size_t size) {
       array = new int[size];
	 std::cout << "Array of size " << size << " created." << std::endl;
    }
 
    ~managed_array() {
       delete[] array;
	 std::cout << "Array deleted." << std::endl;
    }
 
  private:
    int *array;
};

int main() {
    managed_array m(10);
    // Array of size 10 created.
    // Array deleted.

}
