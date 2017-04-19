#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;
void html_out(string::iterator begin, string::iterator end){
	while (begin != end){
		if (*begin == '_'){
			cout << "<em>";
			begin++;
			while (*begin != '_'){
				cout << *begin;
				begin++;
			}
			cout << "</em>";
			begin++;
		}
		if (*begin == '['){
			string text;
			begin++;
			while (*begin != ']'){
				text += *begin;
				begin++;
			}
			begin++;
			cout << "<a href=\"";
			while (*begin != ')'){
				cout << *begin;
				begin++;
			}
			cout << "\">" << text << "</a>";
			begin++;
		}
		else{
			cout << *begin;
			begin++;
		}
	}
}



int main(){
	string line;
	int count_list = 0;
	int count_segment = 0;
	ifstream fin("text");
	if (!fin.is_open())cout << "error" << endl;
	while (getline(fin, line)){
		if (line[0] == '*'){
			if (count_list == 0){
				cout << "<ul>" << endl;
				count_list++;
			}
			string::iterator begin = line.begin();
			begin++;
			while (*begin == ' ')begin++;
			cout << "<li>";
			html_out(begin, line.end());
			cout << "<li>";
			cout << endl;
		}
		else if (line[0] == '#'){
			string::iterator begin = line.begin();
			int title = 0;
			while (*begin == '#'){

				title = (title + 1) % 6;
				begin++;
			}
			while (*begin == ' ')
				begin++;
			cout << "<h" << title << ">";
			html_out(begin, line.end());
			cout << "</h" << title << ">" << endl;
		}
		else if (line.empty()){
			if (count_list>0){

				cout << "</ul>";
				count_list--;
				cout<<endl;
			}
			else if (count_segment>0){
				cout << "</p>";
				count_segment--;
				cout<<endl;
			}
		}
		else{

			if (count_segment == 0){
				cout << "<p>";
				count_segment++;
			}else cout<<endl;
			
			html_out(line.begin(), line.end());
		}
	}
	if (count_list > 0)cout << "</ul>";
	if (count_segment > 0)cout << "</p>";
	return 0;
}


			
