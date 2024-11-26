#include "ShoppingList.h"
#include <iostream>

Item::Item(const std::string &itemName, int qty, double price)
    : name(itemName), quantity(qty), unitPrice(price) {}

std::string Item::getName() const { return name; }
int Item::getQuantity() const { return quantity; }
double Item::getUnitPrice() const { return unitPrice; }

void Item::setQuantity(int qty) { quantity = qty; }
void Item::setUnitPrice(double price) { unitPrice = price; }
double Item::getTotalPrice() const { return quantity * unitPrice; }

ShoppingCart::ShoppingCart() : totalPrice(0) {}

void ShoppingCart::addItem(const Item &item)
{
    items.push_back(item);
    updateTotalPrice();
}

void ShoppingCart::addCoupon(const std::string &coupon)
{
    coupons.push_back(coupon);
}

void ShoppingCart::applyPromotion()
{
    if (totalPrice >= 200000)
    {
        totalPrice *= 0.9; // Apply 10% discount
        addCoupon("10% Discount");
    }
}

void ShoppingCart::checkout() const
{
    std::cout << "Items in the cart:" << std::endl;
    for (const auto &item : items)
    {
        std::cout << item.getName() << " - Quantity: " << item.getQuantity()
                  << ", Unit Price: " << item.getUnitPrice()
                  << ", Total Price: " << item.getTotalPrice() << std::endl;
    }
    std::cout << "Total Price: " << totalPrice << std::endl;
    std::cout << "Coupons applied: ";
    for (const auto &coupon : coupons)
    {
        std::cout << coupon << " ";
    }
    std::cout << std::endl;
}

double ShoppingCart::getTotalPrice() const { return totalPrice; }

void ShoppingCart::updateTotalPrice()
{
    totalPrice = 0;
    for (const auto &item : items)
    {
        totalPrice += item.getTotalPrice();
    }
}

const std::vector<Item> &ShoppingCart::getItems() const { return items; }
const std::vector<std::string> &ShoppingCart::getCoupons() const { return coupons; }
