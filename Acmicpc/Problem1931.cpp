#include <iostream>
#include <list>

using namespace std;

class MeetingTime 
{
public:
	int startTime;
	int endTime;

	void setTime(int startTime, int endTime)
	{
		this->startTime = startTime;
		this->endTime = endTime;
	}

	int compare(const MeetingTime otherMeeting)
	{
		if (startTime < otherMeeting.startTime)
			return -1;
		else if (startTime > otherMeeting.startTime)
			return 1;
		else
		{
			if (endTime < otherMeeting.endTime)
				return -1;
			else if (endTime > otherMeeting.endTime)
				return 1;
			
			return 0;
		}
	}

	bool checkOverlap(const MeetingTime otherMeeting)
	{
		if (startTime >= otherMeeting.endTime)
			return false;
		else if (endTime <= otherMeeting.startTime)
			return false;
		else
			return true;
	}
};

void merge(MeetingTime* times, MeetingTime* sorted, int left, int mid, int right)
{
	int s = left, l = left, r = mid + 1;
	while (l <= mid || r <= right)
	{
		if (l <= mid && r <= right)
		{
			if (times[l].compare(times[r]) <= 0)
				sorted[s++] = times[l++];
			else
				sorted[s++] = times[r++];
		}
		else if (l <= mid)
		{
			sorted[s++] = times[l++];
		}
		else if (r <= right)
		{
			sorted[s++] = times[r++];
		}
	}

	for (int i = left; i <= right; i++)
		times[i] = sorted[i];
}

void partition(MeetingTime* times, MeetingTime* sorted, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		partition(times, sorted, left, mid);
		partition(times, sorted, mid + 1, right);
		merge(times, sorted, left, mid, right);
	}
}

void sort(MeetingTime* times, int n)
{
	MeetingTime* sorted = new MeetingTime[n];
	partition(times, sorted, 0, n - 1);

	delete[] sorted;
}

int getMeetingTeamAmount(MeetingTime* times, int n)
{
	list<MeetingTime*> meetingList;

	meetingList.push_back(times);
	for (int i = 1; i < n; i++)
	{
		if (times[i].checkOverlap(*meetingList.back()))
		{
			if (times[i].endTime < meetingList.back()->endTime)
			{
				meetingList.pop_back();
				meetingList.push_back(times + i);
			}
		}
		else
			meetingList.push_back(times + i);
	}

	return meetingList.size();
}

int main()
{
	int n;
	scanf("%d", &n);
	MeetingTime* meetingTimes = new MeetingTime[n];

	for (int i = 0; i < n; i++) 
	{
		int start, end;
		scanf("%d %d", &start, &end);
		meetingTimes[i].setTime(start, end);
	}

	sort(meetingTimes, n);

	printf("%d\n", getMeetingTeamAmount(meetingTimes, n));
		
	delete[] meetingTimes;

	return 0;
}