#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <cstdint>
#include <cstddef>


class MyObj {
	public:
		int iVal;
	MyObj(int val) {
		iVal = val;
	}


};
int* makeArray(int* a) {

        a = new int[3];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	return  a;
}

void copyArray() {
	uint8_t byteArr[4] = { 1, 2, 3, 4 };
	double dblArr[4];
	double* tempArr = (double*) byteArr;
	memmove(&dblArr, tempArr, 4);
	for (int i=0; i < 4; i++) {
		printf(" Index:%d:Val:%F\n", i, dblArr[i]);
		printf(" Index:%d:TempVal:%F\n", i, tempArr[i]);
		printf(" Index:%d:byteVal:%u\n", i, byteArr[i]);

	}

}

void checkObj(MyObj* pObj) {
	delete pObj;
}

int main() {
	int* a = new int[3];//nullptr;
	makeArray(a);
        int* b = a;
        //delete b;
	for (int i=0; i < 3; i++)
		printf("Index:%d: Value:%d\n", i , a[i]);

	copyArray();
	uint8_t number1 = 0xBF;
	uint8_t number2 = 0xBF;
	if (number1 ^ number2) 
		printf("Numbers %u : %u are NOT Equal\n", number1, number2);
	else if ((number1 ^ number2) == 0)  
		printf("Numbers %u : %u are Equal\n", number1, number2);
	//uint8_t myNumber = 10;
	//std::byte myByte = myNumber;
	//printf("Assigned value to byte is :%X\n", myByte); 
	MyObj obj1 = MyObj(5);
	printf("objVal:%d\n", obj1.iVal);
	printf ("Valid:%d\n", (&obj1 == NULL));
	checkObj(&obj1);
	if (&obj1 == NULL)
		printf ("ValidSecond:\n");
	//printf("objVal:%d\n", obj1.iVal);
	return 0;
}



