#include <stdexcept>
#include <iostream>
#include <vector>

std::vector<std::string> transformDateFormat(const std::vector<std::string>& dates)
{
    //throw std::logic_error("Waiting to be implemented");
    std::vector<std::string> reformattedDates;
    for (auto vt : dates) {                                       
        if (vt[4] == '/' && vt[7] == '/' && vt.length() == 10 ) {  // YYYY/MM/DD
            vt.erase(4, 1);                                       
            vt.erase(6, 1);
            reformattedDates.push_back(vt);                        
        }
        if ((vt[2] == '/' && vt[5] == '/' && vt.length() == 10) || (vt[2] == '-' && vt[5] == '-' && vt.length() == 10) ) {  // DD/MM/YYYY or DD-MM-YYY
            vt.erase(2, 1);                                       
            vt.erase(4, 1);
            reformattedDates.push_back(vt);                         
        }
    }


    return reformattedDates;
}

#ifndef RunTests
int main()
{
    std::vector<std::string> dates = {"2010/02/20", "2022/12/30", "19/12/2016", "11-18-2012", "20130720"};
    std::vector<std::string> reformattedDates = transformDateFormat(dates);
    for (auto const& reformattedDate : reformattedDates)
    {
        std::cout << reformattedDate << std::endl;
    }
}
#endif

/*
Index: 0123456789
       YYYY/MM/DD
       DD/MM/YYYY
       MM-DD-YYYY
An application requires different date formats to be converted into one common date format.
Implement the function transformDateFormat  which accepts a list of dates as strings,
and returns a new list of strings representing dates in the format of YYYYMMDD.
All incoming dates will be valid dates, but only those in one of the following formats: YYYY/MM/DD, DD/MM/YYYY,
and MM-DD-YYYY should be included in the returned list, where YYYY, MM, and DD are numbers representing year, month, and day, respectively.
For example, transformDateFormat(std::vector {"2010/02/20", "19/12/2016", "11-18-2012", "20130720"})
should return the list {"20100220", "20161219", "20121118"}.
Starting Coding:
#include <stdexcept>
#include <iostream>
#include <vector>

std::vector<std::string> transformDateFormat(const std::vector<std::string>& dates)
{
    throw std::logic_error("Waiting to be implemented");
}

#ifndef RunTests
int main()
{
    std::vector<std::string> dates = {"2010/02/20", "19/12/2016", "11-18-2012", "20130720"};
    std::vector<std::string> reformattedDates = transformDateFormat(dates);
    for (auto const& reformattedDate : reformattedDates)
    {
        std::cout << reformattedDate << std::endl;
    }
}
#endif
Test case: 
Example case: Exception
Lists containing a single format: Exception
Lists containing multiple formats: Exception
Lists containing multiple formats, some formats should be ignored: Exception
 */