#include "binfa.h"



int main(int argc, char* argv[])
{
    BinTree<int> tree;

    tree.addNode(100);
    tree.addNode(50);
    tree.addNode(200);
    tree.addNode(25);
    tree.addNode(70);
    tree.addNode(220);
    tree.addNode(250);
    tree.addNode(60);
    tree.addNode(300);

    tree.print();

    return 0;
}
