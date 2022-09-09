/*//201RDB090 Andrejs Pētersons
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void addNewBus(map<string, vector<string>>& buses);
void printAllBuses(const map<string, vector<string>>& buses);
void stopInfo(map<string, vector<string>>buses);

int main() {

	map<string, vector<string>> buses;

	while (true) {
		string cmd;
		cout << "command:>";
		cin >> cmd;

		if (cmd == "done")
			break;

		if (cmd == "add") {
			addNewBus(buses);
			continue;
		}

		if (cmd == "print") {

			printAllBuses(buses);
			continue;
		}
		if (cmd == "stop") {
			stopInfo(buses);
			//cout<<"stop command:"<<endl;
			continue;
		}
	}

	return 0;
}
void addNewBus(map<string, vector<string>>& buses) {
	string bus;
	cout << "bus #: ";
	cin >> bus;

	int stop_count;
	cout << "count of stops: ";
	cin >> stop_count;

	vector<string>& listOfStops = buses[bus];
	listOfStops.resize(stop_count);

	cout << "stops:" << endl;
	for (string& stop : listOfStops) {
		cin >> stop;
	}
}

void printAllBuses(const map<string, vector<string>>& buses) {
	if (buses.empty()) {
		cout << "No buses" << endl;
	}
	else {
		for (const auto& bus_item : buses) {
			cout << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				cout << stop << " ";
			}
			cout << endl;
		}
	}
}

void stopInfo(map<string, vector<string>>buses) {
	//bus_item.first->bus name,ключ(bus_item.second->pieturas nosaukums)
	string stopname;
	bool Stopexist;
	map<string,vector<string>>names;
	cout << "input stop:";
	cin >> stopname;
	cout << "Pietura " << stopname << " ievadita " << endl;
	for (const auto bus_item : buses) {
		for (const string stop : bus_item.second) {
			if (stopname == stop) {
				Stopexist = true;
				cout << "result:";
				cout << bus_item.first<<" ";
				continue;
			}
		
		}
	}
	if (!Stopexist) {
		cout << "Net sovpadenij";
	}


}*/