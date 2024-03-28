#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int n;
string add_string(string, string);
int main() {

    cin >> n;

    deque<string> d;
    d.push_back("0");
    d.push_back("1");


    if(n==0 || n==1) {
        cout << n;
    }
    else {
        for(int i=2;i<=n;i++) {
            
            string temp = add_string(d.front(), d.back());
            
            d.push_back(temp);
            d.pop_front();
            
        }
        cout << d[1];
    }
    
    return 0;
}

string add_string(string a, string b) {
    string str = "";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if(a.length() > b.length()) {
        for(int i=0;i<b.length();i++) {
            if((a[i]-'0' + b[i]-'0') >= 10) {
                str += a[i]+b[i]-'0'-10;
                a[i+1]++;
            }
            else {
                str += a[i]+b[i]-'0';
            }
        }
        for(int i=b.length();i<a.length();i++) {
            str += a[i];
        }
    }
    else if(a.length() == b.length()) {
        for(int i=0;i<b.length()-1;i++) {
            if((a[i]-'0' + b[i]-'0') >= 10) {
                str += (a[i]+b[i]-'0'-10);
                a[i+1]++;
                
            }
            else {
                str += (a[i]+b[i]-'0');
                
            }
        }
        if((a[a.length()-1] + b[b.length()-1]-'0'-'0') >= 10) {
            str += (a[a.length()-1] + b[b.length()-1]-'0'-10);
            str += "1";
            
        }
        else {
            str += (a[a.length()-1] + b[b.length()-1]-'0');
        }
    }
    else {
        for(int i=0;i<a.length();i++) {
            if((a[i]-'0' + b[i]-'0') >= 10) {
                str += a[i]+b[i]-'0'-10;
                b[i+1]++;
            }
            else {
                str += a[i]+b[i]-'0';
            }
        }
        for(int i=a.length();i<b.length();i++) {
            str += b[i];
        }
    }

    reverse(str.begin(), str.end());

    return str;
}