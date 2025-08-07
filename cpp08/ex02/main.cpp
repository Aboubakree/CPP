#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

int main()
{
    std::cout << "=== MutantStack Test 1: Basic functionality ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "\n=== Iterating through MutantStack ===" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "\n=== Comparison with std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    
    std::cout << "\n=== Test 2: Copy constructor ===" << std::endl;
    MutantStack<int> mstack2(mstack);
    std::cout << "Original stack size: " << mstack.size() << std::endl;
    std::cout << "Copied stack size: " << mstack2.size() << std::endl;
    
    std::cout << "\n=== Test 3: Assignment operator ===" << std::endl;
    MutantStack<int> mstack3;
    mstack3.push(42);
    mstack3 = mstack;
    std::cout << "Assigned stack size: " << mstack3.size() << std::endl;

    std::cout << "\n=== Test 5: Const iterators ===" << std::endl;
    const MutantStack<int> const_mstack(mstack);
    std::cout << "Const iteration:" << std::endl;
    
    for (MutantStack<int>::const_iterator cit = const_mstack.begin(); 
         cit != const_mstack.end(); ++cit)
    {
        std::cout << *cit << std::endl;
    }
    
    std::cout << "\n=== Test 7: String MutantStack ===" << std::endl;
    MutantStack<std::string> str_stack;
    str_stack.push("Hello");
    str_stack.push("World");
    str_stack.push("MutantStack");
    
    std::cout << "String MutantStack:" << std::endl;
    for (MutantStack<std::string>::iterator sit = str_stack.begin();
         sit != str_stack.end(); ++sit)
    {
        std::cout << *sit << std::endl;
    }
    
    return 0;
}