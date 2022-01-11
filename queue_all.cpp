#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct Queue {
    Node* pbeg, *pend;
    int size;
};

void printList(Queue Q);
void addToEndList1(Queue &Q, int x);
void deleteAllList(Queue *Q);
int pop(Queue &Q);

int main(int argc, char** argv)
{
    Queue Q;
    Q.pbeg = Q.pend = NULL;
    Q.size = 0;

    int x;
    std::string tmp;

    do
    {
        std::cin >> tmp;
        if(tmp == "size")
        {
            std::cout << Q.size << std::endl;
        }
        else if(tmp == "exit")
        {
            std::cout << "bye" << std::endl;
            deleteAllList(&Q);
            break;
        }
        else if(tmp == "push")
        {
            std::cin >> x;
            addToEndList1(Q, x);
            std::cout << "ok" << std::endl;
        }
        else if(tmp == "pop")
        {
            if(Q.pbeg == NULL)
                std::cout << "error" << std::endl;
            else
                std::cout << pop(Q) << std::endl;
        }
        else if(tmp == "front")
        {
            if(Q.pbeg == NULL)
                std::cout << "error" << std::endl;
            else
                std::cout << Q.pbeg->data << std::endl;
        }
        else if(tmp == "clear")
        {
            deleteAllList(&Q);
            std::cout << "ok" << std::endl;
        }
        //printList(Q);
    }
    while(1);

    return 0;
}

void addToEndList1(Queue &Q, int x)
{
    if(Q.pbeg == NULL)
    {
        Q.pbeg = new Node;
        Q.pend = Q.pbeg;
        Q.pbeg->data = x;
        Q.pbeg->next = NULL;
        Q.pend->next = NULL;
    }
    else
    {
        Q.pend->next = new Node;
        Q.pend->next->prev = Q.pend;
        Q.pend = Q.pend->next;
        Q.pend->next = NULL;
        Q.pend->data = x;
    }
    Q.size++;
}

int pop(Queue &Q)
{
    Node* tmp = Q.pbeg;
    int d = tmp->data;
    if(Q.pbeg->next == NULL)
         Q.pbeg = Q.pend = NULL;
    else
    {
        tmp->next->prev = NULL;
        Q.pbeg = Q.pbeg->next;
    }

    delete tmp;
    Q.size--;
    return d;
}

void printList(Queue Q)
{
    while(Q.pbeg != NULL)
    {
        std::cout << Q.pbeg->data << " -> ";
        Q.pbeg = Q.pbeg->next;
    }
    std::cout << "NULL" << std::endl << std::endl;
}

void deleteAllList(Queue *pQ)
{
    while(pQ->pbeg != NULL)
    {
        pop(*pQ);
    }
}
