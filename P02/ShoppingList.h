#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <string>
#include <vector>

class Item
{
private:
    std::string name;
    int quantity;
    double unitPrice;

public:
    Item(const std::string &itemName, int qty, double price);

    std::string getName() const;
    int getQuantity() const;
    double getUnitPrice() const;

    void setQuantity(int qty);
    void setUnitPrice(double price);

    double getTotalPrice() const;
};

class ShoppingCart
{
private:
    std::vector<Item> items;
    std::vector<std::string> coupons;
    double totalPrice;

    void updateTotalPrice();

public:
    ShoppingCart();

    void addItem(const Item &item);
    void addCoupon(const std::string &coupon);
    void applyPromotion(); // New method for promotion
    void checkout() const;
    double getTotalPrice() const;
    const std::vector<Item> &getItems() const;
    const std::vector<std::string> &getCoupons() const;
};

#endif // SHOPPINGLIST_H
