#include <iostream>
#include <string>
#include <vector>
#define size 10

using namespace std;


class Stack {
private:
	string* data;
	int top;
	int capacity;

public:
	Stack() {
		capacity = size;
		data = new string[capacity];
		top = -1;
	}

	~Stack() {
		delete[] data;
	}

	void push(string item) {
		if (isFull()) {
			cerr << "Can't add more" << endl;
			return;
		}
		data[++top] = item;
	}

	string pop() {
		if (isEmpty()) {
			return " ";
		}
		return data[top--];
	}

	string peek() {
		if (isEmpty()) {
			return " ";
		}
		return data[top];
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == capacity - 1;
	}

	void clear() {
		while (!isEmpty()) {
			data[top] = " ";
			pop();
		}
	}

};

int main() {
	Stack tab;
	Stack backwardTab;

	string url;
	int choice;

	while (true) {
		cout << "For add another site '1'" << endl
			<< "For move backward '2': " << endl
			<< "For move forward '3': " << endl
			<< "For exit press '4': " << endl;

		cin >> choice;

		if (choice == 1) {
			cout << "Enter the url: ";
			cin >> url;
			tab.push(url);

			backwardTab.clear();

			cout << "Site: " << tab.peek() << endl;
		}

		else if (choice == 2) {
			if (tab.isEmpty()) {
				cout << "No site open yet can't move backward" << endl;
			}
			else {
				backwardTab.push(tab.pop());

				if (tab.peek() != " ")
					cout << "Site: " << tab.peek() << endl;

				else
					cout << "Can't move backward" << endl;
			}
		}
		else if (choice == 3) {
			if (backwardTab.isEmpty() == false) {
				tab.push(backwardTab.pop());
				if (tab.peek() != " ") {
					cout << "Site: " << tab.peek() << endl;
				}
				backwardTab.pop();
			}
			else {
				cout << "No forward history available." << endl;
			}
		}
		else if (choice == 4) {
			cout << "Thanks for using" << endl;
			return 0;
		}
		else {
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return 0;
}
