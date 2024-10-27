#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int NoOfRoom;
void main()
 {
  printf("Enter the total no of Room :");
  scanf("%d", &NoOfRoom);
   Create();
   EmptyRoom();
   AtPosition();
   StudentDetail();
   NuumberOfStudentAtLeave();
   NoticeCreate();
   FeesDetails();
 }

    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    }*temp, *head, *tail, *newnode, *temprev;



    void Create()
    {
    head=0;
    for(int i=1; i<=NoOfRoom; i++)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the Data in %d node : ",i);
    scanf("%d", &newnode->data);
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
        {
        head=newnode;
        temp=newnode;
        }
    else
        {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
        }
    }
    }

    static int NonEmptyRoom=0;

    void EmptyRoom()
    {
    temp=head;

    int a=0;
    for(int j=1; j<=NoOfRoom; j++)
        {
    if(temp->data==0)
    {
        printf("\n Room Number Which is Empty= %d ", j);
        a++;
    }
    temp=temp->next;
        }
        NonEmptyRoom=NoOfRoom-a;
        printf("\n Total Number of Occupied Rooms=%d ", NonEmptyRoom);
    }

    void AtPosition(){
        temp=head;
        int pos, i=1;
        printf("\n Enter the posion at which the Room is being allocated\n");
        scanf("%d", &pos);
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temprev=temp->prev;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\n Enter the Data of newnode : ");
        scanf("%d", &newnode->data);


        if(newnode->data!=0){
            NonEmptyRoom++;
        }
        newnode->next=temp->next;  
        newnode->prev=temp->prev;
        free(temp);
    temprev->next=newnode;



        temp=head;
    while(temp!=0){
        printf("\n %d", temp->data);
        temp=temp->next;
    }
    }


    void StudentDetail(){
    int MobileNo[NonEmptyRoom];

    char Name[NonEmptyRoom][50]; // Adjust the size according to your needs
     
        fflush(stdin);
        for (int i = 0; i <NonEmptyRoom; i++) {
            printf("\n Enter Student Name of Room No %d: ", i+1);
        
            // Read the string from user
            fgets(Name[i], sizeof(Name[i]), stdin);
        
            // Remove the newline character at the end if present
            if (Name[i][strlen(Name[i]) - 1] == '\n') {
                Name[i][strlen(Name[i]) - 1] = '\0';
            }

        }
        for(int i=0; i<NonEmptyRoom; i++) {
            printf("Enter the mobile No of Student in room no %d: ", i+1);
            scanf("%d", &MobileNo[i]);
        }

        for (int i = 0; i <NonEmptyRoom; i++) {
            printf("\n \n Details of student in room no: %d", i+1);
            printf("\n  Name: %s", Name[i]);
            printf("\n mobile No of Student in room no :%d = %d", i+1, MobileNo[i]);
        }

        return 0;
    }

    static int c=0;

    void NuumberOfStudentAtLeave()
    {    
        char select;
        printf(" \n Press r to go to case returned student AND c to go to add leave student \n");
        scanf("%s", &select);
        switch(select){
            case 'c':
                    c++;
                printf("\n Number Of Student At Leave :%d", c);
                break;
            case 'r':
                    if(c==0){
                        printf("\n No Student are at Leave.");
                        break;
                    }
                    c--;
                    printf("\n Number Of Student At Leave :%d", c);
                    break;
            default:
                    printf("\n number of Student At Leave = %d ",c);
        }

    
    }
    
    void NoticeCreate()
    {

            printf("\n                                             [NOTICE]                   ");
            printf(" \n This is to inform you that from tommorow onwards the outgoing timing has been changed.\n");
            printf("\n The new timing is till 10 pm.");

    }

    void FeesDetails()
    {
        printf("\n --> WARNING!:   NO ONE IS ALLOWED TO USE ANY KIND OF HEAVY ELECTRICAL APPLIANCES LIKE:- IRON, KETEL etc. IF FOUND THAN HEAVY PENALTY MAY BE IMPOSED.\n");
        printf("\n --> TOBACOO IS STRICTLY PRIHIBITED!");
        printf("\n                                              [FEES DEATILS]                        \n");
        printf("\n -->Rooms without AC : 70,000 per year.\n");
        printf("\n -->Rooms with AC : 75,000 per year.\n");
    }
