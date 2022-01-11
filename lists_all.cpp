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

    ///Вводим размер списка
    //std::cout << "How many elements: ";
    //std::cin >> n;
    //std::cout << std::endl;

    //Вводим список
    //createList(pbeg, n);
    testingList(pbeg);
    printList(pbeg);

    ///Реализуем добавление в середину (можно и в конец) списка
    std::cout << "Place to add and what: ";
    std::cin >> place >> x;
    //Проверка на плохие данные + добавление
    if(!addToList(pbeg, place, x)) std::cout << "Incorrect place for adding" << std::endl;
    printList(pbeg);

    ///Проверяем работу функции при добавлении в начало
    std::cout << "What add to list begin: ";
    std::cin >> x;
    std::cout << std::endl;
    addToList(pbeg, 0, x);
    printList(pbeg);

    ///Проверяем удаление из списка
    std::cout << "Which place to clear: ";
    std::cin >> place;
    if(!deleteFromList(pbeg, place)) std::cout << "Incorrect place for clearing" << std::endl;
    std::cout << std::endl;
    printList(pbeg);

    ///Проверяем возврат значения ноды
    int result = 0;
    std::cout << "Which node data you want to see: ";
    std::cin >> place;
    std::cout << std::endl;
    if(!returnData(pbeg, place, result)) std::cout << "Wrong place" << std::endl;
    else std::cout << result << std::endl;


    ///Очистка памяти
    deleteAllList(pbeg);
    printList(pbeg);

    return 0;
}

///Функция добавления в конец списка (так удобнее)
void addToEndList(Node*& pbeg, int x)
{
    ///Проверяем на пустой список
    if(pbeg == NULL)
    {   ///Добавляем ноду в пустой список
        pbeg = new Node;
        pbeg->data = x;
        pbeg->next = NULL;
        pbeg->prev = NULL;
    }
    else
    {   ///Ищем конец и добавляем туда
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
    if(pbeg == NULL) ///Проверяем на пустой список
    {
        if(place) return false; ///Если место вне пустого списка (place > 0)
        else addToEndList(pbeg, x);
    }
    else
    {
        if(place == 0) ///Добавление в начало списка
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
            for(int i = 0; i < place - 1; i++) ///Находим место
            {
                if(tmp->next == NULL) return false; ///Если данное место вне диапозона списка
                else tmp = tmp->next;
            }
            Node* newNode = new Node;
            newNode->data = x;
            if(tmp->next == NULL)
            {   ///Добавляем элемент в конец списка
                newNode->next = NULL;
                newNode->prev = tmp;
                tmp->next = newNode;
            }
            else
            {   ///Добавляем элемент на место place
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

    if(place == 0) ///Если нулевой элемент
    {
        if(pbeg == NULL) return true; ///Если пустой список
        pbeg = pbeg->next;
        tmp->next->prev = NULL;
    }
    else
    {
        for(int i = 0; i < place; i++) ///Идем до place ноды
        {
            if(tmp->next == NULL) return false; ///Если данное место вне диапозона списка
            else tmp = tmp->next;
        }
        if (tmp->next == NULL) ///Если удаляем последнюю ноду
        {
            tmp->prev->next = NULL;
        }
        else
        {   ///Удаление элемента в середине
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

///Функция для отладки
void testingList(Node*& pbeg)
{
    addToEndList(pbeg, 0);
    addToEndList(pbeg, 1);
    addToEndList(pbeg, 2);
    addToEndList(pbeg, 3);
    addToEndList(pbeg, 4);
    addToEndList(pbeg, 5);
}

///Возврат значения произвольной ноды
bool returnData(Node*& pbeg, unsigned int place, int &result)
{
    Node* tmp = pbeg;
    for(int i = 0; i < place; i++) ///Идем до place ноды
    {
        if(tmp->next == NULL) return false; ///Если данное место вне диапозона списка
        else tmp = tmp->next;
    }
    result = tmp->data;

    return true;
}
