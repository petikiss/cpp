#include <memory>
#include <iostream>


struct Node
{
    Node(int d) : data(d) {}
    std::unique_ptr<Node> parent;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    int data;
};


class BinaryTree
{
private:
    std::unique_ptr<Node> root;
public:
    void insert(std::unique_ptr<Node> p)
    {
        if( root == nullptr)
        {
            std::cout << "Inserting root element(" << p->data << ")\n";
            root = std::move(p);
        }
        else
        {
            std::cout << "Inserting common node element!(" << p->data << ")\n";
            //std::unique_ptr<Node> tmpParent (p);


            while()
            {

            }
        }
    }

    std::unique_ptr<Node> next()
    {
    }

    void print()
    {

    }
};



int main()
{
    BinaryTree b;

    std::unique_ptr<Node> n1( new Node(50));
    std::unique_ptr<Node> n2( new Node(30));
    std::unique_ptr<Node> n3( new Node(40));
    std::unique_ptr<Node> n4( new Node(100));
    std::unique_ptr<Node> n5( new Node(90));
    std::unique_ptr<Node> n6( new Node(70));


    b.insert(std::move(n1));
    b.insert(std::move(n2));
    b.insert(std::move(n3));
    b.insert(std::move(n4));
    b.insert(std::move(n5));
    b.insert(std::move(n6));



    b.print();

    return 0;
}
