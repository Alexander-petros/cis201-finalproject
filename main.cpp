#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

class Words
{
public:
    Words(vector<char> c, int i)
    {
       set_string(c);
       add_count();
       set_linecount(i);
    }
    void set_string(vector<char> s)
    {
       string x(s.data(), s.size());
        word = x;
    }
    void add_count()
    {
        count++;
    }
    char check_char(int i)
    {
       return word.at(i);
    }
    string return_word()
    {
       return word;
    }
    void set_linecount(int i)
    {
       at_line.push_back(i);
    }
    void return_linecount()
    {
       for (int i = 0; i < at_line.size(); i++)
       {
          cout << at_line[i] << " ";
       }
    }


private:
    string word;
    int count;
    vector<int> at_line;
};
void read_all (vector<Words> w)
{
   for (int i = 0; i <=  w.size(); i++)
   {
      cout << "The word is: " << w[i].return_word() << endl;
      cout << "And it is located at lines: "; 
      w[i].return_linecount();
      cout << endl;
  }
}
int main ()
{
    string line;
    char buffer;
    bool new_word = true;
    int wordcount = 0;
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
           if ( (buffer <= 47 && buffer != 32) || (buffer >= 94 && buffer <= 96) || (buffer >= 58 && buffer <= 64) ||
              buffer == '\n')
              //Detects if it is any punctuation and ignores it
           {
              if (buffer == '\n')
              {
                 cout << "New Line";
                 line_count++;
              }
           }
           else
           {
               if (buffer != 32)
               {
                 c.push_back(tolower(buffer));
                 //cout << c[num];
                 num++;
               }
               else 
               {
                Words * word = new Words(c, line_count);
                c.clear();
                for ( int i = 0; i < w.size(); i++)
                {
                   if ( w[i].return_word() == word->return_word())
                      {
                         w[i].add_count();
                         w[i].set_linecount(line_count);
                         new_word = false;
                         cout << "Old Word" << endl;
                         delete word;
                         break;
                      }
                   else
                   {
                      new_word = true;
                   }
                }
                if (new_word == true)
                {
                   cout << "New Word" << word->return_word() << endl;
                   w.push_back(*word);
                }
                num = 0;
              }
           }
        }
        alice.close();
    }
    else 
    {
        cout << "Unable to open file";
    }
    read_all(w);
    return 0;
}
