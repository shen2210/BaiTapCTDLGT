#include<iostream>
#include<stack>
using namespace std;

int uuTien(char); 		// muc do uu tien cua toan tu
void hauTo();	  		// chuyen trung to sang hau to
void dinhGiaTri(string);// tinh gia tri bieu thuc hau to

int main(){
	hauTo();
	return 0;
}

void dinhGiaTri(string str) {
	stack <int> st;
	for (int i = 0; i < str.size() ; i++){
		if(str[i] >= '0' && str[i] <= '9') st.push(str[i] - '0');
		else{
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			
			if(str[i] == '+') st.push(b+a);
			else if(str[i] == '-') st.push(b-a);
			else if(str[i] == '*') st.push(b*a);
			else if(str[i] == '/') st.push(b/a);
			else if(str[i] == '%') st.push(b%a);
			else if(str[i] == '^') {
				int tmp = b;
				for (int i = 0; i < a-1; i++){
					tmp *= b;
				}
				st.push(tmp);
			}
			
		} 
	}
	cout<<st.top()<<endl;
}

int uuTien(char c){
	if ( c == '(' ) return 0;
	if ( c == '+' || c == '-' ) return 1;
	if ( c == '*' || c == '/'|| c == '%') return 2;
	if ( c == '^' ) return 3;
}

void hauTo(){
	stack <char> s;
	int i = 0;
	string str, str1= "",str2 = "";
	cout<<"Nhap bieu thuc : \n";
	getline(cin, str);
	cout<<"Chuyen bieu thuc tu dang trung to sang hau to : \n";
	
	while(i < str.length()){
		char c = str.at(i);		// vi tri thu i trong str
		if (c != ' '){
			if ( c - '0' >= 0 && c - '0' <= 9 || isalpha(c)) str1 += c;		// ( 1 + 2 ) - 1
			else {
				cout<< str1 <<" ";
				str2 += str1;
				str1 = "";
				if(c == '(') s.push(c);
				else if (c == ')'){
					while(s.top() != '('){
						str2 += s.top();		
						cout<<s.top();
						s.pop();
					}
					s.pop();
				}
				else{
					while( !s.empty() && uuTien(c) <= uuTien(s.top())){
						str2 += s.top();
						cout<<s.top();
						s.pop();
					}
					s.push(c);
				}
			}
		}
		i++;
	}
	
	if (str1 != "") {
		str2 += str1;
		cout<< str1 <<" ";
	}
	
	while (!s.empty()){
		str2 += s.top();
		cout<<s.top();
		s.pop();
	}
	
	if (isalpha(str2[0])){
		cout<<"\nChi tinh duoc bieu thuc so tu nhien \n";
	}
	else {
		cout<<"\nGia tri cua bieu thuc la : \n";
		//cout<<str2<<"\n";
		dinhGiaTri(str2);
	}
}
