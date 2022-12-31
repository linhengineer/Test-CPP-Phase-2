#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
int minPieces(const std::vector<int>& original, const std::vector<int>& desired) {
    //throw std::logic_error("Waiting to be implemented");
    std:: size_t local = original.size() + 1;
    std::size_t slice = 0 ;
    for (std::size_t m = 0 ; m < original.size() ; m++) {
        for (std::size_t n = 0 ; n < desired.size() ; n++) {
            if (original[m] == desired[n]) {
                if (( n - local ) == 1) {
                    local = n;
                }
                else {
                    local = n;
                    slice++;
                }
                break;
            }
        }
    }
    return slice;
}

#ifndef RunTests
int main() {
    std::vector<int> original = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> desired = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    std::cout << minPieces(original, desired) << std::endl;
}
#endif

/*
You are given two paper strips. On each strip, all numbers in the range [1, 2, ... N] are written in random order and no number is repeated. Cut the original paper strip into several pieces and rearrange those pieces to form the desired sequence.
Write a function that, efficiently with respect to time used, returns the minimum number of cut pieces needed to perform the described operation.
For example, the following code should display 3 because the pieces used should be (1), (4, 3), and (2):
std::vector<int> original = { 1, 4, 3, 2 }; 
std::vector<int> desired = { 1, 2, 4, 3 }; 
std::cout << PaperStrip::minPieces(original, desired) << std::endl;

Starting Coding:
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
int minPieces(const std::vector<int>& original, const std::vector<int>& desired)
{
    throw std::logic_error("Waiting to be implemented");
}

#ifndef RunTests
int main()
{
    std::vector<int> original = { 1, 4, 3, 2 };
    std::vector<int> desired = { 1, 2, 4, 3 };
    std::cout << minPieces(original, desired) << std::endl;
}
#endif

Test case: 
Example case: 
10 elements: 
Performance test with a large paper strip: 

*/
