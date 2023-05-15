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
        Node* nd = new Node; //����������� ������� ����� ����
        nd->data = ID;        //������ ���� ������
        nd->next = NULL;     //����� ���� � �����, ������� NULL
        if (head == NULL)     //���� ������� ������ ����
            head = nd;
        else                 //���� ���� ��� �� ������
        {
            Node* current = head;
            //���� � ����� �������������� ���������� ����
            while (current->next != NULL)
                current = current->next;
            //�������������� ��������� �� ���������
            current->next = nd;
        }
    }
    //�����, ��������� ��������� ������ �� �����
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