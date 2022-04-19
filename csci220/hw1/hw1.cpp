#include <iostream>
#include <stdexcept>
#include <ctime>

using namespace std;

// R-1.11
class Flower
{
    private:
        string name;
        int pedal;
        float price;
    public:
        Flower(string name, int pedal, float price)
        : name(name), pedal(pedal), price(price) {}
        void setName(string str)
        {   name = str; }
        void setPedal(int n)
        {   pedal = n;  }
        void setPrice(float n)
        {   price = n;  }
        string getName()
        {   return name;    }
        int getPedal()
        {   return pedal;   }
        float getPrice()
        {   return price;   }
};

// R-1.18
bool isMultiple(long n, long m)
{
    double i;
    i = (double)n / m;  
    if (i - (long)i)
        return false;
    else
        return true;
}

// R-1.20 
int func(int n)
{
    return n * (n - 1) / 2;
}
// C-1.5 – just outline a possible solution without actual pseudocode or code
// C-1.6 – just outline a possible solution without actual pseudocode or code

// C-2.4
class Parallel
{
    private:
        string err;
    public:
        Parallel(const string& err)
        : err(err) {}
        string what()
        {
            return err;
        }
};

class Line
{
    private:
        double a;
        double b;
    public:
        Line(int a, int b)
        : a(a), b(b) {}
        double intersect(Line l)
        {        
            double result;
            
            try
            {
                if (a == l.a)
                {
                    throw Parallel("The two lines are parallel.");
                }
                else
                {
                    result = (l.b - b) / (a - l.a);
                }
            }
            catch(Parallel& err)
            {
                std::cerr << err.what() << '\n';
                exit(-1);
            }

            return result;
        }
};

// R-3.11
int max(int A[], int n)
{
    if (n <= 0 || A[n] > max(A, n - 1))
    {
        return A[n];
    }
    else
    {
        return max(A, n - 1);
    }   
}

// C-3.5
const int n{1000};
bool p[n][n]{false};

int meet(int i, int j)
{
    bool isWinner[2]{true};
    
    p[i][j] = true;
    p[j][i] = true;

    for (int k = 0; k < n; ++k) 
    {
        if (p[i][k] == false)
        {
            isWinner[0] = false;
        }

        if (p[j][k] == false)
        {
            isWinner[1] = false;
        }

        if (isWinner[0] == false && isWinner[1] == false)
        {
            return -1;
        }
    }

    if (isWinner[0] && isWinner[1])
    {
        return -2;
    }
    else if (isWinner[0])
    {
        return i;
    }
    else if (isWinner[1])
    {
        return j;
    }
    
    return -1;
}

// C-3.10
struct Node
{
    string str;
    Node *next;
    Node *prev;
};

Node *head;

void swapSLL(string x, string y)
{
    Node *cur = head;
    Node *xprev, *xcur, *xnext;
    Node *yprev, *ycur, *ynext;
    while (cur)
    {
        if (cur->next->str == x)
        {
            xprev = cur;
            xcur = cur->next;
            xnext = cur->next->next;
        }
        if (cur->next->str == y)
        {
            yprev = cur;
            ycur = cur->next;
            ynext = cur->next->next;
        }
         
        cur = cur->next;
    }
    
    xprev->next = ycur;
    xcur->next = ynext;
    yprev->next = xcur;
    ycur->next = xnext;
}

void swapDLL(string x, string y)
{
    Node *cur = head;
    Node *xprev, *xcur, *xnext;
    Node *yprev, *ycur, *ynext;
    while (cur)
    {
        if (cur->next->str == x)
        {
            xprev = cur;
            xcur = cur->next;
            xnext = cur->next->next;
        }
        if (cur->next->str == y)
        {
            yprev = cur;
            ycur = cur->next;
            ynext = cur->next->next;
        }
         
        cur = cur->next;
    }

    xprev->next = ycur;
    xnext->prev = ycur;
    yprev->next = xcur;
    ynext->prev = xcur;
    xcur->prev = yprev;
    xcur->next = ynext;
    ycur->prev = xprev;
    ycur->next = xnext;
}

// C-4.6
void sort(int A[], int n, int k)
{
    int B[10000];
    int begin{0};
    int end{n - 1};
    int temp;
    for (int i = 0; i < n; ++i) 
    {
        if (A[i] <= k)
        {
            temp = A[begin];
            A[begin] = A[i];
            A[i] = temp;
            begin++;
        }
        else
        {
            temp = A[end];
            A[end] = A[i];
            A[i] = temp;
            end--;
        }
    }
}

int main()
{

}