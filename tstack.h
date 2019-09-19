/*
tstack.h
Project 7
Samuel lamb
cop3330
4/9/2019
*/


#ifndef _TSTACK_H
#define _TSTACK_H

#include <cstring>
#include <iostream>

namespace fsu
{
    template <typename T, size_t N = 100>
    class Stack
    {
        public:

      
            void Push(const T& t);   // push t onto stack; error if full
            T Pop();                 // pop stack and return removed element; error if stack is empty
            T& Top();                // return top element of stack; error if stack is empty
            const T& Top() const;    // const version
            size_t Size() const;     // return number of elements in stack
            size_t Capacity() const; // return storage capacity [maximum size] of stack
            bool Empty() const;      // return 1/true if stack is empty, 0/false if not empty
            void Clear();            // make the stack empty
            
      
            Stack();         
            Stack(char ofc, int dir);           // default constructor
            Stack(T fill,char ofc, int dir);      // sets ofc_ and dir_
            Stack(const Stack&);                // copy constructor
            ~Stack();                          // destructor
            Stack& operator = (const Stack&);  // assignment operator
            
    
            void Display(std::ostream& os) const; // output stack contents through os - depends on ofc_ and dir_
            void SetOFC(char ofc);
            void SetDIR(int dir);
            void Dump(std::ostream& os) const;   // output all private data (for development use only)

        private:

       
            const size_t capacity_;  // = N = size of array   - fixed during life of stack
            T* data_;              // dynamically allocated array of T objects    - where T objects are stored
            size_t size_;            // current size of stack - dynamic during life of stack

          
            char ofc_;
            int dir_;   
    }; //end Stack
    

    template < typename T , size_t N >
    void Stack<T, N>::Push(const T& t)
    {
        if(size_==capacity_)
        {
            std::cerr << "** Stack error: Push(x) called on full stack\n";
        }
        else
        {
          data_[size_] = t;
          size_ += 1;
        }
    }

    
  
    template < typename T , size_t N >
    T Stack<T, N>::Pop()
    {
      T o;
        if(size_== 0)
        {
            
          std::cerr << "** Stack error: Pop() called on Empty Stack\n";
        }
        else
        {
          o = Top();
          size_ -= 1;
        }
        return o;
    }

 
    template < typename T , size_t N >
    T& Stack<T, N>::Top()
    {
        if(size_== 0)
        {
            std::cerr << "** Stack error: Top() called on empty stack\n";
            return data_[0];
        }
        else
        {
            return data_[size_ - 1];
            
        }
    }

 
    template < typename T , size_t N >
    const T& Stack<T, N>::Top() const
    {
        if(size_== 0)
        {
            std::cerr << "** Stack error: Top() called on empty stack\n";
            return data_[0];
        }
        else
        {
           return data_[size_ - 1];
            
        }
    }

    template < typename T , size_t N >
    size_t Stack<T, N>::Size()const
    {
        return size_;
    }

    
    template < typename T , size_t N >
    size_t Stack<T, N>::Capacity()const
    {
        return capacity_;
    }

    template < typename T , size_t N >
    bool Stack<T, N>::Empty()const
    {
        if(size_ == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    
    template < typename T , size_t N >
    void Stack<T, N>::Clear()
    {
        size_ = 0;
    }

  
    template < typename T , size_t N >
    Stack<T, N>::Stack(): capacity_(N), size_(0), ofc_('\0'), dir_(1)
    {
        if(capacity_ < 1)
        {
            std::cerr << "Error"<< std::endl;
        }
        else
        {
          data_ = new T[capacity_];
        }
    }

    template < typename T , size_t N >
    Stack<T, N>::Stack(char ofc, int dir) : capacity_(N), size_(0), ofc_(ofc), dir_(dir)
    {
        if(capacity_ < 1)
        {
            std::cerr << "Error"<< std::endl;
        }
        
        data_ = new T[capacity_];
       // Stack<T, N>::SetOFC(ofc_);
       // Stack<T, N>::SetDIR(dir_);

    }


    template < typename T , size_t N >
    Stack<T, N>::Stack(const Stack& s): capacity_(N), size_(s.size_), ofc_(s.ofc_), dir_(s.dir_)
    {
      data_ = new T[capacity_];
      for(size_t i = 0; i < size_; ++i)
      {
        data_[i] = s.data_[i];
      }

    }


    template < typename T , size_t N >
    Stack<T, N>::~Stack()
    {
      delete[] data_;
    }



	template < typename T , size_t N >
	Stack<T,N>& Stack<T,N>::operator=(const Stack& s)
	{
    if(this != &s)
    {
	  size_ = s.size_;
	  dir_=s.dir_;
	  ofc_=s.ofc_;
	    for (size_t i = 0; i < size_; ++i)
	    {
	      data_[i] = s.data_[i];
	    }
    }
	  return *this;
    }

	
 
    template < typename T , size_t N >
    Stack<T, N>::Stack(T fill, char ofc, int dir) : capacity_(N), size_(0), ofc_(ofc), dir_(dir)
    {  
      data_ = new T[capacity_];
      for (size_t i = 0; i < N; ++i)
	    {
	      data_[i] = fill;
	    }

    }


  template < typename T , size_t N >
	void Stack<T,N>::Display(std::ostream& os)const
	{
	  if (dir_>=0)
	  {
	    for (size_t i = 0; i < size_; ++i)
	    {
	      if (ofc_=='\0')
	      {
	        os << data_[i];
	      }
	      else
	      {
	        os << ofc_ << data_[i];
	      }
	    }
	  }
	  else
	  {
	    for (size_t i = size_ ; i > 0; --i)
	    {
	      if (ofc_=='\0')
	      {
	        os << data_[i - 1];
	      }
	      else
	      {
	        os << ofc_ << data_[i - 1];
	      }
	    }
	  }
	}
	

	template < typename T , size_t N >
	void Stack<T,N>::SetOFC(char ofc)
	{
	  ofc_=ofc;
	}
	

	template < typename T , size_t N >
	void Stack<T,N>::SetDIR(int dir)
	{
	  dir_=dir;
	}
	

	template < typename T , size_t N >
	void Stack<T,N>::Dump(std::ostream& os) const
	{
	  os << "Capacity: " << capacity_ << "\n";
	  os << "Size:     " << size_  << "\n";
	  os << "Array:    [";
	  for (size_t i = 0; i < capacity_ - 1; ++i)
	  {
	    if (i < size_ )
	    {
	      os << data_[i];
	    }
	    else
	    {
	      os << "*";
	    }
	    if (i < capacity_ - 2)
	    {
	      os << ",";
	    }
	  }
	  os << "]\n";
	

	  os << "Stack:    [";
	  if (size_ > 0)
	  {
	    for (size_t i = 0; i < size_ ; ++i)
	    {
	      os << data_[i];
	      if (i < size_ - 1)
	      {
	        os << ",";
	      }
	    }
	  }
	  os << "]\n";
	}


    template < typename T , size_t N >
    std::ostream& operator << (std::ostream& os, const Stack<T,N>& s)
    {
        s.Display (os);
        return os;
    }



}

#endif
