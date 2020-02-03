#include<iostream>  
#include <fstream>
  
using namespace std; 
  
// main function - 
// g++ -std=c++17 t_c17.cpp -o


int main() 
{
    short count = 0;
    std::string str1;
    int l = 0;
    int w = 1;
    int h = 2;
    int data[3] = {0, 0, 0};
    ifstream file("data");
    string databuffer;
    long total_square_feet;
    
    while (file && getline(file, databuffer))
    {
        if (databuffer.length() == 0)
        {
            cout << "databuffer is 0" << endl;
            continue;
        }            
        bool deleteX = false;
        count = 0;
        for (unsigned datachar = 0; datachar < databuffer.length(); ++datachar)
        {           

            if (databuffer.at(datachar) == 'x' || (databuffer.length() == datachar + 1) )
            {
                //get the right char
                if (databuffer.at(datachar) == 'x')
                {
                    if (deleteX)
                            str1.erase(0,1);
                    // cout << "i is " << datachar << " string is " << str1 << endl;

                }
                        
                if(databuffer.length() == datachar + 1)
                {
                    str1.append(1, databuffer.at(datachar));
                    str1.erase(0, 1);
                    // cout << "i is " << datachar << " string is " << str1 << endl;
                }

                //conversion
                try
           {               
                data[count] = std::stoi (str1);
                // cout << "data [count] is: " << data[count] << " count is "<< count << endl;
           }
           catch(const std::exception& e)
           {
               std::cerr << "error: Bad input -> "<< e.what() << '\n';
           }

                //reset
                str1.clear(); //str1 = "";
                deleteX = true;
                count ++;

                //calcultate everything
                if (count == 3)
                {
                 long  squareFeet = 2 * (data[l] * data[w] +  data[w] * data[h] + data[h] * data[l]);   
                 cout << "squareFeet: " << squareFeet << endl; 
                 int smallest_side= data[l] * data[w];
                 if (smallest_side> (data[w] * data[h]))
                        smallest_side = data[w] * data[h];
                 if (smallest_side> (data[h] * data[l]))
                        smallest_side = data[h] * data[l];
                 cout << smallest_side << "<----" << endl; 
                 total_square_feet += smallest_side + squareFeet;
                }
            }
            if (!(databuffer.length() == datachar + 1))
            {
                str1.append(1, databuffer.at(datachar));
            }
        }

        cout << "total_square_feet =>  " << total_square_feet << endl;
        cout << "-------------<>--------------" << endl;
    }

    //read data (from file or website)
    //print data
    //calcultate line by line
    return 0;
}
