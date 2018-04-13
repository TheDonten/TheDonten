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
    queue_t &operator =(queue_t const& other){
       if(other.head){
             node_t * node;
  while(head!=nullptr){
  node = head->next;
  delete head;
  head = node;

}
      
       }
     node_t* p = other.head;
     while( p!= nullptr){
         push(p->value);
         p = p->next;
           
    }
   return  *this;
}
    void push(T  value) {
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
~queue_t(){
    node_t * node;
  while(head!=nullptr){
  node = head->next;
  delete head;
  head = node;
}
}
};

int main(){
    queue_t q1;
    queue_t q2;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q2.push(5);
    q2.push(6);
    q2.push(7);
    q1 = q2;
    q1.write(cout,q1.head_());
}
    /*for(int i=0; i<3; i++)
    {
        cin>>value;
        q1.push(value);
    }

    q1.write(cout,q1.head_());
    //q1.pop_back();
    if(2 ==q1.pop_back()) cout<<"Okay"<<endl;
    q1.write(cout,q1.head_());*/
    
