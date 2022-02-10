
#define maxOrders 100
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Dish
{
    string dishCode;
    string dishName;
    double price;
    int quantity;

public:
    Dish(string dishCode = "", string dishName = "", double price = 0.0, int quantity = 0)
    {
        this->dishCode = dishCode;
        this->dishName = dishName;
        this->price = price;
        this->quantity = quantity;
    }
    string getDishName()
    {
        return this->dishName;
    }

    int getQuantity()
    {
        return this->quantity;
    }

    double getPrice()
    {
        return this->price;
    }

    string getDishCode()
    {
        return this->dishCode;
    }
};

class Bill
{
    Dish *dishes;
    int numberOfDishes;
    string billName;

public:
    // static int billId;
    Bill(string billName, Dish *d, int numberOfDishes)
    {
        dishes = new Dish[numberOfDishes];
        for (int i = 0; i < numberOfDishes; i++)
        {
            dishes[i] = d[i];
        }
        this->numberOfDishes = numberOfDishes;
        // billId++;
        this->billName = billName;
    }
    // void printBill(){
    //     cout<<"Bill of "<<d.name <<""
    // }

    string getBillName()
    {
        return billName;
    }
    void generateBill()
    {
        // cout << "bill id: " << billId << endl;
        cout << "bill name: " << billName << endl;
        cout << "Dishes Ordered: " << endl;
        for (int i = 0; i < numberOfDishes; i++)
        {
            cout << "dish " << i + 1 << " : " << dishes[i].getDishName() << "--->" << dishes[i].getPrice() * dishes[i].getQuantity() << endl;
        }
    }
};
unordered_map<string, Dish> db;
unordered_map<int, Dish *> ordersDb;

void fillDb()
{
    int n;
    cout << "enter number of dishes available for today:\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string dishCode;
        string dishName;
        double price;
        cout << "enter " << i + 1 << "st dish details:\n";
        cout << "enter code for the dish:";
        cin >> dishCode;
        cout << "enter name for the dish:";
        cin.ignore();
        getline(cin, dishName);
        cout << "enter price for the dish:";
        cin >> price;
        db[dishCode] = Dish(dishCode, dishName, price);
    }
}

int main()
{
    // Bill::billId = 0;
    fillDb();
    cout << "-------------Now open for orders:-------------\n";
    int input;
    cout << "-press1 to add an order\n-press0 to exit\n";
    cout << "enter your choice: ";
    cin >> input;
    cout << endl;
    int counter=0;
    while (input)
    {
        switch (input)
        {
        
        case 1:
            string username;
            cout << "enter the username: ";
            cin.ignore();
            getline(cin, username);
            // Bill b();
            cout<<"enter number of dishes: ";
            int numberOfDishes;
            cin >> numberOfDishes; // no of dishes user want
            cout<<endl;
            Dish *listOfDishes = new Dish[numberOfDishes];
            for (int i = 0; i < numberOfDishes; i++)
            {
                string dishCode;

                int quantity;
                cout << "enter dishcode and quantity\n";
                cin.ignore();
                getline(cin, dishCode);
                Dish d = db[dishCode];
                string dishName = d.getDishName();
                double price = d.getPrice();

                cin >> quantity;
                // pushing into the orderesDb
                Dish temp = Dish(dishCode, dishName, price, quantity);
                listOfDishes[i] = temp;
            }

            ordersDb[counter++] = listOfDishes;
            Bill b(username, listOfDishes, numberOfDishes);
            cout << "generating the bill\n";
            b.generateBill();
            cout << endl;
            b.getBillName();
            cout << "-press1 to add an order\n-press0 to exit\n";
            cout << "enter your choice: ";
            cin>>input;
        }        
    }
}
