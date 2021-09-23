#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
class Sample
{
private:      //access modifire
    int a, b; //data member
public:       //assess Modifire
    //Constructers
    Sample() {}                                                  //Default or non perameterized constructer
    Sample(int a, int b) { this->a = a, this->b = b; }           //parameterized constructer
    Sample(Sample &temp) { this->a = temp.a, this->b = temp.b; } //copy constructer
    //Property Functions
    //accessor
    int geta() { return a; }
    int getb() { return b; }
    // Mutator
    void seta(int a) { this->a = a; }
    void setb(int b) { this->b = b; }
};
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    Sample s1;
    s1.seta(12);
    s1.setb(15);
    cout << s1.geta() << " " << s1.getb() << endl;
    Sample *s2 = &s1;
    cout << s2->geta() << " " << s2->getb() << endl;
    Sample *s3 = new Sample; //Sample()
    s3->seta(30);
    s3->setb(40);
    cout << s3->geta() << " " << s3->getb() << endl;
    Sample s4(s1);
    cout << s4.geta() << " " << s4.getb() << endl;
    return 0;
}
