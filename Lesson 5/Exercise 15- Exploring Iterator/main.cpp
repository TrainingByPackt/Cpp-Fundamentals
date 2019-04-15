#include <iostream>
#include <vector>
int main()
{
   std::vector<int> numbers = {1, 2, 3, 4, 5};
   auto it = numbers.begin();
   std::cout << *it << std::endl; // dereference: points to 1
   it++; // increment: now it points to 2
   std::cout << *it << std::endl;
   // random access: access the 2th element after the current one
   std::cout << it[2] << std::endl;
   --it; // decrement: now it points to 1 again
   std::cout << *it << std::endl;
   it += 4; // advance the iterator by 4 positions: now it points to 5
   std::cout << *it << std::endl;
   it++; // advance past the last element;
   std::cout << "'it' is after the past element: " << (it == numbers.
end()) << std::endl;
}

