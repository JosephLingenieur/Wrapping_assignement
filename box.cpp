#include "box.h"
#include <algorithm>
#include <vector>
#include <sstream>


box::box(int lenght, int width, int height) :
    m_length{lenght},
    m_width{width},
    m_height{height}
{
}

int box::calculateSurfaceArea()
{
    auto top_side = m_length * m_width;
    auto front_side = m_width * m_height;
    auto right_side = m_height * m_length;
    return 2 * (top_side + front_side + right_side);
}

int box::calculateSmallestSide()
{
    auto top_side = m_length * m_width;
    auto front_side = m_width * m_height;
    auto right_side = m_height * m_length;
    return std::min({right_side, top_side, front_side});
}

box::box(std::string line)
{
    bool delete_reference_x = false;
    unsigned int count = 0;
    int data[3];
    std::string string_data;
    for (size_t i = 0; i < line.length(); ++i)
    {
        if (line.at(i) == 'x' || line.length() == i+1)
        {
            if (line.at(i) == 'x' && delete_reference_x)
                string_data.erase(0,1);
            if (line.length() == i + 1)
            {
                string_data.append(1, line.at(i));
                string_data.erase(0, 1);
            }

            try
            {
                data[count] = std::stoi(string_data);
            }
            catch (const std::exception&)
            {
                throw "Unable to convert data properly";
            }
            string_data.clear();
            delete_reference_x = true;
            count++;
            if (count == 3)
            {
                m_length = data[0];
                m_width = data[1];
                m_height = data[2];
                box mybox(m_length, m_width, m_height);
                return;
            }
        }
        if (!(line.length() == i + 1))
            string_data.append(1, line.at(i));
    }
}

