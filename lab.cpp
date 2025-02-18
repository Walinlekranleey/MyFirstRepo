#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::string input;
    std::cin >> input;
    //input = "([](){([])})";
    std::stack<char> stack;
    std::stack<int> open;
    for(int i = 0; i < input.length(); ++i) {
        if(input[i] == '('  input[i] == '{'  input[i] == '[') {
            stack.push(input[i]);
            open.push(i);
        } else if(input[i] == ')'  input[i] == '}'  input[i] == ']') {
            if(stack.empty()) {
                std::cout << i+1;
                return 0;
            }
            if(input[i] == ')' && stack.top() == '(') {
                stack.pop();
                open.pop();
            } else if(input[i] == '}' && stack.top() == '{') {
                stack.pop();
                open.pop();
            } else if(input[i] == ']' && stack.top() == '[') {
                stack.pop();
                open.pop();
            } else {
                std::cout << i+1;
                return 0;
            }
        }
    }
    if(stack.empty()) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << open.top() + 1;
    }
    return 0;
}
