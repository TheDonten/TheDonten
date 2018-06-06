#include <sstream>
#include<iostream>
#include<string>

template <typename T>
class tree_t
{
private:
	struct node_t {
		node_t * left;
		node_t * right;
		T value;
	};
private:
	node_t * root_;
public:
	tree_t()
	{
		root_= nullptr;
	}
	void del(node_t * node)
	{	
		if (root_ != nullptr) {
			if (node->left) del (node->left);
			if (node->right) del (node->right);
			delete node;
		}
	}
	~tree_t()
	{
			del(root_);
			//root_ = nullptr;
	}
	
	bool isEmpty()
	{
		return (!root_);
	}
	
	void insert(T value)
	{
		node_t * node = new node_t;
		node->value = value;
		node->left = nullptr;
		node->right = nullptr;

		if (root_ == nullptr) {
			root_ = node;
		}
		else {
			node_t * branch = root_;
			while (branch != nullptr){
				if (value > branch->value){
					if (branch->right != nullptr) {
						branch = branch->right;
					}
					else {
						branch->right = node;
						return;
					}
				}
				else {
					if (value < branch->value){
						if (branch->left != nullptr) {
							branch = branch->left;
						}
						else {
							branch->left = node;
							return;
						}
					}
					else
					{
						return;
					}

				}
			}
		}
	}
	bool find(T value) const
	{
		node_t * branch = root_;
		while (branch != nullptr){
			if (value == branch->value) {
				return true;
			}
			else {
				if (value > branch->value) {
					branch = branch->right;
				}
				else {
					branch = branch->left;
				}
			}
		}
		return false;
	}
	
	node_t * root() const
	{
		return  root_;
	}
	void print(std::ostream & stream ,  node_t * node , size_t i = 1) const
	{
		if (node->right) {
			i++;
			print(stream ,node->right, i);
			i--;
		}
		for (size_t k = 0; k < i; k++) {
			stream << "--";
		}
			stream << node->value << std::endl;
		if (node->left) {
			i++;
			print(stream ,node->left, i);
			i--;
		}
	}
	
	
	tree_t(std::initializer_list<T> keys)
	{
		root_ = nullptr;
		size_t size = keys.size();
		for (size_t i = 0; i < size; i++) {
			T a = *(keys.begin()+i);
			insert(a);
		}
	}
	void delete_one_child(node_t* node, node_t* child, node_t* parent){
            if(parent){
                if(parent->right == node) parent->right = child;
                else parent->left = child;
            }
            else root_ = child;
            if(node->right == child) node->right = nullptr;
            else node->left = nullptr;
            
        }
      
        
        node_t* left_child(node_t* node){
            while(node->left != nullptr){
                node = node->left;
            }
            return node;
        }
	node_t* left_child_parent(node_t* node){
            node_t* parent = node;
            node = node->right;
            while(node->left != nullptr){
                parent = node;
                node = node->left;
            }
            return parent;
        }
          void transplant(node_t* node, node_t* parent){
              node_t* child_left = left_child(node->right);
              node_t* child_left_parent = left_child_parent(node);
              if(child_left->right ) {child_left_parent->left = child_left->right;
                                    child_left->right = nullptr; 
              }
              else child_left_parent->left = nullptr;
              if(parent){
                  if(parent->right == node) parent->right = child_left;
                  else parent->left = child_left;
              }
              else root_ = child_left;
                                      
             
              if(node->right != child_left){child_left->right = node->right;
              node->right = nullptr;}
              
              if(node->left) {child_left->left = node->left;
              node->left = nullptr;}
              
          }
	bool remove(T key)
	{   node_t* node = root_;
            node_t* parent = nullptr;
            while(node->value != key && node){
                 parent = node;
            if (key < node->value)
                node = node->left;
            else
                node = node->right;
            }
            if(node == nullptr) return false;
            
            if(node->left == nullptr && node->right == nullptr){
                if(parent){
                    if(parent->right == node) parent->right = nullptr;
                    else parent->left = nullptr;
                }
                else root_ = nullptr;
               
            }
            else if(node->left && node->right == nullptr){
                delete_one_child(node,node->left,parent);
            }
            else if(node->right && node->left == nullptr){
                delete_one_child(node,node->right,parent);
            }
            else if(node->right && node->left){
                transplant(node,parent);
                
            }
	}
};
