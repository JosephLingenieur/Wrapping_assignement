
#include <iostream>
#include "box.h"
#include "filex.h"

//Find the assignement here : https://adventofcode.com/2015/day/2

int main()
{
	std::cout << "***********start********** \n";
	data_file file("data.txt");
	box present(0, 0, 0);
	auto my_boxes = file.read();
	int my_result = 0;
	for (auto the_box : my_boxes)
	{
		my_result += the_box.calculateSmallestSide() + the_box.calculateSurfaceArea();
		std::cout << "->" << my_result << std::endl;
	}

    return 0;
}
