#include<iostream>
#include<unordered_map>
using namespace std;

class node{
    public:

    int key;
    int data;
    node* next;
    node* prev;
    
    node(int k, int v){
      data = v;
      key = k;
      prev = next = NULL;
    }
};

node*head = new node(-1,-1);
node* tail = new node(-1,-1);

void addnode(node* newnode){
    node* nextnode = head->next;
    head->next = newnode;
    nextnode->prev = newnode;

    newnode->next = nextnode;
    newnode->prev = head;
}

void delnode(node* oldnode){
    node* prevnode = oldnode->prev;
    node* nxtnode = oldnode->next;
    
   prevnode->next = nxtnode;
   nxtnode->prev = prevnode;
    
}

unordered_map<int, node*>m;
int limit;
void LRU(int capacity){
    limit = capacity;
    head->next = tail;
    tail->prev = head; 
}

int get(int key){
    if (m.find(key) == m.end())
    {
        return -1;
    }
    
    node* ansnode = m[key];
    int ans = ansnode->data;

    m.erase(key);
    delnode(ansnode);

    addnode(ansnode);
    m[key] = ansnode;

    return ans;

}

void put(int key, int data ){
    if (m.find(key) != m.end())
    {
       node* oldnode = m[key];
       delnode(oldnode);
       m.erase(key);

    }

    if (m.size() == limit)
    {
        m.erase(tail->prev->key);
        delnode(tail->prev);
    }
       
    node* newnode = new node(key, data);
    addnode(newnode);
    m[key] = newnode;

}



int main(){
    LRU(2); 

    put(1, 1);
    put(2, 2);
    cout << get(1) << endl;
    put(3, 3); 
    cout << get(2) << endl; 
    put(4,4);
    cout << get(1) << endl; 
    cout << get(3) << endl; 
    cout << get(4) << endl; 
    return 0;
}