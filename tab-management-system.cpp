#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack {
private:
	string* data;
	int top;
	int capacity;

public:
	Stack(int size) {
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
			cerr << "No site open yet can't move backward" << endl;
			return " ";
		}
		return data[top--];
	}

	string peek() {
		if (isEmpty()) {
			cerr << "No site open yet" << endl;
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
};

int main() {
	Stack stack(10);

	string url;
	vector<string> lastSite;
	int choice, index = -1;

	while (true) {
		cout << "For add another site '1'" << endl
			<< "For move backward '2': " << endl
			<< "For move forward '3': " << endl
			<< "For exit press '4': " << endl;

		cin >> choice;

		if (choice == 1) {
			cout << "Enter the url: ";
			cin >> url;
			stack.push(url);

			cout << "Site: " << stack.peek() << endl;
		}
		else if (choice == 2) {
			lastSite.push_back(stack.pop());
			index++;
			if (lastSite[index] != " ") {
				cout << "Site: " << stack.peek() << endl;
			}
		}
		else if (choice == 3) {
			if (index >= 0) {
				stack.push(lastSite[index]);
				cout << "Site: " << stack.peek() << endl;
				lastSite.erase(lastSite.begin() + index);
				index--;
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
