#include <iostream>

using namespace std;
template<typename T>
class queue_t {
private:
    struct node_t{
        node_t* next;
        T value;
    };
private:
    node_t* head;
    node_t* tail;
public:
    queue_t(){
        head = nullptr;
        tail = nullptr;
    }
    node_t* head_() const{
        return head;
    }
    queue_t(queue_t const& other){
       // this->head =
    }
    void push(T value) {
        node_t* node = new node_t;
        node->value=value;
        node->next= nullptr;
        if(head == nullptr){
            head = node;
            tail = node;
            return;
        }
       else {
            /*tail = head;
            while(tail->next != nullptr){
                tail = tail->next;
            }
            tail->next = node;*/
            tail->next = node;
            tail = tail->next;
        }
    }
    T pop_back(){
        T value = head->value;
        node_t* node= head->next;
        delete head;
        head = node;
        return value;
    }
void write(std::ostream & stream, node_t* head){
    node_t * p;
    p=head;
    while (p != NULL) {
        stream << "+---+"<<endl;
        stream<<p->value<<endl;
        p = p->next;
    }
}
};

int main(){
    queue_t<int> q1;
    int value;
    for(int i=0; i<3; i++)
    {
        cin>>value;
        q1.push(value);
    }

    q1.write(cout,q1.head_());
    //q1.pop_back();
    if(2 ==q1.pop_back()) cout<<"Okay"<<endl;
    q1.write(cout,q1.head_());
}
