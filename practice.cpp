#include <bits/stdc++.h>
using namespace std;

// string tolower(string s)
// {
//     transform(s.begin(), s.end(), s.begin(), ::tolower);
//     return s;
// }

class Harish
{
private:
    unordered_map<string, string> rules;

public:
    Harish()
    {
        rules["hi"] = "Hello!";
        rules["how are you"] = "I'm doing well, thank you!";
        rules["what's your name"] = "My name is Chatbot.";
        rules["bye"] = "Goodbye!";
    }
    string get_response(string input)
    {
        for (const auto x : rules)
        {
            if (input.find(x.first) != string::npos)
            {
                return x.second;
            }
        }
        return "i am not getting you";
    }
};

int main()
{
    Harish h;
    cout << "Chatbot: Hello welcome to our service\n";

    while (true)
    {
        string inputuser;
        cout << "User: ";
        getline(cin, inputuser);

        string response = h.get_response(inputuser);

        cout << "Chatbot: " << response << endl;

        if (inputuser == "bye")
        {
            break;
        }
    }
    return 0;
}