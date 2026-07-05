#include <fstream>
#include <iostream>
 
int main() 
{
    int ivalue;
    int j = 0;
    try
    {
        std::ifstream in("in.txt");
	std::cout << in.is_open();
	std::cout << in.fail();
        in.exceptions(std::ifstream::failbit); // may throw
        in >> ivalue; // may throw
	std::cout << in.fail();
	std::cout << "finished with  file:";
        in.close();
    }
    catch (const std::ios_base::failure& fail)
    {
        // handle exception here
	//std::cout << in.fail() << ":value of in.fail() Exception block\n";
        std::cout << fail.what() << '\n';
    }

    for (int i=0x800;i<=0xBFF;i++)
	j++;
    std::cout << " LoopCount:" << j << std::endl;

    return 0;
}
