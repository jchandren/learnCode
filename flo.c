#include<stdio.h>
#include<stdint.h>
#include<math.h>
int main() {
	uint32_t num = 23065;
        float divisor = 100.0;
	//float factor = 0.01;
	double factor = 0.01;
	float result;
	//double divisor = 100.0;
        printf("%u:%f:\n", num, (float)num/100);
	printf("%u:%.2f:\n", num, num/100.0);


	printf("%u:%f:%f:%f:%f\n", num, (float)num/100, (double)num/100, (float)num/100.0, (double)num/100.0);
        result = round(num * factor);
	printf("%u:%f:%f:%f:%f\n", num, num*factor, (double)num*factor, (float)num*factor,result);
	printf("%u:%f:%f:%f:%f:%f\n", num, (float)num/divisor, (double)num/divisor, ((float)(num))/divisor, (float)(num/divisor),(float)num/(float)divisor);
}

