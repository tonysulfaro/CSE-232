#include<iostream>
using std::cout; using std::endl; using std::boolalpha;

#include "22.1-binaryTree.h"

int main(){
    BNode<long> bn(123);
    cout << "BNode:"<<bn << endl;
    BNode<long>* ptr;
    cout << boolalpha;

    BinaryTree<long> bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(2);
    bt.insert(1);
    bt.insert(6);
    bt.insert(4);
    cout << "Binary Tree inorder:"<<bt << endl;
    cout << "Binary Tree level order:";
    bt.BFS_print();
    ptr = bt.find(5);
    if (ptr != nullptr)
	cout << "Found it"<<endl;
    else
	cout << "Value not found"<<endl;

    BinaryTree<long> bt2(bt);
    bt2.insert(10);
    cout << "Binary Tree inorder:"<<bt2 << endl;    
    cout << "Binary Tree inorder:"<<bt << endl;

    {
    BinaryTree<long> bt3;
    bt3 = bt;
    bt3.insert(25);
    cout << "Binary Tree inorder:"<<bt3 << endl;    
    cout << "Binary Tree inorder:"<<bt << endl;
    cout << "Binary Tree level order:";
    bt3.BFS_print();    
    }

    bt2.BFS_print();
    cout << "Del of 3 successful? "<<bt2.del_node(3)<<endl;
    bt2.BFS_print();
    cout << "Del of 1 successful? "<<bt2.del_node(1)<<endl;
    bt2.BFS_print();
    cout << "Del of 7 successful?" <<bt2.del_node(7)<<endl;
    bt2.BFS_print();
    cout << "Binary Tree inorder:"<<bt2 << endl;
    bt2.BFS_print();
    
}
