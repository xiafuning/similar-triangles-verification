#include <iostream>
#include <cstdlib>


void printMemory(int memory[], int size)
{
	//std::cout << "print memory" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << memory[i] << " ";
	std::cout << std::endl;
}

void bubbleSort(int dataIndex, int memory[])
{
	//printMemory(memory, 6);
	int R_1 = 0;
	int R_2 = 0;
	int dataCounter = dataIndex;
	bool flag = true;
	while (flag == true)
	{
		dataCounter = dataIndex;
		flag = false;
		while (dataCounter < dataIndex + 2)
		{
			R_1= memory[dataCounter];
			R_2= memory[dataCounter + 1];
			if (memory[dataCounter] < memory[dataCounter + 1])
			{
				memory[dataCounter + 1] = R_1;
				memory[dataCounter] = R_2;
				flag = true;
			}
			dataCounter++;
		}
	}
}

int main(int argc, char *argv[])
{
	std::cout << "---start similar triangles verfication---" << std::endl;
	// memory and parameter initialisation
	int memory[6] = {3, 3, 4, 4, 6, 8};
	int index = 0;
	int R_1 = 0;
	int R_2 = 0;
	int product_1 = 0;
	int product_2 = 0;
	if (argc != 7)
	{
		std::cerr << "Invalid number of input arguments\nPlease input the side lengths of 2 triangles" << std::endl;
		return 1;
	}
	else
	{
		for (int i = 1; i < argc; i++ )
		{
			memory[i-1] = atoi(argv[i]);
		}
	
	}
	std::cout << "initial memory" << std::endl;
	printMemory(memory, 6);

	while (index < 2)
	{
		if (index == 1)
		{
			bubbleSort(3, memory);
			std::cout << "memory after second sort" << std::endl;
			printMemory(memory, 6);
		}
		else
		{
			bubbleSort(0, memory);			
			std::cout << "memory after first sort" << std::endl;
			printMemory(memory, 6);
		}
		index++;
	}	
	R_1 = memory[0];
	R_2 = memory[4];
	product_1 = R_1 * R_2;
	R_1 = memory[1];
	R_2 = memory[3];
	product_2 = R_1 * R_2;
	if (product_1 == product_2)
	{
		R_1 = memory[0];
		R_2 = memory[5];
		product_1 = R_1 * R_2;
		R_1 = memory[2];
		R_2 = memory[3];
		product_2 = R_1 * R_2;
		if (product_1 == product_2)
			std::cout << "these 2 triangles are similar!" << std::endl;
		else
			std::cout << "these 2 triangles are not similar!" << std::endl;
	}
	else
		std::cout << "these 2 triangles are not similar!" << std::endl;
	
	return 0;
}
