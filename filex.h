#ifndef FILEX_H
#define FILEX_H

#include <fstream>
#include "box.h"

/**
 * This class open, read and save data of any ASCII file in boxes.
 *
 */
class data_file
{
public:
    /**
    * @brief   Open any ASCII file.
    *
    * @param   Use to calculate the surface of each present.
    */
	data_file(std::string your_file);

    /**
     * @brief   Read every data available line by line and store those data in boxes.
     *
     * @return   Return all saved boxes made during the reading process.
     */
    std::vector<box> read();

private:
	std::ifstream m_file;
};


#endif