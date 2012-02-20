 /****************************************************
 *
 * KNNClassifier - K Nearest Neighbour Classifier ( could be Extrended ) 
 *
 * KNNClassifier decleration
 *
 * Initial Version : Jaison George ( jaisong87@gmail.com ) 
 *
 **********************************************************/

#ifndef __KNNCLASSIFIER__H__
#define __KNNCLASSIFIER__H__

#include<vector>
#include<cmath>
#include<iostream>
#include<map>
using namespace std;

/* Only integer attributes are supported
 * Support s arbitrary K value
 * dimensionality is also custom
 */
class KNNClassifier{
vector<vector<int> > X; // Set of X values
vector<int> Y; // Set of Y values
int K; // Will consider K nearest neighbours
int attribCount; // This is the dimensionality

public:
KNNClassifier(int, int); // Constructor
bool learnNextInput(vector<int>, int); // learn next input
int predict(vector<int>); //predict
};

#endif
