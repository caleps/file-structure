#include<iostream>
#include<conio.h>
#include <string>
#include <windows.h>
#include<fstream>
#include<vector>
using namespace std;

//============================================<child>============================
class index
{
public:
	int id;
	int position;
public:
	//---------------------------------------------------------
	void set(int i, int p)
	{
		id = i; position = p;
	}
	//---------------------------------------------------------
	void show()
	{
		cout << "\n ID= " << id << " - Index= " << position;
	}
	//---------------------------------------------------------
	int write_file(ostream& ofs, index& ind)
	{
		ofs.seekp(0, ios::end);
		int pos = ofs.tellp();
		cout << "\n index path:=" << pos << "\n";
		if (ofs.write((char*)&ind, sizeof(ind)))
		{
			return pos;
		}
		else
		{
			return -1;
		}
	}
	//---------------------------------------------------------
	bool read_file(istream& ifs, index& ind)
	{
		// cout<<"Path="<<ifs.tellg()<<"\n";
		if (ifs.read((char*)&ind, sizeof(ind)))
		{
			return true;
		}
		else
		{

			return false;
		}
	}
	void Delete(fstream& f, index ind, int ID)
	{
		ofstream tmp("tmp.txt", ios::out);
		f.read((char*)&ind, sizeof(ind));
		while (!f.eof())
		{
			if (ind.id != ID)
			{
				tmp.write((char *)&ind, sizeof(ind));
			}
			f.read((char*)&ind, sizeof(ind));
		}
		tmp.close();
		f.close();
		remove("Index_1.txt");
		rename("tmp.txt", "Index_1.txt");
	}
};

class child
{
public:
	int  id;
	char fname[10];
	char lname[10];
	int age;
	char hoppy[10];
	int room_id;
	int enter_date;

public:
	child()
	{
		id = 0;
	}
	void enter_data()
	{
		//cout << "\n";
		cout << "enter id :"; cin >> id;
		cout << "\n";
		cout << "enter first name :"; cin >> fname;
		cout << "\n";
		cout << "enter last name :"; cin >> lname;
		cout << "\n";
		cout << "enter age :"; cin >> age;
		cout << "\n";
		cout << "enter hoppy :"; cin >> hoppy;
		cout << "\n";
		cout << "enter room id :"; cin >> room_id;
		cout << "\n";
		cout << "enter date of entering :"; cin >> enter_date;
		cout << "\n";
	}
	void display()
	{
		cout << "\n -----------------------------------\n";
		cout << id << " " << fname << " " << lname << " " << age << " " << hoppy << " " << room_id << " " << enter_date << endl;
	}
	//----------------------------------------------------------
	int write_file(ostream& ofs, child& ch)
	{
		ofs.seekp(0, ios::end);
		int pos = ofs.tellp();
		cout << "\n child Path:=" << pos << "\n";
		if (ofs.write((char*)&ch, sizeof(ch)))
		{
			return pos;
		}
		else
		{
			return -1;
		}
	}
	//---------------------------------------------------------
	bool read_file(istream& ifs, child& ch)
	{
		//cout<<"Path="<<ifs.tellg()<<"\n";
		if (ifs.read((char*)&ch, sizeof(child)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool read_record(istream& ifs, child& ch, int seek)
	{

		ifs.seekg(seek);
		if (ifs.read((char*)&ch, sizeof(ch)))
		{
			cout << "\n -> Record:"; ch.display();
			return true;
		}
		else
		{
			return false;
		}
	}


	void Delete(fstream& f, child ch, int ID)
	{
		ofstream tmp("tmp.txt", ios::out);
		f.read((char*)&ch, sizeof(ch));
		while (!f.eof())
		{
			if (ch.id != ID)
			{
				tmp.write((char *)&ch, sizeof(ch));
			}
			f.read((char*)&ch, sizeof(ch));
		}
		tmp.close();
		f.close();
		remove("File_1.txt");
		rename("tmp.txt", "File_1.txt");
	}
};

	///////////////////////////////////////////////////

	//============================================<donner>============================
	class index_donners
	{
	public:
		int id;
		int sequence;
	public:
		//---------------------------------------------------------
		void set(int i, int s)
		{
			id = i; sequence = s;
		}
		//---------------------------------------------------------
		void show()
		{
			cout << "\n ID= " << id << " - Index= " << sequence;
		}
		//---------------------------------------------------------
		int write_file(ostream& ofs, index_donners& dd)
		{
			ofs.seekp(0, ios::end);
			int pos = ofs.tellp();
			cout << "\n Path:=" << pos << "\n";
			if (ofs.write((char*)&dd, sizeof(dd)))
			{
				return pos;
			}
			else
			{
				return -1;
			}
		}
		//---------------------------------------------------------
		bool read_file(istream& ifs, index_donners& dd)
		{
			// cout<<"Path="<<ifs.tellg()<<"\n";
			if (ifs.read((char*)&dd, sizeof(dd)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void Delete(fstream& f, index_donners& dd, int ID)
		{
			ofstream tmp("tmp.txt", ios::out);
			f.read((char*)&dd, sizeof(dd));
			while (!f.eof())
			{
				if (dd.id != ID)
				{
					tmp.write((char *)&dd, sizeof(dd));
				}
				f.read((char*)&dd, sizeof(dd));
			}
			tmp.close();
			f.close();
			remove("Index_d.txt");
			rename("tmp.txt", "Index_d.txt");
		}
	};
	class donners
	{
	public:
		int  id;
		char name[10];
		int money;
	public:
		donners()
		{
			id = 0;
			money = 0;
		}
		void enter_data()
		{
			cout << "\n donner ID=";   cin >> id;
			cout << " donner Name: ";  cin >> name;
			cout << " donner money: ";  cin >> money;
		}
		void display()
		{
			cout << "\n -----------------------------------\n"
				<< "  ID=" << id << " \t name:\ " << name << " \t money:\ " << money;
		}
		//----------------------------------------------------------
		int write_file(ostream& ofs, donners& d)
		{
			ofs.seekp(0, ios::end);
			int pos = ofs.tellp();
			cout << "\n Path:=" << pos << "\n";
			if (ofs.write((char*)&d, sizeof(d)))
			{
				return pos;
			}
			else
			{
				return -1;
			}
		}
		//---------------------------------------------------------
		bool read_file(istream& ifs, donners& d)
		{
			//cout<<"Path="<<ifs.tellg()<<"\n";
			if (ifs.read((char*)&d, sizeof(d)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool read_record(istream& ifs, donners& d, int seek)
		{

			ifs.seekg(seek);
			if (ifs.read((char*)&d, sizeof(d)))
			{
				cout << "\n -> Record:"; d.display(); return true;
			}
			else
			{
				return false;
			}
		}
		void Delete(fstream& f, donners d, int ID)
		{
			ofstream tmp("tmp.txt", ios::out);
			f.read((char*)&d, sizeof(d));
			while (!f.eof())
			{
				if (d.id != ID)
				{
					tmp.write((char *)&d, sizeof(d));
				}
				f.read((char*)&d, sizeof(d));
			}
			tmp.close();
			f.close();
			remove("File_d.txt");
			rename("tmp.txt", "File_d.txt");
		}

	};
	//================================================<moderators>======================
	class index_moderator {
	public:
		int id;
		int sequence;
	public:
		//---------------------------------------------------------
		void set(int i, int s)
		{
			id = i; sequence = s;
		}
		//---------------------------------------------------------
		void show()
		{
			cout << "\n ID= " << id << " - Index= " << sequence;
		}
		//---------------------------------------------------------
		int write_file(ostream& ofs, index_moderator& md)
		{
			ofs.seekp(0, ios::end);
			int pos = ofs.tellp();
			cout << "\n Path:=" << pos << "\n";
			if (ofs.write((char*)&md, sizeof(md)))
			{
				return pos;
			}
			else
			{
				return -1;
			}
		}
		//---------------------------------------------------------
		bool read_file(istream& ifs, index_moderator& md)
		{
			// cout<<"Path="<<ifs.tellg()<<"\n";
			if (ifs.read((char*)&md, sizeof(md)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void Delete(fstream& f, index_moderator& md, int ID)
		{
			ofstream tmp("tmp.txt", ios::out);
			f.read((char*)&md, sizeof(md));
			while (!f.eof())
			{
				if (md.id != ID)
				{
					tmp.write((char *)&md, sizeof(md));
				}
				f.read((char*)&md, sizeof(md));
			}
			tmp.close();
			f.close();
			remove("Index_m.txt");
			rename("tmp.txt", "Index_m.txt");
		}
	};
	class moderator
	{
	public:
		int id;
		char fname[10];
		char lname[10];
		int phone;
		char specialist[10];
		int shift;

	public:
		moderator()
		{
			id = 0;
			phone = 0;
			shift = 0;
		}
		void enter_data()
		{
			cout << "\n Moderator ID: ";   cin >> id;
			cout << " Moderator first name: ";  cin >> fname;
			cout << " Moderator last name: ";  cin >> lname;
			cout << " Moderator phone: ";  cin >> phone;
			cout << " Moderator specialist : ";  cin >> specialist;
			cout << " Moderator shift : ";  cin >> shift;

		}
		void display()
		{
			cout << "\n -----------------------------------\n"
				<< "  ID=" << id << " \t first name:\ " << fname << " \t last name:\ " << lname << " \t phone:\ " << phone << " \t specialist:\ " << specialist << " \t shift:\ " << shift;
		}
		//----------------------------------------------------------
		int write_file(ostream& ofs, moderator& mod)
		{
			ofs.seekp(0, ios::end);
			int pos = ofs.tellp();
			cout << "\n Path:=" << pos << "\n";
			if (ofs.write((char*)&mod, sizeof(mod)))
			{
				return pos;
			}
			else
			{
				return -1;
			}
		}
		//---------------------------------------------------------
		bool read_file(istream& ifs, moderator& mod)
		{
			//cout<<"Path="<<ifs.tellg()<<"\n";
			if (ifs.read((char*)&mod, sizeof(mod)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool read_record(istream& ifs, moderator& mod, int seek)
		{

			ifs.seekg(seek);
			if (ifs.read((char*)&mod, sizeof(mod)))
			{
				cout << "\n -> Record:"; mod.display(); return true;
			}
			else
			{
				return false;
			}
		}
		void Delete(fstream& f, moderator m, int ID)
		{
			ofstream tmp("tmp.txt", ios::out);
			f.read((char*)&m, sizeof(m));
			while (!f.eof())
			{
				if (m.id != ID)
				{
					tmp.write((char *)&m, sizeof(m));
				}
				f.read((char*)&m, sizeof(m));
			}
			tmp.close();
			f.close();
			remove("File_m.txt");
			rename("tmp.txt", "File_m.txt");
		}
	};
	//-----------------------Child------------------
	bool Update(int ID, fstream& f, fstream& i, child ch, index ind)
	{
		//fstream f1, f2;
		i.open("Index_1.txt", ios::in | ios::out);
		f.open("File_1.txt", ios::in | ios::out);
		bool check = false;
		index in;

		while (i.read((char*)&in, sizeof(index)))
		{
			long pos = i.tellg();
			if (in.id == ID)
			{

				int value = in.position;
				f.seekg(value);
				f.read((char*)&ch, sizeof(child));
				long pos1 = f.tellg();
				if (ch.id != -1)
				{
					f.seekp(pos1 - sizeof(ch));
					ch.enter_data();
					f.write((char*)&ch, sizeof(child));

					i.seekp(pos - sizeof(in));
					ind.id = ch.id;
					ind.position = in.position;
					i.write((char*)&ind, sizeof(index));
					check = true;
					break;
				}
			}
		}
		f.close();
		i.close();
		return check;
	}
	//-------------------------------Donner---------------------------------
	bool Update(int ID, fstream& f, fstream& i, donners ch, index_donners ind)
	{
		//fstream f1, f2;
		i.open("Index_d.txt", ios::in | ios::out);
		f.open("File_d.txt", ios::in | ios::out);
		bool check = false;
		index_donners in;

		while (i.read((char*)&in, sizeof(index_donners)))
		{
			long pos = i.tellg();
			if (in.id == ID)
			{

				int value = in.sequence;
				f.seekg(value);
				f.read((char*)&ch, sizeof(donners));
				long pos1 = f.tellg();
				if (ch.id != -1)
				{
					f.seekp(pos1 - sizeof(ch));
					ch.enter_data();
					f.write((char*)&ch, sizeof(donners));

					i.seekp(pos - sizeof(in));
					ind.id = ch.id;
					ind.sequence = in.sequence;
					i.write((char*)&ind, sizeof(index_donners));
					check = true;
					break;
				}
			}
		}
		f.close();
		i.close();
		return check;
	}

	//---------------------------------Moderator--------------------------
	bool Update(int ID, fstream& f, fstream& i, moderator ch, index_moderator ind)
	{
		//fstream f1, f2;
		i.open("Index_m.txt", ios::in | ios::out);
		f.open("File_m.txt", ios::in | ios::out);
		bool check = false;
		index_moderator in;

		while (i.read((char*)&in, sizeof(index_moderator)))
		{
			long pos = i.tellg();
			if (in.id == ID)
			{

				int value = in.sequence;
				f.seekg(value);
				f.read((char*)&ch, sizeof(moderator));
				long pos1 = f.tellg();
				if (ch.id != -1)
				{
					f.seekp(pos1 - sizeof(ch));
					ch.enter_data();
					f.write((char*)&ch, sizeof(moderator));

					i.seekp(pos - sizeof(in));
					ind.id = ch.id;
					ind.sequence = in.sequence;
					i.write((char*)&ind, sizeof(index_moderator));
					check = true;
					break;
				}
			}
		}
		f.close();
		i.close();
		return check;
	}


	//============================================< void main >==========================

	void main()
	{
		child ch;  index ind;
		donners d; index_donners dd;
		char ss;
		int n; int op;
	k270:system("cls");
		system("color f1");
		cout << "\n\n\t\t\t\t\t Welcome to our orphanage \n\n\n";
		cout << "\n\t\t\t\t1- Childrens \t2- Moderators\t3- Donners\n\n\n";
		cout << "\n\t\t\tYour choice is = "; cin >> op;
		cout << "\n\n\n\n";
		//cin >> op;


		//system("cls");
		switch (op)
		{
		fch:case 1://////child

		{
			int opp;

			system("cls");
			system("color 75");
			cout << "\t\t\t\t--------------------------<CHILD>----------------------\n\n";
			cout << "\t\t1-Enter new child\t2-Display all\t3-Search\t4-Delete\t5-Update\n";
			cout << "\t\t choice ="; cin >> opp;
			fstream ofs, ofs_index;
			if (opp == 1) {
				ofs.open("File_1.txt", ios::app);
				ofs_index.open("Index_1.txt", ios::app);

				cout << " \n Please enter number of children=";  cin >> n;

				int xx;
				int cf = sizeof(ch);
				for (int j = 0; j < n; j++)
				{
					cout << " \n ________________Child (" << (j + 1) << "):________________\n";
					ch.enter_data();

					xx = ofs.tellp();

					int r = ch.write_file(ofs, ch);
					if (r != -1)
					{

						xx = ofs.tellp();
						xx -= cf;
						ind.set(ch.id, (xx));
						r = ind.write_file(ofs_index, ind);
						if (r != -1)
							cout << " \n done\n";
						else
							cout << " \n Error.\n";
					}
					else
					{
						cout << " \n Error.\n";
					}

				}
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss != '0')
				{
					goto fch;
					break;
				}
				else if (ss == '0')
					goto k270;

				ofs.close();
				ofs_index.close();

			}
			//////////////////////////////////////////////////////////////////////////////
			else if (opp == 2) {
				ifstream ifs, ifs_index;      // define object for reading.
				ifs.open("File_1.txt", ios::in);
				ifs_index.open("Index_1.txt", ios::in);
				ifs.seekg(0, ios::beg);
				while (!ifs.eof())
				{
					if (ch.read_file(ifs, ch))
					{
						ch.display();
					}
				}


				cout << "\n All Data --------------------\n";
				ifs_index.close();
				ifs_index.open("Index_1.txt", ios::out);

				while (!ifs_index.eof())
				{
					if (ind.read_file(ifs_index, ind))
					{
						ind.show();
					}
				}
				ifs.close();
				ifs_index.close();
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fch;

			}
			/////////////////////////////////////////////
			else if (opp == 3)
			{
				ifstream ifs, ifs_index;      // define object for reading.
				ifs.open("File_1.txt", ios::in);
				ifs_index.open("Index_1.txt", ios::in);
				int t; cout << "\n enter target id to search="; cin >> t;
				ifs_index.seekg(0, ios::beg);
				int cc = 0;
				while (!ifs_index.eof())
				{
					//
					int x = ind.read_file(ifs_index, ind);


					if (ind.id == t)
					{
						cout << "\n Found ";
						ch.read_record(ifs, ch, ind.position);
					}
					//else	cout << "Not Found";
					else cc++;
				}
				if (cc != 0)cout << "Not Found";
				ifs.close();
				ifs_index.close();
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else
					_getch();
				goto fch;



			}
			else if (opp == 4)
			{
				fstream ifs, ifs_index;      // define object for reading.
				ifs.open("File_1.txt", ios::in);
				ifs_index.open("Index_1.txt", ios::in);
				int t; cout << "\n enter target id to delete="; cin >> t;

				ifs_index.seekg(0, ios::beg);
				int cc = 0;
				while (!ifs_index.eof())
				{
					//
					int x = ind.read_file(ifs_index, ind);


					if (ind.id == t)
					{
						ifs_index.seekg(0, ios::beg);
						ifs.seekg(0, ios::beg);
						ch.Delete(ifs, ch, t);
						ind.Delete(ifs_index, ind, t);
						cout << "\n Done\n";
						cc++;
					}

					
				}
				if (cc == 0)cout << "Not Found";
				ifs.close();
				ifs_index.close();
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fch;

			}

			else if (opp == 5)
			{
				fstream ifs, ifs_index;      // define object for reading.
				int t; cout << "\n enter target id to update="; cin >> t;
				Update(t, ifs, ifs_index, ch, ind);
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fch;


			}






		} break;


		case 2:///////moderators
		{
			moderator m; index_moderator md;
			int opp;
		fm: system("cls");
			system("color 7c");
			cout << "\t\t\t\t--------------------------<Moderator>----------------------\n\n";
			cout << "\t\t1-Enter new moderator\t2-Display all\t3-Search\t4-Delete\t5-Update\n";
			cout << "\t\t choice ="; cin >> opp;
			fstream ofs, ofs_index;
			if (opp == 1) {
				ofs.open("File_m.txt", ios::app);
				ofs_index.open("Index_m.txt", ios::app);

				cout << " \n Please enter number of moderators=";  cin >> n;

				int xx;
				int cf = sizeof(m);
				for (int j = 0; j < n; j++)
				{
					cout << " \n ________________<Moderator(" << (j + 1) << "):________________\n";
					m.enter_data();

					xx = ofs.tellp();

					int r = m.write_file(ofs, m);
					if (r != -1)
					{

						xx = ofs.tellp();
						xx -= cf;
						md.set(m.id, (xx));
						r = md.write_file(ofs_index, md);
						if (r != -1)
							cout << " \n done\n";
						else
							cout << " \n Error.\n";
					}
					else
					{
						cout << " \n Error.\n";
					}

				}
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fm;
				ofs.close();
				ofs_index.close();

			}
			//////////////////////////////////////////////////////////////////////////////
			else if (opp == 2) {
				ifstream ifs, ifs_index;      // define object for reading.
				ifs.open("File_m.txt", ios::in);
				ifs_index.open("Index_m.txt", ios::in);
				ifs.seekg(0, ios::beg);
				while (!ifs.eof())
				{
					if (m.read_file(ifs, m))
					{
						m.display();
					}
				}


				cout << "\n All Data --------------------\n";
				ifs_index.close();
				ifs_index.open("Index_m.txt", ios::out);

				while (!ifs_index.eof())
				{
					if (md.read_file(ifs_index, md))
					{
						md.show();
					}
				}
				ifs.close();
				ifs_index.close();
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fm;
			}
			/////////////////////////////////////////////
			else if (opp == 3)
			{
				ifstream ifs, ifs_index;      // define object for reading.
				ifs.open("File_m.txt", ios::in);
				ifs_index.open("Index_m.txt", ios::in);
				int t; cout << "\n enter target id to search="; cin >> t;
				ifs_index.seekg(0, ios::beg);
				int cc = 0;
				while (!ifs_index.eof())
				{
					//
					int x = md.read_file(ifs_index, md);


					if (md.id == t)
					{
						cout << "\n Found ";
						m.read_record(ifs, m, md.sequence);
					}
					//else	cout << "Not Found";
					else cc++;
				}
				if (cc != 0)cout << "Not Found";
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fm;

			}
			else if (opp == 4)
			{

				fstream ifs, ifs_index;      // define object for reading.
				ifs.open("File_m.txt", ios::in);
				ifs_index.open("Index_m.txt", ios::in);
				int t; cout << "\n enter target id to delete="; cin >> t;

				ifs_index.seekg(0, ios::beg);
				int cc = 0;
				while (!ifs_index.eof())
				{
					//
					int x = md.read_file(ifs_index, md);


					if (md.id == t)
					{
						ifs_index.seekg(0, ios::beg);
						ifs.seekg(0, ios::beg);
						m.Delete(ifs, m, t);
						md.Delete(ifs_index, md, t);
						cout << "\n Done\n";
						cc++;
					}

					
				}
				if (cc == 0)cout << "Not Found";
				ifs.close();
				ifs_index.close();
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fm;

			}

			else if (opp == 5)
			{
				fstream ifs, ifs_index;      // define object for reading.
				int t; cout << "\n enter target id to update="; cin >> t;
				Update(t, ifs, ifs_index, m, md);
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fm;


			}


			else cout << "\n\t\t\t\tERROR!!\n";



		} break;

		case 3:////////donners
		{

			donners d; index_donners dd;
			int opp;
		fd: system("cls");
			system("color 79");
			cout << "\t\t\t\t--------------------------<Donner>----------------------\n\n";
			cout << "\t\t1-Enter new donner\t2-Display all\t3-Search\t4-Delete\t5-Update\n";
			cout << "\t\t choice ="; cin >> opp;
			fstream ofs, ofs_index;
			if (opp == 1) {
				ofs.open("File_d.txt", ios::app);
				ofs_index.open("Index_d.txt", ios::app);

				cout << " \n Please enter number of donners=";  cin >> n;

				int xx;
				int cf = sizeof(d);
				for (int j = 0; j < n; j++)
				{
					cout << " \n ________________<Donner(" << (j + 1) << "):________________\n";
					d.enter_data();

					xx = ofs.tellp();

					int r = d.write_file(ofs, d);
					if (r != -1)
					{

						xx = ofs.tellp();
						xx -= cf;
						dd.set(d.id, (xx));
						r = dd.write_file(ofs_index, dd);
						if (r != -1)
							cout << " \n done\n";
						else
							cout << " \n Error.\n";
					}
					else
					{
						cout << " \n Error.\n";
					}

				}
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fd;
				ofs.close();
				ofs_index.close();

			}
			//////////////////////////////////////////////////////////////////////////////
			else if (opp == 2) {
				ifstream ifs, ifs_index;      // define object for reading.
				ifs.open("File_d.txt", ios::in);
				ifs_index.open("Index_d.txt", ios::in);
				ifs.seekg(0, ios::beg);
				while (!ifs.eof())
				{
					if (d.read_file(ifs, d))
					{
						d.display();
					}
				}


				cout << "\n All Data --------------------\n";
				ifs_index.close();
				ifs_index.open("Index_d.txt", ios::out);

				while (!ifs_index.eof())
				{
					if (dd.read_file(ifs_index, dd))
					{
						dd.show();
					}
				}
				ifs.close();
				ifs_index.close();
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				// cin >> ss;
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

				{
					//  _getch();
					goto fd;
				}
			}
			/////////////////////////////////////////////
			else if (opp == 3)
			{
				ifstream ifs, ifs_index;      // define object for reading.
				ifs.open("File_d.txt", ios::in);
				ifs_index.open("Index_d.txt", ios::in);
				int t; cout << "\n enter target id to search="; cin >> t;
				ifs_index.seekg(0, ios::beg);
				int cc = 0;
				while (!ifs_index.eof())
				{
					//
					int x = dd.read_file(ifs_index, dd);


					if (dd.id == t)
					{
						cout << "\n Found ";
						d.read_record(ifs, d, dd.sequence);
					}
					//else	cout << "Not Found";
					else cc++;
				}
				if (cc != 0)cout << "Not Found";
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fd;

			}
			else if (opp == 4)
			{

				fstream ifs, ifs_index;      // define object for reading.
				ifs.open("File_d.txt", ios::in);
				ifs_index.open("Index_d.txt", ios::in);
				int t; cout << "\n enter target id to delete="; cin >> t;

				ifs_index.seekg(0, ios::beg);
				int cc = 0;
				while (!ifs_index.eof())
				{
					//
					int x = dd.read_file(ifs_index, dd);


					if (dd.id == t)
					{
						ifs_index.seekg(0, ios::beg);
						ifs.seekg(0, ios::beg);
						d.Delete(ifs, d, t);
						dd.Delete(ifs_index, dd, t);
						cout << "\n Done\n";
						cc++;
					}

					
				}
				if (cc == 0)cout << "Not Found";
				ifs.close();
				ifs_index.close();
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();


				goto fd;

			}
			else if (opp == 5)
			{
				fstream ifs, ifs_index;      // define object for reading.
				int t; cout << "\n enter target id to update="; cin >> t;
				Update(t, ifs, ifs_index, d, dd);
				cout << "\n\t\t\t\t\t press any key to have another operation\n\n\t\t\t\t\tpress 0 to back to the start menue :";
				cin >> ss;
				if (ss == '0')
					goto k270;
				else

					_getch();
				goto fd;
			}
			else cout << "\n\t\t\t\tERROR!!\n";




		}break;

		default:
		{
			system("color 0c");
			cout << "\t\t\t\t\t\t\tWRONG!!";
			Sleep(500);
			system("cls");
			goto k270;
		}
		break;

		}


		_getch();
	}