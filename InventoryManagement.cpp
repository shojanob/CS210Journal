/*

Shokhrukh Janobilov 8/25/2024

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
public:
    int id;
    string name;
    int quantity;
    double price;

    Item(int id, string name, int quantity, double price) {
        this->id = id;
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }
};

class Inventory {
private:
    vector<Item> items;
    int nextId;

public:
    Inventory() : nextId(1) {}

    void addItem() {
        string name;
        int quantity;
        double price;

        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter item quantity: ";
        cin >> quantity;
        cout << "Enter item price: ";
        cin >> price;

        items.push_back(Item(nextId, name, quantity, price));
        cout << "Item added with ID: " << nextId << endl;
        nextId++;
    }

    void viewItems() {
        if (items.empty()) {
            cout << "No items in inventory." << endl;
            return;
        }

        cout << "ID\tName\t\tQuantity\tPrice" << endl;
        for (const auto& item : items) {
            cout << item.id << "\t" << item.name << "\t\t" << item.quantity << "\t\t" << item.price << endl;
        }
    }

    void updateItem() {
        int id;
        cout << "Enter the ID of the item to update: ";
        cin >> id;

        for (auto& item : items) {
            if (item.id == id) {
                cout << "Updating item: " << item.name << endl;
                cout << "Enter new quantity: ";
                cin >> item.quantity;
                cout << "Enter new price: ";
                cin >> item.price;
                cout << "Item updated." << endl;
                return;
            }
        }

        cout << "Item with ID " << id << " not found." << endl;
    }

    void deleteItem() {
        int id;
        cout << "Enter the ID of the item to delete: ";
        cin >> id;

        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->id == id) {
                cout << "Deleting item: " << it->name << endl;
                items.erase(it);
                cout << "Item deleted." << endl;
                return;
            }
        }

        cout << "Item with ID " << id << " not found." << endl;
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\nInventory Management System" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. View Items" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Delete Item" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.addItem();
                break;
            case 2:
                inventory.viewItems();
                break;
            case 3:
                inventory.updateItem();
                break;
            case 4:
                inventory.deleteItem();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
