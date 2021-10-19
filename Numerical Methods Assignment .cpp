/*
Assignment on: Polynomial,Bisection,False,Newton,Secant
Md. Soyaeb Islam
Id:1705001

*/

#include<bits/stdc++.h>

/* Defining equation to be solved.
   Change this equation to solve another problem. */

#define    f(x)    x*x - x - 2
#define   g(x)   2*x -1 //Derivative of the function


using namespace std;

void Polynomial();
void Bisection();
void False();
void Newton();
void Secant();

int main()
{

    int n;
    cout<<"      Select the following Methods:      "<<endl<<endl;
    cout<<endl<<"         1. Polynomial Method"<<endl;
    cout<<endl<<"         2. Bisection Method"<<endl;
    cout<<endl<<"         3. False Position Method"<<endl;
    cout<<endl<<"         4. Newton Rapson Method"<<endl;
    cout<<endl<<"         5. Secant Method"<<endl<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
        Polynomial();
        break;
    case 2:
        Bisection();
        break;
    case 3:
        False();
        break;
    case 4:
        Newton();
        break;
    case 5:
        Secant();
        break;
    }

    return 0;
}

void Polynomial()
{
    float a[100],sum=0,x;
    int n,i;
    /* Setting precision and writing floating point values in fixed-point notation. */
    cout<< setprecision(6)<< fixed;

    /* Inputs */
up:

    cout<<"Enter degree of the polynomial X  "<<endl;
    cin>>n;
    cout<<"Enter coefficient's of the polynomial X  "<<endl;
    for(i=n; i>=0; i--)
    {
        cout<<"Enter Coefficient of [ X^"<<i<<" ]  "<<endl;
        cin>>a[i];
    }

    cout<<"Enter the value of X  "<<endl;
    cin>>x;

    for(i=n; i>0; i--)
    {
        sum=(sum+a[i])*x;
    }

    sum=sum+a[0];

    cout<<"Value of the polynomial is = "<< sum<<endl;
}

void Bisection()
{
    float x0, x1, x, f0, f1, f, e;
    int step = 1;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout<< setprecision(6)<< fixed;

    /* Inputs */
up:
    cout<<"Enter first guess: ";
    cin>>x0;
    cout<<"Enter second guess: ";
    cin>>x1;
    cout<<"Enter tolerable error: ";
    cin>>e;

    /* Calculating Functional Value */
    f0 = f(x0);
    f1 = f(x1);

    /* Checking whether given guesses brackets the root or not. */
    if( f0 * f1 > 0.0)
    {
        cout<<"Incorrect Initial Guesses."<< endl;
        goto up;
    }
    /* Implementing Bisection Method */
    cout<< endl<<"****************"<< endl;
    cout<<"Bisection Method"<< endl;
    cout<<"****************"<< endl;
    do
    {
        /* Bisecting Interval */
        x = (x0 + x1)/2;
        f = f(x);

        cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x<<" and f(x) = "<< setw(10)<< f(x)<< endl;

        if( f0 * f < 0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
        }
        step = step + 1;
    }
    while(fabs(f)>e);

    cout<<endl<< "Root is: "<<  x<<endl;
}

void False()
{
    /* Declaring required variables */
    float x0, x1, x, f0, f1, f, e;
    int step = 1;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout<< setprecision(6)<< fixed;

    /* Inputs */
up:
    cout<<"Enter first guess: ";
    cin>>x0;
    cout<<"Enter second guess: ";
    cin>>x1;
    cout<<"Enter tolerable error: ";
    cin>>e;

    /* Calculating Functional Value */
    f0 = f(x0);
    f1 = f(x1);

    /* Checking whether given guesses brackets the root or not. */
    if( f0 * f1 > 0.0)
    {
        cout<<"Incorrect Initial Guesses."<< endl;
        goto up;
    }
    /* Implementing False Position Method */
    cout<< endl<<"*********************"<< endl;
    cout<<"False Position Method"<< endl;
    cout<<"*********************"<< endl;
    do
    {
        /* Applying False Position Method */
        /* x is next approximated root using False Position method */
        x = x0 - (x0-x1) * f0/ (f0-f1);
        f = f(x);

        cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x<<" and f(x) = "<< setw(10)<< f(x)<< endl;

        if( f0 * f < 0)
        {
            x1 = x;
            f1 = f;
        }
        else
        {
            x0 = x;
            f0 = f;
        }
        step = step + 1;
    }
    while(fabs(f)>e);

    cout<< endl<<"Root is: "<< x<< endl;

}

void Newton()
{
    float x0, x1, f0, f1, g0, e;
    int step = 1, N;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout<< setprecision(6)<< fixed;

    /* Inputs */
    cout<<"Enter initial guess: ";
    cin>>x0;
    cout<<"Enter tolerable error: ";
    cin>>e;
    cout<<"Enter maximum iteration: ";
    cin>>N;

    /* Implementing Newton Raphson Method */
    cout<< endl<<"*********************"<< endl;
    cout<<"Newton Raphson Method"<< endl;
    cout<<"*********************"<< endl;
    do
    {
        g0 = g(x0);
        f0 = f(x0);
        if(g0 == 0.0)
        {
            cout<<"Mathematical Error.";
            exit(0);
        }


        x1 = x0 - f0/g0;


        cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x1<<" and f(x) = "<< setw(10)<< f(x1)<< endl;
        x0 = x1;

        step = step+1;

        if(step > N)
        {
            //cout<<"Not Convergent.";
            exit(0);
        }

        f1 = f(x1);

    }
    while(fabs(f1)>e);

    cout<< endl<<"Root is: "<< x1;

}
void Secant()
{
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1, N;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout<< setprecision(6)<< fixed;

    /* Inputs */
    cout<<"Enter first guess: ";
    cin>>x0;
    cout<<"Enter second guess: ";
    cin>>x1;
    cout<<"Enter tolerable error: ";
    cin>>e;
    cout<<"Enter maximum iteration: ";
    cin>>N;

    /* Implementing Secant Method */
    cout<< endl<<"**************"<< endl;
    cout<<"Secant Method"<< endl;
    cout<<"**************"<< endl;
    do
    {
        f0 = f(x0);
        f1 = f(x1);
        if(f0 == f1)
        {
            cout<<"Mathematical Error.";
            exit(0);
        }

        x2 = x1 - (x1 - x0) * f1/(f1-f0);
        f2 = f(x2);

        cout<<"Iteration-"<< step<<":\t x2 = "<< setw(10)<< x2<<" and f(x2) = "<< setw(10)<< f(x2)<< endl;

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        step = step + 1;

        if(step > N)
        {
            //cout<<"Not Convergent.";
            exit(0);
        }
    }
    while(fabs(f2)>e);

    cout<< endl<<"Root is: "<< x2;
}
