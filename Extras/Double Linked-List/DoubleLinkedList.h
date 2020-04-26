#include <iostream>

using namespace std;

class Node{
    public:
        int key;
        int value;
        Node * next;
        Node * prev;
        
        Node(int k, int val){
            key = k;
            value = val;
        }
};

class DoubleLinkedList{
	Node * head;
	Node * tail;
	int size = 0;

    public:
        void addFirst(Node * node){
            if(isEmpty()) {
                tail = node;
                tail->next = NULL;
            }else{
                node->next = head;
                head->prev = node;
            }
            head = node;
            node->prev = NULL;
            size++;
        }

        void deleteNode(Node * node){
            if(isEmpty()){
                cout << "there is no element in the list" << endl;
                return;
            }

            if(getSize() == 1){
                head = NULL;
                tail = NULL;
            }else{
                if(node->next != NULL){
                    node->next->prev = node->prev;
                }else{
                    tail = node->prev;
                } 
                if(node->prev != NULL){
                    node->prev->next = node->next;
                }else{
                    head = node->next;
                }
            }
            size--;
        }

        Node * deleteLast(){
            if(size == 0) return NULL;
            Node * nodeDelete = tail;
            deleteNode(nodeDelete);
            return nodeDelete;
        }

        bool isEmpty(){
            return size == 0;
        }

        int getSize(){
            return size;
        }

        void print(){
            Node * node = head;
            while(node != NULL){
                cout << node->value << " ";
                node = node->next;
            }
            cout << endl;
        }

        void printBackward(){
            Node * node = tail;
            while(node != NULL){
                cout << node->value << " ";
                node = node->prev;
            }
            cout << endl;
        }
};