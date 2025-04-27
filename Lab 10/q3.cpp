#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct User{
    string user_id;
    string first_name;
};

struct Product {
    string product_id;
    string product_name;
};

vector<User> loadUsers() {
    vector<User> users;
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string user_id, first_name, last_name, address, email;
        getline(ss, user_id, ',');
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, address, ',');
        getline(ss, email, ',');

        users.push_back({user_id, first_name});
    }
    return users;
}

vector<Product> loadProducts() {
    vector<Product> products;
    ifstream file("products.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string product_id, product_name, description, price;
        getline(ss, product_id, ',');
        getline(ss, product_name, ',');
        getline(ss, description, ',');
        getline(ss, price, ',');

        products.push_back({product_id, product_name});
    }
    return products;
}

vector<string> findProductsForUser(const string& userName, const vector<User>& users, const vector<Product>& products) {
    vector<string> result;
    ifstream file("orders.txt");
    string line;
    string targetUserId = "";

    // First, find the user_id for the given userName
    for (const auto& user : users) {
        if (user.first_name == userName) {
            targetUserId = user.user_id;
            break;
        }
    }

    if (targetUserId == "") {
        cout << "User not found." << endl;
        return result;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string order_id, user_id, product_ordered, total_paid;
        getline(ss, order_id, ',');
        getline(ss, user_id, ',');
        getline(ss, product_ordered, ',');
        getline(ss, total_paid, ',');

        if (user_id == targetUserId) {
            // Find the product name for this product_ordered
            for (const auto& product : products) {
                if (product.product_id == product_ordered) {
                    result.push_back(product.product_name);
                    break;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<User> users = loadUsers();
    vector<Product> products = loadProducts();
    string targetUser = "Linus";

    vector<string> productsForUser = findProductsForUser(targetUser, users, products);

    cout << "Products ordered by " << targetUser << ":" << endl;
    for (const auto& product : productsForUser) {
        cout << "- " << product << endl;
    }

    return 0;
}
