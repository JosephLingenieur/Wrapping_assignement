#include <iostream>
#include <fstream>
#include <algorithm>


// main function -
// g++ -std=c++17 t_c17.cpp -o

class Mydata
{
private:
    int l, w, h;

public:
    Mydata(int a, int b, int c) : l(a), w(b), h(c){};

    long readfile(std::istream &your_file, std::string your_databuffer, std::string data_char)
    {
        long total_square_feet;
        int data[3];
        short count;
        while (your_file && getline(your_file, your_databuffer))
        {
            if (your_databuffer.length() == 0)
            {
                //cout << "databuffer is 0" << endl;
                continue;
            }
            bool deleteX = false;
            count = 0;
            for (unsigned index = 0; index < your_databuffer.length(); ++index) // replace with size_t
            {

                if (your_databuffer.at(index) == 'x' || (your_databuffer.length() == index + 1))
                {
                    //get the right char
                    if (your_databuffer.at(index) == 'x')
                    {
                        if (deleteX)
                            data_char.erase(0, 1);
                        // cout << "i is " << index << " string is " << data_char << endl;
                    }

                    if (your_databuffer.length() == index + 1)
                    {
                        data_char.append(1, your_databuffer.at(index));
                        data_char.erase(0, 1);
                        // cout << "i is " << index << " string is " << data_char << endl;
                    }

                    //conversion
                    try
                    {
                        data[count] = std::stoi(data_char);
                    }
                    catch (const std::exception &e)
                    {
                        //std::cerr << "error: Bad input -> " << e.what() << '\n';
                        return 1;
                    }

                    //reset
                    data_char.clear(); //data_char = "";
                    deleteX = true;
                    count++;

                    //calcultate everything
                    if (count == 3)
                    {
                        long squareFeet = 2 * (data[l] * data[w] + data[w] * data[h] + data[h] * data[l]);
                         //cout << "squareFeet: " << squareFeet << endl;
                        int smallest_side = data[l] * data[w];
                        if (smallest_side > (data[w] * data[h]))
                            smallest_side = data[w] * data[h];
                        if (smallest_side > (data[h] * data[l]))
                            smallest_side = data[h] * data[l];
                       int smallest_side_  = std::min ( data[h] * data[l] , std::min (data[l] * data[w], data[w] * data[h])); // not readable
                        //  cout << smallest_side << "<----" << endl;
                        total_square_feet += smallest_side_ + squareFeet;
                    }
                }
                if (!(your_databuffer.length() == index + 1))
                {
                    data_char.append(1, your_databuffer.at(index));
                }
            }
        }
        //cout << "<=return =>  " << total_square_feet << endl;
        return total_square_feet;
    }
};

class box
{
    public:

    box(){}

    void dimension ()
    {
        /**
         * @brief  I dont know if I have to use set en get || or struck zie struck
         * 
         */
    }

    struct dimension
    {
        int length;
        int width;
        int heigth;
    };

    int smallest_side()
    {
        return 0;
    }

    long surface_area_box()
    {
        /* here the process */
        /* That will also contain calcultating() */
        return 0;
    }
    
    long calcultate_surface_area ()
    {
        return 0;
    }

    void readfile_iftream(const char *input_file)
    {
        
        std::ifstream myfile (input_file);
        if (myfile.is_open())
        {
            int i;
            std::string line;
            while (getline(myfile, line))
            {
                ++i;
                std::cout << " line number " << i << ": "<<line << '\n';
            }
            myfile.close();
        }

        else
            std::cout << "Unable to open file";
    }

    void readfile_istream (const char *input_file)
    {
        std::filebuf fb;
        if (fb.open(input_file, std::ios::in))
        {
            std::istream File(&fb);
            while (File)
                std::cout << char(File.get());
                std::cout << "--END---" << std::endl;
            fb.close();
        }
    }


private:

};



int main()
{
    std::ifstream file1("data");
    std::string databuffer;
    std::string data;
    Mydata t(0, 0, 0);
    std::cout << "total square feet is: " << t.readfile(file1, databuffer, data) << std::endl;

    return 0;
}

