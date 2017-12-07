#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

class Words
{
public:
    void set_string(string s)
    {
        word = s;
    }
    void add_count()
    {
        count++;
    }


private:
    string word;
    int count;
    vector<int> at_lines;
};
int main ()
{
    string line;
    char buffer;
    Words word;
    vector<Words> w;
    vector<char> c;
    int line_count = 0;
    int num = 0;
    ifstream alice;
    alice.open ("alice.txt");
    if (alice.is_open())
    {
        while (alice.get(buffer) )
        {
            c.push_back(tolower(buffer));
            cout << c[num] << '\n';
            num++;
        }
        alice.close();
    }
    else 
    {
        cout << "Unable to open file";
    }
    
    return 0;
}
