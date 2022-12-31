#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
class Ship
{
private:
    std::vector<int> containers;
public:
    Ship(int containerCount, std::function<int(int)> fillContainer){
        for (int i = 0; i < containerCount; i++){
            containers.push_back(fillContainer(i));
        }
    }
    int peekContainer(int containerIndex){
        return containers[containerIndex];
    }
};

#ifndef RunTests
int main(){
    Ship ship(10, [](int containerIndex) { return containerIndex; });
    for (int i = 0; i < 10; i++) {
        std::cout << "Container: " << i << ", cargo: " << ship.peekContainer(i) << "\n";
    }
}
#endif

/*
A ship has containerCount containers indexed as 0, 1, ..., containerCount - 1. Each container must be filled in the constructor of the Ship using the fillContainer function, which accepts the container's index and returns the container's cargo.
The code below works, but the server has enough memory only for a ship with few containers. Change the code so that the server has enough memory even for a ship with many containers.
Starting Coding:
#include <iostream>
#include <unordered_map>
#include <functional>
class Ship
{
public:
    Ship(int containerCount, std::function<int(int)> fillContainer)
    {
        for (int i = 0; i < containerCount; i++)
        {
            this->containers.insert({ i, new int(fillContainer(i)) });
        }
    }
    int peekContainer(int containerIndex)
    {
        return *this->containers.at(containerIndex);
    }
private:
    std::unordered_map<int, int*> containers;
};

#ifndef RunTests
int main()
{
    Ship ship(10, [](int containerIndex) { return containerIndex; });
    for (int i = 0; i < 10; i++) {
        std::cout << "Container: " << i << ", cargo: " << ship.peekContainer(i) << "\n";
    }
}
#endif
Test case: 
Ship with a medium number of containers: Memory limit exceeded
Ship with a large number of containers: Memory limit exceeded
*/