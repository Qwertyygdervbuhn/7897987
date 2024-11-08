#include <iostream>
using namespace std;

template <typename T>
class ForwardList {
private:
    class Node { 
    public:
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    ForwardList() : head(nullptr) {}

    ~ForwardList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ForwardList(const ForwardList<T>& other) : head(nullptr) {
        Node* temp = other.head;
        while (temp) {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    ForwardList<T>& operator=(const ForwardList<T>& other) {
        if (this != &other) {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            Node* temp = other.head;
            while (temp) {
                push_back(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    ForwardList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    cout << "List 1: ";
    list1.print();

    ForwardList<int> list2 = list1;
    cout << "List 2: ";
    list2.print();

    ForwardList<int> list3;
    list3 = list1;
    cout << "List 3: ";
    list3.print();

 
}
