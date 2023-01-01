#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>


class Archive
{
    std::string title;
    std::string content;

public:
    void add(int id, std::string title, std::string content)
    {
        std::vector<std::string> v;
        v.push_back(title);
        v.push_back(content);
        records[id] = v;
        this->id = id;
    }

    void remove(int id)
    {

        records[id].clear();
    }
    void clear()
    {
        records.clear();
    }
    int id;
    std::unordered_map<int, std::vector<std::string>> records;
};

#ifndef RunTests
int main()
{
    Archive archive;

    archive.add(123456, "Hamlet", "Hamlet, Prince of Denmark.");

    std::cout << "ID: " << archive.id << " || Title: " << archive.records[archive.id][0] << " || Content: " << archive.records[archive.id][1] << std::endl;

    archive.add(123457, "Othello", "Othello, the Moore of Venice.");
    std::cout << "ID: " << archive.id << " || Title: " << archive.records[archive.id][0] << " || Content: " << archive.records[archive.id][1] << std::endl;

    archive.remove(123456);

    archive.clear();
}
#endif

/*A customer has complained that their archive application still occupies a big chunk of memory although they have removed all the records from it.
Fix the problem.
Starting Coding:
#include <iostream>
#include <unordered_map>
#include <string>

class Archive
{
    class Record
    {
    public:
        Record(std::string title, std::string content)
        {
            this->title = title;
            this->content = content;
        }
        std::string title;
        std::string content;
    };
public:
    void add(int id, std::string title, std::string content)
    {
        records[id] = new Record(title, content);
    }

    void remove(int id, std::string& title, std::string& content)
    {
        std::unordered_map<int, Record*>::iterator it = records.find(id);

        Record* doc = it->second;
        title = doc->title;
        content = doc->content;
        records.erase(it);
    }
    void clear()
    {
        records.clear();
    }

private:
    std::unordered_map<int, Record*> records;
};

#ifndef RunTests
int main()
{
    Archive archive;
    archive.add(123456, "Hamlet", "Hamlet, Prince of Denmark.");
    archive.add(123457, "Othello", "Othello, the Moore of Venice.");

    std::string title, content;
    archive.remove(123456, title, content);

    std::cout << title << '\n';
    std::cout << content;

    archive.clear();
}
#endif
Test case: 
Add and remove: Memory limit exceeded
Add and clear: Memory limit exceeded
Add and destroy: Memory limit exceeded
*/