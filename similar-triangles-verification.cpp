#include <iostream>


void printMemory(int memory[], int size)
{
	//std::cout << "print memory" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << memory[i] << std::endl;
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



int main(int argc,char *argv[])
{
	std::cout << "---start similar triangles verfication---" << std::endl;
	// memory and parameter initialisation
	int memory[6] = {3, 3, 4, 4, 6, 8};
	int index = 0;
	//int dataCounter, flag;
	int product_1 = 0;
	int product_2 = 0;

	while (index < 2)
	{
		if (index == 1)
		{
			bubbleSort(3, memory);
			printMemory(memory, 6);
		}
		else
		{
			bubbleSort(0, memory);
			printMemory(memory, 6);
		}
		index++;
	}

	product_1 = memory[0] * memory[4];
	product_2 = memory[1] * memory[3];

	if (product_1 == product_2)
		std::cout << "these 2 triangles are similar!" << std::endl;
	else
		std::cout << "these 2 triangles are not similar!" << std::endl;
	
	return 0;
}




