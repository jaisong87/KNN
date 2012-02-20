 /****************************************************
 *
 * KNNClassifier - K Nearest Neighbour Classifier ( could be Extrended ) 
 *
 * KNNClassifier Impl
 *
 * Initial Version : Jaison George ( jaisong87@gmail.com ) 
 *
 **********************************************************/
#include "KNNClassifier.h"

// gives Euclidian distance
// Could extend this and support all types of distances
float dist(vector<int> curInp, vector<int> sampleX)
{
float dis = 0;

//Summing all the square differences for Euclidian distances 
for(int i=0;i<curInp.size();i++)
	{
		dis += (curInp[i]-sampleX[i])*(curInp[i]-sampleX[i]);
	}

//Taking square root 
dis = sqrt(dis);
return dis;
}

//Constructor for getting value of K, dimensionality
KNNClassifier::KNNClassifier(int neighbours, int a)
{
K = neighbours;
attribCount = a;
}

// learn the next Input 
bool KNNClassifier::learnNextInput(vector<int> v, int label)
{
if(v.size() != attribCount)
	return false;
X.push_back(v);
Y.push_back(label);
//cout<<"Learned for label : "<<label<<endl;
return true;
}

// Predict the output
int KNNClassifier::predict(vector<int> V)
{
if(V.size() != attribCount)
	{
	cout<<"Can't make a prediction. Input is not consistent with the number of attributes...."<<endl;
	return -1;
	}
multimap<float, int>  disMap;

for(int i=0;i<X.size();i++)
	{
		float distance = dist(V, X[i]);	
		disMap.insert(pair<float,int>(distance, i)); // Map of distance to index of the item in training
	}

//Now return the Y values of lowest-K distances
cout<<"Best "<<K<<" Matches are ";
multimap<float,int>::iterator itr = disMap.begin();

map<int, int> votesForClass;
for(int i = 0; i<(K-1);i++)
	{
		votesForClass[Y[itr->second]]++;
		cout<<Y[itr->second]<<"("<<itr->first<<"),";
		itr++;
	}
cout<<Y[itr->second]<<"("<<itr->first<<")"<<endl;
votesForClass[Y[itr->second]]++;

int ans = 0; //Majority Vote

//Find the majority Vote now
cout<<" Frequency table for best "<<K<<" neighbours ";
for(map<int, int>::iterator itr = votesForClass.begin(); itr != votesForClass.end();itr++)
	{	
			if( itr->second > votesForClass[ans])
			ans = itr->first;
		cout<<"("<<itr->first<<","<<itr->second<<") ";
	}
	cout<<endl;

cout<<" Majority vote for the prediction is "<< ans <<endl;
return ans;	
}
