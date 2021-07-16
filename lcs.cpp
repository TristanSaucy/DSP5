#include "lcs.hpp"
LCS::LCS()
{	
	input.open("twoStrings.txt");
	std::string str1;
	std::string str2;
	getline(input,str1);
	getline(input,str2);
	input.close();
	int iLength = str1.length()+1;
	int jLength = str2.length()+1;
	int arr[iLength][jLength];
	for(int i=0;i<iLength;i++) // initialization of array
	{
		arr[i][0]=0;
	}
	for(int j=1;j<jLength;j++) //gotta shave that nanosecond off
	{
		arr[0][j]=0;
	}

	for(int i=1;i<iLength;i++)
	{
		for(int j=1;j<jLength;j++)
		{
			if(str1.at(i-1)==str2.at(j-1))//A comparison is made to see if chars match
			{
				arr[i][j]=arr[i-1][j-1]+1; // Add 1 to whatever is to its diagonal
			}
			else if(arr[i-1][j]>=arr[i][j-1]) // if up is >= to left
			{
				arr[i][j]=arr[i-1][j]; // copy up to current
			}
			else
			{
				arr[i][j]=arr[i][j-1];  // copy left to current
			}		
		}
	}

	std::stringstream ss;
	int i=iLength-1;

	int j=jLength-1;
	while(j!=0 && i!=0)
	{
		if(arr[i][j]==0)
		{
			break;
		}
		else if(arr[i][j-1]==arr[i-1][j]) // if left is the same as up, check the diagonal
		{
			if(arr[i-1][j-1]==arr[i][j]) // if the diagonal is same value as current, go up
			{
				i--;
			}
			else
			{
				ss<<str1.at(i-1); // load stringstream with character
				i--;
				j--;
			}
		}
		else if(arr[i-1][j] > arr[i][j-1]) // if up is greater than left, go up
		{
			i--;
		}
		else // last case is to just go left
		{
			j--;
		}
	}
	std::string reversed(ss.str());
	std::string lcsString(reversed.rbegin(),reversed.rend());
	std::cout<<"First String:"<<std::endl<<str1<<std::endl<<"Second String:"<<std::endl<<str2<<std::endl;
	std::cout<<"LCS:"<<std::endl<<lcsString<<std::endl;

	// PART 2
	std::cout<< "Upper Triangular Matrix from input of \"Multistring.txt\""<<std::endl;
	std::vector<std::string> stringArr;
	input.open("multiStrings.txt");
	int numLines;
	input>>numLines;
	std::string tempString;
	for(int i=0;i<numLines;i++)
	{
		input>>tempString;
		stringArr.push_back(tempString);
	}
	input.close();


	std::cout<<"  ";
	for(int m=1;m<=numLines;m++)
	{
		std::cout<<" "<<0<<m;
	}
	std::cout<<std::endl;

	// fancy double pointers wow
	int **arr2;
	int counter;
	int str1L;
	int str2L;
	float result;
	float tempNum;
	for(int m=1;m<=numLines;m++) // double loop for the construction of the upper triangular matrix
	{
		
		std::cout << 0 <<m<<" ";

		for(int n=1;n<=numLines; n++) //m is row, n is col
		{
			if(m>=n)
			{
				std::cout << " - ";
			}
			else // this is where comparisons are made
			{
				
				i=stringArr.at(m-1).length()+1;
				j=stringArr.at(n-1).length()+1;
				arr2=new int*[i];
				for(int k=0;k<i;k++) //dynamic memory allocation
				{
					arr2[k]=new int[j];
				}
				// I think I should just be able to copy and paste the code from above

				for(int q=0;q<i;q++) // initialization of array
				{
					arr2[q][0]=0;
				}
				for(int q=1;q<j;q++) //gotta shave that nanosecond off
				{
					arr2[0][q]=0;
				}

				for(int q=1;q<i;q++)
				{
					for(int w=1;w<j;w++)
					{
						if(stringArr.at(m-1).at(q-1)==stringArr.at(n-1).at(w-1))//A comparison is made to see if chars match
						{
							arr2[q][w]=arr2[q-1][w-1]+1; // Add 1 to whatever is to its diagonal
						}
						else if(arr2[q-1][w]>=arr2[q][w-1]) // if up is >= to left
						{
							arr2[q][w]=arr2[q-1][w]; // copy up to current
						}
						else
						{
							arr2[q][w]=arr2[q][w-1];  // copy left to current
						}		
					}
				}	

				int t=i-1;
				counter=0;
				int y=j-1;
				while(t!=0 && y!=0)
				{
					if(arr2[t][y]==0)
					{
						break;
					}
					else if(arr2[t][y-1]==arr2[t-1][y]) // if left is the same as up, check the diagonal
					{
						if(arr2[t-1][y-1]==arr2[t][y]) // if the diagonal is same value as current, go up
						{
							t--;
						}
						else
						{
							counter++;
							t--;
							y--;
						}
					}
					else if(arr2[t-1][y] > arr2[t][y-1]) // if up is greater than left, go up
					{
						t--;
					}
					else // last case is to just go left
					{
						y--;
					}
				}
				




				str1L=stringArr.at(m-1).length();
				str2L=stringArr.at(n-1).length();
				while(1)
				{
					if(str1L>=str2L)
					{
		
						result=1-str2L*1.0/str1L;
					if(result<=0.1)
					{
						tempNum=counter*1.0/str2L;
						if(tempNum>=0.9)
						{
							std::cout << " H ";
							break;
						}
					}
					if(result<=0.2)
					{
						tempNum=counter*1.0/str2L;
						if(tempNum>=0.8)
						{
							std::cout<<" M ";
							break;
						}
					}
					if(result<=0.4)
					{
						tempNum=counter*1.0/str2L;
						if(tempNum>=0.5)
						{
							std::cout<<" L ";
							break;
						}
					}
					std::cout<<" D ";
					break;
				}
				else
				{
					result=1-str1L*1.0/str2L;
					if(result<=0.1)
					{
						tempNum=counter*1.0/str1L;
						if(tempNum>=0.9)
						{
							std::cout << " H ";
							break;
						}
					}
					if(result<=0.2)
					{
						tempNum=counter*1.0/str1L;
						if(tempNum>=0.8)
						{
							std::cout<<" M ";
							break;
						}
					}
					if(result<=0.4)
					{
						tempNum=counter*1.0/str1L;
						if(tempNum>=0.5)
						{
							std::cout<<" L ";
							break;
						}
					}
					std::cout<<" D ";
					break;
				}

				}

				for(int k=0; k<i; k++) // followed by dynamic deallocation
				{
					delete [] arr2[k];
				}
				delete [] arr2;
			}
		}
		std::cout<<std::endl;
	}




}
