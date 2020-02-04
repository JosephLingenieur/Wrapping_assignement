#include "filex.h"

data_file::data_file(std::string your_file)
{
	m_file.open(your_file);
	if (!m_file.is_open())
		throw "Unable to open file";
}

std::vector<box> data_file::read()
{
    std::vector<box> boxes;
    std::string data_by_line;
    while (std::getline(m_file, data_by_line))
    {
        boxes.push_back(box(data_by_line));
    }
    return boxes;
}

