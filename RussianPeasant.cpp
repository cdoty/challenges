#include <stdio.h>

void multiply(int _iValue1, int _iValue2, int& _iResult);

int main()
{
	int	iValue1 = 25;
	int	iValue2 = 25;

	printf("%d x %d = ", iValue1, iValue2);

	int	iResult;

	multiply(iValue1, iValue2, iResult);

	printf("%d\n", iResult);

	return	0;
}

void multiply(int _iValue1, int _iValue2, int& _iResult)
{
	_iResult	= 0;
	
	while (_iValue2 > 0)
	{
		if (_iValue2 & 1)
		{
			_iResult	+= _iValue1;
		}

		_iValue1	<<= 1;
		_iValue2	>>= 1;
	}
}
