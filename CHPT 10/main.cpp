
// Bryan Carranza
/* This program converts ROMAN NUMERALS to POSITIVE INTEGERS. The program prompts the user to input Roman numeral values, and then outputs the values in either Roman numerals or positive integers at the request of the user*/



#include <iostream>
#include <string>

using namespace std;

class romanType // Identifies romanType class
{
    
private:
    string romanVal;
    int integerVal;
    
public:
    romanType();
    void setRomVal(string romanVal);
    void convertToInt();
    void printNumber(char request);
};

int main()
{
    romanType rType;
    string romVal;
    char request;
    
    cout << "Welcome to the Roman numeral converter!" << endl << endl; // Welcome notice to identify program
    
    cout << "Please enter Roman numerals: "; // Prompts user to tner Roman numerals for conversion
    cin >> romVal;
    cout << endl;
    
    rType.setRomVal(romVal);
    rType.convertToInt();
    
    cout << "Press 'R' for Roman numeral value or 'P' for positive integer value (Please ensure Roman numerals are capitalized.): "; /* Prompts user to request either Roman numeral value or positive integer value*/
    cin >> request;
    cout << endl;
    rType.printNumber(request);
    
    while (request != 'R' && request != 'P') // Notifies user of invalid input and allows re-input
    {
        cout << "Invalid selection. Please enter 'R' for Roman numerals or 'P' for positive integers: ";
        cin >> request;
        cout << endl;
        rType.printNumber(request);
    }
    
    return 0;
}

romanType::romanType() // Sets initial Roman numeral and integer values to zero
{
    romanVal= " ";
    integerVal= 0;
}

void romanType::setRomVal(string romVal)
{
    romanVal = romVal;
}

void romanType::convertToInt() // Converts Roman numeral input to integer value
{
    char current = '0';
    char next = '0';
    
    current = romanVal[romanVal.length()-1];
    if (current == 'M')
        integerVal += 1000;
    else if (current == 'D')
        integerVal += 500;
    else if (current == 'C')
        integerVal += 100;
    else if (current == 'L')
        integerVal += 50;
    else if (current == 'X')
        integerVal += 10;
    else if (current == 'V')
        integerVal += 5;
    else if (current == 'I')
        integerVal += 1;
    
  for (unsigned int i = 0; i < romanVal.length()-1; i++) // Calculates (adds or subracts) Roman numeral values
        
    {
        current = romanVal[i];
        next = romanVal[i + 1];
        
        if (current == 'M')
            integerVal += 1000;
        
        else if (current == 'D')
            integerVal += 500;
        
        else if (current == 'C' && (next == 'D' || next == 'M'))
            integerVal -= 100;
        
        else if (current == 'C')
            integerVal += 100;
        
        else if (current == 'L')
            integerVal += 50;
        
        else if (current == 'X')
            integerVal += 10;
        
        else if (current == 'X' && (next == 'L' || next == 'C'|| next == 'M'))
            integerVal -= 10;
        
        else if (current == 'V')
            integerVal += 5;
        
        else if (current == 'I' && (next == 'L' || next == 'C' || next == 'M' || next == 'V'|| next == 'X'))
            integerVal -= 1;
        
        else if (current == 'I')
            integerVal += 1;
    }
}

void romanType::printNumber(char request) // Outputs final value requested by the user
{
    if (request == 'R')
        cout << "Roman numeral value: " << romanVal << endl;
    else if (request == 'P')
        cout << "Positive integer value: " << integerVal << endl;
}
