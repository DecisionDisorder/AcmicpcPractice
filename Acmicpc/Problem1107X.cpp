#include <iostream>
#include <cmath>
#include <stack>
#include <string>

using namespace std;

int ticktok(int targetNum, bool availableButtons[])
{
	int i = 0;
	while (targetNum - i >= 0 || targetNum + i < 10)
	{
		if(targetNum - i >= 0)
			if(availableButtons[targetNum - i])
				return targetNum - i;
		if(targetNum + i < 10)
			if(availableButtons[targetNum + i])
				return targetNum + i;
		i++;
	}
}

int main()
{
	int startingChannel = 100;
	int targetChannel, m, diff, buttonCount = 0;
	int ticktokResult;
	string channelPressed = "";
	stack<int> channelNumbers;
	bool isSame = true;

	cin >> targetChannel >> m;

	bool availableButtons[10] = {true, true, true, true, true, true, true, true, true, true};
	for (int i = 0; i < m; i++)
	{
		int btn;
		cin >> btn;
		availableButtons[btn] = false;
	}
		
	if(startingChannel == targetChannel)
		cout << 0 << endl;
	
	diff = abs(startingChannel - targetChannel);

	if(targetChannel == 0)
		channelNumbers.push(0);
	else {
		for (int n = targetChannel; n > 0; n /= 10)
			channelNumbers.push(n % 10);
	}
	
	while (!channelNumbers.empty())
	{
		int num = channelNumbers.top();
		channelNumbers.pop();

		if (!isSame)
		{
			if(ticktokResult > 0)
				channelPressed.append(to_string(ticktok(9, availableButtons)));
			else
				channelPressed.append(to_string(ticktok(0, availableButtons)));
			buttonCount++;
		}
		else if (availableButtons[num])
		{
			channelPressed.append(to_string(num));
			buttonCount++;
		}
		else
		{
			int t = ticktok(num, availableButtons);
			ticktokResult = num - t;
			channelPressed.append(to_string(t));
			buttonCount++;
			isSame = false;
		}
	}
	cout << "Pressed: " << channelPressed << endl;
	buttonCount += abs(targetChannel - stoi(channelPressed));

	if(diff > buttonCount)
		cout << buttonCount << endl;
	else
		cout << diff << endl;


	return 0;
}