#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<cmath>
using namespace std;
//defining the size and length of array by the data through excel files
#define size 500
#define length_data 4001
//we could add class or structure in here.
class File {
	//taking 3 public perameters as given in the excel file
	//also making each variable of type string so that it's easy to get access when reading file
public:
	string id;
	string speed;
	string distance;
};
//here we will separately pick every entry each column and then repeat it for the rows through the help of loops
void separating_string(string str, string* str1, string* str2, string* str3) {
	string vstr = "";
	bool flag1 = true, flag2 = true, flag3 = true;
	for (int i = 0; i < str.length(); i++) {
		//this condition will separate string from one column to the other
		if (str[i] == ',') {
			//for 1st column
			if (flag1 == true) {
				*str1 = vstr;
				vstr = "";
				flag1 = false;
				continue;
			}
			//for 2nd column
			if (flag2 == true) {
				*str2 = vstr;
				vstr = "";
				flag2 = false;
				continue;
			}
		}
		//for 3rd column
		vstr += str[i];
	}
	//this will work when we have to jump to the next line
	*str3 = vstr;
}
//here we will calculate the distance between the two clusters
double distanceCalculate(int* x1, int y1) {
	double dist = 0;
	for (int i = 0; i < 4001; i++) {
		//calculating Euclidean distance
		dist += pow(x1[i] - y1, 2);
	}
	dist = sqrt(dist);
	return dist;
}
//picking the shortest distances from the 5 assumed clusters to calculate the distances
int shortestDistancetoCluster(int d1, int d2, int d3, int d4, int d5) {
	//abs command gets the absolute value of the given data
	d1 = abs((int)d1);
	d2 = abs((int)d2);
	d3 = abs((int)d3);
	d4 = abs((int)d4);
	d5 = abs((int)d5);
	//simple conditions for the shortest value
	if (d1 < d2 && d1 < d3 && d1 < d4 && d1 < d5) {
		return 1;
	}
	else if (d2 < d1 && d2 < d3 && d2 < d4 && d2 < d5) {
		return 2;
	}
	else if (d3 < d1 && d3 < d2 && d3 < d4 && d3 < d5) {
		return 3;
	}
	else if (d4 < d1 && d4 < d2 && d4 < d3 && d4 < d5) {
		return 4;
	}
	else {
		return 5;
	}
}
//picking the number of clusters and sepataring through the shoertest and longest distances
void clustering(int** graphArray, File* data_in_ram) {
	//assumed 5 clusters value to separate them 
	//used random numbers to generate these 5 numbers
	srand(time(NULL));
	int var1 = rand() % 100;
	int var2 = rand() % 100;
	int var3 = rand() % 100;
	int var4 = rand() % 100;
	int var5 = rand() % 100;
	//variables needed for the proper working
	int new_var1 = 0;
	int new_var2 = 0;
	int new_var3 = 0;
	int new_var4 = 0;
	int new_var5 = 0;
	int count1 = 1, count2 = 1, count3 = 1, count4 = 1, count5 = 1;
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	//do-while loop needed to sum up all the same clusters in one place
	do {
		new_var1 = var1;
		new_var2 = var2;
		new_var3 = var3;
		new_var4 = var4;
		new_var5 = var5;
		//accessing 2D array with the help of nested for loops
		for (int i = 0; i < 500; i++) {
			for (int j = 0; j < 500; j++) {
				int a = var1 - graphArray[i][j];
				int b = var2 - graphArray[i][j];
				int c = var3 - graphArray[i][j];
				int d = var4 - graphArray[i][j];
				int e = var5 - graphArray[i][j];
				if (a < 0) {
					a *= -1;
				}
				if (b < 0) {
					b *= -1;
				}
				if (c < 0) {
					c *= -1;
				}
				if (d < 0) {
					d *= -1;
				}
				if (e < 0) {
					e *= -1;
				}
				if (a < b && a < c && a < d && a < e) {
					count1++;
					sum1 += graphArray[i][j];
				}
				else if (b < a && b < c && b < d && b < e) {
					count2++;
					sum2 += graphArray[i][j];
				}
				else if (c < a && c < b && c < d && c < e) {
					count3++;
					sum3 += graphArray[i][j];
				}
				else if (d < a && d < b && c > d && d < e) {
					count4++;
					sum4 += graphArray[i][j];
				}
				else {
					count5++;
					sum5 += graphArray[i][j];
				}
			}
		}
		//declaring each variable again so that we can not repeat count any cluster 
		var1 = sum1 / count1;
		var2 = sum2 / count2;
		var3 = sum3 / count3;
		var4 = sum4 / count4;
		var5 = sum5 / count5;
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
		sum4 = 0;
		sum5 = 0;
		count1 = 1;
		count2 = 1;
		count3 = 1;
		count4 = 1;
		count5 = 1;
	} while (new_var1 != var1 && new_var2 != var2 && new_var3 != var3 && new_var4 != var4 && new_var5 != var5);
	//*-*-*-*-*-*-*-*-*-*-*-*-*-RAN TOOOOOOOOOO LONG IT WAS SAD ;(
	//then?? nothing dikhawa
	//int clusters;
	//*cout << "Enter the number of clusters: ";
	//cin >> clusters;*/
	//int c1 = 1, c2 = 1, c3 = 1, c4 = 1, c5 = 1, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	//srand(time(0));
	//int cluster1 = rand() % 100;
	//int cluster2 = rand() % 100;
	//int	cluster3 = rand() % 100;
	//int cluster4 = rand() % 100; 
	//int cluster5 = rand() % 100;
	//while (cluster1 != t1 && cluster2 != t2 && cluster3 != t3 && cluster4 != t4 && cluster5 != t5)
	//{
	//	cluster1 = t1, cluster2 = t2, cluster3 = t3, cluster4 = t4, cluster5 = t5;
	//	for (int i = 0; i < 4001; i++) 
	//	{
	//		for (int j = 0; j < 4001; j++) 
	//		{
	//			//Hamza and nimra are both in team decore for Nascon 23 :)
	//			switch (shortestDistancetoCluster(graphArray[i][j] - cluster1, (graphArray[i][j] - cluster2), (graphArray[i][j] - cluster3), (graphArray[i][j] - cluster4), (graphArray[i][j] - cluster5)))
	//			{
	//			case 1:
	//				c1++;
	//				s1 += graphArray[i][j];
	//				break;
	//			case 2:
	//				c2++;
	//				s2 += graphArray[i][j];
	//				break;
	//			case 3:
	//				c3++;
	//				s3 += graphArray[i][j];
	//				break;
	//			case 4:
	//				c4++;
	//				s4 += graphArray[i][j];
	//				break;
	//			case 5:
	//				c5++;
	//				s5 += graphArray[i][j];
	//				break;
	//			}
	//		}
	//	}
	//	cluster1 = s1 / c1;
	//	cluster2 = s2 / c2;
	//	cluster3 = s3 / c3;
	//	cluster4 = s4 / c4;
	//	cluster5 = s5 / c5;
	//	//bismmilah parho
	//	
	//	s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, c1 = 1, c2 = 1, c3 = 1, c4 = 1, c5 = 1;
	//	cout << "here" << endl;
	//}
	int counter = 0;
	fstream file, outputfile;
	file.open("driver-data.csv");
	outputfile.open("Clustered.csv", ios::out | ios::app);
	string text;
	bool flag = true;
	//the clustered data :
	outputfile << "ID,Mean Distance,Mean speed,Appointed Cluster\n";
	for (int i = 0; i < length_data - 1; i++) {
		//stoi command is used so that we can convert the string data again into integer so that we can write it in file in integer form
		int xcorrdinate = stoi(data_in_ram[i].distance);
		int ycorrdinate = stoi(data_in_ram[i].speed);
		//output of the clustered data:
		outputfile << data_in_ram[i].id << "," << data_in_ram[i].distance << "," << data_in_ram[i].speed << "," << shortestDistancetoCluster(graphArray[xcorrdinate][ycorrdinate] - new_var1, graphArray[xcorrdinate][ycorrdinate] - new_var2, graphArray[xcorrdinate][ycorrdinate] - new_var3, graphArray[xcorrdinate][ycorrdinate] - new_var4, graphArray[xcorrdinate][ycorrdinate] - new_var5) << "\n";
	}
}

int main() {
	//making a dynamic array for the data in file
	File* darray = new File[length_data];
	ifstream myfile;
	myfile.open("driver-data.csv");
	int position = 0;
	string str;
	string str1, str2, str3;
	bool flag = true;
	while (1) {
		getline(myfile, str);
		if (flag == true) {
			flag = false;
			continue;
		}
		//break condition for the infinite loop at the end of file
		if (str == "" || str == "\n") {
			break;
		}
		separating_string(str, &str1, &str2, &str3);
		darray[position].id = (str1);
		darray[position].distance = (str2);
		darray[position].speed = (str3);
		position++;
		str = str1 = str2 = str3 = "";
	}
	//another array for the clustered data
	int** graphArray = new int* [length_data];
	for (int i = 0; i < length_data; i++) {
		graphArray[i] = new int[length_data];
	}
	//initializing the declared array to zero
	for (int i = 0; i < length_data; i++) {
		for (int j = 0; j < length_data; j++) {
			graphArray[i][j] = 0;
		}
	}
	for (int i = 0; i < position; i++) {
		//stoi command is used so that we can convert the string data again into integer so that we can write it in file in integer form
		graphArray[int(stoi(darray[i].distance))][int(stoi(darray[i].speed))] = stoi(darray[i].distance);
	}
	clustering(graphArray, darray);
	return 0;
}
