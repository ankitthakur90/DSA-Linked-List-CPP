#include<iostream>
#include<map>

using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }

};
void append(Node* &Head,Node* &tail,int data){

   Node* temp = new Node(data);

   Node* curr = Head;

   while (curr->next != NULL)
   {
  
     curr = curr ->next;

   }
   curr->next = temp;

   tail = temp;

}


void show(Node* &Head){
    Node* curr = Head;

    while (curr!=NULL)
    {
       cout<<curr->data<<" ";
       curr = curr->next;
    }
    cout<<endl;
    
}

bool detectLoop(Node* Head){

    Node* curr = Head;

    map<Node* , bool> visited;

    while (curr!=NULL)
    {
        if(visited[curr] == true){
            return 1;
        }
        visited[curr] = true;

        curr = curr->next;

    }
    return 0;
    
}




int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(5);
   
    Node *Head = Node1;
    Node *tail = Node1;

    

    append(Head,tail,8);
    append(Head,tail,10);
    append(Head,tail,20);
    append(Head,tail,30);
    

  tail->next = Head->next; // This will create cycle 
  // show(Head);
    // cout<<Head->data<<endl;
    // cout<<tail->data<<endl;

    if(detectLoop(Head)){
        cout<<" Cycle Is Present! "<<endl;
    }
    else{
        cout<<" Cycle Not Is Present! "<<endl;
    }






    return 0;
}
