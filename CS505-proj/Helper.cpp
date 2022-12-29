#include "../Data.Structures/Queue.cpp"
#include <iostream>
using namespace std;

namespace Helper {
    static int chooseCommands(string cmds[], int size)
    {
        int cmdIndex = -1;
        cout << "Please choose command: \n";
        for (int i = 0; i < size; i++)
        {
            cout << cmds[i] << endl;
        }

        cin >> cmdIndex;

        return cmdIndex;
    }
    static void addCustomer(Queue* _customers) 
    {
        string name = "";
        cout << "please enter customer name: ";
        cin >> name;
        Customer* _cust = new Customer(name);
        _customers->enqueue(_cust);
    }
    static void serveCustomer(Queue* _customers) 
    {
        if (_customers->queueIsEmpty())
            cout << "There is no customer to serve";
        else
            cout<< _customers->dequeue()->getName() +" is served successfully!";
    }
}
