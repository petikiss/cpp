#include <memory>
#include <iostream>



struct Test
{
    int a = 6;

    friend std::ostream& operator<<(std::ostream& out, Test t)
    {
        out << t.a << std::endl;

        return out;
    }
};


void foo()
{

}



int main()
{
    std::shared_ptr<Test> t1 (new Test());
    std::shared_ptr<Test> t2;

    t2 = t1;

    std::cout << t1.get() << " " << *t1.get() << std::endl; // get() the row pointer and after dereference it
    std::cout << t2.get() << " " << t2->a << std::endl;
    std::cout << "Data: " << *t1;
    std::cout << "Ref cout: " << t1.use_count() << std::endl;


    // make_shared


}


