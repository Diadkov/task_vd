#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findme, val = 0;
string monthtype (string &month);
bool check (vector <string> str, string sname, string smonth);

int main(){
	string sname, smonth;
	int counter = 0, num = 0, isum = 0;
	int i;
	vector <string> str;
	vector <int> itotal;
	
	string FilePath = "C:\\Users\\vd\\Desktop\\csv.csv";
	ifstream my_file;
	my_file.open(FilePath);
	if (!my_file) {
		cout << "File isn't opened!" << endl;
		return -1;
	}
	else{
		cout << "File opened successfully!" << endl;
	}
	
	// File is on!
	
	
	cout << "Data output presented in file newcsv.csv." << endl;
	cout << "His path: C:\\Users\\vd\\Desktop\\newcsv.csv" << endl;
		
		while((i = my_file.get()) != EOF) {   //	checking is file fulfilled?
			if (i!='\n' && i!='\"'){			// if no " and new string than
	        	if(i!=';' && counter == 0)	sname += char(i);	// first enter. we divide variables by ;
				else if(i == ';' && counter == 0){				// sname - string name
					sname = sname + ';';
					counter++;
				}
				else if(counter == 6 && i != ';')	smonth = smonth + char(i);	// add new character every
				else if(counter == 6 && i == ';'){				// put ; in the end
					smonth = smonth + ';';
					counter++;
				}
				else if (i == ';' && counter > 0 && (counter != 0 || counter != 6 || counter != 7))	counter++;
				else if(counter == 7 && i !='\n'){
					smonth = monthtype(smonth);					// function to find type
					if(check(str, sname, smonth) == false){
						itotal[findme] += i - 48;
					}
					else{
						itotal.push_back(i - 48);
					}
						
				}
			}																			
	        else if(i =='\n'){
	        	if(check(str, sname, smonth) != false)
				str.push_back(sname + smonth);	// write it to the vector
				sname.clear(); 				// clear string
	            smonth.clear(); 			// clear string
	            counter = 0;			// for not making more mistakes
	        }
	    }
	    ofstream fout;
  		fout.open("C:\\Users\\vd\\Desktop\\newcsv.csv");
		for(int k = 0; k < str.size(); k++){
			fout << str[k] << itotal[k] << '\n';
		}
		
	return 0;
}

bool check (vector <string> str, string sname, string smonth){
	for(int k = 0; k < str.size(); k++){
   	 	if(str[k].find(sname + smonth) != std::string::npos){
   	 		findme = k;
   	 		return false;
   	 		break;
		}
	}
	return true;
}

string monthtype (string &month){
		if(month.find("-01-") != std::string::npos){
			month = "January;";
		}
		else if(month.find("-02-") != std::string::npos == true){
			month = "February;";
		}
		else if(month.find("-03-") != std::string::npos == true){
			month = "March;";
		}
		else if(month.find("-04-") != std::string::npos == true){
			month = "April;";
		}
		else if(month.find("-05-") != std::string::npos == true){
			month = "May;";
		}
		else if(month.find("-06-") != std::string::npos == true){
			month = "June;";
		}
		else if(month.find("-07-") != std::string::npos == true){
			month = "July;";
		}
		else if(month.find("-08-") != std::string::npos == true){
			month = "August;";
		}
		else if(month.find("-09-") != std::string::npos == true){
			month = "September;";
		}
		else if(month.find("-10-") != std::string::npos == true){
			month = "October;";
		}
		else if(month.find("-11-") != std::string::npos == true){
			month = "November;";
		}
		else if(month.find("-12-") != std::string::npos == true){
			month = "December;";
		}
		return month;
	}  
                       