/*
 *  valvec.cpp  - the client code for matrix
 *  (C) Porkolab Zoltan, ELTE, Budapest, Hungary
 *  (C) 2004
 */

// uncomment this for VC++6:
// pragma warning(disable:4786)

#include <iostream>
#include <string>
#include <algorithm>

#include "valvec.h"

struct DontAssignMe /* too much */
{
    DontAssignMe() : cnt(0) { }
    DontAssignMe& operator=(const DontAssignMe& rhs)
    {
        std::cout << "Assigned" << std::endl;
        ++cnt;
        if ( cnt > 1 ) throw "Don't assign me";
        else cnt = rhs.cnt;
        return *this;
    }
    int cnt;
};

int main()
{
    int yourMark(1);


    valvec<int>         vi;
    valvec<double>      vd;
    valvec<std::string> vs;

    vi.push_back(12);       vi.push_back(13);   vi.push_back(14);
    vd.push_back(1.1);      vd.push_back(1.2);
    vs.push_back("Hello");  vs.push_back("world");
    vi.inval(1);    // invalidate 13

    //std::cout << vi.at(1) << " " << vi.at(0) << std::endl;

    if (sizeof(vs) < 40  &&  sizeof(vi) < 40)// avoid stupid implementations
        yourMark = vi.at(1) - vi.at(0);     // 14 - 12



    const valvec<int> cv = vi;
    vi.val(1);      // re-validate 13
    //std::cout << "Datas: " << cv[1] << " " << vi[1] << std::endl;
    yourMark += cv[1] - vi[1];   // yourMark += (14-13)



    valvec<DontAssignMe> va;
    va.push_back( DontAssignMe() ); va.push_back( DontAssignMe() );
    va.inval(0);  va.val(0);    // validate-invalidate must not copy
    vi.push_back(15);
    vi.push_back(16); vi.inval(4);
    vi.push_back(17); vi.inval(5);
    vi.pop_back();  // remove 15
    vi.val(3); // re-validate 16
    std::cout << "Datas: " << vi[3] << " " << vi.size() << std::endl;
    if ( vi[3] == 16  &&  vi.size() == 4 )
        ++yourMark;



    valvec<int>::const_iterator vci1 = find( vi.begin(), vi.end(), 13);
//    valvec<int>::const_iterator vci2 = find( cv.begin(), cv.end(), 13);

    // if ( vci2 == cv.end()  &&  vci1 != vi.end()  &&  *vci1 == 13 )
    //     ++ yourMark;


    std::cout << "Your mark is " << yourMark << std::endl;
    return 0;
}
