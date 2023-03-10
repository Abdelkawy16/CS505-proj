#include <iostream>
#include <cstdlib>
#include "../Data.Structures/Queue.h"
#include "../Data.Structures/Queue.cpp"
#include "../Data.Structures/Stack.h"
#include "../Data.Structures/Stack.cpp"
#include "../Models/Customer.h"
#include "../Models/Meal.cpp"
#include "Helper.cpp"

using namespace std;
static int chooseCommands(string cmds[], int size, string message)
{
    int cmdIndex = -1;
    cout << message << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i+1 <<". " << cmds[i] << endl;
    }
    cin >> cmdIndex;

    return cmdIndex;
}
static void addCustomer(Queue& _customers, Stack& _logs)
{
    string name = "";
    cout << "please enter customer name: ";
    cin >> name;
    Customer* _cust = new Customer(name);
    _logs.push();
    _customers.enqueue(_cust);
    string cmd[] = { "Add order", "Show orders", "back" };
    int cmdIndex = chooseCommands(cmd, 3, "Please enter command:");
    while (cmdIndex != 3)
    {
        switch (cmdIndex)
        {
        case 1:
            cmdIndex = chooseCommands(MealString, 4, "choose meal number: ");
            if(cmdIndex > 0 && cmdIndex <= 4)
                _cust->addOrder((Meal)(cmdIndex - 1));
            else
                cout << "meal is not found!\n";
            break;
        case 2:
            cout << _cust->getName() << " orderd: ";
            _cust->getOrders();
            break;
        default:
            cout << "Invalid input!\n";
            break;
        };
        cmdIndex = chooseCommands(cmd, 3, "Please enter command:");
    }
}
static void serveCustomer(Queue& _customers, Stack& _logs)
{
    if (_customers.queueIsEmpty())
        cout << "There is no customer to serve\n";
    else
        cout << _customers.dequeue()->getName() + " is served successfully!\n";
}
int main()
{
    Queue* _customers = new Queue;
    Stack *logs = new Stack;
    /*logs.push("Restaurant opened");
    Customer* ahmed = new Customer("Ahmed");
    ahmed->addOrder(Meal::Burger);
    ahmed->addOrder(Meal::Crepe);
    ahmed->addOrder(Meal::Liver);
    ahmed->getOrders();
    _customers->enqueue(ahmed);
    _customers->enqueue(new Customer("Ali"));*/
    string cmd[] = { "Add Customer" , "Serve Customer", "Show Logs", "Exit"};
    int cmdIndex = chooseCommands(cmd, 4, "Please enter command:");
    while (cmdIndex != 4)
    {
        switch (cmdIndex)
        {
        case 1:
            addCustomer(*_customers, *logs);
            break;
        case 2:
            serveCustomer(*_customers, *logs);
            break;
        case 3:
            logs->display();
            break;
        default:
            cout << "Invalid input!\n";
            break;
        };
        cout << "=============\n";
        cmdIndex = chooseCommands(cmd, 4, "Please enter command:");
    }
    exit(0);
    /*auto t = time(nullptr);
    auto tm = *localtime(&t);
    cout << put_time(&tm, "%d-%m-%Y %H-%M-%S");*/
}
