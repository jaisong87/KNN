 /****************************************************
 *
 * KNNClassifier - K Nearest Neighbour Classifier ( could be Extrended ) 
 *
 * This is a sample program that uses KNNClassifier. Make changes here to try different inputs
 *
 * Initial Version : Jaison George ( jaisong87@gmail.com ) 
 *
 **********************************************************/

#include "KNNClassifier.h"
#include<sstream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

void print(vector<int> X)
{
for(int i = 0; i<X.size();i++)
	cout<<X[i]<<",";
cout<<endl;
}

int main()
{
ifstream training("optdigits_tra_trans(1).dat"); // Input File
int curY;
int attribCnt = 64; // 64 dimensions

KNNClassifier K1(3, attribCnt); // Consider 3 Neighbours in 64D space 

int cnt = 0;

//Do training here
string line;
while(getline(training, line)) // get next input as there is only 1 input per line
	{
	int tmp;
	vector<int> curX;
	stringstream ss1(line);
	for(int i=0;i< attribCnt;i++) // getting all 64 attribValues
		{
			ss1>>tmp;
			curX.push_back(tmp);
		}
	ss1>>curY; // Getting Y value
	K1.learnNextInput(curX,curY); // Feed this also to the classifier to learn
	}

//Test the inputs now
ifstream test("optdigits_trial_trans(1).dat"); // Test File
int inp = 0; 
while(getline(test, line)) //get next input for testing
        {
	inp++;
	cout<<"Input#"<<inp<<" ";
        int tmp;
        vector<int> curX;
        stringstream ss1(line);
        for(int i=0;i< attribCnt;i++) // Taking all 64 attribs 
                {
                        ss1>>tmp;
                        curX.push_back(tmp);
                }
	//print(curX); can print the input if required
        curY = K1.predict(curX); // predict Y now ( classifier will print the result on screen )
        }


return 0;
}
