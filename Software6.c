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
	printf("The digits are 1s:%d, 10s:%d, 100s:%d, 1000s:%d, 10000s:%d \n", decimalArray[0], decimalArray[1], decimalArray[2], decimalArray[3], decimalArray[4]);
	
	printf("Please enter 8 numbers to sort: \n");
	int bubbleArray [8];
	for (int a = 0; a <8; a++)
		{
			int value;
			scanf("%d", &value);
			bubbleArray[a] = value;
		}
    bubbleSort(bubbleArray,8);
	printf("Your sorted array is: %d, %d, %d, %d, %d, %d, %d, %d ", bubbleArray[0], bubbleArray[1], bubbleArray[2], bubbleArray[3], bubbleArray[4], bubbleArray[5], bubbleArray[6], bubbleArray[7]);
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
    int temp;
    int begin = 0;
    for (int end = size - 1; end >= 0; end --)
        {
            begin = 0;
            for (int i = 0; i < end; i++)
            {
                if (arr[begin] > arr[begin + 1])
                {
                    temp = arr[begin];
                    arr[begin] = arr[begin + 1];
                    arr[begin+1] = temp;
                }
                begin = begin + 1;
            }
            
        }
}
