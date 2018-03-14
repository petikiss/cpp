// http://thbecker.net/articles/rvalue_references/section_01.html

// c:
// An lvalue is an expression e that may appear on the left or on the right hand side of an assignment,
// whereas an rvalue is an expression that can only appear on the right hand side of an assignment.


// c++:
// An lvalue is an expression that refers to a memory location and allows us to take the address of that memory location via the & operator.
// An rvalue is an expression that is not an lvalue.

int& foo()
{
}

int foo2()
{
}


int main()
{
    int a = 5;
    int b = 6;

    // (a+b) = 3; // rvalue

    foo() = 4; // lvaule

    foo2() = 2; // rvalue

    // &foo2(); // rvalue
}
