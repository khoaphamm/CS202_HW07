#include "ShoppingList.h"
#include <iostream>
#include <fstream>
#include <string>

// Function to load items from a file into the shopping cart
void loadItemsFromFile(const std::string &filename, ShoppingCart &cart)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string name;
    int quantity;
    double unitPrice;

    while (file >> name >> quantity >> unitPrice)
    {
        Item item(name, quantity, unitPrice);
        cart.addItem(item);
    }
    file.close();
}

// Function to save the order details to a file
void saveOrderToFile(const std::string &filename, const ShoppingCart &cart)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to write to file " << filename << std::endl;
        return;
    }

    file << "Items in the cart:\n";
    for (const auto &item : cart.getItems())
    {
        file << item.getName() << " - Quantity: " << item.getQuantity()
             << ", Unit Price: " << item.getUnitPrice()
             << ", Total Price: " << item.getTotalPrice() << '\n';
    }

    file << "Total Price: " << cart.getTotalPrice() << "\n";
    file << "Coupons applied: ";
    for (const auto &coupon : cart.getCoupons())
    {
        file << coupon << " ";
    }
    file << "\n";
    file.close();
}

int main()
{
    ShoppingCart cart;

    // Load items from file
    loadItemsFromFile("products.txt", cart);

    // Apply promotion
    cart.applyPromotion();

    // Checkout and display details
    cart.checkout();

    // Save order to file
    saveOrderToFile("order_summary.txt", cart);

    return 0;
}
