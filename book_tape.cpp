#include<iostream>
#include<stdio.h>
using namespace std;
class publication 
{
    private:
    string title;
    float price;

    public:
    void add()
    {
        cout<<"\n------------enter the publication info----------"<<endl;
        cout<<"enter the title of the publication :";
        cin.ignore();
        getline(cin,title);
        cout<<"enter the price of publication :";
        cin>>price;
    }

    void display()
    {
        cout<<"\n----------------------------------";
        cout<<"\ntitle of publication "<<title;
        cout<<"\npriceeee :"<< price;
    }

};

class book: public publication
{
    private: int pg_count;
    public: void add_book(){
        try
        {
            add();
            cout<<"enter page count of book :";
            cin>>pg_count;
            if(pg_count<=0){
                throw pg_count;
            }
        }
        catch(...)
        {
            cout<<"\ninvalid page count";
            pg_count = 0;
        }
        
    }
    void display_book(){
        display();
        cout<<"\npagecount :"<<pg_count;
        cout<<"\n-----------------------------------";
    }
};

class tape:public publication
{
    private: float play_time;
    public: void add_tape()
    {
        try{
            add();
            cout<<"enter play duration of the tape : ";
            cin>>play_time;
            if(play_time<=0)
            
                throw play_time;
            
        }catch(...){
                cout<<"\ninvalid play time";
                play_time =0;
            }
    }
        void display_tape()
        {
            display();
            cout<<"\nplay time :"<<play_time<<"min"<<endl;
            cout<<"-------------------------------";
        }
    
};

int main()
{
    book b1[10];
    tape t1[10];

    int ch,x=0,y=0;
    do
    {
        cout<<"\n-----publication database system------";
        cout<<"\n--------menu-------";
        cout<<"\n1. add info to books";
        cout<<"\n2. add info to tapes";
        cout<<"\n3. display books info";
        cout<<"\n4. display tape info";
        cout<<"\n5. exit ";
        cout<<"\n enter your choice";
        cin>>ch;
        switch(ch){
            case 1:
            b1[x].add_book();
            x++;
            break;

            case 2:
            t1[y].add_tape();
            y++;
            break;

            case 3:
            cout<<"\n---book publication db system";
            for(int j=0;j<x;j++)
            {
                b1[j].display_book();
            }
            break;

            case 4:
            cout<<"\n-----tape pub db sys----";
            for(int j = 0;j<y;j++)
            {
                t1[j].display_tape();
            }
            break;

            case 5:
            exit(0);
        }
    } while (ch != 5);
    return 0;
    
}
