#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool operasi(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
        return true;
    }else{
        return false;
    }
}

int precedence(char c){
    if(c == '^'){
        return 3;
    }else if(c == '*' || c == '/'){
        return 2;
    }else if(c == '+' || c == '-'){
        return 1;
    }else{
        return -1;
    }
}

string InfixToPostfix(stack<char> s, string infix){
    string postfix;

    for(int i=0;i<infix.length();i++){
        if((infix[i] >= 'a' && infix[i] <= 'z') ||(infix[i] >= 'A' && infix[i] <= 'Z')){
            postfix+=infix[i];
        }else if(infix[i] == '('){
            s.push(infix[i]);
        }else if(infix[i] == ')'){
            while((s.top()!='(') && (!s.empty())){
                char temp=s.top();
                postfix+=temp;
                s.pop();
            }
            if(s.top()=='('){
                s.pop();
            }
        }else if(operasi(infix[i])){
            if(s.empty()){
                s.push(infix[i]);
            }else{
                if(precedence(infix[i])>precedence(s.top())){
                    s.push(infix[i]);
                }else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^')){
                    s.push(infix[i]);
                }else{
                    while((!s.empty())&&(precedence(infix[i])<=precedence(s.top()))){
                        postfix+=s.top();s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }

    return postfix;
}

string InfixToPrefix(stack<char> s, string infix){
    string prefix;
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '('){
            infix[i] = ')';
        }else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            prefix += infix[i];
        }else if (infix[i] == '(') {
            s.push(infix[i]);
        }else if (infix[i] == ')') {
            while ((s.top() != '(') && (!s.empty())) {
                prefix += s.top();
                s.pop();
            }if (s.top() == '(') {
                s.pop();
            }
            }else if (operasi(infix[i])) {
                if (s.empty()) {
                    s.push(infix[i]);
                }else {
                    if (precedence(infix[i]) > precedence(s.top())) {
                        s.push(infix[i]);
                    }else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')) {
                        while ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')) {
                        prefix += s.top();
                        s.pop();
                        }
                        s.push(infix[i]);
                    }else if (precedence(infix[i]) == precedence(s.top())) {
                        s.push(infix[i]);
                    }else {
                        while ((!s.empty()) && (precedence(infix[i]) < precedence(s.top()))) {
                        prefix += s.top();
                        s.pop();
                        }
                        s.push(infix[i]);
                    }
                }
            }
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}


int main(){
    string infix, postfix, prefix;
    cout << "Silahkan masukkan ekspresi infix : ";
    cin >> infix;
    stack <char> stack;
    postfix = InfixToPostfix(stack, infix);
    cout << "Hasil konversi ekspresi infix ke postfix : " << postfix;
    prefix = InfixToPrefix(stack, infix);
    cout << endl;
    cout << "Hasil konversi ekspresi infix ke prefix : " << prefix;
    return 0;
}
