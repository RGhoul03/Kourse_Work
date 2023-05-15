#include <iostream>

using namespace std;

struct Node{
    string data;
    Node* next;
};

class List{
private:
    Node* head;
public:
    List(){
        head = NULL;
    }
    
    void addNode(string ID)
    {
        Node* nd = new Node; //динамически создаем новый узел
        nd->data = ID;        //задаем узлу данные
        nd->next = NULL;     //новый узел в конце, поэтому NULL
        if (head == NULL)     //если создаем первый узел
            head = nd;
        else                 //если узел уже не первый
        {
            Node* current = head;
            //ищем в цикле предшествующий последнему узел
            while (current->next != NULL)
                current = current->next;
            //предшествующий указывает на последний
            current->next = nd;
        }
    }
    //метод, выводящий связанный список на экран
    void printList()
    {
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    bool find_item(string ID) {
        Node* current = head;
        while (current != NULL)
        {
            if (ID == current->data) { return true; break; }

            current = current->next;
        }
        return false;
    }
};