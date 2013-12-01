#include <stdio.h>

void multiply(int _iValue1, int _iValue2, int& _iResult);
void divide(int _iValue1, int _iValue2, int& _iResult, int& _iRemainder);

int main()
{
	int	iValue1 = 65;
	int	iValue2 = 25;

	printf("%d x %d = ", iValue1, iValue2);

	int	iResult;

	multiply(iValue1, iValue2, iResult);

	printf("%d\n", iResult);

	iValue1 = 6502;
	iValue2 = 10;

	printf("%d / %d = ", iValue1, iValue2);

	int	iRemainder;

	divide(iValue1, iValue2, iResult, iRemainder);

	printf("%d remainder %d\n", iResult, iRemainder);

	return	1;
}

void multiply(int _iValue1, int _iValue2, int& _iResult)
{
	_iResult	= 0;
	
	for (int iLoop = 0; iLoop < 32; ++iLoop)
	{
		if (1 == (_iValue1 & 1))
		{
			_iResult	+= _iValue2;
		}

		_iValue1	>>= 1;
		_iValue2	+= _iValue2;
	}
}

void divide(int _iValue1, int _iValue2, int& _iResult, int& _iRemainder)
{
	_iResult	= 0;

	int	iStart2		= _iValue2;
	int	iDivisor	= 1;

	while (_iValue2 + _iValue2 < _iValue1)
	{
		_iValue2	+= _iValue2;

		iDivisor	<<= 1;
	}

	while (_iValue1 >= iStart2)
	{
		if (_iValue1 >= _iValue2)
		{
			_iResult	+= iDivisor;
			_iValue1	-= _iValue2;
		}

		_iValue2	>>= 1;
		iDivisor	>>= 1;
	}

	_iRemainder	= _iValue1;
}