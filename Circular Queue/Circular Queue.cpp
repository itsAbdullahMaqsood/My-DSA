#include <iostream>		//The problem with the queue Data Structure is that if some of the values
#include <conio.h>		//have been dequeued, the rear is still 4 and isFUll() still returns true
using namespace std;	//since the array is still full, new values can't be added unless the whole
						//array has been emptied and Rear and Front become '-1'

class Queue {
	int arr[5];
	int size = sizeof(arr) / sizeof(arr[0]);
public:
	int Front = -1, Rear = -1;
	Queue() {
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}

	bool isFull() {
		if (Front == Rear + 1 % size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() {
		if (Rear == Front && Front == -1) {
			return true;
		}
		else
			return false;
	}

	void enqueue(int value) {
		if (isEmpty()) {
			Rear++;
			Front++;
			arr[Rear] = value;
		}
		else if (!isFull()) {
			Rear++;
			Rear %= size;
			arr[Rear] = value;
		}
		else {
			cout << "Queue overflow";
		}
	}

	int dequeue() {
		int x = 0;
		if (isEmpty()) {
			cout << "Queue underflow";
			return 0;
		}
		else if (Rear == Front && Rear != -1) {
			x = arr[Front];
			arr[Front] = 0;
			Rear = Front = -1;
			return x;
		}
		else {
			if (Front >= 0) {
				x = arr[Front];
				arr[Front] = 0;
				Front++;
				Front %= size;
				return x;
			}
		}
	}

	int co() {
		return ((sizeof(arr) / sizeof(arr[0])) - 1);
	}

	int count() {
		if (Rear == Front && Front == -1) {
			return 0;
		}
		else
			return (Rear - Front + 1);
	}

	void display() {
		for (int i = 0; i < size; i++)
		{
			cout << "   " << arr[i];
			cout << "\t";
		}
	}


};

int main() {

	int value, selection;
	Queue q;
	do {
		cout << "1.enqueue \n2.dequeue \n3.isFull \n4.isEmpty \n5.count \n6.display";
		cout << "\n\nselection: ";
		cin >> selection;
		cout << endl << endl << endl;
		switch (selection) {
			cout << "\n";
		case 1:
			cout << "value: ";
			cin >> value;
			q.enqueue(value);
			break;
		case 2:
			cout << "The dequeued value is : " << q.dequeue();
			break;
		case 3:
			cout << q.isFull();
			break;
		case 4:
			cout << q.isEmpty();
			break;
		case 5:
			cout << q.count();
			break;
		case 6:
			q.display();
			break;
		}
		cout << "\nFront: " <<q.Front << endl;
		cout << "Rear: " <<q.Rear << endl ;
		q.display();
		_getch();
		system("cls");
	} while (true);


	return 0;
}