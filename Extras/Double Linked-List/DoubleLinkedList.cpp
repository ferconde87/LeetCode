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
            }else{
                node->next = head;
                head->prev = node;
            }
            head = node;
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

        Node * deleteLast(){
            if(size == 0) return NULL;
            Node * nodeDelete = tail;
            deleteNode(nodeDelete);
            return nodeDelete;
        }

};


int main(){
    Node * node1 = new Node(1,1);
    Node * node2 = new Node(2,2);  
    Node * node3 = new Node(3,3);
    Node * node4 = new Node(4,4);
    
    DoubleLinkedList ddl;
    ddl.addFirst(node1);
    ddl.addFirst(node2);
    ddl.addFirst(node3);
    ddl.addFirst(node4);

    ddl.print();//4 3 2 1

    ddl.deleteNode(node3);

    ddl.print();//4 2 1

    ddl.deleteNode(node1);

    ddl.print();//4 2

    Node * node5 = new Node(5,5);
    ddl.addFirst(node5);
    ddl.print();//5 4 2;

    Node* lastNode;
    lastNode = ddl.deleteLast();
    cout << lastNode->value << endl;//2
    ddl.print();//5 4
    ddl.printBackward();//4 5

    ddl.deleteNode(node4);
    ddl.print();

    ddl.deleteNode(node5);
    ddl.print();

    ddl.deleteNode(node5);
    ddl.print();//4 2
    ddl.printBackward();//2 4

    ddl.deleteNode(node2);
    ddl.print();//4
    ddl.printBackward();//4


    Node * node6 = new Node(6);
    ddl.addFirst(node6);
    ddl.print();//6 4
    ddl.printBackward();//4 6

    ddl.deleteNode(node4);
    ddl.print();//6
    ddl.printBackward();//6

    ddl.deleteNode(node6);

    ddl.print();//
    ddl.printBackward();//

    return 0;
}
