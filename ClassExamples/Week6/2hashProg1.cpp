

#include <iostream>
#include <string>
using namespace std;
#define MAX 7 

int main() {
	bool full = false;   
	char inputLine[80] = "";
	int hashValue, modHash, i;
	string name[MAX];  
	int firstHash[MAX];  
	bool occupied[MAX] = { MAX * false };
	cout << "Please enter each string of characters followed by <Enter>." << endl
		<< "Terminate by entering EOF on keyboard (control-z in Windows)." << endl;
	while (!cin.eof() && full == false) { 
		cin.getline(inputLine, 80);
		if (!cin.eof()) {
			hashValue = 0; 
			for (i = 0; i < strlen(inputLine); i++) {
				hashValue += (int)inputLine[i];
			}
			modHash = hashValue % MAX;	
			if (occupied[modHash] == false) {
				name[modHash] = inputLine;
				firstHash[modHash] = modHash;
				occupied[modHash] = true;
				cout << "Your input line " << inputLine << " hashes to "
					<< modHash << endl;
			}
			else   
			{
				cout << "Hash collision! We need to find an open table entry." << endl;
				bool found = false; 
				for (i = 0; i < MAX && found == false && full == false; i++) {
					if (occupied[i] == false) {  
						name[i] = inputLine; 
						firstHash[i] = modHash;
						occupied[i] = true;
						cout << "Your input line " << inputLine
							<< " hashes to " << i << endl;
						found = true; // Set array position found
					}
					else
						if (i >= MAX - 1) {
							cout << "Sorry! Table is full!" << " We cannot place your entry."
								<< endl << endl;
							full = true;  
						}
				}
			}
		}
	}
	for (i = 0; i < MAX; i++)  
		if (occupied[i] == true)
			cout << " Position in table is " << i << " Hashed to " << firstHash[i]
			<< ".\tString is " << name[i] << endl;
	return 0;
}
