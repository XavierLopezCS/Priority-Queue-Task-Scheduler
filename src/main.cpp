// 136 - Lab10 - Priority Queue

using namespace std;
#include <vector>
#include <set>
#include <iostream>
#include <string>

class PriorityQueue {
private:
	vector<pair<string, int>> elem;

public:
	PriorityQueue() {}
	bool empty() {
		return elem.empty();
	}

	size_t size() {
		return elem.size();
	}

	void push(string desc, int priority) {
		// emplace_back directly constructs the element in place using its constructor,
		elem.emplace_back(desc, priority);
		// elem.push_back(make_pair(value, priority));
	}

	string top() {
		if (empty()) {
			throw out_of_range("Priority queue is empty");
		}
		int maxPriority = elem[0].second;
		int maxIndex = 0;
		for (size_t i = 1; i < elem.size(); i++) {
			if (elem[i].second > maxPriority) {
				maxPriority = elem[i].second;
				maxIndex = static_cast<int>(i);
			}
		}

		return elem[maxIndex].first;
	}

	void pop() {
		if (empty()) {
			throw out_of_range("Priority queue is empty");
		}
		int maxPriority = elem[0].second;
		int maxIndex = 0;
		for (size_t i = 1; i < elem.size(); ++i) {
			if (elem[i].second > maxPriority) {
				maxPriority = elem[i].second;
				maxIndex = static_cast<int>(i);
			}
		}
		elem.erase(elem.begin() + maxIndex);
	}

	void print() {
		for (const auto& pair : elem) {
			cout << " (" << pair.first << ", " << pair.second << ") ";
		}
		cout << endl;
	}

	pair<string, int> peekTop() {
		if (empty()) {
			throw out_of_range("Priority queue is empty");
		}
		int maxPriority = elem[0].second;
		size_t maxIndex = 0;
		for (size_t i = 1; i < elem.size(); i++) {
			if (elem[i].second > maxPriority) {
				maxPriority = elem[i].second;
				maxIndex = i;
			}
		}
		return elem[maxIndex];
	}
};

// =========================================


class TaskScheduler {
private:
	PriorityQueue taskQueue;

public:
	TaskScheduler() {}
	bool empty() {
		return taskQueue.empty();
	}

	void addTask(string desc, int priority) {
		// emplace_back directly constructs the element in place using its constructor,
		taskQueue.push(desc, priority);
	}

	void removeTask() {
		taskQueue.pop();
	}


	/*void displayTasks() const {
		PriorityQueue temp = taskQueue;
		cout << "Displaying Tasks: " << endl;
		while (!temp.empty()) {
			cout << "(" << temp.top() << ", " << ")" << endl;
			temp.pop();
		}
	}
	*/
	void displayTasks() const {
		PriorityQueue temp = taskQueue;
		while (!temp.empty()) {
			auto topTask = temp.peekTop();
			cout << "(" << topTask.first << ", " << topTask.second << ")" << endl;
			temp.pop();
		}
	}

};
int main()
{
	int again;
	TaskScheduler task;
	string description, temp;
	int priority;

	cout << "Welcome to Priority Queue" << endl << endl;

	do {
		cout << "1: Add a task (Enter priority and description)" << endl;
		cout << "2: Remove the highest priority task and print" << endl;
		cout << "3: Display all tasks (in priority order)" << endl;
		cout << "4: Exit" << endl;
		cin >> again;
		cin.ignore();

		switch (again) {
		case 1:
			cout << "======================" << endl;
			cout << "Enter Task Description: ";
			getline(cin, description);

			cout << "Enter Task Priority: ";
			cin >> priority;
			task.addTask(description, priority);
			cout << "======================" << endl;
			break;

		case 2:
			cout << "\n======================" << endl;
			task.removeTask();
			cout << "After Removing The Highest Degree: " << endl;
			task.displayTasks();
			cout << "\n======================" << endl;
			break;

		case 3:
			cout << "\n======================" << endl;
			cout << "Displaying Tasks (from highest degree to lowest): " << endl;
			task.displayTasks();
			cout << "\n======================" << endl;
			break;

		case 4:
			cout << "Exiting Program" << endl;
			break;

		default:
			cout << "Invalid input, try again." << endl;
			break;
		}
	} while (again == 1 || again == 2 || again == 3);

	return 0;

}
