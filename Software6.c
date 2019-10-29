#include <stdio.h>

int BCD_to_DEC(int num);
void DEC_to_BCD (int arr[], int num);
void bubbleSort (int arr[], int size);

int main()
{
	printf("Please enter a five digit numbers in BCD(hex): \n");
	int x;
	scanf ("%x", &x);	
	printf("This value in decimal is: %d \n", BCD_to_DEC(x) );

	printf("Please enter a five digit number in decimal: \n");
	int d;
	scanf("%d", &d);

	int decimalArray [5];	
	DEC_to_BCD(decimalArray, d);
	printf("The digits are 1s:%d, 10s:%d, 100s:%d, 1000s:%d, 10000s:%d", decimalArray[0], decimalArray[1], decimalArray[2], decimalArray[3], decimalArray[4]);
	
	return 0;
	

}

int BCD_to_DEC(int num)
{
	int mask = 0xf;
	int ones = 0;
	int tenth = 0;
	int hundredth = 0;
	int thousandth = 0;
	int tenThousandth = 0;
	
	ones = mask & num;
	mask = mask << 4;
	
	tenth = mask & num;
	tenth = tenth >> 4;
	mask = mask << 4;

	hundredth = mask & num;
	hundredth = hundredth >> 8;
	mask = mask << 4;

	thousandth = mask & num;
	thousandth = thousandth >> 12;
	mask = mask << 4;

	tenThousandth = mask & num;
	tenThousandth = tenThousandth >> 16;


	return tenThousandth*10000 + thousandth*1000 + hundredth*100 + tenth*10 + ones;
}

void DEC_to_BCD (int arr[], int num)
{
	
	for (int i = 0; i < 5; i++)
    	{
        	arr[i] = num%10;
		num = num/10;
    	}
	
}

void bubbleSort (int arr[], int size)
{
	
}
