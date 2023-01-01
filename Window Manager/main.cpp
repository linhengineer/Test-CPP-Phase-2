#include <iostream>
#include <string>
#include <vector>

class WindowManager
{
    std::vector<std::string> v;
public:
    void open(const std::string windowName)
    {
      v.push_back(windowName);
    }

    void close(const std::string windowName)
    {
    for(std::size_t i =0 ; i < v.size() ; i++) {
        if(v[i]==windowName){
            v.erase(v.begin()+i);
            break;
        }
    }
    }

    std::string getTopWindow()
    {
        return v[v.size()-1];
    }
};

#ifndef RunTests
int main()
{
    WindowManager wm;
    wm.open("Calculator");
    wm.open("Browser");
    wm.open("Player");
    wm.close("Browser");
    std::cout << wm.getTopWindow();
}
#endif

/*
The window manager handles windows in a graphical user interface. Windows are displayed on top of each other, the top one being completely visible. When new window is opened, it is placed on top of all the other windows.
Implement the class WindowManager, that contains the following methods that should be efficient with respect to time used:
•	Open - Opens a window with the given name and puts it on top of all other windows.
•	Close - Closes a window with the given name. Every open window will have a different name.
•	GetTopWindow - Returns the name of the top window.
For example, if Calculator, Browser and Player are opened (in that order) and after that Browser is closed, Player is the top window. See the image for details.
Test case: 
Example case: Exception
Small number of windows: Exception
Performance test on a large number of windows: Exception
*/