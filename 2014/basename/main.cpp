#include <libgen.h>
//#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char* argv[])
{
std::cout << argv[0] << std::endl;
  char* name = get_current_dir_name();
printf("aktualis dir:%s\n",name);
std::cout<<"asdf:" << dirname(argv[0]) << std::endl; 

}
