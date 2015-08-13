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

    your_index.put("programozási módszertan", 4);
    your_index.put("analízis", 2); // :-)
    your_index.put("programozási nyelvek I", 5);
    your_index.put("programozási nyelvek II", 2);
    yourMark = your_index.get("programozási nyelvek II");



    your_index.put("programozási nyelvek II", 3);
    const dict<std::string,int>  copy_of_your_index = your_index;
    yourMark = copy_of_your_index.get("programozási nyelvek II");


    if ( your_index["programozási nyelvek II"] ==
                  copy_of_your_index["programozási nyelvek II"] )
        ++your_index["programozási nyelvek II"];
     yourMark = your_index["programozási nyelvek II"];



    try
    {
        your_index["Java programozási nyelv"] = 5;
    }
    catch( bad_index<std::string> bi )
    {
        std::cerr << "A " << bi.index() << " targyat meg nem tanultuk\n";
        yourMark = your_index["programozási nyelvek II"]+1;
    }

    std::cout << "Your mark is " << yourMark << endl;
    return 0;
}
