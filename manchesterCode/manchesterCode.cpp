#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void encoder(string message, int n)
{
	bitset<8> eachByte{ NULL };

	for (int i = 0; i < n; i++)
	{
		int temp{ 15 };
		eachByte = bitset<8>(message[i]);
		bitset<16> eachByteModulated{ NULL };
		cout << endl << "character  " << message[i] << "  in ASCII Binary Form         --> " << eachByte;

		for (int k = 7; k >= 0; k = k - 1)
		{
			eachByteModulated[temp] = eachByte[k];
			if (eachByte[k] == 0)
			{
				eachByteModulated[temp - 1] = 1;
			}
			else
			{
				eachByteModulated[temp - 1] = 0;
			}
			temp = temp - 2;

		}
		temp = 0;
		cout << endl;
		cout << "character  " << message[i] << "  in Manchester Modulated Form --> " << eachByteModulated << endl << endl;

	}
}

int main()
{
	string theMessage;
	cout << "Enter the message: ";

	getline(cin, theMessage);
	int messageLength = theMessage.length();

	encoder(theMessage, messageLength);
}

