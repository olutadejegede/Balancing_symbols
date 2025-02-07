#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//---------------------------//
// Stack Class               //
//---------------------------//

class Stack
{
public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    char Top() const;
    void AddFront(char item);
    char RemoveFront();
    void Balance(string symbols);

protected:
private:
    struct Stack_Node
    {
        char data;
        Stack_Node *next;
    };
    typedef Stack_Node *Stack_ptr;

    Stack_ptr Tos;
};

//---------------------------//
// Stack Functions           //
//---------------------------//

Stack::Stack()
{
    Tos = nullptr;
}

Stack::~Stack()
{
    while (!isEmpty())
        RemoveFront();
}

bool Stack::isEmpty() const
{
    return Tos == nullptr;
}

bool Stack::isFull() const
{                 //----------------------------------------//
    return false; // Although LinkedList will never be full //
} //----------------------------------------//

char Stack::Top() const
{
    if (!this->isEmpty())
        return Tos->data;
    else
    {
        cout << "ERROR: Stack is Empty!" << endl;
        return '\0';
    }
}

void Stack::AddFront(char item)
{
    if (!this->isFull())
    {
        Stack_ptr new_node = new Stack_Node;
        new_node->data = item;
        new_node->next = Tos;
        Tos = new_node;
    }
    else
        cout << "ERROR: Stack is Full!" << endl;
}

char Stack::RemoveFront()
{
    if (!this->isEmpty())
    {
        Stack_ptr temp = Tos;
        char deleted_char = Tos->data;
        Tos = Tos->next;
        delete temp;
        return deleted_char;
    }
    else
    {
        cout << "ERROR: Stack is Empty!" << endl;
        return '\0';
    }
}

void Stack::Balance(string symbols)
{
    int len = symbols.length();
    bool isValid = true;
    for (int i = 0; i < len; ++i)
    {
        if (symbols[i] == '(' || symbols[i] == '[' || symbols[i] == '{')
        {
            AddFront(symbols[i]);
        }
        if (symbols[i] == ')' || symbols[i] == ']' || symbols[i] == '}')
        {
            if (this->isEmpty())
            {
                cout << "ERROR: List is empty!" << endl;
                isValid = false;
            }
            else
            {
                char front = Top();
                if (symbols[i] == ')' && front == '(' || symbols[i] == ']' && front == '[' || symbols[i] == '}' && front == '{')
                    RemoveFront();
                else
                {
                    cout << "ERROR: Symbol Does Not Correspond!" << endl;
                    isValid = false;
                }
            }
        }
    }
    if (this->isEmpty() && isValid)
        cout << "Symbols are Legal!" << endl;
    else
        cout << "ERROR: Symbols are not valid!" << endl;
}

//---------------------------//
// Main Function             //
//---------------------------//

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "ERROR: No file found!" << endl;
        return -1;
    }
    else
    {
        ifstream filename(argv[1]);
        string input;
        Stack stack;
        if (filename.is_open())
            while (getline(filename, input))
            {
                stack.Balance(input);
            }
        else
        {
            cout << "ERROR: Unable to open file!" << endl;
            return -1;
        }

        filename.close();
        return 0;
    }
}