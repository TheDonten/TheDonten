#include <sstream>
#include<iostream>
#include<string>

template <typename T>
class tree_t
{
private:
	struct node_t {
            node_t* parent;
		node_t * left;
		node_t * right;
                bool color = false;
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
	
 node_t *    grandparent( node_t* node)
{
	if ((node!= nullptr) && (node->parent != nullptr))
		return node->parent->parent;
	else
		return nullptr;
}

node_t* uncle( node_t *node)
{
	node_t *g = grandparent(node);
	if (g == NULL)
		return nullptr; // No grandparent means no uncle
	if (node->parent == g->left)
		return g->right;
	else
		return g->left;
}

   void rotate_left(node_t* node) {
        node_t* vetka = node->right;
        if(root_ == node){
            root_ = node->right;
        }
        vetka->parent = node->parent;
        if (node->parent != nullptr) {
            if (node->parent->left == node)
                node->parent->left = vetka;
            else
                node->parent->right = vetka;
        }
        node->right = vetka->left;
        if (vetka->left != nullptr) vetka->left->parent = node;
        node->parent = vetka;
        vetka->left = node;
    }
    void rotate_right(node_t* node) {
        node_t* vetka = node->left;
        if(root_ == node){
            root_ = node->left;
        }
        vetka->parent = node->parent;
        if (node->parent != nullptr) {
            if (node->parent->left == node)
                node->parent->left = vetka;
            else
                node->parent->right = vetka;
        }
        node->left = vetka->right;
        if (vetka->right != nullptr) vetka->right->parent = node;

        node->parent = vetka;
        vetka->right = node;
    }

void insert_case1(node_t *node)
{
	if (node->parent == nullptr)
		node->color = false;
	else
		insert_case2(node);
}

void insert_case2(node_t *node)
{
	if (node->parent->color == false)
		return; /* Tree is still valid */
	else
		insert_case3(node);
}
void insert_case3(node_t *node)
{
	node_t *u = uncle(node), *g;

	if ((u != nullptr) && (u->color == true)) {
	// && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
		node->parent->color = false;
		u->color = false;
		g = grandparent(node);
		g->color = true;
		insert_case1(g);
	} else {
		insert_case4(node);
	}
}
void insert_case4(node_t  *node)
{
	node_t *g = grandparent(node);

	if ((node == node->parent->right) && (node->parent == g->left)) {
		rotate_left(node->parent);
		node = node->left;
	} else if ((node == node->parent->left) && (node->parent == g->right)) {
		rotate_right(node->parent);
		node = node->right;
	}
	insert_case5(node);
}

void insert_case5(node_t *node)
{
	node_t *g = grandparent(node);

	node->parent->color = false;
	g->color = true;
	if ((node == node->parent->left) && (node->parent == g->left)) {
		rotate_right(g);
	} else { /* (n == n->parent->right) && (n->parent == g->right) */
		rotate_left(g);
	}
}
	void insert(T value)
	{
		node_t * node = new node_t;
		node->value = value;
		node->left = nullptr;
		node->right = nullptr;

		if (root_ == nullptr) {
			root_ = node;
                        root_->parent = nullptr;
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
                                                branch->right->parent = branch;
                                                branch->right->color = true;
                                                insert_case1(branch->right);
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
                                                        branch->left->parent = branch;
                                                        branch->left->color = true;
                                                        insert_case1(branch->left);
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
                if(node->color == true)
			stream << node->value <<"R"<< std::endl;
                else  stream << node->value <<"B"<< std::endl;
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
	
};

