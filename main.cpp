#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//create a structure node to hold a node of linked list
struct Node{
  int info;  //hold value or info of a node
  Node *next; // holds address of next node/ points to next node consisting of info and next
  // make sure to use (*) for declaration else, incomplete type error
};

//insertion at start
void insertStart(int value, Node *&start){
//pass value to be inserted and linked list of type node is passes by reference
  Node *p; //declaration of node p/insertion node

  //incase the linked list is completely empty
  if(start==NULL){
    p = new Node; //create new node
    p->info = value; //assign value
    p->next = NULL; //since it serves as the only node in list
    start = p; //most imp -> place start before p... so it points at p
  }
  //incase of already existing elements
  else{
    p = new Node;
    p->info = value;
    p->next = start; //p points at next node which is start
    start = p; // now start is moved backward to point at p
  }

}

// insertion at end of linked list use traversal
void insertEnd(int value, Node *&start){
     Node *p, *q; //declare 2 pointers 1 for insertion node, other for traversal
  //in case the linked list is completely empty
  if(start==NULL){
    p = new Node; //create new node
    p->info = value; //assign value
    p->next = NULL; //since it serves as the only node in list
    start = p; //most imp -> place start before p... so it points at p
  }
  //in case of already existing elements
  else{
     q=start; //initialize q to begin from start of list
     while(q->next!=NULL){
        //the loop iterates till last node is reached
        q = q-> next; //move q 1 step ahead
     }
     // loop termination condition fulfilled and reached at end of loop
     p = new Node; // new insertion node created
     p->info = value;
     p->next=NULL; // since it's the last node
     q->next = p; // q holds address of p i.e: establishes a link
  }

}

// Insertion after a specific value
void InsertSpecific(int positionVal, int value, Node *&start){

    Node *p, *q;

    q = start;

    // Traverse the list
    while(q != NULL){

        // Find the position node
        if(q->info == positionVal){

            // Create new node
            p = new Node;
            p->info = value;

            // Connect new node with the next node
            p->next = q->next;

            // Connect position node with new node
            q->next = p;

            return;
        }

        // Move q to next node
        q = q->next;
    }

    cout << "The value you entered was not found in the linked list!" << endl;
}


// for display pass linked list by reference
void display(Node *&start){
     Node *p, *q; //declare 2 pointers
     q = start; //initialize start with q
     while(q!=NULL){
        cout << q->info << " "; //print values of list
        q=q->next; //move q 1 step ahead
     }

     cout << endl;
}

//deletion at start
 void deleteStart(Node *&start){

    if(start==NULL){
        cout << "No node to delete!" << endl;
    }
    else if(start->next == NULL){
        delete start;
    }
    else {
        Node *q; //create pointer q
        q = start; //start from 1st node
        start = start->next; // move start to 2nd node
        q->next= NULL; // break link of 1st node with next node
        delete q; // finally delete the 1st node

    }

}

//deletion at end
void deleteEnd(Node *&start){
     if(start==NULL){
        cout << "No node to delete!" << endl;
    }
    else if(start->next == NULL){
        delete start;
    }
    else{
        Node *p, *q; // 2 pointers one for prev node, other for next
        p = start;
        q = start->next;
        while(q!=NULL){
            p = p->next;
            q = q ->next; // move both pointers one node ahead
            if(q->next==NULL){
                p->next = NULL; // break link of 2nd last node with last node
                delete q; // now delete last node
                return; //terminate loop and end function
            }
        }
    }

}

//deletion at specific position
  void deleteSpecific(int value, Node*&start){

         // Empty list
    if(start == NULL){
           cout << "List is empty!" << endl;
           return;
    }

     // Delete first node
    else if(start->info == value){
        Node* temp = start;
        start = start->next;
        delete temp;
        return;
    }
    else{
        Node *p, *q;
        p = start;
        q = start->next;
        bool notFound = true;
        while (q!=NULL){

            if(q->info == value){
                p->next = q->next;
                notFound = false;
                delete q;
                return;
            }
             p=p->next;
             q = q->next;
        }
        if(notFound){
            cout << value << " isn't found in the list!" << endl;
        }

    }

  }

  void reverseDisplay(Node *&start){
       if(start==NULL){ // At null the function returns
        return;
       }
       else{
        reverseDisplay(start->next); //the function calls the next node until null
        cout << start->info << " "; // lastly the stack prints in reverse order as each call returns fulfilling the condition of null
       }
  }

  void reverseList(Node *&start){
       Node *prev = NULL;
       Node *curr = start;
       Node *next = NULL;



       while(curr!=NULL){
            next = curr->next; //pointing/linking current with next node
            curr->next = prev; // reversing the current link
            prev = curr; // moving prev to current
            curr = next; // move curr to the saved next node

       }

       start = prev; // new starting point or head
  }


void dupControl(Node *&start, int target = -1) {
    Node *p = start;
    Node *q;
    Node *r;

    while (p != NULL) {
        r = p;
        q = p->next;

        while (q != NULL) {
            // If target is provided, delete all its occurrences.
            // Otherwise, remove duplicate values.
            if ((target != -1 && q->info == target) ||
                (target == -1 && p->info == q->info)) {

                r->next = q->next;
                delete q;
                q = r->next;
            }
            else {
                r = q;
                q = q->next;
            }
        }

        p = p->next;
    }

    // For Question 9, also remove matching nodes at the head.
    if (target != -1) {
        while (start != NULL && start->info == target) {
            Node *temp = start;
            start = start->next;
            delete temp;
        }
    }
}

   void midFinder(Node *&start){
        //first step is to find total num of nodes
        Node *p , *counter;
        counter = start;
        p = start;
        int nodeCount = 0;
        int limit;
        while(counter!=NULL){
          counter = counter->next;
          nodeCount++;
        }
        limit = (nodeCount + 1) / 2; //this is a simpler approach for both even and odd mids
        if(nodeCount%2==0){

             //limit = nodeCount/2;
            for(int i=1; i<limit; i++){
               p = p->next;
            }
        cout << "The middle person is: " << p->info << endl;
        }
        else{
             //limit = ceil(nodeCount/2.0); --> logically correct, but over complicated
             for(int i=1; i<limit; i++){
               p = p->next;
            }
        cout << "The middle person is: " << p->info << endl;
        }


   }

   bool hasLoop(Node *start)  //Q#4
{
    Node *slow = start; // traverse with gap of 1 node at a time
    Node *fast = start; // traverse with gap of 2 nodes at a time

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) //incase of a loop both pointers will meet at same point
            return true;
    }

    return false;
}

 void splitEvenOdd(Node *&start){
      Node *p = start; //traversal
      Node *evenList = NULL;  //list for even pricing
      Node *oddList = NULL;   //list for odd pricing

      // must initialize lists with null, otherwise it won't function desirably due to garbage value

      while(p!=NULL){
            if(p->info%2==0){
                //even node condition
                insertEnd(p->info, evenList);
            }
            else{
                //odd node condition
                insertEnd(p->info, oddList);
            }
        p = p->next;
      }
      cout << "EVEN FRUIT PRICING: " << endl;
      display(evenList);
      cout << "ODD FRUIT PRICING: " << endl;
      display(oddList);

 }

  void halfReversal(Node *&start){
       int counter = 0;
       Node *p = start;
       Node *firstHalf = NULL;
       Node *secondHalf = NULL;
       for(Node *temp=start; temp!=NULL; temp=temp->next){
        counter++;
       }

       int half = (counter+1)/2;

       for(int i=0; i<half; i++){
           insertEnd(p->info, firstHalf);
         p = p->next;
       }

       while(p!=NULL){
            insertEnd(p->info, secondHalf);
        p = p->next;
       }

       reverseList(firstHalf);
       reverseList(secondHalf);


       Node *r = secondHalf;


       while (r!=NULL){
            insertEnd(r->info, firstHalf);
        r = r->next;
       }

       cout << "Half reversal list: " << endl;
       display(firstHalf);

  }


   void rearrangeNodes(Node *&start) {
    // Handle empty list or a list with only one node
    if (start == NULL || start->next == NULL) {
        return;
    }

    Node *p = start;
    Node *q = start->next;

    // Update head to the second node
    start = q;

    while (true) {
        // Save the first node of the next pair
        Node *nextPair = q->next;

        // Swap the current pair
        q->next = p;

        // Handle the remaining zero or one node
        if (nextPair == NULL || nextPair->next == NULL) {
            p->next = nextPair;
            break;
        }

        // Connect the current pair to the next swapped pair
        p->next = nextPair->next;

        // Move to the next pair
        p = nextPair;
        q = nextPair->next;
    }
}

void SinglyInsertion(Node *&node){
     int number;
    int position;
    char choice;
    do{
             cout << "\nDo you want to insert value at start(s), end(e), specified position(k) or terminate(t) program?" <<endl;
             cin>>choice;
             if(choice=='S' || choice=='s'){
                cout << "\nEnter number to be inserted: ";
                cin>>number;
                insertStart(number, node);
                display(node);
             }
             else if(choice=='E' || choice=='e'){
                cout << "\nEnter number to be inserted: ";
                cin>>number;
                insertEnd(number, node);
                display(node);
             }
             else if(choice=='K' || choice=='k'){
                cout << "\nEnter position and number to be inserted respectively: ";
                cin>>position>>number;
                InsertSpecific(position, number, node);
                display(node);
             }
             else
                break;

    }while(choice!=NULL);

}


Node* copyList(Node *start) {
    Node *copyNode = NULL;
    Node *p = start;

    while (p != NULL) {
        insertEnd(p->info, copyNode);
        p = p->next;
    }

    return copyNode;
}

void deleteList(Node *&start) {
    while (start != NULL) {
        Node *temp = start;
        start = start->next;
        delete temp;
    }
}


// ================= DOUBLY LINKED LIST ==================================

//doubly link list struct, includes address of previous and next node, along with info/value of node
struct dNode{
 int info;
 dNode *prev;
 dNode *next;

};

void d_insertStart(int value, dNode *&start){
      dNode *p;
      if(start==NULL){ //check if list is empty!
        p = new dNode; //create node
        p->info = value; //assign value
        p->prev = NULL;
        p->next = NULL;
        //since it's the only node in list both prev and next point to null
        start = p; //the head pointer now points at p, so list is maintained
      }
      else{
        p = new dNode; //create node
        p->info = value; //assign value
        p->next = start; // next of p points at start so head pointer of list isn't lost
        p->prev = NULL; //since p is the first node of list
       (p->next)->prev = p; //the prev of node next to p, links with p
        start = p; //finally the head pointer start points at p which is now the 1st node

      }

 }

 void d_display(dNode *&start){
      dNode *p = start;
      while(p!=NULL){
        cout << p->info << "<->";
        p=p->next;
      }
      cout << endl;
 }

 //insertion at end
 void d_insertEnd(int value, dNode *&start){
     dNode *p;
      if(start==NULL){ //check if list is empty!
        p = new dNode; //create node
        p->info = value; //assign value
        p->prev = NULL;
        p->next = NULL;
        //since it's the only node in list both prev and next point to null
        start = p; //the head pointer now points at p, so list is maintained
      }
      else{
        p = start; //p will act as traversal pointer
        while(p->next!=NULL){
            p = p->next;
        }
        //after loop termination insert a  new node at end of list
        dNode *q = new dNode;
        q->info = value;
        q->next = NULL;
        q->prev = p; //double link
        p->next = q; //double link
      }

 }

 // insert at specific position
   void d_insertSpecificPos(int pos, int value, dNode*&start){
        dNode *p; //insertion node
        p = new dNode;
        p->info = value;
        dNode *q = start; //traversal node
        for(int i=1; i<pos-1; i++){ //IMPORTANT: this vondition inserts node exactly at desired position
            q = q->next; //traverse till desirable position
        }
        //Now insert p at that position
       // Insert p after q
       p->next = q->next;
       p->prev = q;

    if(q->next != NULL)
    {
        q->next->prev = p; //very imp so that program doesn't crash when last node is null
    }

    q->next = p;
}

 //deletion at start
  void d_deleteStart(dNode *&start){

  // ---- empty list ------//
  if(start==NULL){
    cout << "No node to delete!" << endl;
  }
  // --- if only one node available --- //
  else if(start->next == NULL){
    delete start; //simply delete list as head is the only node
    start = NULL;
  }
  // --- start of list --- //
  else{
    dNode *q = start; // create a node and initialize with start
    start = start->next; //move head node 1 step ahead
    (q->next)->prev = NULL; // or simply start->prev = null, disconnect q
    delete q;
  }

  }

  //deletion at end
  void d_deleteEnd(dNode *&start){
       // ---- empty list ------//
  if(start==NULL){
    cout << "No node to delete!" << endl;
  }
  // --- if only one node available --- //
  else if(start->next == NULL){
    delete start; //simply delete list as head is the only node
    start = NULL;
  }

  else{
    dNode *q = start; //traversal node pointer
    while(q->next!=NULL){
        q = q->next; //traversal
    }

    //after termination of loop
    (q->prev)->next = NULL;
    delete q;

  }

  }

  //deletion at specified position
 void d_deleteSpecificPos(int pos, dNode *&start)
{
    if(start == NULL)
        return;

    dNode *q = start;

    for(int i = 1; i < pos; i++)
    {
        if(q == NULL)
            return;

        q = q->next;
    }

    if(q == NULL)
        return;

    // Deleting first node
    if(q->prev == NULL)
    {
        d_deleteStart(start);
        return;
    }

    // Deleting middle or last node
    q->prev->next = q->next;

    if(q->next != NULL)
        q->next->prev = q->prev;

    delete q;
}



void doublyInsertion(dNode *&dnode) {
    int number;
    int position;
    char choice;

    do {
        cout << "\nDo you want to insert value at "
             << "start(s), end(e), specified position(k) "
             << "or terminate(t) program?" << endl;
        cin >> choice;

        if (choice == 'S' || choice == 's') {
            cout << "\nEnter number to be inserted: ";
            cin >> number;

            d_insertStart(number, dnode);
            d_display(dnode);
        }
        else if (choice == 'E' || choice == 'e') {
            cout << "\nEnter number to be inserted: ";
            cin >> number;

            d_insertEnd(number, dnode);
            d_display(dnode);
        }
        else if (choice == 'K' || choice == 'k') {
            cout << "\nEnter position and number respectively: ";
            cin >> position >> number;

            if (position == 1) {
                d_insertStart(number, dnode);
            }
            else if (position > 1) {
                dNode *p = dnode;
                int count = 1;

                while (p != NULL && count < position - 1) {
                    p = p->next;
                    count++;
                }

                if (p == NULL) {
                    cout << "Invalid position!" << endl;
                }
                else {
                    d_insertSpecificPos(position, number, dnode);
                }
            }
            else {
                cout << "Invalid position!" << endl;
            }

            d_display(dnode);
        }
        else if (choice == 'T' || choice == 't') {
            break;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 'T' && choice != 't');
}

//QUESTION#1
void d_swapNodes(dNode *&start, dNode *p, dNode *q) {
    if (p == NULL || q == NULL || p == q)
        return;

    // Case 1: p and q are adjacent, with p before q
    if (p->next == q) {
        dNode *beforeP = p->prev;
        dNode *afterQ = q->next;

        if (beforeP != NULL)
            beforeP->next = q;
        else
            start = q;

        if (afterQ != NULL)
            afterQ->prev = p;

        q->prev = beforeP;
        q->next = p;
        p->prev = q;
        p->next = afterQ;
        return;
    }

    // Case 2: p and q are adjacent, with q before p
    if (q->next == p) {
        d_swapNodes(start, q, p);
        return;
    }

    // Case 3: p and q are not adjacent
    dNode *beforeP = p->prev;
    dNode *afterP = p->next;
    dNode *beforeQ = q->prev;
    dNode *afterQ = q->next;

    if (beforeP != NULL)
        beforeP->next = q;
    else
        start = q;

    if (afterP != NULL)
        afterP->prev = q;

    if (beforeQ != NULL)
        beforeQ->next = p;
    else
        start = p;

    if (afterQ != NULL)
        afterQ->prev = p;

    p->prev = beforeQ;
    p->next = afterQ;
    q->prev = beforeP;
    q->next = afterP;
}


void deskReverse(dNode *&start) {
    int counter = 0;

    // Step 1: Count nodes
    for (dNode *p = start; p != NULL; p = p->next) {
        counter++;
    }

    // Step 2: Empty or single-node list
    if (counter < 2) {
        return;
    }

    int total = counter;

    // Step 3: Find the last node
    dNode *first = start;
    dNode *last = start;

    while (last->next != NULL) {
        last = last->next;
    }

    // Step 4: Swap corresponding outer nodes
    for (int i = 0; i < total / 2; i++) {

        // Save pointers BEFORE swapping
        dNode *nextFirst = first->next;
        dNode *prevLast = last->prev;

        d_swapNodes(start, first, last);

        // Move inward
        first = nextFirst;
        last = prevLast;
    }
}


void playlist(dNode *&start) {
    if (start == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    dNode *p = start;
    char c;

    cout << "Your playList: " << endl;
    d_display(start);

    cout << "Song " << p->info << " is playing..." << endl;

    do {
        cout << "Move forward (f), backward (b), or exit (t)?"
             << endl;
        cin >> c;

        if (c == 'f' || c == 'F') {
            if (p->next != NULL) {
                p = p->next;
            } else {
                cout << "End of PlayList!" << endl;
                continue;
            }
        }
        else if (c == 'b' || c == 'B') {
            if (p->prev != NULL) {
                p = p->prev;
            } else {
                cout << "Beginning of PlayList!" << endl;
                continue;
            }
        }
        else if (c == 't' || c == 'T') {
            cout << "Playlist exited successfully!" << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
            continue;
        }

        cout << "Song " << p->info << " is playing..." << endl;

    } while (true);
}

 // ===================== QUESTION #3 ===============================
 // defining nodes for all sections



struct Item {
    string name;
    Item *prev, *next;
};

struct Section {
    string name;
    Section *prev, *next;
    Item *items;
};                                                        // THIS IS A HEIRARCHIAL STRUCTURE, EACH NEW NODE CONTAINS A LIST OF PREV NODE
                                                          // IN ADDITION TO ITS ALL POINTERS
struct Store {
    string name;
    Store *prev, *next;
    Section *sections;
};

struct Location {
    string city;
    Location *prev, *next;
    Store *stores;
};

// helper functions for finding & appending each section's lists


Location* findLocation(Location *head, string city) {
    while (head != NULL) {
        if (head->city == city)
            return head;
        head = head->next;
    }
    return NULL;
}

Store* findStore(Location *loc, string name) {
    if (loc == NULL) return NULL;

    Store *p = loc->stores;
    while (p != NULL) {
        if (p->name == name) return p;
        p = p->next;
    }
    return NULL;
}

Section* findSection(Store *st, string name) {
    if (st == NULL) return NULL;

    Section *p = st->sections;
    while (p != NULL) {
        if (p->name == name) return p;
        p = p->next;
    }
    return NULL;
}

void addLocation(Location *&head, string city) {
    Location *p = new Location{city, NULL, NULL, NULL};

    if (head == NULL) {
        head = p;
        return;
    }

    Location *q = head;
    while (q->next != NULL)
        q = q->next;

    q->next = p;
    p->prev = q;
}

void addStore(Location *loc, string name) {
    Store *p = new Store{name, NULL, NULL, NULL};

    if (loc->stores == NULL) {
        loc->stores = p;
        return;
    }

    Store *q = loc->stores;
    while (q->next != NULL)
        q = q->next;

    q->next = p;
    p->prev = q;
}

void addSection(Store *st, string name) {
    Section *p = new Section{name, NULL, NULL, NULL};

    if (st->sections == NULL) {
        st->sections = p;
        return;
    }

    Section *q = st->sections;
    while (q->next != NULL)
        q = q->next;

    q->next = p;
    p->prev = q;
}

void addItem(Section *sec, string name) {
    Item *p = new Item{name, NULL, NULL};

    if (sec->items == NULL) {
        sec->items = p;
        return;
    }

    Item *q = sec->items;
    while (q->next != NULL)
        q = q->next;

    q->next = p;
    p->prev = q;
}



 // functions for removing items from particular list

void removeItem(Section *sec, string name) {
    if (sec == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    Item *p = sec->items;

    while (p != NULL && p->name != name)
        p = p->next;

    if (p == NULL) {
        cout << "Item not found!" << endl;
        return;
    }

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        sec->items = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

    delete p;
    cout << "Item removed successfully!" << endl;
}

void displaySection(Section *sec) {
    if (sec == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    Item *p = sec->items;

    cout << "Items in " << sec->name << ": ";

    if (p == NULL)
        cout << "No items";

    while (p != NULL) {
        cout << p->name;
        if (p->next != NULL)
            cout << " <-> ";
        p = p->next;
    }

    cout << endl;
}

void displayStore(Store *st) {
    if (st == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    Section *s = st->sections;

    cout << "\nStore: " << st->name << endl;

    if (s == NULL) {
        cout << "No sections available!" << endl;
        return;
    }

    while (s != NULL) {
        displaySection(s);
        s = s->next;
    }
}


  //main function of question#3


void manageInventory(Location *&locations) {
    int choice;
    string city, storeName, sectionName, itemName;

    do {
        cout << "\n===== INVENTORY MANAGEMENT =====" << endl;
        cout << "1. Add Location/City" << endl;
        cout << "2. Add Store" << endl;
        cout << "3. Add Section" << endl;
        cout << "4. Store an Item" << endl;
        cout << "5. Remove an Item" << endl;
        cout << "6. Display Section Items" << endl;
        cout << "7. Display Store Items" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter city name: ";
            cin >> ws;
            getline(cin, city);

            if (findLocation(locations, city) != NULL) {
                cout << "Location already exists!" << endl;
                break;
            }

            addLocation(locations, city);
            cout << "Location added!" << endl;
            break;

        case 2: {
            cout << "Enter city: ";
            cin >> ws;
            getline(cin, city);

            Location *loc = findLocation(locations, city);

            if (loc == NULL) {
                cout << "Location not found!" << endl;
                break;
            }

            cout << "Enter store name: ";
            getline(cin, storeName);

            if (findStore(loc, storeName) != NULL) {
                cout << "Store already exists!" << endl;
                break;
            }

            addStore(loc, storeName);
            cout << "Store added!" << endl;
            break;
        }

        case 3: {
            cout << "Enter city: ";
            cin >> ws;
            getline(cin, city);

            Location *loc = findLocation(locations, city);

            cout << "Enter store name: ";
            getline(cin, storeName);

            Store *st = findStore(loc, storeName);

            if (st == NULL) {
                cout << "Store not found!" << endl;
                break;
            }

            cout << "Enter section name: ";
            getline(cin, sectionName);

            if (findSection(st, sectionName) != NULL) {
                cout << "Section already exists!" << endl;
                break;
            }

            addSection(st, sectionName);
            cout << "Section added!" << endl;
            break;
        }

        case 4:
        case 5:
        case 6: {
            cout << "Enter city: ";
            cin >> ws;
            getline(cin, city);

            Location *loc = findLocation(locations, city);

            cout << "Enter store name: ";
            getline(cin, storeName);

            Store *st = findStore(loc, storeName);

            if (st == NULL) {
                cout << "Store not found!" << endl;
                break;
            }

            cout << "Enter section name: ";
            getline(cin, sectionName);

            Section *sec = findSection(st, sectionName);

            if (sec == NULL) {
                cout << "Section not found!" << endl;
                break;
            }

            if (choice == 4) {
                cout << "Enter item name: ";
                getline(cin, itemName);

                addItem(sec, itemName);
                cout << "Item stored successfully!" << endl;
            }
            else if (choice == 5) {
                cout << "Enter item name to remove: ";
                getline(cin, itemName);

                removeItem(sec, itemName);
            }
            else {
                displaySection(sec);
            }

            break;
        }

        case 7: {
            cout << "Enter city: ";
            cin >> ws;
            getline(cin, city);

            Location *loc = findLocation(locations, city);

            cout << "Enter store name: ";
            getline(cin, storeName);

            Store *st = findStore(loc, storeName);
            displayStore(st);
            break;
        }

        case 0:
            cout << "Inventory system closed!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);
}

 // QUESTION #4

    void cinemaSeating(dNode *&start) {
    if (start == NULL || start->next == NULL ||
        start->next->next == NULL) {
        cout << "At least three nodes are required." << endl;
        return;
    }

    int count = 0;

    for (dNode *p = start; p != NULL; p = p->next) {
        count++;
    }

    int leftPos = 2;
    int rightPos = count - 1;

    while (leftPos < rightPos) {
        dNode *p = start;
        dNode *q = start;

        for (int i = 1; i < leftPos; i++) {
            p = p->next;
        }

        for (int i = 1; i < rightPos; i++) {
            q = q->next;
        }

        d_swapNodes(start, p, q);

        leftPos++;
        rightPos--;
    }
}


    // DOUBLY LINKED LIST


    struct c_Node {
    int info;
    c_Node *next;
};


void c_insertStart(int value, c_Node *&start) {
    c_Node *p, *q;

    // If the list is empty
    if (start == NULL) {
        p = new c_Node;
        p->info = value;
        p->next = p;
        start = p;
    }
    else {
        // Find the last node
        q = start;
        while (q->next != start) {
            q = q->next;
        }

        // Create new node at start
        p = new c_Node;
        p->info = value;
        p->next = start;

        // Update last node's link
        q->next = p;

        // Update head pointer
        start = p;
    }
}


void c_insertEnd(int value, c_Node *&start) {
    c_Node *p, *q;

    // If the list is empty
    if (start == NULL) {
        p = new c_Node;
        p->info = value;
        p->next = p;
        start = p;
    }
    else {
        // Traverse to the last node
        q = start;
        while (q->next != start) {
            q = q->next;
        }

        // Create new node
        p = new c_Node;
        p->info = value;

        // Connect new node to start
        p->next = start;

        // Connect old last node to new node
        q->next = p;
    }
}


void c_insertSpecific(int positionVal, int value,
                      c_Node *&start) {
    c_Node *p, *q;

    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    q = start;

    do {
        if (q->info == positionVal) {
            p = new c_Node;
            p->info = value;

            p->next = q->next;
            q->next = p;

            return;
        }

        q = q->next;

    } while (q != start);

    cout << "The value you entered was not found!"
         << endl;
}


void c_deleteStart(c_Node *&start) {
    // If list is empty
    if (start == NULL) {
        cout << "No node to delete!" << endl;
    }

    // If only one node exists
    else if (start->next == start) {
        delete start;
        start = NULL;
    }

    else {
        c_Node *p, *q;

        p = start;

        // Find the last node
        q = start;
        while (q->next != start) {
            q = q->next;
        }

        // Move start to the second node
        start = start->next;

        // Connect last node to new start
        q->next = start;

        // Delete old first node
        p->next = NULL;
        delete p;
    }
}



void c_deleteEnd(c_Node *&start) {
    // If list is empty
    if (start == NULL) {
        cout << "No node to delete!" << endl;
    }

    // If only one node exists
    else if (start->next == start) {
        delete start;
        start = NULL;
    }

    else {
        c_Node *p, *q;

        p = start;
        q = start->next;

        // Traverse until q reaches the last node
        while (q->next != start) {
            p = q;
            q = q->next;
        }

        // Make second-last node point to start
        p->next = start;

        // Delete last node
        q->next = NULL;
        delete q;
    }
}

void c_deleteSpecific(int value, c_Node *&start) {
    // If list is empty
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    c_Node *p, *q;

    // If first node contains the value
    if (start->info == value) {
        c_deleteStart(start);
        return;
    }

    // Search for the value
    p = start;
    q = start->next;

    while (q != start) {
        if (q->info == value) {
            p->next = q->next;

            q->next = NULL;
            delete q;

            return;
        }

        p = q;
        q = q->next;
    }

    cout << value << " isn't found in the list!"
         << endl;
}

void c_display(c_Node *&start) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    c_Node *p = start;

    do {
        cout << p->info << " ";
        p = p->next;
     } while (p != start);

    cout << endl;
}


int josephus(c_Node *&start, int M) {
    if (start == NULL || M <= 0)
        return -1;

    c_Node *current = start;
    c_Node *previous = start;

    // Find the last node
    while (previous->next != start) {
        previous = previous->next;
    }

    // Eliminate persons until one remains
    while (current->next != current) {
        // Skip M - 1 persons
        for (int i = 1; i < M; i++) {
            previous = current;
            current = current->next;
        }

        // Remove the Mth person
        previous->next = current->next;

        if (current == start)
            start = current->next;

        delete current;

        // Continue from the next person
        current = previous->next;
    }

    // Save the survivor's original position
    int survivor = current->info;

    delete current;
    start = NULL;

    return survivor;
}


void CircularlyInsertion(c_Node *&cnode) {
    int number;
    int position;
    char choice;

    do {
        cout << "\nDo you want to insert value at "
             << "start(s), end(e), after a specific value(k) "
             << "or terminate(t) program?" << endl;
        cin >> choice;

        if (choice == 'S' || choice == 's') {
            cout << "\nEnter number to be inserted: ";
            cin >> number;

            c_insertStart(number, cnode);
            c_display(cnode);
        }
        else if (choice == 'E' || choice == 'e') {
            cout << "\nEnter number to be inserted: ";
            cin >> number;

            c_insertEnd(number, cnode);
            c_display(cnode);
        }
        else if (choice == 'K' || choice == 'k') {
            cout << "\nEnter existing value and new value respectively: ";
            cin >> position >> number;

            c_insertSpecific(position, number, cnode);
            c_display(cnode);
        }
        else if (choice == 'T' || choice == 't') {
            break;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 'T' && choice != 't');
}


// robin task creator


struct TaskNode {
    string name;
    int priority;
    string status;
    TaskNode *next;
};


// Add a task at the end of the circular list
void addTask(TaskNode *&head, string name, int priority) {
    TaskNode *p = new TaskNode;
    p->name = name;
    p->priority = priority;
    p->status = "Pending";

    if (head == NULL) {
        p->next = p;
        head = p;
    }
    else {
        TaskNode *q = head;

        while (q->next != head) {
            q = q->next;
        }

        q->next = p;
        p->next = head;
    }

    cout << "Task added successfully!" << endl;
}


// Remove a task by name
void removeTask(TaskNode *&head, string name) {
    if (head == NULL) {
        cout << "Task list is empty!" << endl;
        return;
    }

    TaskNode *current = head;
    TaskNode *previous = NULL;

    do {
        if (current->name == name) {

            // Only one task exists
            if (current->next == current) {
                delete current;
                head = NULL;
            }
            else {
                // Find the previous node if deleting the head
                if (previous == NULL) {
                    previous = head;

                    while (previous->next != head) {
                        previous = previous->next;
                    }
                }

                previous->next = current->next;

                if (current == head) {
                    head = current->next;
                }

                delete current;
            }

            cout << "Task removed successfully!" << endl;
            return;
        }

        previous = current;
        current = current->next;

    } while (current != head);

    cout << "Task not found!" << endl;
}


// Display all tasks
void displayTasks(TaskNode *head) {
    if (head == NULL) {
        cout << "No tasks available!" << endl;
        return;
    }

    TaskNode *p = head;

    cout << "\n===== ALL TASKS =====" << endl;

    do {
        cout << "Name: " << p->name
             << " | Priority: " << p->priority
             << " | Status: " << p->status << endl;

        p = p->next;

    } while (p != head);
}


// Update task status by name
void updateTaskStatus(TaskNode *head, string name, string newStatus) {
    if (head == NULL) {
        cout << "Task list is empty!" << endl;
        return;
    }

    TaskNode *p = head;

    do {
        if (p->name == name) {
            p->status = newStatus;

            cout << "Task status updated successfully!" << endl;
            cout << "Task: " << p->name
                 << " | Status: " << p->status << endl;
            return;
        }

        p = p->next;

    } while (p != head);

    cout << "Task not found!" << endl;
}


// Get the next pending task in round-robin order
void getNextTask(TaskNode *&current) {
    if (current == NULL) {
        cout << "No tasks available!" << endl;
        return;
    }

    TaskNode *p = current;

    // Check each task at most once
    do {
        if (p->status == "Pending") {
            cout << "Next task to execute: " << p->name
                 << " | Priority: " << p->priority << endl;

            p->status = "In-progress";
            cout << "Status: " << p->status << endl;

            // Next search begins after this task
            current = p->next;
            return;
        }

        p = p->next;

    } while (p != current);

    cout << "No pending tasks available!" << endl;
}


// Round-robin task scheduler menu
void taskSchedulerMenu() {
    TaskNode *head = NULL;
    TaskNode *current = NULL;

    int choice;
    int priority;
    string name;
    string status;

    do {
        cout << "\n===== ROUND-ROBIN TASK SCHEDULER =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Get Next Task" << endl;
        cout << "4. Display All Tasks" << endl;
        cout << "5. Update Task Status" << endl;
        cout << "0. Exit Scheduler" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task name (one word): ";
                cin >> name;

                cout << "Enter task priority: ";
                cin >> priority;

                addTask(head, name, priority);

                if (current == NULL) {
                    current = head;
                }
                break;

            case 2:
                cout << "Enter task name to remove: ";
                cin >> name;

                {
                    TaskNode *oldHead = head;
                    TaskNode *oldCurrent = current;

                    removeTask(head, name);

                    if (head == NULL) {
                        current = NULL;
                    }
                    else if (oldCurrent != NULL &&
                             oldCurrent->name == name) {
                        current = head;
                    }
                    else if (oldHead != head && current == oldHead) {
                        current = head;
                    }
                }
                break;

            case 3:
                getNextTask(current);
                break;

            case 4:
                displayTasks(head);
                break;

            case 5:
                cout << "Enter task name: ";
                cin >> name;

                cout << "Enter new status "
                     << "(Pending/In-progress/Completed): ";
                cin >> status;

                if (status == "Pending" ||
                    status == "In-progress" ||
                    status == "Completed") {
                    updateTaskStatus(head, name, status);
                }
                else {
                    cout << "Invalid status!" << endl;
                }
                break;

            case 0:
                cout << "Exiting task scheduler..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    // Free all task nodes
    while (head != NULL) {
        if (head->next == head) {
            delete head;
            head = NULL;
        }
        else {
            TaskNode *last = head;

            while (last->next != head) {
                last = last->next;
            }

            TaskNode *temp = head;
            head = head->next;
            last->next = head;
            delete temp;
        }
    }

    current = NULL;
}





int main() {
    cout << "######## SINGLY LINKED LIST ASSIGNMENT ########"
         << endl;

    // Get the original list from the user
    Node *node = NULL;

    cout << "\nCreate the original linked list:" << endl;
    SinglyInsertion(node);

    cout << "\nOriginal list: ";
    display(node);

    // Run all ten questions one by one
    for (int question = 1; question <= 10; question++) {

        cout << "\n\n========================================"
             << endl;
        cout << "QUESTION NO. " << question << endl;
        cout << "========================================"
             << endl;

        // Make a fresh copy for this question
        Node *work = copyList(node);

        switch (question) {

            case 1:
                cout << "Display in reverse without modifying:"
                     << endl;
                reverseDisplay(work);
                cout << endl;

                cout << "List remains unchanged: ";
                display(work);
                break;

            case 2:
                cout << "Reverse the linked list:" << endl;
                reverseList(work);
                display(work);
                break;

            case 3:
                cout << "Remove duplicate contacts:" << endl;
                dupControl(work);
                display(work);
                break;

            case 4:
                cout << "Detect a loop in the list:" << endl;

                if (work != NULL) {
                    Node *tail = work;

                    while (tail->next != NULL) {
                        tail = tail->next;
                    }

                    // Create a loop for testing
                    tail->next = work;

                    if (hasLoop(work)) {
                        cout << "Loop detected!" << endl;
                    }
                    else {
                        cout << "No loop detected." << endl;
                    }

                    // Break the loop before deleting nodes
                    tail->next = NULL;
                }
                else {
                    cout << "Empty list: no loop." << endl;
                }
                break;

            case 5:
                cout << "Find the middle node:" << endl;

                if (work == NULL) {
                    cout << "List is empty." << endl;
                }
                else {
                    midFinder(work);
                }
                break;

            case 6:
                cout << "Separate even and odd values:" << endl;
                splitEvenOdd(work);
                break;

            case 7:
                cout << "Reverse both halves separately:" << endl;
                halfReversal(work);
                break;

            case 8:
                cout << "Remove duplicate stamp designs:" << endl;
                dupControl(work);
                display(work);
                break;

            case 9: {
                int target;

                cout << "Enter the ID to delete completely: ";
                cin >> target;

                cout << "Original list for this question: ";
                display(work);

                dupControl(work, target);

                cout << "After deleting all occurrences: ";
                display(work);
                break;
            }

            case 10:
                cout << "Swap every two consecutive nodes:"
                     << endl;
                rearrangeNodes(work);
                display(work);
                break;
        }

        // Release this question's working copy
        deleteList(work);
    }

    // Release the original list
    deleteList(node);

    cout << "\n######## END OF SINGLY LINKED LIST ########"
         << endl;




   cout << "################# DOUBLY LINKED LIST ########################## " << endl;

   dNode *dnode = NULL;

   cout << "\nCreate the original doubly linked list:" << endl;
   doublyInsertion(dnode);

   cout << "\nOriginal doubly linked list: ";
   d_display(dnode);

   for (int question = 1; question <= 4; question++) {

       cout << "\n========================================" << endl;
       cout << "DOUBLY LINKED LIST QUESTION " << question << endl;
       cout << "========================================" << endl;

       // Create a fresh copy for each question
       dNode *work = NULL;

       for (dNode *p = dnode; p != NULL; p = p->next) {
           d_insertEnd(p->info, work);
       }

       switch (question) {

           case 1:
               cout << "Reverse the desk arrangement:" << endl;
               deskReverse(work);
               d_display(work);
               break;

           case 2:
               cout << "Playlist navigation:" << endl;
               playlist(work);
               break;

           case 3: {
               cout << "Inventory management:" << endl;
               Location *locations = NULL;
               manageInventory(locations);
               break;
           }

           case 4:
               cout << "Rearrange cinema seating:" << endl;

               if (work == NULL || work->next == NULL ||
                   work->next->next == NULL) {
                   cout << "At least three nodes are required." << endl;
               }
               else {
                   cinemaSeating(work);
                   d_display(work);
               }
               break;
       }

       // Delete the working copy
       while (work != NULL) {
           d_deleteStart(work);
       }
   }

   // Delete the original doubly linked list
   while (dnode != NULL) {
       d_deleteStart(dnode);
   }

   cout << "\n######## END OF DOUBLY LINKED LIST ########" << endl;


   cout << "################# CIRCULAR LINKED LIST ########################## " << endl;

   c_Node *cnode = NULL;

   cout << "\nCreate the original circular linked list:" << endl;
   CircularlyInsertion(cnode);

   cout << "\nOriginal circular linked list: ";
   c_display(cnode);

   for (int question = 1; question <= 2; question++) {

       cout << "\n========================================" << endl;
       cout << "CIRCULAR LINKED LIST QUESTION " << question << endl;
       cout << "========================================" << endl;

       switch (question) {

           case 1: {
               int N, M;

               cout << "Josephus Problem" << endl;
               cout << "Enter number of people: ";
               cin >> N;

               cout << "Enter elimination interval M: ";
               cin >> M;

               if (N <= 0 || M <= 0) {
                   cout << "N and M must be positive." << endl;
                   break;
               }

               c_Node *circle = NULL;

               // Create a circle containing people 1 to N
               for (int i = 1; i <= N; i++) {
                   c_insertEnd(i, circle);
               }

               cout << "Initial circle: ";
               c_display(circle);

               int survivor = josephus(circle, M);

               cout << "The surviving person's position is: "
                    << survivor << endl;

               break;
           }

           case 2:
               cout << "Round-robin task scheduler" << endl;

               // Call your task-scheduler menu here
               // after defining its node structure and function.

               break;
       }
   }

   // Delete the original circular linked list
   while (cnode != NULL) {
       c_deleteStart(cnode);
   }

   cout << "\n######## END OF CIRCULAR LINKED LIST ########" << endl;


    return 0;
}





