#include <vector>
#include <stdexcept>
#include <iostream>
int nthLowestSelling(const std::vector<int>& sales, int n) 
{
    throw std::logic_error("Waiting to be implemented");
}

#ifndef RunTests
int main()
{
    std::vector<int> input;
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(5);
    input.push_back(4);
    input.push_back(5);
    int x = nthLowestSelling(input, 2);
    std::cout << x;
}
#endif

/*
Write a method that, efficiently with respect to time used, finds the n-th lowest selling book in the list.
Each element of the sales array represents a single sale of a book with that book's id. The n-th lowest selling
book is the book that has more sales than n-1 books. Assume that book sales counts are unique.
For example, nthLowestSelling({ 5, 4, 3, 2, 1, 5, 4, 3, 2, 5, 4, 3, 5, 4, 5 }, 2) should return 2.
In the array, the book with the id 1 was sold once, id 2 twice, id 3 three times, id 4 four times, and id 5 five times,
making the book with the id 1 the lowest selling book in the array and id 2 the second lowest selling book.
Test case: 
Example case: 
Additional list elements: 
Performance test with a large number of elements: 
*/