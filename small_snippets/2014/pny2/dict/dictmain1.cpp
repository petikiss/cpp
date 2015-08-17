/*
 *  main.cc   - the client code for class dict
 *  (C) Porkolab Zoltan, ELTE, Budapest, Hungary
 *  (C) 2001
 */

#include <iostream>
#include <string>
#include "dict.h"


int main()
{
    int yourMark(1);


    dict<std::string,int>  your_index;

    your_index.put("programoz�si m�dszertan", 4);
    your_index.put("anal�zis", 2); // :-)
    your_index.put("programoz�si nyelvek I", 5);
    your_index.put("programoz�si nyelvek II", 2);
    yourMark = your_index.get("programoz�si nyelvek II");



    your_index.put("programoz�si nyelvek II", 3);
    const dict<std::string,int>  copy_of_your_index = your_index;
    yourMark = copy_of_your_index.get("programoz�si nyelvek II");


    if ( your_index["programoz�si nyelvek II"] ==
                  copy_of_your_index["programoz�si nyelvek II"] )
        ++your_index["programoz�si nyelvek II"];
     yourMark = your_index["programoz�si nyelvek II"];



    try
    {
        your_index["Java programoz�si nyelv"] = 5;
    }
    catch( bad_index<std::string> bi )
    {
        std::cerr << "A " << bi.index() << " targyat meg nem tanultuk\n";
        yourMark = your_index["programoz�si nyelvek II"]+1;
    }

    std::cout << "Your mark is " << yourMark << endl;
    return 0;
}
