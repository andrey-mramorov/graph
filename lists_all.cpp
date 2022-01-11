#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void createList(Node*& pbeg, unsigned int n);
void printList(Node* p);
void testingList(Node*& pbeg);
void addToEndList(Node*& pbeg, int x);
bool addToList(Node*& pbeg, unsigned int place, int x);
bool deleteFromList(Node*& pbeg, unsigned int place);
bool returnData(Node*& pbeg, unsigned int place, int &result);
void deleteAllList(Node*& pbeg);

int main(int argc, char** argv)
{
    Node* pbeg = NULL;

    int n, x, place;

    ///������ ������ ������
    //std::cout << "How many elements: ";
    //std::cin >> n;
    //std::cout << std::endl;

    //������ ������
    //createList(pbeg, n);
    testingList(pbeg);
    printList(pbeg);

    ///��������� ���������� � �������� (����� � � �����) ������
    std::cout << "Place to add and what: ";
    std::cin >> place >> x;
    //�������� �� ������ ������ + ����������
    if(!addToList(pbeg, place, x)) std::cout << "Incorrect place for adding" << std::endl;
    printList(pbeg);

    ///��������� ������ ������� ��� ���������� � ������
    std::cout << "What add to list begin: ";
    std::cin >> x;
    std::cout << std::endl;
    addToList(pbeg, 0, x);
    printList(pbeg);

    ///��������� �������� �� ������
    std::cout << "Which place to clear: ";
    std::cin >> place;
    if(!deleteFromList(pbeg, place)) std::cout << "Incorrect place for clearing" << std::endl;
    std::cout << std::endl;
    printList(pbeg);

    ///��������� ������� �������� ����
    int result = 0;
    std::cout << "Which node data you want to see: ";
    std::cin >> place;
    std::cout << std::endl;
    if(!returnData(pbeg, place, result)) std::cout << "Wrong place" << std::endl;
    else std::cout << result << std::endl;


    ///������� ������
    deleteAllList(pbeg);
    printList(pbeg);

    return 0;
}

///������� ���������� � ����� ������ (��� �������)
void addToEndList(Node*& pbeg, int x)
{
    ///��������� �� ������ ������
    if(pbeg == NULL)
    {   ///��������� ���� � ������ ������
        pbeg = new Node;
        pbeg->data = x;
        pbeg->next = NULL;
        pbeg->prev = NULL;
    }
    else
    {   ///���� ����� � ��������� ����
        Node* tmp = pbeg;
        while(tmp->next != NULL)
            tmp = tmp->next;
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = tmp;
        tmp->next = newNode;
    }
}

void printList(Node* p)
{
    while(p != NULL)
    {
        std::cout << p -> data << " -> ";
        p = p -> next;
    }
    std::cout << "NULL" << std::endl << std::endl;
}

bool addToList(Node*& pbeg, unsigned int place, int x)
{
    if(pbeg == NULL) ///��������� �� ������ ������
    {
        if(place) return false; ///���� ����� ��� ������� ������ (place > 0)
        else addToEndList(pbeg, x);
    }
    else
    {
        if(place == 0) ///���������� � ������ ������
        {
            Node* newNode = new Node;
            newNode->next = pbeg;
            newNode->prev = NULL;
            newNode->data = x;
            pbeg->prev = newNode;
            pbeg = newNode;
        }
        else
        {
            Node* tmp = pbeg;
            for(int i = 0; i < place - 1; i++) ///������� �����
            {
                if(tmp->next == NULL) return false; ///���� ������ ����� ��� ��������� ������
                else tmp = tmp->next;
            }
            Node* newNode = new Node;
            newNode->data = x;
            if(tmp->next == NULL)
            {   ///��������� ������� � ����� ������
                newNode->next = NULL;
                newNode->prev = tmp;
                tmp->next = newNode;
            }
            else
            {   ///��������� ������� �� ����� place
                newNode->next = tmp->next;
                newNode->prev = tmp;
                tmp->next = newNode;
                newNode->next->prev = newNode;
            }
        }
    }
    return true;
}

bool deleteFromList(Node*& pbeg, unsigned int place)
{
    Node* tmp = pbeg;

    if(place == 0) ///���� ������� �������
    {
        if(pbeg == NULL) return true; ///���� ������ ������
        pbeg = pbeg->next;
        tmp->next->prev = NULL;
    }
    else
    {
        for(int i = 0; i < place; i++) ///���� �� place ����
        {
            if(tmp->next == NULL) return false; ///���� ������ ����� ��� ��������� ������
            else tmp = tmp->next;
        }
        if (tmp->next == NULL) ///���� ������� ��������� ����
        {
            tmp->prev->next = NULL;
        }
        else
        {   ///�������� �������� � ��������
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
    }
    delete tmp;

    return true;
}

void deleteAllList(Node*& pbeg)
{
    Node* tmp = pbeg;
    Node* Next = pbeg->next;
    while(tmp->next != NULL)
    {
        delete tmp;
        tmp = Next;
        Next = Next->next;
    }
    pbeg = NULL;
}

void createList(Node*& pbeg, unsigned int n)
{
    int x;
    for(int i = 0; i < n; i++)
    {
        std::cin >> x;
        addToEndList(pbeg, x);
    }
}

///������� ��� �������
void testingList(Node*& pbeg)
{
    addToEndList(pbeg, 0);
    addToEndList(pbeg, 1);
    addToEndList(pbeg, 2);
    addToEndList(pbeg, 3);
    addToEndList(pbeg, 4);
    addToEndList(pbeg, 5);
}

///������� �������� ������������ ����
bool returnData(Node*& pbeg, unsigned int place, int &result)
{
    Node* tmp = pbeg;
    for(int i = 0; i < place; i++) ///���� �� place ����
    {
        if(tmp->next == NULL) return false; ///���� ������ ����� ��� ��������� ������
        else tmp = tmp->next;
    }
    result = tmp->data;

    return true;
}
