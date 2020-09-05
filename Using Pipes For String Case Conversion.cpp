#include <bits/stdc++.h>
#include <unistd.h>
#define endl "\n"
#define f(a,n) for(int a;a<n;a++)

using namespace std;

char CaseConversion(char str[]){
	int l = strlen(str);
	f(a,l){
		if(isupper(str[a])){
			str[a] = tolower(str[a]);
		}
		else{
			str[a] = toupper(str[a]);
		}
	}
	return *str;
}

int main(){
	char str[100];
	cout<<"Enter the string :";
	cin.get(str, 100);
	cout<<endl;
	int fd[2];	
	write(fd[1],str,strlen(str));
	cout<<"String '"<<str<<"' is written in Pipe with Pid "<<getpid()<<endl;	
	str[100] = CaseConversion(str);
	close(fd[0]);
	read(fd[0],str,strlen(str));
	cout<<"String '"<<str<<"' is read in Pipe with Pid "<<getpid()<<endl;
	cout<<endl<<"Finall Ouput : "<<str<<endl;	
	return 0;
}

/*

Ouput : 

-----------------------------------------------------------------

Enter the string :Chetan

String 'Chetan' is written in Pipe with Pid 13812
String 'cHETAN' is read in Pipe with Pid 13812

Finall Ouput : cHETAN

-----------------------------------------------------------------

Enter the string :Hello World

String 'Hello World' is written in Pipe with Pid 19876
String 'hELLO wORLD' is read in Pipe with Pid 19876

Finall Ouput : hELLO wORLD

----------------------------------------------------------------

*/
