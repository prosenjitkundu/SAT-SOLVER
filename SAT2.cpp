#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <random>
#include "togasat.hpp"

using namespace std;
vector<vector<int>> vec;
int unsat = 0;
int color[4];
std::vector<int> clause;

void findSAT()
{
    togasat::Solver solver;
    for (int i = 0; i < vec.size(); i++)
    {
        solver.addClause(vec[i]);
    }
    togasat::lbool status = solver.solve();
    if (status == 1)
    {
        unsat = 1;
    }
    solver.sat_solver(color);
    //solver.printAnswer();
}
void codebreaker(int b, int w, int Choice[4])
{
    static int color[4];
    static int post[4];
    int i, j, k, l, n, m, p, q;
    std::vector<int> clause;

    if (b == 0 && w == 0)
    {
        //The loop condition where
        //no color matches with the code Maker
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int k = 0; k < 4; k++)
        {
            clause.clear();
            for (int j = 0; j < 4; j++)
            {
                clause.push_back(4 * color[k] + post[j]);
            }
            vec.push_back(clause);
        }
    }
    else if (b == 1 && w == 0)
    {
        //The loop condition where
        //one color matches with the code Maker
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int l = 0; l < 4; l++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (j != l)
                    {
                        clause.clear();
                        clause.push_back(-(color[l] * 4 + post[l]));
                        clause.push_back(-(color[j] * 4 + post[k]));
                        vec.push_back(clause);
                    }
                }
            }
        }
    }
    else if (b == 2 && w == 0)
    {
        //The loop condition where
        //two color matches with the code Maker
        for (i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (l = 0; l < 4; l++)
        {
            for (j = 0; j < 4; j++)
            {
                if (j == l)
                    break;
                for (k = 0; k < 4; k++)
                {
                    for (m = 0; m < 4; m++)
                        if ((k == l && m == l) || (k == j && m == j))
                            break;
                    {
                        clause.clear();
                        clause.push_back(-(color[l] * 4 + post[l]));
                        clause.push_back(-(color[j] * 4 + post[j]));
                        clause.push_back(-(color[k] * 4 + post[m]));
                        vec.push_back(clause);
                    }
                }
            }
        }
    }
    else if (b == 3 && w == 0)
    {
        //The loop condition where
        //three color matches with the code Maker
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int l = 0; l < 4; l++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j == l)
                    break;
                for (int k = 0; k < 4; k++)
                {
                    if (k == l || k == j)
                        break;
                    for (int m = 0; m < 4; m++)
                    {
                        for (int n = 0; n < 4; n++)
                        {
                            if ((m == l && n == l) || (m == j && n == j) || (m == j && n == j))
                                clause.clear();
                            clause.push_back(-(color[l] * 4 + post[l]));
                            clause.push_back(-(color[j] * 4 + post[j]));
                            clause.push_back(-(color[k] * 4 + post[k]));
                            clause.push_back(-(color[m] * 4 + post[n]));
                            vec.push_back(clause);
                        }
                    }
                }
            }
        }
    }
    else if (b == 0 && w == 1)
    {
        //The loop condition where one color matches with
        //the code Maker but at different position from its present position
        for (int i = 0; i < 4; i++)
        {
            int color = Choice[i] / 4;
            int post = Choice[i] % 4;
            for (int j = 0; j < 4; j++)
            {
                if (j == post)
                    break;
                for (int k = 0; k < 4; k++)
                {
                    int color1 = Choice[k] / 4;
                    if (k == i)
                        break;
                    for (int m = 0; m < 4; m++)
                    {
                        clause.clear();
                        clause.push_back(-(4 * color + j));
                        clause.push_back(-(4 * color1 + m));
                        vec.push_back(clause);
                    }
                }
            }
        }
    }
    else if (b == 0 && w == 2)
    {
        //The loop condition where two color matches with the code Maker
        //but at different position from its present position
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (j == k)
                    break;
                for (int l = 0; l < 4; l++)
                {
                    if (l == j)
                        break;
                    for (int m = 0; m < 4; m++)
                    {
                        if (m == k || m == l)
                            break;
                        for (int n = 0; n < 4; n++)
                        {
                            if (n == l || n == j)
                                break;
                            for (int p = 0; p < 4; p++)
                            {
                                clause.clear();
                                clause.push_back(-(color[j] * 4 + post[k]));
                                clause.push_back(-(color[l] * 4 + post[m]));
                                clause.push_back(-(color[n] * 4 + post[p]));
                                vec.push_back(clause);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (b == 0 && w == 3)
    {
        //The loop condition where three color matches with
        //the code Maker but at different position from its present position
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (j == k)
                    break;
                for (int l = 0; l < 4; l++)
                {
                    if (l == j)
                        break;
                    for (int m = 0; m < 4; m++)
                    {
                        if (l == m)
                            break;
                        for (int n = 0; n < 4; n++)
                        {
                            if (n == j || n == l)
                                break;
                            for (int p = 0; p < 4; p++)
                            {
                                if (n == p)
                                    break;
                                for (int q = 0; q < 4; q++)
                                {
                                    if (q == j || q == l || q == n)
                                        break;
                                    for (int r = 0; r < 4; r++)
                                    {
                                        clause.clear();
                                        clause.push_back(-(color[j] * 4 + post[k]));
                                        clause.push_back(-(color[l] * 4 + post[m]));
                                        clause.push_back(-(color[n] * 4 + post[p]));
                                        clause.push_back(-(color[q] * 4 + post[r]));
                                        vec.push_back(clause);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (b == 0 && w == 4)
    {
        //The loop condition where four color matches with
        //the code Maker but at different position from its present position
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (k == j)
                    break;
                for (int l = 0; l < 4; l++)
                {
                    if (l == k || l == j)
                        break;
                    for (int m = 0; m < 4; m++)
                    {
                        if (m == k || l == m || m == j)
                            break;
                        clause.clear();
                        clause.push_back(-(color[k] * 4 + post[j]));
                        clause.push_back(-(color[l] * 4 + post[j]));
                        clause.push_back(-(color[m] * 4 + post[j]));
                        vec.push_back(clause);
                    }
                }
            }
        }
    }
    else if (b == 1 && w == 1)
    {
        //The loop condition where two color matches where one color is at correct column
        //and the other one is at different position from its present position
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int l = 0; l < 4; l++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j == l)
                    break;
                for (int k = 0; k < 4; k++)
                {
                    if (j == k || k == l)
                        break;
                    for (int m = 0; m < 4; m++)
                    {
                        for (int n = 0; n < 4; n++)
                        {
                            if ((m == l && n == l) || (m == j && n == j))
                                break;
                            clause.clear();
                            clause.push_back(-(color[l] * 4 + post[l]));
                            clause.push_back(-(color[j] * 4 + post[k]));
                            clause.push_back(-(color[m] * 4 + post[n]));
                            vec.push_back(clause);
                        }
                    }
                }
            }
        }
    }
    else if (b == 1 && w == 2)
    {
        //The loop condition where two color matches where one color is at correct column
        //and the other two is at different position from its present position
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int l = 0; l < 4; l++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j == l)
                    break;
                for (int k = 0; k < 4; k++)
                {
                    if (j == k || k == l)
                        break;
                    for (int m = 0; m < 4; m++)
                    {
                        if (m == j || m == l)
                            break;
                        for (int n = 0; n < 4; n++)
                        {
                            if (n == k || n == l)
                                break;
                            for (int p = 0; p < 4; p++)
                            {
                                for (int q = 0; q < 4; q++)
                                {
                                    if (p == l && q == l)
                                        break;
                                    clause.clear();
                                    clause.push_back(-(color[l] * 4 + post[l]));
                                    clause.push_back(-(color[j] * 4 + post[k]));
                                    clause.push_back(-(color[m] * 4 + post[n]));
                                    clause.push_back(-(color[p] * 4 + post[q]));
                                    vec.push_back(clause);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (b == 1 && w == 3)
    {
        //The loop condition where two color matches where one color is at correct column
        //and the other three is at different position from its present position
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int l = 0; l < 4; l++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j == l)
                    break;
                for (int k = 0; k < 4; k++)
                {
                    if (j == k || k == l)
                        break;
                    for (int m = 0; m < 4; m++)
                    {
                        if (m == l && k == l)
                            break;
                        clause.clear();
                        clause.push_back(-(color[l] * 4 + post[l]));
                        clause.push_back(-(color[j] * 4 + post[k]));
                        clause.push_back(-(color[m] * 4 + post[k]));
                        vec.push_back(clause);
                    }
                }
            }
        }
    }
    else if (b == 2 && w == 1)
    {
        //The loop condition where three color matches where two color is at correct column
        //and the other one is at different position from its present position
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int l = 0; l < 4; l++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j == l)
                    break;
                for (int p = 0; p < 4; p++)
                {
                    if (p == l || p == j)
                        break;
                    for (int q = 0; q < 4; q++)
                    {
                        if (q == p || q == j || q == l)
                            break;
                        for (int k = 0; k < 4; k++)
                        {
                            for (int m = 0; m < 4; m++)
                            {
                                if ((k == l && m == l) || (k == j && m == j))
                                    break;
                                clause.clear();
                                clause.push_back(-(color[l] * 4 + post[l]));
                                clause.push_back(-(color[j] * 4 + post[j]));
                                clause.push_back(-(color[p] * 4 + post[q]));
                                clause.push_back(-(color[k] * 4 + post[m]));
                                vec.push_back(clause);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (b == 2 && w == 2)
    {
        //The loop condition where four color matches where two color is at correct column
        //and the other two is at different position from its present position
        for (int i = 0; i < 4; i++)
        {
            color[i] = Choice[i] / 4;
            post[i] = Choice[i] % 4;
        }
        for (int l = 0; l < 4; l++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j == l)
                    break;
                for (int m = 0; m < 4; m++)
                {
                    if (m == j || m == l)
                        break;
                    for (int n = 0; n < 4; n++)
                    {
                        if ((m == l && n == l) || (m == j && n == j))
                            clause.clear();
                        clause.push_back(-(color[l] * 4 + post[l]));
                        clause.push_back(-(color[j] * 4 + post[j]));
                        clause.push_back(-(color[m] * 4 + post[n]));
                        vec.push_back(clause);
                    }
                }
            }
        }
    }

    findSAT();
    cout << endl;
}
void codemaker()
{
    int a, tries = 0, right, close;
    int Colors[8] = {0 /*red*/, 1 /*blue*/, 2 /*yellow*/, 3 /*purple*/, 4 /*orange*/, 5 /*green*/, 6 /*white*/, 7 /*black*/};
    int Code[4];
    srand(time(0));
    a = rand() % 8; //Determine first colour
    Code[0] = Colors[a];
    while (Code[0] == Colors[a])
    {
        a = rand() % 8;
    }
    Code[1] = Colors[a]; //Determine Second colour

    while (Code[0] == Colors[a] || Code[1] == Colors[a])
    {
        a = rand() % 8;
    }
    Code[2] = Colors[a]; //Determine third colour
    while (Code[0] == Colors[a] || Code[1] == Colors[a] || Code[2] == Colors[a])
    {
        a = rand() % 8;
    }
    Code[3] = Colors[a]; //Determine fourth colour
    cout << "\n"
         << Code[0] << ", " << Code[1] << ", " << Code[2] << ", " << Code[3] << "\n";
    togasat::Solver solver;
    std::vector<int> clause;
    int i, j, k;
    int Choice[4];
    static int count = 0;
    for (i = 0; i < 4; i++)
    {
        Choice[i] = i;
    }
    int b = 1;
    int w = 0;
    while (1)
    {
        codebreaker(b, w, Choice); //sending the initial choice of color to code breaker
        b = 0;
        w = 0;
        for (int i = 0; i < 4; i++)
        {
            if (Code[i] / 4 == Choice[i])
                b++;
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i == j)
                    break;
                if (Code[i] / 4 == Choice[j])
                    w++;
            }
        }
        cout << "black : " << b << "white : " << w << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << (Choice[i]) << " ";
        }
        cout << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << (color[i] / 4) << " ";
        }
        cout << endl;
        if (b == 4)
        {
            return;
        }
    }
}
int main(int argc, char *argv[])
{
    codemaker();
    return 0;
}
