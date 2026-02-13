#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;
struct log
{
    char username[10];
    char password[10];
}log1;
struct stuinfo
{
    char name[10];
    char add[10];
    char email[10];
    int roll,age,hindi,eng,sci,phone;
}s;
struct tea
{
    char name[20];
    char email[20];
    int id;
    char add[50]; 
    int phone,age;
    long salary;
    char sub[29];
    char clss[20];
}t;
//*************************************************/
    class school
  {
    public:
     /*void login();
     void addinfo(int);
     void displayinfo(int);
     void deleteinfo(int);
     void updatetinfo(int);
     void findinfo(int);*/
     void menu();
     void sign_in();
     void sign_up();
     void m_menu();
     void admin_menu();
     void teacher_menu();
     void student_menu();
     void addinfo();
     void deleteinfo();
     void updateinfo();
     void disp_stui();
     void findinfo();
     void display_admin();
     void updateinfo_student();
     void upteacher();
     void onstup();
     void onteach();
     void disp_teach();

  }admin1;
//************************************/
void school::teacher_menu()
{
    int c;
    cout<<"1. Disp Teacher\n";
    cout<<"2. Update Teacher\n";
    cout<<"3. Update Marks\n";
    cout<<"4. Back\n";
    cout<<"choice\n";
    cin>>c;
    do{
         if(c==1)
            admin1.disp_teach();
        else if(c==2)
            admin1.onteach();
        else if(c==3)
        admin1.updateinfo_student(); 
        else if(c==4)
            admin1.m_menu();
           else
          exit(0); 
    }
    while(c!=0);
}

void school::onteach()
{
    int swami,e;
    cout<<" enter id to update teacher info ";
    cin>>swami;
    int found=0;
    ifstream fin("teacher.dat",ios::in | ios::binary);
    ofstream fout("temp.dat",ios::out | ios::binary);
    tea t;
    while(fin.read((char*)&t,sizeof(t)))
    {
        if(t.id==swami)
        {
            found=1;
            cout<<" enter new name ";
            cin>>t.name;
             cout<<" enter new adress ";
             cin>>t.add;
             cout<<" enter new phone no ";
             cin>>t.phone;
             cout<<" enter new email id ";
             cin>>t.email;
             cout<<"yes\n";
        }

        else
        {
          fout.write((char*)&t,sizeof(t));  
          admin1.teacher_menu();
        }
    
    fin.close();
    fout.close();  
    remove("teacher.dat");
    rename("temp.dat","teacher.dat");
    }
    cout<<"for 1";
    cin>>e;
    if(e==1)
        admin1.teacher_menu();
    else
        exit(0);
}
void school::disp_teach()
{ 
    int q;
    cout<<"_______tttteeeaaacccchhheeeeff press 0 for back chillx\n";
    ifstream fin("teacher.dat",ios::in |ios::binary);
    tea t;
    cout << "\n\n===== TEACHERS RECORD LIST \n\n";
    cout << "Teacher ID   Name   Salary   Phone No   Class Teaching email  Subject\n"; 
    while(fin.read((char*)&t,sizeof(t)))
    {
        cout<<t.id<<"   "<<t.name<<"   "<< t.salary<<"   "<< t.add<<"   "<<t.phone<<"  " << t.sub<<t.email<< endl;
    fin.close();
    }
    cout<<"press 0 for exit 9 fro previous menu";
    cin>>q;
    if(q==0)
    {
        admin1.teacher_menu();

    }
    else if(q==9)
        admin1.m_menu();
    else
        exit(0);
}

//****************************************** */

  void school::updateinfo()
  {
    int w,e;
    cout<<"1 for student update\n 2 for teacher update\n";
    cin>>w;
    if(w==1)
    {
    int swami,found=0;
    cout<<" enter roll no to update student info ";
    cin>>swami;
    char x;
    ifstream fin("student.dat",ios::in | ios::binary);
    ofstream fout("temp.dat",ios::out | ios::binary);
    stuinfo s;
    tea t;
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(s.roll==swami)
        {
            found=1;
            cout<<" enter new hindi ";
            cin>>s.hindi;
            cout<<" enter new eng no ";
            cin>>s.eng;
            cout<<" enter new sci teach ";
            cin>>s.sci;
        }
        else
        fout.write((char*)&s,sizeof(s));       
    }
    fin.close();
    fout.close();
    remove("student.dat");
    rename("temp.dat","student.dat");
    cout<<"exit 0 for main admin and 1 for admin main menu";
    cin>>e;    
}
  else if(w==2)
  {
    int swami,found=0;
    cout<<" enter id to update ";
    cin>>swami;
    ifstream fin("teacher.dat",ios::in | ios::binary);
    ofstream fout("temp.dat",ios::out | ios::binary);
    tea t;
    while(fin.read((char*)&t,sizeof(t)))
    {
        if(t.id==swami)
        {
            found=1;
            cout<<" enter new name ";
            cin>>t.name;
             cout<<" enter new adress ";
             cin>>t.add;
             cout<<" enter new phone no ";
             cin>>t.phone;
             cout<<" enter new email id ";
             cin>>t.email;
             cout<<"age new:";
             cin>>t.age;
             cout<<"salary new:";
             cin>>t.salary;
            fout.write((char*)&t,sizeof(t));
        }
        else
           fout.write((char*)&t,sizeof(t));
    }
    fout.close();
    fin.close();
    remove("teacher.dat");
    rename("temp.dat","teacher.dat");
}
    else if(w==3)
        admin1.admin_menu();
    else
        exit(0);
}
//*********************************** */
void school::admin_menu()
{
    int c;
    cout<<"\n\n1. Add Student/ Teacher\n";
    cout<<"2. Disp Student/ Teacher\n";
    cout<<"3. Update Student/ Teacher\n";
    cout<<"4. Find Student/ Teacher\n";
    cout<<"5. Delete Student/ Teacher\n";
    cout<<"6. Back\n";
    cout<<"Enter Choice (0 for Exit : )\n";
    cin>>c;
    do{
        if(c==1)
        admin1.addinfo();
         else if(c==2)
         admin1.display_admin();
        else if(c==3)
        admin1.updateinfo();
        else if(c==4)
        admin1.findinfo();  
        else if(c==5)
        admin1.deleteinfo();
        else if(c==6)
        admin1.m_menu();
        else 
          exit(0); 
    }
   while(c!=0);
}
   void school::addinfo()
{
    int t=0,p;
    cout<<"heelo pls\n\n"<<"choose 1. student\n"<<"choice 2.teacher nd last exit\n";
    cin>>t;
    if(t==1)
    {
     fstream fout("student.dat",ios::app|ios::binary);
            stuinfo s;
            fout.seekp(0,ios::end);
            cout<<"enter student name:";
            cin>>s.name;
            cout<<"enter  roll no:";
            cin>>s.roll;
            cout<<"enter age:";
            cin>>s.age;
            cout<<"enter adress:";
            cin>>s.add;
            cout<<"enter phone no:";
            cin>>s.phone;
            cout<<"enter email id:";
            cin>>s.email;
            cout<<"enter hindi marks:";
            cin>>s.hindi;
            cout<<"enter english marks";
            cin>>s.eng;
            cout<<"enter science marks:";
            cin>>s.sci;
            fout.write((char*)&s,sizeof(s));
            cout<<"do it";
            fout.close();
    }
    else if(t==2)
    {
            fstream fout("teacher.dat",ios::app|ios::binary);
            tea t;
            if(!fout)cout<<"file not found";
            fflush;
            fout.seekp(0,ios::end);
            cin.ignore();
            cout<<"enter teacher name:";cin.getline(t.name,20);
            cout<<"enter teacher id:";cin>>t.id;
            cout<<"enter age:";cin>>t.age;
            cout<<"enter adress:";
            cin>>t.add;
            cout<<"enter phone no:";
            cin>>t.phone;
            cout<<"enter email id:";
            cin>>t.email;
            cout<<"enter subject assigned:";
            cin>>t.sub;
            cout<<"enter salary:";
            cin>>t.salary;
            cout<<"enter class teaching:";
            cin>>t.clss;
            fout.write((char*)&t,sizeof(t));
            cout<<"do it";
            fout.close(); 
    }
    else if(t==3)
    {
        admin1.admin_menu();
    }
    else
        exit(0);
}

void school::updateinfo_student()
{
    int swami;
    int e;
    cout<<" enter roll no to update student info ";
    cin>>swami;
    int found=0;
    ifstream fin("student.dat",ios::in | ios::binary);
    ofstream fout("temp.dat",ios::out | ios::binary);
    stuinfo s;
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(s.roll==swami)
        {
            found=1;
            cout<<" enter new hindi ";
            cin>>s.hindi;
            cout<<" enter new eng no ";
            cin>>s.eng;
            cout<<" enter new sci teach ";
            cin>>s.sci;
            fout.write((char*)&s,sizeof(s));
        }
    else{
        fout.write((char*)&s,sizeof(s));
        admin1.teacher_menu();
    }
    fin.close();
    fout.close();
    remove("student.dat");
    rename("temp.dat","student.dat");
}
cout<<"//exit 1 ......";
if(e==1)
{
    admin1.teacher_menu();
}
else
{
exit(0);
}
}

    
//************************************************************** */
void school::deleteinfo()
{
    int o;
    cout<<"choice 1. delete student\n choice 2. delete teacher\n ";
    cin>>o;
    if(o==1)
    {
        int find = 0;
        int swami;
        cout<< " put delete our machine do rest of it and press 3 for x ";
        cin>>swami;
        ifstream fin("student.dat",ios::in | ios::binary);
        ofstream fout("temt.dat",ios::out | ios::binary);
        stuinfo s;
        while(fin.read((char*)&s,sizeof(s)))
        {
            if(s.roll!=swami)
                fout.write((char*)&s,sizeof(s));
        }
        fin.close();
        fout.close();
        remove("student.dat");
        rename("temt.dat","student.dat");
    }   
    else if(o==2)
    {
        int findi=0;
        int swami;
        cout<< " put delete our machine do rest of it ";
        cin>>swami;
        tea t;
        ifstream fin("teacher.dat",ios::in | ios::binary);
        ofstream fout("temt.dat",ios::out | ios::binary);
        while(fin.read((char*)&t,sizeof(t)))
        {
            if(t.id!=swami)
                fout.write((char*)&t,sizeof(t));
        }
        fin.close();
        fout.close();         
        remove("teacher.dat");
        rename("temt.dat","teacher.dat");

    }
    else if(o==3)
    {
        admin1.admin_menu();
    }
    else
    {
        exit(0);

    }
}
//************************************************************************** */
  void school::findinfo()
  {
    int p;
    cout<<"c 1.student\n 2. teacher\n and 3\n";
    cin>>p;
    if(p==1)
    {
        int swami,found=0;
        cout<<" enter id to find ";
        cin>>swami;
        ifstream fin("student.dat",ios::in | ios::binary);
        stuinfo s;
        while(fin.read((char*)&s,sizeof(s)))
        {
            if(s.roll==swami)
            {
                found=1;
                cout<<" student roll no "<<s.roll<<endl;
                cout<<" student name "<<s.name<<endl;
                cout<<" student hindi marks "<<s.hindi<<endl;
                cout<<" student eng marks "<<s.eng<<endl;
                cout<<" student sci marks "<<s.sci<<endl;
                cout<<" student age\n ";
                cout<<" s.age<<endl ";
                cout<<" student adress "<<s.add<<endl;
                cout<<" mission accomplished ";
                break;
            }
        }
        if(found==0)
            cout<<" pls revert";
        fin.close();
    }
    else if(p==1)
    {
        int swami,found=0;
        cout<<" enter id to find ";
        cin>>swami;
        ifstream fin("teacherinfo.dat",ios::in | ios::binary);
         tea t;
        while(fin.read((char*)&t,sizeof(t)))
        {
            if(t.id==swami)
            {
                found=1;
                cout<<" teacher id "<<t.id<<endl;
                cout<<" teacher name "<<t.name<<endl;
                cout<<" teacher salary "<<t.salary<<endl;
                cout<<" teacher address "<<t.add<<endl;
                cout<<" teacher phone no "<<t.phone<<endl;
                cout<<" teacher subject "<<t.sub<<endl;
                cout<<" mission accomplished ";
            }
        }
        if(found==0)
            cout<<" pls revert";
        fin.close();
    }
    else if(p==3)
    {
        admin1.admin_menu();
    }
    else 
    {
        exit(0);
    }
    
 }

 void school::disp_stui()
 {
    int o;
    stuinfo s;
    ifstream fin("student.dat",ios::in|ios::binary);
    
    while(fin.read((char*)&s,sizeof(s)))
    {
            cout<<"student menu\n";
            cout<<" student roll no "<<s.roll<<endl;
            cout<<" student name "<<s.name<<endl;
            cout<<" student hindi marks "<<s.hindi<<endl;
            cout<<" student eng marks "<<s.eng<<endl;
            cout<<" student sci marks "<<s.sci<<endl;
            cout<<" student age ";
            cout<<s.age<<endl;
            cout<<" student adress "<<s.add<<endl;
            cout<<" student phone no "<<s.phone<<endl;
            cout<<" student email id "<<s.email<<endl;
        cout<<" mission accomplished in...... /n ";
        fin.close();
    }

    cout<<"press zero for exit 1 for previous menu";
    cin>>o;
    if(o==1)
    {
        admin1.student_menu();
    }
    else if(o==2)
    {
        admin1.m_menu();
    }
    else{
        exit(0);
    }

        }
 /////************************************************ */
   void school::display_admin()
   {
      int o;
      cout<<"\n\ndo know one for student 2 foee\n ad 2 for : \n\n";
      cin>>o;
       stuinfo s;
      if(o==1)
      {
     ifstream fin("student.dat",ios::in | ios::binary);
        while(fin.read((char*)&s,sizeof(s)))
        {
            cout<<"student menu\n";
            cout<<" student roll no "<<s.roll<<endl;
            cout<<" student name "<<s.name<<endl;
            cout<<" student hindi marks "<<s.hindi<<endl;
            cout<<" student eng marks "<<s.eng<<endl;
            cout<<" student sci marks "<<s.sci<<endl;
            cout<<" student age ";
            cout<<s.age<<endl;
            cout<<" student adress "<<s.add<<endl;
            cout<<" student phone no "<<s.phone<<endl;
            cout<<" student email id "<<s.email<<endl;
        cout<<" mission accomplished in...... /n ";
        } 
        fin.close();
    }
    else if(o==2)
    {
    tea t;
    ifstream fin("teacher.dat", ios::in | ios::binary);
    cout << "\n\n===== TEACHERS RECORD LIST \n\n";
    cout << "Teacher ID   Name   Salary   Phone No   Class Teachingfreg email  Subject\n"; 
    while (fin.read((char*)&t, sizeof(t)))
        cout<<t.id<<"               "<<t.name<<"          "<< t.salary<<"          "<< t.add<<"            "<<t.phone<<"        " << t.sub<<"          "<<t.email<< endl;
    fin.close();
}
else if(o==3)
{
    admin1.m_menu();
}
else
{exit(0);}
}
//********************************************/
void school::student_menu()
{
    int c;
    cout<<"1. Disp Student\n";
    cout<<"2. Update Student\n";
    cout<<"3. Back\n";
    cout<<"enter your choice\n";
    cin>>c;
    do{
        if(c==1)
        admin1.disp_stui();
        else if(c==2)
        admin1.onstup();
        else if(c==3) 
          admin1.m_menu();
          else
           exit(0); 
    }
    while(c!=3);
}
//******************************************* */
void school::onstup()
{
    int swami,w,found=0;
    cout<<" enter roll no to update student info ";
    cin>>swami;
    char x;
    ifstream fin("student.dat",ios::in | ios::binary);
    ofstream fout("temp.dat",ios::out | ios::binary);
    stuinfo s;
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(s.roll==swami)
        {
            found=1;
            cout<<"enter name:";
            cin>>s.name;
            cout<<"enter age:";
            cin>>s.age;
            cout<<"enter address:";
            cin>>s.add;
            cout<<"enter phone no:";
            cin>>s.phone;
            cout<<"enter email id:";
            cin>>s.email;
            fout.write((char*)&s,sizeof(s));
        }

      else
    {
        fout.write((char*)&s,sizeof(s));
    }
    
    fin.close();
    fout.close();
    remove("student.dat");
    rename("temp.dat","student.dat");
}
    cout<<"press 0 for exit and 1 main previous";
    cin>>w;
    if(w==0)
    {
        admin1.m_menu();
    }
    else if(w==1)
    {
        admin1.admin_menu();
    }

    else{
        exit(0);
    }

}
/*************************************/

void school::sign_up()
{
    log log1;
    int w;
    ofstream fout("login.dat",ios::out|ios::binary);
    cout<<"enter your user(name):";
    cin>>log1.username;
    cout<<"enter your key";
    cin>>log1.password; 
    fout.write(reinterpret_cast<char*>(&log1),sizeof(log1)); 
    fout.close();
    cout<<"Account  has been created duck";
    sign_in();
}
 void school::sign_in()
 {
    cout<<"\n\n_____________ welcome to school mangement systum be sensitive ________\n";
    log log1;
    int found=0;
    ifstream fin("login.dat",ios::in|ios::binary);
    char userr[10];
    char passwordd[10];
  

    cout<<"\nenter your user(name) :";
    cin>>userr;
    cout<<"\nenter your key :";
    cin>>passwordd;
    while(fin.read(reinterpret_cast<char*>(&log1),sizeof(log1)))
    {
        cout<<log1.password;
    if(strcmp(log1.username,userr)==0 && strcmp(log1.password,passwordd)==0)
    {
        found=1;
        cout<<"\nyou are logged in successfully\n";
        admin1.m_menu();
        break;
    }
    }
    if(found==1)   
    {
        cout<<"get out";       
    }
    fin.close();


 }

 //******************************************* */
 void school::m_menu()
 {
    int c;
    cout<<"\n\n1. Admin\n";
    cout<<"2. Student\n";
    cout<<"3. Teacher\n";
    cout<<"exit \n0";
    cout<<"Enter Choice (0 For Exit)\n";
    cin>>c;
    do{
        if(c==1)
            admin1.admin_menu();
        else if(c==2)
            admin1.student_menu();
        else if(c==3)
            admin1.teacher_menu();
        else if(c==0)
         admin1.menu();
        else
          exit(0); 
    }
    while(c!=0);
 }


 //////////////*********/

 void school::menu()
 {
    int c;
    cout<<"1. Sign In\n";
    cout<<"2. Sign Up\n";
    cout<<"Enter Choice (0 For Exit)\n";
    cin>>c;
    do{
        if(c==1)
            admin1.sign_in();
        else if(c==2)
            admin1.sign_up();
        else if(c==3)
        admin1.menu();
        else
          exit(0); 
    }
    while(c!=0);
 }
 
//*******************************************/
 main()
{
    system("CLS"); 
     admin1.menu();
    return 0;  
    }



