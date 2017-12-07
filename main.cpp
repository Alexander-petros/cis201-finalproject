#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

class Words
{
public:
    Words(vector<char> c)
    {
       set_string(c);
       add_count();
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


private:
    string word;
    int count;
    vector<int> at_line;
};
bool check_word (vector<Words> w, vector<char> word)
{
   return false;
}
void read_all (vector<Words> w)
{
   for (int i = 0; i <=  w.size(); i++)
   {
      cout << w[i].return_word() << endl;
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
           if ( (buffer <= 47 && buffer != 32) || (buffer >= 94 && buffer <= 96) || (buffer >= 58 && buffer <= 64))
              //Detects if it is any punctuation and ignores it
           {
           }
           else
           {
               if (buffer != 32)// && check_word(w,c) == true)
               {
                 c.push_back(tolower(buffer));
                 //cout << c[num];
                 num++;
               }
               else 
               {
                Words * word = new Words(c);
                //cout << word->return_word() << endl;
                c.clear();
                for ( int i = 0; i < w.size(); i++)
                {
                   if ( w[i].return_word() == word->return_word())
                      {
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
