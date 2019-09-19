/*
fstack.cpp
Project 7
Samuel lamb
cop3330
4/9/2019
*/

#include <tstack.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>

char ofc;
int dir;
fsu::Stack<int> stack('\0',1);
fsu::Stack<int> stackAssign(stack);
void DisplayMenu ();

int main()
{
  char input;
  fsu::Stack<int> *sptr = &stack;
  DisplayMenu();
  do
  {
    std::cout << "Enter [command][argument] (\'M\' for menu, \'Q\' to quit): ";
    std::cin >> input;
    switch(input)
    {
      case '+': case '1':
      {
        int val;
        std::cin >> val;
        sptr -> Push(val);
        break;
      }
      case '-': case '2':
      {
        sptr->Pop();
        break;
      }
      case 'c': case 'C':
      {
        sptr->Clear();
        break;
      }
      case 't': case 'T':
      {
        std::cout << "Top of Stack: " << sptr->Top();
        std::cout << '\n';
        break;
      }
      case 'e': case 'E':
      {
        if (sptr -> Empty())
        {
          std::cout << "Stack is empty";
        }
        else
        {
          std::cout << "Stack is not empty";
        }
        std::cout << '\n';
        break;
      }
      case 's': case 'S':
      {
        std::cout << "Stack size     = " << sptr -> Size();
        std::cout << '\n';
        break;
      }
      case '=':
      {
        fsu::Stack<int, 100> stackCopy(stack);
        stackCopy.SetOFC(ofc);
        stackCopy.SetDIR(dir);
        std::cout << "CopyTest:\n";
        std::cout << "Copied object        size: " << stackCopy.Size() << std::endl;
        std::cout << "           contents: ";
        stackCopy.Display(std::cout);
        std::cout << '\n'; 

        stackAssign = stack;
        stackAssign.SetOFC(ofc);
        stackAssign.SetDIR(dir);
        std::cout << "AssignTest:" << std::endl;
        std::cout << "Original object     size " << stack.Size() << std::endl;
        std::cout << "                 contents: " <<std::endl;
        stack.Display(std::cout);
        std::cout << "Assignee object     size " << stackAssign.Size() << std::endl;
        std::cout << "                 contents: " <<std::endl;
        stackAssign.Display(std::cout);
        std::cout << std::endl;

        
        if (stack.Size()==0)
        {
            std::cout << "ConstTest: inactive on empty stack";
        }
        else
        {
            const int constTop = stack.Top();
            int top = stack.Top();
            if (top == constTop)
            {
              std::cout << "ConstTest: OK";
            }
            else
            {
              std::cout << "ConstTest: NOY OK";
            }
        }
        std::cout << std::endl;
        break;
    }
      case 'D':
      {
        std::cout << "Stack contents:   ";
        sptr -> Display(std::cout);
        std::cout << '\n';
        break;
      }
      case 'o': case 'O':
      {
        std::cin >> ofc;
        if (ofc == '0')
        {
          ofc = '\0';
        }
        else if (ofc == 'b' || ofc == 'B')
        {
          ofc = ' ';
        }
        else if (ofc == 't' || ofc == 'T')
        {
          ofc = '\t';
        }
        else if (ofc == 'n' || ofc == 'N')
        {
          ofc = '\n';
        }
        else
        {
          std::cout << " ** bad ofc: only 0, b|B, t|T, n|N accepted\n";
          break;
        }
        sptr -> SetOFC(ofc);
        break;
      }
      case '<':
      {
        dir = +1;
        sptr -> SetDIR(+1);
        break;
      }
      case '>':
      {
        dir = -1;
        sptr -> SetDIR(-1);   
        break;
      }
      case 'u': case 'U':
      {
        std::cout << "Stack Dump():" << '\n';
        sptr -> Dump(std::cout);
        break;
      }
      case 'm': case 'M':
      {
        DisplayMenu();
        break;
      }
      case 'q': case 'Q':
      {
        input = 'Q';
        break;
      }
      default:
      {
        std::cout << " command not found \n";
      }
    }
  }
  while (input != 'Q');
  std::cout << "Have a great day.\n";
  return 0;
}

void DisplayMenu()
{
  std::cout << "Push(Tval)  .............  + tval or 1 tval\n"
            << "Pop()  ..................  - or 2\n"
            << "Clear()  ................  C\n"
            << "Top()  ..................  T\n"
            << "Empty()  ................  E\n"
            << "Size()  .................  S\n"
            << "Copy tests  .............  =\n"
            << "Display()  ..............  D\n"
            << "SetOFC(ofc)  ............  O 0|b|t|n\n"
            << "SetDIR(+1)  .............  < (horizontal -->)\n"
            << "SetDIR(-1)  .............  > (vertical   ^  )\n"
            << "Dump()  .................  U\n"
            << "Display this menu  ......  M\n";
}
