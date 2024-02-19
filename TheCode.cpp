#include <iostream>
#include <ctime>
 


using namespace std;

int main(){
    bool allValidInput;
    string fullname, ID, Batchyear;
    char acPosition;
    int numofspaces, Year;

    bool validName, validID;
    bool validBatchYear, validAcPosition;

    int counter=0;

    string firstname, middlename, familyname;
    string username, email, password;
    string  emailname;

    do{
        allValidInput = true;
        validName=true, validID=true;
        validBatchYear=true, validAcPosition=true;
        numofspaces = 0;

        cout << "Enter a full name: ";
        getline(cin, fullname); 
       
        for(int i = 0; i < fullname.length(); i++) {
            if (fullname[i] == ' '){
                ++numofspaces;
            }
        }
        if(numofspaces != 2){
            validName=false;
        }

        cout << "Enter your ID:";
        cin >> ID;
        for (int i = 0; i < ID.length();i++) {
            if ( ! isdigit(ID[i]) ) {
                validID = false;
            }
        } 
        if (ID.length() != 10){
            validID = false;
        }

        cout << "Enter Academic Position (E/e for Employee, S/s for Student): ";
        cin >> acPosition;
        if ( acPosition != 'E' && acPosition != 'S' && acPosition!='e' && acPosition!='s') {
            validAcPosition = false;
        }

        if (acPosition=='S' || acPosition =='s' ){
            cout << "Please enter Batch year: ";
            cin >> Batchyear;
            if (Batchyear.length()== 4){
                for (int i = 0; i < Batchyear.length(); i++) {
                    if (!isdigit(Batchyear[i])) {
                        validBatchYear=false;
                    }
                } 

                Year =stoi(Batchyear);
                if(Year < 2013 || Year > 2023){
                    validBatchYear=false;
                }
             }else{
                validBatchYear=false;
             } 
        }

        if( !validName || !validID || !validAcPosition || !validBatchYear ){
            allValidInput=false; 
            cout<<"\n\n"; 
            cout<<"Information entered incorrectly. Please try again.";
            cout<<"\n\n";
        } 

      cin.ignore(); 
     counter++;
    }while ( ! allValidInput );
    
    int firstSpace, lastSpace;
    for (int x=0; x<fullname.length();x++){
        if (fullname[x] == ' '){
            firstSpace=x;
            break;
        }
    }
    for (int x=0; x<fullname.length();x++){
        if (fullname[x] == ' '){
            lastSpace=x;
        }
    }

    firstname = fullname.substr(0, firstSpace);
    middlename = fullname.substr(firstSpace+1 , lastSpace-firstSpace-1 );
    familyname = fullname.substr(lastSpace+1 , fullname.length());
            
    char _1name = toupper(firstname[0]);
    char _2name = tolower(middlename[0]);
    char _3name = tolower(familyname[0]);
    char underscore = '_';
    string _id = ID.substr(4, 6);
            

    switch (acPosition) {
        case 'e':
        case 'E':{
             for (int i = 0; i < firstname.length(); i++) {
                firstname[i] = toupper(firstname[i]);
           }

             for (int i = 0; i < middlename.length(); i++) {
                middlename[i] = toupper(middlename[i]);
           }

             for (int i = 0; i < familyname.length(); i++) {
                familyname[i] = toupper(familyname[i]);
           }
            username += firstname[0];
            username += middlename[0];
            username += familyname;
        
            cout << "\n Username: " << username;


            string efirstname;
            string emiddlename;
            string efamilyname;

            for (int i = 0; i < firstname.length(); i++) {
               efirstname += tolower(firstname[i]);
           }
        
            for (int i = 0; i < middlename.length(); i++) {
               emiddlename += tolower(middlename[i]);
           }
        
            for (int i = 0; i < familyname.length(); i++) {
               efamilyname += tolower(familyname[i]);
           }
            
            emailname += efirstname[0];
            emailname += emiddlename[0];
            emailname += efamilyname;

            email = emailname + "@iau.edu.sa";
            cout << "\n Email: " << email << endl;
       
       
            password += _1name;
            password += _2name;
            password += _3name;
            password += underscore;
            password +=_id;
            
            cout<<"Password: " <<password <<endl;
          break;
        }
        case'S':
        case's':{
            int num_;
            string year;
            year=Batchyear.substr(2, 2);
            srand(time(0));
            num_=rand()%10000;
            cout<<"\n Username:"<<"2"<<year<<"000"<<num_;
            cout<<"\n Email:"<<"2"<<year<<"000"<<num_<<"@iau.edu.sa";
            
            
            password += _1name;
            password += _2name;
            password += _3name;
            password += underscore;
            password +=_id;
            
            cout<<"\n Password: " <<password;
            break;
        }
    }
        
        
cout<<"\n User information entered successfully, after "<<counter<<" attempts.";   
    return 0;
}
