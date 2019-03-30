#include<iostream>
using namespace std;

struct player{
    int data;
    player *next;
};

void createPlayer(player * &p){
    int num;
    
    cout << "Enter an int: " << endl;
    cin >> num;
    
    player *pl = new player;
    pl->data = num;

    pl->next = p;
    p=pl;
}

void printList(player * p){
    
    int i = 0;
    
    while(p!=NULL){
    	cout << "Adress: " << p << endl;
    	
    	cout << "Player " << i++ << ": " << p->data << endl;
        p=p->next;
        
    }
    
}

void deleteMax(player * p){
	int max = 0;
	cout << p->next->data;
	/*while(p){
		if(p->data > max){
			max = p->data;
		}
		p=p->next;
	}*/
}

int main(){
    int n;
    player *head = NULL;
    
    while(true){
        cout << "Create player: 1\nPrint list: 2\nQuit: 3\n";
        cin >> n;
        switch(n){
            case(1): 
            		createPlayer(head);
					break;
            case(2): 
            		printList(head);
            		cout << "Head adress: " << head << endl;
                    break;
            case(3):
            		return 0;
            case(4): 
            		deleteMax(head);
            		break;
            default: 
            		cout << "Enter valid char.\n";
                    break;
        }
    }
}