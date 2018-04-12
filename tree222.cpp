#include <iostream>
#include <sstream>
#include <string>
#include <valarray>
#include <fstream>
#include <initializer_list>
using namespace std;
class tree_t {
private:
    struct node_t {
        node_t* left;
        node_t* right;
        int value;
    };

private:
    node_t* root_;

public:
    tree_t() {
        root_ = nullptr;
    }

    node_t* root() {
        return root_;
    }
/*tree_t(std::initializer_list<int> keys)
{
	int n = keys.size();
	const int* _ptr = keys.begin();
	for (int i=0; i < n; i++)
	{
		insert(_ptr[i]);
	}
}*/
    void insert(int value) {
        node_t* node = new node_t;
        node->value = value;
        node->right = nullptr;
        node->left = nullptr;
        if (root_ == nullptr) {
            root_ = node;
            return;
        }

        node_t* vetka = root_;
        while (vetka != nullptr) {
            if (vetka->value < value) {
                if (vetka->right != nullptr) {
                    vetka = vetka->right;
                } else {
                    vetka->right = node;
                    return;
                }
            } else if (vetka->value > value) {
                if (vetka->left != nullptr) {
                    vetka = vetka->left;
                } else {
                    vetka->left = node;
                    return;
                }
            } else
                return;
        }
    }
    bool find(int value) const {
        node_t * node = root_;
        while(node != nullptr) {
            if(node -> value == value) {
                return true;
            }
            else {
                if( value <= node->value) {
                    node = node->left;
                }
                else node = node->right;
            }
        }
        return false;
    }

    void print(std::ostream& stream, int level, node_t* node) {
        if (node == nullptr)
            return;

        print(stream, level + 1, node->right);

        for (unsigned int i = 0; i < level; i++) {
            stream << "---";
        }
        stream << node->value<<endl;

        print(stream, level + 1, node->left);
    }
    void operation( std::ostream & stream, char op, int value) {
        switch (op) {
        case '+' : {
            insert(value);
            break;
        }
        case '?': {
            find(value);
            break;
        }
        case'=': {
            print(stream,0,root_);
            break;
        }
        case 'q': {
            exit(0);
            break;
        }
        default: {
            cout<<"invalid operation";
        }
        }
    }
    bool remove(int value) {
        if (!find(value))
            return false;
        node_t* node = root_;
        node_t* q = nullptr; // родитель элемента, которого нам нужно удалить
        while( (node!=nullptr) && (node->value!=value)) {
            q = node;
            if(value < node->value) node=node->left;
            else node=node->right;

        }
        node_t* v; // установить в сортировочном виде дерева.

        if (node->left==nullptr)  v = node->right;
        else if ( node->right==nullptr)  v = node->left;
        
        else  {
            node_t * t;
            node_t * s;
            t=node;
            v = node->right;
            s= v->left;
           while (s!=nullptr)     
            { t=v;//t - отец перменной v;
              v=s;
              s=v->left;

            }
            
            if (t!=node){
                t->left=v->right;
                v->right=node->right;
                v->left=node->left;
            }
            else {
                v->left=node->left;
                
            }
       }                
        if(q==nullptr) {
            root_=v;
          }
        else if( node==q->left) q->left=v;
     else q->right=v;  
        delete node;
    }
     void destroy(node_t * node) {
        node_t * time= node;
        
        while(time != nullptr) {
            if(time->left != nullptr) {
                time= time->left;
            }
            else if(time->right != nullptr) {
                time = time->right;
            }
            else if(time == node && node->left == nullptr && node->right == nullptr) {

                delete  time;
                break;
            }
            else if(time->left == nullptr && time->right == nullptr) {
                delete  time;
                time = node;
            }

        }

    }
    ~tree_t() {

        destroy(root_);

    }

};
int main() {
    initializer_list <int> c2{ 5, 4, 3, 2, 1 };  
    string string;
    int value;
    char op;
    /* getline(cin, string);
     istringstream stream(string);
     stream>> value;*/

    tree_t tree1;
    /*cin>>value;
    tree1.insert(value);

    cin>>value;
    tree1.insert(value);
    cin>>value;
    tree1.insert(value);
    cout<<endl;
    cout<<endl;

    tree1.print(cout);*/
    for(unsigned int i=0; i<8; i++) {
        cin>>value;
        tree1.insert(value);
    }
    tree1.print(cout, 0, tree1.root());

    cin>>value;
    tree1.remove(value);
    tree1.print(cout, 0, tree1.root());
    //  cin>>value;
    //  tree1.insert(value);
    //if(tree1.find(4) == true) {cout<<"meh"<<endl;}


// return 0;
}
