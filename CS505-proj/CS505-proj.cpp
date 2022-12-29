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

int main()
{
    Queue* _customers = new Queue;
    Stack logs;
    logs.push("Restaurant opened");
    Customer* ahmed = new Customer("Ahmed");
    ahmed->addOrder(Meal::Burger);
    ahmed->addOrder(Meal::Crepe);
    ahmed->addOrder(Meal::Liver);
    ahmed->getOrders();
    _customers->enqueue(ahmed);
    _customers->enqueue(new Customer("Ali"));
    string cmd[] = { "1. Add Customer" , "2. Serve Customer", "3. Exit" };
    int cmdIndex = Helper::chooseCommands(cmd, 3);
    while (cmdIndex != 3)
    {
        switch (cmdIndex)
        {
        case 1:
            Helper::addCustomer(_customers);
            break;
        case 2:
            Helper::serveCustomer(_customers);
            break;
        default:
            cout << "Invalid input!\n";
            break;
        };
        cmdIndex = Helper::chooseCommands(cmd, 3);
    }
    exit(0);
    /*auto t = time(nullptr);
    auto tm = *localtime(&t);
    cout << put_time(&tm, "%d-%m-%Y %H-%M-%S");*/
}
