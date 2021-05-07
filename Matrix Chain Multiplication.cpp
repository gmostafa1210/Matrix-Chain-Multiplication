#include<bits/stdc++.h>
using namespace std;

int bb[30][30];
ofstream out;
string cheak;

void Parenthesis(int i, int j)
{
    if(i == j)
    {
        cout<< "A" << i << " ";
        cheak += "A";
        stringstream ss;
        ss << i;
        string str = ss.str();
        cheak += str;
        cheak += " ";
    }
    else
    {
        cout << "(";
        cheak += "(";
        Parenthesis(i, bb[i][j]);
        Parenthesis(bb[i][j]+1, j);
        cout << ")";
        cheak += ")";
    }
}

void MAT_MUL(int a[], int n)
{
    out.open("output.txt");
    int mm[n][n], i, j, k, p, q, r;
    fill(&mm[0][0], &mm[n][n], 0);
    fill(&bb[0][0], &bb[n][n], 0);
    for(i = 2; i < n; i++)
    {
        for(j = 1; j < n-i+1; j++)
        {
            r = i+j-1;
            mm[j][r] = INFINITY;
            for(k = j; k < r; k++)
            {
                p = mm[j][k] + mm[k+1][r] + (a[j-1] * a[k] * a[r]);
                if(p < mm[j][r])
                {
                    mm[j][r] = p;
                    bb[j][r] = k;
                }
            }
        }
    }
    for(i = 1; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            cout << mm[i][j] << " ";
            out << mm[i][j] << " ";
        }
        cout << endl;
        out << endl;
    }

    cout << endl << "Minimum no of multiplication need: " << mm[1][n-1] << endl;
    out << endl << "Minimum no of multiplication need: " << mm[1][n-1] << endl;

    Parenthesis(1, n-1);
}

int main()
{
    int n, i, j, s;
    ifstream myfile;
    myfile.open("MCMinput.txt");
    myfile >> n;
    int a[n+1];
    for(i = 0; i <= n; i++)
    {
        myfile >> a[i];
    }
    MAT_MUL(a, n+1);
    out << endl << cheak << endl;
    return 0;
}
