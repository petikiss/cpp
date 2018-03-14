#include <iostream>
#include <memory>

class MyList
{
    struct Node
    {
        Node(int data) : _next(nullptr), _data(data) {}
        std::shared_ptr<Node> _next;
        int _data;
    };

    std::shared_ptr<Node> root;
public:
    MyList() : root(nullptr) {}
    void push_back(int data)
    {
        std::unique_ptr<Node> n( new Node(data));
        if (root == nullptr)
        {
//            root = n;
        }
    }
};


int main()
{
    MyList l;

    l.push_back(6);



    return 0;
}
