#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<vector>

using namespace std;


class NursingHome{
    private:
    string name,age,BGroup,disease;
    vector<pair<string,double>>med;

    public:
    NursingHome():name(""),age(""),BGroup(""),disease(""){}

    void setName(string name){
        this->name=name;
    }

    void setAge(string age){
        this->age=age;
    }

    void setGroup(string BGroup){
        this->BGroup=BGroup;
    }

    void setMed(string medName,double price){
        
        med.push_back(make_pair(medName,price));

    }
    
    void setDisease(string disease){
        this->disease=disease;
    }

    vector<pair<string,double>> getMed(){
        return this->med;
    }

    string getName(){
        return this->name;
    }

    string getAge(){
        return this->age;
    }

    string getBGroup(){
        return this->BGroup;
    }

    string getDisease(){
        return this->disease;
    }

};
double sum=0;

void discharge(){
    system("cls");

    string name;
    cout<<"Enter name of Patient: ";
    cin>>name;

    ifstream infile("NursingHome.txt");
    ofstream outfile("NursingHome Temp.txt");

    if(!infile || !outfile){
        cout<<"Error: File Can't Open!"<<endl;

    }
    else{
        string line;
        bool found=false;
        while(getline(infile,line)){
            stringstream ss;
            ss<<line;
            string patientName;
            ss>>patientName;
            if(name == patientName){
                found =true;
                cout<<"Total Bill is:"<<sum<<endl;
                double val;
                cout<<"Total amount "<<patientName<<"has:";
                cin>>val;
                if(val>=sum)
                cout<<patientName <<"is Discharged!"<<endl;
                else
                cout<<patientName <<"is not Discharged!"<<endl;     
                sum=0;
            }
            else{
                outfile<<line<<endl;

            }
        }
        if(!found){
            cout<<"Incorrect name!"<<endl;
        }
        
    }
    outfile.close();
    infile.close();
    remove("NursingHome.txt");
    rename("NursingHome Temp.txt","NursingHome.txt");
    Sleep(3000);
}

void admit(NursingHome n){
    system("cls");
    
    string name,age,group,disease;

    cout<<"Enter Name of Patient:";
    cin>>name;
    n.setName(name);

    cout<<"Enter Age of Patient:";
    cin>>age;
    n.setAge(age);

    cout<<"Enter blood group of Patient:";
    cin>>group;
    n.setGroup(group);

    cout<<"Enter the disease the patient was diagonised with:";
    cin>>disease;
    n.setDisease(disease);


    int cnt;
    cout<<"Number of medicines patient has to take:";
    cin>>cnt;
    int i=cnt;
    cout<<"Enter the name of medicine and its cost:"<<endl;
    while(i--){
        string medName;
        double medCost;
        cin>>medName>>medCost;
        sum+=(double)medCost;
        n.setMed(medName,medCost);
    }
    
    ofstream outfile("NursingHome.txt",ios::app);
    if(!outfile.is_open()){
        cout<<"\tError:File can't open"<<endl;
    }
    else{
        outfile<<"\t"<<n.getName()<<" : "<<n.getAge()<<" : "<<n.getBGroup()<<" : "<<n.getDisease()<<":"<<"Medicines: ";
        vector<pair<string,double>>p;
        p=n.getMed();
        int i=0;
        while (i<cnt)
        {
            outfile<<p[i].first<<" "<<p[i].second;
            i++;
        }outfile<<endl;
        cout<<"Patient Admitted!"<<endl;
        
    }
    outfile.close();
    Sleep(3000);
}
int main(){

    NursingHome n1;

    bool exit=false;
    while(!exit){
        system("cls");
        int val;
        cout<<"Nursing Home Management System"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1.Admit Patient"<<endl;
        cout<<"2.Discharge Patient"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter Choice:";
        cin>>val;

        if(val==1){
            admit(n1);
        }
        else if(val==2){
            discharge();
        }
        else if(val==3){
            system("cls");
            exit=true;
            cout<<"\tThanks for choosing us!"<<endl;
            Sleep(3000);
        }

        Sleep(3000);

    }
    
    

    return 0;
}