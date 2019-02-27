# include <iostream>

void Cal() {
           static int count = 1;
           static int x = 1;
           x = count * count;
           std::cout << count << "*" << count;
           std::cout << ": " << x <<std::endl;
           count++;
}

int main() 
{
  for (int i=1; i<11; i++)
    Cal();
  return 0; 
}
