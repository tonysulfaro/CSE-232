#include<iostream>
using std::ostream; using std::cout; using std::endl; using std::flush;
#include<string>
using std::string; using std::to_string;
#include<deque>
using std::deque;
#include<utility>
using std::pair;
#include<algorithm>
using std::sort; using std::copy; using std::swap;

/*
  wfp 4/20/15
  binary search tree
*/

//
// BNode
//

template<typename T>
struct BNode{
public:
    BNode* left_;
    BNode* right_;
    T      data_;

    BNode():left_(nullptr),right_(nullptr),data_(T()) {};
    BNode(T d): left_(nullptr),right_(nullptr),data_(d) {};
    BNode(const BNode&) = default;
    bool operator==(BNode& bn){return data_ == bn.data_;};
    bool operator!=(BNode& bn){return data_ != bn.data_;};    
    bool operator<(BNode& bn){return data_ < bn.data_;};
    bool operator>(BNode& bn){return data_ > bn.data_;};        
};

template<typename T>
ostream& operator<<(ostream& out, const BNode<T>& bn){
    out << bn.data_;
    return out;
}

//
// Tree
//

template<typename T>
class BinaryTree{
private:
    BNode<T>* root_;

public:
    BinaryTree():root_(nullptr) {};
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BinaryTree& operator=(BinaryTree);
    void insert(T);
    void insert(BNode<T>*&, BNode<T>*&);
    bool del_node(T);
    void del_node(BNode<T>*&);
    operator string();
    BNode<T>*& find(T);
    BNode<T>*& find(BNode<T>*&, BNode<T>*&);    
    void BFS_print();
    friend ostream& operator<<(ostream& out, BinaryTree<T>& bt){
	out << string(bt);
	return out;
    };
};

// function for recursive copy. BNode is public so not
// required to be part of BinaryTree
template<typename T>
void copy_recurse(BNode<T>*& new_ptr, BNode<T>* to_copy_ptr){
    if (to_copy_ptr == nullptr)
	new_ptr = nullptr;
    else{
	new_ptr = new BNode<T>(to_copy_ptr->data_);
	copy_recurse(new_ptr->left_, to_copy_ptr->left_);
	copy_recurse(new_ptr->right_, to_copy_ptr->right_);
    }
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& bt){
    copy_recurse(root_, bt.root_);
}

// function for recursive destruction
template<typename T>
void destruct_recurse(BNode<T>* bn_ptr){
    if (bn_ptr != nullptr){
	//cout << "recurse on :"<<bn_ptr->data_<<endl;
	destruct_recurse(bn_ptr->left_);
	destruct_recurse(bn_ptr->right_);
	//cout <<"Destroying:"<<bn_ptr->data_<<endl;
	delete bn_ptr;
    }
}

template<typename T>
BinaryTree<T>::~BinaryTree(){
    destruct_recurse(root_);
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree bt){
    swap(root_, bt.root_);
    return *this;
}

// recursive
template<typename T>
void BinaryTree<T>::insert(BNode<T>*& tree_ptr, BNode<T>*& new_node){
    if (tree_ptr == nullptr)
	tree_ptr = new_node;

    // disallow multiple entries
    else if (*tree_ptr != *new_node){
	if (*new_node < *tree_ptr)
	    insert(tree_ptr->left_, new_node);
	else if (*new_node > *tree_ptr)
	    insert(tree_ptr->right_, new_node);
    }
}

template<typename T>
void BinaryTree<T>::insert(T d){
    BNode<T>* node = new BNode<T>(d);
    insert(root_,node);
}

template<typename T>
BNode<T>*& BinaryTree<T>::find(T d){
    return find_recurse(d, root_);
}

// function, recursive find value
template<typename T>
BNode<T>*& find_recurse(T val, BNode<T>*& node_ptr){
    if (node_ptr == nullptr){
	cout << "Null ptr"<<endl;
	return node_ptr;
    }
    if (node_ptr->data_ == val){
	cout << "Found it:"<<val<<endl;
	return node_ptr;
    }
    else if (val < node_ptr->data_){
	//cout << "Recurse left from: "<< node_ptr->data_<<endl;
	return find_recurse(val, node_ptr->left_);
    }
    else{
	//cout << "Recurse right from: "<< node_ptr->data_<<endl;
	return find_recurse(val, node_ptr->right_);
    }
}

template<typename T>
BNode<T>*& BinaryTree<T>::find(BNode<T>*& ptr, BNode<T>*& node){
    if(ptr == nullptr)
	return ptr;
    else if (*ptr == *node)
	return ptr;
    else if (*node < *ptr)
	return find(ptr->left_, node);
//    else if (*node > *ptr)
    else
	return find(ptr->right_, node);
}
	        
template<typename T>
BinaryTree<T>::operator string(){
    string result="";
    return recurse_str(root_, result);
}

template<typename T>
string recurse_str(BNode<T>* ptr, string result){
    if (ptr == nullptr)
	return result;
    else{
	result = recurse_str(ptr->left_, result);
	result = result + to_string(ptr->data_)+",";
	result = recurse_str(ptr->right_, result);
    }
    return result;
}

template <typename T>
void BinaryTree<T>::BFS_print(){
    using NodePair = pair< BNode<T>*, int>;
    NodePair nd_pr;
    BNode<T>* node_ptr;
    int level, previous_level=-1;
    if (root_ == nullptr)
	return;
    deque < NodePair > bfs_queue;
    bfs_queue.push_back({root_,0});
    
    while (!bfs_queue.empty()) {
	nd_pr = bfs_queue.front();
	node_ptr = nd_pr.first;
	level = nd_pr.second;	
	bfs_queue.pop_front();
	// to get a newline for a new level
	// have to track previous_level, see if it is different
	if (level != previous_level){
	    cout << endl;
	    cout <<"Level "<< level <<": ";
	    previous_level = level;
	    cout << " ";
	}
	// print the data 
	cout <<node_ptr->data_ << ", ";
	// update the queue
	if (node_ptr->left_ != nullptr)
	    bfs_queue.push_back({node_ptr->left_, level+1});
	if (node_ptr->right_ != nullptr)
	    bfs_queue.push_back({node_ptr->right_, level+1});
    }
    cout << endl;
}

template <typename T>
bool BinaryTree<T>::del_node(T val){
    BNode<T>*& to_del = find(val);
    bool result;
    if (to_del != nullptr){
	del_node(to_del);
	result = true;
    }
    else
	result = false;
    return result;
}

template<typename T>
void BinaryTree<T>::del_node(BNode<T>*& to_del){
    BNode<T>* copy_to_del = to_del;
    
    // 0 or 1 child cases
    if (to_del->right_ == nullptr){
	cout << "One child right case"<<endl;
	to_del = to_del -> left_;
    }
    else if (to_del->left_ == nullptr){
	cout << "One child left case"<<endl;;
	to_del = to_del->right_;
    }
    // 2 child case
    else{
	cout << "two node case"<<endl;
	BNode<T>* right_ptr = to_del->right_;
	BNode<T>* leftmost_ptr = right_ptr;
	cout << "Node:"<<to_del->data_<<endl;
	cout << "Right:"<<right_ptr->data_<<endl;
	cout <<" Start Left:"<<leftmost_ptr->data_<<endl;
	while (leftmost_ptr->left_ != nullptr)
	    leftmost_ptr = leftmost_ptr->left_;
	cout << "Leftmost:"<<leftmost_ptr->data_<<endl;
	
	leftmost_ptr->left_ = to_del->left_;
	to_del = to_del->right_;
    }
    delete copy_to_del;
}
	
	    
	
    
    
	

