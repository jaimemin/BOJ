#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;

stack < int > s;

int main(void)
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        string command;
        cin >> command;

        if (command == "push")
        {
            int num;
            cin >> num;

            s.push(num);
        } 
        else if (command == "pop")
        {
            if (!s.empty())
            {
                cout << s.top() << endl;

                s.pop();
            } 
            else
            {
                cout << -1 << endl;
            }
        } 
        else if (command == "size")
        {
            cout << s.size() << endl;
        }
        else if (command == "empty")
        {
            cout << s.empty() << endl;
        }
        else if (command == "top")
        {
            if (!s.empty())
            {
                cout << s.top() << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
