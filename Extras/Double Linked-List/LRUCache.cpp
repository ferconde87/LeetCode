#include "DoubleLinkedList.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache{
    private:
        DoubleLinkedList ddl;
        unordered_map<int, Node *> map;
        int capacity;

    public:
        LRUCache(int c){
            capacity = c;
        }

        bool isFull(){
            return capacity == ddl.getSize();
        }

        void put(int key, int value){
            auto it = map.find(key);
            if(it != map.end()){
                ddl.deleteNode(it->second);
                //it isn't necesary to delete from map because it will be update
            }else{
                if(isFull()){
                    Node * nodeToDelete = ddl.deleteLast();
                    map.erase(nodeToDelete->key);
                }
            }

            Node * node = new Node(key, value);
            map[key] = node;//insert or update 
            ddl.addFirst(node);
        }

        void put2(int key, int value){
            if(isFull()){
                Node * last = ddl.deleteLast();
                map.erase(last->key);
            }

            auto it = map.find(key);
            if(it != map.end()){
                Node* nodeToDelete = it->second;
                ddl.deleteNode(nodeToDelete);
            }
            Node * node = new Node(key, value);
            map[key] = node;//insert or update 
            ddl.addFirst(node);
        }

        int get(int key){
            auto it = map.find(key);
            if(it == map.end()) return -1;
            Node * node = it->second;
            int value = node->value;
            ddl.deleteNode(node);
            ddl.addFirst(node);
            return value;
        }

        void print(){
            ddl.print();
            ddl.printBackward();
        }
};

int main(){
    LRUCache lru(3);

    lru.put(1,1);
    lru.put(2,2);
    lru.put(3,3);
    lru.print();
    lru.put(1,1);
    lru.put(1,11);
    lru.print();

    lru.put(1,1);
    lru.put(2,2);
    lru.put(3,3);

    lru.print();//3 2 1
    
    lru.get(1);
    lru.print();//1 3 2
    
    lru.get(2);
    lru.print();//2 1 3
    
    lru.put(4,4);
    lru.print();//4 2 1
    
    lru.put(2,256);
    lru.print();//256 4 1

    lru.get(1);//1 256 4
    lru.put(2,8);//8 1 4
    lru.print();//

    lru.put(5,5);
    lru.print();//5 8 1

    lru.put(2,2);
    lru.print();//2 5 1

    lru.put(1,11);
    lru.print();//11 2 5

    lru.get(1);//11 2 5
    lru.put(2,22);//22 11 5
    lru.print();

    lru.put(3,3);
    lru.put(3,33);//33 22 11
    lru.put(9,99);//99 33 22
    lru.print();

    lru.put(7,7);//7 99 33
    lru.print();
    lru.put(7,77);//77 99 33
    lru.print();

    return 0;
}