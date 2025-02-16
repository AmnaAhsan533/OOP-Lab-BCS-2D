#include<iostream>
#include<vector>
#include<string>
using namespace std;

class MenuItem{
    public:
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p): name(n), type(t), price(p){}
};

class CoffeeShop{
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

    public:
    CoffeeShop(string shopName, vector<MenuItem> items): name(shopName), menu(items){}
    string addOrder(string itemName){
        for(const auto& item : menu){
            if(item.name == itemName){
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }  
        return "This item is currently unavailable";  
    }
    string fulfillOrder(){
        if(!orders.empty()){
            string fulfilledItem = orders.front();
            orders.erase(orders.begin());
            return "The " + fulfilledItem + " is ready";
        } return "All orders have been fulfilled";
    }
    vector<string> listOrders(){
        return orders;
    }
    double dueAmount(){
        double total = 0.0;
        for(const auto &order: orders){
            for(const auto &item: menu){
                if(item.name == order){
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }
    string cheapestItem(){
        if(menu.empty()) return "No items on menu";
        MenuItem cheapest = menu[0];
        for(const auto &item: menu){
            if(item.price < cheapest.price){
                cheapest = item;
            }
        } return cheapest.name;
    }
    vector<string> drinksOnly(){
        vector<string> drinks;
        for(const auto &item : menu){
            if(item.type == "drink"){
                drinks.push_back(item.name);
            }
        } return drinks;
    }
    vector<string> foodOnly(){
        vector<string> foods;
        for(const auto &item : menu){
            if(item.type == "food"){
                foods.push_back(item.name);
            }
        } return foods;
    }
};

int main(){
    vector<MenuItem> menu = {
        {"Espresso", "drink", 3.0},
        {"Cappuccino", "drink", 3.5},
        {"Latte", "drink", 4.0},
        {"Sandwich", "food", 5.5},
        {"Pasta", "food", 2.5}
    };
    CoffeeShop myShop("Debug Cafe", menu);

    cout<<myShop.addOrder("Espresso")<<endl;
    cout<<myShop.addOrder("Sandwich")<<endl;
    cout<<myShop.fulfillOrder()<<endl;

    vector<string> currentOrders = myShop.listOrders();
    cout<<"Current Orders: ";
    for(const auto &order: currentOrders){
        cout<<order<<", ";
    }cout<<endl;

    cout<<"Total due: "<<myShop.dueAmount()<<endl;
    cout<<"Cheapest item: "<<myShop.cheapestItem()<<endl;

    return 0;
}