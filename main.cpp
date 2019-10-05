#include <fstream>
#include <iostream>
using namespace std;

struct listNode{

	string chStr;
	int prob;
	listNode *next;

	listNode(string str, int count){
		chStr = str;
		prob = count;
		next = NULL;
	}
	listNode(string str, int count, listNode *nnode){
		chStr = str;
		prob = count;
		next = nnode;
	}
};

class linkedList{

	public:
		listNode *listHead;
		linkedList(listNode *lhead){
			listHead = lhead;
		}
		void insertNewNode(listNode *lhead, listNode *nnode){
			listNode *spot = findSpot(lhead, nnode);
			nnode->next = spot->next;
			spot->next = nnode;
		}
		listNode *findSpot(listNode *lhead, listNode *nnode){
			// findSpot(LHead, NewNode) Alg steps:
			listNode *spot = lhead;// step 1: spot <-- LHead
			while(spot->next != NULL && spot->next->prob<nnode->prob){// 2: if(spot.next != null && spot.next.count < NewNode.count)
				spot = spot->next;// spot <-- spot.next
			}// 3: repeat step 2 until the condition fails
			return spot;// 4: return spot
		}
		string printList(listNode *lhead){
			string list = "listHead-->";
			while(lhead->next != NULL){
				list += string("(\"")+ string(lhead->chStr) + string("\", ")+to_string(lhead->prob) + string(", \"") + string(lhead->next->chStr)+ string("\")-->");
				lhead = lhead->next;
			}
			list += string("(\"") + string(lhead->chStr)+ string("\", ") +to_string(lhead->prob) + string(", NULL)-->NULL\n");
			return list;
		}
};

int main(int argc, char const *argv[]) {
	if(argc<3){
		cout<<endl<<"Pass correct # of args"<<endl<<endl;
	}
	listNode *listHead = new listNode("dummy", 0);// Step 1: listHead <- get a newNode as the dummy listNode with (“dummy” ,0), listHead to point to.
	linkedList ll(listHead);
	// Step 2: inFile <- open input file using argv
	// 		   outFIle <- open output file using argv
	ifstream inFile;
	inFile.open(argv[1]);
	ofstream outFile;
	outFile.open(argv[2 ]);

	string chr;
	int prob;
	while(inFile >> chr >> prob){// Step 3: chr <- get from inFile// Prob <- get from inFile
		listNode *nnode = new listNode(chr,prob);// newNode <- get a new listNode
		ll.insertNewNode(listHead, nnode);// Step 4: insertNewNode (listHead, newNode)
		outFile<<ll.printList(listHead);// Step 5: printList (listHead)
	}// Step 6: repeat step 3 – step 5 until the end of inFile

	outFile.close();//Step 7: close inFile
	inFile.close();//	close outFile

	cout << "Done!"<<endl;

	return 0;
}