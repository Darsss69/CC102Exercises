//Darius James M. Serito    BSCS-1B

#include <iostream>
using namespace std;

int main()
{
    struct book
    {
        int barcode;
        string title;
        int year;
        int rating;
    };

    int numBooks;
    char choice;

    auto input = [&](book s[], int n)// INPUT FUNCTION (inside main using lambda)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"\nEnter Barcode: ";
            cin>>s[i].barcode;

            // Check if there is a duplicate
            for(int j = 0; j < i; j++)
            {
                while(s[i].barcode == s[j].barcode)
                {
                    cout<<"Taken, enter new barcode: ";
                    cin>>s[i].barcode;
                    j = -1;
                }
            }

            cin.ignore();
            cout<<"Enter Title: ";
            getline(cin, s[i].title);

            cout<<"Enter Year Published: ";
            cin>>s[i].year;

            cout<<"Enter Rating (0-5): ";
            cin>>s[i].rating;
            cin.ignore();
        }
    };

    // DISPLAY FUNCTION
    auto display = [&](book s[], int n)
    {
        cout<<"\nBarcode\t\tTitle\t\tYear\t\tRating\t\tCategory\n";

        for(int i = 0; i < n; i++)
        {
            cout<<s[i].barcode
                 <<"\t\t" <<s[i].title
                 <<"\t\t" <<s[i].year
                 <<"\t\t" <<s[i].rating <<"\t\t";

            if(s[i].rating == 5) cout<<"Excellent";
            else if(s[i].rating == 4) cout<<"Very Good";
            else if(s[i].rating == 3) cout<<"Good";
            else if(s[i].rating == 2) cout<<"Fair";
            else if(s[i].rating == 1) cout<<"Poor";
            else if(s[i].rating == 0) cout<<"No Rating";
            else cout<<"Invalid";

            cout<<endl;
        }
    };

    // MAIN LOOP
    do{
        cout<<"Enter how many books: ";
        cin>>numBooks;
        cin.ignore();

        book obj[numBooks];

        input(obj, numBooks);
        display(obj, numBooks);

        cout<<"Again?(Y/y): ";
        cin>>choice;

    } while(choice == 'Y' || choice == 'y');

    return 0;
}
