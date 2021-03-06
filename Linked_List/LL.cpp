#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Linked_List{
    public:
    ll data;
    Linked_List *next;
    Linked_List(){
        this->next=NULL;
    }
    Linked_List(ll data){
        this->data=data;
        this->next=NULL;
    }
    Linked_List* add(ll data,Linked_List* &head){
        if(head==NULL){
            Linked_List* temp=new Linked_List(data);
            head=temp;
        }
        else{
            Linked_List* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            Linked_List* temp=new Linked_List(data);
            ptr->next=temp;
        }
        return head;
    }
    void Print_Linked_List(Linked_List* head){
        while(head){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
    Linked_List* Find_Middle(Linked_List* head){
        Linked_List *sp=head,*fp=head->next;
        if(head==NULL or head->next==NULL){
            return head;
        }
        while(fp and fp->next)
        {
            sp=sp->next;
            fp=fp->next;
            fp=fp->next;
        }
        return sp;
    }
    Linked_List* Delete_Middle(Linked_List *head){
         Linked_List *sp=head,*fp=head->next,*pre;
         if(head==NULL or head->next==NULL)
             return head;
         while(fp and fp->next){
             pre=sp;
             sp=sp->next;
             fp=fp->next->next;
         }
         pre->next=sp->next;
         delete sp;
         return head;
    }
    Linked_List* Delete_Linked_List(Linked_List* head){
        if(head==NULL)
             return head;
        if(head->next==NULL){
            delete head;
            return head;
        }
        Linked_List* cur=head ,*pre=head;
        while(cur){
            pre=cur;
            cur=cur->next;
            delete pre;
        }
        return head;
    }
    void Print_Reverse(Linked_List* head){
        if(head==NULL)
        return;
        Print_Reverse(head->next);
        cout<<head->data<<" ";
        return;
    }
    Linked_List* Reverse_Linked_List(Linked_List* head){
        if(head==NULL or head->next==NULL){
            return head;
        }
        Linked_List *pre=NULL,*cur=head,*next=head;
        while(cur){
            next=next->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        head=pre;
        return head;
    }
    bool Is_Palindrome(Linked_List *&left,Linked_List *right){
        if(right==NULL){
            return true;
        }
        bool first=Is_Palindrome(left,right->next);
        bool second=left->data==right->data;
        left=left->next;
        return first and second;
    }
    Linked_List* Remove_Duplicate_Sorted(Linked_List* head){
        Linked_List *pre=head, *cur=head->next;
        if(head==NULL and head->next==NULL)
            return head;
        while(cur){
            if(cur->data==pre->data){
                pre->next=cur->next;
                cur=cur->next;
            }
            else{
                pre=cur;
                cur=cur->next;
            }
        }
        return head;
    }
    Linked_List* Remove_Duplicate_Unsorted(Linked_List* head){
        map<int,int> m;
        Linked_List *pre=NULL,*cur=head;
        if(head==NULL and head->next==NULL)
              return head;
        while(cur){
            if(m[cur->data]>0){
                pre->next=cur->next;
                cur=cur->next;
            }
            else{
                m[cur->data]=cur->data;
                pre=cur;
                cur=cur->next;
            }
        }
        return head;
    }
    bool Detect_Loop(Linked_List* head){
        Linked_List *sp=head,*fp=head;
        while(fp and fp->next)
        {
            sp=sp->next;
            fp=fp->next->next;
            if(sp==fp)
                return true;
        }
        return false;
    }
    Linked_List* Remove_Loop(Linked_List* head){
        Linked_List *sp=head,*fp=head;
        while(sp and fp and fp->next)
        {
            sp=sp->next;
            fp=fp->next->next;
            if(sp==fp)
               break;
        }
        if(sp==fp)
        {
                
            sp=head;
            if(sp==fp)
            {
                while(fp->next != sp)
                {
                    fp=fp->next;
                }
            }
            else
            {
                while(sp->next != fp->next)
                {
                    sp=sp->next;
                    fp=fp->next;
                }
            }
            fp->next=NULL;
        }
        
        return head;
    }
    Linked_List* Intersection_Point(Linked_List* cur1,Linked_List* cur2){
        Linked_List *o=cur1,*l=cur2;
        while(cur1!=cur2){
            if(cur2==NULL){
                cur2=o;
            }
            else
               cur2=cur2->next;
            if(cur1==NULL){
                cur1=l;
            }
            else
               cur1=cur1->next;
            
        }
    }
    Linked_List* ODD_EVN(Linked_List* head){
        Linked_List *o=head,*e=head->next,*ptr=e;
        if(head==NULL or head->next==NULL or head->next->next==NULL)
             return head;
        while(o->next and e->next){
            o->next=e->next;
            o=e->next;
            e->next=o->next;
            e=o->next;
        }
        o->next=ptr;
        return head;
    }
    Linked_List *merge(Linked_List *head1,Linked_List *head2)
    {
        if(head1==NULL or head2==NULL){
            return (head1==NULL)?head2:head1;
        }
        if(head1->data<head2->data){
            head1=merge(head1->next,head2);
            return head1;
        }
        else{
            head2=merge(head1,head2->next);
            return head2;
        }
    }
    Linked_List* merge_sort(Linked_List* head)
    {
        if(head==NULL and head->next==NULL){
            return head;
        }
        Linked_List *sp=head,*fp=head,*pre=sp;
        while(fp and fp->next){
            pre=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        pre->next=NULL;
        auto h1=merge_sort(head);
        auto h2=merge_sort(sp);
        return merge(h1,h2);
        
    }
};
int main(){
    Linked_List* head=new Linked_List(2);
    head=head->add(2,head);
    head=head->add(5,head);
    head=head->add(2,head);
    head=head->add(7,head);
    head=head->add(2,head);
    head=head->add(5,head);
    head=head->add(8,head);
    head=head->add(7,head);
    // head->Print_Linked_List(head);
    // head=head->Find_Middle(head);
    // cout<<endl<<head->data<<endl;
    // head=head->Delete_Middle(head);
    // head->Print_Linked_List(head);
    // head->Delete_Linked_List(head);
    // head->Print_Linked_List(head);
    // head->Print_Reverse(head);
    // head=head->Reverse_Linked_List(head);
    // head->Print_Linked_List(head);
    // cout<<endl;
    // cout<<head->Is_Palindrome(head,head);
    // head=head->Remove_Duplicate_Sorted(head);
    // head->Print_Linked_List(head);
    // head=head->Remove_Duplicate_Unsorted(head);
    // head->Print_Linked_List(head);
    // Linked_List *ptr;
    // ptr=head;
    // ptr=ptr->next->next;
    // while(head->next){
    //     head=head->next;
    // }
    // head->next=ptr;
    // cout<<head->Detect_Loop(head);
    // head=head->Remove_Loop(head);
    // head->Print_Linked_List(head);
    
}
