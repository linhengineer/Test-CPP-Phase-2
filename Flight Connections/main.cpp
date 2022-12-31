#include <iostream>
#include <vector>


int getMinimumConnections(const std::vector<std::vector<bool>>& matrix) {
    //throw std::logic_error("Waiting to be implemented");
    std::vector<std::vector<std::size_t>> connections;
    std::vector<std::size_t> airport_connected;

    bool is_first = false;
    bool is_same = false;

    for (std::size_t x = 0 ; x < matrix.size() ; x++) {
        for (std::size_t y = 0 ; y < x ; y++) {
            if ( matrix[x][y] == true ) {
                airport_connected.push_back(x);
                airport_connected.push_back(y);
                if (!is_first) {
                    is_first = true;
                    connections.push_back({x, y});
                }
                else {
                    if (!is_same) {
                        for (std::size_t m = 0 ; m < connections.size() ; m++) {
                            for (std::size_t n = 0 ; n < connections[m].size() ; n++) {
                                if (x == connections[m][n]) {
                                    connections[m].push_back(y);
                                    is_same = true;
                                    break;
                                }
                                if (y == connections[m][n]) {
                                    connections[m].push_back(x);
                                    is_same = true;
                                    break;
                                }
                            }
                            break;
                        } 
                    }
                    if (!is_same) {
                        connections.push_back({x, y});
                        is_same = false;
                        break;
                    }
                    is_same = false;
                }
            }
        }
    }
    // Add airport not connect
    for (std::size_t i = 0 ; i < matrix.size() ; i++) {
        bool exist = false;
        for (auto vt : airport_connected) {
            if ( i == vt) {
                exist = true;
                break;
            }
        }
        if (!exist) {
            connections.push_back({i});
        }
        
    }
    return connections.size() - 1 ;
}

#ifndef RunTests

int main() {
    
    std::vector<std::vector<bool>> matrix {
        // //       0      1      2      3      4
        // /* 0 */ {false, true, true, true, true},
        // /* 1 */ {true, false, true, true, true},
        // /* 2 */ {true, false, false, true, true},
        // /* 3 */ {true, false, true, false, true},
        // /* 4 */ {true, false, true, true, false}

        //       0      1      2      3      4      5
        /* 0 */ {false, true, true, false, false, false},
        /* 1 */ {true, false, false, false, false, false},
        /* 2 */ {true, false, false, false, false, false},
        /* 3 */ {false, false, false, false, false, false},
        /* 4 */ {false, false, false, false, false, false},
        /* 5 */ {false, false, false, false, false, false}
    };
    for (auto vec : matrix) {
        for (auto val : vec) {
            std::cout << val << " " ;
        }
        std::cout << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    std::cout << getMinimumConnections(matrix) << std::endl;
    
}

#endif

/*
In an effort to connect all airports with minimal costs, an airport authority needs to identify the minimum number of new
flight connections so that it is possible to reach all airports from every other airport directly or indirectly.
Airports and flight connections are represented by a boolean matrix. Airports are represented by numbers 0, 1, 2, and so on.
So, if airport '0' is connected via a flight with airport '1' then elements [0][1] and [1][0] will have the value true, or
false if there is no flight connectivity. All flights are bi-directional.
The function getMinimumConnections accepts a two-dimensional array matrix. The function should return the minimum number
of flight connections that need to be added so that all airports are reachable from every other airport, directly or indirectly.
For example, the following code should print 1, as a minimum of 1 additional flight connection will connect all airports
(directly or indirectly).
 
std::vector<std::vector<bool>> matrix {
    {false, true, false, false, true},
    {true, false, false, false, false},
    {false, false, false, true, false},
    {false, false, true, false, false},
    {true, false, false, false, false}
};
std::cout << getMinimumConnections(matrix) << std::endl; // should print 1

Starting Coding:
#include <iostream>
#include <vector>
int getMinimumConnections(const std::vector<std::vector<bool>>& matrix)
{
    throw std::logic_error("Waiting to be implemented");
}

#ifndef RunTests
int main()
{
    std::vector<std::vector<bool>> matrix {
        {false, true, false, false, true},
        {true, false, false, false, false},
        {false, false, false, true, false},
        {false, false, true, false, false},
        {true, false, false, false, false}
    };
    std::cout << getMinimumConnections(matrix) << std::endl; // should print 1
}
#endif
Test case: 
Example case: 
All airports are pre-connected: 
Some airports are pre-connected: 
Performance test on large number of airports and flight connections

*/