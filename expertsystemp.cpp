/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string rule1(vector<string> v1)
{

    string ans;
    int count = 0;
    vector<string> v2;
    v2.push_back("Fever");
    v2.push_back("Headache");
    v2.push_back("BodyPain");
    v2.push_back("Weakness");

    for (int i = 0; i < v1.size(); i++)
    {

        for (int j = 0; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                count++;
            }
        }
    }
    if (count >= 3)
    {
        ans = "You have symptoms of the maleria";
    }

    return ans;
}
string rule2(vector<string> v1)
{

    string ans;
    int count = 0;
    vector<string> v2;
    v2.push_back("TestPositive");
    v2.push_back("Cough");
    v2.push_back("Cold");
    v2.push_back("BodyPain");

    for (int i = 0; i < v1.size(); i++)
    {

        for (int j = 0; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                count++;
            }
        }
    }
    if (count >= 3)
    {
        ans = "You have symptoms of the Covid-19";
    }
    return ans;
}
string rule3(vector<string> v1)
{

    string ans;
    int count = 0;
    vector<string> v2;
    v2.push_back("Blood-flow");
    v2.push_back("Headache");
    v2.push_back("BodyPain");
    v2.push_back("Low-level-haemloglobin");

    for (int i = 0; i < v1.size(); i++)
    {

        for (int j = 0; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                count++;
            }
        }
    }
    if (count >= 3)
    {
        ans = "You have symptoms of the Blood Cancer";
    }
    return ans;
}
string rule4(vector<string> v1)
{

    string ans;
    int count = 0;
    vector<string> v2;
    v2.push_back("Yellow-skin");
    v2.push_back("yellow-nails");
    v2.push_back("BodyPain");
    v2.push_back("Headache");

    for (int i = 0; i < v1.size(); i++)
    {

        for (int j = 0; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                count++;
            }
        }
    }
    if (count >= 3)
    {
        ans = "You have symptoms of the Typhoid";
    }

    return ans;
}
string rule5(vector<string> v1)
{

    string ans;
    int count = 0;
    vector<string> v2;
    v2.push_back("Naushea");
    v2.push_back("Headache");
    v2.push_back("vomiting");
    v2.push_back("Weakness");

    for (int i = 0; i < v1.size(); i++)
    {

        for (int j = 0; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                count++;
            }
        }
    }
    if (count >= 3)
    {
        ans = "You have symptoms of the Food-poisioning";
    }

    return ans;
}

int main()
{
    vector<string> symptoms;
    int n;
    cout << "Enter the number of the symptoms" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1;
        cout << "Enter the symptom" << endl;
        cin >> s1;
        symptoms.push_back(s1);
    }
    vector<string> diagonis;
    string ans1 = rule1(symptoms);
    string ans2 = rule2(symptoms);
    string ans3 = rule3(symptoms);
    string ans4 = rule4(symptoms);
    string ans5 = rule5(symptoms);
    if (ans1 != "")
    {
        diagonis.push_back(ans1);
    }
    if (ans2 != "")
    {
        diagonis.push_back(ans2);
    }
    if (ans3 != "")
    {
        diagonis.push_back(ans3);
    }
    if (ans4 != "")
    {
        diagonis.push_back(ans4);
    }
    if (ans5 != "")
    {
        diagonis.push_back(ans5);
    }

    for (int i = 0; i < diagonis.size(); i++)
    {
        cout << diagonis[i] << endl;
    }
    if (diagonis.size() == 0)
    {
        cout << "No symptoms found" << endl;
    }

    return 0;
}
