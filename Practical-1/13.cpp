#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string longest = "";
    string word = "";

    for(int i = 0; i <= sentence.length(); i++)
    {
        if(i == sentence.length() || sentence[i] == ' ')
        {
            if(word.length() > longest.length())
                longest = word;

            word = "";
        }
        else
        {
            word += sentence[i];
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length();

    return 0;
}
