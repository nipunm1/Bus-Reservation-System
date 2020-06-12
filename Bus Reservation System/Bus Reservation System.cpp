#include <iostream>
#include <string.h>
using namespace std;

static int p=0;
class bus{
    char bus_no[10], driver_name[30], arrival_time[10], depart_time[10], from[20], to[20], seat[8][4][10];
    public:
        void install();
        void available();
        void allotment();
        void vacant();
        void show();
        void position(int l);
};
bus b[10];
void bus::install(){
    cout<<"Enter Bus Number \n";
    cin>>b[p].bus_no;
    cout<<"Enter Drivers Name \n";
    cin>>b[p].driver_name;
    cout << "From \n";
    cin >> b[p].from;
    cout << "To \n";
    cin >> b[p].to;
    cout<<"Enter Arrival Time \n";
    cin>>b[p].arrival_time;
    cout<<"Enter Departure Time \n";
    cin>>b[p].depart_time;
    b[p].vacant();
    p++;
}
void bus::available() {
    int i;
    for(i=0;i<p;i++) {
        printf("---------------------------------------------------------------------------\n");
        cout<<"Bus number : "<<b[i].bus_no<<" Driver Name : "<<b[i].driver_name<<" From : "<<b[i].from<<" To : "<<b[i].to<<" Arrival Time : "<<b[i].arrival_time<<" Departure Time : "<<b[i].depart_time<<endl;
        printf("---------------------------------------------------------------------------\n");
    }
}
void bus::allotment(){
    int seat,i;
    char num[10];
    cout<<"Enter Bus Number : ";
    cin>>num;
    for(i=0;i<=p;i++){
        if(strcmp(b[i].bus_no, num)==0){
            break;
        }
    }
    if(i<=p){
        cout<<"Enter Seat Number : ";
        cin>>seat;
        if(seat>32){
            cout<<"There is only 32 seats in this bus.\n";
        }
        else{
            if(strcmp(b[i].seat[seat/4][(seat%4)-1],"Vacant")==0){
                cout<<"Enter Passengers Name : ";
                cin>>b[i].seat[seat/4][(seat%4)-1];
            }
            else{
                cout<<"This seat is already reserved \n";
            }
        }
    }
    if(i>p){
        cout<<"Enter correct bus number \n";
    }
}
void bus::show(){
    int n,a=1,i,j;
    char number[10];
    cout<<"Enter Bus Number \n";
    cin>>number;
    for(n=0;n<=p;n++){
        if(strcmp(b[n].bus_no, number)==0){
            break;
        }
    }
    while(n<=p){
        cout << "Bus number : " << b[n].bus_no << " Driver Name : " << b[n].driver_name << " From : " << b[n].from << " To : " << b[n].to <<endl;
        b[n].position(n);
        for(i=0;i<8;i++){
            for(j=0;j<4;j++){
                a++;
                if(strcmp(b[n].seat[i][j],"Vacant")!=0) {
                    cout<< "The seat number "<<(a - 1)<<" is reserved \n";
                }
            }
        }
        break;
    }
    if(n>p){
        cout<<"Enter correct Bus number \n";
    }
}
void bus::position(int l){
    int seats=0, vac_seats=0;
    int i, j;
    for(i=0;i<8;i++){
        for(j=0;j<4;j++){
            seats++;
            if(strcmp(b[l].seat[i][j],"Vacant")==0){
                cout<<seats<<"."<< b[l].seat[i][j]<<"\t";
                vac_seats++;
            }
            else {
                cout<<seats<<"."<<b[l].seat[i][j]<<"\t";
            }
        }
    }
    cout<<endl<<"There are "<<vac_seats<<" seats are empty in Bus no: "<<b[l].bus_no<<endl;
}
void bus::vacant(){
    int i,j;
    for(i = 0; i < 8; i++){
        for (j = 0; j < 4; j++){
            strcpy_s(b[p].seat[i][j], "Vacant");
        }
    }
}
int main(){
    system("cls");
    int choice;
    do {
        cout<<"********************************************************************* \n";
        cout<<"1. For Install New Bus Details \n";
        cout<<"2. Buses Available \n";
        cout<<"3. Show seats \n";
        cout<<"4. For Seat Reservation \n";
        cout<<"5. For Exit \n";
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<"********************************************************************* \n";
        switch(choice){
            case 1:b[p].install();break;
            case 2:b[p].available();break;
            case 3:b[p].show(); break;
            case 4:b[p].allotment(); break;
            case 5: exit(1);
            default:cout<<"Invalid choice \n";
        }

    } while (choice!=5);
    system("pause");
    return 0;
}
