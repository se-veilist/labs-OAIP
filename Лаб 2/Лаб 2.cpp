//Имеются две упорядоченные очереди (одно- или двунаправленная),
//элементами которых являются целые числа.Объединить эти очереди в одну
//упорядоченную очередь.
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void sort(queue<int>& queue4)
{
	vector<int> vect;
	while (!queue4.empty())
	{
		vect.push_back(queue4.front());
		queue4.pop();
	}
	sort(vect.begin(), vect.end());
	for (int i : vect)
	{
		queue4.push(i);
	}
}

queue<int> makeQueues(std::queue<int>& queue1, queue<int>& queue2)
{
	queue<int> queue3;
	while (!queue1.empty() && !queue2.empty())
	{
		if (queue1.front() < queue2.front())
		{
			queue3.push(queue1.front());
			queue1.pop();
		}
		else
		{
			queue3.push(queue2.front());
			queue2.pop();
		}

	}
	return queue3;

}

int main()
{
	setlocale(LC_ALL, "");

	queue<int> queue1;
	cout << "Введите элементы очереди 1" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		int a;
		cin >> a;
		queue1.push(a);
	}

	queue<int> queue2;
	cout << "Введите элементы очереди 2" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		int a;
		cin >> a;
		queue2.push(a);
	}

	queue<int> makeQueue = makeQueues(queue1, queue2);
	sort(makeQueue);
	cout << "Объединённая очередь - ";
	while (!makeQueue.empty())
	{
		cout << makeQueue.front();
		makeQueue.pop();
	}
}
