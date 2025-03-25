/* 
 * Filename: numVerbalizer.cpp
 *
 * Name: Huthsady Legend Boun
 * Professor: Grace Comp
 * Class: Comp Sci II
 * Date: 3 - 25 - 2025
 *
 * Description: Program that allows a user to enter any number from 0-9999 and 
 * get the english pronunciation of that number
*/


#include <iostream>
#include <string>



class Numbers
{
public:

   Numbers(int x) : number(x) {} // Constructor


   int getNumber();        // Getters                 
   int getThouPlace();
   int getHunPlace();
   int getTenPlace();
   int getOnePlace();
   //void getPrint();
   void print();

   std::string oneThruTwenty[21] =
   {
      "", "One", "Two", "Three",
      "Four", "Five", "Six", "Seven",
      "Eight", "Nine", "Ten", "Eleven",
      "Twelve", "Thirteen", "Fourteen",
      "Fifteen", "Sixteen", "Seventeen",
      "Eighteen", "Nineteen", "Twenty"
   };

   std::string edgeCases[3] =
   {
      "Thirty", "Fifty", "Eighty"
   };


private:

   int number;       // Member

   int thouPlace(int x); // Methods
   int hunPlace(int x);
   int tenPlace(int x);
   int onePlace(int x);
};


int introduction() // Begins the program with a prompt and input
{
   int x = -1;
   while (x < 0 || x > 9999)
   {
       std::cout << "Please enter any number 0 - 9999: \n";
       std::cin >> x;
   }
   return x;
}




int Numbers::getNumber()      // Getter Definitions
{
   return number;
}

int Numbers::getThouPlace()
{
   return thouPlace(0);
}

int Numbers::getHunPlace()
{
   return hunPlace(0);
}

int Numbers::getTenPlace()
{
   return tenPlace(0);
}

int Numbers::getOnePlace()
{
   return onePlace(0);
}
/*
void Numbers::getPrint()
{
   print();
}
*/

int Numbers::thouPlace(int x)       // Method Definitions
{
   x = number;

   if (x >= 1000)
   {
      while (x >= 10)
      {
         x /= 10;
      }
      return x;
   }
   return 0;
}

int Numbers::hunPlace(int x)
{
   x = number;


   if (x >= 1000 || x >= 100)
   {
      x %= 1000;
      x /= 100;
      
      return x;
   }
   return 0;
}

int Numbers::tenPlace(int x)     // Need to make a case for 10 - 12
{
   x = number;

      x = x % 100;
      x = x / 10;
      return x;
}

int Numbers::onePlace(int x)
{
   x = number;
   
   x %= 10;

   return x;
}

void Numbers::print()
{
   int thou = getThouPlace();
   int hund = getHunPlace();
   int tens = getTenPlace();
   int ones = getOnePlace();

   if (thou > 0)
   {
      std::cout << oneThruTwenty[thou] << " Thousand ";     // Thousands place logic
   }
   
   if (hund > 0)
   {
      std::cout << oneThruTwenty[hund] << " Hundred ";      // Hundreds place logic
   }

   switch (tens)        // Tens place logic
   {
   case 0:
      std::cout << oneThruTwenty[0] << "";
      break;
   case 1:
      ones += 10;
      std::cout << oneThruTwenty[ones] << "\n";
      break;
   case 2:
      std::cout << oneThruTwenty[20] << " ";
      break;
   case 3:
      std::cout << edgeCases[0] << " ";
      break;
   case 5:
      std::cout << edgeCases[1] << " ";
      break;
   case 8: 
      std::cout << edgeCases[2] << "";
      break;
   default:
      std::cout << oneThruTwenty[tens] << "ty ";
   }


   if (ones < 10)      // Ones place logic
   {
      std::cout << oneThruTwenty[ones] << "\n";
   }
   



}


int main()     // Main function. Every cpp program needs it.
{
   int progStop = 1;

   while (progStop == 1)
   {
      Numbers userInput(introduction());


      userInput.getTenPlace();

      userInput.print();
   }
}
