#ifndef HEADER_POPULATION_H
#define HEADER_POPULATION_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
////https://www.tutorialspoint.com/cplusplus/cpp_templates.htm
//https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
//https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
class Population{
	private:

	public:
		int n;
		int ub;
		int lb;
		int dimension;
		std::vector <double> individual;
        std::vector <double> population[];
        double J[];
		Population(int n, int lb ,	int ub ,int dimension);
		~Population();
};

#endif /* HEADER_POPULATION_H */

/*
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack { 
   private: 
      vector<T> elems;    // elements 

   public: 
      void push(T const&);  // push element 
      void pop();               // pop element 
      T top() const;            // return top element 
      
      bool empty() const {      // return true if empty.
         return elems.empty(); 
      } 
}; 

template <class T>
void Stack<T>::push (T const& elem) { 
   // append copy of passed element 
   elems.push_back(elem);    
} 

template <class T>
void Stack<T>::pop () { 
   if (elems.empty()) { 
      throw out_of_range("Stack<>::pop(): empty stack"); 
   }
   
   // remove last element 
   elems.pop_back();         
} 

template <class T>
T Stack<T>::top () const { 
   if (elems.empty()) { 
      throw out_of_range("Stack<>::top(): empty stack"); 
   }
   
   // return copy of last element 
   return elems.back();      
} 

int main() { 
   try {
      Stack<int>         intStack;  // stack of ints 
      Stack<string> stringStack;    // stack of strings 

      // manipulate int stack 
      intStack.push(7); 
      cout << intStack.top() <<endl; 

      // manipulate string stack 
      stringStack.push("hello"); 
      cout << stringStack.top() << std::endl; 
      stringStack.pop(); 
      stringStack.pop(); 
   } catch (exception const& ex) { 
      cerr << "Exception: " << ex.what() <<endl; 
      return -1;
   } 
} 

*/