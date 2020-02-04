#ifndef BOX_H
#define BOX_H

#include <vector>
#include <string>

/**
 *
 * This class create boxes and make the rigth calculation for each boxe.
 *
 */
class box
{
public:
    /**
     * @brief box will be only be use to initialise it own parameters.
     *
     * @param length    The length of each present.
     * @param width     The width of each present
     * @param height    The height of each present
     */
    box(int lenght, int width, int height);

    /**
     * @brief Calculate the surface area of each present.
     *
     * @return  Return the calculated surface area of each present.
     */
    int calculateSurfaceArea();

    /**
     *@brief  Calculate the smallest side of eacht present.
     *
     * @return   Return the calculated area of each smallest side.
     */
    int calculateSmallestSide();

    /**
     * @brief   Read every data line and store those data in one box.
     *
     * @param   A line in the form "int 'x' int 'x' int", with the dimensions of the box.
     *
     * @return
     */
     box(std::string line);

private:
    int m_length;
    int m_width;
    int m_height;
};

#endif

