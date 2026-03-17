#include<iostream>
using namespace std;

void processGrades(int **grades, int students, int subjects);

int main()
{
    int students, subjects;

    cout<<"Enter number of students: ";
    cin>>students;
    cout<<"Enter number of subjects: ";
    cin>>subjects;
    cout<<endl;

    int **grades = new int*[students];//creating an array for grades also creating a pointers for row of students
    for(int i = 0; i<students; i++)
    {
        grades[i] = new int[subjects];//this indicates that in each row there will be columns
    }

    for(int i = 0; i<students; i++)//asking input from the user
    {
        cout<<"Enter grades for student "<<i+1<<"\n";
        for(int j = 0; j<subjects; j++)
        {
            cout<<"Subject "<<j+1<<": ";
            cin>>grades[i][j];
        }
        cout<<endl;
    }

    processGrades(grades, students, subjects);

    for(int i=0; i<students; i++)
    {
        delete[] grades[i];//delete each row of pointers
    }
    delete[] grades; //delete the array of pointers;

    return 0;
}

void processGrades(int **grades, int students, int subjects)
{
    cout<<"\nGrade Matrix\n";
    for(int i=0; i<students; i++)
    {
        for(int j=0; j<subjects; j++)
        {
            cout<<grades[i][j]<<"\t";
        }
        cout<<endl;
    }

    for(int i=0 ;i<students; i++)
    {
        double sum = 0;
        for(int j=0; j<subjects; j++)
        {
            sum+=grades[i][j];
        }
        double average = sum/subjects;
        cout<<"Average for Student "<<i+1<<": "<<average<<"\n";
    }

    int highest = grades[0][0]
    for(int i=0 ;i<students; i++)
    {
        for(int j=0; j<subjects; j++)
        {
            if(grades[i][j]>highest)
            {
                highest = grades[i][j];
            }
        }
    }
    cout<<"The highest grade is: "<<highest;



}
