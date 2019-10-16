#include<stdio.h>
#include<stdlib.h>
typedef int ll;
 struct node
{
    ll data;
    struct node* next;
    struct node*prev;
};


struct node* push_back(ll data, struct node* curr)
{
    curr->next = (struct node*)malloc(sizeof(struct node));
    struct node *temp =  (struct node*)malloc(sizeof(struct node));
    temp = curr;
    curr = curr->next;
    curr->data = data;
    curr->next = NULL;
    curr->prev = temp;
    return curr;
}
int main()
{
    ll t;
    scanf("%d",&t);
    while(t--)
    {

        struct node*curr = (struct node*)(malloc(sizeof(struct node)));
        struct node*head = (struct node*)(malloc(sizeof(struct node)));

        head = curr;
        curr->data = 1;
        curr->next = NULL;
        curr->prev = NULL;
        ll current_length = 1;
    ll k;
    scanf("%d",&k);
	if(k==0)
		k=1;
    

    
        for(ll j=1;j<=k;j++)
        {
            ll carry=0,product, go;
            curr  = head;
            for(ll i=0;i<current_length;i++)
            {
                product = (curr->data)*k+carry;
                go = product%10;
                (curr->data) = go;
                carry = product/10;
                if(curr->next!=NULL)
                curr=curr->next;

            }
            if(carry!=0)
            {
                while(carry!=0)
                {
                    go = carry%10;
                    curr = push_back(go, curr);
                    current_length++;
                    carry=carry/10;
                }
            }

        }
    
    ll counter = 0;


    struct node*end = (struct node*)(malloc(sizeof(struct node)));
    end = curr;
    curr = head;
    while(curr!=NULL)
    {
        if(curr->data== 0)
        {
            counter++;
        }
        if(curr->data!= 0)
            break;
        curr   =  curr->next;
    }
   



    curr = end;
  while(curr!= NULL)
  {
      printf("%d",curr->data);
      curr=curr->prev;
  }
    printf("\n");

  }

}

