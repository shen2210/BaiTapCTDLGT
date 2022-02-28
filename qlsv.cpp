#include <bits/stdc++.h>
using namespace std;

struct Student{
	string fullName, id;
	double score;
};

struct SV{
	Student s;
	SV *pNext;
};

typedef struct SV* sv;

// nhap thong tin 1 sv
sv makeNode(){
	Student s;
	cout<<"Nhap thong tin sinh vien: \n";
	cout<<"Nhap ID: ";cin>>s.id;
	cout<<"Nhap ho ten:  ";cin.ignore();
	getline(cin,s.fullName);
	cout<<"Nhap diem mon CTDL & GT: ";cin>>s.score;
	sv tmp = new SV();
	tmp->s = s;
	tmp->pNext = NULL;
	return tmp;
}

// so luong sinh vien
int size(sv s){
	int c = 0;
	while (s != NULL){
		c++;
		s = s->pNext;
	}
	return c;
}

// them 1 sinh vien vao dau danh sach
void insertFirst(sv& a){
	sv tmp = makeNode();
	if (a == NULL){
		a = tmp;
	}
	else {
		tmp->pNext = a;
		a = tmp; 
	}
}

// them 1 sinh vien vao cuoi danh sach
void insertLast(sv& a){
	sv tmp = makeNode();
	if (a == NULL){
		a = tmp;
	}
	else {
		sv p = a;
		while (p->pNext != NULL){
			p = p->pNext;
		}
		p->pNext = tmp;
	}
}


// them 1 sinh vien vao giua danh sach
void insertMiddle(sv& a,int pos){
	if(pos <= 0 || pos > (size(a)+1)){
		cout<<"Vi tri khong hop le !"; return;
	}
	if(pos == 1) {
		insertFirst(a); return;
	}
	else if (pos == (size(a)+1)) {
		insertLast(a); return;
	}
	sv tmp = makeNode();
	sv p = a;
	for (int i=1;i<pos-1;i++) p = p->pNext; 	
	tmp->pNext = p->pNext;
	p->pNext = tmp;
}

// xoa 1 sinh vien dau
void deleteFirst(sv& a){
	if (a == NULL) return;
	a = a->pNext;
} 

// xoa 1 sinh vien cuoi
void deleteLast(sv& a){
	if (a == NULL) return;
	sv pfirst = NULL, plast = a;
	
	while (plast->pNext != NULL){
		pfirst = plast;
		plast = plast->pNext;
	}
	if (pfirst == NULL) a = NULL;	
	else {
		pfirst->pNext = NULL;
	}
}

// xoa 1 sinh vien o giua
void deleteMiddle(sv& a,int pos){
	if(pos <= 0 || pos > size(a)){
		cout<<"Vi tri khong hop le !"; return;
	}
	sv pfirst = NULL, plast = a;
	for (int i=1;i<pos;i++){
		pfirst = plast;
		plast = plast->pNext;
	}
	if (pfirst == NULL) a = NULL;
	else{
		pfirst->pNext = plast->pNext;
	}
} 

// in thong tin 1 sinh vien
void infoStudent(Student s){
	cout<<"\n-----------------------------------------------\n";
	cout<<"ID: "<<s.id<<endl;
	cout<<"Ho va ten: "<<s.fullName<<endl;
	cout<<"Diem mon CTDL & GT: "<<s.score<<endl;
}

// in danh sach sinh vien
void infoStudents(sv a){
	cout<<"\n-------------Danh sach sinh vien:--------------";
	while (a != NULL){
		infoStudent(a->s);
		a = a->pNext;
	}
	cout<<endl;
}

// sap xep sinh vien theo thu tu score
void sort(sv& a){
	for(sv p = a;p->pNext != NULL;p=p->pNext){
		sv min = p;
		for(sv q = p->pNext;q != NULL;q= q->pNext){
			if(q->s.score < min->s.score){
				min = q;
			}
		}
		Student tmp = min->s;
		min->s = p->s;
		p->s = tmp;
	}
}

// tim kiem 1 sinh vien
void search(sv& a,string id){
	sv tmp = a; 
	bool check = false;
	while (tmp != NULL){
		if (tmp->s.id == id){
			check = true;
			break;
		}
		tmp = tmp->pNext;
	}
	if (check == true){
		infoStudent(tmp->s);
	}
	else cout<<"ID khong ton tai trong danh sach ! \n";
}
 
 // chinh sua thong tin 1 sinh vien
void adjust(sv& a,string id){
 	sv p = a;
 	bool check = false;
 	while (p != NULL){
 		if (p->s.id == id){
 			check = true;
 			break;
		 }
 		p = p->pNext;
	 }
	if (check == true){
		int choice;
		do{
			cout<<"\n------------------------\n";
			cout<<"| 0. Finish               |\n";	
			cout<<"| 1. Chinh sua id         |\n";
			cout<<"| 2. Chinh sua ho ten     | \n";
			cout<<"| 3. Chinh sua diem       |\n";
			cout<<"\n------------------------\n";
			cout<<"Nhap chuc nang: ";cin>>choice;
			switch(choice){
				case 1:
					cin.ignore();
					cout<<"Nhap ID: ";cin>>p->s.id;
					p->s.fullName = p->s.fullName;
					p->s.score = p->s.score;
					
					break;
				case 2:
					cin.ignore();
					cout<<"Nhap ho ten:  ";
					getline(cin,p->s.fullName);
					p->s.id = p->s.id;
					p->s.score = p->s.score;
					break;
				case 3:
					cout<<"Nhap diem mon CTDL & GT: ";cin>>p->s.score;
					p->s.id = p->s.id;
					p->s.fullName = p->s.fullName;
					break;
			}
			sv tmp = p;
			tmp->pNext = p->pNext;
		}
		while (choice != 0);
	}
	else cout<<"ID khong ton tai trong danh sach ! \n";
 }
 
// menu
void menu(){
	cout<<"\n-------------------MENU------------------------\n";
	cout<<"1. Chen 1 sinh vien vao dau danh sach \n";
	cout<<"2. Chen 1 sinh vien vao cuoi danh sach \n";
	cout<<"3. Chen 1 sinh vien vao giua danh sach \n";
	cout<<"4. Xoa 1 sinh vien o dau danh sach \n";
	cout<<"5. Xoa 1 sinh vien o cuoi danh sach \n";
	cout<<"6. Xoa 1 sinh vien o giua danh sach \n";
	cout<<"7. Sap xep danh sach sinh vien tang dan theo diem \n";
	cout<<"8. In danh sach sinh vien \n";
	cout<<"9. Tim kiem 1 sinh vien \n";
	cout<<"10.Chinh sua thong tin 1 sinh vien \n";
	cout<<"0. Thoat chuong trinh \n";
	cout<<"-----------------------------------------------\n";
}

int main(){
	sv head = NULL;
	int choice, pos;
	string id;
	while(1){
		menu();
		cout<<"Nhap lua chon: ";cin>>choice;
		switch (choice){
			case 0:
				return 0;
			case 1:
				insertFirst(head);
				break;
			case 2:
				insertLast(head);
				break;
			case 3:
				cout<<"Nhap vi tri can chen: "; cin>>pos;
				insertMiddle(head,pos);
				break;
			case 4:
				deleteFirst(head);
				break;
			case 5:
				deleteLast(head);
				break;
			case 6:
				cout<<"Nhap vi tri can xoa: "; cin>>pos;
				deleteMiddle(head,pos);
				break;
			case 7:
				sort(head);
				infoStudents(head);
				break;
			case 8:
				infoStudents(head);
				break;
			case 9:
				cin.ignore();
				cout<<"Nhap id sinh vien can tim: ";cin>>id;
				search(head,id);
				break; 
			case 10:
				cout<<"Nhap id sinh vien can chinh sua: ";cin>>id;
				adjust(head,id);
				break;
		}
		system("pause");
	}
		
	return 0;
}
