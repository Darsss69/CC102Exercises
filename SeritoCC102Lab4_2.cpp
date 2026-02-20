//Darius James M. Serito  BSCS-1B

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{

    double sales[5][4] = {0};

    int salesperson, product;
    double amount;
    char choice;

    cout<<"===== Monthly Sales Entry =====\n";

    do
    {
        cout<<"\nEnter Salesperson number (1-4): ";
        cin>>salesperson;

        cout<<"Enter Product number (1-5): ";
        cin>>product;

        cout<<"Enter Total Dollar Value: ";
        cin>>amount;

        sales[product - 1][salesperson - 1]+=amount;

        cout<<"\nAdd another sales slip?(y/n): ";
        cin>>choice;


    } while(choice=='y' || choice=='Y');

    cout<<"\n\n===== Monthly Sales Summary =====\n\n";

    cout<<setw(12) <<"Product";

    for(int s=0; s<4; s++)
    {
        cout<<setw(12) <<"SP " + to_string(s+1);
    }

    cout<<setw(15) <<"Total\n";

    for(int i=0; i<5; i++)
    {
        double productTotal = 0;

        for(int j=0; j<4; j++)
        {
           cout<<setw(12) <<"Product " + to_string(i+1);
           productTotal+=sales[i][j];
        }

         cout<<setw(15) <<productTotal <<endl;
    }

    cout<<"\nSalesperson Totals:\n";

    for(int j=0; j<4; j++)
    {
        double spTotal=0;

        for(int i=0; i<5; i++)
        {
            spTotal += sales[i][j];
        }

        cout<<"Salesperson " <<j+1 <<": "
            <<fixed <<setprecision(2) <<spTotal <<endl;


    }

     cout<<"\nProgram Ended.\n";


    return 0;
}

