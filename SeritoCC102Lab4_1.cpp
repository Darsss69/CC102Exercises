#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    char again;

    do
    {
     int students, quizzes;

     cout<<"Enter number of students: ";
     cin>>students;
     cout<<"Enter number of quizzes: ";
     cin>>quizzes;

     vector<vector<int>>scores(students, vector<int>(quizzes));

     for(int i=0; i<students; i++)
     {
         cout<<"\nEnter scores for student " <<i+1 <<":\n";

         for(int j=0; j<quizzes; j++)
         {
             cout<<"Quiz " <<j+1 <<": ";
             cin>>scores[i][j];
         }

     }

     cout<<"\nStudent\t";


     for(int j=0; j<quizzes; j++)
     {
         cout<<"Q" <<j+1 <<"\t";
     }

     cout<<"Average\n";

     for(int i=0; i<students; i++)
     {
         int sum=0;

         cout<<i+1 <<"\t";


         for(int j=0; j<quizzes; j++)
         {
             cout<<scores[i][j]<<"\t";
             sum+=scores[i][j];
         }

     double average = (double)sum/quizzes;

     cout << fixed << setprecision(2) << average << endl;

     }

    cout<<"Do you want to run the program again?(Y/y): ";
    cin>>again;


    }while(again == 'Y' || again == 'y');

    cout<<"Program Terminated.";


    return 0;
}
