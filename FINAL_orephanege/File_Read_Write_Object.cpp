#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class index
{	
  public:
		int id;
		int sequence;
  public:
		//---------------------------------------------------------
		void set(int i, int s)
		{id=i; sequence=s;}
		//---------------------------------------------------------
		void show()
		{cout<<"\n ID= "<<id<<" - Index= "<<sequence;}
		//---------------------------------------------------------
		int write_file(ostream& ofs,index& ind)
        {
		 ofs.seekp(0, ios::end);
		 int pos=ofs.tellp();
	  	 cout<<"\n Path:="<<pos<<"\n";
         if(ofs.write((char*)&ind,sizeof(ind)))
          { return pos; }
         else
          { return -1;}
        }
     //---------------------------------------------------------
       bool read_file(istream& ifs,index& ind)
        {
		// cout<<"Path="<<ifs.tellg()<<"\n";
         if(ifs.read((char*)&ind,sizeof(ind)))
          { return true; }
         else
          { return false;}
        }
};
class student
 {
  public:
       int  id;
       char name[10];
  public:
       student()
        { id=0;}
       void enter_data()
	   {
			cout<<"\n Student ID=";   cin>>id;
			cout<<" Student Name: ";  cin>>name;
	   }
       void display()
	   {
		    cout<<"\n -----------------------------------\n"
				<<"  ID="<<id <<" \t name:\ "<<name;
	   }
     //----------------------------------------------------------
       int write_file(ostream& ofs,student& std)
        {
		ofs.seekp(0, ios::end);
		 int pos=ofs.tellp();
	  	 cout<<"\n Path:="<<pos<<"\n";
         if(ofs.write((char*)&std,sizeof(std)))
          { return pos; }
         else
          { return -1;}
        }
     //---------------------------------------------------------
       bool read_file(istream& ifs,student& std)
        {
		 //cout<<"Path="<<ifs.tellg()<<"\n";
         if(ifs.read((char*)&std,sizeof(std)))
          { return true; }
         else
          { return false;}
        }
       bool read_record(istream& ifs,student& std,int seek)
        {
		
		 ifs.seekg(seek);
         if(ifs.read((char*)&std,sizeof(std)))
          { cout<<"\n -> Record:"; std.display(); return true; }
         else
          { return false;}
        } 
};

//============================================< void main >

void main()
 {
 student std;  index ind; int n;
  
 //---------------------------------------------------------
  ofstream ofs,ofs_index;     
  ofs.open("D:\\File organization\\File_1.txt",ios::app);
  ofs_index.open("D:\\File organization\\Index_1.txt",ios::app);
  
  cout<<" \n Please enter # students=";  cin>>n;
  
   int xx;
   int cf=sizeof(std);
  for(int j=0;j<n;j++)
    {
     cout<<" \n ________________Student ("<<(j+1)<<"):________________\n";
     std.enter_data();
	 
	 xx=ofs.tellp();

	 int r=std.write_file(ofs,std);
     if(r!=-1)
     {
		 
		 xx=ofs.tellp();
		 xx-=cf;
		 ind.set(std.id,(xx));
		 r=ind.write_file(ofs_index,ind);
		 if(r!=-1)
			 cout<<" \n done\n";
		 else 
		     cout<<" \n Error.\n";
	 }
     else
      { cout<<" \n Error.\n";}
    }

  ofs.close();                       
  ofs_index.close();
  
  //--------------------------------------------------------------------------

  char name[20]; int id=0;
  ifstream ifs,ifs_index;      // define object for witing.
  ifs.open("d:\\File organization\\File_1.txt",ios::out);
  ifs_index.open("d:\\File organization\\Index_1.txt",ios::out);
  //ifs.seekg(sizeof(std));

  //n=1;
  cout<<"\n --------------------<Reading from file>----------------------\n";
 
  
  int t; cout<<"\n enter target id to search="; cin>>t;
  ifs_index.seekg(0,ios::beg);
  while(!ifs_index.eof())//for(int i=0; i<n;i++)//
  {
	 int x= ind.read_file(ifs_index,ind);
	 int cc;
	
	 if(ind.id==t)
	 { 
		 cout<<"\n Found ";
		 std.read_record(ifs,std,ind.sequence);
	 }
  }
  //---------------- all students ------------
  cout<<"\n All Data --------------------\n";
  ifs.seekg(0,ios::beg);
   while(!ifs.eof())//for(int j=0;j<n;j++)
    {
    if(std.read_file(ifs,std))
     {
     std.display();
     }
    }


  cout<<"\n All Data --------------------\n";
  ifs_index.close();
  ifs_index.open("d:\\File organization\\Index_1.txt",ios::out);
 
   while(!ifs_index.eof())//for(int j=0;j<n;j++)
    {
    if(ind.read_file(ifs_index,ind))
     {
     ind.show();
     }
    }
 ifs.close();
 ifs_index.close();


////----------------------------------------------------------------

 getch();
 }