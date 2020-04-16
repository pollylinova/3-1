//3-1 spisyk L s neobhodimi funkcii i menu
//spisyk s nachalen ukazatel pstart systawq spisyk samo s elementite, koito ne se powtarqt
//da se izwedat na ekrana po podhodqsh nachin
#include <iostream>
using namespace std;
struct list {
	int key;
	list* next;
}
*start = NULL; 

void add_å(int n) { 
	list *p = start, * q = p;
	q = new list;		  
	q->key = n;	 
	q->next = NULL;	 
	if (start)	  
	{
		while (p->next)	    
			p = p->next;
		p->next = q;
	}
	else
		start = q;
}

void print() 
{
	if (start)  {
		list* p = start;
		while (p){
			cout << p->key << " ";    
			p = p->next;
		}
	}
	else
		cout << "\n Empty list";
}

void help()
{
	list* p = start;
	list* q;
	list* r;
	list* t;
	if (start)
	{
		for(p = start; p->next != NULL; p = p->next)
		{
			q = p;
			while (q->next) 
			{
				if (q->next->key == p->key)
				{
					r = q->next;
					q->next=q->next->next;
					delete r;
					t = p;
					if (start == p) {
						start = start->next;
					}
					p = p->next;
					delete t;
				}
				q = q->next;
			}

		}
	}
}




int main()
{
	int ch, num, br, i;
	do
	{
		cout << "\n\t Menu";
		cout << "\n 1.Add elements";
		cout << "\n 2.Print full list L";
		cout << "\n 3.Print list P, no repeating numbers";
		cout << "\n 4.Exit";
		do
		{
			cout << "\n Your choice is: ";
			cin >> ch;
		} while (ch < 1 || ch>4);
		switch (ch) {
		case 1:
			cout << "\n How many elements do you want to add? ";
			cin >> br;
			cout << "\n Input L-stack elements: " << endl;
			for (i = 0; i < br; i++)
			{
				cout << " ";
				cin >> num;
				add_å(num);
			}
			break;

		case 2: 
			cout << "\n List is: " << endl;
			print(); break;
		case 3: 
			help();
			cout << "List P: " << endl;
			print();
			break;
		}

	} while (ch != 4);
}

/* 
kogato p iskame da ima dostyp do next se prawi sys strelka p->next 
rykowodstwo 64 stranica - obhojdane 
list* p = start; // now ukazatel wzimasht stoinostta na starta , taka se create-va ukazatel w spisyka wzimash dadena stoinost
while (p->key != n && p->next) {//dokato p razlichno ot n (ne e namereno chislo n), 
p = p->next; //otiwa w sledwashtiq element (cikyl)
if (p->key == n) { //ako stoinostta (key) e rawna na n
*/

//start=new list;
//start->key=n , starta wzima nowa stoinost
//start->next=p , w next otiwa staroto nachalo na spisyk (dobawqne na element w nachaloto), elementa sled starta = p;

