//Darius James M. Serito   BSCS-1B

#include <iostream>
#include <fstream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int number)
{
    if(number <= 1)
    {
        return false;
    }

    for(int i = 2; i * i <= number; i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Function to count prime numbers in NUMS.txt
int primeGetter()
{
    fstream file;
    int primeCounter = 0;

    file.open("NUMS.txt", ios::in);

    if(file.is_open())
    {
        int num;

        while(file >> num)
        {
            if(isPrime(num))
            {
                primeCounter++;
            }
        }

        file.close();
    }
    else
    {
        cout << "Failed to open NUMS.txt\n";
    }

    return primeCounter;
}

int main()
{
    fstream file;

    // Write numbers to NUMS.txt (required by activity)
    file.open("NUMS.txt", ios::out);

    if(file.is_open())
    {
        file << "7\n";
        file << "12\n";
        file << "19\n";
        file << "25\n";
        file << "31\n";
        file << "44\n";
        file << "58\n";
        file << "63\n";
        file << "72\n";
        file << "89\n";

        file.close();
    }
    else
    {
        cout << "Failed to create NUMS.txt\n";
    }

    int z = primeGetter();

    cout << "Amount of prime numbers in the file: " << z << endl;

    return 0;
}
