
#include <iostream>



int main()
{
void* raw = operator new(5*sizeof(int));

int* place = static_cast<int*>(raw);


for(int i = 0; i < 5; i++)
{
new (&place[i]) int(i);
}


std::cout << place[2] << std::endl;


   return 0;
}
