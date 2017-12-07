#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class Words
{
public:
    //constructs word class
    Words(vector<char> c, int i)
    {
       set_string(c);
       set_linecount(i);
    }
    //Sets the word in the string
    void set_string(vector<char> s)
    {
       string x(s.data(), s.size());
        word = x;
    }
    //Returns the word
    string return_word()
    {
       return word;
    }
    //Stores place where lines are at
    void set_linecount(int i)
    {
       at_line.push_back(i);
    }
    //returns linecount
    void return_linecount()
    {
       for (int i = 0; i < at_line.size(); i++)
       {
          cout << at_line[i] << " ";
       }
    }
    //Returns how many times a word appears
    int return_count()
    {
       count = 0;
       for (int i = 0; i < at_line.size(); i++)
       {
          count++;
       }
       return count;
    }


private:
    string word;
    int count;
    vector<int> at_line;
};
//Reads all words in vector
void read_all (vector<Words> w)
{
   for (int i = 0; i <  w.size(); i++)
   {
      cout << w[i].return_word() << " : "; 
      cout << w[i].return_count(); 
      cout << " : ";
      w[i].return_linecount();
      cout << " " << endl;
  }
}
int main ()
{
    string line;
    char buffer;
    bool new_word = true;
    int wordcount = 0, line_count = 0, num = 0;
    vector<Words> w;
    vector<char> c;
    ifstream alice;
    alice.open ("alice.txt");
    if (alice.is_open())
    {
        while (alice.get(buffer) )
        {
           if (alice.eof() == true)
              {
                 break; //forces program to break in case while loop does not
              }
           if ( (buffer <= 47 && buffer != 32 && buffer != 10) || (buffer >= 94 && buffer <= 96) || (buffer >= 58 && buffer <= 64))
              //Detects if it is any punctuation and ignores it
           {
           }
           else
           {
               if (buffer == '\n')
               {
                 buffer = 32;
                 c.push_back(buffer); //Detects if it is newline and forces it to become a space
                 line_count++;
               }
               if ( buffer != 32)
               {
                  c.push_back(tolower(buffer)); //Adds letter to vector
                  num++;
                  
               }
               else 
               {
                Words * word = new Words(c, line_count); //Constructs a new word 
                c.clear(); //Clears word so new words can be stored
                for ( int i = 0; i < w.size(); i++) //Goes for the entire size of the word
                {
                   if ( w[i].return_word() == word->return_word()) //If the word exists then it skips that word
                      {
                         w[i].set_linecount(line_count); //increments the lines that they are found on
                         new_word = false;
                         delete word; //frees up data that is used
                         break;
                      }
                   else
                   {
                      new_word = true; //confirms there is a new word
                   }
                }
                if (new_word == true)
                {
                   w.push_back(*word); //if it actually is a new word then it adds to the vector
                }
                num = 0; //Sets the 'pointer' back to the beginning of the word
              }
           }
        }
        alice.close();
    }
    else 
    {
        cout << "Unable to open file";
    }
    read_all(w); //reads the file
    return 0;
}
