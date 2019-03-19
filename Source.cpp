#include <string>
#include <iostream>

using namespace std;

class PatientAccount
{
	//static variables
	static float medicalCost;
	static float surgeryCost;
	static float totalCost;
		//Public local variables of the class
public:

	int numberOfDays;
	int surgery;
	//float addedCost updates more costs.
	void setmedical(float addedCost)
	{
		//checks if value is garbage
		if (medicalCost < 0)
		{
			medicalCost = 0;
		}
		medicalCost = medicalCost + addedCost;
		cout << "New medical cost is : $" << medicalCost << endl;
	}
	//float addedCost updates costs
	void setSurgery(float addedCost)
	{
		if (surgeryCost < 0)
		{
			surgeryCost = 0;
		}
		surgeryCost = surgeryCost + addedCost;
		cout << "New surgery cost is: $" << surgeryCost << endl;
	}
	// day spent in the hospital
	float total(int day)
	{
		totalCost = 0;
		numberOfDays = day;
		//calculate total charge
		totalCost = (medicalCost + surgeryCost) + (numberOfDays* 50);
		return totalCost;
	}
};

//declare static variables of the class
float PatientAccount::medicalCost;
float PatientAccount::surgeryCost;
float PatientAccount::totalCost;

class pharmacy :public PatientAccount
{
public:
	static string medication[5];
	//array for medication prices
	static float medicinePrice[5];
	PatientAccount patient;
	void update(int x)
	{
		float medicineCost = medicinePrice[x];
		patient.setmedical(medicineCost);
		float addedCost = medicinePrice[x];
		patient.setmedical(addedCost);
	}
};
//Name of the medications
string pharmacy::medication[5] = { "Antibiotic", "Pain killers","Antidepressant",
								"Antioxidants","Antiviralents" };
float pharmacy::medicinePrice[5] = { 75.00, 375.00, 135.00, 50.00, 125.00 };

class surgery : public PatientAccount
{
public:
	static string surgeryType[5];
	static float surgeryPrice[5];
	PatientAccount patient;
	//place is the slot
	void update(int place)
	{
		//cost of the surgery
		float addedCost = surgeryPrice[place];
			//adds the surgery costs
			patient.setSurgery(addedCost);
	}
};
//surgery Types
string surgery::surgeryType[5] = { "Heart Surgery","Cataract Surgery", "Tonsillectomy",
								  "Prostatectomy", "Mastectomy" };
//Cost of each surgery
float surgery::surgeryPrice[5] = { 4125.00, 650.00, 125.00, 700.00, 2130.00 };

int main()
{
	int surgeryLoop = 0;
	int medicineLoop = 0;
	int medicationNumber;
	int surgeryDone;
	int days;
	int moreMedication;
	float total;

	surgery medicalProcedure;
	PatientAccount patient;
	pharmacy medicine;

	cout << "Hospital Billing\n";
	cout << "\nSurgery types available\n";

	//prints the surgery types
	while (surgeryLoop < 5)
	{
		cout << surgeryLoop + 1 << ".";
		cout << medicalProcedure.surgeryType[surgeryLoop] << "\n"; 
		surgeryLoop++;
	}
	//User input
	cout << "\n Enter surgery numbered performed: ";
	cin >> surgeryDone;
	medicalProcedure.update(surgeryDone - 1);
	cout << "Types of medication\n";
	//medication loop
	while (medicineLoop < 5)
	{
		cout << medicineLoop << " . "; 
		cout << medicine.medication[medicineLoop] << "\n";
		medicineLoop++;
	}
	do
	{
		cout << "Enter medications used: ";
		cin >> medicationNumber;

		medicine.update(medicationNumber - 1);
		cout << "\n Enter 1 to enter more medication 0 to continue Billing: ";
		cin >> moreMedication;

	} while (moreMedication == 1);
	//charging 50 dollars for stay per day
	cout << "Each day is $50 to stay at the hospital.\n";
	cout << "Enter how many days you spend in the hospital: ";
	cin >> days;
	total = patient.total(days);
	cout << "\n Total medical bills: $" << total;
	return 0;
}