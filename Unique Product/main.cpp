#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

std::string firstUniqueProduct( std::vector<std::string>& products)
{   // Tạo vector duy nhất
    for (std::size_t i = 0; i < products.size(); i++) {
        for (std::size_t j = i + 1; j < products.size(); j++) {
            if (products[i] == products[j]) {
                products.erase(products.begin() + i);
                products.erase(products.begin() + j);
            }
        }
    }
    //Check xem vector có rỗng không
    if (products.empty()){
        return "";
    }
    else
    return products[0]; // In ra sp đầu tiên
}

#ifndef RunTests
int main()
{
    std::vector<std::string> products = { "Apple", "Computer", "Apple", "Bag" };
    std::cout << firstUniqueProduct(products);
}
#endif

/*Write a method that, efficiently with respect to time used, finds the first product in a vector that occurs only once in that vector. If there are no unique products in the vector, an empty string should be returned.
For example, for vector products containing { "Apple", "Computer", "Apple", "Bag" }, firstUniqueProduct(products) should return "Computer".
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

std::string firstUniqueProduct(const std::vector<std::string>& products)
{
    throw std::logic_error("Waiting to be implemented");
}

#ifndef RunTests
int main()
{
    std::vector<std::string> products = { "Apple", "Computer", "Apple", "Bag" };
    std::cout << firstUniqueProduct(products);
}
#endif
*/