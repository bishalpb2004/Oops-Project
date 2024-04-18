#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<vector>
using namespace std;

class Government
{
    public:
    int annual_come;
};
class NursingHome:public Government{
    private:
    string name,age,BGroup,disease,doctorName,contactNumber;
    int noDays;
    vector<pair<string,double>>med;

    public:
    NursingHome():name(""),age(""),BGroup(""),disease(""),doctorName(""),contactNumber(""),noDays(0){}

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

    void setDName(string dName){
        this->doctorName=dName;
    }

    void setContactNumber(string contactNumber){
        this->contactNumber=contactNumber;
    }

    void setNoDays(int noDays){
        this->noDays=noDays;
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

    string getDName(){
        return this->doctorName;
    }

    string getContactNumber(){
        return this->contactNumber;
    }

    int getNoDays(){
        return this->noDays;
    }

};
double sum=0;
int rate=2000;

void discharge(NursingHome n){
    system("cls");
    string name;
    cout<<"Enter name of Patient: ";
    cin>>name;
    bool checkers=true;
    ifstream infile("NursingHome.txt");
    ofstream outfile("NursingHome Temp.txt");

    if(!infile || !outfile){
        cout<<"Error: File Can't Open!"<<endl;

    }
    else{
        infile.seekg(0);
        string line;
        bool found=false;
        
        while(getline(infile,line))
        {
            stringstream ss;
            ss<<line;
            string patientName;
            ss>>patientName;
            if(name == patientName){
                found =true;
                int noDays;
                cout<<"Number of Days patient stayed:";
                cin>>noDays;
                n.setNoDays(noDays);
                
                sum+=(double)(noDays*rate);
                cout<<"Total Bill is:"<<sum<<endl;
                double val;
                cout<<"Total amount "<<patientName<<" has:";
                cin>>val;
                cout<<"Enter the annual income of "<<patientName<<":";
                cin>>n.annual_come;
                if(val>=sum || n.annual_come<=100000){
                    cout<<patientName <<" is Discharged!"<<endl;
                }
                
                else
                {
                    checkers=false;
                    cout<<patientName <<" can't be Discharged!"<<endl;     
                    
                    
                }
                
            }
            else
            {
                outfile<<line<<endl;
            }
        }
        if(!found){
            cout<<"Incorrect name!"<<endl;
        }
        
    }
    if(!checkers){
        outfile.close();
        infile.close();
    }

    else{
        outfile.close();
        infile.close();
        remove("NursingHome.txt");
        rename("NursingHome Temp.txt","NursingHome.txt");
    }
    
    Sleep(3000);
}

void admit(NursingHome n){
    system("cls");
    
    string name,age,group,disease,dName,contactNumber;

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

    cout<<"Enter contact number of the patient:";
    cin>>contactNumber;
    n.setContactNumber(contactNumber);

    cout<<"Enter name of doctor assigned for the patient:";
    cin>>dName;
    n.setDName(dName);

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
        outfile<<"\t"<<n.getName()<<" : "<<n.getAge()<<" : "<<n.getBGroup()<<" : "<<n.getDisease()<<" : "<<"Medicines: ";
        vector<pair<string,double>>p;
        p=n.getMed();
        int i=0;
        while (i<cnt)
        {
            outfile<<p[i].first<<" "<<p[i].second;
            i++;
        }
        outfile<<" : "<<n.getContactNumber()<<" : "<<n.getDName();
        outfile<<endl;
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
            discharge(n1);
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


