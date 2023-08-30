#include <iostream> 
#include <string>
using namespace std; 

// No Change is allowed in header files
// Clearly Mark your changes with comments

// Moved function prototype to proper place at beginning of program.
void timeOnJob(int arvHr, int arvMin, bool arvIsAM,
		int depHr, int depMin, bool depIsAM);

int main()
{
	string employeeName;
	int arrivalHr;
	int arrivalMin; // This needed to be declared
	int departureHr; 
	int departureMin;
	bool arrivalAM; // This also needed to be declared 
	bool departureAM;
	char response; 
	char discard; 
	char isAM;

	cout << "This program calculates the total time spent by an " << "employee on the job." << endl;
	cout << "To run the program, enter (y/Y: ";
	cin >> response;
	cout << endl;
	cin.get(discard);

	while (response == 'y' || response == 'Y')
	{
		cout << "Enter employee's name: ";
		getline(cin, employeeName);
		cout << endl;

		cout << "Enter arrival hour: ";
		cin >> arrivalHr;
		cout << endl;
		cout << "Enter arrival minute: ";
		cin >> arrivalMin;
		cout << endl;
		cout << "Enter (y/Y) if arrival is before 12:00PM: ";
		cin >> isAM;
		cout << endl;

		// This needed to be moved here because we need to wait until we have received data for "isAM"
		if (isAM == 'y' || isAM == 'Y')
			arrivalAM = true;
		else 
			arrivalAM = false;

		cout << "Enter departure hour: ";
		cin >> departureHr;
		cout << endl;
		cout << "Enter departure minute: ";
		cin >> departureMin;
		cout << endl;
		cout << "Enter (y/Y) if departure is before 12:00PM: ";
		cin >> isAM;
		cout << endl;

		// This needed to be moved here because we need to wait until we have received updated data for "isAM"
		if (isAM == 'y' || isAM == 'Y')
			departureAM = true;
		else
			departureAM = false;
		
		cout << employeeName << endl;
		timeOnJob(arrivalHr, arrivalMin, arrivalAM,
			departureHr, departureMin, departureAM);

		cout << "Run program again (y/Y): ";
		cin >> response;
		cout << endl;
		cin.get(discard);
	}

	return 0;
}

void timeOnJob(int arvHr, int arvMin, bool arvIsAM,
	int depHr, int depMin, bool depIsAM)
{
	int arvTimeInMin;
	int depTimeInMin;
	int timeOnJobInMin;

	// Moved this to its proper place. We need to convert the time to minutes to be used in calculations later on
	arvTimeInMin = arvHr * 60 + arvMin;
	depTimeInMin = depHr * 60 + depMin;

	// Removed unnecessary "else" before the if statement and added overnight condition that wasn't accounted for 
	if (arvIsAM == true && depIsAM == false || arvIsAM == false && depIsAM == true)
	{
		timeOnJobInMin = (720 - arvTimeInMin) + depTimeInMin;
		cout << "Time spent of job: "
			<< timeOnJobInMin / 60 << " hour(s) and "
			<< timeOnJobInMin % 60 << " minutes." << endl;
	} else if ((arvIsAM == true && depIsAM == true)
		|| (arvIsAM == false && depIsAM == false))
	{
		if (arvTimeInMin <= depTimeInMin)
		{
			timeOnJobInMin = depTimeInMin - arvTimeInMin;
			cout << "Time spent of job: "
				<< timeOnJobInMin / 60 << " hour(s) and "
				<< timeOnJobInMin % 60 << " minutes." << endl;
		}
		else
			cout << "Invalid input." << endl;
	}

	else
		cout << "Invalid input." << endl;
}
