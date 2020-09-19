#include <iostream>

int main()
{
    // Part 2: Palindrome Check

    // Input string from command-line
    std::string str;
    std::cout << "Enter String:" << std::endl;
    std::cin >> str;

    // Palindrome Check
    int left = 0;
    int right = str.length() - 1;
    bool is_palindrome = true;
    while (left < right) {
    	if (str[left] != str[right]) {
    		is_palindrome = false;
    		break;
    	}
    	left++;
    	right--;
    }
    std::string not_keyword = "NOT ";
    if (is_palindrome) {
    	not_keyword = "";
    }
    std::cout << str << " is " << not_keyword << "a palindrome" << std::endl;

    return 0;
}
